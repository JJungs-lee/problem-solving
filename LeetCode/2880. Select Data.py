import pandas as pd

def selectData(students: pd.DataFrame) -> pd.DataFrame:
    df = students.loc[students['student_id'] == 101]
    return df.iloc[:,1:3]