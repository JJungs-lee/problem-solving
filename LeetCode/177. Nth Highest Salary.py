import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    df = employee['salary'].sort_values(ascending=False).drop_duplicates()

    if len(df) < N or N <= 0:
        return pd.DataFrame({f'getNthHighestSalary({N})': [None]})

    nth_highest = df.iloc[N-1]
    return pd.DataFrame({f'getNthHighestSalary({N})': [nth_highest]})