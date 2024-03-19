import pandas as pd

def largest_orders(orders: pd.DataFrame) -> pd.DataFrame:
    if orders.empty:
        return pd.DataFrame(columns=['customer_number'])
    largest_customer = orders['customer_number'].value_counts().idxmax()
    return pd.DataFrame({'customer_number': [largest_customer]})