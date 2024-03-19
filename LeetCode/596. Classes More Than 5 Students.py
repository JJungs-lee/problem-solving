import pandas as pd

def find_classes(courses: pd.DataFrame) -> pd.DataFrame:
    df = courses.groupby('class').agg(cnt=('student', 'nunique')).reset_index()
    df = df[df['cnt'] >= 5]
    return df[['class']]