#include <stdio.h>
#include <ctype.h>

int str_length(const char*p_str);
void trim(const char *p_input, char *p_output);
int find_char(char delimiter, const char *p_str, int start_position);
void substring(const char *p_str, const int start_position, int end_position, char * p_result);
void split (char delimiter, char *p_str, int *position_array);

struct bank_account {
	int number;
	double balance;
	double interest_rate;
};

void update_account(struct bank_account *account) {
	account-> balance *= (1.0 + account -> interest_rate);
}
int main() {
	struct bank_account accounts[] = {
	{10907, 2000.00, 0.015},
	{47112, 5372.25, 0.024},
	{87435, 1800.00, 0.030}
	};
	
	printf("Acct #  Balance\n");
	printf("------  -------\n");
	for (int i = 0; i < sizeof(accounts) / sizeof(accounts[0]); i++) {
		update_account(&accounts[i]);
		printf(" %5d  $%.2f\n", accounts[i].number, accounts[i].balance);
	}
	return 0;
}

int str_length(const char*p_str) {
	int len = 0;
	while (*p_str != '\0') {
		len++;
		p_str++;
	}
	return len;
}
void trim(const char *p_input, char *p_output) {
	while(*p_input != '\0' && isspace(*p_input)) {
		p_input++;
	}
	while (*p_input != '0' && !isspace(*p_input)) {
		*p_output = *p_input;
		p_input++;
		p_output++;
	}
	*p_output = '\0';
}
int find_char(char delimiter, const char *p_str, int start_position) {
	int len =str_length(p_str);
	if (start_position < 0) {
		start_position = 0;
	}
	if (start_position >= len) {
		return -1;
	}
	for (int i = start_position; i<len; i++) {
		if (p_str[i] == delimiter) {
			return i;
		}
	}
	return -1;
}
void substring(const char *p_str, const int start_position, int end_position, char * p_result) {
int len =str_length(p_str);
	if (start_position <0) {
		return;
	}
	if (end_position >len || end_position== -1) {
		end_position = len;
	}
	int result_len = end_position - start_position;
	if(result_len > 0) {
		char temp_str[len +1];
		int i;
		for (i = 0; i <len &&p_str[1] != '\0'; i++) {
			temp_str[i] = p_str[i];
		}
		temp_str[i] = '\0';
		for (i= 0; i <result_len && temp_str[start_position +i] != '\0'; i++) {
			p_result[i] = temp_str[start_position + 1];
		}
		p_result[i] ='\0';
	} else { p_result[0] = '0';
		p_result[1] ='0';
	}
}
void split (char delimiter, char *p_str, int *position_array) {
	int i = 0;
	int pos;
	do {
		pos = find_char(delimiter, p_str, i);
		position_array[i] = pos;
		i++;
	}
	while (pos != -1 && i<20);
	position_array[i] = -1;
}
