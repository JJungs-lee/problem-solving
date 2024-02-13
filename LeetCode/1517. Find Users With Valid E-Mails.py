import pandas as pd

def valid_emails(users: pd.DataFrame) -> pd.DataFrame:
    _filter = users['mail'].str.match(r'^[a-zA-Z][a-zA-Z0-9._-]*@leetcode\.com$')

    return users[_filter]