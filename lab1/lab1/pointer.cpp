#define _CRT_SECURE_NO_WARNINGS  // Вимкнення попереджень компілятора
#include <iostream>

using namespace std;

// Функція для введення імені файлу
char* FP_enter_name()
{
	char* filename = new char[100];
	cout << "Enter file name: ";
	cin.getline(filename, 100);
	return filename;
}

// Перевірка, чи вдалося відкрити файл
void FP_is_open(FILE* file, char* filename)
{
	if (file == NULL) {
		cout << "Failed to open file: " << filename << endl;
		return;
	}
}

// Виведення вмісту файлу
void FP_print_file(char* filename)
{
	FILE* file = fopen(filename, "rb");
	FP_is_open(file, filename);

	char ch;
	cout << "\n " << filename << " contents: \n" << endl;
	while ((ch = fgetc(file)) != EOF) {
		cout << ch;
	}
	cout << '\n';
	fclose(file);
}

// Запис тексту в файл
void FP_write_to_file(char* filename)
{
	FILE* file = fopen(filename, "a");
	FP_is_open(file, filename);

	cout << "Enter the text to write to the file:\n";
	char* ch = new char[256];
	while (true) {
		cin.getline(ch, 255);
		if (strcmp(ch, "") == 0) {
			break;
		}
		fprintf(file, "%s\n", ch);
	}
	fclose(file);
}

// Зчитування тексту з файлу
char* FP_read_text(char* filename)
{
	FILE* file = fopen(filename, "r");
	FP_is_open(file, filename);

	char* text = new char[10000];

	char ch;
	int i = 0;

	while ((ch = fgetc(file)) != EOF) {
		if (ch == '\n' && i > 0 && text[i - 1] == '\n') {
			break; // зупинитись, якщо зустрінуться два порожніх рядки підряд
		}
		text[i] = ch;
		i++;
	}
	text[i] = '\0';
	fclose(file);
	return text;
}

// Обробка файлу
void FP_work_file(const char* input, const char* filename)
{
	FILE* out = fopen(filename, "w");

	char current_line[1000] = "";
	char current_word[1000] = "";
	char longest_word[1000] = "";

	int current_length = 1;
	int longest_length = 1;
	char current_char = '\0';

	for (int i = 0; input[i]; i++) {
		char c = input[i];

		if (c == ' ' || c == '\n' || c == '.' || c == ',') {
			// Перевірка, чи поточне слово містить найдовшу послідовність
			if (current_length > longest_length && strstr(current_word, (const char*)(current_char + std::string(current_length - 1, current_char)).c_str())) {
				longest_length = current_length;
				strcpy(longest_word, current_word);
			}
			else if (current_length == longest_length && strstr(current_word, (const char*)(current_char + std::string(current_length - 1, current_char)).c_str())) {
				strcat(longest_word, " ");
				strcat(longest_word, current_word);
			}
			current_word[0] = '\0';
			current_length = 1;
			current_char = '\0';
		}
		else {
			if (c == current_char) {
				strncat(current_word, &c, 1);
				current_length++;
			}
			else {
				strncat(current_word, &c, 1);
				current_char = c;
				current_length = 1;
			}
		}

		// Виведення рядків
		if (c == '\n') {
			// Пошук найдовшої послідовності
			int pos = 0;
			int len = strlen(current_line);
			while (pos < len) {
				char* word_pos = strstr(current_line + pos, longest_word);
				if (word_pos) {
					int word_idx = word_pos - current_line;
					char line_beginning[1000] = "";
					char line_ending[1000] = "";
					strncpy(line_beginning, current_line, word_idx);
					strcpy(line_ending, current_line + word_idx + strlen(longest_word));
					sprintf(current_line, "%s %s %s", longest_word, line_beginning, line_ending);
					pos = word_idx + strlen(longest_word) + 1;
				}
				else {
					break;
				}
			}
			fprintf(out, "%s\n", current_line);
			current_line[0] = '\0';
			longest_word[0] = '\0';
			longest_length = 1;
			current_char = '\0';
		}
		else {
			strncat(current_line, (const char*)&c, 1);
		}
	}

	fclose(out);
}

// Заміна повторюючихся символів у словах дужками
void FP_replaceDuplicatesWithBrackets(const char* str, const char* filename) {
	FILE* out = fopen(filename, "w");

	int count = 0;
	char lastChar = str[0];
	char result[1000] = { 0 };
	int resultIndex = 0;

	for (int i = 1; str[i] != '\0'; i++) {
		if (str[i] == lastChar) {
			count++;
		}
		else {
			if (count > 0) {
				char buffer[3] = { '{', lastChar, '}' };
				for (int j = 0; j < 3; j++) {
					result[resultIndex++] = buffer[j];
				}
				count = 0;
			}
			else {
				result[resultIndex++] = lastChar;
			}
			lastChar = str[i];
		}
	}

	if (count > 0) {
		char buffer[3] = { '{', lastChar, '}' };
		for (int j = 0; j < 3; j++) {
			result[resultIndex++] = buffer[j];
		}
	}
	else {
		result[resultIndex++] = lastChar;
	}

	fprintf(out, "%s", result);
	fclose(out);
}
