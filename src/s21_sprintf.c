#include "s21_string.h"

char *my_itoa(int value, char *res, int b, spec_t flag) {
  if (b < 2 || b > 36) {
    *res = '\0';
    return res;
  }

  if (value == 0) {
    int index = 0;
    if (flag.flag_plus) {
      res[index++] = '+';
    } else if (flag.flag_space) {
      res[index++] = ' ';
    }
    res[index++] = '0';
    res[index++] = '\0';
  } else {
    char *ptr = res, *ptr1 = res, tmp_char;
    int tmp_value;

    while (value) {
      tmp_value = value;
      value /= b;
      *ptr++ =
          "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvw"
          "xy"
          "z"[35 + (tmp_value - value * b)];
    }

    if (tmp_value < 0) {
      *ptr++ = '-';
    } else if (flag.flag_plus) {
      *ptr++ = '+';
    } else if (flag.flag_space) {
      *ptr++ = ' ';
    }
    *ptr-- = '\0';

    while (ptr1 < ptr) {
      tmp_char = *ptr;
      *ptr-- = *ptr1;
      *ptr1++ = tmp_char;
    }
  }

  return res;
}

int my_isdigit(char c) { return (c >= '0' && c <= '9'); }

int my_strlen(char *str) {
  int i = 0;
  while (str[i]) {
    i++;
  }
  return i;
}

int my_pow(int dec, int base) {
  if (base == 0)
    dec = 1;
  else {
    for (int i = 1; i < base; i++) {
      dec *= dec;
    }
  }
  return dec;
}

long my_atoi(char *c) {
  int i;
  int checkminus;
  long res;

  checkminus = 0;
  i = 0;
  res = 0;
  while (((c[i] >= 8) && (c[i] <= 13)) || c[i] == 32) i++;
  if (c[i] == '-' || c[i] == '+') {
    if (c[i] == '-') checkminus = 1;
    i++;
  }
  while ((c[i] >= '0') && (c[i] <= '9')) {
    res = res * 10 + (c[i] - '0');
    i++;
  }
  if (checkminus == 1) res = -res;
  return (res);
}

/* ФУНКЦИИ обработки разных форматов и доавление готового вывода в буфер*/

int num_to_buffer(char *buffer, int64_t val, spec_t flag) {
  int num_len = 0;
  int minus = 0;
  char tmp_num[1024] = {0};
  int64_t val_cpy = val;

  if (flag.lenght == 'h') {
    val = (int16_t)val;
    val_cpy = (int16_t)val_cpy;
  } else if (flag.lenght == '0') {
    val = (int32_t)val;
    val_cpy = (int32_t)val_cpy;
  }

  // записываем строку из цифр в tmp_num
  if (val < 0) {
    minus = 1;
    val = val * -1;
  }

  if (flag.accuracy == 0 && val_cpy == 0) {
  }

  while (val > 9) {
    tmp_num[num_len++] = (val % 10) + '0';
    val = val / 10;
  }
  tmp_num[num_len++] = val + '0';

  if (flag.accuracy > my_strlen(tmp_num)) {
    for (; num_len != flag.accuracy; num_len++) {
      tmp_num[num_len] = '0';
    }
  }

  if (minus) {
    tmp_num[num_len++] = '-';
  } else if (flag.flag_plus) {
    tmp_num[num_len++] = '+';
  } else if (flag.flag_space) {
    tmp_num[num_len++] = ' ';
  }
  tmp_num[num_len] = '\0';

  if (flag.accuracy == 0 && val_cpy == 0) {
    for (int k = 0; tmp_num[k]; k++) {
      if (tmp_num[k] == '0') tmp_num[k] = '\0';
    }
  }

  for (int i = 0, sym = 0; i < num_len / 2; i++) {
    sym = tmp_num[i];
    tmp_num[i] = tmp_num[num_len - 1 - i];
    tmp_num[num_len - 1 - i] = sym;
  }

  tmp_num[num_len] = '\0';

  int buf_idx = 0;
  int i = 0;

  // запись числа в Буффер с учетом ширины
  while (tmp_num[i]) {
    buffer[buf_idx + i] = tmp_num[i];
    i++;
  }
  buf_idx += i;
  buffer[buf_idx] = '\0';

  return buf_idx;
}

int char_to_buffer(char *buffer, int val, spec_t flag) {
  (void)flag;
  int i = 0;
  flag.accuracy = 1;
  buffer[i++] = val;
  buffer[i] = '\0';

  return i;
}

int wchar_to_buffer(char *buffer, wchar_t val, spec_t flag) {
  int i = 0;
  (void)flag;
  flag.accuracy = 1;
  char tmp[1024] = {'\0'};

  wcstombs(tmp, &val, 1024);
  for (int j = 0; tmp[j]; j++) {
    buffer[i] = tmp[j];
    i++;
  }

  buffer[i] = '\0';

  return i;
}

int procent_to_buffer(char *buffer, spec_t flag) {
  buffer[0] = '%';
  buffer[1] = '\0';
  (void)flag;

  return 0;
}

int str_to_buffer(char *buffer, char *val, spec_t flag) {
  int i = 0;
  int buf_idx = 0;

  if (flag.accuracy == -1) {
    flag.accuracy = my_strlen(val);
  }
  while (i != flag.accuracy) {
    buffer[buf_idx + i] = val[i];
    i++;
  }
  buffer[buf_idx + i] = '\0';

  return i;
}

long int wchar_str_to_buffer(char *buffer, wchar_t *val, spec_t flag) {
  int i = 0;
  int buf_idx = 0;
  long int check = 0;  // проверка на то, правильно ли у нас перевелась строка
                       // из wchar в char
  char tmp[1024] = {'\0'};

  check = wcstombs(tmp, val, 1024);

  // вот тут может происходить ошибка конвертации, которую по-хорошему нужно
  // обработать
  if (check != -1) {
    if (flag.accuracy == -1) {
      flag.accuracy = my_strlen(tmp);
    }
    while (i != flag.accuracy) {
      buffer[buf_idx + i] = tmp[i];
      i++;
    }
  }

  buffer[buf_idx + i] = '\0';

  return check;
}

int float_to_buffer(char *buffer, double val, spec_t flag) {
  long double c = 0, o = modfl(val, &c);
  char celoe[1024] = {'\0'};
  char drobi[1024] = {'\0'};
  char float_in_str[1024] = {'\0'};
  int check = 0;

  if (!(val != val || isinf(val))) {
    int okruglenie =
        (flag.accuracy_dot && (flag.accuracy == -1 || flag.accuracy == 0));

    if (!flag.accuracy_dot && flag.accuracy == -1) {
      flag.accuracy = 6;
    }

    if (okruglenie) c = roundl(val);
    my_itoa((int)c, celoe, 10, flag);

    if (o < 0) {
      o *= -1.;
    }
    int i = 0;
    while (i < flag.accuracy) {
      o = o * 10;
      drobi[i++] = (int)o % 10 + '0';
    }
    drobi[i] = '\0';
    long long clean_drobi = roundl(o);

    if (clean_drobi) {
      drobi[my_strlen(drobi)] = '\0';
      for (int i = my_strlen(drobi) - 1; clean_drobi || i > 0; i--) {
        drobi[i] = (int)(clean_drobi % 10 + 0.05) + '0';
        clean_drobi /= 10;
      }
    }

    for (int i = 0; celoe[i]; i++) {
      float_in_str[check] = celoe[i];
      check++;
    }

    if (!(flag.accuracy_dot && (flag.accuracy == -1 || flag.accuracy == 0))) {
      i = 0;
      float_in_str[check++] = '.';
      while (i < flag.accuracy) {
        float_in_str[check + i] = drobi[i];
        i++;
      }
      float_in_str[check + i] = '\0';
    }

    for (int i = 0; drobi[i]; i++) {
      float_in_str[check] = drobi[i];
      check++;
    }
    float_in_str[check] = '\0';

    i = 0;
    for (int j = 0; float_in_str[j]; j++) {
      buffer[i] = float_in_str[j];
      i++;
    }
    buffer[i] = '\0';
  } else {
    if (val != val) {
      buffer[0] = 'n';
      buffer[1] = 'a';
      buffer[2] = 'n';
      buffer[3] = '\0';
    }
    if (isinf(val)) {
      buffer[0] = 'i';
      buffer[1] = 'n';
      buffer[2] = 'f';
      buffer[3] = '\0';
    }
  }

  return check;
}

int unsigned_to_buffer(char *buffer, uint64_t val, spec_t flag) {
  int num_len = 0;
  char tmp_num[1024] = {0};

  if (flag.lenght == 'h') {
    val = (uint16_t)val;
  } else if (flag.lenght == '0') {
    val = (uint32_t)val;
  }

  while (val > 9) {
    tmp_num[num_len++] = (val % 10) + '0';
    val = val / 10;
  }
  tmp_num[num_len++] = val + '0';

  if (flag.accuracy > my_strlen(tmp_num)) {
    for (; num_len != flag.accuracy; num_len++) {
      tmp_num[num_len] = '0';
    }
  }

  for (int i = 0, sym = 0; i < num_len / 2; i++) {
    sym = tmp_num[i];
    tmp_num[i] = tmp_num[num_len - 1 - i];
    tmp_num[num_len - 1 - i] = sym;
  }

  tmp_num[num_len] = '\0';

  int buf_idx = 0;
  int i = 0;

  while (tmp_num[i]) {
    buffer[buf_idx + i] = tmp_num[i];
    i++;
  }

  buf_idx += i;

  buffer[buf_idx] = '\0';

  return buf_idx;
}

/***********************************************************************/

/*ФУНКЦИИ парсинга флагов и обработки спецификатора*/

int parse_width(const char *format, spec_t *flag, va_list va) {
  char num[100] = {'\0'};
  int j = 0;
  int i = 0;
  if (format[i] == '*') {
    flag->width = va_arg(va, int);
    i++;
  } else if (my_isdigit(format[i])) {
    while (my_isdigit(format[i])) {
      num[j] = format[i];
      j++;
      i++;
    }
    num[j] = '\0';
    flag->width = (int)my_atoi(num);
  }
  return i;
}

int parse_length(const char *format, spec_t *flag) {
  int i = 0;

  if (format[i] == 'h') {
    flag->lenght = 'h';
    i++;
  } else if (format[i] == 'l') {
    flag->lenght = 'l';
    i++;
  }

  return i;
}

int parse_flags(const char *format, spec_t *flag) {
  int i = 0;
  while (format[i] == '+' || format[i] == '-' || format[i] == ' ') {
    if (format[i] == '+') flag->flag_plus = 1;
    if (format[i] == '-') flag->flag_minus = 1;
    if (format[i] == ' ') flag->flag_space = 1;
    i++;
  }
  return i;
}

int parse_accuracy(const char *format, spec_t *flag, va_list va) {
  char num[100] = {'\0'};
  int j = 0;
  int i = 0;

  if (format[i] == '.') {
    flag->accuracy_dot = 1;
    i++;
    if (format[i] == '*') {
      i++;
      flag->accuracy = va_arg(va, int);
    } else if (my_isdigit(format[i])) {
      while (my_isdigit(format[i])) {
        num[j] = format[i];
        j++;
        i++;
      }
      num[j] = '\0';
      flag->accuracy = (int)my_atoi(num);
    }
  }
  return i;
}

spec_t prepare_spec(const char *format, va_list va, int *buf_len) {
  int i = 0;
  spec_t flag;

  flag.width = 0;
  flag.accuracy = -1;
  flag.accuracy_dot = 0;
  flag.lenght = '0';
  flag.flag_minus = 0;
  flag.flag_plus = 0;
  flag.flag_space = 0;

  i += parse_flags(format + i, &flag);
  i += parse_width(format + i, &flag, va);
  i += parse_accuracy(format + i, &flag, va);
  i += parse_length(format + i, &flag);

  flag.type = format[i];

  *buf_len = i + 1;
  // printf("type: %c\nf_minus: %d\n f_space: %d\n f_plus: %d\n width: %d\n
  // lenght: %c\n accuracy: %d\n", flag.type, flag.flag_minus, flag.flag_space,
  // flag.flag_plus, flag.width, flag.lenght, flag.accuracy);

  return flag;
}

/***********************************************************************/

long int prepare_buffer(char *buffer, spec_t current_flag, va_list ap) {
  long int check_error = 0;

  if ((current_flag.type == 'd') || (current_flag.type == 'i')) {
    int64_t value = va_arg(ap, int64_t);
    num_to_buffer(buffer, value, current_flag);
  } else if (current_flag.type == 'c') {
    if (current_flag.lenght == 'l') {
      wchar_t value = 0;
      value = va_arg(ap, wchar_t);
      wchar_to_buffer(buffer, value, current_flag);
    } else {
      int value = 0;
      value = va_arg(ap, int);
      char_to_buffer(buffer, value, current_flag);
    }
  } else if (current_flag.type == '%') {
    procent_to_buffer(buffer, current_flag);
  } else if (current_flag.type == 'u') {
    uint64_t value = va_arg(ap, uint64_t);
    unsigned_to_buffer(buffer, value, current_flag);
  } else if (current_flag.type == 's') {
    if (current_flag.lenght == 'l') {
      wchar_t *value = va_arg(ap, wchar_t *);
      check_error = wchar_str_to_buffer(buffer, value, current_flag);
    } else {
      char *value = va_arg(ap, char *);
      str_to_buffer(buffer, value, current_flag);
    }
  } else if (current_flag.type == 'f') {
    double value = va_arg(ap, double);
    float_to_buffer(buffer, value, current_flag);
  }

  return check_error;
}

long int prepare_bufer_with_width(char *buffer, char *buffer_with_width,
                                  spec_t flag) {
  int i = 0;
  int buf_idx = 0;

  if (flag.width && !flag.flag_minus && flag.width > my_strlen(buffer)) {
    while (buf_idx != flag.width - my_strlen(buffer)) {
      buffer_with_width[buf_idx] = ' ';
      buf_idx++;
    }
  }

  while (buffer[i]) {
    buffer_with_width[buf_idx + i] = buffer[i];
    i++;
  }

  if (flag.width && flag.flag_minus && flag.width > my_strlen(buffer)) {
    while (buf_idx != flag.width - my_strlen(buffer)) {
      buffer_with_width[buf_idx + i] = ' ';
      buf_idx++;
    }
  }

  buffer_with_width[buf_idx + i] = '\0';
  return 0;
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list ap;
  spec_t current_flag;
  char buffer[2048] = {0};
  char bufer_with_width[2048] = {0};
  int i = 0;
  int sym_count = 0;
  int buf_len = 0;
  long int check_error = 0;

  va_start(ap, format);
  while (format[i] && !check_error) {
    if (format[i] == '%') {
      current_flag = prepare_spec(format + i + 1, ap, &buf_len);
      check_error = prepare_buffer(buffer, current_flag, ap);
      if (!check_error) {
        prepare_bufer_with_width(buffer, bufer_with_width, current_flag);
        for (int buf_i = 0; bufer_with_width[buf_i]; buf_i++) {
          str[sym_count] = bufer_with_width[buf_i];
          sym_count++;
        }
        i += buf_len;
      }
    } else {
      str[sym_count] = format[i];
      sym_count++;
    }
    i++;
  }

  str[sym_count] = '\0';

  if (check_error) sym_count = -1;

  return sym_count;
}
