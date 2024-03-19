import pandas as pd

def count_salary_categories(accounts: pd.DataFrame) -> pd.DataFrame:
    total_size = len(accounts)
    
    low_salary = len(accounts[accounts['income'] < 20000])
    high_salary = len(accounts[accounts['income'] > 50000])
    aver_salary = total_size - low_salary - high_salary

    df = pd.DataFrame({'category': ['Low Salary', 'Average Salary', 'High Salary'], 
                    'accounts_count': [low_salary, aver_salary, high_salary]})

    return df