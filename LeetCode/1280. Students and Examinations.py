import pandas as pd

def students_and_examinations(students: pd.DataFrame, subjects: pd.DataFrame, examinations: pd.DataFrame) -> pd.DataFrame:
    left_table = pd.merge(left=students, right=subjects, how='cross').sort_values(['student_id', 'subject_name'])
    right_table = examinations.groupby(['student_id', 'subject_name']).agg(attended_exams=('subject_name', 'count')).reset_index()

    res = pd.merge(left_table, right_table, how='left', on=['student_id','subject_name'])
    res['attended_exams'] = res['attended_exams'].fillna(0)
    return res[['student_id', 'student_name', 'subject_name', 'attended_exams']]