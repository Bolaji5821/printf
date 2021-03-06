#ifndef _PRINTF_H_
#define _PRINTF_H_

#define BUFSIZE 1024

/* Importing Libraries */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/* Type Definitions */

/**
 * struct printer - structure for printing various types
 * @symbol: type to print
 * @func_t: function to print
 */

typedef struct printer
{
	const char symbol;
	int (*func_t)(va_list);
} printer_t;

/* Function Prototypes */

int _write(char c);
int _printf(const char *format, ...);
int print_char(va_list arguments);
int print_string(va_list arguments);
int print_percent(__attribute__((unused))va_list arguments);
int print_i(va_list arguments);
int print_d(va_list arguments);
int (*get_flag_func(const char s))(va_list);
int print_integer(va_list arguments);
int print_decimal(va_list arguments);
int binary_recursive(unsigned int num, int len);
int print_binary(va_list arguments);
int print_unint(va_list arguments);
int print_octal(va_list args);
int rot13(va_list arguments);
char *_memcpy(char *dest, char *src, unsigned int n);
char *rev_str(char *s);
int print_reversed(va_list arg);
int (*func_t)(va_list);

#endif /* _PRINTF_H_ */
#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/**
 * struct printHandler - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct printHandler
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} ph;

/* print_nums */
int print_int(va_list l, flags_t *f);
void print_number(int n);
int print_unsigned(va_list l, flags_t *f);
int count_digit(int i);

/* print_bases */
int print_hex(va_list l, flags_t *f);
int print_hex_big(va_list l, flags_t *f);
int print_binary(va_list l, flags_t *f);
int print_octal(va_list l, flags_t *f);

/* converter */
char *convert(unsigned long int num, int base, int lowercase);

/* _printf */
int _printf(const char *format, ...);

/* get_print */
int (*get_print(char s))(va_list, flags_t *);

/* get_flag */
int get_flag(char s, flags_t *f);

/* print_alpha */
int print_string(va_list l, flags_t *f);
int print_char(va_list l, flags_t *f);

/* write_funcs */
int _putchar(char c);
int _puts(char *str);

/* print_custom */
int print_rot13(va_list l, flags_t *f);
int print_rev(va_list l, flags_t *f);
int print_bigS(va_list l, flags_t *f);

/* print_address */
int print_address(va_list l, flags_t *f);

/* print_percent */
int print_percent(va_list l, flags_t *f);

#endif
