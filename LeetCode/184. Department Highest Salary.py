import pandas as pd

def department_highest_salary(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    df_merge = employee.merge(department, left_on = 'departmentId', right_on = 'id', suffixes = ('_emp', '_dep'))
    df_merge = df_merge[df_merge['salary'] == df_merge.groupby('id_dep')['salary'].transform(max)]

    df = df_merge[['name_dep', 'name_emp', 'salary']]
    df.rename(columns = {'name_dep': 'Department', 'name_emp': 'Employee', 'salary': 'salary'}, inplace = True)

    return df