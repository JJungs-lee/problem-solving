class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {
		unordered_set<string> st;

		for (string email : emails) {
			string uniqueEmail;

			for (char e : email) {
				if (e == '@' || e == '+')
					break;
				if (e == '.')
					continue;
				uniqueEmail += e;
			}

			uniqueEmail += email.substr(email.find('@'));
			st.insert(uniqueEmail);
		}
		return st.size();
	}
};