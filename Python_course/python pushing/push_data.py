import pandas as pd
import psycopg2
from psycopg2.extras import execute_values
import json

DB_URL = "postgresql://neondb_owner:npg_dr6lhuMKLfo4@ep-purple-mouse-ahwfz8vg-pooler.c-3.us-east-1.aws.neon.tech/neondb?sslmode=require&channel_binding=require"
def push_data():
    conn = None
    try:
        conn = psycopg2.connect(DB_URL)
        cur = conn.cursor()
        print("Connected to Database ✅")

        # =========================
        # 1. CATEGORIES (FAST)
        # =========================
        df_cat = pd.read_csv('final_categories.csv')

        cat_values = [(name,) for name in df_cat['name'].dropna().unique()]

        execute_values(cur, """
            INSERT INTO categories (name)
            VALUES %s
            ON CONFLICT (name) DO NOTHING
        """, cat_values)

        cur.execute("SELECT id, name FROM categories")
        cat_map = {name: str(id) for id, name in cur.fetchall()}

        print("Categories Done ✅")

        # =========================
        # 2. SUBCATEGORIES (FAST)
        # =========================
        df_sub = pd.read_csv('final_subcategories.csv')

        sub_values = []
        for row in df_sub.itertuples(index=False):
            cat_id = cat_map.get(row.category_name)
            if cat_id:
                sub_values.append((row.name, cat_id))

        execute_values(cur, """
            INSERT INTO subcategories (name, category_id)
            VALUES %s
            ON CONFLICT (name, category_id) DO NOTHING
        """, sub_values)

        cur.execute("SELECT id, name FROM subcategories")
        sub_map = {name: str(id) for id, name in cur.fetchall()}

        print("Subcategories Done ✅")

        # =========================
        # 3. PRODUCTS (FASTEST)
        # =========================
        df_prod = pd.read_csv('final_products.csv')

        product_values = []
        for row in df_prod.itertuples(index=False):
            c_id = cat_map.get(row.category_name)
            s_id = sub_map.get(row.subcategory_name)

            if c_id and s_id:
                specs = getattr(row, 'specifications', '{}')
                specs = str(specs).replace('"', "'")



                # ensure valid text/json string
                if isinstance(specs, dict):
                    specs = json.dumps(specs)

                product_values.append((
                    row.name,
                    row.description,
                    float(row.price),
                    float(row.original_price),
                    c_id,
                    s_id,
                    specs
                ))

        execute_values(cur, """
            INSERT INTO products
            (name, description, price, original_price, category_id, subcategory_id, specs)
            VALUES %s
        """, product_values)

        conn.commit()

        print(f"🚀 DONE! {len(product_values)} products inserted.")

    except Exception as e:
        if conn:
            conn.rollback()
        print("❌ Error:", e)

    finally:
        if conn:
            cur.close()
            conn.close()

if __name__ == "__main__":
    push_data()