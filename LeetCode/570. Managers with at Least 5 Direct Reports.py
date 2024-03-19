import pandas as pd

def find_managers(employee: pd.DataFrame) -> pd.DataFrame:
    df = employee.groupby('managerId').size().reset_index(name='directReport')
    df = df[df['directReport'] >= 5]

    result = df.merge(employee[['id', 'name']], left_on='managerId', right_on='id', how='inner')

    return result[['name']]