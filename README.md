# man_3_printf

.TH _PRINTF 3 "March 29, 2025" "Holberton School" "Custom printf Function Manual"
.SH NAME
_printf \- produces output according to a format
.SH SYNOPSIS
.B #include "main.h"
.PP
.B int _printf(const char *format, ...);
.SH DESCRIPTION
The
.B _printf
function produces output according to a specified format string, which is
composed of zero or more directives. Ordinary characters in the format
string are copied to the output as-is, while conversion specifiers
begin with a percent sign (\fB%\fR) and indicate how subsequent arguments
are formatted.
.PP

Supported conversion specifiers include:
.TP
.B %c
Prints a single character.
.TP
.B %s
Prints a string.
.TP
.B %%
Prints a literal percent sign.
.TP
.B %d and %i
Prints a signed integer.
.PP
Please note that features such as flag characters, field width, precision,
and length modifiers are not currently supported in this implementation.

.SH RETURN VALUE
On success, this function returns the number of characters printed
(excluding the terminating null byte). If an error occurs (e.g., the format
string is
.I NULL
or printing fails), it returns
.B \-1 .
.SH ERRORS
If the format string is invalid or
.B _printf
fails to write output, it returns
.B \-1 .

.SH AUTHORs
Written by Khulood AlOtaibi and Abdullah Alameeri

.SH SEE ALSO
.BR printf (3)
