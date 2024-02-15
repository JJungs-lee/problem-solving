import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    df = employee['salary'].sort_values(ascending=False).unique()
    if len(df) >= 2:
        return pd.DataFrame({'SecondHighestSalary': [df[1]]})

    return pd.DataFrame({'SecondHighestSalary': [None]})