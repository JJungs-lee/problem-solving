import pandas as pd

def big_countries(world: pd.DataFrame) -> pd.DataFrame:
    df_area = world['area'] >= 3000000
    df_pop = world['population'] >= 25000000

    return world[df_area | df_pop][['name', 'population', 'area']]