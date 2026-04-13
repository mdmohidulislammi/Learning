import pandas as pd
import psycopg2
from psycopg2.extras import execute_values
import re

DB_URL = "postgresql://neondb_owner:password@ep-purple-mouse-ahwfz8vg-pooler.c-3.us-east-1.aws.neon.tech/neondb?sslmode=require&channel_binding=require"


def clean_text_content(text):

    if pd.isna(text):
        return ""

    text = str(text)

    text = re.sub(r"(?i)\besp32\b", "", text)

    # Fix leftover commas
    text = re.sub(r",\s*,", ",", text)
    text = re.sub(r",\s*\)", ")", text)
    text = re.sub(r"\(\s*,", "(", text)

    return text.strip()



def safe_float(value):
    try:
        return float(value)
    except:
        return 0.0


def push_data():

    conn = None

    try:

        print("Connecting to database...")

        conn = psycopg2.connect(DB_URL)
        cur = conn.cursor()

        print("Connected to Database ✅")


        print("Deleting all existing data...")

        cur.execute("""
            TRUNCATE TABLE
            products,
            subcategories,
            categories
            RESTART IDENTITY CASCADE;
        """)

        conn.commit()

        print("Database reset complete 🗑️")

      

        print("Loading categories...")

        df_cat = pd.read_csv("final_categories.csv")

        cat_values = [
            (name,)
            for name in df_cat["name"]
            .dropna()
            .unique()
        ]

        execute_values(
            cur,
            """
            INSERT INTO categories (name)
            VALUES %s
            ON CONFLICT (name) DO NOTHING
            """,
            cat_values
        )

        cur.execute("SELECT id, name FROM categories")

        cat_map = {
            name: str(id)
            for id, name in cur.fetchall()
        }

        print("Categories inserted:", len(cat_map), "✅")

 

        print("Loading subcategories...")

        df_sub = pd.read_csv("final_subcategories.csv")

        sub_values = []

        for row in df_sub.itertuples(index=False):

            cat_id = cat_map.get(row.category_name)

            if cat_id:

                sub_values.append((
                    row.name,
                    cat_id
                ))

        execute_values(
            cur,
            """
            INSERT INTO subcategories
            (name, category_id)
            VALUES %s
            ON CONFLICT (name, category_id)
            DO NOTHING
            """,
            sub_values
        )

        cur.execute("SELECT id, name FROM subcategories")

        sub_map = {
            name: str(id)
            for id, name in cur.fetchall()
        }

        print("Subcategories inserted:", len(sub_map), "✅")


        print("Loading products...")

        df_prod = pd.read_csv("final_products.csv")

        product_values = []

        skipped = 0

        for row in df_prod.itertuples(index=False):

            c_id = cat_map.get(row.category_name)
            s_id = sub_map.get(row.subcategory_name)

            if not c_id or not s_id:
                skipped += 1
                continue

            try:

                name = clean_text_content(row.name)

                description = clean_text_content(
                    getattr(row, "description", "")
                )

                price = safe_float(row.price)

                original_price = safe_float(
                    getattr(row, "original_price", price)
                )

                product_values.append((
                    name,
                    description,
                    price,
                    original_price,
                    c_id,
                    s_id
                ))

            except Exception:

                skipped += 1

        print("Prepared products:", len(product_values))
        print("Skipped rows:", skipped)

      

        execute_values(
            cur,
            """
            INSERT INTO products
            (
                name,
                description,
                price,
                original_price,
                category_id,
                subcategory_id
            )
            VALUES %s
            """,
            product_values
        )

        conn.commit()

        print(
            f"🚀 SUCCESS: {len(product_values)} products inserted"
        )

    except Exception as e:

        if conn:
            conn.rollback()

        print("❌ ERROR:", e)

    finally:

        if conn:
            cur.close()
            conn.close()

        print("Database connection closed.")




if __name__ == "__main__":

    push_data()