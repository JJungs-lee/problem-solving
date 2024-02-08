import pandas as pd

def findHeavyAnimals(animals: pd.DataFrame) -> pd.DataFrame:
    df = animals.sort_values(by='weight', ascending=False)
    return df[df['weight'] >= 100].iloc[:,:1]