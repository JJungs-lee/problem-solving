import pandas as pd

def total_time(employees: pd.DataFrame) -> pd.DataFrame:
    employees['total_time'] = employees['out_time'] - employees['in_time']
    employees['event_day'] = employees['event_day'].astype('string')

    df = employees.groupby(['event_day', 'emp_id'])['total_time'].sum().reset_index()
    df.columns = ['day', 'emp_id', 'total_time']
    return df