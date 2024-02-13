import pandas as pd

def find_patients(patients: pd.DataFrame) -> pd.DataFrame:
    _filter = patients['conditions'].str.contains(r'\bDIAB1', regex=True)

    return patients[_filter]
