import pandas as pd
data=pd.read_csv('price.csv')
name_series=pd.Series(data['Name'])
price_series=pd.Series(data['Price'])
print(name_series)
print(price_series)