typedef long unsigned int size_t;
typedef __builtin_va_list __gnuc_va_list;
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;
typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;
typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct
{
  int __val[2];
} __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef long int __suseconds64_t;
typedef int __daddr_t;
typedef int __key_t;
typedef int __clockid_t;
typedef void *__timer_t;
typedef int __blksize_t;
typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;
typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;
typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;
typedef long int __fsword_t;
typedef long int __ssize_t;
typedef long int __syscall_slong_t;
typedef unsigned long int __syscall_ulong_t;
typedef __off64_t __loff_t;
typedef char *__caddr_t;
typedef long int __intptr_t;
typedef unsigned int __socklen_t;
typedef int __sig_atomic_t;
typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
typedef struct _G_fpos_t
{
  __off_t __pos;
  __mbstate_t __state;
} __fpos_t;
typedef struct _G_fpos64_t
{
  __off64_t __pos;
  __mbstate_t __state;
} __fpos64_t;
struct _IO_FILE;
typedef struct _IO_FILE __FILE;
struct _IO_FILE;
typedef struct _IO_FILE FILE;
struct _IO_FILE;
struct _IO_marker;
struct _IO_codecvt;
struct _IO_wide_data;
typedef void _IO_lock_t;
struct _IO_FILE
{
  int _flags;
  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;
  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;
  struct _IO_marker *_markers;
  struct _IO_FILE *_chain;
  int _fileno;
  int _flags2;
  __off_t _old_offset;
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];
  _IO_lock_t *_lock;
  __off64_t _offset;
  struct _IO_codecvt *_codecvt;
  struct _IO_wide_data *_wide_data;
  struct _IO_FILE *_freeres_list;
  void *_freeres_buf;
  size_t __pad5;
  int _mode;
  char _unused2[15 * sizeof(int) - 4 * sizeof(void *) - sizeof(size_t)];
};
typedef __ssize_t cookie_read_function_t(void *__cookie, char *__buf,
                                         size_t __nbytes);
typedef __ssize_t cookie_write_function_t(void *__cookie, const char *__buf,
                                          size_t __nbytes);
typedef int cookie_seek_function_t(void *__cookie, __off64_t *__pos,
                                   int __w);
typedef int cookie_close_function_t(void *__cookie);
typedef struct _IO_cookie_io_functions_t
{
  cookie_read_function_t *read;
  cookie_write_function_t *write;
  cookie_seek_function_t *seek;
  cookie_close_function_t *close;
} cookie_io_functions_t;
typedef __gnuc_va_list va_list;
typedef __off64_t off_t;
typedef __off64_t off64_t;
typedef __ssize_t ssize_t;
typedef __fpos64_t fpos_t;
typedef __fpos64_t fpos64_t;
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
extern int remove(const char *__filename)
    __attribute__((__nothrow__, __leaf__));
extern int rename(const char *__old, const char *__new)
    __attribute__((__nothrow__, __leaf__));
extern int renameat(int __oldfd, const char *__old, int __newfd,
                    const char *__new)
    __attribute__((__nothrow__, __leaf__));
extern int renameat2(int __oldfd, const char *__old, int __newfd,
                     const char *__new, unsigned int __flags)
    __attribute__((__nothrow__, __leaf__));
extern int fclose(FILE *__stream);
extern FILE *
tmpfile(void) __asm__(""
                      "tmpfile64")
    __attribute__((__malloc__)) __attribute__((__malloc__(fclose, 1)));
extern FILE *tmpfile64(void)
    __attribute__((__malloc__)) __attribute__((__malloc__(fclose, 1)));
extern char *tmpnam(char[20]) __attribute__((__nothrow__, __leaf__));
extern char *tmpnam_r(char __s[20])
    __attribute__((__nothrow__, __leaf__));
extern char *tempnam(const char *__dir, const char *__pfx)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__malloc__(__builtin_free, 1)));
extern int fflush(FILE *__stream);
extern int fflush_unlocked(FILE *__stream);
extern int fcloseall(void);
extern FILE *fopen(const char *__restrict __filename,
                   const char *__restrict __modes) __asm__(""
                                                           "fopen64")
    __attribute__((__malloc__)) __attribute__((__malloc__(fclose, 1)));
extern FILE *freopen(const char *__restrict __filename,
                     const char *__restrict __modes,
                     FILE *__restrict __stream) __asm__(""
                                                        "freopen64");
extern FILE *fopen64(const char *__restrict __filename,
                     const char *__restrict __modes)
    __attribute__((__malloc__)) __attribute__((__malloc__(fclose, 1)));
extern FILE *freopen64(const char *__restrict __filename,
                       const char *__restrict __modes,
                       FILE *__restrict __stream);
extern FILE *fdopen(int __fd, const char *__modes)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__malloc__(fclose, 1)));
extern FILE *fopencookie(void *__restrict __magic_cookie,
                         const char *__restrict __modes,
                         cookie_io_functions_t __io_funcs)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__malloc__(fclose, 1)));
extern FILE *fmemopen(void *__s, size_t __len, const char *__modes)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__malloc__(fclose, 1)));
extern FILE *open_memstream(char **__bufloc, size_t *__sizeloc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__malloc__(fclose, 1)));
extern void setbuf(FILE *__restrict __stream, char *__restrict __buf)
    __attribute__((__nothrow__, __leaf__));
extern int setvbuf(FILE *__restrict __stream, char *__restrict __buf,
                   int __modes, size_t __n)
    __attribute__((__nothrow__, __leaf__));
extern void setbuffer(FILE *__restrict __stream, char *__restrict __buf,
                      size_t __size)
    __attribute__((__nothrow__, __leaf__));
extern void setlinebuf(FILE *__stream)
    __attribute__((__nothrow__, __leaf__));
extern int fprintf(FILE *__restrict __stream,
                   const char *__restrict __format, ...);
extern int printf(const char *__restrict __format, ...);
extern int sprintf(char *__restrict __s,
                   const char *__restrict __format, ...)
    __attribute__((__nothrow__));
extern int vfprintf(FILE *__restrict __s,
                    const char *__restrict __format,
                    __gnuc_va_list __arg);
extern int vprintf(const char *__restrict __format,
                   __gnuc_va_list __arg);
extern int vsprintf(char *__restrict __s,
                    const char *__restrict __format,
                    __gnuc_va_list __arg) __attribute__((__nothrow__));
extern int snprintf(char *__restrict __s, size_t __maxlen,
                    const char *__restrict __format, ...)
    __attribute__((__nothrow__)) __attribute__((__format__(__printf__, 3, 4)));
extern int vsnprintf(char *__restrict __s, size_t __maxlen,
                     const char *__restrict __format,
                     __gnuc_va_list __arg) __attribute__((__nothrow__))
__attribute__((__format__(__printf__, 3, 0)));
extern int vasprintf(char **__restrict __ptr,
                     const char *__restrict __f, __gnuc_va_list __arg)
    __attribute__((__nothrow__)) __attribute__((__format__(__printf__, 2, 0)));
extern int __asprintf(char **__restrict __ptr,
                      const char *__restrict __fmt, ...)
    __attribute__((__nothrow__)) __attribute__((__format__(__printf__, 2, 3)));
extern int asprintf(char **__restrict __ptr,
                    const char *__restrict __fmt, ...)
    __attribute__((__nothrow__)) __attribute__((__format__(__printf__, 2, 3)));
extern int vdprintf(int __fd, const char *__restrict __fmt,
                    __gnuc_va_list __arg)
    __attribute__((__format__(__printf__, 2, 0)));
extern int dprintf(int __fd, const char *__restrict __fmt, ...)
    __attribute__((__format__(__printf__, 2, 3)));
extern int fscanf(FILE *__restrict __stream,
                  const char *__restrict __format, ...);
extern int scanf(const char *__restrict __format, ...);
extern int sscanf(const char *__restrict __s,
                  const char *__restrict __format, ...)
    __attribute__((__nothrow__, __leaf__));
extern int fscanf(FILE *__restrict __stream,
                  const char *__restrict __format,
                  ...) __asm__(""
                               "__isoc99_fscanf");
extern int scanf(const char *__restrict __format,
                 ...) __asm__(""
                              "__isoc99_scanf");
extern int sscanf(const char *__restrict __s,
                  const char *__restrict __format,
                  ...) __asm__(""
                               "__isoc99_sscanf")
    __attribute__((__nothrow__, __leaf__));
extern int vfscanf(FILE *__restrict __s,
                   const char *__restrict __format,
                   __gnuc_va_list __arg)
    __attribute__((__format__(__scanf__, 2, 0)));
extern int vscanf(const char *__restrict __format, __gnuc_va_list __arg)
    __attribute__((__format__(__scanf__, 1, 0)));
extern int vsscanf(const char *__restrict __s,
                   const char *__restrict __format,
                   __gnuc_va_list __arg)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__format__(__scanf__, 2, 0)));
extern int vfscanf(FILE *__restrict __s,
                   const char *__restrict __format,
                   __gnuc_va_list __arg) __asm__(""
                                                 "__isoc99_vfscanf")
    __attribute__((__format__(__scanf__, 2, 0)));
extern int vscanf(const char *__restrict __format,
                  __gnuc_va_list __arg) __asm__(""
                                                "__isoc99_vscanf")
    __attribute__((__format__(__scanf__, 1, 0)));
extern int vsscanf(const char *__restrict __s,
                   const char *__restrict __format,
                   __gnuc_va_list __arg) __asm__(""
                                                 "__isoc99_vsscanf")
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__format__(__scanf__, 2, 0)));
extern int fgetc(FILE *__stream);
extern int getc(FILE *__stream);
extern int getchar(void);
extern int getc_unlocked(FILE *__stream);
extern int getchar_unlocked(void);
extern int fgetc_unlocked(FILE *__stream);
extern int fputc(int __c, FILE *__stream);
extern int putc(int __c, FILE *__stream);
extern int putchar(int __c);
extern int fputc_unlocked(int __c, FILE *__stream);
extern int putc_unlocked(int __c, FILE *__stream);
extern int putchar_unlocked(int __c);
extern int getw(FILE *__stream);
extern int putw(int __w, FILE *__stream);
extern char *fgets(char *__restrict __s, int __n,
                   FILE *__restrict __stream)
    __attribute__((__access__(__write_only__, 1, 2)));
extern char *fgets_unlocked(char *__restrict __s, int __n,
                            FILE *__restrict __stream)
    __attribute__((__access__(__write_only__, 1, 2)));
extern __ssize_t __getdelim(char **__restrict __lineptr,
                            size_t *__restrict __n, int __delimiter,
                            FILE *__restrict __stream);
extern __ssize_t getdelim(char **__restrict __lineptr,
                          size_t *__restrict __n, int __delimiter,
                          FILE *__restrict __stream);
extern __ssize_t getline(char **__restrict __lineptr,
                         size_t *__restrict __n,
                         FILE *__restrict __stream);
extern int fputs(const char *__restrict __s, FILE *__restrict __stream);
extern int puts(const char *__s);
extern int ungetc(int __c, FILE *__stream);
extern size_t fread(void *__restrict __ptr, size_t __size,
                    size_t __n, FILE *__restrict __stream);
extern size_t fwrite(const void *__restrict __ptr, size_t __size,
                     size_t __n, FILE *__restrict __s);
extern int fputs_unlocked(const char *__restrict __s,
                          FILE *__restrict __stream);
extern size_t fread_unlocked(void *__restrict __ptr, size_t __size,
                             size_t __n, FILE *__restrict __stream);
extern size_t fwrite_unlocked(const void *__restrict __ptr,
                              size_t __size, size_t __n,
                              FILE *__restrict __stream);
extern int fseek(FILE *__stream, long int __off, int __whence);
extern long int ftell(FILE *__stream);
extern void rewind(FILE *__stream);
extern int fseeko(FILE *__stream, __off64_t __off,
                  int __whence) __asm__(""
                                        "fseeko64");
extern __off64_t ftello(FILE *__stream) __asm__(""
                                                "ftello64");
extern int fgetpos(FILE *__restrict __stream,
                   fpos_t *__restrict __pos) __asm__(""
                                                     "fgetpos64");
extern int fsetpos(FILE *__stream,
                   const fpos_t *__pos) __asm__(""
                                                "fsetpos64");
extern int fseeko64(FILE *__stream, __off64_t __off, int __whence);
extern __off64_t ftello64(FILE *__stream);
extern int fgetpos64(FILE *__restrict __stream,
                     fpos64_t *__restrict __pos);
extern int fsetpos64(FILE *__stream, const fpos64_t *__pos);
extern void clearerr(FILE *__stream)
    __attribute__((__nothrow__, __leaf__));
extern int feof(FILE *__stream) __attribute__((__nothrow__, __leaf__));
extern int ferror(FILE *__stream)
    __attribute__((__nothrow__, __leaf__));
extern void clearerr_unlocked(FILE *__stream)
    __attribute__((__nothrow__, __leaf__));
extern int feof_unlocked(FILE *__stream)
    __attribute__((__nothrow__, __leaf__));
extern int ferror_unlocked(FILE *__stream)
    __attribute__((__nothrow__, __leaf__));
extern void perror(const char *__s);
extern int fileno(FILE *__stream)
    __attribute__((__nothrow__, __leaf__));
extern int fileno_unlocked(FILE *__stream)
    __attribute__((__nothrow__, __leaf__));
extern int pclose(FILE *__stream);
extern FILE *popen(const char *__command, const char *__modes)
    __attribute__((__malloc__)) __attribute__((__malloc__(pclose, 1)));
extern char *ctermid(char *__s) __attribute__((__nothrow__, __leaf__))
__attribute__((__access__(__write_only__, 1)));
extern char *cuserid(char *__s)
    __attribute__((__access__(__write_only__, 1)));
struct obstack;
extern int obstack_printf(struct obstack *__restrict __obstack,
                          const char *__restrict __format, ...)
    __attribute__((__nothrow__)) __attribute__((__format__(__printf__, 2, 3)));
extern int obstack_vprintf(struct obstack *__restrict __obstack,
                           const char *__restrict __format,
                           __gnuc_va_list __args)
    __attribute__((__nothrow__)) __attribute__((__format__(__printf__, 2, 0)));
extern void flockfile(FILE *__stream)
    __attribute__((__nothrow__, __leaf__));
extern int ftrylockfile(FILE *__stream)
    __attribute__((__nothrow__, __leaf__));
extern void funlockfile(FILE *__stream)
    __attribute__((__nothrow__, __leaf__));
extern int __uflow(FILE *);
extern int __overflow(FILE *, int);
extern __inline __attribute__((__gnu_inline__)) int vprintf(const char *__restrict __fmt, __gnuc_va_list __arg)
{
  return vfprintf(stdout, __fmt, __arg);
}

extern __inline __attribute__((__gnu_inline__)) int getchar(void)
{
  return getc(stdin);
}

extern __inline __attribute__((__gnu_inline__)) int fgetc_unlocked(FILE *__fp)
{
  return (__builtin_expect(((__fp)->_IO_read_ptr >= (__fp)->_IO_read_end), 0)
              ? __uflow(__fp)
              : *(unsigned char *)(__fp)->_IO_read_ptr++);
}

extern __inline __attribute__((__gnu_inline__)) int getc_unlocked(FILE *__fp)
{
  return (__builtin_expect(((__fp)->_IO_read_ptr >= (__fp)->_IO_read_end), 0)
              ? __uflow(__fp)
              : *(unsigned char *)(__fp)->_IO_read_ptr++);
}

extern __inline __attribute__((__gnu_inline__)) int getchar_unlocked(void)
{
  return (__builtin_expect(((stdin)->_IO_read_ptr >= (stdin)->_IO_read_end),
                           0)
              ? __uflow(stdin)
              : *(unsigned char *)(stdin)->_IO_read_ptr++);
}

extern __inline __attribute__((__gnu_inline__)) int putchar(int __c)
{
  return putc(__c, stdout);
}

extern __inline __attribute__((__gnu_inline__)) int fputc_unlocked(int __c, FILE *__stream)
{
  return (__builtin_expect(((__stream)->_IO_write_ptr >= (__stream)->_IO_write_end),
                           0)
              ? __overflow(__stream,
                           (unsigned char)(__c))
              : (unsigned char)(*(__stream)->_IO_write_ptr++ = (__c)));
}

extern __inline __attribute__((__gnu_inline__)) int putc_unlocked(int __c, FILE *__stream)
{
  return (__builtin_expect(((__stream)->_IO_write_ptr >= (__stream)->_IO_write_end),
                           0)
              ? __overflow(__stream,
                           (unsigned char)(__c))
              : (unsigned char)(*(__stream)->_IO_write_ptr++ = (__c)));
}

extern __inline __attribute__((__gnu_inline__)) int putchar_unlocked(int __c)
{
  return (__builtin_expect(((stdout)->_IO_write_ptr >= (stdout)->_IO_write_end),
                           0)
              ? __overflow(stdout,
                           (unsigned char)(__c))
              : (unsigned char)(*(stdout)->_IO_write_ptr++ = (__c)));
}

extern __inline __attribute__((__gnu_inline__)) __ssize_t
getline(char **__lineptr, size_t *__n, FILE *__stream)
{
  return __getdelim(__lineptr, __n, '\n', __stream);
}

extern __inline __attribute__((__gnu_inline__)) int __attribute__((__nothrow__, __leaf__)) feof_unlocked(FILE *__stream)
{
  return (((__stream)->_flags & 0x0010) != 0);
}

extern __inline __attribute__((__gnu_inline__)) int
    __attribute__((__nothrow__, __leaf__))
    ferror_unlocked(FILE *__stream)
{
  return (((__stream)->_flags & 0x0020) != 0);
}

typedef int wchar_t;
typedef struct
{
  int quot;
  int rem;
} div_t;
typedef struct
{
  long int quot;
  long int rem;
} ldiv_t;
__extension__ typedef struct
{
  long long int quot;
  long long int rem;
} lldiv_t;
extern size_t __ctype_get_mb_cur_max(void)
    __attribute__((__nothrow__, __leaf__));
extern double atof(const char *__nptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));
extern int atoi(const char *__nptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));
extern long int atol(const char *__nptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));
__extension__ extern long long int atoll(const char *__nptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));
extern double strtod(const char *__restrict __nptr,
                     char **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern float strtof(const char *__restrict __nptr,
                    char **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern long double strtold(const char *__restrict __nptr,
                           char **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern _Float32 strtof32(const char *__restrict __nptr,
                         char **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern _Float64 strtof64(const char *__restrict __nptr,
                         char **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern _Float128 strtof128(const char *__restrict __nptr,
                           char **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern _Float32x strtof32x(const char *__restrict __nptr,
                           char **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern _Float64x strtof64x(const char *__restrict __nptr,
                           char **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern long int strtol(const char *__restrict __nptr,
                       char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern unsigned long int strtoul(const char *__restrict __nptr,
                                 char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
__extension__ extern long long int strtoq(const char *__restrict __nptr,
                                          char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
__extension__ extern unsigned long long int strtouq(const char *__restrict __nptr,
                                                    char **__restrict __endptr,
                                                    int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
__extension__ extern long long int strtoll(const char *__restrict __nptr,
                                           char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
__extension__ extern unsigned long long int strtoull(const char *__restrict __nptr,
                                                     char **__restrict __endptr,
                                                     int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int strfromd(char *__dest, size_t __size, const char *__format,
                    double __f)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
extern int strfromf(char *__dest, size_t __size, const char *__format,
                    float __f)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
extern int strfroml(char *__dest, size_t __size, const char *__format,
                    long double __f)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
extern int strfromf32(char *__dest, size_t __size, const char *__format,
                      _Float32 __f)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
extern int strfromf64(char *__dest, size_t __size, const char *__format,
                      _Float64 __f)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
extern int strfromf128(char *__dest, size_t __size, const char *__format,
                       _Float128 __f)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
extern int strfromf32x(char *__dest, size_t __size, const char *__format,
                       _Float32x __f)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
extern int strfromf64x(char *__dest, size_t __size, const char *__format,
                       _Float64x __f)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
struct __locale_struct
{
  struct __locale_data *__locales[13];
  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;
  const char *__names[13];
};
typedef struct __locale_struct *__locale_t;
typedef __locale_t locale_t;
extern long int strtol_l(const char *__restrict __nptr,
                         char **__restrict __endptr, int __base,
                         locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 4)));
extern unsigned long int strtoul_l(const char *__restrict __nptr,
                                   char **__restrict __endptr,
                                   int __base, locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 4)));
__extension__ extern long long int strtoll_l(const char *__restrict __nptr,
                                             char **__restrict __endptr, int __base,
                                             locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 4)));
__extension__ extern unsigned long long int strtoull_l(const char *__restrict __nptr,
                                                       char **__restrict __endptr,
                                                       int __base, locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 4)));
extern double strtod_l(const char *__restrict __nptr,
                       char **__restrict __endptr, locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 3)));
extern float strtof_l(const char *__restrict __nptr,
                      char **__restrict __endptr, locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 3)));
extern long double strtold_l(const char *__restrict __nptr,
                             char **__restrict __endptr,
                             locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 3)));
extern _Float32 strtof32_l(const char *__restrict __nptr,
                           char **__restrict __endptr,
                           locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 3)));
extern _Float64 strtof64_l(const char *__restrict __nptr,
                           char **__restrict __endptr,
                           locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 3)));
extern _Float128 strtof128_l(const char *__restrict __nptr,
                             char **__restrict __endptr,
                             locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 3)));
extern _Float32x strtof32x_l(const char *__restrict __nptr,
                             char **__restrict __endptr,
                             locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 3)));
extern _Float64x strtof64x_l(const char *__restrict __nptr,
                             char **__restrict __endptr,
                             locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 3)));
extern __inline __attribute__((__gnu_inline__)) int __attribute__((__nothrow__, __leaf__)) atoi(const char *__nptr)
{
  return (int)strtol(__nptr, (char **)((void *)0), 10);
}

extern __inline __attribute__((__gnu_inline__)) long int __attribute__((__nothrow__, __leaf__)) atol(const char *__nptr)
{
  return strtol(__nptr, (char **)((void *)0), 10);
}

__extension__ extern __inline __attribute__((__gnu_inline__)) long long int
    __attribute__((__nothrow__, __leaf__))
    atoll(const char *__nptr)
{
  return strtoll(__nptr, (char **)((void *)0), 10);
}

extern char *l64a(long int __n) __attribute__((__nothrow__, __leaf__));
extern long int a64l(const char *__s)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));
typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;
typedef __loff_t loff_t;
typedef __ino64_t ino_t;
typedef __ino64_t ino64_t;
typedef __dev_t dev_t;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __nlink_t nlink_t;
typedef __uid_t uid_t;
typedef __pid_t pid_t;
typedef __id_t id_t;
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;
typedef __key_t key_t;
typedef __clock_t clock_t;
typedef __clockid_t clockid_t;
typedef __time_t time_t;
typedef __timer_t timer_t;
typedef __useconds_t useconds_t;
typedef __suseconds_t suseconds_t;
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;
typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;
typedef int register_t __attribute__((__mode__(__word__)));
static __inline __uint16_t
__bswap_16(__uint16_t __bsx)
{
  return __builtin_bswap16(__bsx);
}

static __inline __uint32_t
__bswap_32(__uint32_t __bsx)
{
  return __builtin_bswap32(__bsx);
}

__extension__ static __inline __uint64_t
__bswap_64(__uint64_t __bsx)
{
  return __builtin_bswap64(__bsx);
}

static __inline __uint16_t
__uint16_identity(__uint16_t __x)
{
  return __x;
}

static __inline __uint32_t
__uint32_identity(__uint32_t __x)
{
  return __x;
}

static __inline __uint64_t
__uint64_identity(__uint64_t __x)
{
  return __x;
}

typedef struct
{
  unsigned long int __val[(1024 / (8 * sizeof(unsigned long int)))];
} __sigset_t;
typedef __sigset_t sigset_t;
struct timeval
{
  __time_t tv_sec;
  __suseconds_t tv_usec;
};
struct timespec
{
  __time_t tv_sec;
  __syscall_slong_t tv_nsec;
};
typedef long int __fd_mask;
typedef struct
{
  __fd_mask fds_bits[1024 / (8 * (int)sizeof(__fd_mask))];
} fd_set;
typedef __fd_mask fd_mask;
extern int select(int __nfds, fd_set *__restrict __readfds,
                  fd_set *__restrict __writefds,
                  fd_set *__restrict __exceptfds,
                  struct timeval *__restrict __timeout);
extern int pselect(int __nfds, fd_set *__restrict __readfds,
                   fd_set *__restrict __writefds,
                   fd_set *__restrict __exceptfds,
                   const struct timespec *__restrict __timeout,
                   const __sigset_t *__restrict __sigmask);
typedef __blksize_t blksize_t;
typedef __blkcnt64_t blkcnt_t;
typedef __fsblkcnt64_t fsblkcnt_t;
typedef __fsfilcnt64_t fsfilcnt_t;
typedef __blkcnt64_t blkcnt64_t;
typedef __fsblkcnt64_t fsblkcnt64_t;
typedef __fsfilcnt64_t fsfilcnt64_t;
typedef union
{
  __extension__ unsigned long long int __value64;
  struct
  {
    unsigned int __low;
    unsigned int __high;
  } __value32;
} __atomic_wide_counter;
typedef struct __pthread_internal_list
{
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;
typedef struct __pthread_internal_slist
{
  struct __pthread_internal_slist *__next;
} __pthread_slist_t;
struct __pthread_mutex_s
{
  int __lock;
  unsigned int __count;
  int __owner;
  unsigned int __nusers;
  int __kind;
  int __spins;
  __pthread_list_t __list;
};
struct __pthread_rwlock_arch_t
{
  unsigned int __readers;
  unsigned int __writers;
  unsigned int __wrphase_futex;
  unsigned int __writers_futex;
  unsigned int __pad3;
  unsigned int __pad4;
  int __cur_writer;
  int __shared;
  unsigned long int __pad1;
  unsigned long int __pad2;
  unsigned int __flags;
};
struct __pthread_cond_s
{
  __atomic_wide_counter __wseq;
  __atomic_wide_counter __g1_start;
  unsigned int __g_refs[2];
  unsigned int __g_size[2];
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
};
typedef unsigned int __tss_t;
typedef unsigned long int __thrd_t;
typedef struct
{
  int __data;
} __once_flag;
typedef unsigned long int pthread_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
union pthread_attr_t
{
  char __size[56];
  long int __align;
};
typedef union pthread_attr_t pthread_attr_t;
typedef union
{
  struct __pthread_mutex_s __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;
typedef union
{
  struct __pthread_cond_s __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;
typedef union
{
  struct __pthread_rwlock_arch_t __data;
  char __size[56];
  long int __align;
} pthread_rwlock_t;
typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;
typedef volatile int pthread_spinlock_t;
typedef union
{
  char __size[32];
  long int __align;
} pthread_barrier_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;
extern long int random(void) __attribute__((__nothrow__, __leaf__));
extern void srandom(unsigned int __seed)
    __attribute__((__nothrow__, __leaf__));
extern char *initstate(unsigned int __seed, char *__statebuf,
                       size_t __statelen)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern char *setstate(char *__statebuf)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
struct random_data
{
  int32_t *fptr;
  int32_t *rptr;
  int32_t *state;
  int rand_type;
  int rand_deg;
  int rand_sep;
  int32_t *end_ptr;
};
extern int random_r(struct random_data *__restrict __buf,
                    int32_t *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int srandom_r(unsigned int __seed, struct random_data *__buf)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int initstate_r(unsigned int __seed, char *__restrict __statebuf,
                       size_t __statelen,
                       struct random_data *__restrict __buf)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 4)));
extern int setstate_r(char *__restrict __statebuf,
                      struct random_data *__restrict __buf)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int rand(void) __attribute__((__nothrow__, __leaf__));
extern void srand(unsigned int __seed)
    __attribute__((__nothrow__, __leaf__));
extern int rand_r(unsigned int *__seed)
    __attribute__((__nothrow__, __leaf__));
extern double drand48(void) __attribute__((__nothrow__, __leaf__));
extern double erand48(unsigned short int __xsubi[3])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern long int lrand48(void) __attribute__((__nothrow__, __leaf__));
extern long int nrand48(unsigned short int __xsubi[3])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern long int mrand48(void) __attribute__((__nothrow__, __leaf__));
extern long int jrand48(unsigned short int __xsubi[3])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern void srand48(long int __seedval)
    __attribute__((__nothrow__, __leaf__));
extern unsigned short int *seed48(unsigned short int __seed16v[3])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern void lcong48(unsigned short int __param[7])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
struct drand48_data
{
  unsigned short int __x[3];
  unsigned short int __old_x[3];
  unsigned short int __c;
  unsigned short int __init;
  __extension__ unsigned long long int __a;
};
extern int drand48_r(struct drand48_data *__restrict __buffer,
                     double *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int erand48_r(unsigned short int __xsubi[3],
                     struct drand48_data *__restrict __buffer,
                     double *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int lrand48_r(struct drand48_data *__restrict __buffer,
                     long int *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int nrand48_r(unsigned short int __xsubi[3],
                     struct drand48_data *__restrict __buffer,
                     long int *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int mrand48_r(struct drand48_data *__restrict __buffer,
                     long int *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int jrand48_r(unsigned short int __xsubi[3],
                     struct drand48_data *__restrict __buffer,
                     long int *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int srand48_r(long int __seedval, struct drand48_data *__buffer)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int seed48_r(unsigned short int __seed16v[3],
                    struct drand48_data *__buffer)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int lcong48_r(unsigned short int __param[7],
                     struct drand48_data *__buffer)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern __uint32_t arc4random(void) __attribute__((__nothrow__, __leaf__));
extern void arc4random_buf(void *__buf, size_t __size)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern __uint32_t arc4random_uniform(__uint32_t __upper_bound)
    __attribute__((__nothrow__, __leaf__));
extern void *malloc(size_t __size) __attribute__((__nothrow__, __leaf__))
__attribute__((__malloc__)) __attribute__((__alloc_size__(1)));
extern void *calloc(size_t __nmemb, size_t __size)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__alloc_size__(1, 2)));
extern void *realloc(void *__ptr, size_t __size)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__)) __attribute__((__alloc_size__(2)));
extern void free(void *__ptr) __attribute__((__nothrow__, __leaf__));
extern void *reallocarray(void *__ptr, size_t __nmemb, size_t __size)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__))
    __attribute__((__alloc_size__(2, 3)))
    __attribute__((__malloc__(__builtin_free, 1)));
extern void *reallocarray(void *__ptr, size_t __nmemb, size_t __size)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__malloc__(reallocarray, 1)));
extern void *alloca(size_t __size) __attribute__((__nothrow__, __leaf__));
extern void *valloc(size_t __size) __attribute__((__nothrow__, __leaf__))
__attribute__((__malloc__)) __attribute__((__alloc_size__(1)));
extern int posix_memalign(void **__memptr, size_t __alignment, size_t __size)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern void *aligned_alloc(size_t __alignment, size_t __size)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__alloc_align__(1))) __attribute__((__alloc_size__(2)));
extern void abort(void) __attribute__((__nothrow__, __leaf__))
__attribute__((__noreturn__));
extern int atexit(void (*__func)(void))
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int at_quick_exit(void (*__func)(void))
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int on_exit(void (*__func)(int __status, void *__arg), void *__arg)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern void exit(int __status) __attribute__((__nothrow__, __leaf__))
__attribute__((__noreturn__));
extern void quick_exit(int __status) __attribute__((__nothrow__, __leaf__))
__attribute__((__noreturn__));
extern void _Exit(int __status) __attribute__((__nothrow__, __leaf__))
__attribute__((__noreturn__));
extern char *getenv(const char *__name)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern char *secure_getenv(const char *__name)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int putenv(char *__string) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int setenv(const char *__name, const char *__value, int __replace)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int unsetenv(const char *__name)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int clearenv(void) __attribute__((__nothrow__, __leaf__));
extern char *mktemp(char *__template) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int
mkstemp(char *__template) __asm__(""
                                  "mkstemp64") __attribute__((__nonnull__(1)));
extern int mkstemp64(char *__template) __attribute__((__nonnull__(1)));
extern int mkstemps(char *__template,
                    int __suffixlen) __asm__(""
                                             "mkstemps64")
    __attribute__((__nonnull__(1)));
extern int mkstemps64(char *__template, int __suffixlen)
    __attribute__((__nonnull__(1)));
extern char *mkdtemp(char *__template)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int mkostemp(char *__template,
                    int __flags) __asm__(""
                                         "mkostemp64")
    __attribute__((__nonnull__(1)));
extern int mkostemp64(char *__template, int __flags)
    __attribute__((__nonnull__(1)));
extern int mkostemps(char *__template, int __suffixlen,
                     int __flags) __asm__(""
                                          "mkostemps64")
    __attribute__((__nonnull__(1)));
extern int mkostemps64(char *__template, int __suffixlen, int __flags)
    __attribute__((__nonnull__(1)));
extern int system(const char *__command);
extern char *canonicalize_file_name(const char *__name)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__malloc__)) __attribute__((__malloc__(__builtin_free, 1)));
extern char *realpath(const char *__restrict __name,
                      char *__restrict __resolved)
    __attribute__((__nothrow__, __leaf__));
typedef int (*__compar_fn_t)(const void *, const void *);
typedef __compar_fn_t comparison_fn_t;
typedef int (*__compar_d_fn_t)(const void *, const void *, void *);
extern void *bsearch(const void *__key, const void *__base,
                     size_t __nmemb, size_t __size,
                     __compar_fn_t __compar)
    __attribute__((__nonnull__(1, 2, 5)));
extern __inline __attribute__((__gnu_inline__)) void *bsearch(const void *__key, const void *__base, size_t __nmemb,
                                                              size_t __size, __compar_fn_t __compar)
{
  size_t __l, __u, __idx;
  const void *__p;
  int __comparison;
  __l = 0;
  __u = __nmemb;
  while (__l < __u)
  {
    __idx = (__l + __u) / 2;
    __p = (const void *)(((const char *)__base) + (__idx * __size));
    __comparison = (*__compar)(__key, __p);
    if (__comparison < 0)
      __u = __idx;
    else if (__comparison > 0)
      __l = __idx + 1;
    else
    {
      return (void *)__p;
    }
  }
  return ((void *)0);
}

extern void qsort(void *__base, size_t __nmemb, size_t __size,
                  __compar_fn_t __compar)
    __attribute__((__nonnull__(1, 4)));
extern void qsort_r(void *__base, size_t __nmemb, size_t __size,
                    __compar_d_fn_t __compar, void *__arg)
    __attribute__((__nonnull__(1, 4)));
extern int abs(int __x) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));
extern long int labs(long int __x) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));
__extension__ extern long long int llabs(long long int __x)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern div_t div(int __numer, int __denom)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern ldiv_t ldiv(long int __numer, long int __denom)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
__extension__ extern lldiv_t lldiv(long long int __numer,
                                   long long int __denom)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern char *ecvt(double __value, int __ndigit, int *__restrict __decpt,
                  int *__restrict __sign)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3, 4)));
extern char *fcvt(double __value, int __ndigit, int *__restrict __decpt,
                  int *__restrict __sign)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3, 4)));
extern char *gcvt(double __value, int __ndigit, char *__buf)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
extern char *qecvt(long double __value, int __ndigit,
                   int *__restrict __decpt, int *__restrict __sign)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3, 4)));
extern char *qfcvt(long double __value, int __ndigit,
                   int *__restrict __decpt, int *__restrict __sign)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3, 4)));
extern char *qgcvt(long double __value, int __ndigit, char *__buf)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
extern int ecvt_r(double __value, int __ndigit, int *__restrict __decpt,
                  int *__restrict __sign, char *__restrict __buf,
                  size_t __len) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3, 4, 5)));
extern int fcvt_r(double __value, int __ndigit, int *__restrict __decpt,
                  int *__restrict __sign, char *__restrict __buf,
                  size_t __len) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3, 4, 5)));
extern int qecvt_r(long double __value, int __ndigit,
                   int *__restrict __decpt, int *__restrict __sign,
                   char *__restrict __buf, size_t __len)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__nonnull__(3, 4, 5)));
extern int qfcvt_r(long double __value, int __ndigit,
                   int *__restrict __decpt, int *__restrict __sign,
                   char *__restrict __buf, size_t __len)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__nonnull__(3, 4, 5)));
extern int mblen(const char *__s, size_t __n)
    __attribute__((__nothrow__, __leaf__));
extern int mbtowc(wchar_t *__restrict __pwc,
                  const char *__restrict __s, size_t __n)
    __attribute__((__nothrow__, __leaf__));
extern int wctomb(char *__s, wchar_t __wchar)
    __attribute__((__nothrow__, __leaf__));
extern size_t mbstowcs(wchar_t *__restrict __pwcs,
                       const char *__restrict __s, size_t __n)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__access__(__read_only__, 2)));
extern size_t wcstombs(char *__restrict __s,
                       const wchar_t *__restrict __pwcs, size_t __n)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__access__(__write_only__, 1, 3)))
    __attribute__((__access__(__read_only__, 2)));
extern int rpmatch(const char *__response)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int getsubopt(char **__restrict __optionp,
                     char *const *__restrict __tokens,
                     char **__restrict __valuep)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__nonnull__(1, 2, 3)));
extern int posix_openpt(int __oflag);
extern int grantpt(int __fd) __attribute__((__nothrow__, __leaf__));
extern int unlockpt(int __fd) __attribute__((__nothrow__, __leaf__));
extern char *ptsname(int __fd) __attribute__((__nothrow__, __leaf__));
extern int ptsname_r(int __fd, char *__buf, size_t __buflen)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)))
    __attribute__((__access__(__write_only__, 2, 3)));
extern int getpt(void);
extern int getloadavg(double __loadavg[], int __nelem)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern __inline __attribute__((__gnu_inline__)) double __attribute__((__nothrow__, __leaf__)) atof(const char *__nptr)
{
  return strtod(__nptr, (char **)((void *)0));
}

extern void *memcpy(void *__restrict __dest, const void *__restrict __src,
                    size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern void *memmove(void *__dest, const void *__src, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern void *memccpy(void *__restrict __dest, const void *__restrict __src,
                     int __c, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)))
    __attribute__((__access__(__write_only__, 1, 4)));
extern void *memset(void *__s, int __c, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int memcmp(const void *__s1, const void *__s2, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
extern int __memcmpeq(const void *__s1, const void *__s2, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
extern void *memchr(const void *__s, int __c, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));
extern void *rawmemchr(const void *__s, int __c)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));
extern void *memrchr(const void *__s, int __c, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)))
    __attribute__((__access__(__read_only__, 1, 3)));
extern char *strcpy(char *__restrict __dest, const char *__restrict __src)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern char *strncpy(char *__restrict __dest,
                     const char *__restrict __src, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern char *strcat(char *__restrict __dest, const char *__restrict __src)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern char *strncat(char *__restrict __dest, const char *__restrict __src,
                     size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern int strcmp(const char *__s1, const char *__s2)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
extern int strncmp(const char *__s1, const char *__s2, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
extern int strcoll(const char *__s1, const char *__s2)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
extern size_t strxfrm(char *__restrict __dest,
                      const char *__restrict __src, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)))
    __attribute__((__access__(__write_only__, 1, 3)));
extern int strcoll_l(const char *__s1, const char *__s2, locale_t __l)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2, 3)));
extern size_t strxfrm_l(char *__dest, const char *__src, size_t __n,
                        locale_t __l) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2, 4)))
__attribute__((__access__(__write_only__, 1, 3)));
extern char *strdup(const char *__s)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__nonnull__(1)));
extern char *strndup(const char *__string, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__nonnull__(1)));
extern char *strchr(const char *__s, int __c)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));
extern char *strrchr(const char *__s, int __c)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));
extern char *strchrnul(const char *__s, int __c)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));
extern size_t strcspn(const char *__s, const char *__reject)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
extern size_t strspn(const char *__s, const char *__accept)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
extern char *strpbrk(const char *__s, const char *__accept)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
extern char *strstr(const char *__haystack, const char *__needle)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
extern char *strtok(char *__restrict __s, const char *__restrict __delim)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern char *__strtok_r(char *__restrict __s,
                        const char *__restrict __delim,
                        char **__restrict __save_ptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 3)));
extern char *strtok_r(char *__restrict __s, const char *__restrict __delim,
                      char **__restrict __save_ptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 3)));
extern char *strcasestr(const char *__haystack, const char *__needle)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
extern void *memmem(const void *__haystack, size_t __haystacklen,
                    const void *__needle, size_t __needlelen)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 3)))
    __attribute__((__access__(__read_only__, 1, 2)))
    __attribute__((__access__(__read_only__, 3, 4)));
extern void *__mempcpy(void *__restrict __dest,
                       const void *__restrict __src, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern void *mempcpy(void *__restrict __dest,
                     const void *__restrict __src, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern size_t strlen(const char *__s)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));
extern size_t strnlen(const char *__string, size_t __maxlen)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));
extern char *strerror(int __errnum) __attribute__((__nothrow__, __leaf__));
extern char *strerror_r(int __errnum, char *__buf, size_t __buflen)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)))
    __attribute__((__access__(__write_only__, 2, 3)));
extern const char *strerrordesc_np(int __err)
    __attribute__((__nothrow__, __leaf__));
extern const char *strerrorname_np(int __err)
    __attribute__((__nothrow__, __leaf__));
extern char *strerror_l(int __errnum, locale_t __l)
    __attribute__((__nothrow__, __leaf__));
extern int bcmp(const void *__s1, const void *__s2, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
extern void bcopy(const void *__src, void *__dest, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern void bzero(void *__s, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern char *index(const char *__s, int __c)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));
extern char *rindex(const char *__s, int __c)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));
extern int ffs(int __i) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));
extern int ffsl(long int __l) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));
__extension__ extern int ffsll(long long int __ll)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern int strcasecmp(const char *__s1, const char *__s2)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
extern int strncasecmp(const char *__s1, const char *__s2, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
extern int strcasecmp_l(const char *__s1, const char *__s2, locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2, 3)));
extern int strncasecmp_l(const char *__s1, const char *__s2,
                         size_t __n, locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2, 4)));
extern void explicit_bzero(void *__s, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__access__(__write_only__, 1, 2)));
extern char *strsep(char **__restrict __stringp,
                    const char *__restrict __delim)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern char *strsignal(int __sig) __attribute__((__nothrow__, __leaf__));
extern const char *sigabbrev_np(int __sig)
    __attribute__((__nothrow__, __leaf__));
extern const char *sigdescr_np(int __sig)
    __attribute__((__nothrow__, __leaf__));
extern char *__stpcpy(char *__restrict __dest, const char *__restrict __src)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern char *stpcpy(char *__restrict __dest, const char *__restrict __src)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern char *__stpncpy(char *__restrict __dest,
                       const char *__restrict __src, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern char *stpncpy(char *__restrict __dest,
                     const char *__restrict __src, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int strverscmp(const char *__s1, const char *__s2)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
extern char *strfry(char *__string) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern void *memfrob(void *__s, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__access__(__read_write__, 1, 2)));
extern char *basename(const char *__filename)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int *__errno_location(void) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));
extern char *program_invocation_name;
extern char *program_invocation_short_name;
typedef int error_t;
typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;
typedef __int_least8_t int_least8_t;
typedef __int_least16_t int_least16_t;
typedef __int_least32_t int_least32_t;
typedef __int_least64_t int_least64_t;
typedef __uint_least8_t uint_least8_t;
typedef __uint_least16_t uint_least16_t;
typedef __uint_least32_t uint_least32_t;
typedef __uint_least64_t uint_least64_t;
typedef signed char int_fast8_t;
typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
typedef long int intptr_t;
typedef unsigned long int uintptr_t;
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;
typedef __socklen_t socklen_t;
extern int access(const char *__name, int __type)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int euidaccess(const char *__name, int __type)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int eaccess(const char *__name, int __type)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int execveat(int __fd, const char *__path, char *const __argv[],
                    char *const __envp[], int __flags)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 3)));
extern int faccessat(int __fd, const char *__file, int __type, int __flag)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern __off64_t
lseek(int __fd, __off64_t __offset, int __whence) __asm__(""
                                                          "lseek64") __attribute__((__nothrow__, __leaf__));
extern __off64_t lseek64(int __fd, __off64_t __offset, int __whence)
    __attribute__((__nothrow__, __leaf__));
extern int close(int __fd);
extern void closefrom(int __lowfd)
    __attribute__((__nothrow__, __leaf__));
extern ssize_t read(int __fd, void *__buf, size_t __nbytes)
    __attribute__((__access__(__write_only__, 2, 3)));
extern ssize_t write(int __fd, const void *__buf, size_t __n)
    __attribute__((__access__(__read_only__, 2, 3)));
extern ssize_t pread(int __fd, void *__buf, size_t __nbytes,
                     __off64_t __offset) __asm__(""
                                                 "pread64")
    __attribute__((__access__(__write_only__, 2, 3)));
extern ssize_t pwrite(int __fd, const void *__buf, size_t __nbytes,
                      __off64_t __offset) __asm__(""
                                                  "pwrite64")
    __attribute__((__access__(__read_only__, 2, 3)));
extern ssize_t pread64(int __fd, void *__buf, size_t __nbytes,
                       __off64_t __offset)
    __attribute__((__access__(__write_only__, 2, 3)));
extern ssize_t pwrite64(int __fd, const void *__buf, size_t __n,
                        __off64_t __offset)
    __attribute__((__access__(__read_only__, 2, 3)));
extern int pipe(int __pipedes[2])
    __attribute__((__nothrow__, __leaf__));
extern int pipe2(int __pipedes[2], int __flags)
    __attribute__((__nothrow__, __leaf__));
extern unsigned int alarm(unsigned int __seconds)
    __attribute__((__nothrow__, __leaf__));
extern unsigned int sleep(unsigned int __seconds);
extern __useconds_t ualarm(__useconds_t __value,
                           __useconds_t __interval)
    __attribute__((__nothrow__, __leaf__));
extern int usleep(__useconds_t __useconds);
extern int pause(void);
extern int chown(const char *__file, __uid_t __owner, __gid_t __group)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int fchown(int __fd, __uid_t __owner, __gid_t __group)
    __attribute__((__nothrow__, __leaf__));
extern int lchown(const char *__file, __uid_t __owner, __gid_t __group)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int fchownat(int __fd, const char *__file, __uid_t __owner,
                    __gid_t __group, int __flag)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int chdir(const char *__path)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int fchdir(int __fd) __attribute__((__nothrow__, __leaf__));
extern char *getcwd(char *__buf, size_t __size)
    __attribute__((__nothrow__, __leaf__));
extern char *get_current_dir_name(void)
    __attribute__((__nothrow__, __leaf__));
extern char *getwd(char *__buf)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__deprecated__))
    __attribute__((__access__(__write_only__, 1)));
extern int dup(int __fd) __attribute__((__nothrow__, __leaf__));
extern int dup2(int __fd, int __fd2)
    __attribute__((__nothrow__, __leaf__));
extern int dup3(int __fd, int __fd2, int __flags)
    __attribute__((__nothrow__, __leaf__));
extern char **__environ;
extern char **environ;
extern int execve(const char *__path, char *const __argv[],
                  char *const __envp[])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int fexecve(int __fd, char *const __argv[], char *const __envp[])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int execv(const char *__path, char *const __argv[])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int execle(const char *__path, const char *__arg, ...)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int execl(const char *__path, const char *__arg, ...)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int execvp(const char *__file, char *const __argv[])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int execlp(const char *__file, const char *__arg, ...)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int execvpe(const char *__file, char *const __argv[],
                   char *const __envp[])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int nice(int __inc) __attribute__((__nothrow__, __leaf__));
extern void _exit(int __status) __attribute__((__noreturn__));
enum
{
  _PC_LINK_MAX,
  _PC_MAX_CANON,
  _PC_MAX_INPUT,
  _PC_NAME_MAX,
  _PC_PATH_MAX,
  _PC_PIPE_BUF,
  _PC_CHOWN_RESTRICTED,
  _PC_NO_TRUNC,
  _PC_VDISABLE,
  _PC_SYNC_IO,
  _PC_ASYNC_IO,
  _PC_PRIO_IO,
  _PC_SOCK_MAXBUF,
  _PC_FILESIZEBITS,
  _PC_REC_INCR_XFER_SIZE,
  _PC_REC_MAX_XFER_SIZE,
  _PC_REC_MIN_XFER_SIZE,
  _PC_REC_XFER_ALIGN,
  _PC_ALLOC_SIZE_MIN,
  _PC_SYMLINK_MAX,
  _PC_2_SYMLINKS
};
enum
{
  _SC_ARG_MAX,
  _SC_CHILD_MAX,
  _SC_CLK_TCK,
  _SC_NGROUPS_MAX,
  _SC_OPEN_MAX,
  _SC_STREAM_MAX,
  _SC_TZNAME_MAX,
  _SC_JOB_CONTROL,
  _SC_SAVED_IDS,
  _SC_REALTIME_SIGNALS,
  _SC_PRIORITY_SCHEDULING,
  _SC_TIMERS,
  _SC_ASYNCHRONOUS_IO,
  _SC_PRIORITIZED_IO,
  _SC_SYNCHRONIZED_IO,
  _SC_FSYNC,
  _SC_MAPPED_FILES,
  _SC_MEMLOCK,
  _SC_MEMLOCK_RANGE,
  _SC_MEMORY_PROTECTION,
  _SC_MESSAGE_PASSING,
  _SC_SEMAPHORES,
  _SC_SHARED_MEMORY_OBJECTS,
  _SC_AIO_LISTIO_MAX,
  _SC_AIO_MAX,
  _SC_AIO_PRIO_DELTA_MAX,
  _SC_DELAYTIMER_MAX,
  _SC_MQ_OPEN_MAX,
  _SC_MQ_PRIO_MAX,
  _SC_VERSION,
  _SC_PAGESIZE,
  _SC_RTSIG_MAX,
  _SC_SEM_NSEMS_MAX,
  _SC_SEM_VALUE_MAX,
  _SC_SIGQUEUE_MAX,
  _SC_TIMER_MAX,
  _SC_BC_BASE_MAX,
  _SC_BC_DIM_MAX,
  _SC_BC_SCALE_MAX,
  _SC_BC_STRING_MAX,
  _SC_COLL_WEIGHTS_MAX,
  _SC_EQUIV_CLASS_MAX,
  _SC_EXPR_NEST_MAX,
  _SC_LINE_MAX,
  _SC_RE_DUP_MAX,
  _SC_CHARCLASS_NAME_MAX,
  _SC_2_VERSION,
  _SC_2_C_BIND,
  _SC_2_C_DEV,
  _SC_2_FORT_DEV,
  _SC_2_FORT_RUN,
  _SC_2_SW_DEV,
  _SC_2_LOCALEDEF,
  _SC_PII,
  _SC_PII_XTI,
  _SC_PII_SOCKET,
  _SC_PII_INTERNET,
  _SC_PII_OSI,
  _SC_POLL,
  _SC_SELECT,
  _SC_UIO_MAXIOV,
  _SC_IOV_MAX = _SC_UIO_MAXIOV,
  _SC_PII_INTERNET_STREAM,
  _SC_PII_INTERNET_DGRAM,
  _SC_PII_OSI_COTS,
  _SC_PII_OSI_CLTS,
  _SC_PII_OSI_M,
  _SC_T_IOV_MAX,
  _SC_THREADS,
  _SC_THREAD_SAFE_FUNCTIONS,
  _SC_GETGR_R_SIZE_MAX,
  _SC_GETPW_R_SIZE_MAX,
  _SC_LOGIN_NAME_MAX,
  _SC_TTY_NAME_MAX,
  _SC_THREAD_DESTRUCTOR_ITERATIONS,
  _SC_THREAD_KEYS_MAX,
  _SC_THREAD_STACK_MIN,
  _SC_THREAD_THREADS_MAX,
  _SC_THREAD_ATTR_STACKADDR,
  _SC_THREAD_ATTR_STACKSIZE,
  _SC_THREAD_PRIORITY_SCHEDULING,
  _SC_THREAD_PRIO_INHERIT,
  _SC_THREAD_PRIO_PROTECT,
  _SC_THREAD_PROCESS_SHARED,
  _SC_NPROCESSORS_CONF,
  _SC_NPROCESSORS_ONLN,
  _SC_PHYS_PAGES,
  _SC_AVPHYS_PAGES,
  _SC_ATEXIT_MAX,
  _SC_PASS_MAX,
  _SC_XOPEN_VERSION,
  _SC_XOPEN_XCU_VERSION,
  _SC_XOPEN_UNIX,
  _SC_XOPEN_CRYPT,
  _SC_XOPEN_ENH_I18N,
  _SC_XOPEN_SHM,
  _SC_2_CHAR_TERM,
  _SC_2_C_VERSION,
  _SC_2_UPE,
  _SC_XOPEN_XPG2,
  _SC_XOPEN_XPG3,
  _SC_XOPEN_XPG4,
  _SC_CHAR_BIT,
  _SC_CHAR_MAX,
  _SC_CHAR_MIN,
  _SC_INT_MAX,
  _SC_INT_MIN,
  _SC_LONG_BIT,
  _SC_WORD_BIT,
  _SC_MB_LEN_MAX,
  _SC_NZERO,
  _SC_SSIZE_MAX,
  _SC_SCHAR_MAX,
  _SC_SCHAR_MIN,
  _SC_SHRT_MAX,
  _SC_SHRT_MIN,
  _SC_UCHAR_MAX,
  _SC_UINT_MAX,
  _SC_ULONG_MAX,
  _SC_USHRT_MAX,
  _SC_NL_ARGMAX,
  _SC_NL_LANGMAX,
  _SC_NL_MSGMAX,
  _SC_NL_NMAX,
  _SC_NL_SETMAX,
  _SC_NL_TEXTMAX,
  _SC_XBS5_ILP32_OFF32,
  _SC_XBS5_ILP32_OFFBIG,
  _SC_XBS5_LP64_OFF64,
  _SC_XBS5_LPBIG_OFFBIG,
  _SC_XOPEN_LEGACY,
  _SC_XOPEN_REALTIME,
  _SC_XOPEN_REALTIME_THREADS,
  _SC_ADVISORY_INFO,
  _SC_BARRIERS,
  _SC_BASE,
  _SC_C_LANG_SUPPORT,
  _SC_C_LANG_SUPPORT_R,
  _SC_CLOCK_SELECTION,
  _SC_CPUTIME,
  _SC_THREAD_CPUTIME,
  _SC_DEVICE_IO,
  _SC_DEVICE_SPECIFIC,
  _SC_DEVICE_SPECIFIC_R,
  _SC_FD_MGMT,
  _SC_FIFO,
  _SC_PIPE,
  _SC_FILE_ATTRIBUTES,
  _SC_FILE_LOCKING,
  _SC_FILE_SYSTEM,
  _SC_MONOTONIC_CLOCK,
  _SC_MULTI_PROCESS,
  _SC_SINGLE_PROCESS,
  _SC_NETWORKING,
  _SC_READER_WRITER_LOCKS,
  _SC_SPIN_LOCKS,
  _SC_REGEXP,
  _SC_REGEX_VERSION,
  _SC_SHELL,
  _SC_SIGNALS,
  _SC_SPAWN,
  _SC_SPORADIC_SERVER,
  _SC_THREAD_SPORADIC_SERVER,
  _SC_SYSTEM_DATABASE,
  _SC_SYSTEM_DATABASE_R,
  _SC_TIMEOUTS,
  _SC_TYPED_MEMORY_OBJECTS,
  _SC_USER_GROUPS,
  _SC_USER_GROUPS_R,
  _SC_2_PBS,
  _SC_2_PBS_ACCOUNTING,
  _SC_2_PBS_LOCATE,
  _SC_2_PBS_MESSAGE,
  _SC_2_PBS_TRACK,
  _SC_SYMLOOP_MAX,
  _SC_STREAMS,
  _SC_2_PBS_CHECKPOINT,
  _SC_V6_ILP32_OFF32,
  _SC_V6_ILP32_OFFBIG,
  _SC_V6_LP64_OFF64,
  _SC_V6_LPBIG_OFFBIG,
  _SC_HOST_NAME_MAX,
  _SC_TRACE,
  _SC_TRACE_EVENT_FILTER,
  _SC_TRACE_INHERIT,
  _SC_TRACE_LOG,
  _SC_LEVEL1_ICACHE_SIZE,
  _SC_LEVEL1_ICACHE_ASSOC,
  _SC_LEVEL1_ICACHE_LINESIZE,
  _SC_LEVEL1_DCACHE_SIZE,
  _SC_LEVEL1_DCACHE_ASSOC,
  _SC_LEVEL1_DCACHE_LINESIZE,
  _SC_LEVEL2_CACHE_SIZE,
  _SC_LEVEL2_CACHE_ASSOC,
  _SC_LEVEL2_CACHE_LINESIZE,
  _SC_LEVEL3_CACHE_SIZE,
  _SC_LEVEL3_CACHE_ASSOC,
  _SC_LEVEL3_CACHE_LINESIZE,
  _SC_LEVEL4_CACHE_SIZE,
  _SC_LEVEL4_CACHE_ASSOC,
  _SC_LEVEL4_CACHE_LINESIZE,
  _SC_IPV6 = _SC_LEVEL1_ICACHE_SIZE + 50,
  _SC_RAW_SOCKETS,
  _SC_V7_ILP32_OFF32,
  _SC_V7_ILP32_OFFBIG,
  _SC_V7_LP64_OFF64,
  _SC_V7_LPBIG_OFFBIG,
  _SC_SS_REPL_MAX,
  _SC_TRACE_EVENT_NAME_MAX,
  _SC_TRACE_NAME_MAX,
  _SC_TRACE_SYS_MAX,
  _SC_TRACE_USER_EVENT_MAX,
  _SC_XOPEN_STREAMS,
  _SC_THREAD_ROBUST_PRIO_INHERIT,
  _SC_THREAD_ROBUST_PRIO_PROTECT,
  _SC_MINSIGSTKSZ,
  _SC_SIGSTKSZ
};
enum
{
  _CS_PATH,
  _CS_V6_WIDTH_RESTRICTED_ENVS,
  _CS_GNU_LIBC_VERSION,
  _CS_GNU_LIBPTHREAD_VERSION,
  _CS_V5_WIDTH_RESTRICTED_ENVS,
  _CS_V7_WIDTH_RESTRICTED_ENVS,
  _CS_LFS_CFLAGS = 1000,
  _CS_LFS_LDFLAGS,
  _CS_LFS_LIBS,
  _CS_LFS_LINTFLAGS,
  _CS_LFS64_CFLAGS,
  _CS_LFS64_LDFLAGS,
  _CS_LFS64_LIBS,
  _CS_LFS64_LINTFLAGS,
  _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,
  _CS_XBS5_ILP32_OFF32_LDFLAGS,
  _CS_XBS5_ILP32_OFF32_LIBS,
  _CS_XBS5_ILP32_OFF32_LINTFLAGS,
  _CS_XBS5_ILP32_OFFBIG_CFLAGS,
  _CS_XBS5_ILP32_OFFBIG_LDFLAGS,
  _CS_XBS5_ILP32_OFFBIG_LIBS,
  _CS_XBS5_ILP32_OFFBIG_LINTFLAGS,
  _CS_XBS5_LP64_OFF64_CFLAGS,
  _CS_XBS5_LP64_OFF64_LDFLAGS,
  _CS_XBS5_LP64_OFF64_LIBS,
  _CS_XBS5_LP64_OFF64_LINTFLAGS,
  _CS_XBS5_LPBIG_OFFBIG_CFLAGS,
  _CS_XBS5_LPBIG_OFFBIG_LDFLAGS,
  _CS_XBS5_LPBIG_OFFBIG_LIBS,
  _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,
  _CS_POSIX_V6_ILP32_OFF32_CFLAGS,
  _CS_POSIX_V6_ILP32_OFF32_LDFLAGS,
  _CS_POSIX_V6_ILP32_OFF32_LIBS,
  _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,
  _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,
  _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,
  _CS_POSIX_V6_ILP32_OFFBIG_LIBS,
  _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,
  _CS_POSIX_V6_LP64_OFF64_CFLAGS,
  _CS_POSIX_V6_LP64_OFF64_LDFLAGS,
  _CS_POSIX_V6_LP64_OFF64_LIBS,
  _CS_POSIX_V6_LP64_OFF64_LINTFLAGS,
  _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,
  _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,
  _CS_POSIX_V6_LPBIG_OFFBIG_LIBS,
  _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS,
  _CS_POSIX_V7_ILP32_OFF32_CFLAGS,
  _CS_POSIX_V7_ILP32_OFF32_LDFLAGS,
  _CS_POSIX_V7_ILP32_OFF32_LIBS,
  _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS,
  _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS,
  _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS,
  _CS_POSIX_V7_ILP32_OFFBIG_LIBS,
  _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS,
  _CS_POSIX_V7_LP64_OFF64_CFLAGS,
  _CS_POSIX_V7_LP64_OFF64_LDFLAGS,
  _CS_POSIX_V7_LP64_OFF64_LIBS,
  _CS_POSIX_V7_LP64_OFF64_LINTFLAGS,
  _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS,
  _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS,
  _CS_POSIX_V7_LPBIG_OFFBIG_LIBS,
  _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS,
  _CS_V6_ENV,
  _CS_V7_ENV
};
extern long int pathconf(const char *__path, int __name)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern long int fpathconf(int __fd, int __name)
    __attribute__((__nothrow__, __leaf__));
extern long int sysconf(int __name)
    __attribute__((__nothrow__, __leaf__));
extern size_t confstr(int __name, char *__buf, size_t __len)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__access__(__write_only__, 2, 3)));
extern __pid_t getpid(void) __attribute__((__nothrow__, __leaf__));
extern __pid_t getppid(void) __attribute__((__nothrow__, __leaf__));
extern __pid_t getpgrp(void) __attribute__((__nothrow__, __leaf__));
extern __pid_t __getpgid(__pid_t __pid)
    __attribute__((__nothrow__, __leaf__));
extern __pid_t getpgid(__pid_t __pid)
    __attribute__((__nothrow__, __leaf__));
extern int setpgid(__pid_t __pid, __pid_t __pgid)
    __attribute__((__nothrow__, __leaf__));
extern int setpgrp(void) __attribute__((__nothrow__, __leaf__));
extern __pid_t setsid(void) __attribute__((__nothrow__, __leaf__));
extern __pid_t getsid(__pid_t __pid)
    __attribute__((__nothrow__, __leaf__));
extern __uid_t getuid(void) __attribute__((__nothrow__, __leaf__));
extern __uid_t geteuid(void) __attribute__((__nothrow__, __leaf__));
extern __gid_t getgid(void) __attribute__((__nothrow__, __leaf__));
extern __gid_t getegid(void) __attribute__((__nothrow__, __leaf__));
extern int getgroups(int __size, __gid_t __list[])
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__access__(__write_only__, 2, 1)));
extern int group_member(__gid_t __gid)
    __attribute__((__nothrow__, __leaf__));
extern int setuid(__uid_t __uid) __attribute__((__nothrow__, __leaf__));
extern int setreuid(__uid_t __ruid, __uid_t __euid)
    __attribute__((__nothrow__, __leaf__));
extern int seteuid(__uid_t __uid)
    __attribute__((__nothrow__, __leaf__));
extern int setgid(__gid_t __gid) __attribute__((__nothrow__, __leaf__));
extern int setregid(__gid_t __rgid, __gid_t __egid)
    __attribute__((__nothrow__, __leaf__));
extern int setegid(__gid_t __gid)
    __attribute__((__nothrow__, __leaf__));
extern int getresuid(__uid_t *__ruid, __uid_t *__euid, __uid_t *__suid)
    __attribute__((__nothrow__, __leaf__));
extern int getresgid(__gid_t *__rgid, __gid_t *__egid, __gid_t *__sgid)
    __attribute__((__nothrow__, __leaf__));
extern int setresuid(__uid_t __ruid, __uid_t __euid, __uid_t __suid)
    __attribute__((__nothrow__, __leaf__));
extern int setresgid(__gid_t __rgid, __gid_t __egid, __gid_t __sgid)
    __attribute__((__nothrow__, __leaf__));
extern __pid_t fork(void) __attribute__((__nothrow__));
extern __pid_t vfork(void) __attribute__((__nothrow__, __leaf__));
extern __pid_t _Fork(void) __attribute__((__nothrow__, __leaf__));
extern char *ttyname(int __fd) __attribute__((__nothrow__, __leaf__));
extern int ttyname_r(int __fd, char *__buf, size_t __buflen)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)))
    __attribute__((__access__(__write_only__, 2, 3)));
extern int isatty(int __fd) __attribute__((__nothrow__, __leaf__));
extern int ttyslot(void) __attribute__((__nothrow__, __leaf__));
extern int link(const char *__from, const char *__to)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int linkat(int __fromfd, const char *__from, int __tofd,
                  const char *__to, int __flags)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 4)));
extern int symlink(const char *__from, const char *__to)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern ssize_t readlink(const char *__restrict __path,
                        char *__restrict __buf, size_t __len)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)))
    __attribute__((__access__(__write_only__, 2, 3)));
extern int symlinkat(const char *__from, int __tofd,
                     const char *__to)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 3)));
extern ssize_t readlinkat(int __fd, const char *__restrict __path,
                          char *__restrict __buf, size_t __len)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 3)))
    __attribute__((__access__(__write_only__, 3, 4)));
extern int unlink(const char *__name)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int unlinkat(int __fd, const char *__name, int __flag)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int rmdir(const char *__path)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern __pid_t tcgetpgrp(int __fd)
    __attribute__((__nothrow__, __leaf__));
extern int tcsetpgrp(int __fd, __pid_t __pgrp_id)
    __attribute__((__nothrow__, __leaf__));
extern char *getlogin(void);
extern int getlogin_r(char *__name, size_t __name_len)
    __attribute__((__nonnull__(1)))
    __attribute__((__access__(__write_only__, 1, 2)));
extern int setlogin(const char *__name)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern char *optarg;
extern int optind;
extern int opterr;
extern int optopt;
extern int getopt(int ___argc, char *const *___argv,
                  const char *__shortopts)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 3)));
extern int gethostname(char *__name, size_t __len)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__access__(__write_only__, 1, 2)));
extern int sethostname(const char *__name, size_t __len)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__access__(__read_only__, 1, 2)));
extern int sethostid(long int __id)
    __attribute__((__nothrow__, __leaf__));
extern int getdomainname(char *__name, size_t __len)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__access__(__write_only__, 1, 2)));
extern int setdomainname(const char *__name, size_t __len)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__access__(__read_only__, 1, 2)));
extern int vhangup(void) __attribute__((__nothrow__, __leaf__));
extern int revoke(const char *__file)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int profil(unsigned short int *__sample_buffer, size_t __size,
                  size_t __offset, unsigned int __scale)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int acct(const char *__name)
    __attribute__((__nothrow__, __leaf__));
extern char *getusershell(void) __attribute__((__nothrow__, __leaf__));
extern void endusershell(void) __attribute__((__nothrow__, __leaf__));
extern void setusershell(void) __attribute__((__nothrow__, __leaf__));
extern int daemon(int __nochdir, int __noclose)
    __attribute__((__nothrow__, __leaf__));
extern int chroot(const char *__path)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern char *getpass(const char *__prompt)
    __attribute__((__nonnull__(1)));
extern int fsync(int __fd);
extern int syncfs(int __fd) __attribute__((__nothrow__, __leaf__));
extern long int gethostid(void);
extern void sync(void) __attribute__((__nothrow__, __leaf__));
extern int getpagesize(void) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));
extern int getdtablesize(void) __attribute__((__nothrow__, __leaf__));
extern int truncate(const char *__file,
                    __off64_t __length) __asm__(""
                                                "truncate64")
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int truncate64(const char *__file, __off64_t __length)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int ftruncate(int __fd,
                     __off64_t __length) __asm__(""
                                                 "ftruncate64")
    __attribute__((__nothrow__, __leaf__));
extern int ftruncate64(int __fd, __off64_t __length)
    __attribute__((__nothrow__, __leaf__));
extern int brk(void *__addr) __attribute__((__nothrow__, __leaf__));
extern void *sbrk(intptr_t __delta)
    __attribute__((__nothrow__, __leaf__));
extern long int syscall(long int __sysno, ...)
    __attribute__((__nothrow__, __leaf__));
extern int lockf(int __fd, int __cmd,
                 __off64_t __len) __asm__(""
                                          "lockf64");
extern int lockf64(int __fd, int __cmd, __off64_t __len);
ssize_t copy_file_range(int __infd, __off64_t *__pinoff,
                        int __outfd, __off64_t *__poutoff,
                        size_t __length, unsigned int __flags);
extern int fdatasync(int __fildes);
extern char *crypt(const char *__key, const char *__salt)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern void swab(const void *__restrict __from, void *__restrict __to,
                 ssize_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)))
__attribute__((__access__(__read_only__, 1, 3)))
__attribute__((__access__(__write_only__, 2, 3)));
int getentropy(void *__buffer, size_t __length)
    __attribute__((__access__(__write_only__, 1, 2)));
extern int close_range(unsigned int __fd, unsigned int __max_fd,
                       int __flags)
    __attribute__((__nothrow__, __leaf__));
extern __pid_t gettid(void) __attribute__((__nothrow__, __leaf__));
typedef int __gwchar_t;
typedef struct
{
  long int quot;
  long int rem;
} imaxdiv_t;
extern intmax_t imaxabs(intmax_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern imaxdiv_t imaxdiv(intmax_t __numer, intmax_t __denom)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern intmax_t strtoimax(const char *__restrict __nptr,
                          char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__));
extern uintmax_t strtoumax(const char *__restrict __nptr,
                           char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__));
extern intmax_t wcstoimax(const __gwchar_t *__restrict __nptr,
                          __gwchar_t **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__));
extern uintmax_t wcstoumax(const __gwchar_t *__restrict __nptr,
                           __gwchar_t **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__));
enum
{
  _ISupper = ((0) < 8 ? ((1 << (0)) << 8) : ((1 << (0)) >> 8)),
  _ISlower = ((1) < 8 ? ((1 << (1)) << 8) : ((1 << (1)) >> 8)),
  _ISalpha = ((2) < 8 ? ((1 << (2)) << 8) : ((1 << (2)) >> 8)),
  _ISdigit = ((3) < 8 ? ((1 << (3)) << 8) : ((1 << (3)) >> 8)),
  _ISxdigit = ((4) < 8 ? ((1 << (4)) << 8) : ((1 << (4)) >> 8)),
  _ISspace = ((5) < 8 ? ((1 << (5)) << 8) : ((1 << (5)) >> 8)),
  _ISprint = ((6) < 8 ? ((1 << (6)) << 8) : ((1 << (6)) >> 8)),
  _ISgraph = ((7) < 8 ? ((1 << (7)) << 8) : ((1 << (7)) >> 8)),
  _ISblank = ((8) < 8 ? ((1 << (8)) << 8) : ((1 << (8)) >> 8)),
  _IScntrl = ((9) < 8 ? ((1 << (9)) << 8) : ((1 << (9)) >> 8)),
  _ISpunct = ((10) < 8 ? ((1 << (10)) << 8) : ((1 << (10)) >> 8)),
  _ISalnum = ((11) < 8 ? ((1 << (11)) << 8) : ((1 << (11)) >> 8))
};
extern const unsigned short int **__ctype_b_loc(void)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern const __int32_t **__ctype_tolower_loc(void)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern const __int32_t **__ctype_toupper_loc(void)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern int isalnum(int) __attribute__((__nothrow__, __leaf__));
extern int isalpha(int) __attribute__((__nothrow__, __leaf__));
extern int iscntrl(int) __attribute__((__nothrow__, __leaf__));
extern int isdigit(int) __attribute__((__nothrow__, __leaf__));
extern int islower(int) __attribute__((__nothrow__, __leaf__));
extern int isgraph(int) __attribute__((__nothrow__, __leaf__));
extern int isprint(int) __attribute__((__nothrow__, __leaf__));
extern int ispunct(int) __attribute__((__nothrow__, __leaf__));
extern int isspace(int) __attribute__((__nothrow__, __leaf__));
extern int isupper(int) __attribute__((__nothrow__, __leaf__));
extern int isxdigit(int) __attribute__((__nothrow__, __leaf__));
extern int tolower(int __c) __attribute__((__nothrow__, __leaf__));
extern int toupper(int __c) __attribute__((__nothrow__, __leaf__));
extern int isblank(int) __attribute__((__nothrow__, __leaf__));
extern int isctype(int __c, int __mask)
    __attribute__((__nothrow__, __leaf__));
extern int isascii(int __c) __attribute__((__nothrow__, __leaf__));
extern int toascii(int __c) __attribute__((__nothrow__, __leaf__));
extern int _toupper(int) __attribute__((__nothrow__, __leaf__));
extern int _tolower(int) __attribute__((__nothrow__, __leaf__));
extern __inline __attribute__((__gnu_inline__)) int __attribute__((__nothrow__, __leaf__)) tolower(int __c)
{
  return __c >= -128 && __c < 256 ? (*__ctype_tolower_loc())[__c] : __c;
}

extern __inline __attribute__((__gnu_inline__)) int __attribute__((__nothrow__, __leaf__)) toupper(int __c)
{
  return __c >= -128 && __c < 256 ? (*__ctype_toupper_loc())[__c] : __c;
}

extern int isalnum_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int isalpha_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int iscntrl_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int isdigit_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int islower_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int isgraph_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int isprint_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int ispunct_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int isspace_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int isupper_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int isxdigit_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int isblank_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int __tolower_l(int __c, locale_t __l)
    __attribute__((__nothrow__, __leaf__));
extern int tolower_l(int __c, locale_t __l)
    __attribute__((__nothrow__, __leaf__));
extern int __toupper_l(int __c, locale_t __l)
    __attribute__((__nothrow__, __leaf__));
extern int toupper_l(int __c, locale_t __l)
    __attribute__((__nothrow__, __leaf__));
extern void __assert_fail(const char *__assertion, const char *__file,
                          unsigned int __line, const char *__function)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern void __assert_perror_fail(int __errnum, const char *__file,
                                 unsigned int __line, const char *__function)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern void __assert(const char *__assertion, const char *__file, int __line)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern long int __sysconf(int __name) __attribute__((__nothrow__, __leaf__));
struct sched_param
{
  int sched_priority;
};
extern int clone(int (*__fn)(void *__arg), void *__child_stack,
                 int __flags, void *__arg, ...)
    __attribute__((__nothrow__, __leaf__));
extern int unshare(int __flags) __attribute__((__nothrow__, __leaf__));
extern int sched_getcpu(void) __attribute__((__nothrow__, __leaf__));
extern int getcpu(unsigned int *, unsigned int *)
    __attribute__((__nothrow__, __leaf__));
extern int setns(int __fd, int __nstype)
    __attribute__((__nothrow__, __leaf__));
typedef unsigned long int __cpu_mask;
typedef struct
{
  __cpu_mask __bits[1024 / (8 * sizeof(__cpu_mask))];
} cpu_set_t;
extern int __sched_cpucount(size_t __setsize, const cpu_set_t *__setp)
    __attribute__((__nothrow__, __leaf__));
extern cpu_set_t *__sched_cpualloc(size_t __count)
    __attribute__((__nothrow__, __leaf__));
extern void __sched_cpufree(cpu_set_t *__set)
    __attribute__((__nothrow__, __leaf__));
extern int sched_setparam(__pid_t __pid, const struct sched_param *__param)
    __attribute__((__nothrow__, __leaf__));
extern int sched_getparam(__pid_t __pid, struct sched_param *__param)
    __attribute__((__nothrow__, __leaf__));
extern int sched_setscheduler(__pid_t __pid, int __policy,
                              const struct sched_param *__param)
    __attribute__((__nothrow__, __leaf__));
extern int sched_getscheduler(__pid_t __pid)
    __attribute__((__nothrow__, __leaf__));
extern int sched_yield(void) __attribute__((__nothrow__, __leaf__));
extern int sched_get_priority_max(int __algorithm)
    __attribute__((__nothrow__, __leaf__));
extern int sched_get_priority_min(int __algorithm)
    __attribute__((__nothrow__, __leaf__));
extern int sched_rr_get_interval(__pid_t __pid, struct timespec *__t)
    __attribute__((__nothrow__, __leaf__));
extern int sched_setaffinity(__pid_t __pid, size_t __cpusetsize,
                             const cpu_set_t *__cpuset)
    __attribute__((__nothrow__, __leaf__));
extern int sched_getaffinity(__pid_t __pid, size_t __cpusetsize,
                             cpu_set_t *__cpuset)
    __attribute__((__nothrow__, __leaf__));
typedef cpu_set_t rte_cpuset_t;
typedef uint64_t unaligned_uint64_t;
typedef uint32_t unaligned_uint32_t;
typedef uint16_t unaligned_uint16_t;
static inline int
rte_is_aligned(const void *const restrict ptr, const unsigned int align)
{
  return ((uintptr_t)ptr & (align - 1)) == 0;
}

typedef uint64_t phys_addr_t;
typedef uint64_t rte_iova_t;
__extension__ typedef void *RTE_MARKER[0];
__extension__ typedef uint8_t RTE_MARKER8[0];
__extension__ typedef uint16_t RTE_MARKER16[0];
__extension__ typedef uint32_t RTE_MARKER32[0];
__extension__ typedef uint64_t RTE_MARKER64[0];
uint64_t rte_str_to_size(const char *str);
__attribute__((noreturn)) void
rte_exit(int exit_code, const char *format, ...)
    __attribute__((format(gnu_printf, 2, 3)));
int rte_strsplit(char *string, int stringlen,
                 char **tokens, int maxtokens, char delim);
static inline size_t
rte_strlcpy(char *dst, const char *src, size_t size)
{
  return (size_t)snprintf(dst, size, "%s", src);
}

static inline size_t
rte_strlcat(char *dst, const char *src, size_t size)
{
  size_t l = strnlen(dst, size);
  if (l < size)
    return l + rte_strlcpy(&dst[l], src, size - l);
  return l + strlen(src);
}

ssize_t rte_strscpy(char *dst, const char *src, size_t dsize);
__attribute__((section(".text.experimental"))) static inline const char *
rte_str_skip_leading_spaces(const char *src)
{
  const char *p = src;
  while (((*__ctype_b_loc())[(int)((*p))] & (unsigned short int)_ISspace))
    p++;
  return p;
}

typedef long int ptrdiff_t;
typedef struct
{
  long long __max_align_ll
      __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld
      __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;
extern void __assert_fail(const char *__assertion, const char *__file,
                          unsigned int __line, const char *__function)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern void __assert_perror_fail(int __errnum, const char *__file,
                                 unsigned int __line, const char *__function)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern void __assert(const char *__assertion, const char *__file, int __line)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
int rte_openlog_stream(FILE *f);
FILE *rte_log_get_stream(void);
void rte_log_set_global_level(uint32_t level);
uint32_t rte_log_get_global_level(void);
int rte_log_get_level(uint32_t logtype);
_Bool rte_log_can_log(uint32_t logtype, uint32_t loglevel);
int rte_log_set_level_pattern(const char *pattern, uint32_t level);
int rte_log_set_level_regexp(const char *regex, uint32_t level);
int rte_log_set_level(uint32_t logtype, uint32_t level);
int rte_log_cur_msg_loglevel(void);
int rte_log_cur_msg_logtype(void);
int rte_log_register(const char *name);
int rte_log_register_type_and_pick_level(const char *name,
                                         uint32_t level_def);
void rte_log_list_types(FILE *out, const char *prefix);
void rte_log_dump(FILE *f);
int rte_log(uint32_t level, uint32_t logtype, const char *format, ...)
    __attribute__((cold)) __attribute__((format(gnu_printf, 3, 4)));
int rte_vlog(uint32_t level, uint32_t logtype, const char *format,
             va_list ap) __attribute__((format(gnu_printf, 3, 0)));
void rte_dump_stack(void);
void __rte_panic(const char *funcname, const char *format, ...)
    __attribute__((cold))
    __attribute__((noreturn)) __attribute__((format(gnu_printf, 2, 3)));
static inline uint32_t
rte_bit_relaxed_get32(unsigned int nr, volatile uint32_t *addr)
{
  do
  {
  } while (0);
  uint32_t mask = 1U << nr;
  return (*addr) & mask;
}

static inline void
rte_bit_relaxed_set32(unsigned int nr, volatile uint32_t *addr)
{
  do
  {
  } while (0);
  uint32_t mask = (1U << (nr));
  *addr = (*addr) | mask;
}

static inline void
rte_bit_relaxed_clear32(unsigned int nr, volatile uint32_t *addr)
{
  do
  {
  } while (0);
  uint32_t mask = (1U << (nr));
  *addr = (*addr) & (~mask);
}

static inline uint32_t
rte_bit_relaxed_test_and_set32(unsigned int nr, volatile uint32_t *addr)
{
  do
  {
  } while (0);
  uint32_t mask = (1U << (nr));
  uint32_t val = *addr;
  *addr = val | mask;
  return val & mask;
}

static inline uint32_t
rte_bit_relaxed_test_and_clear32(unsigned int nr, volatile uint32_t *addr)
{
  do
  {
  } while (0);
  uint32_t mask = (1U << (nr));
  uint32_t val = *addr;
  *addr = val & (~mask);
  return val & mask;
}

static inline uint64_t
rte_bit_relaxed_get64(unsigned int nr, volatile uint64_t *addr)
{
  do
  {
  } while (0);
  uint64_t mask = (1UL << (nr));
  return (*addr) & mask;
}

static inline void
rte_bit_relaxed_set64(unsigned int nr, volatile uint64_t *addr)
{
  do
  {
  } while (0);
  uint64_t mask = (1UL << (nr));
  (*addr) = (*addr) | mask;
}

static inline void
rte_bit_relaxed_clear64(unsigned int nr, volatile uint64_t *addr)
{
  do
  {
  } while (0);
  uint64_t mask = (1UL << (nr));
  *addr = (*addr) & (~mask);
}

static inline uint64_t
rte_bit_relaxed_test_and_set64(unsigned int nr, volatile uint64_t *addr)
{
  do
  {
  } while (0);
  uint64_t mask = (1UL << (nr));
  uint64_t val = *addr;
  *addr = val | mask;
  return val;
}

static inline uint64_t
rte_bit_relaxed_test_and_clear64(unsigned int nr, volatile uint64_t *addr)
{
  do
  {
  } while (0);
  uint64_t mask = (1UL << (nr));
  uint64_t val = *addr;
  *addr = val & (~mask);
  return val & mask;
}

static inline unsigned int
rte_clz32(uint32_t v)
{
  return (unsigned int)__builtin_clz(v);
}

static inline unsigned int
rte_clz64(uint64_t v)
{
  return (unsigned int)__builtin_clzll(v);
}

static inline unsigned int
rte_ctz32(uint32_t v)
{
  return (unsigned int)__builtin_ctz(v);
}

static inline unsigned int
rte_ctz64(uint64_t v)
{
  return (unsigned int)__builtin_ctzll(v);
}

static inline unsigned int
rte_popcount32(uint32_t v)
{
  return (unsigned int)__builtin_popcount(v);
}

static inline unsigned int
rte_popcount64(uint64_t v)
{
  return (unsigned int)__builtin_popcountll(v);
}

static inline uint32_t
rte_combine32ms1b(uint32_t x)
{
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;
  return x;
}

static inline uint64_t
rte_combine64ms1b(uint64_t v)
{
  v |= v >> 1;
  v |= v >> 2;
  v |= v >> 4;
  v |= v >> 8;
  v |= v >> 16;
  v |= v >> 32;
  return v;
}

static inline uint32_t
rte_bsf32(uint32_t v)
{
  return (uint32_t)rte_ctz32(v);
}

static inline int
rte_bsf32_safe(uint32_t v, uint32_t *pos)
{
  if (v == 0)
    return 0;
  *pos = rte_bsf32(v);
  return 1;
}

static inline uint32_t
rte_bsf64(uint64_t v)
{
  return (uint32_t)rte_ctz64(v);
}

static inline int
rte_bsf64_safe(uint64_t v, uint32_t *pos)
{
  if (v == 0)
    return 0;
  *pos = rte_bsf64(v);
  return 1;
}

static inline uint32_t
rte_fls_u32(uint32_t x)
{
  return (x == 0) ? 0 : 32 - rte_clz32(x);
}

static inline uint32_t
rte_fls_u64(uint64_t x)
{
  return (x == 0) ? 0 : 64 - rte_clz64(x);
}

static inline int
rte_is_power_of_2(uint32_t n)
{
  return n && !(n & (n - 1));
}

static inline uint32_t
rte_align32pow2(uint32_t x)
{
  x--;
  x = rte_combine32ms1b(x);
  return x + 1;
}

static inline uint32_t
rte_align32prevpow2(uint32_t x)
{
  x = rte_combine32ms1b(x);
  return x - (x >> 1);
}

static inline uint64_t
rte_align64pow2(uint64_t v)
{
  v--;
  v = rte_combine64ms1b(v);
  return v + 1;
}

static inline uint64_t
rte_align64prevpow2(uint64_t v)
{
  v = rte_combine64ms1b(v);
  return v - (v >> 1);
}

static inline uint32_t
rte_log2_u32(uint32_t v)
{
  if (v == 0)
    return 0;
  v = rte_align32pow2(v);
  return rte_bsf32(v);
}

static inline uint32_t
rte_log2_u64(uint64_t v)
{
  if (v == 0)
    return 0;
  v = rte_align64pow2(v);
  return rte_bsf64(v);
}

extern void __assert_fail(const char *__assertion, const char *__file,
                          unsigned int __line, const char *__function)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern void __assert_perror_fail(int __errnum, const char *__file,
                                 unsigned int __line, const char *__function)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern void __assert(const char *__assertion, const char *__file, int __line)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
typedef int rte_memory_order;
static inline void rte_atomic_thread_fence(rte_memory_order memorder);
static inline int
rte_atomic16_cmpset(volatile uint16_t *dst, uint16_t exp, uint16_t src);
static inline int
rte_atomic16_cmpset(volatile uint16_t *dst, uint16_t exp, uint16_t src)
{
  return __sync_bool_compare_and_swap(dst, exp, src);
}

static inline uint16_t
rte_atomic16_exchange(volatile uint16_t *dst, uint16_t val);
static inline uint16_t
rte_atomic16_exchange(volatile uint16_t *dst, uint16_t val)
{
  return __atomic_exchange_n(dst, val, 5);
}

typedef struct
{
  volatile int16_t cnt;
} rte_atomic16_t;
static inline void
rte_atomic16_init(rte_atomic16_t *v)
{
  v->cnt = 0;
}

static inline int16_t
rte_atomic16_read(const rte_atomic16_t *v)
{
  return v->cnt;
}

static inline void
rte_atomic16_set(rte_atomic16_t *v, int16_t new_value)
{
  v->cnt = new_value;
}

static inline void
rte_atomic16_add(rte_atomic16_t *v, int16_t inc)
{
  __atomic_fetch_add((volatile int16_t *)&v->cnt, inc, 5);
}

static inline void
rte_atomic16_sub(rte_atomic16_t *v, int16_t dec)
{
  __atomic_fetch_sub((volatile int16_t *)&v->cnt, dec, 5);
}

static inline void rte_atomic16_inc(rte_atomic16_t *v);
static inline void
rte_atomic16_inc(rte_atomic16_t *v)
{
  rte_atomic16_add(v, 1);
}

static inline void rte_atomic16_dec(rte_atomic16_t *v);
static inline void
rte_atomic16_dec(rte_atomic16_t *v)
{
  rte_atomic16_sub(v, 1);
}

static inline int16_t
rte_atomic16_add_return(rte_atomic16_t *v, int16_t inc)
{
  return __atomic_fetch_add((volatile int16_t *)&v->cnt, inc, 5) + inc;
}

static inline int16_t
rte_atomic16_sub_return(rte_atomic16_t *v, int16_t dec)
{
  return __atomic_fetch_sub((volatile int16_t *)&v->cnt, dec, 5) - dec;
}

static inline int rte_atomic16_inc_and_test(rte_atomic16_t *v);
static inline int
rte_atomic16_inc_and_test(rte_atomic16_t *v)
{
  return __atomic_fetch_add((volatile int16_t *)&v->cnt, 1, 5) + 1 == 0;
}

static inline int rte_atomic16_dec_and_test(rte_atomic16_t *v);
static inline int
rte_atomic16_dec_and_test(rte_atomic16_t *v)
{
  return __atomic_fetch_sub((volatile int16_t *)&v->cnt, 1, 5) - 1 == 0;
}

static inline int rte_atomic16_test_and_set(rte_atomic16_t *v);
static inline int
rte_atomic16_test_and_set(rte_atomic16_t *v)
{
  return rte_atomic16_cmpset((volatile uint16_t *)&v->cnt, 0, 1);
}

static inline void
rte_atomic16_clear(rte_atomic16_t *v)
{
  v->cnt = 0;
}

static inline int
rte_atomic32_cmpset(volatile uint32_t *dst, uint32_t exp, uint32_t src);
static inline int
rte_atomic32_cmpset(volatile uint32_t *dst, uint32_t exp, uint32_t src)
{
  return __sync_bool_compare_and_swap(dst, exp, src);
}

static inline uint32_t
rte_atomic32_exchange(volatile uint32_t *dst, uint32_t val);
static inline uint32_t
rte_atomic32_exchange(volatile uint32_t *dst, uint32_t val)
{
  return __atomic_exchange_n(dst, val, 5);
}

typedef struct
{
  volatile int32_t cnt;
} rte_atomic32_t;
static inline void
rte_atomic32_init(rte_atomic32_t *v)
{
  v->cnt = 0;
}

static inline int32_t
rte_atomic32_read(const rte_atomic32_t *v)
{
  return v->cnt;
}

static inline void
rte_atomic32_set(rte_atomic32_t *v, int32_t new_value)
{
  v->cnt = new_value;
}

static inline void
rte_atomic32_add(rte_atomic32_t *v, int32_t inc)
{
  __atomic_fetch_add((volatile int32_t *)&v->cnt, inc, 5);
}

static inline void
rte_atomic32_sub(rte_atomic32_t *v, int32_t dec)
{
  __atomic_fetch_sub((volatile int32_t *)&v->cnt, dec, 5);
}

static inline void rte_atomic32_inc(rte_atomic32_t *v);
static inline void
rte_atomic32_inc(rte_atomic32_t *v)
{
  rte_atomic32_add(v, 1);
}

static inline void rte_atomic32_dec(rte_atomic32_t *v);
static inline void
rte_atomic32_dec(rte_atomic32_t *v)
{
  rte_atomic32_sub(v, 1);
}

static inline int32_t
rte_atomic32_add_return(rte_atomic32_t *v, int32_t inc)
{
  return __atomic_fetch_add((volatile int32_t *)&v->cnt, inc, 5) + inc;
}

static inline int32_t
rte_atomic32_sub_return(rte_atomic32_t *v, int32_t dec)
{
  return __atomic_fetch_sub((volatile int32_t *)&v->cnt, dec, 5) - dec;
}

static inline int rte_atomic32_inc_and_test(rte_atomic32_t *v);
static inline int
rte_atomic32_inc_and_test(rte_atomic32_t *v)
{
  return __atomic_fetch_add((volatile int32_t *)&v->cnt, 1, 5) + 1 == 0;
}

static inline int rte_atomic32_dec_and_test(rte_atomic32_t *v);
static inline int
rte_atomic32_dec_and_test(rte_atomic32_t *v)
{
  return __atomic_fetch_sub((volatile int32_t *)&v->cnt, 1, 5) - 1 == 0;
}

static inline int rte_atomic32_test_and_set(rte_atomic32_t *v);
static inline int
rte_atomic32_test_and_set(rte_atomic32_t *v)
{
  return rte_atomic32_cmpset((volatile uint32_t *)&v->cnt, 0, 1);
}

static inline void
rte_atomic32_clear(rte_atomic32_t *v)
{
  v->cnt = 0;
}

static inline int
rte_atomic64_cmpset(volatile uint64_t *dst, uint64_t exp, uint64_t src);
static inline int
rte_atomic64_cmpset(volatile uint64_t *dst, uint64_t exp, uint64_t src)
{
  return __sync_bool_compare_and_swap(dst, exp, src);
}

static inline uint64_t
rte_atomic64_exchange(volatile uint64_t *dst, uint64_t val);
static inline uint64_t
rte_atomic64_exchange(volatile uint64_t *dst, uint64_t val)
{
  return __atomic_exchange_n(dst, val, 5);
}

typedef struct
{
  volatile int64_t cnt;
} rte_atomic64_t;
static inline void rte_atomic64_init(rte_atomic64_t *v);
static inline void
rte_atomic64_init(rte_atomic64_t *v)
{
  v->cnt = 0;
}

static inline int64_t rte_atomic64_read(rte_atomic64_t *v);
static inline int64_t
rte_atomic64_read(rte_atomic64_t *v)
{
  return v->cnt;
}

static inline void rte_atomic64_set(rte_atomic64_t *v, int64_t new_value);
static inline void
rte_atomic64_set(rte_atomic64_t *v, int64_t new_value)
{
  v->cnt = new_value;
}

static inline void rte_atomic64_add(rte_atomic64_t *v, int64_t inc);
static inline void
rte_atomic64_add(rte_atomic64_t *v, int64_t inc)
{
  __atomic_fetch_add((volatile int64_t *)&v->cnt, inc, 5);
}

static inline void rte_atomic64_sub(rte_atomic64_t *v, int64_t dec);
static inline void
rte_atomic64_sub(rte_atomic64_t *v, int64_t dec)
{
  __atomic_fetch_sub((volatile int64_t *)&v->cnt, dec, 5);
}

static inline void rte_atomic64_inc(rte_atomic64_t *v);
static inline void
rte_atomic64_inc(rte_atomic64_t *v)
{
  rte_atomic64_add(v, 1);
}

static inline void rte_atomic64_dec(rte_atomic64_t *v);
static inline void
rte_atomic64_dec(rte_atomic64_t *v)
{
  rte_atomic64_sub(v, 1);
}

static inline int64_t
rte_atomic64_add_return(rte_atomic64_t *v, int64_t inc);
static inline int64_t
rte_atomic64_add_return(rte_atomic64_t *v, int64_t inc)
{
  return __atomic_fetch_add((volatile int64_t *)&v->cnt, inc, 5) + inc;
}

static inline int64_t
rte_atomic64_sub_return(rte_atomic64_t *v, int64_t dec);
static inline int64_t
rte_atomic64_sub_return(rte_atomic64_t *v, int64_t dec)
{
  return __atomic_fetch_sub((volatile int64_t *)&v->cnt, dec, 5) - dec;
}

static inline int rte_atomic64_inc_and_test(rte_atomic64_t *v);
static inline int
rte_atomic64_inc_and_test(rte_atomic64_t *v)
{
  return rte_atomic64_add_return(v, 1) == 0;
}

static inline int rte_atomic64_dec_and_test(rte_atomic64_t *v);
static inline int
rte_atomic64_dec_and_test(rte_atomic64_t *v)
{
  return rte_atomic64_sub_return(v, 1) == 0;
}

static inline int rte_atomic64_test_and_set(rte_atomic64_t *v);
static inline int
rte_atomic64_test_and_set(rte_atomic64_t *v)
{
  return rte_atomic64_cmpset((volatile uint64_t *)&v->cnt, 0, 1);
}

static inline void rte_atomic64_clear(rte_atomic64_t *v);
static inline void
rte_atomic64_clear(rte_atomic64_t *v)
{
  rte_atomic64_set(v, 0);
}

typedef struct __attribute__((__aligned__(16)))
{
  union
  {
    uint64_t val[2];
    __extension__ __int128 int128;
  };
} rte_int128_t;

static inline __attribute__((always_inline)) void rte_atomic_thread_fence(rte_memory_order memorder)
{
  __atomic_thread_fence(memorder);
}

extern void __assert_fail(const char *__assertion, const char *__file,
                          unsigned int __line, const char *__function)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern void __assert_perror_fail(int __errnum, const char *__file,
                                 unsigned int __line, const char *__function)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern void __assert(const char *__assertion, const char *__file, int __line)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
static inline void rte_pause(void);
static inline __attribute__((always_inline)) void
rte_wait_until_equal_16(volatile uint16_t *addr, uint16_t expected,
                        rte_memory_order memorder);
static inline __attribute__((always_inline)) void
rte_wait_until_equal_32(volatile uint32_t *addr, uint32_t expected,
                        rte_memory_order memorder);
static inline __attribute__((always_inline)) void
rte_wait_until_equal_64(volatile uint64_t *addr, uint64_t expected,
                        rte_memory_order memorder);
static inline __attribute__((always_inline)) void
rte_wait_until_equal_16(volatile uint16_t *addr, uint16_t expected,
                        rte_memory_order memorder)
{
  ((memorder == 2 || memorder ==
                         0)
       ? (void)(0)
       : __assert_fail("memorder == rte_memory_order_acquire || memorder == rte_memory_order_relaxed",
                       "../lib/eal/include/generic/rte_pause.h", 83,
                       __extension__ __PRETTY_FUNCTION__));
  while (__atomic_load_n((volatile uint16_t *)addr, memorder) != expected)
    rte_pause();
}

static inline __attribute__((always_inline)) void
rte_wait_until_equal_32(volatile uint32_t *addr, uint32_t expected,
                        rte_memory_order memorder)
{
  ((memorder == 2 || memorder ==
                         0)
       ? (void)(0)
       : __assert_fail("memorder == rte_memory_order_acquire || memorder == rte_memory_order_relaxed",
                       "../lib/eal/include/generic/rte_pause.h", 94,
                       __extension__ __PRETTY_FUNCTION__));
  while (__atomic_load_n((volatile uint32_t *)addr, memorder) != expected)
    rte_pause();
}

static inline __attribute__((always_inline)) void
rte_wait_until_equal_64(volatile uint64_t *addr, uint64_t expected,
                        rte_memory_order memorder)
{
  ((memorder == 2 || memorder ==
                         0)
       ? (void)(0)
       : __assert_fail("memorder == rte_memory_order_acquire || memorder == rte_memory_order_relaxed",
                       "../lib/eal/include/generic/rte_pause.h", 105,
                       __extension__ __PRETTY_FUNCTION__));
  while (__atomic_load_n((volatile uint64_t *)addr, memorder) != expected)
    rte_pause();
}

static inline void
rte_pause(void)
{
  __asm__ volatile(".int 0x0100000F" ::: "memory");
}

typedef struct
{
  int32_t cnt;
} rte_rwlock_t;
static inline void
rte_rwlock_init(rte_rwlock_t *rwl)
{
  rwl->cnt = 0;
}

static inline void
rte_rwlock_read_lock(rte_rwlock_t *rwl)
{
  int32_t x;
  while (1)
  {
    while (__atomic_load_n(&rwl->cnt, 0) & (0x1 | 0x2))
      rte_pause();
    x = __atomic_fetch_add(&rwl->cnt, 0x4, 2) + 0x4;
    if (__builtin_expect(!!(!(x & (0x1 | 0x2))), 1))
      return;
    __atomic_fetch_sub(&rwl->cnt, 0x4, 0);
  }
}

static inline int
rte_rwlock_read_trylock(rte_rwlock_t *rwl)
{
  int32_t x;
  x = __atomic_load_n(&rwl->cnt, 0);
  if (x & (0x1 | 0x2))
    return -16;
  x = __atomic_fetch_add(&rwl->cnt, 0x4, 2) + 0x4;
  if (__builtin_expect(!!(x & (0x1 | 0x2)), 0))
  {
    __atomic_fetch_sub(&rwl->cnt, 0x4, 3);
    return -16;
  }
  return 0;
}

static inline void
rte_rwlock_read_unlock(rte_rwlock_t *rwl)
{
  __atomic_fetch_sub(&rwl->cnt, 0x4, 3);
}

static inline int
rte_rwlock_write_trylock(rte_rwlock_t *rwl)
{
  int32_t x;
  x = __atomic_load_n(&rwl->cnt, 0);
  if (x < 0x2 &&
      __atomic_compare_exchange_n(&rwl->cnt, &x, x + 0x2, 1, 2, 0))
    return 0;
  else
    return -16;
}

static inline void
rte_rwlock_write_lock(rte_rwlock_t *rwl)
{
  int32_t x;
  while (1)
  {
    x = __atomic_load_n(&rwl->cnt, 0);
    if (__builtin_expect(!!(x < 0x2), 1))
    {
      if (__atomic_compare_exchange_n(&rwl->cnt, &x, 0x2, 1, 2, 0))
        return;
    }
    if (!(x & 0x1))
      __atomic_fetch_or(&rwl->cnt, 0x1, 0);
    while (__atomic_load_n(&rwl->cnt, 0) > 0x1)
      rte_pause();
  }
}

static inline void
rte_rwlock_write_unlock(rte_rwlock_t *rwl)
{
  __atomic_fetch_sub(&rwl->cnt, 0x2, 3);
}

static inline int
rte_rwlock_write_is_locked(rte_rwlock_t *rwl)
{
  if (__atomic_load_n(&rwl->cnt, 0) & 0x2)
    return 1;
  return 0;
}

static inline void rte_rwlock_read_lock_tm(rte_rwlock_t *rwl);
static inline void rte_rwlock_read_unlock_tm(rte_rwlock_t *rwl);
static inline void rte_rwlock_write_lock_tm(rte_rwlock_t *rwl);
static inline void rte_rwlock_write_unlock_tm(rte_rwlock_t *rwl);
static inline void
rte_rwlock_read_lock_tm(rte_rwlock_t *rwl)
{
  rte_rwlock_read_lock(rwl);
}

static inline void
rte_rwlock_read_unlock_tm(rte_rwlock_t *rwl)
{
  rte_rwlock_read_unlock(rwl);
}

static inline void
rte_rwlock_write_lock_tm(rte_rwlock_t *rwl)
{
  rte_rwlock_write_lock(rwl);
}

static inline void
rte_rwlock_write_unlock_tm(rte_rwlock_t *rwl)
{
  rte_rwlock_write_unlock(rwl);
}

struct timex
{
  unsigned int modes;
  __syscall_slong_t offset;
  __syscall_slong_t freq;
  __syscall_slong_t maxerror;
  __syscall_slong_t esterror;
  int status;
  __syscall_slong_t constant;
  __syscall_slong_t precision;
  __syscall_slong_t tolerance;
  struct timeval time;
  __syscall_slong_t tick;
  __syscall_slong_t ppsfreq;
  __syscall_slong_t jitter;
  int shift;
  __syscall_slong_t stabil;
  __syscall_slong_t jitcnt;
  __syscall_slong_t calcnt;
  __syscall_slong_t errcnt;
  __syscall_slong_t stbcnt;
  int tai;
  int : 32;
  int : 32;
  int : 32;
  int : 32;
  int : 32;
  int : 32;
  int : 32;
  int : 32;
  int : 32;
  int : 32;
  int : 32;
};
extern int clock_adjtime(__clockid_t __clock_id, struct timex *__utx)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
  long int tm_gmtoff;
  const char *tm_zone;
};
struct itimerspec
{
  struct timespec it_interval;
  struct timespec it_value;
};
struct sigevent;
extern clock_t clock(void) __attribute__((__nothrow__, __leaf__));
extern time_t time(time_t *__timer) __attribute__((__nothrow__, __leaf__));
extern double difftime(time_t __time1, time_t __time0)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern time_t mktime(struct tm *__tp) __attribute__((__nothrow__, __leaf__));
extern size_t strftime(char *__restrict __s, size_t __maxsize,
                       const char *__restrict __format,
                       const struct tm *__restrict __tp)
    __attribute__((__nothrow__, __leaf__));
extern char *strptime(const char *__restrict __s,
                      const char *__restrict __fmt, struct tm *__tp)
    __attribute__((__nothrow__, __leaf__));
extern size_t strftime_l(char *__restrict __s, size_t __maxsize,
                         const char *__restrict __format,
                         const struct tm *__restrict __tp,
                         locale_t __loc)
    __attribute__((__nothrow__, __leaf__));
extern char *strptime_l(const char *__restrict __s,
                        const char *__restrict __fmt, struct tm *__tp,
                        locale_t __loc)
    __attribute__((__nothrow__, __leaf__));
extern struct tm *gmtime(const time_t *__timer)
    __attribute__((__nothrow__, __leaf__));
extern struct tm *localtime(const time_t *__timer)
    __attribute__((__nothrow__, __leaf__));
extern struct tm *gmtime_r(const time_t *__restrict __timer,
                           struct tm *__restrict __tp)
    __attribute__((__nothrow__, __leaf__));
extern struct tm *localtime_r(const time_t *__restrict __timer,
                              struct tm *__restrict __tp)
    __attribute__((__nothrow__, __leaf__));
extern char *asctime(const struct tm *__tp)
    __attribute__((__nothrow__, __leaf__));
extern char *ctime(const time_t *__timer)
    __attribute__((__nothrow__, __leaf__));
extern char *asctime_r(const struct tm *__restrict __tp,
                       char *__restrict __buf)
    __attribute__((__nothrow__, __leaf__));
extern char *ctime_r(const time_t *__restrict __timer,
                     char *__restrict __buf)
    __attribute__((__nothrow__, __leaf__));
extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;
extern char *tzname[2];
extern void tzset(void) __attribute__((__nothrow__, __leaf__));
extern int daylight;
extern long int timezone;
extern time_t timegm(struct tm *__tp) __attribute__((__nothrow__, __leaf__));
extern time_t timelocal(struct tm *__tp)
    __attribute__((__nothrow__, __leaf__));
extern int dysize(int __year) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));
extern int nanosleep(const struct timespec *__requested_time,
                     struct timespec *__remaining);
extern int clock_getres(clockid_t __clock_id, struct timespec *__res)
    __attribute__((__nothrow__, __leaf__));
extern int clock_gettime(clockid_t __clock_id, struct timespec *__tp)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int clock_settime(clockid_t __clock_id, const struct timespec *__tp)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int clock_nanosleep(clockid_t __clock_id, int __flags,
                           const struct timespec *__req,
                           struct timespec *__rem);
extern int clock_getcpuclockid(pid_t __pid, clockid_t *__clock_id)
    __attribute__((__nothrow__, __leaf__));
extern int timer_create(clockid_t __clock_id,
                        struct sigevent *__restrict __evp,
                        timer_t *__restrict __timerid)
    __attribute__((__nothrow__, __leaf__));
extern int timer_delete(timer_t __timerid)
    __attribute__((__nothrow__, __leaf__));
extern int timer_settime(timer_t __timerid, int __flags,
                         const struct itimerspec *__restrict __value,
                         struct itimerspec *__restrict __ovalue)
    __attribute__((__nothrow__, __leaf__));
extern int timer_gettime(timer_t __timerid, struct itimerspec *__value)
    __attribute__((__nothrow__, __leaf__));
extern int timer_getoverrun(timer_t __timerid)
    __attribute__((__nothrow__, __leaf__));
extern int timespec_get(struct timespec *__ts, int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int timespec_getres(struct timespec *__ts, int __base)
    __attribute__((__nothrow__, __leaf__));
extern int getdate_err;
extern struct tm *getdate(const char *__string);
extern int getdate_r(const char *__restrict __string,
                     struct tm *__restrict __resbufp);
typedef unsigned char rte_uuid_t[16];
_Bool rte_uuid_is_null(const rte_uuid_t uu);
static inline void
rte_uuid_copy(rte_uuid_t dst, const rte_uuid_t src)
{
  memcpy(dst, src, sizeof(rte_uuid_t));
}

int rte_uuid_compare(const rte_uuid_t a, const rte_uuid_t b);
int rte_uuid_parse(const char *in, rte_uuid_t uu);
void rte_uuid_unparse(const rte_uuid_t uu, char *out, size_t len);
enum rte_intr_mode
{
  RTE_INTR_MODE_NONE = 0,
  RTE_INTR_MODE_LEGACY,
  RTE_INTR_MODE_MSI,
  RTE_INTR_MODE_MSIX
};
enum rte_proc_type_t
{
  RTE_PROC_AUTO = -1,
  RTE_PROC_PRIMARY = 0,
  RTE_PROC_SECONDARY,
  RTE_PROC_INVALID
};
enum rte_proc_type_t rte_eal_process_type(void);
int rte_eal_iopl_init(void);
int rte_eal_init(int argc, char **argv);
int rte_eal_cleanup(void);
int rte_eal_primary_proc_alive(const char *config_file_path);
_Bool rte_mp_disable(void);
struct rte_mp_msg
{
  char name[64];
  int len_param;
  int num_fds;
  uint8_t param[256];
  int fds[8];
};
struct rte_mp_reply
{
  int nb_sent;
  int nb_received;
  struct rte_mp_msg *msgs;
};
typedef int (*rte_mp_t)(const struct rte_mp_msg *msg, const void *peer);
typedef int (*rte_mp_async_reply_t)(const struct rte_mp_msg *request,
                                    const struct rte_mp_reply *reply);
int rte_mp_action_register(const char *name, rte_mp_t action);
void rte_mp_action_unregister(const char *name);
int rte_mp_sendmsg(struct rte_mp_msg *msg);
int rte_mp_request_sync(struct rte_mp_msg *req, struct rte_mp_reply *reply,
                        const struct timespec *ts);
int rte_mp_request_async(struct rte_mp_msg *req, const struct timespec *ts,
                         rte_mp_async_reply_t clb);
int rte_mp_reply(struct rte_mp_msg *msg, const char *peer);
typedef void (*rte_usage_hook_t)(const char *prgname);
rte_usage_hook_t rte_set_application_usage_hook(rte_usage_hook_t usage_func);
int rte_eal_has_hugepages(void);
int rte_eal_has_pci(void);
int rte_eal_create_uio_dev(void);
enum rte_intr_mode rte_eal_vfio_intr_mode(void);
void rte_eal_vfio_get_vf_token(rte_uuid_t vf_token);
int rte_sys_gettid(void);
extern __thread int per_lcore__thread_id;
static inline int
rte_gettid(void)
{
  if ((per_lcore__thread_id) == -1)
    (per_lcore__thread_id) = rte_sys_gettid();
  return (per_lcore__thread_id);
}

__attribute__((section(".text.internal")))
uint64_t
rte_eal_get_baseaddr(void);
enum rte_iova_mode
{
  RTE_IOVA_DC = 0,
  RTE_IOVA_PA = (1 << 0),
  RTE_IOVA_VA = (1 << 1)
};
enum rte_iova_mode rte_eal_iova_mode(void);
const char *rte_eal_mbuf_user_pool_ops(void);
const char *rte_eal_get_runtime_dir(void);
__attribute__((section(".text.internal"))) int rte_eal_parse_coremask(const char *coremask, int *cores);
enum rte_lcore_state_t
{
  WAIT,
  RUNNING,
};
typedef int(lcore_function_t)(void *);
int rte_eal_remote_launch(lcore_function_t *f, void *arg,
                          unsigned worker_id);
enum rte_rmt_call_main_t
{
  SKIP_MAIN = 0,
  CALL_MAIN,
};
int rte_eal_mp_remote_launch(lcore_function_t *f, void *arg,
                             enum rte_rmt_call_main_t call_main);
enum rte_lcore_state_t rte_eal_get_lcore_state(unsigned int worker_id);
int rte_eal_wait_lcore(unsigned worker_id);
void rte_eal_mp_wait_lcore(void);
typedef struct
{
  uintptr_t opaque_id;
} rte_thread_t;
typedef uint32_t (*rte_thread_func)(void *arg);
enum rte_thread_priority
{
  RTE_THREAD_PRIORITY_NORMAL = 0,
  RTE_THREAD_PRIORITY_REALTIME_CRITICAL = 1,
};
typedef struct
{
  enum rte_thread_priority priority;
  rte_cpuset_t cpuset;
} rte_thread_attr_t;
typedef struct eal_tls_key *rte_thread_key;
int rte_thread_create(rte_thread_t *thread_id,
                      const rte_thread_attr_t *thread_attr,
                      rte_thread_func thread_func, void *arg);
int rte_thread_create_control(rte_thread_t *thread, const char *name,
                              rte_thread_func thread_func, void *arg);
__attribute__((section(".text.internal"))) int
rte_thread_create_internal_control(rte_thread_t *id, const char *name,
                                   rte_thread_func func, void *arg);
int rte_thread_join(rte_thread_t thread_id, uint32_t *value_ptr);
int rte_thread_detach(rte_thread_t thread_id);
rte_thread_t rte_thread_self(void);
void rte_thread_set_name(rte_thread_t thread_id, const char *thread_name);
__attribute__((section(".text.internal"))) void rte_thread_set_prefixed_name(rte_thread_t id, const char *name);
int rte_thread_equal(rte_thread_t t1, rte_thread_t t2);
int rte_thread_attr_init(rte_thread_attr_t *attr);
int rte_thread_attr_set_priority(rte_thread_attr_t *thread_attr,
                                 enum rte_thread_priority priority);
int rte_thread_attr_set_affinity(rte_thread_attr_t *thread_attr,
                                 rte_cpuset_t *cpuset);
int rte_thread_attr_get_affinity(rte_thread_attr_t *thread_attr,
                                 rte_cpuset_t *cpuset);
int rte_thread_set_affinity_by_id(rte_thread_t thread_id,
                                  const rte_cpuset_t *cpuset);
int rte_thread_get_affinity_by_id(rte_thread_t thread_id,
                                  rte_cpuset_t *cpuset);
int rte_thread_set_affinity(rte_cpuset_t *cpusetp);
void rte_thread_get_affinity(rte_cpuset_t *cpusetp);
int rte_thread_get_priority(rte_thread_t thread_id,
                            enum rte_thread_priority *priority);
int rte_thread_set_priority(rte_thread_t thread_id,
                            enum rte_thread_priority priority);
int rte_thread_key_create(rte_thread_key *key,
                          void (*destructor)(void *));
int rte_thread_key_delete(rte_thread_key key);
int rte_thread_value_set(rte_thread_key key, const void *value);
void *rte_thread_value_get(rte_thread_key key);
extern __thread unsigned per_lcore__lcore_id;
enum rte_lcore_role_t
{
  ROLE_RTE,
  ROLE_OFF,
  ROLE_SERVICE,
  ROLE_NON_EAL,
};
enum rte_lcore_role_t rte_eal_lcore_role(unsigned int lcore_id);
int rte_lcore_has_role(unsigned int lcore_id, enum rte_lcore_role_t role);
static inline unsigned rte_lcore_id(void)
{
  return (per_lcore__lcore_id);
}

unsigned int rte_get_main_lcore(void);
unsigned int rte_lcore_count(void);
int rte_lcore_index(int lcore_id);
unsigned int rte_socket_id(void);
unsigned int rte_socket_count(void);
int rte_socket_id_by_idx(unsigned int idx);
unsigned int rte_lcore_to_socket_id(unsigned int lcore_id);
int rte_lcore_to_cpu_id(int lcore_id);
rte_cpuset_t rte_lcore_cpuset(unsigned int lcore_id);
int rte_lcore_is_enabled(unsigned int lcore_id);
unsigned int rte_get_next_lcore(unsigned int i, int skip_main, int wrap);
typedef int (*rte_lcore_init_cb)(unsigned int lcore_id, void *arg);
typedef void (*rte_lcore_uninit_cb)(unsigned int lcore_id, void *arg);
void *rte_lcore_callback_register(const char *name, rte_lcore_init_cb init,
                                  rte_lcore_uninit_cb uninit, void *arg);
void rte_lcore_callback_unregister(void *handle);
typedef int (*rte_lcore_iterate_cb)(unsigned int lcore_id, void *arg);
int rte_lcore_iterate(rte_lcore_iterate_cb cb, void *arg);
struct rte_lcore_usage
{
  uint64_t total_cycles;
  uint64_t busy_cycles;
};
typedef int (*rte_lcore_usage_cb)(unsigned int lcore_id,
                                  struct rte_lcore_usage *usage);
__attribute__((section(".text.experimental"))) void
rte_lcore_register_usage_cb(rte_lcore_usage_cb cb);
void rte_lcore_dump(FILE *f);
int rte_thread_register(void);
void rte_thread_unregister(void);
typedef struct
{
  volatile int
      locked;
} rte_spinlock_t;
static inline void
rte_spinlock_init(rte_spinlock_t *sl)
{
  sl->locked = 0;
}

static inline void rte_spinlock_lock(rte_spinlock_t *sl);
static inline void
rte_spinlock_lock(rte_spinlock_t *sl)
{
  int exp = 0;
  while (!__atomic_compare_exchange_n(&sl->locked, &exp, 1, 0, 2, 0))
  {
    rte_wait_until_equal_32((volatile uint32_t *)(uintptr_t)&sl->locked,
                            0, 0);
    exp = 0;
  }
}

static inline void rte_spinlock_unlock(rte_spinlock_t *sl);
static inline void
rte_spinlock_unlock(rte_spinlock_t *sl)
{
  __atomic_store_n(&sl->locked, 0, 3);
}

__attribute__((warn_unused_result)) static inline int rte_spinlock_trylock(rte_spinlock_t *sl);
static inline int rte_spinlock_trylock(rte_spinlock_t *sl)
{
  int exp = 0;
  return __atomic_compare_exchange_n(&sl->locked, &exp, 1, 0, 2, 0);
}

static inline int
rte_spinlock_is_locked(rte_spinlock_t *sl)
{
  return __atomic_load_n(&sl->locked, 2);
}

static inline int rte_tm_supported(void);
static inline void rte_spinlock_lock_tm(rte_spinlock_t *sl);
static inline void rte_spinlock_unlock_tm(rte_spinlock_t *sl);
__attribute__((warn_unused_result)) static inline int
rte_spinlock_trylock_tm(rte_spinlock_t *sl);
typedef struct
{
  rte_spinlock_t
      sl;
  volatile int
      user;
  volatile int
      count;
} rte_spinlock_recursive_t;
static inline void
rte_spinlock_recursive_init(rte_spinlock_recursive_t *slr)
{
  rte_spinlock_init(&slr->sl);
  slr->user = -1;
  slr->count = 0;
}

static inline void
rte_spinlock_recursive_lock(rte_spinlock_recursive_t *slr)
{
  int id = rte_gettid();
  if (slr->user != id)
  {
    rte_spinlock_lock(&slr->sl);
    slr->user = id;
  }
  slr->count++;
}

static inline void
rte_spinlock_recursive_unlock(rte_spinlock_recursive_t *slr)
{
  if (--(slr->count) == 0)
  {
    slr->user = -1;
    rte_spinlock_unlock(&slr->sl);
  }
}

__attribute__((warn_unused_result)) static inline int
rte_spinlock_recursive_trylock(rte_spinlock_recursive_t *slr)
{
  int id = rte_gettid();
  if (slr->user != id)
  {
    if (rte_spinlock_trylock(&slr->sl) == 0)
      return 0;
    slr->user = id;
  }
  slr->count++;
  return 1;
}

static inline void rte_spinlock_recursive_lock_tm(rte_spinlock_recursive_t *
                                                      slr);
static inline void rte_spinlock_recursive_unlock_tm(rte_spinlock_recursive_t
                                                        *slr);
__attribute__((warn_unused_result)) static inline int
rte_spinlock_recursive_trylock_tm(rte_spinlock_recursive_t *slr);
static inline int
rte_tm_supported(void)
{
  return 0;
}

static inline void
rte_spinlock_lock_tm(rte_spinlock_t *sl)
{
  rte_spinlock_lock(sl);
}

static inline int
rte_spinlock_trylock_tm(rte_spinlock_t *sl)
{
  return rte_spinlock_trylock(sl);
}

static inline void
rte_spinlock_unlock_tm(rte_spinlock_t *sl)
{
  rte_spinlock_unlock(sl);
}

static inline void
rte_spinlock_recursive_lock_tm(rte_spinlock_recursive_t *slr)
{
  rte_spinlock_recursive_lock(slr);
}

static inline void
rte_spinlock_recursive_unlock_tm(rte_spinlock_recursive_t *slr)
{
  rte_spinlock_recursive_unlock(slr);
}

static inline int
rte_spinlock_recursive_trylock_tm(rte_spinlock_recursive_t *slr)
{
  return rte_spinlock_recursive_trylock(slr);
}

__attribute__((section(".text.internal")))
rte_rwlock_t *
rte_mcfg_mem_get_lock(void);
__attribute__((section(".text.internal")))
rte_rwlock_t *
rte_mcfg_tailq_get_lock(void);
__attribute__((section(".text.internal")))
rte_rwlock_t *
rte_mcfg_mempool_get_lock(void);
__attribute__((section(".text.internal")))
rte_spinlock_t *
rte_mcfg_timer_get_lock(void);
__attribute__((section(".text.internal")))
rte_spinlock_t *
rte_mcfg_ethdev_get_lock(void);
void rte_mcfg_mem_read_lock(void);
void rte_mcfg_mem_read_unlock(void);
void rte_mcfg_mem_write_lock(void);
void rte_mcfg_mem_write_unlock(void);
void rte_mcfg_tailq_read_lock(void);
void rte_mcfg_tailq_read_unlock(void);
void rte_mcfg_tailq_write_lock(void);
void rte_mcfg_tailq_write_unlock(void);
void rte_mcfg_mempool_read_lock(void);
void rte_mcfg_mempool_read_unlock(void);
void rte_mcfg_mempool_write_lock(void);
void rte_mcfg_mempool_write_unlock(void);
void rte_mcfg_timer_lock(void);
void rte_mcfg_timer_unlock(void);
_Bool rte_mcfg_get_single_file_segments(void);
struct rte_fbarray
{
  char name[64];
  unsigned int count;
  unsigned int len;
  unsigned int elt_sz;
  void *data;
  rte_rwlock_t rwlock;
};
int rte_fbarray_init(struct rte_fbarray *arr, const char *name,
                     unsigned int len, unsigned int elt_sz);
int rte_fbarray_attach(struct rte_fbarray *arr);
int rte_fbarray_destroy(struct rte_fbarray *arr);
int rte_fbarray_detach(struct rte_fbarray *arr);
void *rte_fbarray_get(const struct rte_fbarray *arr, unsigned int idx);
int rte_fbarray_find_idx(const struct rte_fbarray *arr, const void *elt);
int rte_fbarray_set_used(struct rte_fbarray *arr, unsigned int idx);
int rte_fbarray_set_free(struct rte_fbarray *arr, unsigned int idx);
int rte_fbarray_is_used(struct rte_fbarray *arr, unsigned int idx);
int rte_fbarray_find_next_free(struct rte_fbarray *arr,
                               unsigned int start);
int rte_fbarray_find_next_used(struct rte_fbarray *arr,
                               unsigned int start);
int rte_fbarray_find_next_n_free(struct rte_fbarray *arr,
                                 unsigned int start, unsigned int n);
int rte_fbarray_find_next_n_used(struct rte_fbarray *arr,
                                 unsigned int start, unsigned int n);
int rte_fbarray_find_contig_free(struct rte_fbarray *arr,
                                 unsigned int start);
int rte_fbarray_find_contig_used(struct rte_fbarray *arr,
                                 unsigned int start);
int rte_fbarray_find_prev_free(struct rte_fbarray *arr,
                               unsigned int start);
int rte_fbarray_find_prev_used(struct rte_fbarray *arr,
                               unsigned int start);
int rte_fbarray_find_prev_n_free(struct rte_fbarray *arr,
                                 unsigned int start, unsigned int n);
int rte_fbarray_find_prev_n_used(struct rte_fbarray *arr,
                                 unsigned int start, unsigned int n);
int rte_fbarray_find_rev_contig_free(struct rte_fbarray *arr,
                                     unsigned int start);
int rte_fbarray_find_rev_contig_used(struct rte_fbarray *arr,
                                     unsigned int start);
int rte_fbarray_find_biggest_free(struct rte_fbarray *arr,
                                  unsigned int start);
int rte_fbarray_find_biggest_used(struct rte_fbarray *arr,
                                  unsigned int start);
int rte_fbarray_find_rev_biggest_free(struct rte_fbarray *arr,
                                      unsigned int start);
int rte_fbarray_find_rev_biggest_used(struct rte_fbarray *arr,
                                      unsigned int start);
void rte_fbarray_dump_metadata(struct rte_fbarray *arr, FILE *f);
struct rte_memseg
{
  rte_iova_t iova;
  union
  {
    void *addr;
    uint64_t addr_64;
  };
  size_t len;
  uint64_t hugepage_sz;
  int32_t socket_id;
  uint32_t nchannel;
  uint32_t nrank;
  uint32_t flags;
} __attribute__((__packed__));
struct rte_memseg_list
{
  union
  {
    void *base_va;
    uint64_t addr_64;
  };
  uint64_t page_sz;
  int socket_id;
  volatile uint32_t version;
  size_t len;
  unsigned int external;
  unsigned int heap;
  struct rte_fbarray memseg_arr;
};
int rte_mem_lock_page(const void *virt);
phys_addr_t rte_mem_virt2phy(const void *virt);
rte_iova_t rte_mem_virt2iova(const void *virt);
void *rte_mem_iova2virt(rte_iova_t iova);
struct rte_memseg *rte_mem_virt2memseg(const void *virt,
                                       const struct rte_memseg_list
                                           *msl);
struct rte_memseg_list *rte_mem_virt2memseg_list(const void *virt);
typedef int (*rte_memseg_walk_t)(const struct rte_memseg_list *msl,
                                 const struct rte_memseg *ms,
                                 void *arg);
typedef int (*rte_memseg_contig_walk_t)(const struct rte_memseg_list
                                            *msl,
                                        const struct rte_memseg *ms,
                                        size_t len, void *arg);
typedef int (*rte_memseg_list_walk_t)(const struct rte_memseg_list *msl,
                                      void *arg);
int rte_memseg_walk(rte_memseg_walk_t func, void *arg);
int rte_memseg_contig_walk(rte_memseg_contig_walk_t func, void *arg);
int rte_memseg_list_walk(rte_memseg_list_walk_t func, void *arg);
int rte_memseg_walk_thread_unsafe(rte_memseg_walk_t func, void *arg);
int rte_memseg_contig_walk_thread_unsafe(rte_memseg_contig_walk_t func,
                                         void *arg);
int rte_memseg_list_walk_thread_unsafe(rte_memseg_list_walk_t func,
                                       void *arg);
int rte_memseg_get_fd(const struct rte_memseg *ms);
int rte_memseg_get_fd_thread_unsafe(const struct rte_memseg *ms);
int rte_memseg_get_fd_offset(const struct rte_memseg *ms, size_t *offset);
int rte_memseg_get_fd_offset_thread_unsafe(const struct rte_memseg *ms,
                                           size_t *offset);
int rte_extmem_register(void *va_addr, size_t len,
                        rte_iova_t iova_addrs[], unsigned int n_pages,
                        size_t page_sz);
int rte_extmem_unregister(void *va_addr, size_t len);
int rte_extmem_attach(void *va_addr, size_t len);
int rte_extmem_detach(void *va_addr, size_t len);
void rte_dump_physmem_layout(FILE *f);
uint64_t rte_eal_get_physmem_size(void);
unsigned rte_memory_get_nchannel(void);
unsigned rte_memory_get_nrank(void);
int rte_mem_check_dma_mask(uint8_t maskbits);
int rte_mem_check_dma_mask_thread_unsafe(uint8_t maskbits);
void rte_mem_set_dma_mask(uint8_t maskbits);
int rte_eal_using_phys_addrs(void);
enum rte_mem_event
{
  RTE_MEM_EVENT_ALLOC = 0,
  RTE_MEM_EVENT_FREE,
};
typedef void (*rte_mem_event_callback_t)(enum rte_mem_event event_type,
                                         const void *addr, size_t len,
                                         void *arg);
int rte_mem_event_callback_register(const char *name,
                                    rte_mem_event_callback_t clb,
                                    void *arg);
int rte_mem_event_callback_unregister(const char *name, void *arg);
typedef int (*rte_mem_alloc_validator_t)(int socket_id,
                                         size_t cur_limit,
                                         size_t new_len);
int rte_mem_alloc_validator_register(const char *name,
                                     rte_mem_alloc_validator_t clb,
                                     int socket_id, size_t limit);
int rte_mem_alloc_validator_unregister(const char *name, int socket_id);
struct rte_memzone
{
  char name[32];
  rte_iova_t iova;
  union
  {
    void *addr;
    uint64_t addr_64;
  };
  size_t len;
  uint64_t hugepage_sz;
  int32_t socket_id;
  uint32_t flags;
} __attribute__((__packed__));
__attribute__((section(".text.experimental"))) int rte_memzone_max_set(size_t max);
__attribute__((section(".text.experimental")))
size_t
rte_memzone_max_get(void);
const struct rte_memzone *rte_memzone_reserve(const char *name,
                                              size_t len, int socket_id,
                                              unsigned flags);
const struct rte_memzone *rte_memzone_reserve_aligned(const char *name,
                                                      size_t len,
                                                      int socket_id,
                                                      unsigned flags,
                                                      unsigned align);
const struct rte_memzone *rte_memzone_reserve_bounded(const char *name,
                                                      size_t len,
                                                      int socket_id,
                                                      unsigned flags,
                                                      unsigned align,
                                                      unsigned bound);
int rte_memzone_free(const struct rte_memzone *mz);
const struct rte_memzone *rte_memzone_lookup(const char *name);
void rte_memzone_dump(FILE *f);
void rte_memzone_walk(void (*func)(const struct rte_memzone *, void *arg),
                      void *arg);
enum rte_ring_queue_behavior
{
  RTE_RING_QUEUE_FIXED = 0,
  RTE_RING_QUEUE_VARIABLE
};
enum rte_ring_sync_type
{
  RTE_RING_SYNC_MT,
  RTE_RING_SYNC_ST,
  RTE_RING_SYNC_MT_RTS,
  RTE_RING_SYNC_MT_HTS,
};
struct rte_ring_headtail
{
  volatile uint32_t head;
  volatile uint32_t tail;
  union
  {
    enum rte_ring_sync_type sync_type;
    uint32_t single;
  };
};
union __rte_ring_rts_poscnt
{
  _Alignas(sizeof(uint64_t)) uint64_t raw;
  struct
  {
    uint32_t cnt;
    uint32_t pos;
  } val;
};
struct rte_ring_rts_headtail
{
  volatile union __rte_ring_rts_poscnt tail;
  enum rte_ring_sync_type sync_type;
  uint32_t htd_max;
  volatile union __rte_ring_rts_poscnt head;
};
union __rte_ring_hts_pos
{
  _Alignas(sizeof(uint64_t)) uint64_t raw;
  struct
  {
    uint32_t head;
    uint32_t tail;
  } pos;
};
struct rte_ring_hts_headtail
{
  volatile union __rte_ring_hts_pos ht;
  enum rte_ring_sync_type sync_type;
};
struct rte_ring
{
  _Alignas(64) char name[(32 - sizeof("RG_") + 1)];
  int flags;
  const struct rte_memzone *memzone;
  uint32_t size;
  uint32_t mask;
  uint32_t capacity;
  _Alignas(64) char cache_guard_0[64 * 1];
  union __attribute__((__aligned__(64)))
  {
    struct rte_ring_headtail prod;
    struct rte_ring_hts_headtail hts_prod;
    struct rte_ring_rts_headtail rts_prod;
  };
  _Alignas(64) char cache_guard_1[64 * 1];
  union __attribute__((__aligned__(64)))
  {
    struct rte_ring_headtail cons;
    struct rte_ring_hts_headtail hts_cons;
    struct rte_ring_rts_headtail rts_cons;
  };
  _Alignas(64) char cache_guard_2[64 * 1];
};

static inline __attribute__((always_inline)) void
__rte_ring_enqueue_elems_32(struct rte_ring *r, const uint32_t size,
                            uint32_t idx, const void *obj_table,
                            uint32_t n)
{
  unsigned int i;
  uint32_t *ring = (uint32_t *)&r[1];
  const uint32_t *obj = (const uint32_t *)obj_table;
  if (__builtin_expect(!!(idx + n <= size), 1))
  {
    for (i = 0; i < (n & ~0x7); i += 8, idx += 8)
    {
      ring[idx] = obj[i];
      ring[idx + 1] = obj[i + 1];
      ring[idx + 2] = obj[i + 2];
      ring[idx + 3] = obj[i + 3];
      ring[idx + 4] = obj[i + 4];
      ring[idx + 5] = obj[i + 5];
      ring[idx + 6] = obj[i + 6];
      ring[idx + 7] = obj[i + 7];
    }
    switch (n & 0x7)
    {
    case 7:
      ring[idx++] = obj[i++];
    case 6:
      ring[idx++] = obj[i++];
    case 5:
      ring[idx++] = obj[i++];
    case 4:
      ring[idx++] = obj[i++];
    case 3:
      ring[idx++] = obj[i++];
    case 2:
      ring[idx++] = obj[i++];
    case 1:
      ring[idx++] = obj[i++];
    }
  }
  else
  {
    for (i = 0; idx < size; i++, idx++)
      ring[idx] = obj[i];
    for (idx = 0; i < n; i++, idx++)
      ring[idx] = obj[i];
  }
}

static inline __attribute__((always_inline)) void
__rte_ring_enqueue_elems_64(struct rte_ring *r, uint32_t prod_head,
                            const void *obj_table, uint32_t n)
{
  unsigned int i;
  const uint32_t size = r->size;
  uint32_t idx = prod_head & r->mask;
  uint64_t *ring = (uint64_t *)&r[1];
  const unaligned_uint64_t *obj = (const unaligned_uint64_t *)obj_table;
  if (__builtin_expect(!!(idx + n <= size), 1))
  {
    for (i = 0; i < (n & ~0x3); i += 4, idx += 4)
    {
      ring[idx] = obj[i];
      ring[idx + 1] = obj[i + 1];
      ring[idx + 2] = obj[i + 2];
      ring[idx + 3] = obj[i + 3];
    }
    switch (n & 0x3)
    {
    case 3:
      ring[idx++] = obj[i++];
    case 2:
      ring[idx++] = obj[i++];
    case 1:
      ring[idx++] = obj[i++];
    }
  }
  else
  {
    for (i = 0; idx < size; i++, idx++)
      ring[idx] = obj[i];
    for (idx = 0; i < n; i++, idx++)
      ring[idx] = obj[i];
  }
}

static inline __attribute__((always_inline)) void
__rte_ring_enqueue_elems_128(struct rte_ring *r, uint32_t prod_head,
                             const void *obj_table, uint32_t n)
{
  unsigned int i;
  const uint32_t size = r->size;
  uint32_t idx = prod_head & r->mask;
  rte_int128_t *ring = (rte_int128_t *)&r[1];
  const rte_int128_t *obj = (const rte_int128_t *)obj_table;
  if (__builtin_expect(!!(idx + n <= size), 1))
  {
    for (i = 0; i < (n & ~0x1); i += 2, idx += 2)
      memcpy((void *)(ring + idx), (const void *)(obj + i), 32);
    switch (n & 0x1)
    {
    case 1:
      memcpy((void *)(ring + idx), (const void *)(obj + i), 16);
    }
  }
  else
  {
    for (i = 0; idx < size; i++, idx++)
      memcpy((void *)(ring + idx), (const void *)(obj + i), 16);
    for (idx = 0; i < n; i++, idx++)
      memcpy((void *)(ring + idx), (const void *)(obj + i), 16);
  }
}

static inline __attribute__((always_inline)) void
__rte_ring_enqueue_elems(struct rte_ring *r, uint32_t prod_head,
                         const void *obj_table, uint32_t esize,
                         uint32_t num)
{
  if (esize == 8)
    __rte_ring_enqueue_elems_64(r, prod_head, obj_table, num);
  else if (esize == 16)
    __rte_ring_enqueue_elems_128(r, prod_head, obj_table, num);
  else
  {
    uint32_t idx, scale, nr_idx, nr_num, nr_size;
    scale = esize / sizeof(uint32_t);
    nr_num = num * scale;
    idx = prod_head & r->mask;
    nr_idx = idx * scale;
    nr_size = r->size * scale;
    __rte_ring_enqueue_elems_32(r, nr_size, nr_idx, obj_table, nr_num);
  }
}

static inline __attribute__((always_inline)) void
__rte_ring_dequeue_elems_32(struct rte_ring *r, const uint32_t size,
                            uint32_t idx, void *obj_table, uint32_t n)
{
  unsigned int i;
  uint32_t *ring = (uint32_t *)&r[1];
  uint32_t *obj = (uint32_t *)obj_table;
  if (__builtin_expect(!!(idx + n <= size), 1))
  {
    for (i = 0; i < (n & ~0x7); i += 8, idx += 8)
    {
      obj[i] = ring[idx];
      obj[i + 1] = ring[idx + 1];
      obj[i + 2] = ring[idx + 2];
      obj[i + 3] = ring[idx + 3];
      obj[i + 4] = ring[idx + 4];
      obj[i + 5] = ring[idx + 5];
      obj[i + 6] = ring[idx + 6];
      obj[i + 7] = ring[idx + 7];
    }
    switch (n & 0x7)
    {
    case 7:
      obj[i++] = ring[idx++];
    case 6:
      obj[i++] = ring[idx++];
    case 5:
      obj[i++] = ring[idx++];
    case 4:
      obj[i++] = ring[idx++];
    case 3:
      obj[i++] = ring[idx++];
    case 2:
      obj[i++] = ring[idx++];
    case 1:
      obj[i++] = ring[idx++];
    }
  }
  else
  {
    for (i = 0; idx < size; i++, idx++)
      obj[i] = ring[idx];
    for (idx = 0; i < n; i++, idx++)
      obj[i] = ring[idx];
  }
}

static inline __attribute__((always_inline)) void
__rte_ring_dequeue_elems_64(struct rte_ring *r, uint32_t cons_head,
                            void *obj_table, uint32_t n)
{
  unsigned int i;
  const uint32_t size = r->size;
  uint32_t idx = cons_head & r->mask;
  uint64_t *ring = (uint64_t *)&r[1];
  unaligned_uint64_t *obj = (unaligned_uint64_t *)obj_table;
  if (__builtin_expect(!!(idx + n <= size), 1))
  {
    for (i = 0; i < (n & ~0x3); i += 4, idx += 4)
    {
      obj[i] = ring[idx];
      obj[i + 1] = ring[idx + 1];
      obj[i + 2] = ring[idx + 2];
      obj[i + 3] = ring[idx + 3];
    }
    switch (n & 0x3)
    {
    case 3:
      obj[i++] = ring[idx++];
    case 2:
      obj[i++] = ring[idx++];
    case 1:
      obj[i++] = ring[idx++];
    }
  }
  else
  {
    for (i = 0; idx < size; i++, idx++)
      obj[i] = ring[idx];
    for (idx = 0; i < n; i++, idx++)
      obj[i] = ring[idx];
  }
}

static inline __attribute__((always_inline)) void
__rte_ring_dequeue_elems_128(struct rte_ring *r, uint32_t cons_head,
                             void *obj_table, uint32_t n)
{
  unsigned int i;
  const uint32_t size = r->size;
  uint32_t idx = cons_head & r->mask;
  rte_int128_t *ring = (rte_int128_t *)&r[1];
  rte_int128_t *obj = (rte_int128_t *)obj_table;
  if (__builtin_expect(!!(idx + n <= size), 1))
  {
    for (i = 0; i < (n & ~0x1); i += 2, idx += 2)
      memcpy((void *)(obj + i), (void *)(ring + idx), 32);
    switch (n & 0x1)
    {
    case 1:
      memcpy((void *)(obj + i), (void *)(ring + idx), 16);
    }
  }
  else
  {
    for (i = 0; idx < size; i++, idx++)
      memcpy((void *)(obj + i), (void *)(ring + idx), 16);
    for (idx = 0; i < n; i++, idx++)
      memcpy((void *)(obj + i), (void *)(ring + idx), 16);
  }
}

static inline __attribute__((always_inline)) void
__rte_ring_dequeue_elems(struct rte_ring *r, uint32_t cons_head,
                         void *obj_table, uint32_t esize,
                         uint32_t num)
{
  if (esize == 8)
    __rte_ring_dequeue_elems_64(r, cons_head, obj_table, num);
  else if (esize == 16)
    __rte_ring_dequeue_elems_128(r, cons_head, obj_table, num);
  else
  {
    uint32_t idx, scale, nr_idx, nr_num, nr_size;
    scale = esize / sizeof(uint32_t);
    nr_num = num * scale;
    idx = cons_head & r->mask;
    nr_idx = idx * scale;
    nr_size = r->size * scale;
    __rte_ring_dequeue_elems_32(r, nr_size, nr_idx, obj_table, nr_num);
  }
}

static inline __attribute__((always_inline)) void
__rte_ring_update_tail(struct rte_ring_headtail *ht, uint32_t old_val,
                       uint32_t new_val, uint32_t single,
                       uint32_t enqueue)
{
  (void)(enqueue);
  if (!single)
    rte_wait_until_equal_32((uint32_t *)(uintptr_t)&ht->tail, old_val, 0);
  __atomic_store_n(&ht->tail, new_val, 3);
}

static inline __attribute__((always_inline)) unsigned int
__rte_ring_move_prod_head(struct rte_ring *r, unsigned int is_sp,
                          unsigned int n,
                          enum rte_ring_queue_behavior behavior,
                          uint32_t *old_head, uint32_t *new_head,
                          uint32_t *free_entries)
{
  const uint32_t capacity = r->capacity;
  uint32_t cons_tail;
  unsigned int max = n;
  int success;
  *old_head = __atomic_load_n(&r->prod.head, 0);
  do
  {
    n = max;
    rte_atomic_thread_fence(2);
    cons_tail = __atomic_load_n(&r->cons.tail, 2);
    *free_entries = (capacity + cons_tail - *old_head);
    if (__builtin_expect(!!(n > *free_entries), 0))
      n = (behavior == RTE_RING_QUEUE_FIXED) ? 0 : *free_entries;
    if (n == 0)
      return 0;
    *new_head = *old_head + n;
    if (is_sp)
    {
      r->prod.head = *new_head;
      success = 1;
    }
    else
      success =
          __atomic_compare_exchange_n(&r->prod.head, old_head, *new_head, 0,
                                      0, 0);
  } while (__builtin_expect(!!(success == 0), 0));
  return n;
}

static inline __attribute__((always_inline)) unsigned int
__rte_ring_move_cons_head(struct rte_ring *r, int is_sc,
                          unsigned int n,
                          enum rte_ring_queue_behavior behavior,
                          uint32_t *old_head, uint32_t *new_head,
                          uint32_t *entries)
{
  unsigned int max = n;
  uint32_t prod_tail;
  int success;
  *old_head = __atomic_load_n(&r->cons.head, 0);
  do
  {
    n = max;
    rte_atomic_thread_fence(2);
    prod_tail = __atomic_load_n(&r->prod.tail, 2);
    *entries = (prod_tail - *old_head);
    if (n > *entries)
      n = (behavior == RTE_RING_QUEUE_FIXED) ? 0 : *entries;
    if (__builtin_expect(!!(n == 0), 0))
      return 0;
    *new_head = *old_head + n;
    if (is_sc)
    {
      r->cons.head = *new_head;
      success = 1;
    }
    else
      success =
          __atomic_compare_exchange_n(&r->cons.head, old_head, *new_head, 0,
                                      0, 0);
  } while (__builtin_expect(!!(success == 0), 0));
  return n;
}

static inline __attribute__((always_inline)) unsigned int
__rte_ring_do_enqueue_elem(struct rte_ring *r, const void *obj_table,
                           unsigned int esize, unsigned int n,
                           enum rte_ring_queue_behavior behavior,
                           unsigned int is_sp,
                           unsigned int *free_space)
{
  uint32_t prod_head, prod_next;
  uint32_t free_entries;
  n = __rte_ring_move_prod_head(r, is_sp, n, behavior,
                                &prod_head, &prod_next, &free_entries);
  if (n == 0)
    goto end;
  __rte_ring_enqueue_elems(r, prod_head, obj_table, esize, n);
  __rte_ring_update_tail(&r->prod, prod_head, prod_next, is_sp, 1);
end:
  if (free_space != ((void *)0))
    *free_space = free_entries - n;
  return n;
}

static inline __attribute__((always_inline)) unsigned int
__rte_ring_do_dequeue_elem(struct rte_ring *r, void *obj_table,
                           unsigned int esize, unsigned int n,
                           enum rte_ring_queue_behavior behavior,
                           unsigned int is_sc,
                           unsigned int *available)
{
  uint32_t cons_head, cons_next;
  uint32_t entries;
  n = __rte_ring_move_cons_head(r, (int)is_sc, n, behavior,
                                &cons_head, &cons_next, &entries);
  if (n == 0)
    goto end;
  __rte_ring_dequeue_elems(r, cons_head, obj_table, esize, n);
  __rte_ring_update_tail(&r->cons, cons_head, cons_next, is_sc, 0);
end:
  if (available != ((void *)0))
    *available = entries - n;
  return n;
}

ssize_t rte_ring_get_memsize_elem(unsigned int esize, unsigned int count);
struct rte_ring *rte_ring_create_elem(const char *name, unsigned int esize,
                                      unsigned int count, int socket_id,
                                      unsigned int flags);
static inline __attribute__((always_inline)) unsigned int
rte_ring_mp_enqueue_bulk_elem(struct rte_ring *r, const void *obj_table,
                              unsigned int esize, unsigned int n,
                              unsigned int *free_space)
{
  return __rte_ring_do_enqueue_elem(r, obj_table, esize, n,
                                    RTE_RING_QUEUE_FIXED, RTE_RING_SYNC_MT,
                                    free_space);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_sp_enqueue_bulk_elem(struct rte_ring *r, const void *obj_table,
                              unsigned int esize, unsigned int n,
                              unsigned int *free_space)
{
  return __rte_ring_do_enqueue_elem(r, obj_table, esize, n,
                                    RTE_RING_QUEUE_FIXED, RTE_RING_SYNC_ST,
                                    free_space);
}

static inline __attribute__((always_inline)) void
__rte_ring_hts_update_tail(struct rte_ring_hts_headtail *ht,
                           uint32_t old_tail, uint32_t num,
                           uint32_t enqueue)
{
  uint32_t tail;
  (void)(enqueue);
  tail = old_tail + num;
  __atomic_store_n(&ht->ht.pos.tail, tail, 3);
}

static inline __attribute__((always_inline)) void
__rte_ring_hts_head_wait(const struct rte_ring_hts_headtail *ht,
                         union __rte_ring_hts_pos *p)
{
  while (p->pos.head != p->pos.tail)
  {
    rte_pause();
    p->raw = __atomic_load_n(&ht->ht.raw, 2);
  }
}

static inline __attribute__((always_inline)) unsigned int
__rte_ring_hts_move_prod_head(struct rte_ring *r, unsigned int num,
                              enum rte_ring_queue_behavior behavior,
                              uint32_t *old_head,
                              uint32_t *free_entries)
{
  uint32_t n;
  union __rte_ring_hts_pos np, op;
  const uint32_t capacity = r->capacity;
  op.raw = __atomic_load_n(&r->hts_prod.ht.raw, 2);
  do
  {
    n = num;
    __rte_ring_hts_head_wait(&r->hts_prod, &op);
    *free_entries = capacity + r->cons.tail - op.pos.head;
    if (__builtin_expect(!!(n > *free_entries), 0))
      n = (behavior == RTE_RING_QUEUE_FIXED) ? 0 : *free_entries;
    if (n == 0)
      break;
    np.pos.tail = op.pos.tail;
    np.pos.head = op.pos.head + n;
  } while (__atomic_compare_exchange_n(&r->hts_prod.ht.raw, (uint64_t *)(uintptr_t)&op.raw, np.raw, 0,
                                       2, 2) == 0);
  *old_head = op.pos.head;
  return n;
}

static inline __attribute__((always_inline)) unsigned int
__rte_ring_hts_move_cons_head(struct rte_ring *r, unsigned int num,
                              enum rte_ring_queue_behavior behavior,
                              uint32_t *old_head, uint32_t *entries)
{
  uint32_t n;
  union __rte_ring_hts_pos np, op;
  op.raw = __atomic_load_n(&r->hts_cons.ht.raw, 2);
  do
  {
    n = num;
    __rte_ring_hts_head_wait(&r->hts_cons, &op);
    *entries = r->prod.tail - op.pos.head;
    if (n > *entries)
      n = (behavior == RTE_RING_QUEUE_FIXED) ? 0 : *entries;
    if (__builtin_expect(!!(n == 0), 0))
      break;
    np.pos.tail = op.pos.tail;
    np.pos.head = op.pos.head + n;
  } while (__atomic_compare_exchange_n(&r->hts_cons.ht.raw, (uint64_t *)(uintptr_t)&op.raw, np.raw, 0,
                                       2, 2) == 0);
  *old_head = op.pos.head;
  return n;
}

static inline __attribute__((always_inline)) unsigned int
__rte_ring_do_hts_enqueue_elem(struct rte_ring *r,
                               const void *obj_table, uint32_t esize,
                               uint32_t n,
                               enum rte_ring_queue_behavior behavior,
                               uint32_t *free_space)
{
  uint32_t free, head;
  n = __rte_ring_hts_move_prod_head(r, n, behavior, &head, &free);
  if (n != 0)
  {
    __rte_ring_enqueue_elems(r, head, obj_table, esize, n);
    __rte_ring_hts_update_tail(&r->hts_prod, head, n, 1);
  }
  if (free_space != ((void *)0))
    *free_space = free - n;
  return n;
}

static inline __attribute__((always_inline)) unsigned int
__rte_ring_do_hts_dequeue_elem(struct rte_ring *r, void *obj_table,
                               uint32_t esize, uint32_t n,
                               enum rte_ring_queue_behavior behavior,
                               uint32_t *available)
{
  uint32_t entries, head;
  n = __rte_ring_hts_move_cons_head(r, n, behavior, &head, &entries);
  if (n != 0)
  {
    __rte_ring_dequeue_elems(r, head, obj_table, esize, n);
    __rte_ring_hts_update_tail(&r->hts_cons, head, n, 0);
  }
  if (available != ((void *)0))
    *available = entries - n;
  return n;
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_mp_hts_enqueue_bulk_elem(struct rte_ring *r,
                                  const void *obj_table,
                                  unsigned int esize, unsigned int n,
                                  unsigned int *free_space)
{
  return __rte_ring_do_hts_enqueue_elem(r, obj_table, esize, n,
                                        RTE_RING_QUEUE_FIXED, free_space);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_mc_hts_dequeue_bulk_elem(struct rte_ring *r, void *obj_table,
                                  unsigned int esize, unsigned int n,
                                  unsigned int *available)
{
  return __rte_ring_do_hts_dequeue_elem(r, obj_table, esize, n,
                                        RTE_RING_QUEUE_FIXED, available);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_mp_hts_enqueue_burst_elem(struct rte_ring *r,
                                   const void *obj_table,
                                   unsigned int esize, unsigned int n,
                                   unsigned int *free_space)
{
  return __rte_ring_do_hts_enqueue_elem(r, obj_table, esize, n,
                                        RTE_RING_QUEUE_VARIABLE, free_space);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_mc_hts_dequeue_burst_elem(struct rte_ring *r, void *obj_table,
                                   unsigned int esize, unsigned int n,
                                   unsigned int *available)
{
  return __rte_ring_do_hts_dequeue_elem(r, obj_table, esize, n,
                                        RTE_RING_QUEUE_VARIABLE, available);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_mp_hts_enqueue_bulk(struct rte_ring *r, void *const *obj_table,
                             unsigned int n, unsigned int *free_space)
{
  return rte_ring_mp_hts_enqueue_bulk_elem(r, obj_table,
                                           sizeof(uintptr_t), n,
                                           free_space);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_mc_hts_dequeue_bulk(struct rte_ring *r, void **obj_table,
                             unsigned int n, unsigned int *available)
{
  return rte_ring_mc_hts_dequeue_bulk_elem(r, obj_table,
                                           sizeof(uintptr_t), n, available);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_mp_hts_enqueue_burst(struct rte_ring *r,
                              void *const *obj_table, unsigned int n,
                              unsigned int *free_space)
{
  return rte_ring_mp_hts_enqueue_burst_elem(r, obj_table,
                                            sizeof(uintptr_t), n,
                                            free_space);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_mc_hts_dequeue_burst(struct rte_ring *r, void **obj_table,
                              unsigned int n, unsigned int *available)
{
  return rte_ring_mc_hts_dequeue_burst_elem(r, obj_table,
                                            sizeof(uintptr_t), n,
                                            available);
}

static inline __attribute__((always_inline)) void
__rte_ring_rts_update_tail(struct rte_ring_rts_headtail *ht)
{
  union __rte_ring_rts_poscnt h, ot, nt;
  ot.raw = __atomic_load_n(&ht->tail.raw, 2);
  do
  {
    h.raw = __atomic_load_n(&ht->head.raw, 0);
    nt.raw = ot.raw;
    if (++nt.val.cnt == h.val.cnt)
      nt.val.pos = h.val.pos;
  } while (__atomic_compare_exchange_n(&ht->tail.raw, (uint64_t *)(uintptr_t)&ot.raw, nt.raw, 0, 3,
                                       2) == 0);
}

static inline __attribute__((always_inline)) void
__rte_ring_rts_head_wait(const struct rte_ring_rts_headtail *ht,
                         union __rte_ring_rts_poscnt *h)
{
  uint32_t max;
  max = ht->htd_max;
  while (h->val.pos - ht->tail.val.pos > max)
  {
    rte_pause();
    h->raw = __atomic_load_n(&ht->head.raw, 2);
  }
}

static inline __attribute__((always_inline)) uint32_t
__rte_ring_rts_move_prod_head(struct rte_ring *r, uint32_t num,
                              enum rte_ring_queue_behavior behavior,
                              uint32_t *old_head, uint32_t *free_entries)
{
  uint32_t n;
  union __rte_ring_rts_poscnt nh, oh;
  const uint32_t capacity = r->capacity;
  oh.raw = __atomic_load_n(&r->rts_prod.head.raw, 2);
  do
  {
    n = num;
    __rte_ring_rts_head_wait(&r->rts_prod, &oh);
    *free_entries = capacity + r->cons.tail - oh.val.pos;
    if (__builtin_expect(!!(n > *free_entries), 0))
      n = (behavior == RTE_RING_QUEUE_FIXED) ? 0 : *free_entries;
    if (n == 0)
      break;
    nh.val.pos = oh.val.pos + n;
    nh.val.cnt = oh.val.cnt + 1;
  } while (__atomic_compare_exchange_n(&r->rts_prod.head.raw, (uint64_t *)(uintptr_t)&oh.raw, nh.raw, 0,
                                       2, 2) == 0);
  *old_head = oh.val.pos;
  return n;
}

static inline __attribute__((always_inline)) unsigned int
__rte_ring_rts_move_cons_head(struct rte_ring *r, uint32_t num,
                              enum rte_ring_queue_behavior behavior,
                              uint32_t *old_head, uint32_t *entries)
{
  uint32_t n;
  union __rte_ring_rts_poscnt nh, oh;
  oh.raw = __atomic_load_n(&r->rts_cons.head.raw, 2);
  do
  {
    n = num;
    __rte_ring_rts_head_wait(&r->rts_cons, &oh);
    *entries = r->prod.tail - oh.val.pos;
    if (n > *entries)
      n = (behavior == RTE_RING_QUEUE_FIXED) ? 0 : *entries;
    if (__builtin_expect(!!(n == 0), 0))
      break;
    nh.val.pos = oh.val.pos + n;
    nh.val.cnt = oh.val.cnt + 1;
  } while (__atomic_compare_exchange_n(&r->rts_cons.head.raw, (uint64_t *)(uintptr_t)&oh.raw, nh.raw, 0,
                                       2, 2) == 0);
  *old_head = oh.val.pos;
  return n;
}

static inline __attribute__((always_inline)) unsigned int
__rte_ring_do_rts_enqueue_elem(struct rte_ring *r,
                               const void *obj_table, uint32_t esize,
                               uint32_t n,
                               enum rte_ring_queue_behavior behavior,
                               uint32_t *free_space)
{
  uint32_t free, head;
  n = __rte_ring_rts_move_prod_head(r, n, behavior, &head, &free);
  if (n != 0)
  {
    __rte_ring_enqueue_elems(r, head, obj_table, esize, n);
    __rte_ring_rts_update_tail(&r->rts_prod);
  }
  if (free_space != ((void *)0))
    *free_space = free - n;
  return n;
}

static inline __attribute__((always_inline)) unsigned int
__rte_ring_do_rts_dequeue_elem(struct rte_ring *r, void *obj_table,
                               uint32_t esize, uint32_t n,
                               enum rte_ring_queue_behavior behavior,
                               uint32_t *available)
{
  uint32_t entries, head;
  n = __rte_ring_rts_move_cons_head(r, n, behavior, &head, &entries);
  if (n != 0)
  {
    __rte_ring_dequeue_elems(r, head, obj_table, esize, n);
    __rte_ring_rts_update_tail(&r->rts_cons);
  }
  if (available != ((void *)0))
    *available = entries - n;
  return n;
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_mp_rts_enqueue_bulk_elem(struct rte_ring *r,
                                  const void *obj_table,
                                  unsigned int esize, unsigned int n,
                                  unsigned int *free_space)
{
  return __rte_ring_do_rts_enqueue_elem(r, obj_table, esize, n,
                                        RTE_RING_QUEUE_FIXED, free_space);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_mc_rts_dequeue_bulk_elem(struct rte_ring *r, void *obj_table,
                                  unsigned int esize, unsigned int n,
                                  unsigned int *available)
{
  return __rte_ring_do_rts_dequeue_elem(r, obj_table, esize, n,
                                        RTE_RING_QUEUE_FIXED, available);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_mp_rts_enqueue_burst_elem(struct rte_ring *r,
                                   const void *obj_table,
                                   unsigned int esize, unsigned int n,
                                   unsigned int *free_space)
{
  return __rte_ring_do_rts_enqueue_elem(r, obj_table, esize, n,
                                        RTE_RING_QUEUE_VARIABLE, free_space);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_mc_rts_dequeue_burst_elem(struct rte_ring *r,
                                   void *obj_table,
                                   unsigned int esize, unsigned int n,
                                   unsigned int *available)
{
  return __rte_ring_do_rts_dequeue_elem(r, obj_table, esize, n,
                                        RTE_RING_QUEUE_VARIABLE, available);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_mp_rts_enqueue_bulk(struct rte_ring *r,
                             void *const *obj_table, unsigned int n,
                             unsigned int *free_space)
{
  return rte_ring_mp_rts_enqueue_bulk_elem(r, obj_table,
                                           sizeof(uintptr_t), n,
                                           free_space);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_mc_rts_dequeue_bulk(struct rte_ring *r, void **obj_table,
                             unsigned int n, unsigned int *available)
{
  return rte_ring_mc_rts_dequeue_bulk_elem(r, obj_table,
                                           sizeof(uintptr_t), n, available);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_mp_rts_enqueue_burst(struct rte_ring *r,
                              void *const *obj_table, unsigned int n,
                              unsigned int *free_space)
{
  return rte_ring_mp_rts_enqueue_burst_elem(r, obj_table,
                                            sizeof(uintptr_t), n,
                                            free_space);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_mc_rts_dequeue_burst(struct rte_ring *r, void **obj_table,
                              unsigned int n, unsigned int *available)
{
  return rte_ring_mc_rts_dequeue_burst_elem(r, obj_table,
                                            sizeof(uintptr_t), n,
                                            available);
}

static inline uint32_t
rte_ring_get_prod_htd_max(const struct rte_ring *r)
{
  if (r->prod.sync_type == RTE_RING_SYNC_MT_RTS)
    return r->rts_prod.htd_max;
  return (4294967295U);
}

static inline int
rte_ring_set_prod_htd_max(struct rte_ring *r, uint32_t v)
{
  if (r->prod.sync_type != RTE_RING_SYNC_MT_RTS)
    return -95;
  r->rts_prod.htd_max = v;
  return 0;
}

static inline uint32_t
rte_ring_get_cons_htd_max(const struct rte_ring *r)
{
  if (r->cons.sync_type == RTE_RING_SYNC_MT_RTS)
    return r->rts_cons.htd_max;
  return (4294967295U);
}

static inline int
rte_ring_set_cons_htd_max(struct rte_ring *r, uint32_t v)
{
  if (r->cons.sync_type != RTE_RING_SYNC_MT_RTS)
    return -95;
  r->rts_cons.htd_max = v;
  return 0;
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_enqueue_bulk_elem(struct rte_ring *r, const void *obj_table,
                           unsigned int esize, unsigned int n,
                           unsigned int *free_space)
{
  switch (r->prod.sync_type)
  {
  case RTE_RING_SYNC_MT:
    return rte_ring_mp_enqueue_bulk_elem(r, obj_table, esize, n,
                                         free_space);
  case RTE_RING_SYNC_ST:
    return rte_ring_sp_enqueue_bulk_elem(r, obj_table, esize, n,
                                         free_space);
  case RTE_RING_SYNC_MT_RTS:
    return rte_ring_mp_rts_enqueue_bulk_elem(r, obj_table, esize, n,
                                             free_space);
  case RTE_RING_SYNC_MT_HTS:
    return rte_ring_mp_hts_enqueue_bulk_elem(r, obj_table, esize, n,
                                             free_space);
  }
  do
  {
  } while (0);
  if (free_space != ((void *)0))
    *free_space = 0;
  return 0;
}

static inline __attribute__((always_inline)) int
rte_ring_mp_enqueue_elem(struct rte_ring *r, void *obj,
                         unsigned int esize)
{
  return rte_ring_mp_enqueue_bulk_elem(r, obj, esize, 1,
                                       ((void *)0))
             ? 0
             : -105;
}

static inline __attribute__((always_inline)) int
rte_ring_sp_enqueue_elem(struct rte_ring *r, void *obj,
                         unsigned int esize)
{
  return rte_ring_sp_enqueue_bulk_elem(r, obj, esize, 1,
                                       ((void *)0))
             ? 0
             : -105;
}

static inline __attribute__((always_inline)) int
rte_ring_enqueue_elem(struct rte_ring *r, void *obj,
                      unsigned int esize)
{
  return rte_ring_enqueue_bulk_elem(r, obj, esize, 1,
                                    ((void *)0))
             ? 0
             : -105;
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_mc_dequeue_bulk_elem(struct rte_ring *r, void *obj_table,
                              unsigned int esize, unsigned int n,
                              unsigned int *available)
{
  return __rte_ring_do_dequeue_elem(r, obj_table, esize, n,
                                    RTE_RING_QUEUE_FIXED, RTE_RING_SYNC_MT,
                                    available);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_sc_dequeue_bulk_elem(struct rte_ring *r, void *obj_table,
                              unsigned int esize, unsigned int n,
                              unsigned int *available)
{
  return __rte_ring_do_dequeue_elem(r, obj_table, esize, n,
                                    RTE_RING_QUEUE_FIXED, RTE_RING_SYNC_ST,
                                    available);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_dequeue_bulk_elem(struct rte_ring *r, void *obj_table,
                           unsigned int esize, unsigned int n,
                           unsigned int *available)
{
  switch (r->cons.sync_type)
  {
  case RTE_RING_SYNC_MT:
    return rte_ring_mc_dequeue_bulk_elem(r, obj_table, esize, n,
                                         available);
  case RTE_RING_SYNC_ST:
    return rte_ring_sc_dequeue_bulk_elem(r, obj_table, esize, n,
                                         available);
  case RTE_RING_SYNC_MT_RTS:
    return rte_ring_mc_rts_dequeue_bulk_elem(r, obj_table, esize,
                                             n, available);
  case RTE_RING_SYNC_MT_HTS:
    return rte_ring_mc_hts_dequeue_bulk_elem(r, obj_table, esize,
                                             n, available);
  }
  do
  {
  } while (0);
  if (available != ((void *)0))
    *available = 0;
  return 0;
}

static inline __attribute__((always_inline)) int
rte_ring_mc_dequeue_elem(struct rte_ring *r, void *obj_p,
                         unsigned int esize)
{
  return rte_ring_mc_dequeue_bulk_elem(r, obj_p, esize, 1,
                                       ((void *)0))
             ? 0
             : -2;
}

static inline __attribute__((always_inline)) int
rte_ring_sc_dequeue_elem(struct rte_ring *r, void *obj_p,
                         unsigned int esize)
{
  return rte_ring_sc_dequeue_bulk_elem(r, obj_p, esize, 1,
                                       ((void *)0))
             ? 0
             : -2;
}

static inline __attribute__((always_inline)) int
rte_ring_dequeue_elem(struct rte_ring *r, void *obj_p,
                      unsigned int esize)
{
  return rte_ring_dequeue_bulk_elem(r, obj_p, esize, 1,
                                    ((void *)0))
             ? 0
             : -2;
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_mp_enqueue_burst_elem(struct rte_ring *r,
                               const void *obj_table,
                               unsigned int esize, unsigned int n,
                               unsigned int *free_space)
{
  return __rte_ring_do_enqueue_elem(r, obj_table, esize, n,
                                    RTE_RING_QUEUE_VARIABLE,
                                    RTE_RING_SYNC_MT, free_space);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_sp_enqueue_burst_elem(struct rte_ring *r,
                               const void *obj_table,
                               unsigned int esize, unsigned int n,
                               unsigned int *free_space)
{
  return __rte_ring_do_enqueue_elem(r, obj_table, esize, n,
                                    RTE_RING_QUEUE_VARIABLE,
                                    RTE_RING_SYNC_ST, free_space);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_enqueue_burst_elem(struct rte_ring *r, const void *obj_table,
                            unsigned int esize, unsigned int n,
                            unsigned int *free_space)
{
  switch (r->prod.sync_type)
  {
  case RTE_RING_SYNC_MT:
    return rte_ring_mp_enqueue_burst_elem(r, obj_table, esize, n,
                                          free_space);
  case RTE_RING_SYNC_ST:
    return rte_ring_sp_enqueue_burst_elem(r, obj_table, esize, n,
                                          free_space);
  case RTE_RING_SYNC_MT_RTS:
    return rte_ring_mp_rts_enqueue_burst_elem(r, obj_table, esize,
                                              n, free_space);
  case RTE_RING_SYNC_MT_HTS:
    return rte_ring_mp_hts_enqueue_burst_elem(r, obj_table, esize,
                                              n, free_space);
  }
  do
  {
  } while (0);
  if (free_space != ((void *)0))
    *free_space = 0;
  return 0;
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_mc_dequeue_burst_elem(struct rte_ring *r, void *obj_table,
                               unsigned int esize, unsigned int n,
                               unsigned int *available)
{
  return __rte_ring_do_dequeue_elem(r, obj_table, esize, n,
                                    RTE_RING_QUEUE_VARIABLE,
                                    RTE_RING_SYNC_MT, available);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_sc_dequeue_burst_elem(struct rte_ring *r, void *obj_table,
                               unsigned int esize, unsigned int n,
                               unsigned int *available)
{
  return __rte_ring_do_dequeue_elem(r, obj_table, esize, n,
                                    RTE_RING_QUEUE_VARIABLE,
                                    RTE_RING_SYNC_ST, available);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_dequeue_burst_elem(struct rte_ring *r, void *obj_table,
                            unsigned int esize, unsigned int n,
                            unsigned int *available)
{
  switch (r->cons.sync_type)
  {
  case RTE_RING_SYNC_MT:
    return rte_ring_mc_dequeue_burst_elem(r, obj_table, esize, n,
                                          available);
  case RTE_RING_SYNC_ST:
    return rte_ring_sc_dequeue_burst_elem(r, obj_table, esize, n,
                                          available);
  case RTE_RING_SYNC_MT_RTS:
    return rte_ring_mc_rts_dequeue_burst_elem(r, obj_table, esize,
                                              n, available);
  case RTE_RING_SYNC_MT_HTS:
    return rte_ring_mc_hts_dequeue_burst_elem(r, obj_table, esize,
                                              n, available);
  }
  do
  {
  } while (0);
  if (available != ((void *)0))
    *available = 0;
  return 0;
}

static inline __attribute__((always_inline)) uint32_t
__rte_ring_st_get_tail(struct rte_ring_headtail *ht, uint32_t *tail,
                       uint32_t num)
{
  uint32_t h, n, t;
  h = ht->head;
  t = ht->tail;
  n = h - t;
  do
  {
  } while (0);
  num = (n >= num) ? num : 0;
  *tail = t;
  return num;
}

static inline __attribute__((always_inline)) void
__rte_ring_st_set_head_tail(struct rte_ring_headtail *ht,
                            uint32_t tail, uint32_t num,
                            uint32_t enqueue)
{
  uint32_t pos;
  (void)(enqueue);
  pos = tail + num;
  ht->head = pos;
  __atomic_store_n(&ht->tail, pos, 3);
}

static inline __attribute__((always_inline)) uint32_t
__rte_ring_hts_get_tail(struct rte_ring_hts_headtail *ht, uint32_t *tail,
                        uint32_t num)
{
  uint32_t n;
  union __rte_ring_hts_pos p;
  p.raw = __atomic_load_n(&ht->ht.raw, 0);
  n = p.pos.head - p.pos.tail;
  do
  {
  } while (0);
  num = (n >= num) ? num : 0;
  *tail = p.pos.tail;
  return num;
}

static inline __attribute__((always_inline)) void
__rte_ring_hts_set_head_tail(struct rte_ring_hts_headtail *ht,
                             uint32_t tail, uint32_t num,
                             uint32_t enqueue)
{
  union __rte_ring_hts_pos p;
  (void)(enqueue);
  p.pos.head = tail + num;
  p.pos.tail = p.pos.head;
  __atomic_store_n(&ht->ht.raw, p.raw, 3);
}

static inline __attribute__((always_inline)) unsigned int
__rte_ring_do_enqueue_start(struct rte_ring *r, uint32_t n,
                            enum rte_ring_queue_behavior behavior,
                            uint32_t *free_space)
{
  uint32_t free, head, next;
  switch (r->prod.sync_type)
  {
  case RTE_RING_SYNC_ST:
    n = __rte_ring_move_prod_head(r, RTE_RING_SYNC_ST, n,
                                  behavior, &head, &next, &free);
    break;
  case RTE_RING_SYNC_MT_HTS:
    n = __rte_ring_hts_move_prod_head(r, n, behavior, &head, &free);
    break;
  case RTE_RING_SYNC_MT:
  case RTE_RING_SYNC_MT_RTS:
  default:
    do
    {
    } while (0);
    n = 0;
    free = 0;
  }
  if (free_space != ((void *)0))
    *free_space = free - n;
  return n;
}

static inline __attribute__((always_inline)) unsigned int
__rte_ring_do_dequeue_start(struct rte_ring *r, void *obj_table,
                            uint32_t esize, uint32_t n,
                            enum rte_ring_queue_behavior behavior,
                            uint32_t *available)
{
  uint32_t avail, head, next;
  switch (r->cons.sync_type)
  {
  case RTE_RING_SYNC_ST:
    n = __rte_ring_move_cons_head(r, RTE_RING_SYNC_ST, n,
                                  behavior, &head, &next, &avail);
    break;
  case RTE_RING_SYNC_MT_HTS:
    n = __rte_ring_hts_move_cons_head(r, n, behavior, &head, &avail);
    break;
  case RTE_RING_SYNC_MT:
  case RTE_RING_SYNC_MT_RTS:
  default:
    do
    {
    } while (0);
    n = 0;
    avail = 0;
  }
  if (n != 0)
    __rte_ring_dequeue_elems(r, head, obj_table, esize, n);
  if (available != ((void *)0))
    *available = avail - n;
  return n;
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_enqueue_bulk_elem_start(struct rte_ring *r, unsigned int n,
                                 unsigned int *free_space)
{
  return __rte_ring_do_enqueue_start(r, n, RTE_RING_QUEUE_FIXED, free_space);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_enqueue_bulk_start(struct rte_ring *r, unsigned int n,
                            unsigned int *free_space)
{
  return rte_ring_enqueue_bulk_elem_start(r, n, free_space);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_enqueue_burst_elem_start(struct rte_ring *r, unsigned int n,
                                  unsigned int *free_space)
{
  return __rte_ring_do_enqueue_start(r, n, RTE_RING_QUEUE_VARIABLE,
                                     free_space);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_enqueue_burst_start(struct rte_ring *r, unsigned int n,
                             unsigned int *free_space)
{
  return rte_ring_enqueue_burst_elem_start(r, n, free_space);
}

static inline __attribute__((always_inline)) void
rte_ring_enqueue_elem_finish(struct rte_ring *r,
                             const void *obj_table,
                             unsigned int esize, unsigned int n)
{
  uint32_t tail;
  switch (r->prod.sync_type)
  {
  case RTE_RING_SYNC_ST:
    n = __rte_ring_st_get_tail(&r->prod, &tail, n);
    if (n != 0)
      __rte_ring_enqueue_elems(r, tail, obj_table, esize, n);
    __rte_ring_st_set_head_tail(&r->prod, tail, n, 1);
    break;
  case RTE_RING_SYNC_MT_HTS:
    n = __rte_ring_hts_get_tail(&r->hts_prod, &tail, n);
    if (n != 0)
      __rte_ring_enqueue_elems(r, tail, obj_table, esize, n);
    __rte_ring_hts_set_head_tail(&r->hts_prod, tail, n, 1);
    break;
  case RTE_RING_SYNC_MT:
  case RTE_RING_SYNC_MT_RTS:
  default:
    do
    {
    } while (0);
  }
}

static inline __attribute__((always_inline)) void
rte_ring_enqueue_finish(struct rte_ring *r, void *const *obj_table,
                        unsigned int n)
{
  rte_ring_enqueue_elem_finish(r, obj_table, sizeof(uintptr_t), n);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_dequeue_bulk_elem_start(struct rte_ring *r, void *obj_table,
                                 unsigned int esize, unsigned int n,
                                 unsigned int *available)
{
  return __rte_ring_do_dequeue_start(r, obj_table, esize, n,
                                     RTE_RING_QUEUE_FIXED, available);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_dequeue_bulk_start(struct rte_ring *r, void **obj_table,
                            unsigned int n, unsigned int *available)
{
  return rte_ring_dequeue_bulk_elem_start(r, obj_table, sizeof(uintptr_t),
                                          n, available);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_dequeue_burst_elem_start(struct rte_ring *r, void *obj_table,
                                  unsigned int esize, unsigned int n,
                                  unsigned int *available)
{
  return __rte_ring_do_dequeue_start(r, obj_table, esize, n,
                                     RTE_RING_QUEUE_VARIABLE, available);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_dequeue_burst_start(struct rte_ring *r, void **obj_table,
                             unsigned int n, unsigned int *available)
{
  return rte_ring_dequeue_burst_elem_start(r, obj_table,
                                           sizeof(uintptr_t), n, available);
}

static inline __attribute__((always_inline)) void rte_ring_dequeue_elem_finish(struct rte_ring *r, unsigned int n)
{
  uint32_t tail;
  switch (r->cons.sync_type)
  {
  case RTE_RING_SYNC_ST:
    n = __rte_ring_st_get_tail(&r->cons, &tail, n);
    __rte_ring_st_set_head_tail(&r->cons, tail, n, 0);
    break;
  case RTE_RING_SYNC_MT_HTS:
    n = __rte_ring_hts_get_tail(&r->hts_cons, &tail, n);
    __rte_ring_hts_set_head_tail(&r->hts_cons, tail, n, 0);
    break;
  case RTE_RING_SYNC_MT:
  case RTE_RING_SYNC_MT_RTS:
  default:
    do
    {
    } while (0);
  }
}

static inline __attribute__((always_inline)) void rte_ring_dequeue_finish(struct rte_ring *r, unsigned int n)
{
  rte_ring_dequeue_elem_finish(r, n);
}

struct __attribute__((__aligned__(64))) rte_ring_zc_data
{
  void *ptr1;
  void *ptr2;
  unsigned int n1;
};

static inline __attribute__((always_inline)) void
__rte_ring_get_elem_addr(struct rte_ring *r, uint32_t head,
                         uint32_t esize, uint32_t num, void **dst1,
                         uint32_t *n1, void **dst2)
{
  uint32_t idx, scale, nr_idx;
  uint32_t *ring = (uint32_t *)&r[1];
  scale = esize / sizeof(uint32_t);
  idx = head & r->mask;
  nr_idx = idx * scale;
  *dst1 = ring + nr_idx;
  *n1 = num;
  if (idx + num > r->size)
  {
    *n1 = r->size - idx;
    *dst2 = ring;
  }
  else
  {
    *dst2 = ((void *)0);
  }
}

static inline __attribute__((always_inline)) unsigned int
__rte_ring_do_enqueue_zc_elem_start(struct rte_ring *r,
                                    unsigned int esize, uint32_t n,
                                    enum rte_ring_queue_behavior
                                        behavior,
                                    struct rte_ring_zc_data *zcd,
                                    unsigned int *free_space)
{
  uint32_t free, head, next;
  switch (r->prod.sync_type)
  {
  case RTE_RING_SYNC_ST:
    n = __rte_ring_move_prod_head(r, RTE_RING_SYNC_ST, n,
                                  behavior, &head, &next, &free);
    break;
  case RTE_RING_SYNC_MT_HTS:
    n = __rte_ring_hts_move_prod_head(r, n, behavior, &head, &free);
    break;
  case RTE_RING_SYNC_MT:
  case RTE_RING_SYNC_MT_RTS:
  default:
    do
    {
    } while (0);
    n = 0;
    free = 0;
    return n;
  }
  __rte_ring_get_elem_addr(r, head, esize, n, &zcd->ptr1,
                           &zcd->n1, &zcd->ptr2);
  if (free_space != ((void *)0))
    *free_space = free - n;
  return n;
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_enqueue_zc_bulk_elem_start(struct rte_ring *r,
                                    unsigned int esize,
                                    unsigned int n,
                                    struct rte_ring_zc_data *zcd,
                                    unsigned int *free_space)
{
  return __rte_ring_do_enqueue_zc_elem_start(r, esize, n,
                                             RTE_RING_QUEUE_FIXED, zcd,
                                             free_space);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_enqueue_zc_bulk_start(struct rte_ring *r, unsigned int n,
                               struct rte_ring_zc_data *zcd,
                               unsigned int *free_space)
{
  return rte_ring_enqueue_zc_bulk_elem_start(r, sizeof(uintptr_t), n,
                                             zcd, free_space);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_enqueue_zc_burst_elem_start(struct rte_ring *r,
                                     unsigned int esize,
                                     unsigned int n,
                                     struct rte_ring_zc_data *zcd,
                                     unsigned int *free_space)
{
  return __rte_ring_do_enqueue_zc_elem_start(r, esize, n,
                                             RTE_RING_QUEUE_VARIABLE, zcd,
                                             free_space);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_enqueue_zc_burst_start(struct rte_ring *r, unsigned int n,
                                struct rte_ring_zc_data *zcd,
                                unsigned int *free_space)
{
  return rte_ring_enqueue_zc_burst_elem_start(r, sizeof(uintptr_t), n,
                                              zcd, free_space);
}

static inline __attribute__((always_inline)) void rte_ring_enqueue_zc_elem_finish(struct rte_ring *r, unsigned int n)
{
  uint32_t tail;
  switch (r->prod.sync_type)
  {
  case RTE_RING_SYNC_ST:
    n = __rte_ring_st_get_tail(&r->prod, &tail, n);
    __rte_ring_st_set_head_tail(&r->prod, tail, n, 1);
    break;
  case RTE_RING_SYNC_MT_HTS:
    n = __rte_ring_hts_get_tail(&r->hts_prod, &tail, n);
    __rte_ring_hts_set_head_tail(&r->hts_prod, tail, n, 1);
    break;
  case RTE_RING_SYNC_MT:
  case RTE_RING_SYNC_MT_RTS:
  default:
    do
    {
    } while (0);
  }
}

static inline __attribute__((always_inline)) void rte_ring_enqueue_zc_finish(struct rte_ring *r, unsigned int n)
{
  rte_ring_enqueue_zc_elem_finish(r, n);
}

static inline __attribute__((always_inline)) unsigned int
__rte_ring_do_dequeue_zc_elem_start(struct rte_ring *r,
                                    uint32_t esize, uint32_t n,
                                    enum rte_ring_queue_behavior
                                        behavior,
                                    struct rte_ring_zc_data *zcd,
                                    unsigned int *available)
{
  uint32_t avail, head, next;
  switch (r->cons.sync_type)
  {
  case RTE_RING_SYNC_ST:
    n = __rte_ring_move_cons_head(r, RTE_RING_SYNC_ST, n,
                                  behavior, &head, &next, &avail);
    break;
  case RTE_RING_SYNC_MT_HTS:
    n = __rte_ring_hts_move_cons_head(r, n, behavior, &head, &avail);
    break;
  case RTE_RING_SYNC_MT:
  case RTE_RING_SYNC_MT_RTS:
  default:
    do
    {
    } while (0);
    n = 0;
    avail = 0;
    return n;
  }
  __rte_ring_get_elem_addr(r, head, esize, n, &zcd->ptr1,
                           &zcd->n1, &zcd->ptr2);
  if (available != ((void *)0))
    *available = avail - n;
  return n;
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_dequeue_zc_bulk_elem_start(struct rte_ring *r,
                                    unsigned int esize,
                                    unsigned int n,
                                    struct rte_ring_zc_data *zcd,
                                    unsigned int *available)
{
  return __rte_ring_do_dequeue_zc_elem_start(r, esize, n,
                                             RTE_RING_QUEUE_FIXED, zcd,
                                             available);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_dequeue_zc_bulk_start(struct rte_ring *r, unsigned int n,
                               struct rte_ring_zc_data *zcd,
                               unsigned int *available)
{
  return rte_ring_dequeue_zc_bulk_elem_start(r, sizeof(uintptr_t),
                                             n, zcd, available);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_dequeue_zc_burst_elem_start(struct rte_ring *r,
                                     unsigned int esize,
                                     unsigned int n,
                                     struct rte_ring_zc_data *zcd,
                                     unsigned int *available)
{
  return __rte_ring_do_dequeue_zc_elem_start(r, esize, n,
                                             RTE_RING_QUEUE_VARIABLE, zcd,
                                             available);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_dequeue_zc_burst_start(struct rte_ring *r, unsigned int n,
                                struct rte_ring_zc_data *zcd,
                                unsigned int *available)
{
  return rte_ring_dequeue_zc_burst_elem_start(r, sizeof(uintptr_t), n,
                                              zcd, available);
}

static inline __attribute__((always_inline)) void rte_ring_dequeue_zc_elem_finish(struct rte_ring *r, unsigned int n)
{
  uint32_t tail;
  switch (r->cons.sync_type)
  {
  case RTE_RING_SYNC_ST:
    n = __rte_ring_st_get_tail(&r->cons, &tail, n);
    __rte_ring_st_set_head_tail(&r->cons, tail, n, 0);
    break;
  case RTE_RING_SYNC_MT_HTS:
    n = __rte_ring_hts_get_tail(&r->hts_cons, &tail, n);
    __rte_ring_hts_set_head_tail(&r->hts_cons, tail, n, 0);
    break;
  case RTE_RING_SYNC_MT:
  case RTE_RING_SYNC_MT_RTS:
  default:
    do
    {
    } while (0);
  }
}

static inline __attribute__((always_inline)) void rte_ring_dequeue_zc_finish(struct rte_ring *r, unsigned int n)
{
  rte_ring_dequeue_elem_finish(r, n);
}

ssize_t rte_ring_get_memsize(unsigned int count);
int rte_ring_init(struct rte_ring *r, const char *name, unsigned int count,
                  unsigned int flags);
struct rte_ring *rte_ring_create(const char *name, unsigned int count,
                                 int socket_id, unsigned int flags);
void rte_ring_free(struct rte_ring *r);
void rte_ring_dump(FILE *f, const struct rte_ring *r);
static inline __attribute__((always_inline)) unsigned int
rte_ring_mp_enqueue_bulk(struct rte_ring *r, void *const *obj_table,
                         unsigned int n, unsigned int *free_space)
{
  return rte_ring_mp_enqueue_bulk_elem(r, obj_table, sizeof(void *),
                                       n, free_space);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_sp_enqueue_bulk(struct rte_ring *r, void *const *obj_table,
                         unsigned int n, unsigned int *free_space)
{
  return rte_ring_sp_enqueue_bulk_elem(r, obj_table, sizeof(void *),
                                       n, free_space);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_enqueue_bulk(struct rte_ring *r, void *const *obj_table,
                      unsigned int n, unsigned int *free_space)
{
  return rte_ring_enqueue_bulk_elem(r, obj_table, sizeof(void *),
                                    n, free_space);
}

static inline __attribute__((always_inline)) int
rte_ring_mp_enqueue(struct rte_ring *r, void *obj)
{
  return rte_ring_mp_enqueue_elem(r, &obj, sizeof(void *));
}

static inline __attribute__((always_inline)) int
rte_ring_sp_enqueue(struct rte_ring *r, void *obj)
{
  return rte_ring_sp_enqueue_elem(r, &obj, sizeof(void *));
}

static inline __attribute__((always_inline)) int
rte_ring_enqueue(struct rte_ring *r, void *obj)
{
  return rte_ring_enqueue_elem(r, &obj, sizeof(void *));
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_mc_dequeue_bulk(struct rte_ring *r, void **obj_table,
                         unsigned int n, unsigned int *available)
{
  return rte_ring_mc_dequeue_bulk_elem(r, obj_table, sizeof(void *),
                                       n, available);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_sc_dequeue_bulk(struct rte_ring *r, void **obj_table,
                         unsigned int n, unsigned int *available)
{
  return rte_ring_sc_dequeue_bulk_elem(r, obj_table, sizeof(void *),
                                       n, available);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_dequeue_bulk(struct rte_ring *r, void **obj_table,
                      unsigned int n, unsigned int *available)
{
  return rte_ring_dequeue_bulk_elem(r, obj_table, sizeof(void *),
                                    n, available);
}

static inline __attribute__((always_inline)) int
rte_ring_mc_dequeue(struct rte_ring *r, void **obj_p)
{
  return rte_ring_mc_dequeue_elem(r, obj_p, sizeof(void *));
}

static inline __attribute__((always_inline)) int
rte_ring_sc_dequeue(struct rte_ring *r, void **obj_p)
{
  return rte_ring_sc_dequeue_elem(r, obj_p, sizeof(void *));
}

static inline __attribute__((always_inline)) int
rte_ring_dequeue(struct rte_ring *r, void **obj_p)
{
  return rte_ring_dequeue_elem(r, obj_p, sizeof(void *));
}

void rte_ring_reset(struct rte_ring *r);
static inline unsigned int
rte_ring_count(const struct rte_ring *r)
{
  uint32_t prod_tail = r->prod.tail;
  uint32_t cons_tail = r->cons.tail;
  uint32_t count = (prod_tail - cons_tail) & r->mask;
  return (count > r->capacity) ? r->capacity : count;
}

static inline unsigned int
rte_ring_free_count(const struct rte_ring *r)
{
  return r->capacity - rte_ring_count(r);
}

static inline int
rte_ring_full(const struct rte_ring *r)
{
  return rte_ring_free_count(r) == 0;
}

static inline int
rte_ring_empty(const struct rte_ring *r)
{
  uint32_t prod_tail = r->prod.tail;
  uint32_t cons_tail = r->cons.tail;
  return cons_tail == prod_tail;
}

static inline unsigned int
rte_ring_get_size(const struct rte_ring *r)
{
  return r->size;
}

static inline unsigned int
rte_ring_get_capacity(const struct rte_ring *r)
{
  return r->capacity;
}

static inline enum rte_ring_sync_type
rte_ring_get_prod_sync_type(const struct rte_ring *r)
{
  return r->prod.sync_type;
}

static inline int
rte_ring_is_prod_single(const struct rte_ring *r)
{
  return (rte_ring_get_prod_sync_type(r) == RTE_RING_SYNC_ST);
}

static inline enum rte_ring_sync_type
rte_ring_get_cons_sync_type(const struct rte_ring *r)
{
  return r->cons.sync_type;
}

static inline int
rte_ring_is_cons_single(const struct rte_ring *r)
{
  return (rte_ring_get_cons_sync_type(r) == RTE_RING_SYNC_ST);
}

void rte_ring_list_dump(FILE *f);
struct rte_ring *rte_ring_lookup(const char *name);
static inline __attribute__((always_inline)) unsigned int
rte_ring_mp_enqueue_burst(struct rte_ring *r, void *const *obj_table,
                          unsigned int n, unsigned int *free_space)
{
  return rte_ring_mp_enqueue_burst_elem(r, obj_table, sizeof(void *),
                                        n, free_space);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_sp_enqueue_burst(struct rte_ring *r, void *const *obj_table,
                          unsigned int n, unsigned int *free_space)
{
  return rte_ring_sp_enqueue_burst_elem(r, obj_table, sizeof(void *),
                                        n, free_space);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_enqueue_burst(struct rte_ring *r, void *const *obj_table,
                       unsigned int n, unsigned int *free_space)
{
  return rte_ring_enqueue_burst_elem(r, obj_table, sizeof(void *),
                                     n, free_space);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_mc_dequeue_burst(struct rte_ring *r, void **obj_table,
                          unsigned int n, unsigned int *available)
{
  return rte_ring_mc_dequeue_burst_elem(r, obj_table, sizeof(void *),
                                        n, available);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_sc_dequeue_burst(struct rte_ring *r, void **obj_table,
                          unsigned int n, unsigned int *available)
{
  return rte_ring_sc_dequeue_burst_elem(r, obj_table, sizeof(void *),
                                        n, available);
}

static inline __attribute__((always_inline)) unsigned int
rte_ring_dequeue_burst(struct rte_ring *r, void **obj_table,
                       unsigned int n, unsigned int *available)
{
  return rte_ring_dequeue_burst_elem(r, obj_table, sizeof(void *),
                                     n, available);
}

static inline void rte_mov16(uint8_t *dst, const uint8_t *src);
static inline void rte_mov32(uint8_t *dst, const uint8_t *src);
static inline void rte_mov64(uint8_t *dst, const uint8_t *src);
static inline void rte_mov128(uint8_t *dst, const uint8_t *src);
static inline void rte_mov256(uint8_t *dst, const uint8_t *src);
static inline void
rte_mov16(uint8_t *dst, const uint8_t *src)
{
  memcpy(dst, src, 16);
}

static inline void
rte_mov32(uint8_t *dst, const uint8_t *src)
{
  memcpy(dst, src, 32);
}

static inline void
rte_mov48(uint8_t *dst, const uint8_t *src)
{
  memcpy(dst, src, 48);
}

static inline void
rte_mov64(uint8_t *dst, const uint8_t *src)
{
  memcpy(dst, src, 64);
}

static inline void
rte_mov128(uint8_t *dst, const uint8_t *src)
{
  memcpy(dst, src, 128);
}

static inline void
rte_mov256(uint8_t *dst, const uint8_t *src)
{
  memcpy(dst, src, 256);
}

enum timer_source
{
  EAL_TIMER_TSC = 0,
  EAL_TIMER_HPET
};
extern enum timer_source eal_timer_source;
uint64_t rte_get_tsc_hz(void);
static inline uint64_t rte_get_tsc_cycles(void);
static inline uint64_t
rte_get_timer_cycles(void)
{
  return rte_get_tsc_cycles();
}

static inline uint64_t
rte_get_timer_hz(void)
{
  return rte_get_tsc_hz();
}

extern void (*rte_delay_us)(unsigned int us);
static inline void
rte_delay_ms(unsigned ms)
{
  rte_delay_us(ms * 1000);
}

void rte_delay_us_block(unsigned int us);
void rte_delay_us_sleep(unsigned int us);
void rte_delay_us_callback_register(void (*userfunc)(unsigned int));
static inline __attribute__((always_inline)) uint64_t
__rte_riscv_rdtime(void)
{
  uint64_t tsc;
  __asm__ volatile("csrr %0, time" : "=r"(tsc)::"memory");
  return tsc;
}

static inline __attribute__((always_inline)) uint64_t
__rte_riscv_rdtime_precise(void)
{
  __asm__ volatile("fence" ::: "memory");
  return __rte_riscv_rdtime();
}

static inline __attribute__((always_inline)) uint64_t
__rte_riscv_rdcycle(void)
{
  uint64_t tsc;
  __asm__ volatile("csrr %0, cycle" : "=r"(tsc)::"memory");
  return tsc;
}

static inline __attribute__((always_inline)) uint64_t
__rte_riscv_rdcycle_precise(void)
{
  __asm__ volatile("fence" ::: "memory");
  return __rte_riscv_rdcycle();
}

static inline __attribute__((always_inline)) uint64_t
rte_rdtsc(void)
{
  if (!0)
    return __rte_riscv_rdtime();
  return __rte_riscv_rdcycle();
}

static inline uint64_t
rte_rdtsc_precise(void)
{
  if (!0)
    return __rte_riscv_rdtime_precise();
  return __rte_riscv_rdcycle_precise();
}

static inline __attribute__((always_inline)) uint64_t
rte_get_tsc_cycles(void)
{
  return rte_rdtsc();
}

typedef uint64_t rte_trace_point_t;
__attribute__((section(".text.experimental"))) int rte_trace_point_enable(rte_trace_point_t *tp);
__attribute__((section(".text.experimental"))) int rte_trace_point_disable(rte_trace_point_t *tp);
__attribute__((section(".text.experimental")))
_Bool
rte_trace_point_is_enabled(rte_trace_point_t *tp);
__attribute__((section(".text.experimental")))
rte_trace_point_t *
rte_trace_point_lookup(const char *name);
__attribute__((section(".text.experimental"))) static inline __attribute__((always_inline))
_Bool
__rte_trace_point_fp_is_enabled(void)
{
  return 0;
}

__attribute__((section(".text.experimental"))) void __rte_trace_mem_per_thread_alloc(void);
__attribute__((section(".text.experimental"))) void __rte_trace_point_emit_field(size_t sz, const char *field,
                                                                                 const char *type);
__attribute__((section(".text.experimental"))) int __rte_trace_point_register(rte_trace_point_t *trace,
                                                                              const char *name,
                                                                              void (*register_fn)(void));
struct __rte_trace_stream_header
{
  uint32_t magic;
  rte_uuid_t uuid;
  uint32_t lcore_id;
  char thread_name[32];
} __attribute__((__packed__));
struct __rte_trace_header
{
  uint32_t offset;
  uint32_t len;
  struct __rte_trace_stream_header stream_header;
  uint8_t mem[];
};
extern __thread void *per_lcore_trace_mem;
static inline __attribute__((always_inline)) void *__rte_trace_mem_get(uint64_t in)
{
  struct __rte_trace_header *trace =
      (struct __rte_trace_header *)((per_lcore_trace_mem));
  const uint16_t sz = in & (0xffffULL << 0);
  if (__builtin_expect(!!(trace == ((void *)0)), 0))
  {
    __rte_trace_mem_per_thread_alloc();
    trace = (struct __rte_trace_header *)((per_lcore_trace_mem));
    if (__builtin_expect(!!(trace == ((void *)0)), 0))
      return ((void *)0);
  }
  uint32_t offset = trace->offset;
  if (__builtin_expect(!!((offset + sz) >= trace->len), 0))
  {
    if (__builtin_expect(!!(in & (1ULL << 62)), 0))
      return ((void *)0);
    offset = 0;
  }
  offset =
      (__typeof__(((offset) +
                   ((__typeof__(offset))(sizeof(uint64_t)) - 1))))((((offset) +
                                                                     ((__typeof__(offset))(sizeof(uint64_t)) -
                                                                      1))) &
                                                                   (~((__typeof__(((offset) +
                                                                                   ((__typeof__(offset))(sizeof(uint64_t)) -
                                                                                    1))))((sizeof(uint64_t)) - 1))));
  void *mem = ((void *)((uintptr_t)(&trace->mem[0]) + (offset)));
  offset += sz;
  trace->offset = offset;
  return mem;
}

static inline __attribute__((always_inline)) void *__rte_trace_point_emit_ev_header(void *mem, uint64_t in)
{
  uint64_t val;
  val = rte_get_tsc_cycles() & ~(0xffffULL << (48));
  val |= ((in & (0xffffULL << (16))) << ((48) - (16)));
  *(uint64_t *)mem = val;
  return ((void *)((uintptr_t)(mem) + (sizeof(uint64_t))));
}

extern rte_trace_point_t __rte_mempool_trace_ops_dequeue_bulk;
static inline __attribute__((always_inline)) void rte_mempool_trace_ops_dequeue_bulk(void *mempool, void **obj_table,
                                                                                     uint32_t nb_objs)
{
  if (!__rte_trace_point_fp_is_enabled())
    return;
  void *mem;
  do
  {
    const uint64_t val =
        __atomic_load_n(&__rte_mempool_trace_ops_dequeue_bulk, 2);
    if (__builtin_expect(!!(!(val & (1ULL << 63))), 1))
      return;
    mem = __rte_trace_mem_get(val);
    if (__builtin_expect(!!(mem == ((void *)0)), 0))
      return;
    mem = __rte_trace_point_emit_ev_header(mem, val);
  } while (0);
  do
  {
    memcpy(mem, &(mempool), sizeof(mempool));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(mempool))));
  } while (0);
  do
  {
    memcpy(mem, &(obj_table), sizeof(obj_table));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(obj_table))));
  } while (0);
  do
  {
    memcpy(mem, &(nb_objs), sizeof(nb_objs));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(nb_objs))));
  } while (0);
}

extern rte_trace_point_t __rte_mempool_trace_ops_dequeue_contig_blocks;
static inline __attribute__((always_inline)) void rte_mempool_trace_ops_dequeue_contig_blocks(void *mempool,
                                                                                              void **first_obj_table,
                                                                                              uint32_t nb_objs)
{
  if (!__rte_trace_point_fp_is_enabled())
    return;
  void *mem;
  do
  {
    const uint64_t val =
        __atomic_load_n(&__rte_mempool_trace_ops_dequeue_contig_blocks, 2);
    if (__builtin_expect(!!(!(val & (1ULL << 63))), 1))
      return;
    mem = __rte_trace_mem_get(val);
    if (__builtin_expect(!!(mem == ((void *)0)), 0))
      return;
    mem = __rte_trace_point_emit_ev_header(mem, val);
  } while (0);
  do
  {
    memcpy(mem, &(mempool), sizeof(mempool));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(mempool))));
  } while (0);
  do
  {
    memcpy(mem, &(first_obj_table), sizeof(first_obj_table));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(first_obj_table))));
  } while (0);
  do
  {
    memcpy(mem, &(nb_objs), sizeof(nb_objs));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(nb_objs))));
  } while (0);
}

extern rte_trace_point_t __rte_mempool_trace_ops_enqueue_bulk;
static inline __attribute__((always_inline)) void rte_mempool_trace_ops_enqueue_bulk(void *mempool,
                                                                                     void *const *obj_table,
                                                                                     uint32_t nb_objs)
{
  if (!__rte_trace_point_fp_is_enabled())
    return;
  void *mem;
  do
  {
    const uint64_t val =
        __atomic_load_n(&__rte_mempool_trace_ops_enqueue_bulk, 2);
    if (__builtin_expect(!!(!(val & (1ULL << 63))), 1))
      return;
    mem = __rte_trace_mem_get(val);
    if (__builtin_expect(!!(mem == ((void *)0)), 0))
      return;
    mem = __rte_trace_point_emit_ev_header(mem, val);
  } while (0);
  do
  {
    memcpy(mem, &(mempool), sizeof(mempool));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(mempool))));
  } while (0);
  do
  {
    memcpy(mem, &(obj_table), sizeof(obj_table));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(obj_table))));
  } while (0);
  do
  {
    memcpy(mem, &(nb_objs), sizeof(nb_objs));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(nb_objs))));
  } while (0);
}

extern rte_trace_point_t __rte_mempool_trace_generic_put;
static inline __attribute__((always_inline)) void rte_mempool_trace_generic_put(void *mempool,
                                                                                void *const *obj_table,
                                                                                uint32_t nb_objs, void *cache)
{
  if (!__rte_trace_point_fp_is_enabled())
    return;
  void *mem;
  do
  {
    const uint64_t val =
        __atomic_load_n(&__rte_mempool_trace_generic_put, 2);
    if (__builtin_expect(!!(!(val & (1ULL << 63))), 1))
      return;
    mem = __rte_trace_mem_get(val);
    if (__builtin_expect(!!(mem == ((void *)0)), 0))
      return;
    mem = __rte_trace_point_emit_ev_header(mem, val);
  } while (0);
  do
  {
    memcpy(mem, &(mempool), sizeof(mempool));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(mempool))));
  } while (0);
  do
  {
    memcpy(mem, &(obj_table), sizeof(obj_table));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(obj_table))));
  } while (0);
  do
  {
    memcpy(mem, &(nb_objs), sizeof(nb_objs));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(nb_objs))));
  } while (0);
  do
  {
    memcpy(mem, &(cache), sizeof(cache));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(cache))));
  } while (0);
}

extern rte_trace_point_t __rte_mempool_trace_put_bulk;
static inline __attribute__((always_inline)) void rte_mempool_trace_put_bulk(void *mempool, void *const *obj_table,
                                                                             uint32_t nb_objs, void *cache)
{
  if (!__rte_trace_point_fp_is_enabled())
    return;
  void *mem;
  do
  {
    const uint64_t val = __atomic_load_n(&__rte_mempool_trace_put_bulk, 2);
    if (__builtin_expect(!!(!(val & (1ULL << 63))), 1))
      return;
    mem = __rte_trace_mem_get(val);
    if (__builtin_expect(!!(mem == ((void *)0)), 0))
      return;
    mem = __rte_trace_point_emit_ev_header(mem, val);
  } while (0);
  do
  {
    memcpy(mem, &(mempool), sizeof(mempool));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(mempool))));
  } while (0);
  do
  {
    memcpy(mem, &(obj_table), sizeof(obj_table));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(obj_table))));
  } while (0);
  do
  {
    memcpy(mem, &(nb_objs), sizeof(nb_objs));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(nb_objs))));
  } while (0);
  do
  {
    memcpy(mem, &(cache), sizeof(cache));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(cache))));
  } while (0);
}

extern rte_trace_point_t __rte_mempool_trace_generic_get;
static inline __attribute__((always_inline)) void rte_mempool_trace_generic_get(void *mempool,
                                                                                void *const *obj_table,
                                                                                uint32_t nb_objs, void *cache)
{
  if (!__rte_trace_point_fp_is_enabled())
    return;
  void *mem;
  do
  {
    const uint64_t val =
        __atomic_load_n(&__rte_mempool_trace_generic_get, 2);
    if (__builtin_expect(!!(!(val & (1ULL << 63))), 1))
      return;
    mem = __rte_trace_mem_get(val);
    if (__builtin_expect(!!(mem == ((void *)0)), 0))
      return;
    mem = __rte_trace_point_emit_ev_header(mem, val);
  } while (0);
  do
  {
    memcpy(mem, &(mempool), sizeof(mempool));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(mempool))));
  } while (0);
  do
  {
    memcpy(mem, &(obj_table), sizeof(obj_table));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(obj_table))));
  } while (0);
  do
  {
    memcpy(mem, &(nb_objs), sizeof(nb_objs));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(nb_objs))));
  } while (0);
  do
  {
    memcpy(mem, &(cache), sizeof(cache));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(cache))));
  } while (0);
}

extern rte_trace_point_t __rte_mempool_trace_get_bulk;
static inline __attribute__((always_inline)) void rte_mempool_trace_get_bulk(void *mempool, void **obj_table,
                                                                             uint32_t nb_objs, void *cache)
{
  if (!__rte_trace_point_fp_is_enabled())
    return;
  void *mem;
  do
  {
    const uint64_t val = __atomic_load_n(&__rte_mempool_trace_get_bulk, 2);
    if (__builtin_expect(!!(!(val & (1ULL << 63))), 1))
      return;
    mem = __rte_trace_mem_get(val);
    if (__builtin_expect(!!(mem == ((void *)0)), 0))
      return;
    mem = __rte_trace_point_emit_ev_header(mem, val);
  } while (0);
  do
  {
    memcpy(mem, &(mempool), sizeof(mempool));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(mempool))));
  } while (0);
  do
  {
    memcpy(mem, &(obj_table), sizeof(obj_table));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(obj_table))));
  } while (0);
  do
  {
    memcpy(mem, &(nb_objs), sizeof(nb_objs));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(nb_objs))));
  } while (0);
  do
  {
    memcpy(mem, &(cache), sizeof(cache));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(cache))));
  } while (0);
}

extern rte_trace_point_t __rte_mempool_trace_get_contig_blocks;
static inline __attribute__((always_inline)) void rte_mempool_trace_get_contig_blocks(void *mempool,
                                                                                      void **first_obj_table,
                                                                                      uint32_t nb_objs)
{
  if (!__rte_trace_point_fp_is_enabled())
    return;
  void *mem;
  do
  {
    const uint64_t val =
        __atomic_load_n(&__rte_mempool_trace_get_contig_blocks, 2);
    if (__builtin_expect(!!(!(val & (1ULL << 63))), 1))
      return;
    mem = __rte_trace_mem_get(val);
    if (__builtin_expect(!!(mem == ((void *)0)), 0))
      return;
    mem = __rte_trace_point_emit_ev_header(mem, val);
  } while (0);
  do
  {
    memcpy(mem, &(mempool), sizeof(mempool));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(mempool))));
  } while (0);
  do
  {
    memcpy(mem, &(first_obj_table), sizeof(first_obj_table));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(first_obj_table))));
  } while (0);
  do
  {
    memcpy(mem, &(nb_objs), sizeof(nb_objs));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(nb_objs))));
  } while (0);
}

extern rte_trace_point_t __rte_mempool_trace_default_cache;
static inline __attribute__((always_inline)) void rte_mempool_trace_default_cache(void *mempool, uint32_t lcore_id,
                                                                                  void *default_cache)
{
  if (!__rte_trace_point_fp_is_enabled())
    return;
  void *mem;
  do
  {
    const uint64_t val =
        __atomic_load_n(&__rte_mempool_trace_default_cache, 2);
    if (__builtin_expect(!!(!(val & (1ULL << 63))), 1))
      return;
    mem = __rte_trace_mem_get(val);
    if (__builtin_expect(!!(mem == ((void *)0)), 0))
      return;
    mem = __rte_trace_point_emit_ev_header(mem, val);
  } while (0);
  do
  {
    memcpy(mem, &(mempool), sizeof(mempool));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(mempool))));
  } while (0);
  do
  {
    memcpy(mem, &(lcore_id), sizeof(lcore_id));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(lcore_id))));
  } while (0);
  do
  {
    memcpy(mem, &(default_cache), sizeof(default_cache));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(default_cache))));
  } while (0);
}

extern rte_trace_point_t __rte_mempool_trace_cache_flush;
static inline __attribute__((always_inline)) void rte_mempool_trace_cache_flush(void *cache, void *mempool)
{
  if (!__rte_trace_point_fp_is_enabled())
    return;
  void *mem;
  do
  {
    const uint64_t val =
        __atomic_load_n(&__rte_mempool_trace_cache_flush, 2);
    if (__builtin_expect(!!(!(val & (1ULL << 63))), 1))
      return;
    mem = __rte_trace_mem_get(val);
    if (__builtin_expect(!!(mem == ((void *)0)), 0))
      return;
    mem = __rte_trace_point_emit_ev_header(mem, val);
  } while (0);
  do
  {
    memcpy(mem, &(cache), sizeof(cache));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(cache))));
  } while (0);
  do
  {
    memcpy(mem, &(mempool), sizeof(mempool));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(mempool))));
  } while (0);
}

struct __attribute__((__aligned__(64))) rte_mempool_cache
{
  uint32_t size;
  uint32_t flushthresh;
  uint32_t len;
  _Alignas(64) void *objs[512 * 2];
};

struct rte_mempool_objsz
{
  uint32_t elt_size;
  uint32_t header_size;
  uint32_t trailer_size;
  uint32_t total_size;
};
struct rte_mempool_objhdr
{
  struct
  {
    struct rte_mempool_objhdr *stqe_next;
  } next;
  struct rte_mempool *mp;
  rte_iova_t iova;
};
struct rte_mempool_objhdr_list
{
  struct rte_mempool_objhdr *stqh_first;
  struct rte_mempool_objhdr **stqh_last;
};
extern int rte_mempool_logtype;
struct rte_mempool_memhdr_list
{
  struct rte_mempool_memhdr *stqh_first;
  struct rte_mempool_memhdr **stqh_last;
};
typedef void(rte_mempool_memchunk_free_cb_t)(struct rte_mempool_memhdr *
                                                 memhdr,
                                             void *opaque);
struct rte_mempool_memhdr
{
  struct
  {
    struct rte_mempool_memhdr *stqe_next;
  } next;
  struct rte_mempool *mp;
  void *addr;
  rte_iova_t iova;
  size_t len;
  rte_mempool_memchunk_free_cb_t *free_cb;
  void *opaque;
};
struct __attribute__((__aligned__(64))) rte_mempool_info
{
  unsigned int contig_block_size;
};

struct __attribute__((__aligned__(64))) rte_mempool
{
  char name[((32 - sizeof("RG_") + 1) - sizeof("MP_") + 1)];
  union
  {
    void *pool_data;
    uint64_t pool_id;
  };
  void *pool_config;
  const struct rte_memzone *mz;
  unsigned int flags;
  int socket_id;
  uint32_t size;
  uint32_t cache_size;
  uint32_t elt_size;
  uint32_t header_size;
  uint32_t trailer_size;
  unsigned private_data_size;
  int32_t ops_index;
  struct rte_mempool_cache *local_cache;
  uint32_t populated_size;
  struct rte_mempool_objhdr_list elt_list;
  uint32_t nb_mem_chunks;
  struct rte_mempool_memhdr_list mem_list;
};

static inline struct rte_mempool_objhdr *
rte_mempool_get_header(void *obj)
{
  return (struct rte_mempool_objhdr
              *)((void *)((uintptr_t)(obj) -
                          (sizeof(struct rte_mempool_objhdr))));
}

static inline struct rte_mempool *
rte_mempool_from_obj(void *obj)
{
  struct rte_mempool_objhdr *hdr = rte_mempool_get_header(obj);
  return hdr->mp;
}

static inline struct rte_mempool_objtlr *
rte_mempool_get_trailer(void *obj)
{
  struct rte_mempool *mp = rte_mempool_from_obj(obj);
  return (struct rte_mempool_objtlr
              *)((void *)((uintptr_t)(obj) + (mp->elt_size)));
}

void rte_mempool_check_cookies(const struct rte_mempool *mp,
                               void *const *obj_table_const, unsigned n,
                               int free);
void rte_mempool_contig_blocks_check_cookies(const struct rte_mempool *mp,
                                             void *const
                                                 *first_obj_table_const,
                                             unsigned int n, int free);
typedef int (*rte_mempool_alloc_t)(struct rte_mempool *mp);
typedef void (*rte_mempool_free_t)(struct rte_mempool *mp);
typedef int (*rte_mempool_enqueue_t)(struct rte_mempool *mp,
                                     void *const *obj_table, unsigned int n);
typedef int (*rte_mempool_dequeue_t)(struct rte_mempool *mp,
                                     void **obj_table, unsigned int n);
typedef int (*rte_mempool_dequeue_contig_blocks_t)(struct rte_mempool *mp,
                                                   void **first_obj_table,
                                                   unsigned int n);
typedef unsigned (*rte_mempool_get_count)(const struct rte_mempool *mp);
typedef ssize_t (*rte_mempool_calc_mem_size_t)(const struct rte_mempool *mp,
                                               uint32_t obj_num,
                                               uint32_t pg_shift,
                                               size_t *min_chunk_size,
                                               size_t *align);
ssize_t rte_mempool_op_calc_mem_size_helper(const struct rte_mempool *mp,
                                            uint32_t obj_num,
                                            uint32_t pg_shift,
                                            size_t chunk_reserve,
                                            size_t *min_chunk_size,
                                            size_t *align);
ssize_t rte_mempool_op_calc_mem_size_default(const struct rte_mempool *mp,
                                             uint32_t obj_num,
                                             uint32_t pg_shift,
                                             size_t *min_chunk_size,
                                             size_t *align);
typedef void(rte_mempool_populate_obj_cb_t)(struct rte_mempool *mp,
                                            void *opaque, void *vaddr,
                                            rte_iova_t iova);
typedef int (*rte_mempool_populate_t)(struct rte_mempool *mp,
                                      unsigned int max_objs,
                                      void *vaddr, rte_iova_t iova,
                                      size_t len,
                                      rte_mempool_populate_obj_cb_t *obj_cb,
                                      void *obj_cb_arg);
int rte_mempool_op_populate_helper(struct rte_mempool *mp,
                                   unsigned int flags, unsigned int max_objs,
                                   void *vaddr, rte_iova_t iova, size_t len,
                                   rte_mempool_populate_obj_cb_t *obj_cb,
                                   void *obj_cb_arg);
int rte_mempool_op_populate_default(struct rte_mempool *mp,
                                    unsigned int max_objs,
                                    void *vaddr, rte_iova_t iova, size_t len,
                                    rte_mempool_populate_obj_cb_t *obj_cb,
                                    void *obj_cb_arg);
typedef int (*rte_mempool_get_info_t)(const struct rte_mempool *mp,
                                      struct rte_mempool_info *info);
struct __attribute__((__aligned__(64))) rte_mempool_ops
{
  char name[32];
  rte_mempool_alloc_t alloc;
  rte_mempool_free_t free;
  rte_mempool_enqueue_t enqueue;
  rte_mempool_dequeue_t dequeue;
  rte_mempool_get_count get_count;
  rte_mempool_calc_mem_size_t calc_mem_size;
  rte_mempool_populate_t populate;
  rte_mempool_get_info_t get_info;
  rte_mempool_dequeue_contig_blocks_t dequeue_contig_blocks;
};

struct __attribute__((__aligned__(64))) rte_mempool_ops_table
{
  rte_spinlock_t sl;
  uint32_t num_ops;
  struct rte_mempool_ops ops[16];
};

extern struct rte_mempool_ops_table rte_mempool_ops_table;
static inline struct rte_mempool_ops *
rte_mempool_get_ops(int ops_index)
{
  do
  {
    if (__builtin_expect(!!(!((ops_index >= 0) && (ops_index < 16))), 0))
      __rte_panic(__func__, "line %d\tassert \"%s\" failed\n"
                            "%.0s",
                  754,
                  "(ops_index >= 0) && (ops_index < RTE_MEMPOOL_MAX_OPS_IDX)",
                  "dummy");
  } while (0);
  return &rte_mempool_ops_table.ops[ops_index];
}

int rte_mempool_ops_alloc(struct rte_mempool *mp);
static inline int
rte_mempool_ops_dequeue_bulk(struct rte_mempool *mp,
                             void **obj_table, unsigned n)
{
  struct rte_mempool_ops *ops;
  int ret;
  rte_mempool_trace_ops_dequeue_bulk(mp, obj_table, n);
  ops = rte_mempool_get_ops(mp->ops_index);
  ret = ops->dequeue(mp, obj_table, n);
  if (ret == 0)
  {
    do
    {
    } while (0);
    do
    {
    } while (0);
  }
  return ret;
}

static inline int
rte_mempool_ops_dequeue_contig_blocks(struct rte_mempool *mp,
                                      void **first_obj_table, unsigned int n)
{
  struct rte_mempool_ops *ops;
  ops = rte_mempool_get_ops(mp->ops_index);
  do
  {
  } while (0);
  rte_mempool_trace_ops_dequeue_contig_blocks(mp, first_obj_table, n);
  return ops->dequeue_contig_blocks(mp, first_obj_table, n);
}

static inline int
rte_mempool_ops_enqueue_bulk(struct rte_mempool *mp, void *const *obj_table,
                             unsigned n)
{
  struct rte_mempool_ops *ops;
  int ret;
  do
  {
  } while (0);
  do
  {
  } while (0);
  rte_mempool_trace_ops_enqueue_bulk(mp, obj_table, n);
  ops = rte_mempool_get_ops(mp->ops_index);
  ret = ops->enqueue(mp, obj_table, n);
  return ret;
}

unsigned rte_mempool_ops_get_count(const struct rte_mempool *mp);
ssize_t rte_mempool_ops_calc_mem_size(const struct rte_mempool *mp,
                                      uint32_t obj_num, uint32_t pg_shift,
                                      size_t *min_chunk_size, size_t *align);
int rte_mempool_ops_populate(struct rte_mempool *mp, unsigned int max_objs,
                             void *vaddr, rte_iova_t iova, size_t len,
                             rte_mempool_populate_obj_cb_t *obj_cb,
                             void *obj_cb_arg);
int rte_mempool_ops_get_info(const struct rte_mempool *mp,
                             struct rte_mempool_info *info);
void rte_mempool_ops_free(struct rte_mempool *mp);
int rte_mempool_set_ops_byname(struct rte_mempool *mp, const char *name,
                               void *pool_config);
int rte_mempool_register_ops(const struct rte_mempool_ops *ops);
typedef void(rte_mempool_obj_cb_t)(struct rte_mempool *mp,
                                   void *opaque, void *obj,
                                   unsigned obj_idx);
typedef rte_mempool_obj_cb_t rte_mempool_obj_ctor_t;
typedef void(rte_mempool_mem_cb_t)(struct rte_mempool *mp,
                                   void *opaque,
                                   struct rte_mempool_memhdr *memhdr,
                                   unsigned mem_idx);
typedef void(rte_mempool_ctor_t)(struct rte_mempool *, void *);
struct rte_mempool *rte_mempool_create(const char *name, unsigned n,
                                       unsigned elt_size,
                                       unsigned cache_size,
                                       unsigned private_data_size,
                                       rte_mempool_ctor_t *mp_init,
                                       void *mp_init_arg,
                                       rte_mempool_obj_cb_t *obj_init,
                                       void *obj_init_arg, int socket_id,
                                       unsigned flags);
struct rte_mempool *rte_mempool_create_empty(const char *name, unsigned n,
                                             unsigned elt_size,
                                             unsigned cache_size,
                                             unsigned private_data_size,
                                             int socket_id, unsigned flags);
void rte_mempool_free(struct rte_mempool *mp);
int rte_mempool_populate_iova(struct rte_mempool *mp, char *vaddr,
                              rte_iova_t iova, size_t len,
                              rte_mempool_memchunk_free_cb_t *free_cb,
                              void *opaque);
int rte_mempool_populate_virt(struct rte_mempool *mp, char *addr,
                              size_t len, size_t pg_sz,
                              rte_mempool_memchunk_free_cb_t *free_cb,
                              void *opaque);
int rte_mempool_populate_default(struct rte_mempool *mp);
int rte_mempool_populate_anon(struct rte_mempool *mp);
uint32_t rte_mempool_obj_iter(struct rte_mempool *mp,
                              rte_mempool_obj_cb_t *obj_cb,
                              void *obj_cb_arg);
uint32_t rte_mempool_mem_iter(struct rte_mempool *mp,
                              rte_mempool_mem_cb_t *mem_cb,
                              void *mem_cb_arg);
void rte_mempool_dump(FILE *f, struct rte_mempool *mp);
struct rte_mempool_cache *rte_mempool_cache_create(uint32_t size,
                                                   int socket_id);
void rte_mempool_cache_free(struct rte_mempool_cache *cache);
static inline __attribute__((always_inline)) struct rte_mempool_cache *
rte_mempool_default_cache(struct rte_mempool *mp, unsigned lcore_id)
{
  if (mp->cache_size == 0)
    return ((void *)0);
  if (lcore_id >= 128)
    return ((void *)0);
  rte_mempool_trace_default_cache(mp, lcore_id, &mp->local_cache[lcore_id]);
  return &mp->local_cache[lcore_id];
}

static inline __attribute__((always_inline)) void
rte_mempool_cache_flush(struct rte_mempool_cache *cache,
                        struct rte_mempool *mp)
{
  if (cache == ((void *)0))
    cache = rte_mempool_default_cache(mp, rte_lcore_id());
  if (cache == ((void *)0) || cache->len == 0)
    return;
  rte_mempool_trace_cache_flush(cache, mp);
  rte_mempool_ops_enqueue_bulk(mp, cache->objs, cache->len);
  cache->len = 0;
}

static inline __attribute__((always_inline)) void
rte_mempool_do_generic_put(struct rte_mempool *mp,
                           void *const *obj_table, unsigned int n,
                           struct rte_mempool_cache *cache)
{
  void **cache_objs;
  if (__builtin_expect(!!(cache == ((void *)0)), 0))
    goto driver_enqueue;
  do
  {
  } while (0);
  do
  {
  } while (0);
  if (__builtin_expect(!!(n > cache->flushthresh), 0))
    goto driver_enqueue_stats_incremented;
  if (cache->len + n <= cache->flushthresh)
  {
    cache_objs = &cache->objs[cache->len];
    cache->len += n;
  }
  else
  {
    cache_objs = &cache->objs[0];
    rte_mempool_ops_enqueue_bulk(mp, cache_objs, cache->len);
    cache->len = n;
  }
  memcpy((cache_objs), (obj_table), (sizeof(void *) * n));
  return;
driver_enqueue:
  do
  {
  } while (0);
  do
  {
  } while (0);
driver_enqueue_stats_incremented:
  rte_mempool_ops_enqueue_bulk(mp, obj_table, n);
}

static inline __attribute__((always_inline)) void
rte_mempool_generic_put(struct rte_mempool *mp, void *const *obj_table,
                        unsigned int n, struct rte_mempool_cache *cache)
{
  rte_mempool_trace_generic_put(mp, obj_table, n, cache);
  do
  {
  } while (0);
  rte_mempool_do_generic_put(mp, obj_table, n, cache);
}

static inline __attribute__((always_inline)) void
rte_mempool_put_bulk(struct rte_mempool *mp, void *const *obj_table,
                     unsigned int n)
{
  struct rte_mempool_cache *cache;
  cache = rte_mempool_default_cache(mp, rte_lcore_id());
  rte_mempool_trace_put_bulk(mp, obj_table, n, cache);
  rte_mempool_generic_put(mp, obj_table, n, cache);
}

static inline __attribute__((always_inline)) void
rte_mempool_put(struct rte_mempool *mp, void *obj)
{
  rte_mempool_put_bulk(mp, &obj, 1);
}

static inline __attribute__((always_inline)) int
rte_mempool_do_generic_get(struct rte_mempool *mp, void **obj_table,
                           unsigned int n,
                           struct rte_mempool_cache *cache)
{
  int ret;
  unsigned int remaining;
  uint32_t index, len;
  void **cache_objs;
  if (__builtin_expect(!!(cache == ((void *)0)), 0))
  {
    remaining = n;
    goto driver_dequeue;
  }
  cache_objs = &cache->objs[cache->len];
  if (__extension__(__builtin_constant_p(n)) && n <= cache->len)
  {
    cache->len -= n;
    for (index = 0; index < n; index++)
      *obj_table++ = *--cache_objs;
    do
    {
    } while (0);
    do
    {
    } while (0);
    return 0;
  }
  len = __extension__(__builtin_constant_p(n)) ? cache->len : __extension__({
										__typeof__
										(n)
										_a
										=
										(n);
										__typeof__
										(cache->len)
										_b
										=
										(cache->len);
										_a
										<
										_b
										?
										_a
										:
										_b; });
  cache->len -= len;
  remaining = n - len;
  for (index = 0; index < len; index++)
    *obj_table++ = *--cache_objs;
  if (!__extension__(__builtin_constant_p(n)) && remaining == 0)
  {
    do
    {
    } while (0);
    do
    {
    } while (0);
    return 0;
  }
  if (__builtin_expect(!!(remaining > 512), 0))
    goto driver_dequeue;
  ret = rte_mempool_ops_dequeue_bulk(mp, cache->objs,
                                     cache->size + remaining);
  if (__builtin_expect(!!(ret < 0), 0))
  {
    goto driver_dequeue;
  }
  cache_objs = &cache->objs[cache->size + remaining];
  for (index = 0; index < remaining; index++)
    *obj_table++ = *--cache_objs;
  cache->len = cache->size;
  do
  {
  } while (0);
  do
  {
  } while (0);
  return 0;
driver_dequeue:
  ret = rte_mempool_ops_dequeue_bulk(mp, obj_table, remaining);
  if (ret < 0)
  {
    if (__builtin_expect(!!(cache != ((void *)0)), 1))
    {
      cache->len = n - remaining;
    }
    do
    {
    } while (0);
    do
    {
    } while (0);
  }
  else
  {
    if (__builtin_expect(!!(cache != ((void *)0)), 1))
    {
      do
      {
      } while (0);
      do
      {
      } while (0);
    }
    else
    {
      do
      {
      } while (0);
      do
      {
      } while (0);
    }
  }
  return ret;
}

static inline __attribute__((always_inline)) int
rte_mempool_generic_get(struct rte_mempool *mp, void **obj_table,
                        unsigned int n, struct rte_mempool_cache *cache)
{
  int ret;
  ret = rte_mempool_do_generic_get(mp, obj_table, n, cache);
  if (ret == 0)
    do
    {
    } while (0);
  rte_mempool_trace_generic_get(mp, obj_table, n, cache);
  return ret;
}

static inline __attribute__((always_inline)) int
rte_mempool_get_bulk(struct rte_mempool *mp, void **obj_table,
                     unsigned int n)
{
  struct rte_mempool_cache *cache;
  cache = rte_mempool_default_cache(mp, rte_lcore_id());
  rte_mempool_trace_get_bulk(mp, obj_table, n, cache);
  return rte_mempool_generic_get(mp, obj_table, n, cache);
}

static inline __attribute__((always_inline)) int
rte_mempool_get(struct rte_mempool *mp, void **obj_p)
{
  return rte_mempool_get_bulk(mp, obj_p, 1);
}

static inline __attribute__((always_inline)) int
rte_mempool_get_contig_blocks(struct rte_mempool *mp,
                              void **first_obj_table, unsigned int n)
{
  int ret;
  ret = rte_mempool_ops_dequeue_contig_blocks(mp, first_obj_table, n);
  if (ret == 0)
  {
    do
    {
    } while (0);
    do
    {
    } while (0);
    do
    {
    } while (0);
  }
  else
  {
    do
    {
    } while (0);
    do
    {
    } while (0);
  }
  rte_mempool_trace_get_contig_blocks(mp, first_obj_table, n);
  return ret;
}

unsigned int rte_mempool_avail_count(const struct rte_mempool *mp);
unsigned int rte_mempool_in_use_count(const struct rte_mempool *mp);
static inline int
rte_mempool_full(const struct rte_mempool *mp)
{
  return rte_mempool_avail_count(mp) == mp->size;
}

static inline int
rte_mempool_empty(const struct rte_mempool *mp)
{
  return rte_mempool_avail_count(mp) == 0;
}

static inline rte_iova_t
rte_mempool_virt2iova(const void *elt)
{
  const struct rte_mempool_objhdr *hdr;
  hdr =
      (const struct rte_mempool_objhdr
           *)((void *)((uintptr_t)(elt) - (sizeof(*hdr))));
  return hdr->iova;
}

void rte_mempool_audit(struct rte_mempool *mp);
static inline void *
rte_mempool_get_priv(struct rte_mempool *mp)
{
  return (char *)mp +
         (sizeof(*(mp)) +
          (((mp->cache_size) ==
            0)
               ? 0
               : (sizeof(struct rte_mempool_cache) * 128)));
}

void rte_mempool_list_dump(FILE *f);
struct rte_mempool *rte_mempool_lookup(const char *name);
uint32_t rte_mempool_calc_obj_size(uint32_t elt_size, uint32_t flags,
                                   struct rte_mempool_objsz *sz);
void rte_mempool_walk(void (*func)(struct rte_mempool *, void *arg),
                      void *arg);
struct rte_mempool_mem_range_info
{
  void *start;
  size_t length;
  _Bool is_contiguous;
};
__attribute__((section(".text.experimental"))) int
rte_mempool_get_mem_range(const struct rte_mempool *mp,
                          struct rte_mempool_mem_range_info *mem_range);
__attribute__((section(".text.experimental")))
size_t
rte_mempool_get_obj_alignment(const struct rte_mempool *mp);
int rte_mempool_get_page_size(struct rte_mempool *mp, size_t *pg_sz);
enum rte_mempool_event
{
  RTE_MEMPOOL_EVENT_READY = 0,
  RTE_MEMPOOL_EVENT_DESTROY = 1,
};
typedef void(rte_mempool_event_callback)(enum rte_mempool_event event,
                                         struct rte_mempool *mp,
                                         void *user_data);
__attribute__((section(".text.internal"))) int
rte_mempool_event_callback_register(rte_mempool_event_callback *func,
                                    void *user_data);
__attribute__((section(".text.internal"))) int
rte_mempool_event_callback_unregister(rte_mempool_event_callback *func,
                                      void *user_data);
static inline void
rte_prefetch0(const volatile void *p);
static inline void
rte_prefetch1(const volatile void *p);
static inline void
rte_prefetch2(const volatile void *p);
static inline void
rte_prefetch_non_temporal(const volatile void *p);
__attribute__((section(".text.experimental"))) static inline void
rte_prefetch0_write(const void *p)
{
  __builtin_prefetch(p, 1, 3);
}

__attribute__((section(".text.experimental"))) static inline void
rte_prefetch1_write(const void *p)
{
  __builtin_prefetch(p, 1, 2);
}

__attribute__((section(".text.experimental"))) static inline void
rte_prefetch2_write(const void *p)
{
  __builtin_prefetch(p, 1, 1);
}

__attribute__((section(".text.experimental"))) static inline void
rte_cldemote(const volatile void *p);
static inline void
rte_prefetch0(const volatile void *p)
{
  (void)(p);
}

static inline void
rte_prefetch1(const volatile void *p)
{
  (void)(p);
}

static inline void
rte_prefetch2(const volatile void *p)
{
  (void)(p);
}

static inline void
rte_prefetch_non_temporal(const volatile void *p)
{
  rte_prefetch0(p);
}

__attribute__((section(".text.experimental"))) static inline void rte_cldemote(const volatile void *p)
{
  (void)(p);
}

const char *rte_get_ptype_l2_name(uint32_t ptype);
const char *rte_get_ptype_l3_name(uint32_t ptype);
const char *rte_get_ptype_l4_name(uint32_t ptype);
const char *rte_get_ptype_tunnel_name(uint32_t ptype);
const char *rte_get_ptype_inner_l2_name(uint32_t ptype);
const char *rte_get_ptype_inner_l3_name(uint32_t ptype);
const char *rte_get_ptype_inner_l4_name(uint32_t ptype);
int rte_get_ptype_name(uint32_t ptype, char *buf, size_t buflen);
typedef uint16_t rte_be16_t;
typedef uint32_t rte_be32_t;
typedef uint64_t rte_be64_t;
typedef uint16_t rte_le16_t;
typedef uint32_t rte_le32_t;
typedef uint64_t rte_le64_t;
static inline uint16_t
rte_constant_bswap16(uint16_t x)
{
  return (uint16_t)((((uint16_t)(x) & 0x00ff) << 8) |
                    (((uint16_t)(x) & 0xff00) >> 8));
}

static inline uint32_t
rte_constant_bswap32(uint32_t x)
{
  return (uint32_t)((((uint32_t)(x) & 0x000000ffU) << 24) |
                    (((uint32_t)(x) & 0x0000ff00U) << 8) |
                    (((uint32_t)(x) & 0x00ff0000U) >> 8) |
                    (((uint32_t)(x) & 0xff000000U) >> 24));
}

static inline uint64_t
rte_constant_bswap64(uint64_t x)
{
  return (uint64_t)((((uint64_t)(x) & 0x00000000000000ffUL) << 56) |
                    (((uint64_t)(x) & 0x000000000000ff00UL) << 40) |
                    (((uint64_t)(x) & 0x0000000000ff0000UL) << 24) |
                    (((uint64_t)(x) & 0x00000000ff000000UL) << 8) |
                    (((uint64_t)(x) & 0x000000ff00000000UL) >> 8) |
                    (((uint64_t)(x) & 0x0000ff0000000000UL) >> 24) |
                    (((uint64_t)(x) & 0x00ff000000000000UL) >> 40) |
                    (((uint64_t)(x) & 0xff00000000000000UL) >> 56));
}

struct rte_mbuf_sched
{
  uint32_t queue_id;
  uint8_t traffic_class;
  uint8_t color;
  uint16_t reserved;
};
enum
{
  RTE_MBUF_L2_LEN_BITS = 7,
  RTE_MBUF_L3_LEN_BITS = 9,
  RTE_MBUF_L4_LEN_BITS = 8,
  RTE_MBUF_TSO_SEGSZ_BITS = 16,
  RTE_MBUF_OUTL3_LEN_BITS = 9,
  RTE_MBUF_OUTL2_LEN_BITS = 7,
  RTE_MBUF_TXOFLD_UNUSED_BITS = sizeof(uint64_t) * 8 -
                                RTE_MBUF_L2_LEN_BITS -
                                RTE_MBUF_L3_LEN_BITS -
                                RTE_MBUF_L4_LEN_BITS -
                                RTE_MBUF_TSO_SEGSZ_BITS -
                                RTE_MBUF_OUTL3_LEN_BITS - RTE_MBUF_OUTL2_LEN_BITS,
  RTE_MBUF_L2_LEN_OFS = 0,
  RTE_MBUF_L3_LEN_OFS = RTE_MBUF_L2_LEN_OFS + RTE_MBUF_L2_LEN_BITS,
  RTE_MBUF_L4_LEN_OFS = RTE_MBUF_L3_LEN_OFS + RTE_MBUF_L3_LEN_BITS,
  RTE_MBUF_TSO_SEGSZ_OFS = RTE_MBUF_L4_LEN_OFS + RTE_MBUF_L4_LEN_BITS,
  RTE_MBUF_OUTL3_LEN_OFS = RTE_MBUF_TSO_SEGSZ_OFS + RTE_MBUF_TSO_SEGSZ_BITS,
  RTE_MBUF_OUTL2_LEN_OFS = RTE_MBUF_OUTL3_LEN_OFS + RTE_MBUF_OUTL3_LEN_BITS,
  RTE_MBUF_TXOFLD_UNUSED_OFS =
      RTE_MBUF_OUTL2_LEN_OFS + RTE_MBUF_OUTL2_LEN_BITS,
};
struct __attribute__((__aligned__(64))) rte_mbuf
{
  void *buf_addr;
  _Alignas(sizeof(rte_iova_t)) rte_iova_t buf_iova;
  union
  {
    uint64_t rearm_data[1];
    __extension__ struct
    {
      uint16_t data_off;
      uint16_t refcnt;
      uint16_t nb_segs;
      uint16_t port;
    };
  };
  uint64_t ol_flags;
  union
  {
    void *rx_descriptor_fields1[24 / sizeof(void *)];
    __extension__ struct
    {
      union
      {
        uint32_t packet_type;
        __extension__ struct
        {
          uint8_t l2_type : 4;
          uint8_t l3_type : 4;
          uint8_t l4_type : 4;
          uint8_t tun_type : 4;
          union
          {
            uint8_t inner_esp_next_proto;
            __extension__ struct
            {
              uint8_t inner_l2_type : 4;
              uint8_t inner_l3_type : 4;
            };
          };
          uint8_t inner_l4_type : 4;
        };
      };
      uint32_t pkt_len;
      uint16_t data_len;
      uint16_t vlan_tci;
      union
      {
        union
        {
          uint32_t rss;
          struct
          {
            union
            {
              struct
              {
                uint16_t hash;
                uint16_t id;
              };
              uint32_t lo;
            };
            uint32_t hi;
          } fdir;
          struct rte_mbuf_sched sched;
          struct
          {
            uint32_t reserved1;
            uint16_t reserved2;
            uint16_t txq;
          } txadapter;
          uint32_t usr;
        } hash;
      };
      uint16_t vlan_tci_outer;
      uint16_t buf_len;
    };
  };
  struct rte_mempool *pool;
  _Alignas(64) struct rte_mbuf *next;
  union
  {
    uint64_t tx_offload;
    __extension__ struct
    {
      uint64_t l2_len : RTE_MBUF_L2_LEN_BITS;
      uint64_t l3_len : RTE_MBUF_L3_LEN_BITS;
      uint64_t l4_len : RTE_MBUF_L4_LEN_BITS;
      uint64_t tso_segsz : RTE_MBUF_TSO_SEGSZ_BITS;
      uint64_t outer_l3_len : RTE_MBUF_OUTL3_LEN_BITS;
      uint64_t outer_l2_len : RTE_MBUF_OUTL2_LEN_BITS;
    };
  };
  struct rte_mbuf_ext_shared_info *shinfo;
  uint16_t priv_size;
  uint16_t timesync;
  uint32_t dynfield1[9];
};

typedef void (*rte_mbuf_extbuf_free_callback_t)(void *addr, void *opaque);
struct rte_mbuf_ext_shared_info
{
  rte_mbuf_extbuf_free_callback_t free_cb;
  void *fcb_opaque;
  uint16_t refcnt;
};
const char *rte_get_rx_ol_flag_name(uint64_t mask);
int rte_get_rx_ol_flag_list(uint64_t mask, char *buf, size_t buflen);
const char *rte_get_tx_ol_flag_name(uint64_t mask);
int rte_get_tx_ol_flag_list(uint64_t mask, char *buf, size_t buflen);
static inline void
rte_mbuf_prefetch_part1(struct rte_mbuf *m)
{
  rte_prefetch0(m);
}

static inline void
rte_mbuf_prefetch_part2(struct rte_mbuf *m)
{
  rte_prefetch0(((void *)((uintptr_t)(m) + (64))));
}

static inline uint16_t rte_pktmbuf_priv_size(struct rte_mempool *mp);
static inline rte_iova_t
rte_mbuf_iova_get(const struct rte_mbuf *m)
{
  return m->buf_iova;
}

static inline void
rte_mbuf_iova_set(struct rte_mbuf *m, rte_iova_t iova)
{
  m->buf_iova = iova;
}

static inline rte_iova_t
rte_mbuf_data_iova(const struct rte_mbuf *mb)
{
  return rte_mbuf_iova_get(mb) + mb->data_off;
}

static inline rte_iova_t
rte_mbuf_data_iova_default(const struct rte_mbuf *mb)
{
  return rte_mbuf_iova_get(mb) + 128;
}

static inline struct rte_mbuf *
rte_mbuf_from_indirect(struct rte_mbuf *mi)
{
  return (struct rte_mbuf
              *)((void *)((uintptr_t)(mi->buf_addr) -
                          (sizeof(*mi) + mi->priv_size)));
}

static inline char *
rte_mbuf_buf_addr(struct rte_mbuf *mb, struct rte_mempool *mp)
{
  return (char *)mb + sizeof(*mb) + rte_pktmbuf_priv_size(mp);
}

static inline char *
rte_mbuf_data_addr_default(struct rte_mbuf *mb)
{
  return rte_mbuf_buf_addr(mb, mb->pool) + 128;
}

static inline char *
rte_mbuf_to_baddr(struct rte_mbuf *md)
{
  return rte_mbuf_buf_addr(md, md->pool);
}

static inline void *
rte_mbuf_to_priv(struct rte_mbuf *m)
{
  return ((void *)((uintptr_t)(m) + (sizeof(struct rte_mbuf))));
}

struct rte_pktmbuf_pool_private
{
  uint16_t mbuf_data_room_size;
  uint16_t mbuf_priv_size;
  uint32_t flags;
};
static inline uint32_t
rte_pktmbuf_priv_flags(struct rte_mempool *mp)
{
  struct rte_pktmbuf_pool_private *mbp_priv;
  mbp_priv = (struct rte_pktmbuf_pool_private *)rte_mempool_get_priv(mp);
  return mbp_priv->flags;
}

static inline uint16_t
rte_mbuf_refcnt_read(const struct rte_mbuf *m)
{
  return __atomic_load_n(&m->refcnt, 0);
}

static inline void
rte_mbuf_refcnt_set(struct rte_mbuf *m, uint16_t new_value)
{
  __atomic_store_n(&m->refcnt, new_value, 0);
}

static inline uint16_t
__rte_mbuf_refcnt_update(struct rte_mbuf *m, int16_t value)
{
  return __atomic_fetch_add(&m->refcnt, value, 4) + value;
}

static inline uint16_t
rte_mbuf_refcnt_update(struct rte_mbuf *m, int16_t value)
{
  if (__builtin_expect(!!(rte_mbuf_refcnt_read(m) == 1), 1))
  {
    ++value;
    rte_mbuf_refcnt_set(m, (uint16_t)value);
    return (uint16_t)value;
  }
  return __rte_mbuf_refcnt_update(m, value);
}

static inline uint16_t
rte_mbuf_ext_refcnt_read(const struct rte_mbuf_ext_shared_info *shinfo)
{
  return __atomic_load_n(&shinfo->refcnt, 0);
}

static inline void
rte_mbuf_ext_refcnt_set(struct rte_mbuf_ext_shared_info *shinfo,
                        uint16_t new_value)
{
  __atomic_store_n(&shinfo->refcnt, new_value, 0);
}

static inline uint16_t
rte_mbuf_ext_refcnt_update(struct rte_mbuf_ext_shared_info *shinfo,
                           int16_t value)
{
  if (__builtin_expect(!!(rte_mbuf_ext_refcnt_read(shinfo) == 1), 1))
  {
    ++value;
    rte_mbuf_ext_refcnt_set(shinfo, (uint16_t)value);
    return (uint16_t)value;
  }
  return __atomic_fetch_add(&shinfo->refcnt, value, 4) + value;
}

void rte_mbuf_sanity_check(const struct rte_mbuf *m, int is_header);
int rte_mbuf_check(const struct rte_mbuf *m, int is_header,
                   const char **reason);
static inline __attribute__((always_inline)) void
__rte_mbuf_raw_sanity_check(__attribute__((__unused__))
                            const struct rte_mbuf *m)
{
  do
  {
  } while (0);
  do
  {
  } while (0);
  do
  {
  } while (0);
  do
  {
  } while (0);
}

static inline struct rte_mbuf *
rte_mbuf_raw_alloc(struct rte_mempool *mp)
{
  struct rte_mbuf *m;
  if (rte_mempool_get(mp, (void **)&m) < 0)
    return ((void *)0);
  __rte_mbuf_raw_sanity_check(m);
  return m;
}

static inline __attribute__((always_inline)) void rte_mbuf_raw_free(struct rte_mbuf *m)
{
  do
  {
  } while (0);
  __rte_mbuf_raw_sanity_check(m);
  rte_mempool_put(m->pool, m);
}

void rte_pktmbuf_init(struct rte_mempool *mp, void *opaque_arg,
                      void *m, unsigned i);
void rte_pktmbuf_pool_init(struct rte_mempool *mp, void *opaque_arg);
struct rte_mempool *rte_pktmbuf_pool_create(const char *name, unsigned n,
                                            unsigned cache_size,
                                            uint16_t priv_size,
                                            uint16_t data_room_size,
                                            int socket_id);
struct rte_mempool *rte_pktmbuf_pool_create_by_ops(const char *name,
                                                   unsigned int n,
                                                   unsigned int cache_size,
                                                   uint16_t priv_size,
                                                   uint16_t data_room_size,
                                                   int socket_id,
                                                   const char *ops_name);
struct rte_pktmbuf_extmem
{
  void *buf_ptr;
  rte_iova_t buf_iova;
  size_t buf_len;
  uint16_t elt_size;
};
struct rte_mempool *rte_pktmbuf_pool_create_extbuf(const char *name,
                                                   unsigned int n,
                                                   unsigned int cache_size,
                                                   uint16_t priv_size,
                                                   uint16_t data_room_size,
                                                   int socket_id,
                                                   const struct
                                                   rte_pktmbuf_extmem
                                                       *ext_mem,
                                                   unsigned int ext_num);
static inline uint16_t
rte_pktmbuf_data_room_size(struct rte_mempool *mp)
{
  struct rte_pktmbuf_pool_private *mbp_priv;
  mbp_priv = (struct rte_pktmbuf_pool_private *)rte_mempool_get_priv(mp);
  return mbp_priv->mbuf_data_room_size;
}

static inline uint16_t
rte_pktmbuf_priv_size(struct rte_mempool *mp)
{
  struct rte_pktmbuf_pool_private *mbp_priv;
  mbp_priv = (struct rte_pktmbuf_pool_private *)rte_mempool_get_priv(mp);
  return mbp_priv->mbuf_priv_size;
}

static inline void
rte_pktmbuf_reset_headroom(struct rte_mbuf *m)
{
  m->data_off = (uint16_t) __extension__(
      {
					   __typeof__ ((uint16_t) 128) _a =
					   ((uint16_t) 128);
					   __typeof__ ((uint16_t) m->buf_len)
					   _b = ((uint16_t) m->buf_len);
					   _a < _b ? _a : _b; });
}

static inline void
rte_pktmbuf_reset(struct rte_mbuf *m)
{
  m->next = ((void *)0);
  m->pkt_len = 0;
  m->tx_offload = 0;
  m->vlan_tci = 0;
  m->vlan_tci_outer = 0;
  m->nb_segs = 1;
  m->port = (65535);
  m->ol_flags &= (1ULL << 61);
  m->packet_type = 0;
  rte_pktmbuf_reset_headroom(m);
  m->data_len = 0;
  do
  {
  } while (0);
}

static inline struct rte_mbuf *
rte_pktmbuf_alloc(struct rte_mempool *mp)
{
  struct rte_mbuf *m;
  if ((m = rte_mbuf_raw_alloc(mp)) != ((void *)0))
    rte_pktmbuf_reset(m);
  return m;
}

static inline int
rte_pktmbuf_alloc_bulk(struct rte_mempool *pool,
                       struct rte_mbuf **mbufs, unsigned count)
{
  unsigned idx = 0;
  int rc;
  rc = rte_mempool_get_bulk(pool, (void **)mbufs, count);
  if (__builtin_expect(!!(rc), 0))
    return rc;
  switch (count % 4)
  {
  case 0:
    while (idx != count)
    {
      __rte_mbuf_raw_sanity_check(mbufs[idx]);
      rte_pktmbuf_reset(mbufs[idx]);
      idx++;
    case 3:
      __rte_mbuf_raw_sanity_check(mbufs[idx]);
      rte_pktmbuf_reset(mbufs[idx]);
      idx++;
    case 2:
      __rte_mbuf_raw_sanity_check(mbufs[idx]);
      rte_pktmbuf_reset(mbufs[idx]);
      idx++;
    case 1:
      __rte_mbuf_raw_sanity_check(mbufs[idx]);
      rte_pktmbuf_reset(mbufs[idx]);
      idx++;
    }
  }
  return 0;
}

static inline struct rte_mbuf_ext_shared_info *
rte_pktmbuf_ext_shinfo_init_helper(void *buf_addr, uint16_t *buf_len,
                                   rte_mbuf_extbuf_free_callback_t free_cb,
                                   void *fcb_opaque)
{
  struct rte_mbuf_ext_shared_info *shinfo;
  void *buf_end = ((void *)((uintptr_t)(buf_addr) + (*buf_len)));
  void *addr;
  addr =
      ((__typeof__(((void *)((uintptr_t)(buf_end) - (sizeof(*shinfo))))))(__typeof__((uintptr_t)(((void *)((uintptr_t)(buf_end) - (sizeof(*shinfo)))))))(((uintptr_t)(((void *)((uintptr_t)(buf_end) - (sizeof(*shinfo)))))) &
                                                                                                                                                         (~((__typeof__((uintptr_t)(((void *)((uintptr_t)(buf_end) -
                                                                                                                                                                                              (sizeof(*shinfo)))))))((sizeof(uintptr_t)) - 1)))));
  if (addr <= buf_addr)
    return ((void *)0);
  shinfo = (struct rte_mbuf_ext_shared_info *)addr;
  shinfo->free_cb = free_cb;
  shinfo->fcb_opaque = fcb_opaque;
  rte_mbuf_ext_refcnt_set(shinfo, 1);
  *buf_len = (uint16_t)((uintptr_t)(shinfo) - (uintptr_t)(buf_addr));
  return shinfo;
}

static inline void
rte_pktmbuf_attach_extbuf(struct rte_mbuf *m, void *buf_addr,
                          rte_iova_t buf_iova, uint16_t buf_len,
                          struct rte_mbuf_ext_shared_info *shinfo)
{
  do
  {
  } while (0);
  do
  {
  } while (0);
  m->buf_addr = buf_addr;
  rte_mbuf_iova_set(m, buf_iova);
  m->buf_len = buf_len;
  m->data_len = 0;
  m->data_off = 0;
  m->ol_flags |= (1ULL << 61);
  m->shinfo = shinfo;
}

static inline void
rte_mbuf_dynfield_copy(struct rte_mbuf *mdst, const struct rte_mbuf *msrc)
{
  memcpy(&mdst->dynfield1, msrc->dynfield1, sizeof(mdst->dynfield1));
}

static inline void
__rte_pktmbuf_copy_hdr(struct rte_mbuf *mdst, const struct rte_mbuf *msrc)
{
  mdst->port = msrc->port;
  mdst->vlan_tci = msrc->vlan_tci;
  mdst->vlan_tci_outer = msrc->vlan_tci_outer;
  mdst->tx_offload = msrc->tx_offload;
  mdst->hash = msrc->hash;
  mdst->packet_type = msrc->packet_type;
  rte_mbuf_dynfield_copy(mdst, msrc);
}

static inline void
rte_pktmbuf_attach(struct rte_mbuf *mi, struct rte_mbuf *m)
{
  do
  {
  } while (0);
  if (((m)->ol_flags & (1ULL << 61)))
  {
    rte_mbuf_ext_refcnt_update(m->shinfo, 1);
    mi->ol_flags = m->ol_flags;
    mi->shinfo = m->shinfo;
  }
  else
  {
    rte_mbuf_refcnt_update(rte_mbuf_from_indirect(m), 1);
    mi->priv_size = m->priv_size;
    mi->ol_flags = m->ol_flags | (1ULL << 62);
  }
  __rte_pktmbuf_copy_hdr(mi, m);
  mi->data_off = m->data_off;
  mi->data_len = m->data_len;
  rte_mbuf_iova_set(mi, rte_mbuf_iova_get(m));
  mi->buf_addr = m->buf_addr;
  mi->buf_len = m->buf_len;
  mi->next = ((void *)0);
  mi->pkt_len = mi->data_len;
  mi->nb_segs = 1;
  do
  {
  } while (0);
  do
  {
  } while (0);
}

static inline void
__rte_pktmbuf_free_extbuf(struct rte_mbuf *m)
{
  do
  {
  } while (0);
  do
  {
  } while (0);
  if (rte_mbuf_ext_refcnt_update(m->shinfo, -1) == 0)
    m->shinfo->free_cb(m->buf_addr, m->shinfo->fcb_opaque);
}

static inline void
__rte_pktmbuf_free_direct(struct rte_mbuf *m)
{
  struct rte_mbuf *md;
  do
  {
  } while (0);
  md = rte_mbuf_from_indirect(m);
  if (rte_mbuf_refcnt_update(md, -1) == 0)
  {
    md->next = ((void *)0);
    md->nb_segs = 1;
    rte_mbuf_refcnt_set(md, 1);
    rte_mbuf_raw_free(md);
  }
}

static inline void
rte_pktmbuf_detach(struct rte_mbuf *m)
{
  struct rte_mempool *mp = m->pool;
  uint32_t mbuf_size, buf_len;
  uint16_t priv_size;
  if (((m)->ol_flags & (1ULL << 61)))
  {
    uint32_t flags = rte_pktmbuf_priv_flags(mp);
    if (flags & (1 << 0))
    {
      return;
    }
    __rte_pktmbuf_free_extbuf(m);
  }
  else
  {
    __rte_pktmbuf_free_direct(m);
  }
  priv_size = rte_pktmbuf_priv_size(mp);
  mbuf_size = (uint32_t)(sizeof(struct rte_mbuf) + priv_size);
  buf_len = rte_pktmbuf_data_room_size(mp);
  m->priv_size = priv_size;
  m->buf_addr = (char *)m + mbuf_size;
  rte_mbuf_iova_set(m, rte_mempool_virt2iova(m) + mbuf_size);
  m->buf_len = (uint16_t)buf_len;
  rte_pktmbuf_reset_headroom(m);
  m->data_len = 0;
  m->ol_flags = 0;
}

static inline int
__rte_pktmbuf_pinned_extbuf_decref(struct rte_mbuf *m)
{
  struct rte_mbuf_ext_shared_info *shinfo;
  m->ol_flags = (1ULL << 61);
  shinfo = m->shinfo;
  if (__builtin_expect(!!(rte_mbuf_ext_refcnt_read(shinfo) == 1), 1))
    return 0;
  if (__builtin_expect(!!(__atomic_fetch_add(&shinfo->refcnt, -1, 4) - 1), 1))
    return 1;
  rte_mbuf_ext_refcnt_set(shinfo, 1);
  return 0;
}

static inline __attribute__((always_inline)) struct rte_mbuf *rte_pktmbuf_prefree_seg(struct rte_mbuf *m)
{
  do
  {
  } while (0);
  if (__builtin_expect(!!(rte_mbuf_refcnt_read(m) == 1), 1))
  {
    if (!(!((m)->ol_flags & ((1ULL << 62) | (1ULL << 61)))))
    {
      rte_pktmbuf_detach(m);
      if (((m)->ol_flags & (1ULL << 61)) &&
          (rte_pktmbuf_priv_flags(m->pool) & (1 << 0)) &&
          __rte_pktmbuf_pinned_extbuf_decref(m))
        return ((void *)0);
    }
    if (m->next != ((void *)0))
      m->next = ((void *)0);
    if (m->nb_segs != 1)
      m->nb_segs = 1;
    return m;
  }
  else if (__rte_mbuf_refcnt_update(m, -1) == 0)
  {
    if (!(!((m)->ol_flags & ((1ULL << 62) | (1ULL << 61)))))
    {
      rte_pktmbuf_detach(m);
      if (((m)->ol_flags & (1ULL << 61)) &&
          (rte_pktmbuf_priv_flags(m->pool) & (1 << 0)) &&
          __rte_pktmbuf_pinned_extbuf_decref(m))
        return ((void *)0);
    }
    if (m->next != ((void *)0))
      m->next = ((void *)0);
    if (m->nb_segs != 1)
      m->nb_segs = 1;
    rte_mbuf_refcnt_set(m, 1);
    return m;
  }
  return ((void *)0);
}

static inline __attribute__((always_inline)) void rte_pktmbuf_free_seg(struct rte_mbuf *m)
{
  m = rte_pktmbuf_prefree_seg(m);
  if (__builtin_expect(!!(m != ((void *)0)), 1))
    rte_mbuf_raw_free(m);
}

static inline void
rte_pktmbuf_free(struct rte_mbuf *m)
{
  struct rte_mbuf *m_next;
  if (m != ((void *)0))
    do
    {
    } while (0);
  while (m != ((void *)0))
  {
    m_next = m->next;
    rte_pktmbuf_free_seg(m);
    m = m_next;
  }
}

void rte_pktmbuf_free_bulk(struct rte_mbuf **mbufs, unsigned int count);
struct rte_mbuf *rte_pktmbuf_clone(struct rte_mbuf *md,
                                   struct rte_mempool *mp);
struct rte_mbuf *rte_pktmbuf_copy(const struct rte_mbuf *m,
                                  struct rte_mempool *mp, uint32_t offset,
                                  uint32_t length);
static inline void
rte_pktmbuf_refcnt_update(struct rte_mbuf *m, int16_t v)
{
  do
  {
  } while (0);
  do
  {
    rte_mbuf_refcnt_update(m, v);
  } while ((m = m->next) != ((void *)0));
}

static inline uint16_t
rte_pktmbuf_headroom(const struct rte_mbuf *m)
{
  do
  {
  } while (0);
  return m->data_off;
}

static inline uint16_t
rte_pktmbuf_tailroom(const struct rte_mbuf *m)
{
  do
  {
  } while (0);
  return (uint16_t)(m->buf_len - rte_pktmbuf_headroom(m) - m->data_len);
}

static inline struct rte_mbuf *
rte_pktmbuf_lastseg(struct rte_mbuf *m)
{
  do
  {
  } while (0);
  while (m->next != ((void *)0))
    m = m->next;
  return m;
}

static inline char *
rte_pktmbuf_prepend(struct rte_mbuf *m, uint16_t len)
{
  do
  {
  } while (0);
  if (__builtin_expect(!!(len > rte_pktmbuf_headroom(m)), 0))
    return ((void *)0);
  m->data_off = (uint16_t)(m->data_off - len);
  m->data_len = (uint16_t)(m->data_len + len);
  m->pkt_len = (m->pkt_len + len);
  return (char *)m->buf_addr + m->data_off;
}

static inline char *
rte_pktmbuf_append(struct rte_mbuf *m, uint16_t len)
{
  void *tail;
  struct rte_mbuf *m_last;
  do
  {
  } while (0);
  m_last = rte_pktmbuf_lastseg(m);
  if (__builtin_expect(!!(len > rte_pktmbuf_tailroom(m_last)), 0))
    return ((void *)0);
  tail = (char *)m_last->buf_addr + m_last->data_off + m_last->data_len;
  m_last->data_len = (uint16_t)(m_last->data_len + len);
  m->pkt_len = (m->pkt_len + len);
  return (char *)tail;
}

static inline char *
rte_pktmbuf_adj(struct rte_mbuf *m, uint16_t len)
{
  do
  {
  } while (0);
  if (__builtin_expect(!!(len > m->data_len), 0))
    return ((void *)0);
  m->data_len = (uint16_t)(m->data_len - len);
  m->data_off = (uint16_t)(m->data_off + len);
  m->pkt_len = (m->pkt_len - len);
  return (char *)m->buf_addr + m->data_off;
}

static inline int
rte_pktmbuf_trim(struct rte_mbuf *m, uint16_t len)
{
  struct rte_mbuf *m_last;
  do
  {
  } while (0);
  m_last = rte_pktmbuf_lastseg(m);
  if (__builtin_expect(!!(len > m_last->data_len), 0))
    return -1;
  m_last->data_len = (uint16_t)(m_last->data_len - len);
  m->pkt_len = (m->pkt_len - len);
  return 0;
}

static inline int
rte_pktmbuf_is_contiguous(const struct rte_mbuf *m)
{
  do
  {
  } while (0);
  return m->nb_segs == 1;
}

const void *__rte_pktmbuf_read(const struct rte_mbuf *m, uint32_t off,
                               uint32_t len, void *buf);
static inline const void *
rte_pktmbuf_read(const struct rte_mbuf *m,
                 uint32_t off, uint32_t len, void *buf)
{
  if (__builtin_expect(!!(off + len <= ((m)->data_len)), 1))
    return ((char *)(void *)((char *)(m)->buf_addr + (m)->data_off +
                             (off)));
  else
    return __rte_pktmbuf_read(m, off, len, buf);
}

static inline int
rte_pktmbuf_chain(struct rte_mbuf *head, struct rte_mbuf *tail)
{
  struct rte_mbuf *cur_tail;
  if (head->nb_segs + tail->nb_segs > (65535))
    return -75;
  cur_tail = rte_pktmbuf_lastseg(head);
  cur_tail->next = tail;
  head->nb_segs = (uint16_t)(head->nb_segs + tail->nb_segs);
  head->pkt_len += tail->pkt_len;
  tail->pkt_len = tail->data_len;
  return 0;
}

static inline __attribute__((always_inline)) uint64_t
rte_mbuf_tx_offload(uint64_t il2, uint64_t il3, uint64_t il4, uint64_t tso,
                    uint64_t ol3, uint64_t ol2, uint64_t unused)
{
  return il2 << RTE_MBUF_L2_LEN_OFS |
         il3 << RTE_MBUF_L3_LEN_OFS |
         il4 << RTE_MBUF_L4_LEN_OFS |
         tso << RTE_MBUF_TSO_SEGSZ_OFS |
         ol3 << RTE_MBUF_OUTL3_LEN_OFS |
         ol2 << RTE_MBUF_OUTL2_LEN_OFS | unused << RTE_MBUF_TXOFLD_UNUSED_OFS;
}

static inline int
rte_validate_tx_offload(const struct rte_mbuf *m)
{
  uint64_t ol_flags = m->ol_flags;
  if (!(ol_flags &
        ((1ULL << 60) | (1ULL << 59) | (1ULL << 58) | (1ULL << 57) |
         (1ULL << 56) | (1ULL << 55) | (1ULL << 54) | (3ULL << 52) | (1ULL << 51) |
         (1ULL << 50) | (1ULL << 49) | (0xFULL << 45) | (1ULL << 44) | (1ULL << 43) |
         (1ULL << 42) | (1ULL << 41))))
    return 0;
  if ((ol_flags & (1ULL << 54)) && (ol_flags & (1ULL << 56)))
    return -22;
  if (ol_flags & ((3ULL << 52) | (1ULL << 50)))
    if (!(ol_flags & ((1ULL << 55) | (1ULL << 56))))
      return -22;
  if (ol_flags & (1ULL << 50))
    if ((m->tso_segsz == 0) ||
        ((ol_flags & (1ULL << 55)) && !(ol_flags & (1ULL << 54))))
      return -22;
  if ((ol_flags & (1ULL << 58)) && !(ol_flags & (1ULL << 59)))
    return -22;
  return 0;
}

int __rte_pktmbuf_linearize(struct rte_mbuf *mbuf);
static inline int
rte_pktmbuf_linearize(struct rte_mbuf *mbuf)
{
  if (rte_pktmbuf_is_contiguous(mbuf))
    return 0;
  return __rte_pktmbuf_linearize(mbuf);
}

void rte_pktmbuf_dump(FILE *f, const struct rte_mbuf *m, unsigned dump_len);
static inline uint32_t
rte_mbuf_sched_queue_get(const struct rte_mbuf *m)
{
  return m->hash.sched.queue_id;
}

static inline uint8_t
rte_mbuf_sched_traffic_class_get(const struct rte_mbuf *m)
{
  return m->hash.sched.traffic_class;
}

static inline uint8_t
rte_mbuf_sched_color_get(const struct rte_mbuf *m)
{
  return m->hash.sched.color;
}

static inline void
rte_mbuf_sched_get(const struct rte_mbuf *m, uint32_t *queue_id,
                   uint8_t *traffic_class, uint8_t *color)
{
  struct rte_mbuf_sched sched = m->hash.sched;
  *queue_id = sched.queue_id;
  *traffic_class = sched.traffic_class;
  *color = sched.color;
}

static inline void
rte_mbuf_sched_queue_set(struct rte_mbuf *m, uint32_t queue_id)
{
  m->hash.sched.queue_id = queue_id;
}

static inline void
rte_mbuf_sched_traffic_class_set(struct rte_mbuf *m, uint8_t traffic_class)
{
  m->hash.sched.traffic_class = traffic_class;
}

static inline void
rte_mbuf_sched_color_set(struct rte_mbuf *m, uint8_t color)
{
  m->hash.sched.color = color;
}

static inline void
rte_mbuf_sched_set(struct rte_mbuf *m, uint32_t queue_id,
                   uint8_t traffic_class, uint8_t color)
{
  m->hash.sched = (struct rte_mbuf_sched){
      .queue_id = queue_id,
      .traffic_class = traffic_class,
      .color = color,
      .reserved = 0,
  };
}

struct rte_malloc_socket_stats
{
  size_t heap_totalsz_bytes;
  size_t heap_freesz_bytes;
  size_t greatest_free_size;
  unsigned free_count;
  unsigned alloc_count;
  size_t heap_allocsz_bytes;
};
void *rte_malloc(const char *type, size_t size, unsigned align)
    __attribute__((alloc_size(2)));
void *rte_zmalloc(const char *type, size_t size, unsigned align)
    __attribute__((alloc_size(2)));
void *rte_calloc(const char *type, size_t num, size_t size, unsigned align)
    __attribute__((alloc_size(2, 3)));
void *rte_realloc(void *ptr, size_t size, unsigned int align)
    __attribute__((alloc_size(2)));
void *rte_realloc_socket(void *ptr, size_t size, unsigned int align,
                         int socket) __attribute__((alloc_size(2)));
void *rte_malloc_socket(const char *type, size_t size, unsigned align,
                        int socket) __attribute__((alloc_size(2)));
void *rte_zmalloc_socket(const char *type, size_t size, unsigned align,
                         int socket) __attribute__((alloc_size(2)));
void *rte_calloc_socket(const char *type, size_t num, size_t size,
                        unsigned align, int socket)
    __attribute__((alloc_size(2, 3)));
void rte_free(void *ptr);
int rte_malloc_validate(const void *ptr, size_t *size);
int rte_malloc_get_socket_stats(int socket,
                                struct rte_malloc_socket_stats *socket_stats);
int rte_malloc_heap_memory_add(const char *heap_name, void *va_addr, size_t len,
                               rte_iova_t iova_addrs[], unsigned int n_pages,
                               size_t page_sz);
int rte_malloc_heap_memory_remove(const char *heap_name, void *va_addr,
                                  size_t len);
int rte_malloc_heap_memory_attach(const char *heap_name, void *va_addr,
                                  size_t len);
int rte_malloc_heap_memory_detach(const char *heap_name, void *va_addr,
                                  size_t len);
int rte_malloc_heap_create(const char *heap_name);
int rte_malloc_heap_destroy(const char *heap_name);
int rte_malloc_heap_get_socket(const char *name);
int rte_malloc_heap_socket_is_external(int socket_id);
void rte_malloc_dump_stats(FILE *f, const char *type);
void rte_malloc_dump_heaps(FILE *f);
rte_iova_t rte_malloc_virt2iova(const void *addr);
void rte_srand(uint64_t seedval);
uint64_t rte_rand(void);
uint64_t rte_rand_max(uint64_t upper_bound);
double rte_drand(void);
struct __attribute__((__aligned__(2))) rte_ether_addr
{
  uint8_t addr_bytes[6];
};

static inline int
rte_is_same_ether_addr(const struct rte_ether_addr *ea1,
                       const struct rte_ether_addr *ea2)
{
  const uint16_t *w1 = (const uint16_t *)ea1;
  const uint16_t *w2 = (const uint16_t *)ea2;
  return ((w1[0] ^ w2[0]) | (w1[1] ^ w2[1]) | (w1[2] ^ w2[2])) == 0;
}

static inline int
rte_is_zero_ether_addr(const struct rte_ether_addr *ea)
{
  const uint16_t *w = (const uint16_t *)ea;
  return (w[0] | w[1] | w[2]) == 0;
}

static inline int
rte_is_unicast_ether_addr(const struct rte_ether_addr *ea)
{
  return (ea->addr_bytes[0] & 0x01) == 0;
}

static inline int
rte_is_multicast_ether_addr(const struct rte_ether_addr *ea)
{
  return ea->addr_bytes[0] & 0x01;
}

static inline int
rte_is_broadcast_ether_addr(const struct rte_ether_addr *ea)
{
  const uint16_t *w = (const uint16_t *)ea;
  return (w[0] & w[1] & w[2]) == 0xFFFF;
}

static inline int
rte_is_universal_ether_addr(const struct rte_ether_addr *ea)
{
  return (ea->addr_bytes[0] & 0x02) == 0;
}

static inline int
rte_is_local_admin_ether_addr(const struct rte_ether_addr *ea)
{
  return (ea->addr_bytes[0] & 0x02) != 0;
}

static inline int
rte_is_valid_assigned_ether_addr(const struct rte_ether_addr *ea)
{
  return rte_is_unicast_ether_addr(ea) && (!rte_is_zero_ether_addr(ea));
}

void rte_eth_random_addr(uint8_t *addr);
static inline void
rte_ether_addr_copy(const struct rte_ether_addr *__restrict ea_from,
                    struct rte_ether_addr *__restrict ea_to)
{
  *ea_to = *ea_from;
}

void rte_ether_format_addr(char *buf, uint16_t size,
                           const struct rte_ether_addr *eth_addr);
int rte_ether_unformat_addr(const char *str, struct rte_ether_addr *eth_addr);
struct __attribute__((__aligned__(2))) rte_ether_hdr
{
  struct rte_ether_addr dst_addr;
  struct rte_ether_addr src_addr;
  rte_be16_t ether_type;
};

struct rte_vlan_hdr
{
  rte_be16_t vlan_tci;
  rte_be16_t eth_proto;
} __attribute__((__packed__));
static inline int
rte_vlan_strip(struct rte_mbuf *m)
{
  struct rte_ether_hdr *eh =
      ((struct rte_ether_hdr *)(void *)((char *)(m)->buf_addr +
                                        (m)->data_off + (0)));
  struct rte_vlan_hdr *vh;
  if (eh->ether_type != __builtin_bswap16(0x8100))
    return -1;
  vh = (struct rte_vlan_hdr *)(eh + 1);
  m->ol_flags |= (1ULL << 0) | (1ULL << 6);
  m->vlan_tci = __builtin_bswap16(vh->vlan_tci);
  memmove(rte_pktmbuf_adj(m, sizeof(struct rte_vlan_hdr)), eh, 2 * 6);
  return 0;
}

static inline int
rte_vlan_insert(struct rte_mbuf **m)
{
  struct rte_ether_hdr *oh, *nh;
  struct rte_vlan_hdr *vh;
  if (!(!((*m)->ol_flags & ((1ULL << 62) | (1ULL << 61)))) || rte_mbuf_refcnt_read(*m) > 1)
    return -22;
  if (((*m)->data_len) < 2 * 6)
    return -22;
  oh =
      ((struct rte_ether_hdr *)(void *)((char *)(*m)->buf_addr +
                                        (*m)->data_off + (0)));
  nh =
      (struct rte_ether_hdr *)(void *)rte_pktmbuf_prepend(*m,
                                                          sizeof(struct
                                                                 rte_vlan_hdr));
  if (nh == ((void *)0))
    return -28;
  memmove(nh, oh, 2 * 6);
  nh->ether_type = __builtin_bswap16(0x8100);
  vh = (struct rte_vlan_hdr *)(nh + 1);
  vh->vlan_tci = __builtin_bswap16((*m)->vlan_tci);
  (*m)->ol_flags &= ~((1ULL << 6) | (1ULL << 57));
  if ((*m)->ol_flags & (0xFULL << 45))
    (*m)->outer_l2_len += sizeof(struct rte_vlan_hdr);
  else
    (*m)->l2_len += sizeof(struct rte_vlan_hdr);
  return 0;
}

typedef struct __jmp_buf_internal_tag
{
  long int __pc;
  long int __regs[12];
  long int __sp;
  double __fpregs[12];
} __jmp_buf[1];
struct __jmp_buf_tag
{
  __jmp_buf __jmpbuf;
  int __mask_was_saved;
  __sigset_t __saved_mask;
};
enum
{
  PTHREAD_CREATE_JOINABLE,
  PTHREAD_CREATE_DETACHED
};
enum
{
  PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_ADAPTIVE_NP,
  PTHREAD_MUTEX_NORMAL = PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE = PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK = PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_DEFAULT = PTHREAD_MUTEX_NORMAL,
  PTHREAD_MUTEX_FAST_NP =
      PTHREAD_MUTEX_TIMED_NP
};
enum
{
  PTHREAD_MUTEX_STALLED,
  PTHREAD_MUTEX_STALLED_NP = PTHREAD_MUTEX_STALLED,
  PTHREAD_MUTEX_ROBUST,
  PTHREAD_MUTEX_ROBUST_NP = PTHREAD_MUTEX_ROBUST
};
enum
{
  PTHREAD_PRIO_NONE,
  PTHREAD_PRIO_INHERIT,
  PTHREAD_PRIO_PROTECT
};
enum
{
  PTHREAD_RWLOCK_PREFER_READER_NP,
  PTHREAD_RWLOCK_PREFER_WRITER_NP,
  PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP,
  PTHREAD_RWLOCK_DEFAULT_NP = PTHREAD_RWLOCK_PREFER_READER_NP
};
enum
{
  PTHREAD_INHERIT_SCHED,
  PTHREAD_EXPLICIT_SCHED
};
enum
{
  PTHREAD_SCOPE_SYSTEM,
  PTHREAD_SCOPE_PROCESS
};
enum
{
  PTHREAD_PROCESS_PRIVATE,
  PTHREAD_PROCESS_SHARED
};
struct _pthread_cleanup_buffer
{
  void (*__routine)(void *);
  void *__arg;
  int __canceltype;
  struct _pthread_cleanup_buffer *__prev;
};
enum
{
  PTHREAD_CANCEL_ENABLE,
  PTHREAD_CANCEL_DISABLE
};
enum
{
  PTHREAD_CANCEL_DEFERRED,
  PTHREAD_CANCEL_ASYNCHRONOUS
};
extern int pthread_create(pthread_t *__restrict __newthread,
                          const pthread_attr_t *__restrict __attr,
                          void *(*__start_routine)(void *),
                          void *__restrict __arg)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 3)));
extern void pthread_exit(void *__retval) __attribute__((__noreturn__));
extern int pthread_join(pthread_t __th, void **__thread_return);
extern int pthread_tryjoin_np(pthread_t __th, void **__thread_return)
    __attribute__((__nothrow__, __leaf__));
extern int pthread_timedjoin_np(pthread_t __th, void **__thread_return,
                                const struct timespec *__abstime);
extern int pthread_clockjoin_np(pthread_t __th, void **__thread_return,
                                clockid_t __clockid,
                                const struct timespec *__abstime);
extern int pthread_detach(pthread_t __th)
    __attribute__((__nothrow__, __leaf__));
extern pthread_t pthread_self(void) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));
extern int pthread_equal(pthread_t __thread1, pthread_t __thread2)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern int pthread_attr_init(pthread_attr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_attr_destroy(pthread_attr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_attr_getdetachstate(const pthread_attr_t *__attr,
                                       int *__detachstate)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_setdetachstate(pthread_attr_t *__attr,
                                       int __detachstate)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_attr_getguardsize(const pthread_attr_t *__attr,
                                     size_t *__guardsize)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_setguardsize(pthread_attr_t *__attr,
                                     size_t __guardsize)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_attr_getschedparam(const pthread_attr_t *__restrict __attr,
                                      struct sched_param *__restrict __param)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_setschedparam(pthread_attr_t *__restrict __attr,
                                      const struct sched_param *__restrict __param)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_getschedpolicy(const pthread_attr_t *__restrict __attr, int *__restrict __policy)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_setschedpolicy(pthread_attr_t *__attr, int __policy)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_attr_getinheritsched(const pthread_attr_t *__restrict __attr, int *__restrict __inherit)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_setinheritsched(pthread_attr_t *__attr,
                                        int __inherit)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_attr_getscope(const pthread_attr_t *__restrict __attr,
                                 int *__restrict __scope)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_setscope(pthread_attr_t *__attr, int __scope)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_attr_getstackaddr(const pthread_attr_t *__restrict __attr, void **__restrict __stackaddr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)))
    __attribute__((__deprecated__));
extern int pthread_attr_setstackaddr(pthread_attr_t *__attr,
                                     void *__stackaddr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__deprecated__));
extern int pthread_attr_getstacksize(const pthread_attr_t *__restrict __attr, size_t *__restrict __stacksize)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_setstacksize(pthread_attr_t *__attr,
                                     size_t __stacksize)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_attr_getstack(const pthread_attr_t *__restrict __attr,
                                 void **__restrict __stackaddr,
                                 size_t *__restrict __stacksize)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__nonnull__(1, 2, 3)));
extern int pthread_attr_setstack(pthread_attr_t *__attr, void *__stackaddr,
                                 size_t __stacksize)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_attr_setaffinity_np(pthread_attr_t *__attr,
                                       size_t __cpusetsize,
                                       const cpu_set_t *__cpuset)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 3)));
extern int pthread_attr_getaffinity_np(const pthread_attr_t *__attr,
                                       size_t __cpusetsize,
                                       cpu_set_t *__cpuset)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 3)));
extern int pthread_getattr_default_np(pthread_attr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_attr_setsigmask_np(pthread_attr_t *__attr,
                                      const __sigset_t *sigmask);
extern int pthread_attr_getsigmask_np(const pthread_attr_t *__attr,
                                      __sigset_t *sigmask);
extern int pthread_setattr_default_np(const pthread_attr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_getattr_np(pthread_t __th, pthread_attr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int pthread_setschedparam(pthread_t __target_thread, int __policy,
                                 const struct sched_param *__param)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
extern int pthread_getschedparam(pthread_t __target_thread,
                                 int *__restrict __policy,
                                 struct sched_param *__restrict __param)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 3)));
extern int pthread_setschedprio(pthread_t __target_thread, int __prio)
    __attribute__((__nothrow__, __leaf__));
extern int pthread_getname_np(pthread_t __target_thread, char *__buf,
                              size_t __buflen)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int pthread_setname_np(pthread_t __target_thread, const char *__name)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int pthread_getconcurrency(void)
    __attribute__((__nothrow__, __leaf__));
extern int pthread_setconcurrency(int __level)
    __attribute__((__nothrow__, __leaf__));
extern int pthread_yield(void) __attribute__((__nothrow__, __leaf__));
extern int
pthread_yield(void) __asm__(""
                            "sched_yield") __attribute__((__nothrow__, __leaf__))
__attribute__((__deprecated__("pthread_yield is deprecated, use sched_yield instead")));
extern int pthread_setaffinity_np(pthread_t __th, size_t __cpusetsize,
                                  const cpu_set_t *__cpuset)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
extern int pthread_getaffinity_np(pthread_t __th, size_t __cpusetsize,
                                  cpu_set_t *__cpuset)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
extern int pthread_once(pthread_once_t *__once_control,
                        void (*__init_routine)(void))
    __attribute__((__nonnull__(1, 2)));
extern int pthread_setcancelstate(int __state, int *__oldstate);
extern int pthread_setcanceltype(int __type, int *__oldtype);
extern int pthread_cancel(pthread_t __th);
extern void pthread_testcancel(void);
struct __cancel_jmp_buf_tag
{
  __jmp_buf __cancel_jmp_buf;
  int __mask_was_saved;
};
typedef struct
{
  struct __cancel_jmp_buf_tag __cancel_jmp_buf[1];
  void *__pad[4];
} __pthread_unwind_buf_t __attribute__((__aligned__));
struct __pthread_cleanup_frame
{
  void (*__cancel_routine)(void *);
  void *__cancel_arg;
  int __do_it;
  int __cancel_type;
};
extern void __pthread_register_cancel(__pthread_unwind_buf_t *__buf);
extern void __pthread_unregister_cancel(__pthread_unwind_buf_t *__buf);
extern void __pthread_register_cancel_defer(__pthread_unwind_buf_t
                                                *__buf);
extern void __pthread_unregister_cancel_restore(__pthread_unwind_buf_t
                                                    *__buf);
extern void __pthread_unwind_next(__pthread_unwind_buf_t *__buf)
    __attribute__((__noreturn__)) __attribute__((__weak__));
extern int __sigsetjmp_cancel(struct __cancel_jmp_buf_tag __env[1],
                              int __savemask) __asm__(""
                                                      "__sigsetjmp")
    __attribute__((__nothrow__)) __attribute__((__returns_twice__));
extern int pthread_mutex_init(pthread_mutex_t *__mutex,
                              const pthread_mutexattr_t *__mutexattr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutex_destroy(pthread_mutex_t *__mutex)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutex_trylock(pthread_mutex_t *__mutex)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));
extern int pthread_mutex_lock(pthread_mutex_t *__mutex)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));
extern int pthread_mutex_timedlock(pthread_mutex_t *__restrict __mutex,
                                   const struct timespec *__restrict __abstime)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_mutex_clocklock(pthread_mutex_t *__restrict __mutex,
                                   clockid_t __clockid,
                                   const struct timespec *__restrict __abstime)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 3)));
extern int pthread_mutex_unlock(pthread_mutex_t *__mutex)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));
extern int pthread_mutex_getprioceiling(const pthread_mutex_t
                                            *__restrict __mutex,
                                        int *__restrict __prioceiling)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_mutex_setprioceiling(pthread_mutex_t *__restrict __mutex, int __prioceiling,
                                        int *__restrict __old_ceiling)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 3)));
extern int pthread_mutex_consistent(pthread_mutex_t *__mutex)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutex_consistent_np(pthread_mutex_t *) __asm__(""
                                                                  "pthread_mutex_consistent")
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__deprecated__("pthread_mutex_consistent_np is deprecated, use pthread_mutex_consistent")));
extern int pthread_mutexattr_init(pthread_mutexattr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutexattr_destroy(pthread_mutexattr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutexattr_getpshared(const pthread_mutexattr_t
                                            *__restrict __attr,
                                        int *__restrict __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_mutexattr_setpshared(pthread_mutexattr_t *__attr,
                                        int __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutexattr_gettype(const pthread_mutexattr_t
                                         *__restrict __attr,
                                     int *__restrict __kind)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_mutexattr_settype(pthread_mutexattr_t *__attr,
                                     int __kind)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutexattr_getprotocol(const pthread_mutexattr_t
                                             *__restrict __attr,
                                         int *__restrict __protocol)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_mutexattr_setprotocol(pthread_mutexattr_t *__attr,
                                         int __protocol)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutexattr_getprioceiling(const pthread_mutexattr_t
                                                *__restrict __attr,
                                            int *__restrict __prioceiling)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_mutexattr_setprioceiling(pthread_mutexattr_t *__attr,
                                            int __prioceiling)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutexattr_getrobust(const pthread_mutexattr_t
                                           *__attr,
                                       int *__robustness)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_mutexattr_getrobust_np(pthread_mutexattr_t *,
                                          int *) __asm__(""
                                                         "pthread_mutexattr_getrobust")
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__deprecated__("pthread_mutexattr_getrobust_np is deprecated, use pthread_mutexattr_getrobust")));
extern int pthread_mutexattr_setrobust(pthread_mutexattr_t *__attr,
                                       int __robustness)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutexattr_setrobust_np(pthread_mutexattr_t *,
                                          int) __asm__(""
                                                       "pthread_mutexattr_setrobust")
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__deprecated__("pthread_mutexattr_setrobust_np is deprecated, use pthread_mutexattr_setrobust")));
extern int pthread_rwlock_init(pthread_rwlock_t *__restrict __rwlock,
                               const pthread_rwlockattr_t *__restrict __attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_rwlock_destroy(pthread_rwlock_t *__rwlock)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_rwlock_rdlock(pthread_rwlock_t *__rwlock)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));
extern int pthread_rwlock_tryrdlock(pthread_rwlock_t *__rwlock)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));
extern int pthread_rwlock_timedrdlock(pthread_rwlock_t *__restrict __rwlock,
                                      const struct timespec *__restrict __abstime)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_rwlock_clockrdlock(pthread_rwlock_t *__restrict __rwlock, clockid_t __clockid,
                                      const struct timespec *__restrict __abstime)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 3)));
extern int pthread_rwlock_wrlock(pthread_rwlock_t *__rwlock)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));
extern int pthread_rwlock_trywrlock(pthread_rwlock_t *__rwlock)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));
extern int pthread_rwlock_timedwrlock(pthread_rwlock_t *__restrict __rwlock,
                                      const struct timespec *__restrict __abstime)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_rwlock_clockwrlock(pthread_rwlock_t *__restrict __rwlock, clockid_t __clockid,
                                      const struct timespec *__restrict __abstime)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 3)));
extern int pthread_rwlock_unlock(pthread_rwlock_t *__rwlock)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));
extern int pthread_rwlockattr_init(pthread_rwlockattr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_rwlockattr_destroy(pthread_rwlockattr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_rwlockattr_getpshared(const pthread_rwlockattr_t
                                             *__restrict __attr,
                                         int *__restrict __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_rwlockattr_setpshared(pthread_rwlockattr_t *__attr,
                                         int __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_rwlockattr_getkind_np(const pthread_rwlockattr_t
                                             *__restrict __attr,
                                         int *__restrict __pref)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_rwlockattr_setkind_np(pthread_rwlockattr_t *__attr,
                                         int __pref)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_cond_init(pthread_cond_t *__restrict __cond,
                             const pthread_condattr_t *__restrict __cond_attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_cond_destroy(pthread_cond_t *__cond)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_cond_signal(pthread_cond_t *__cond)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));
extern int pthread_cond_broadcast(pthread_cond_t *__cond)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));
extern int pthread_cond_wait(pthread_cond_t *__restrict __cond,
                             pthread_mutex_t *__restrict __mutex)
    __attribute__((__nonnull__(1, 2)));
extern int pthread_cond_timedwait(pthread_cond_t *__restrict __cond,
                                  pthread_mutex_t *__restrict __mutex,
                                  const struct timespec *__restrict __abstime)
    __attribute__((__nonnull__(1, 2, 3)));
extern int pthread_cond_clockwait(pthread_cond_t *__restrict __cond,
                                  pthread_mutex_t *__restrict __mutex,
                                  __clockid_t __clock_id,
                                  const struct timespec *__restrict __abstime)
    __attribute__((__nonnull__(1, 2, 4)));
extern int pthread_condattr_init(pthread_condattr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_condattr_destroy(pthread_condattr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_condattr_getpshared(const pthread_condattr_t
                                           *__restrict __attr,
                                       int *__restrict __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_condattr_setpshared(pthread_condattr_t *__attr,
                                       int __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_condattr_getclock(const pthread_condattr_t
                                         *__restrict __attr,
                                     __clockid_t *__restrict __clock_id)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_condattr_setclock(pthread_condattr_t *__attr,
                                     __clockid_t __clock_id)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_spin_init(pthread_spinlock_t *__lock, int __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_spin_destroy(pthread_spinlock_t *__lock)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_spin_lock(pthread_spinlock_t *__lock)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));
extern int pthread_spin_trylock(pthread_spinlock_t *__lock)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));
extern int pthread_spin_unlock(pthread_spinlock_t *__lock)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));
extern int pthread_barrier_init(pthread_barrier_t *__restrict __barrier,
                                const pthread_barrierattr_t *__restrict __attr, unsigned int __count)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_barrier_destroy(pthread_barrier_t *__barrier)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_barrier_wait(pthread_barrier_t *__barrier)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));
extern int pthread_barrierattr_init(pthread_barrierattr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_barrierattr_destroy(pthread_barrierattr_t *__attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_barrierattr_getpshared(const pthread_barrierattr_t
                                              *__restrict __attr,
                                          int *__restrict __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_barrierattr_setpshared(pthread_barrierattr_t *__attr,
                                          int __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_key_create(pthread_key_t *__key,
                              void (*__destr_function)(void *))
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_key_delete(pthread_key_t __key)
    __attribute__((__nothrow__, __leaf__));
extern void *pthread_getspecific(pthread_key_t __key)
    __attribute__((__nothrow__, __leaf__));
extern int pthread_setspecific(pthread_key_t __key,
                               const void *__pointer)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__access__(__none__, 2)));
extern int pthread_getcpuclockid(pthread_t __thread_id,
                                 __clockid_t *__clock_id)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int pthread_atfork(void (*__prepare)(void),
                          void (*__parent)(void),
                          void (*__child)(void))
    __attribute__((__nothrow__, __leaf__));
extern __inline __attribute__((__gnu_inline__)) int
    __attribute__((__nothrow__,
                   __leaf__))
    pthread_equal(pthread_t __thread1,
                  pthread_t __thread2)
{
  return __thread1 == __thread2;
}

struct rte_bus;
struct rte_devargs;
struct rte_device;
struct rte_driver;
enum rte_dev_event_type
{
  RTE_DEV_EVENT_ADD,
  RTE_DEV_EVENT_REMOVE,
  RTE_DEV_EVENT_MAX
};
typedef void (*rte_dev_event_cb_fn)(const char *device_name,
                                    enum rte_dev_event_type event,
                                    void *cb_arg);
enum rte_dev_policy
{
  RTE_DEV_ALLOWED,
  RTE_DEV_BLOCKED,
};
struct rte_mem_resource
{
  uint64_t phys_addr;
  uint64_t len;
  void *addr;
};
const char *rte_driver_name(const struct rte_driver *driver);
const struct rte_bus *rte_dev_bus(const struct rte_device *dev);
const char *rte_dev_bus_info(const struct rte_device *dev);
const struct rte_devargs *rte_dev_devargs(const struct rte_device *dev);
const struct rte_driver *rte_dev_driver(const struct rte_device *dev);
const char *rte_dev_name(const struct rte_device *dev);
int rte_dev_numa_node(const struct rte_device *dev);
int rte_dev_is_probed(const struct rte_device *dev);
int rte_eal_hotplug_add(const char *busname, const char *devname,
                        const char *drvargs);
int rte_dev_probe(const char *devargs);
int rte_eal_hotplug_remove(const char *busname, const char *devname);
int rte_dev_remove(struct rte_device *dev);
typedef int (*rte_dev_cmp_t)(const struct rte_device *dev,
                             const void *data);
struct rte_dev_iterator
{
  const char *dev_str;
  const char *bus_str;
  const char *cls_str;
  struct rte_bus *bus;
  struct rte_class *cls;
  struct rte_device *device;
  void *class_device;
};
typedef void *(*rte_dev_iterate_t)(const void *start,
                                   const char *devstr,
                                   const struct rte_dev_iterator *it);
int rte_dev_iterator_init(struct rte_dev_iterator *it, const char *str);
struct rte_device *rte_dev_iterator_next(struct rte_dev_iterator *it);
int rte_dev_event_callback_register(const char *device_name,
                                    rte_dev_event_cb_fn cb_fn, void *cb_arg);
int rte_dev_event_callback_unregister(const char *device_name,
                                      rte_dev_event_cb_fn cb_fn, void *cb_arg);
void rte_dev_event_callback_process(const char *device_name,
                                    enum rte_dev_event_type event);
int rte_dev_event_monitor_start(void);
int rte_dev_event_monitor_stop(void);
int rte_dev_hotplug_handle_enable(void);
int rte_dev_hotplug_handle_disable(void);
int rte_dev_dma_map(struct rte_device *dev, void *addr, uint64_t iova,
                    size_t len);
int rte_dev_dma_unmap(struct rte_device *dev, void *addr, uint64_t iova,
                      size_t len);
struct rte_driver
{
  struct
  {
    struct rte_driver *tqe_next;
    struct rte_driver **tqe_prev;
  } next;
  const char *name;
  const char *alias;
};
struct rte_device
{
  struct
  {
    struct rte_device *tqe_next;
    struct rte_device **tqe_prev;
  } next;
  const char *name;
  const char *bus_info;
  const struct rte_driver *driver;
  const struct rte_bus *bus;
  int numa_node;
  struct rte_devargs *devargs;
};
enum rte_cman_mode
{
  RTE_CMAN_RED = (1U << (0)),
};
struct rte_cman_red_params
{
  uint8_t min_th;
  uint8_t max_th;
  uint16_t maxp_inv;
};
typedef void (*rte_intr_event_cb_t)(int fd, void *arg);
struct rte_epoll_data
{
  uint32_t event;
  void *data;
  rte_intr_event_cb_t cb_fun;
  void *cb_arg;
};
enum
{
  RTE_EPOLL_INVALID = 0,
  RTE_EPOLL_VALID,
  RTE_EPOLL_EXEC,
};
struct rte_epoll_event
{
  uint32_t status;
  int fd;
  int epfd;
  struct rte_epoll_data epdata;
};
int rte_epoll_wait(int epfd, struct rte_epoll_event *events,
                   int maxevents, int timeout);
int rte_epoll_wait_interruptible(int epfd, struct rte_epoll_event *events,
                                 int maxevents, int timeout);
int rte_epoll_ctl(int epfd, int op, int fd, struct rte_epoll_event *event);
struct rte_intr_handle;
enum rte_intr_handle_type
{
  RTE_INTR_HANDLE_UNKNOWN = 0,
  RTE_INTR_HANDLE_UIO,
  RTE_INTR_HANDLE_UIO_INTX,
  RTE_INTR_HANDLE_VFIO_LEGACY,
  RTE_INTR_HANDLE_VFIO_MSI,
  RTE_INTR_HANDLE_VFIO_MSIX,
  RTE_INTR_HANDLE_ALARM,
  RTE_INTR_HANDLE_EXT,
  RTE_INTR_HANDLE_VDEV,
  RTE_INTR_HANDLE_DEV_EVENT,
  RTE_INTR_HANDLE_VFIO_REQ,
  RTE_INTR_HANDLE_MAX
};
typedef void (*rte_intr_callback_fn)(void *cb_arg);
typedef void (*rte_intr_unregister_callback_fn)(struct rte_intr_handle *
                                                    intr_handle,
                                                void *cb_arg);
int rte_intr_callback_register(const struct rte_intr_handle *intr_handle,
                               rte_intr_callback_fn cb, void *cb_arg);
int rte_intr_callback_unregister(const struct rte_intr_handle *intr_handle,
                                 rte_intr_callback_fn cb, void *cb_arg);
int rte_intr_callback_unregister_pending(const struct rte_intr_handle
                                             *intr_handle,
                                         rte_intr_callback_fn cb_fn,
                                         void *cb_arg,
                                         rte_intr_unregister_callback_fn ucb_fn);
int rte_intr_callback_unregister_sync(const struct rte_intr_handle *intr_handle,
                                      rte_intr_callback_fn cb, void *cb_arg);
int rte_intr_enable(const struct rte_intr_handle *intr_handle);
int rte_intr_disable(const struct rte_intr_handle *intr_handle);
int rte_intr_ack(const struct rte_intr_handle *intr_handle);
int rte_thread_is_intr(void);
struct rte_intr_handle *rte_intr_instance_alloc(uint32_t flags);
void rte_intr_instance_free(struct rte_intr_handle *intr_handle);
int rte_intr_fd_set(struct rte_intr_handle *intr_handle, int fd);
int rte_intr_fd_get(const struct rte_intr_handle *intr_handle);
int rte_intr_type_set(struct rte_intr_handle *intr_handle,
                      enum rte_intr_handle_type type);
enum rte_intr_handle_type
rte_intr_type_get(const struct rte_intr_handle *intr_handle);
__attribute__((section(".text.internal"))) int rte_intr_tls_epfd(void);
__attribute__((section(".text.internal"))) int
rte_intr_rx_ctl(struct rte_intr_handle *intr_handle,
                int epfd, int op, unsigned int vec, void *data);
__attribute__((section(".text.internal"))) void rte_intr_free_epoll_fd(struct rte_intr_handle *intr_handle);
__attribute__((section(".text.internal"))) int
rte_intr_efd_enable(struct rte_intr_handle *intr_handle,
                    uint32_t nb_efd);
__attribute__((section(".text.internal"))) void rte_intr_efd_disable(struct rte_intr_handle *intr_handle);
__attribute__((section(".text.internal"))) int rte_intr_dp_is_en(struct rte_intr_handle *intr_handle);
__attribute__((section(".text.internal"))) int rte_intr_allow_others(struct rte_intr_handle *intr_handle);
__attribute__((section(".text.internal"))) int rte_intr_cap_multiple(struct rte_intr_handle *intr_handle);
__attribute__((section(".text.internal"))) struct rte_intr_handle *rte_intr_instance_dup(const struct
                                                                                         rte_intr_handle *src);
__attribute__((section(".text.internal"))) int rte_intr_dev_fd_set(struct rte_intr_handle *intr_handle, int fd);
__attribute__((section(".text.internal"))) int rte_intr_dev_fd_get(const struct rte_intr_handle *intr_handle);
__attribute__((section(".text.internal"))) int
rte_intr_max_intr_set(struct rte_intr_handle *intr_handle,
                      int max_intr);
__attribute__((section(".text.internal"))) int rte_intr_max_intr_get(const struct rte_intr_handle *intr_handle);
__attribute__((section(".text.internal"))) int
rte_intr_nb_efd_set(struct rte_intr_handle *intr_handle, int nb_efd);
__attribute__((section(".text.internal"))) int rte_intr_nb_efd_get(const struct rte_intr_handle *intr_handle);
__attribute__((section(".text.internal"))) int rte_intr_nb_intr_get(const struct rte_intr_handle *intr_handle);
__attribute__((section(".text.internal"))) int
rte_intr_efd_counter_size_set(struct rte_intr_handle *intr_handle,
                              uint8_t efd_counter_size);
__attribute__((section(".text.internal"))) int
rte_intr_efd_counter_size_get(const struct rte_intr_handle
                                  *intr_handle);
__attribute__((section(".text.internal"))) int
rte_intr_efds_index_set(struct rte_intr_handle *intr_handle,
                        int index, int fd);
__attribute__((section(".text.internal"))) int
rte_intr_efds_index_get(const struct rte_intr_handle *intr_handle,
                        int index);
__attribute__((section(".text.internal"))) int
rte_intr_elist_index_set(struct rte_intr_handle *intr_handle,
                         int index, struct rte_epoll_event elist);
__attribute__((section(".text.internal"))) struct rte_epoll_event *rte_intr_elist_index_get(struct rte_intr_handle
                                                                                                *intr_handle,
                                                                                            int index);
__attribute__((section(".text.internal"))) int
rte_intr_vec_list_alloc(struct rte_intr_handle *intr_handle,
                        const char *name, int size);
__attribute__((section(".text.internal"))) int
rte_intr_vec_list_index_set(struct rte_intr_handle *intr_handle,
                            int index, int vec);
__attribute__((section(".text.internal"))) int
rte_intr_vec_list_index_get(const struct rte_intr_handle *intr_handle,
                            int index);
__attribute__((section(".text.internal"))) void rte_intr_vec_list_free(struct rte_intr_handle *intr_handle);
__attribute__((section(".text.internal"))) int
rte_intr_event_list_update(struct rte_intr_handle *intr_handle,
                           int size);
__attribute__((section(".text.internal"))) void *rte_intr_instance_windows_handle_get(struct rte_intr_handle
                                                                                          *intr_handle);
__attribute__((section(".text.internal"))) int
rte_intr_instance_windows_handle_set(struct rte_intr_handle
                                         *intr_handle,
                                     void *windows_handle);
struct rte_bus;
enum rte_devtype
{
  RTE_DEVTYPE_ALLOWED,
  RTE_DEVTYPE_BLOCKED,
  RTE_DEVTYPE_VIRTUAL,
};
struct rte_devargs
{
  struct
  {
    struct rte_devargs *tqe_next;
    struct rte_devargs **tqe_prev;
  } next;
  enum rte_devtype type;
  enum rte_dev_policy policy;
  char name[64];
  union
  {
    const char *args;
    const char *drv_str;
  };
  struct rte_bus *bus;
  struct rte_class *cls;
  const char *bus_str;
  const char *cls_str;
  char *data;
};
int rte_devargs_parse(struct rte_devargs *da, const char *dev);
int rte_devargs_parsef(struct rte_devargs *da,
                       const char *format, ...)
    __attribute__((format(gnu_printf, 2, 0)));
void rte_devargs_reset(struct rte_devargs *da);
int rte_devargs_insert(struct rte_devargs **da);
int rte_devargs_add(enum rte_devtype devtype, const char *devargs_str);
int rte_devargs_remove(struct rte_devargs *devargs);
unsigned int rte_devargs_type_count(enum rte_devtype devtype);
void rte_devargs_dump(FILE *f);
struct rte_devargs *rte_devargs_next(const char *busname,
                                     const struct rte_devargs *start);
extern __thread int per_lcore__rte_errno;
const char *rte_strerror(int errnum);
enum
{
  RTE_MIN_ERRNO = 1000,
  E_RTE_SECONDARY,
  E_RTE_NO_CONFIG,
  RTE_MAX_ERRNO
};
typedef int (*rte_power_monitor_clb_t)(const uint64_t val,
                                       const uint64_t opaque[4]);
struct rte_power_monitor_cond
{
  volatile void *addr;
  uint8_t size;
  rte_power_monitor_clb_t fn;
  uint64_t opaque[4];
};
int rte_power_monitor(const struct rte_power_monitor_cond *pmc,
                      const uint64_t tsc_timestamp);
int rte_power_monitor_wakeup(const unsigned int lcore_id);
int rte_power_pause(const uint64_t tsc_timestamp);
int rte_power_monitor_multi(const struct rte_power_monitor_cond pmc[],
                            const uint32_t num,
                            const uint64_t tsc_timestamp);
extern rte_trace_point_t __rte_ethdev_trace_rx_burst;
static inline __attribute__((always_inline)) void rte_ethdev_trace_rx_burst(uint16_t port_id, uint16_t queue_id,
                                                                            void **pkt_tbl, uint16_t nb_rx)
{
  if (!__rte_trace_point_fp_is_enabled())
    return;
  void *mem;
  do
  {
    const uint64_t val = __atomic_load_n(&__rte_ethdev_trace_rx_burst, 2);
    if (__builtin_expect(!!(!(val & (1ULL << 63))), 1))
      return;
    mem = __rte_trace_mem_get(val);
    if (__builtin_expect(!!(mem == ((void *)0)), 0))
      return;
    mem = __rte_trace_point_emit_ev_header(mem, val);
  } while (0);
  do
  {
    memcpy(mem, &(port_id), sizeof(port_id));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(port_id))));
  } while (0);
  do
  {
    memcpy(mem, &(queue_id), sizeof(queue_id));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(queue_id))));
  } while (0);
  do
  {
    memcpy(mem, &(pkt_tbl), sizeof(pkt_tbl));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(pkt_tbl))));
  } while (0);
  do
  {
    memcpy(mem, &(nb_rx), sizeof(nb_rx));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(nb_rx))));
  } while (0);
}

extern rte_trace_point_t __rte_ethdev_trace_tx_burst;
static inline __attribute__((always_inline)) void rte_ethdev_trace_tx_burst(uint16_t port_id, uint16_t queue_id,
                                                                            void **pkts_tbl, uint16_t nb_pkts)
{
  if (!__rte_trace_point_fp_is_enabled())
    return;
  void *mem;
  do
  {
    const uint64_t val = __atomic_load_n(&__rte_ethdev_trace_tx_burst, 2);
    if (__builtin_expect(!!(!(val & (1ULL << 63))), 1))
      return;
    mem = __rte_trace_mem_get(val);
    if (__builtin_expect(!!(mem == ((void *)0)), 0))
      return;
    mem = __rte_trace_point_emit_ev_header(mem, val);
  } while (0);
  do
  {
    memcpy(mem, &(port_id), sizeof(port_id));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(port_id))));
  } while (0);
  do
  {
    memcpy(mem, &(queue_id), sizeof(queue_id));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(queue_id))));
  } while (0);
  do
  {
    memcpy(mem, &(pkts_tbl), sizeof(pkts_tbl));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(pkts_tbl))));
  } while (0);
  do
  {
    memcpy(mem, &(nb_pkts), sizeof(nb_pkts));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(nb_pkts))));
  } while (0);
}

extern rte_trace_point_t __rte_eth_trace_call_rx_callbacks;
static inline __attribute__((always_inline)) void rte_eth_trace_call_rx_callbacks(uint16_t port_id,
                                                                                  uint16_t queue_id, void **rx_pkts,
                                                                                  uint16_t nb_rx, uint16_t nb_pkts)
{
  if (!__rte_trace_point_fp_is_enabled())
    return;
  void *mem;
  do
  {
    const uint64_t val =
        __atomic_load_n(&__rte_eth_trace_call_rx_callbacks, 2);
    if (__builtin_expect(!!(!(val & (1ULL << 63))), 1))
      return;
    mem = __rte_trace_mem_get(val);
    if (__builtin_expect(!!(mem == ((void *)0)), 0))
      return;
    mem = __rte_trace_point_emit_ev_header(mem, val);
  } while (0);
  do
  {
    memcpy(mem, &(port_id), sizeof(port_id));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(port_id))));
  } while (0);
  do
  {
    memcpy(mem, &(queue_id), sizeof(queue_id));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(queue_id))));
  } while (0);
  do
  {
    memcpy(mem, &(rx_pkts), sizeof(rx_pkts));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(rx_pkts))));
  } while (0);
  do
  {
    memcpy(mem, &(nb_rx), sizeof(nb_rx));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(nb_rx))));
  } while (0);
  do
  {
    memcpy(mem, &(nb_pkts), sizeof(nb_pkts));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(nb_pkts))));
  } while (0);
}

extern rte_trace_point_t __rte_eth_trace_call_tx_callbacks;
static inline __attribute__((always_inline)) void rte_eth_trace_call_tx_callbacks(uint16_t port_id,
                                                                                  uint16_t queue_id, void **tx_pkts,
                                                                                  uint16_t nb_pkts)
{
  if (!__rte_trace_point_fp_is_enabled())
    return;
  void *mem;
  do
  {
    const uint64_t val =
        __atomic_load_n(&__rte_eth_trace_call_tx_callbacks, 2);
    if (__builtin_expect(!!(!(val & (1ULL << 63))), 1))
      return;
    mem = __rte_trace_mem_get(val);
    if (__builtin_expect(!!(mem == ((void *)0)), 0))
      return;
    mem = __rte_trace_point_emit_ev_header(mem, val);
  } while (0);
  do
  {
    memcpy(mem, &(port_id), sizeof(port_id));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(port_id))));
  } while (0);
  do
  {
    memcpy(mem, &(queue_id), sizeof(queue_id));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(queue_id))));
  } while (0);
  do
  {
    memcpy(mem, &(tx_pkts), sizeof(tx_pkts));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(tx_pkts))));
  } while (0);
  do
  {
    memcpy(mem, &(nb_pkts), sizeof(nb_pkts));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(nb_pkts))));
  } while (0);
}

extern rte_trace_point_t __rte_eth_trace_tx_buffer_drop_callback;
static inline __attribute__((always_inline)) void rte_eth_trace_tx_buffer_drop_callback(void **pkts, uint16_t unsent)
{
  if (!__rte_trace_point_fp_is_enabled())
    return;
  void *mem;
  do
  {
    const uint64_t val =
        __atomic_load_n(&__rte_eth_trace_tx_buffer_drop_callback, 2);
    if (__builtin_expect(!!(!(val & (1ULL << 63))), 1))
      return;
    mem = __rte_trace_mem_get(val);
    if (__builtin_expect(!!(mem == ((void *)0)), 0))
      return;
    mem = __rte_trace_point_emit_ev_header(mem, val);
  } while (0);
  do
  {
    memcpy(mem, &(pkts), sizeof(pkts));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(pkts))));
  } while (0);
  do
  {
    memcpy(mem, &(unsent), sizeof(unsent));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(unsent))));
  } while (0);
}

extern rte_trace_point_t __rte_eth_trace_tx_buffer_count_callback;
static inline __attribute__((always_inline)) void rte_eth_trace_tx_buffer_count_callback(void **pkts,
                                                                                         uint16_t unsent,
                                                                                         uint64_t count)
{
  if (!__rte_trace_point_fp_is_enabled())
    return;
  void *mem;
  do
  {
    const uint64_t val =
        __atomic_load_n(&__rte_eth_trace_tx_buffer_count_callback, 2);
    if (__builtin_expect(!!(!(val & (1ULL << 63))), 1))
      return;
    mem = __rte_trace_mem_get(val);
    if (__builtin_expect(!!(mem == ((void *)0)), 0))
      return;
    mem = __rte_trace_point_emit_ev_header(mem, val);
  } while (0);
  do
  {
    memcpy(mem, &(pkts), sizeof(pkts));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(pkts))));
  } while (0);
  do
  {
    memcpy(mem, &(unsent), sizeof(unsent));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(unsent))));
  } while (0);
  do
  {
    memcpy(mem, &(count), sizeof(count));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(count))));
  } while (0);
}

extern rte_trace_point_t __rte_eth_trace_tx_queue_count;
static inline __attribute__((always_inline)) void rte_eth_trace_tx_queue_count(uint16_t port_id, uint16_t queue_id,
                                                                               int rc)
{
  if (!__rte_trace_point_fp_is_enabled())
    return;
  void *mem;
  do
  {
    const uint64_t val =
        __atomic_load_n(&__rte_eth_trace_tx_queue_count, 2);
    if (__builtin_expect(!!(!(val & (1ULL << 63))), 1))
      return;
    mem = __rte_trace_mem_get(val);
    if (__builtin_expect(!!(mem == ((void *)0)), 0))
      return;
    mem = __rte_trace_point_emit_ev_header(mem, val);
  } while (0);
  do
  {
    memcpy(mem, &(port_id), sizeof(port_id));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(port_id))));
  } while (0);
  do
  {
    memcpy(mem, &(queue_id), sizeof(queue_id));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(queue_id))));
  } while (0);
  do
  {
    memcpy(mem, &(rc), sizeof(rc));
    mem = ((void *)((uintptr_t)(mem) + (sizeof(rc))));
  } while (0);
}

struct rte_dev_reg_info
{
  void *data;
  uint32_t offset;
  uint32_t length;
  uint32_t width;
  uint32_t version;
};
struct rte_dev_eeprom_info
{
  void *data;
  uint32_t offset;
  uint32_t length;
  uint32_t magic;
};
struct rte_eth_dev_module_info
{
  uint32_t type;
  uint32_t eeprom_len;
};
extern int rte_eth_dev_logtype;
struct rte_mbuf;
int rte_eth_iterator_init(struct rte_dev_iterator *iter,
                          const char *devargs);
uint16_t rte_eth_iterator_next(struct rte_dev_iterator *iter);
void rte_eth_iterator_cleanup(struct rte_dev_iterator *iter);
struct rte_eth_stats
{
  uint64_t ipackets;
  uint64_t opackets;
  uint64_t ibytes;
  uint64_t obytes;
  uint64_t imissed;
  uint64_t ierrors;
  uint64_t oerrors;
  uint64_t rx_nombuf;
  uint64_t q_ipackets[16];
  uint64_t q_opackets[16];
  uint64_t q_ibytes[16];
  uint64_t q_obytes[16];
  uint64_t q_errors[16];
};
struct rte_eth_link
{
  union
  {
    uint64_t val64;
    __extension__ struct
    {
      uint32_t link_speed;
      uint16_t link_duplex : 1;
      uint16_t link_autoneg : 1;
      uint16_t link_status : 1;
    };
  };
};
struct rte_eth_thresh
{
  uint8_t pthresh;
  uint8_t hthresh;
  uint8_t wthresh;
};
enum rte_eth_rx_mq_mode
{
  RTE_ETH_MQ_RX_NONE = 0,
  RTE_ETH_MQ_RX_RSS = (1U << (0)),
  RTE_ETH_MQ_RX_DCB = (1U << (1)),
  RTE_ETH_MQ_RX_DCB_RSS = (1U << (0)) | (1U << (1)),
  RTE_ETH_MQ_RX_VMDQ_ONLY = (1U << (2)),
  RTE_ETH_MQ_RX_VMDQ_RSS = (1U << (0)) | (1U << (2)),
  RTE_ETH_MQ_RX_VMDQ_DCB = (1U << (2)) | (1U << (1)),
  RTE_ETH_MQ_RX_VMDQ_DCB_RSS = (1U << (0)) | (1U << (1)) | (1U << (2)),
};
enum rte_eth_tx_mq_mode
{
  RTE_ETH_MQ_TX_NONE = 0,
  RTE_ETH_MQ_TX_DCB,
  RTE_ETH_MQ_TX_VMDQ_DCB,
  RTE_ETH_MQ_TX_VMDQ_ONLY,
};
struct rte_eth_rxmode
{
  enum rte_eth_rx_mq_mode mq_mode;
  uint32_t mtu;
  uint32_t max_lro_pkt_size;
  uint64_t offloads;
  uint64_t reserved_64s[2];
  void *reserved_ptrs[2];
};
enum rte_vlan_type
{
  RTE_ETH_VLAN_TYPE_UNKNOWN = 0,
  RTE_ETH_VLAN_TYPE_INNER,
  RTE_ETH_VLAN_TYPE_OUTER,
  RTE_ETH_VLAN_TYPE_MAX,
};
struct rte_vlan_filter_conf
{
  uint64_t ids[64];
};
enum rte_eth_hash_function
{
  RTE_ETH_HASH_FUNCTION_DEFAULT = 0,
  RTE_ETH_HASH_FUNCTION_TOEPLITZ,
  RTE_ETH_HASH_FUNCTION_SIMPLE_XOR,
  RTE_ETH_HASH_FUNCTION_SYMMETRIC_TOEPLITZ,
  RTE_ETH_HASH_FUNCTION_SYMMETRIC_TOEPLITZ_SORT,
  RTE_ETH_HASH_FUNCTION_MAX,
};
struct rte_eth_rss_conf
{
  uint8_t *rss_key;
  uint8_t rss_key_len;
  uint64_t rss_hf;
  enum rte_eth_hash_function algorithm;
};
static inline uint64_t
rte_eth_rss_hf_refine(uint64_t rss_hf)
{
  if ((rss_hf & (1UL << (63))) && (rss_hf & (1UL << (62))))
    rss_hf &= ~((1UL << (63)) | (1UL << (62)));
  if ((rss_hf & (1UL << (61))) && (rss_hf & (1UL << (60))))
    rss_hf &= ~((1UL << (61)) | (1UL << (60)));
  return rss_hf;
}

struct rte_eth_rss_reta_entry64
{
  uint64_t mask;
  uint16_t reta[64];
};
enum rte_eth_nb_tcs
{
  RTE_ETH_4_TCS = 4,
  RTE_ETH_8_TCS = 8
};
enum rte_eth_nb_pools
{
  RTE_ETH_8_POOLS = 8,
  RTE_ETH_16_POOLS = 16,
  RTE_ETH_32_POOLS = 32,
  RTE_ETH_64_POOLS = 64
};
struct rte_eth_dcb_rx_conf
{
  enum rte_eth_nb_tcs nb_tcs;
  uint8_t dcb_tc[8];
};
struct rte_eth_vmdq_dcb_tx_conf
{
  enum rte_eth_nb_pools nb_queue_pools;
  uint8_t dcb_tc[8];
};
struct rte_eth_dcb_tx_conf
{
  enum rte_eth_nb_tcs nb_tcs;
  uint8_t dcb_tc[8];
};
struct rte_eth_vmdq_tx_conf
{
  enum rte_eth_nb_pools nb_queue_pools;
};
struct rte_eth_vmdq_dcb_conf
{
  enum rte_eth_nb_pools nb_queue_pools;
  uint8_t enable_default_pool;
  uint8_t default_pool;
  uint8_t nb_pool_maps;
  struct
  {
    uint16_t vlan_id;
    uint64_t pools;
  } pool_map[64];
  uint8_t dcb_tc[8];
};
struct rte_eth_vmdq_rx_conf
{
  enum rte_eth_nb_pools nb_queue_pools;
  uint8_t enable_default_pool;
  uint8_t default_pool;
  uint8_t enable_loop_back;
  uint8_t nb_pool_maps;
  uint32_t rx_mode;
  struct
  {
    uint16_t vlan_id;
    uint64_t pools;
  } pool_map[64];
};
struct rte_eth_txmode
{
  enum rte_eth_tx_mq_mode mq_mode;
  uint64_t offloads;
  uint16_t pvid;
  __extension__ uint8_t
      hw_vlan_reject_tagged : 1,
      hw_vlan_reject_untagged : 1, hw_vlan_insert_pvid : 1;
  uint64_t reserved_64s[2];
  void *reserved_ptrs[2];
};
struct rte_eth_rxseg_split
{
  struct rte_mempool *mp;
  uint16_t length;
  uint16_t offset;
  uint32_t proto_hdr;
};
union rte_eth_rxseg
{
  struct rte_eth_rxseg_split split;
};
struct rte_eth_rxconf
{
  struct rte_eth_thresh rx_thresh;
  uint16_t rx_free_thresh;
  uint8_t rx_drop_en;
  uint8_t rx_deferred_start;
  uint16_t rx_nseg;
  uint16_t share_group;
  uint16_t share_qid;
  uint64_t offloads;
  union rte_eth_rxseg *rx_seg;
  struct rte_mempool **rx_mempools;
  uint16_t rx_nmempool;
  uint64_t reserved_64s[2];
  void *reserved_ptrs[2];
};
struct rte_eth_txconf
{
  struct rte_eth_thresh tx_thresh;
  uint16_t tx_rs_thresh;
  uint16_t tx_free_thresh;
  uint8_t tx_deferred_start;
  uint64_t offloads;
  uint64_t reserved_64s[2];
  void *reserved_ptrs[2];
};
struct rte_eth_hairpin_queue_cap
{
  uint32_t locked_device_memory : 1;
  uint32_t rte_memory : 1;
  uint32_t reserved : 30;
};
struct rte_eth_hairpin_cap
{
  uint16_t max_nb_queues;
  uint16_t max_rx_2_tx;
  uint16_t max_tx_2_rx;
  uint16_t max_nb_desc;
  struct rte_eth_hairpin_queue_cap rx_cap;
  struct rte_eth_hairpin_queue_cap tx_cap;
};
struct rte_eth_hairpin_peer
{
  uint16_t port;
  uint16_t queue;
};
struct rte_eth_hairpin_conf
{
  uint32_t peer_count : 16;
  uint32_t tx_explicit : 1;
  uint32_t manual_bind : 1;
  uint32_t use_locked_device_memory : 1;
  uint32_t use_rte_memory : 1;
  uint32_t force_memory : 1;
  uint32_t reserved : 11;
  struct rte_eth_hairpin_peer peers[32];
};
struct rte_eth_desc_lim
{
  uint16_t nb_max;
  uint16_t nb_min;
  uint16_t nb_align;
  uint16_t nb_seg_max;
  uint16_t nb_mtu_seg_max;
};
enum rte_eth_fc_mode
{
  RTE_ETH_FC_NONE = 0,
  RTE_ETH_FC_RX_PAUSE,
  RTE_ETH_FC_TX_PAUSE,
  RTE_ETH_FC_FULL
};
struct rte_eth_fc_conf
{
  uint32_t high_water;
  uint32_t low_water;
  uint16_t pause_time;
  uint16_t send_xon;
  enum rte_eth_fc_mode mode;
  uint8_t mac_ctrl_frame_fwd;
  uint8_t autoneg;
};
struct rte_eth_pfc_conf
{
  struct rte_eth_fc_conf fc;
  uint8_t priority;
};
struct rte_eth_pfc_queue_info
{
  uint8_t tc_max;
  enum rte_eth_fc_mode mode_capa;
};
struct rte_eth_pfc_queue_conf
{
  enum rte_eth_fc_mode mode;
  struct
  {
    uint16_t tx_qid;
    uint8_t tc;
  } rx_pause;
  struct
  {
    uint16_t pause_time;
    uint16_t rx_qid;
    uint8_t tc;
  } tx_pause;
};
enum rte_eth_tunnel_type
{
  RTE_ETH_TUNNEL_TYPE_NONE = 0,
  RTE_ETH_TUNNEL_TYPE_VXLAN,
  RTE_ETH_TUNNEL_TYPE_GENEVE,
  RTE_ETH_TUNNEL_TYPE_TEREDO,
  RTE_ETH_TUNNEL_TYPE_NVGRE,
  RTE_ETH_TUNNEL_TYPE_IP_IN_GRE,
  RTE_ETH_L2_TUNNEL_TYPE_E_TAG,
  RTE_ETH_TUNNEL_TYPE_VXLAN_GPE,
  RTE_ETH_TUNNEL_TYPE_ECPRI,
  RTE_ETH_TUNNEL_TYPE_MAX,
};
struct __attribute__((__aligned__(2))) rte_arp_ipv4
{
  struct rte_ether_addr arp_sha;
  rte_be32_t arp_sip;
  struct rte_ether_addr arp_tha;
  rte_be32_t arp_tip;
} __attribute__((__packed__));

struct __attribute__((__aligned__(2))) rte_arp_hdr
{
  rte_be16_t arp_hardware;
  rte_be16_t arp_protocol;
  uint8_t arp_hlen;
  uint8_t arp_plen;
  rte_be16_t arp_opcode;
  struct rte_arp_ipv4 arp_data;
} __attribute__((__packed__));

struct rte_mbuf *rte_net_make_rarp_packet(struct rte_mempool *mpool,
                                          const struct rte_ether_addr *mac);
struct rte_icmp_base_hdr
{
  uint8_t type;
  uint8_t code;
  rte_be16_t checksum;
} __attribute__((__packed__));
struct rte_icmp_echo_hdr
{
  struct rte_icmp_base_hdr base;
  rte_be16_t identifier;
  rte_be16_t sequence;
} __attribute__((__packed__));
struct rte_icmp_hdr
{
  uint8_t icmp_type;
  uint8_t icmp_code;
  rte_be16_t icmp_cksum;
  rte_be16_t icmp_ident;
  rte_be16_t icmp_seq_nb;
} __attribute__((__packed__));
struct iovec
{
  void *iov_base;
  size_t iov_len;
};
enum __socket_type
{
  SOCK_STREAM = 1,
  SOCK_DGRAM = 2,
  SOCK_RAW = 3,
  SOCK_RDM = 4,
  SOCK_SEQPACKET = 5,
  SOCK_DCCP = 6,
  SOCK_PACKET = 10,
  SOCK_CLOEXEC = 02000000,
  SOCK_NONBLOCK = 00004000
};
typedef unsigned short int sa_family_t;
struct sockaddr
{
  sa_family_t sa_family;
  char sa_data[14];
};
struct sockaddr_storage
{
  sa_family_t ss_family;
  char
      __ss_padding[(128 - (sizeof(unsigned short int)) -
                    sizeof(unsigned long int))];
  unsigned long int __ss_align;
};
enum
{
  MSG_OOB = 0x01,
  MSG_PEEK = 0x02,
  MSG_DONTROUTE = 0x04,
  MSG_TRYHARD = MSG_DONTROUTE,
  MSG_CTRUNC = 0x08,
  MSG_PROXY = 0x10,
  MSG_TRUNC = 0x20,
  MSG_DONTWAIT = 0x40,
  MSG_EOR = 0x80,
  MSG_WAITALL = 0x100,
  MSG_FIN = 0x200,
  MSG_SYN = 0x400,
  MSG_CONFIRM = 0x800,
  MSG_RST = 0x1000,
  MSG_ERRQUEUE = 0x2000,
  MSG_NOSIGNAL = 0x4000,
  MSG_MORE = 0x8000,
  MSG_WAITFORONE = 0x10000,
  MSG_BATCH = 0x40000,
  MSG_ZEROCOPY = 0x4000000,
  MSG_FASTOPEN = 0x20000000,
  MSG_CMSG_CLOEXEC = 0x40000000
};
struct msghdr
{
  void *msg_name;
  socklen_t msg_namelen;
  struct iovec *msg_iov;
  size_t msg_iovlen;
  void *msg_control;
  size_t msg_controllen;
  int msg_flags;
};
struct cmsghdr
{
  size_t cmsg_len;
  int cmsg_level;
  int cmsg_type;
  __extension__ unsigned char __cmsg_data[];
};
extern struct cmsghdr *__cmsg_nxthdr(struct msghdr *__mhdr,
                                     struct cmsghdr *__cmsg)
    __attribute__((__nothrow__, __leaf__));
extern __inline __attribute__((__gnu_inline__)) struct cmsghdr *__attribute__((__nothrow__,
                                                                               __leaf__))
__cmsg_nxthdr(struct msghdr *__mhdr,
              struct cmsghdr *__cmsg)
{
  unsigned char *__msg_control_ptr = (unsigned char *)__mhdr->msg_control;
  unsigned char *__cmsg_ptr = (unsigned char *)__cmsg;
  size_t __size_needed = sizeof(struct cmsghdr) +
                         ((sizeof(size_t) -
                           ((__cmsg->cmsg_len) & (sizeof(size_t) - 1))) &
                          (sizeof(size_t) - 1));
  if ((size_t)__cmsg->cmsg_len < sizeof(struct cmsghdr))
    return (struct cmsghdr *)0;
  if (((size_t)(__msg_control_ptr + __mhdr->msg_controllen - __cmsg_ptr) < __size_needed) || ((size_t)(__msg_control_ptr + __mhdr->msg_controllen - __cmsg_ptr - __size_needed) < __cmsg->cmsg_len))
    return (struct cmsghdr *)0;
  __cmsg = (struct cmsghdr *)((unsigned char *)__cmsg +
                              (((__cmsg->cmsg_len) + sizeof(size_t) -
                                1) &
                               (size_t) ~(sizeof(size_t) - 1)));
  return __cmsg;
}

enum
{
  SCM_RIGHTS = 0x01,
  SCM_CREDENTIALS = 0x02
};
struct ucred
{
  pid_t pid;
  uid_t uid;
  gid_t gid;
};
typedef struct
{
  unsigned long fds_bits[1024 / (8 * sizeof(long))];
} __kernel_fd_set;
typedef void (*__kernel_sighandler_t)(int);
typedef int __kernel_key_t;
typedef int __kernel_mqd_t;
typedef long __kernel_long_t;
typedef unsigned long __kernel_ulong_t;
typedef __kernel_ulong_t __kernel_ino_t;
typedef unsigned int __kernel_mode_t;
typedef int __kernel_pid_t;
typedef int __kernel_ipc_pid_t;
typedef unsigned int __kernel_uid_t;
typedef unsigned int __kernel_gid_t;
typedef __kernel_long_t __kernel_suseconds_t;
typedef int __kernel_daddr_t;
typedef unsigned int __kernel_uid32_t;
typedef unsigned int __kernel_gid32_t;
typedef __kernel_uid_t __kernel_old_uid_t;
typedef __kernel_gid_t __kernel_old_gid_t;
typedef unsigned int __kernel_old_dev_t;
typedef __kernel_ulong_t __kernel_size_t;
typedef __kernel_long_t __kernel_ssize_t;
typedef __kernel_long_t __kernel_ptrdiff_t;
typedef struct
{
  int val[2];
} __kernel_fsid_t;
typedef __kernel_long_t __kernel_off_t;
typedef long long __kernel_loff_t;
typedef __kernel_long_t __kernel_old_time_t;
typedef __kernel_long_t __kernel_time_t;
typedef long long __kernel_time64_t;
typedef __kernel_long_t __kernel_clock_t;
typedef int __kernel_timer_t;
typedef int __kernel_clockid_t;
typedef char *__kernel_caddr_t;
typedef unsigned short __kernel_uid16_t;
typedef unsigned short __kernel_gid16_t;
struct linger
{
  int l_onoff;
  int l_linger;
};
struct osockaddr
{
  unsigned short int sa_family;
  unsigned char sa_data[14];
};
enum
{
  SHUT_RD = 0,
  SHUT_WR,
  SHUT_RDWR
};
typedef union
{
  struct sockaddr *__restrict __sockaddr__;
  struct sockaddr_at *__restrict __sockaddr_at__;
  struct sockaddr_ax25 *__restrict __sockaddr_ax25__;
  struct sockaddr_dl *__restrict __sockaddr_dl__;
  struct sockaddr_eon *__restrict __sockaddr_eon__;
  struct sockaddr_in *__restrict __sockaddr_in__;
  struct sockaddr_in6 *__restrict __sockaddr_in6__;
  struct sockaddr_inarp *__restrict __sockaddr_inarp__;
  struct sockaddr_ipx *__restrict __sockaddr_ipx__;
  struct sockaddr_iso *__restrict __sockaddr_iso__;
  struct sockaddr_ns *__restrict __sockaddr_ns__;
  struct sockaddr_un *__restrict __sockaddr_un__;
  struct sockaddr_x25 *__restrict __sockaddr_x25__;
} __SOCKADDR_ARG __attribute__((__transparent_union__));
typedef union
{
  const struct sockaddr *__restrict __sockaddr__;
  const struct sockaddr_at *__restrict __sockaddr_at__;
  const struct sockaddr_ax25 *__restrict __sockaddr_ax25__;
  const struct sockaddr_dl *__restrict __sockaddr_dl__;
  const struct sockaddr_eon *__restrict __sockaddr_eon__;
  const struct sockaddr_in *__restrict __sockaddr_in__;
  const struct sockaddr_in6 *__restrict __sockaddr_in6__;
  const struct sockaddr_inarp *__restrict __sockaddr_inarp__;
  const struct sockaddr_ipx *__restrict __sockaddr_ipx__;
  const struct sockaddr_iso *__restrict __sockaddr_iso__;
  const struct sockaddr_ns *__restrict __sockaddr_ns__;
  const struct sockaddr_un *__restrict __sockaddr_un__;
  const struct sockaddr_x25 *__restrict __sockaddr_x25__;
} __CONST_SOCKADDR_ARG __attribute__((__transparent_union__));
struct mmsghdr
{
  struct msghdr msg_hdr;
  unsigned int msg_len;
};
extern int socket(int __domain, int __type, int __protocol)
    __attribute__((__nothrow__, __leaf__));
extern int socketpair(int __domain, int __type, int __protocol,
                      int __fds[2]) __attribute__((__nothrow__, __leaf__));
extern int bind(int __fd, __CONST_SOCKADDR_ARG __addr, socklen_t __len)
    __attribute__((__nothrow__, __leaf__));
extern int getsockname(int __fd, __SOCKADDR_ARG __addr,
                       socklen_t *__restrict __len)
    __attribute__((__nothrow__, __leaf__));
extern int connect(int __fd, __CONST_SOCKADDR_ARG __addr, socklen_t __len);
extern int getpeername(int __fd, __SOCKADDR_ARG __addr,
                       socklen_t *__restrict __len)
    __attribute__((__nothrow__, __leaf__));
extern ssize_t send(int __fd, const void *__buf, size_t __n, int __flags);
extern ssize_t recv(int __fd, void *__buf, size_t __n, int __flags);
extern ssize_t sendto(int __fd, const void *__buf, size_t __n,
                      int __flags, __CONST_SOCKADDR_ARG __addr,
                      socklen_t __addr_len);
extern ssize_t recvfrom(int __fd, void *__restrict __buf, size_t __n,
                        int __flags, __SOCKADDR_ARG __addr,
                        socklen_t *__restrict __addr_len);
extern ssize_t sendmsg(int __fd, const struct msghdr *__message,
                       int __flags);
extern int sendmmsg(int __fd, struct mmsghdr *__vmessages,
                    unsigned int __vlen, int __flags);
extern ssize_t recvmsg(int __fd, struct msghdr *__message, int __flags);
extern int recvmmsg(int __fd, struct mmsghdr *__vmessages,
                    unsigned int __vlen, int __flags,
                    struct timespec *__tmo);
extern int getsockopt(int __fd, int __level, int __optname,
                      void *__restrict __optval,
                      socklen_t *__restrict __optlen)
    __attribute__((__nothrow__, __leaf__));
extern int setsockopt(int __fd, int __level, int __optname,
                      const void *__optval, socklen_t __optlen)
    __attribute__((__nothrow__, __leaf__));
extern int listen(int __fd, int __n) __attribute__((__nothrow__, __leaf__));
extern int accept(int __fd, __SOCKADDR_ARG __addr,
                  socklen_t *__restrict __addr_len);
extern int accept4(int __fd, __SOCKADDR_ARG __addr,
                   socklen_t *__restrict __addr_len, int __flags);
extern int shutdown(int __fd, int __how)
    __attribute__((__nothrow__, __leaf__));
extern int sockatmark(int __fd) __attribute__((__nothrow__, __leaf__));
extern int isfdtype(int __fd, int __fdtype)
    __attribute__((__nothrow__, __leaf__));
typedef uint32_t in_addr_t;
struct in_addr
{
  in_addr_t s_addr;
};
struct ip_opts
{
  struct in_addr ip_dst;
  char ip_opts[40];
};
struct in_pktinfo
{
  int ipi_ifindex;
  struct in_addr ipi_spec_dst;
  struct in_addr ipi_addr;
};
enum
{
  IPPROTO_IP = 0,
  IPPROTO_ICMP = 1,
  IPPROTO_IGMP = 2,
  IPPROTO_IPIP = 4,
  IPPROTO_TCP = 6,
  IPPROTO_EGP = 8,
  IPPROTO_PUP = 12,
  IPPROTO_UDP = 17,
  IPPROTO_IDP = 22,
  IPPROTO_TP = 29,
  IPPROTO_DCCP = 33,
  IPPROTO_IPV6 = 41,
  IPPROTO_RSVP = 46,
  IPPROTO_GRE = 47,
  IPPROTO_ESP = 50,
  IPPROTO_AH = 51,
  IPPROTO_MTP = 92,
  IPPROTO_BEETPH = 94,
  IPPROTO_ENCAP = 98,
  IPPROTO_PIM = 103,
  IPPROTO_COMP = 108,
  IPPROTO_L2TP = 115,
  IPPROTO_SCTP = 132,
  IPPROTO_UDPLITE = 136,
  IPPROTO_MPLS = 137,
  IPPROTO_ETHERNET = 143,
  IPPROTO_RAW = 255,
  IPPROTO_MPTCP = 262,
  IPPROTO_MAX
};
enum
{
  IPPROTO_HOPOPTS = 0,
  IPPROTO_ROUTING = 43,
  IPPROTO_FRAGMENT = 44,
  IPPROTO_ICMPV6 = 58,
  IPPROTO_NONE = 59,
  IPPROTO_DSTOPTS = 60,
  IPPROTO_MH = 135
};
typedef uint16_t in_port_t;
enum
{
  IPPORT_ECHO = 7,
  IPPORT_DISCARD = 9,
  IPPORT_SYSTAT = 11,
  IPPORT_DAYTIME = 13,
  IPPORT_NETSTAT = 15,
  IPPORT_FTP = 21,
  IPPORT_TELNET = 23,
  IPPORT_SMTP = 25,
  IPPORT_TIMESERVER = 37,
  IPPORT_NAMESERVER = 42,
  IPPORT_WHOIS = 43,
  IPPORT_MTP = 57,
  IPPORT_TFTP = 69,
  IPPORT_RJE = 77,
  IPPORT_FINGER = 79,
  IPPORT_TTYLINK = 87,
  IPPORT_SUPDUP = 95,
  IPPORT_EXECSERVER = 512,
  IPPORT_LOGINSERVER = 513,
  IPPORT_CMDSERVER = 514,
  IPPORT_EFSSERVER = 520,
  IPPORT_BIFFUDP = 512,
  IPPORT_WHOSERVER = 513,
  IPPORT_ROUTESERVER = 520,
  IPPORT_RESERVED = 1024,
  IPPORT_USERRESERVED = 5000
};
struct in6_addr
{
  union
  {
    uint8_t __u6_addr8[16];
    uint16_t __u6_addr16[8];
    uint32_t __u6_addr32[4];
  } __in6_u;
};
extern const struct in6_addr in6addr_any;
extern const struct in6_addr in6addr_loopback;
struct sockaddr_in
{
  sa_family_t sin_family;
  in_port_t sin_port;
  struct in_addr sin_addr;
  unsigned char sin_zero[sizeof(struct sockaddr) - (sizeof(unsigned short int)) - sizeof(in_port_t) - sizeof(struct in_addr)];
};
struct sockaddr_in6
{
  sa_family_t sin6_family;
  in_port_t sin6_port;
  uint32_t sin6_flowinfo;
  struct in6_addr sin6_addr;
  uint32_t sin6_scope_id;
};
struct ip_mreq
{
  struct in_addr imr_multiaddr;
  struct in_addr imr_interface;
};
struct ip_mreqn
{
  struct in_addr imr_multiaddr;
  struct in_addr imr_address;
  int imr_ifindex;
};
struct ip_mreq_source
{
  struct in_addr imr_multiaddr;
  struct in_addr imr_interface;
  struct in_addr imr_sourceaddr;
};
struct ipv6_mreq
{
  struct in6_addr ipv6mr_multiaddr;
  unsigned int ipv6mr_interface;
};
struct group_req
{
  uint32_t gr_interface;
  struct sockaddr_storage gr_group;
};
struct group_source_req
{
  uint32_t gsr_interface;
  struct sockaddr_storage gsr_group;
  struct sockaddr_storage gsr_source;
};
struct ip_msfilter
{
  struct in_addr imsf_multiaddr;
  struct in_addr imsf_interface;
  uint32_t imsf_fmode;
  uint32_t imsf_numsrc;
  struct in_addr imsf_slist[1];
};
struct group_filter
{
  uint32_t gf_interface;
  struct sockaddr_storage gf_group;
  uint32_t gf_fmode;
  uint32_t gf_numsrc;
  struct sockaddr_storage gf_slist[1];
};
extern uint32_t ntohl(uint32_t __netlong)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern uint16_t ntohs(uint16_t __netshort)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern uint32_t htonl(uint32_t __hostlong)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern uint16_t htons(uint16_t __hostshort)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern int bindresvport(int __sockfd, struct sockaddr_in *__sock_in)
    __attribute__((__nothrow__, __leaf__));
extern int bindresvport6(int __sockfd, struct sockaddr_in6 *__sock_in)
    __attribute__((__nothrow__, __leaf__));
struct cmsghdr;
struct in6_pktinfo
{
  struct in6_addr ipi6_addr;
  unsigned int ipi6_ifindex;
};
struct ip6_mtuinfo
{
  struct sockaddr_in6 ip6m_addr;
  uint32_t ip6m_mtu;
};
extern int inet6_option_space(int __nbytes)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__deprecated__));
extern int inet6_option_init(void *__bp, struct cmsghdr **__cmsgp,
                             int __type)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__deprecated__));
extern int inet6_option_append(struct cmsghdr *__cmsg,
                               const uint8_t *__typep, int __multx,
                               int __plusy)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__deprecated__));
extern uint8_t *inet6_option_alloc(struct cmsghdr *__cmsg, int __datalen,
                                   int __multx, int __plusy)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__deprecated__));
extern int inet6_option_next(const struct cmsghdr *__cmsg,
                             uint8_t **__tptrp)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__deprecated__));
extern int inet6_option_find(const struct cmsghdr *__cmsg,
                             uint8_t **__tptrp, int __type)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__deprecated__));
extern int inet6_opt_init(void *__extbuf, socklen_t __extlen)
    __attribute__((__nothrow__, __leaf__));
extern int inet6_opt_append(void *__extbuf, socklen_t __extlen, int __offset,
                            uint8_t __type, socklen_t __len, uint8_t __align,
                            void **__databufp)
    __attribute__((__nothrow__, __leaf__));
extern int inet6_opt_finish(void *__extbuf, socklen_t __extlen, int __offset)
    __attribute__((__nothrow__, __leaf__));
extern int inet6_opt_set_val(void *__databuf, int __offset, void *__val,
                             socklen_t __vallen)
    __attribute__((__nothrow__, __leaf__));
extern int inet6_opt_next(void *__extbuf, socklen_t __extlen, int __offset,
                          uint8_t *__typep, socklen_t *__lenp,
                          void **__databufp)
    __attribute__((__nothrow__, __leaf__));
extern int inet6_opt_find(void *__extbuf, socklen_t __extlen, int __offset,
                          uint8_t __type, socklen_t *__lenp,
                          void **__databufp)
    __attribute__((__nothrow__, __leaf__));
extern int inet6_opt_get_val(void *__databuf, int __offset, void *__val,
                             socklen_t __vallen)
    __attribute__((__nothrow__, __leaf__));
extern socklen_t inet6_rth_space(int __type, int __segments)
    __attribute__((__nothrow__, __leaf__));
extern void *inet6_rth_init(void *__bp, socklen_t __bp_len, int __type,
                            int __segments)
    __attribute__((__nothrow__, __leaf__));
extern int inet6_rth_add(void *__bp, const struct in6_addr *__addr)
    __attribute__((__nothrow__, __leaf__));
extern int inet6_rth_reverse(const void *__in, void *__out)
    __attribute__((__nothrow__, __leaf__));
extern int inet6_rth_segments(const void *__bp)
    __attribute__((__nothrow__, __leaf__));
extern struct in6_addr *inet6_rth_getaddr(const void *__bp, int __index)
    __attribute__((__nothrow__, __leaf__));
extern int getipv4sourcefilter(int __s, struct in_addr __interface_addr,
                               struct in_addr __group, uint32_t *__fmode,
                               uint32_t *__numsrc, struct in_addr *__slist)
    __attribute__((__nothrow__, __leaf__));
extern int setipv4sourcefilter(int __s, struct in_addr __interface_addr,
                               struct in_addr __group, uint32_t __fmode,
                               uint32_t __numsrc,
                               const struct in_addr *__slist)
    __attribute__((__nothrow__, __leaf__));
extern int getsourcefilter(int __s, uint32_t __interface_addr,
                           const struct sockaddr *__group,
                           socklen_t __grouplen, uint32_t *__fmode,
                           uint32_t *__numsrc,
                           struct sockaddr_storage *__slist)
    __attribute__((__nothrow__, __leaf__));
extern int setsourcefilter(int __s, uint32_t __interface_addr,
                           const struct sockaddr *__group,
                           socklen_t __grouplen, uint32_t __fmode,
                           uint32_t __numsrc,
                           const struct sockaddr_storage *__slist)
    __attribute__((__nothrow__, __leaf__));
extern in_addr_t inet_addr(const char *__cp)
    __attribute__((__nothrow__, __leaf__));
extern in_addr_t inet_lnaof(struct in_addr __in)
    __attribute__((__nothrow__, __leaf__));
extern struct in_addr inet_makeaddr(in_addr_t __net, in_addr_t __host)
    __attribute__((__nothrow__, __leaf__));
extern in_addr_t inet_netof(struct in_addr __in)
    __attribute__((__nothrow__, __leaf__));
extern in_addr_t inet_network(const char *__cp)
    __attribute__((__nothrow__, __leaf__));
extern char *inet_ntoa(struct in_addr __in)
    __attribute__((__nothrow__, __leaf__));
extern int inet_pton(int __af, const char *__restrict __cp,
                     void *__restrict __buf)
    __attribute__((__nothrow__, __leaf__));
extern const char *inet_ntop(int __af, const void *__restrict __cp,
                             char *__restrict __buf, socklen_t __len)
    __attribute__((__nothrow__, __leaf__));
extern int inet_aton(const char *__cp, struct in_addr *__inp)
    __attribute__((__nothrow__, __leaf__));
extern char *inet_neta(in_addr_t __net, char *__buf, size_t __len)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__deprecated__("Use inet_ntop instead")));
extern char *inet_net_ntop(int __af, const void *__cp, int __bits,
                           char *__buf, size_t __len)
    __attribute__((__nothrow__, __leaf__));
extern int inet_net_pton(int __af, const char *__cp,
                         void *__buf, size_t __len)
    __attribute__((__nothrow__, __leaf__));
extern unsigned int inet_nsap_addr(const char *__cp,
                                   unsigned char *__buf, int __len)
    __attribute__((__nothrow__, __leaf__));
extern char *inet_nsap_ntoa(int __len, const unsigned char *__cp,
                            char *__buf)
    __attribute__((__nothrow__, __leaf__));
struct timestamp
{
  uint8_t len;
  uint8_t ptr;
  unsigned int flags : 4;
  unsigned int overflow : 4;
  uint32_t data[9];
};
struct iphdr
{
  unsigned int ihl : 4;
  unsigned int version : 4;
  uint8_t tos;
  uint16_t tot_len;
  uint16_t id;
  uint16_t frag_off;
  uint8_t ttl;
  uint8_t protocol;
  uint16_t check;
  uint32_t saddr;
  uint32_t daddr;
};
struct ip
{
  unsigned int ip_hl : 4;
  unsigned int ip_v : 4;
  uint8_t ip_tos;
  unsigned short ip_len;
  unsigned short ip_id;
  unsigned short ip_off;
  uint8_t ip_ttl;
  uint8_t ip_p;
  unsigned short ip_sum;
  struct in_addr ip_src, ip_dst;
};
struct ip_timestamp
{
  uint8_t ipt_code;
  uint8_t ipt_len;
  uint8_t ipt_ptr;
  unsigned int ipt_flg : 4;
  unsigned int ipt_oflw : 4;
  uint32_t data[9];
};
struct ip6_hdr
{
  union
  {
    struct ip6_hdrctl
    {
      uint32_t ip6_un1_flow;
      uint16_t ip6_un1_plen;
      uint8_t ip6_un1_nxt;
      uint8_t ip6_un1_hlim;
    } ip6_un1;
    uint8_t ip6_un2_vfc;
  } ip6_ctlun;
  struct in6_addr ip6_src;
  struct in6_addr ip6_dst;
};
struct ip6_ext
{
  uint8_t ip6e_nxt;
  uint8_t ip6e_len;
};
struct ip6_hbh
{
  uint8_t ip6h_nxt;
  uint8_t ip6h_len;
};
struct ip6_dest
{
  uint8_t ip6d_nxt;
  uint8_t ip6d_len;
};
struct ip6_rthdr
{
  uint8_t ip6r_nxt;
  uint8_t ip6r_len;
  uint8_t ip6r_type;
  uint8_t ip6r_segleft;
};
struct ip6_rthdr0
{
  uint8_t ip6r0_nxt;
  uint8_t ip6r0_len;
  uint8_t ip6r0_type;
  uint8_t ip6r0_segleft;
  uint8_t ip6r0_reserved;
  uint8_t ip6r0_slmap[3];
  struct in6_addr ip6r0_addr[0];
};
struct ip6_frag
{
  uint8_t ip6f_nxt;
  uint8_t ip6f_reserved;
  uint16_t ip6f_offlg;
  uint32_t ip6f_ident;
};
struct ip6_opt
{
  uint8_t ip6o_type;
  uint8_t ip6o_len;
};
struct ip6_opt_jumbo
{
  uint8_t ip6oj_type;
  uint8_t ip6oj_len;
  uint8_t ip6oj_jumbo_len[4];
};
struct ip6_opt_nsap
{
  uint8_t ip6on_type;
  uint8_t ip6on_len;
  uint8_t ip6on_src_nsap_len;
  uint8_t ip6on_dst_nsap_len;
};
struct ip6_opt_tunnel
{
  uint8_t ip6ot_type;
  uint8_t ip6ot_len;
  uint8_t ip6ot_encap_limit;
};
struct ip6_opt_router
{
  uint8_t ip6or_type;
  uint8_t ip6or_len;
  uint8_t ip6or_value[2];
};
struct rte_ipv4_hdr
{
  __extension__ union
  {
    uint8_t version_ihl;
    struct
    {
      uint8_t ihl : 4;
      uint8_t version : 4;
    };
  };
  uint8_t type_of_service;
  rte_be16_t total_length;
  rte_be16_t packet_id;
  rte_be16_t fragment_offset;
  uint8_t time_to_live;
  uint8_t next_proto_id;
  rte_be16_t hdr_checksum;
  rte_be32_t src_addr;
  rte_be32_t dst_addr;
} __attribute__((__packed__));
static inline uint8_t
rte_ipv4_hdr_len(const struct rte_ipv4_hdr *ipv4_hdr)
{
  return (uint8_t)((ipv4_hdr->version_ihl & (0x0f)) * (4));
}

static inline uint32_t
__rte_raw_cksum(const void *buf, size_t len, uint32_t sum)
{
  const void *end;
  for (end =
           ((void *)((uintptr_t)(buf) +
                     ((__typeof__(len))((len) &
                                        (~((__typeof__(len))((sizeof(uint16_t)) - 1)))))));
       buf != end; buf = ((void *)((uintptr_t)(buf) + (sizeof(uint16_t)))))
  {
    uint16_t v;
    memcpy(&v, buf, sizeof(uint16_t));
    sum += v;
  }
  if (__builtin_expect(!!(len % 2), 0))
  {
    uint16_t left = 0;
    memcpy(&left, end, 1);
    sum += left;
  }
  return sum;
}

static inline uint16_t
__rte_raw_cksum_reduce(uint32_t sum)
{
  sum = ((sum & 0xffff0000) >> 16) + (sum & 0xffff);
  sum = ((sum & 0xffff0000) >> 16) + (sum & 0xffff);
  return (uint16_t)sum;
}

static inline uint16_t
rte_raw_cksum(const void *buf, size_t len)
{
  uint32_t sum;
  sum = __rte_raw_cksum(buf, len, 0);
  return __rte_raw_cksum_reduce(sum);
}

static inline int
rte_raw_cksum_mbuf(const struct rte_mbuf *m, uint32_t off, uint32_t len,
                   uint16_t *cksum)
{
  const struct rte_mbuf *seg;
  const char *buf;
  uint32_t sum, tmp;
  uint32_t seglen, done;
  if (off + len <= ((m)->data_len))
  {
    *cksum =
        rte_raw_cksum(((const char *)(void *)((char *)(m)->buf_addr +
                                              (m)->data_off + (off))),
                      len);
    return 0;
  }
  if (__builtin_expect(!!(off + len > ((m)->pkt_len)), 0))
    return -1;
  seglen = 0;
  for (seg = m; seg != ((void *)0); seg = seg->next)
  {
    seglen = ((seg)->data_len);
    if (off < seglen)
      break;
    off -= seglen;
  }
  do
  {
  } while (0);
  if (seg == ((void *)0))
    return -1;
  seglen -= off;
  buf =
      ((const char *)(void *)((char *)(seg)->buf_addr + (seg)->data_off +
                              (off)));
  if (seglen >= len)
  {
    *cksum = rte_raw_cksum(buf, len);
    return 0;
  }
  sum = 0;
  done = 0;
  for (;;)
  {
    tmp = __rte_raw_cksum(buf, seglen, 0);
    if (done & 1)
      tmp = __builtin_bswap16((uint16_t)tmp);
    sum += tmp;
    done += seglen;
    if (done == len)
      break;
    seg = seg->next;
    buf =
        ((const char *)(void *)((char *)(seg)->buf_addr + (seg)->data_off +
                                (0)));
    seglen = ((seg)->data_len);
    if (seglen > len - done)
      seglen = len - done;
  }
  *cksum = __rte_raw_cksum_reduce(sum);
  return 0;
}

static inline uint16_t
rte_ipv4_cksum(const struct rte_ipv4_hdr *ipv4_hdr)
{
  uint16_t cksum;
  cksum = rte_raw_cksum(ipv4_hdr, rte_ipv4_hdr_len(ipv4_hdr));
  return (uint16_t)~cksum;
}

static inline uint16_t
rte_ipv4_phdr_cksum(const struct rte_ipv4_hdr *ipv4_hdr, uint64_t ol_flags)
{
  struct ipv4_psd_header
  {
    uint32_t src_addr;
    uint32_t dst_addr;
    uint8_t zero;
    uint8_t proto;
    uint16_t len;
  } psd_hdr;
  uint32_t l3_len;
  psd_hdr.src_addr = ipv4_hdr->src_addr;
  psd_hdr.dst_addr = ipv4_hdr->dst_addr;
  psd_hdr.zero = 0;
  psd_hdr.proto = ipv4_hdr->next_proto_id;
  if (ol_flags & ((1ULL << 50) | (1ULL << 42)))
  {
    psd_hdr.len = 0;
  }
  else
  {
    l3_len = __builtin_bswap16(ipv4_hdr->total_length);
    psd_hdr.len =
        __builtin_bswap16((uint16_t)(l3_len - rte_ipv4_hdr_len(ipv4_hdr)));
  }
  return rte_raw_cksum(&psd_hdr, sizeof(psd_hdr));
}

static inline uint16_t
__rte_ipv4_udptcp_cksum(const struct rte_ipv4_hdr *ipv4_hdr,
                        const void *l4_hdr)
{
  uint32_t cksum;
  uint32_t l3_len, l4_len;
  uint8_t ip_hdr_len;
  ip_hdr_len = rte_ipv4_hdr_len(ipv4_hdr);
  l3_len = __builtin_bswap16(ipv4_hdr->total_length);
  if (l3_len < ip_hdr_len)
    return 0;
  l4_len = l3_len - ip_hdr_len;
  cksum = rte_raw_cksum(l4_hdr, l4_len);
  cksum += rte_ipv4_phdr_cksum(ipv4_hdr, 0);
  cksum = ((cksum & 0xffff0000) >> 16) + (cksum & 0xffff);
  return (uint16_t)cksum;
}

static inline uint16_t
rte_ipv4_udptcp_cksum(const struct rte_ipv4_hdr *ipv4_hdr,
                      const void *l4_hdr)
{
  uint16_t cksum = __rte_ipv4_udptcp_cksum(ipv4_hdr, l4_hdr);
  cksum = ~cksum;
  if (cksum == 0 && ipv4_hdr->next_proto_id == IPPROTO_UDP)
    cksum = 0xffff;
  return cksum;
}

static inline uint16_t
__rte_ipv4_udptcp_cksum_mbuf(const struct rte_mbuf *m,
                             const struct rte_ipv4_hdr *ipv4_hdr,
                             uint16_t l4_off)
{
  uint16_t raw_cksum;
  uint32_t cksum;
  uint16_t len;
  if (__builtin_expect(!!(l4_off > m->pkt_len), 0))
    return 0;
  len =
      __builtin_bswap16(ipv4_hdr->total_length) -
      (uint16_t)rte_ipv4_hdr_len(ipv4_hdr);
  if (rte_raw_cksum_mbuf(m, l4_off, len, &raw_cksum))
    return 0;
  cksum = raw_cksum + rte_ipv4_phdr_cksum(ipv4_hdr, 0);
  cksum = ((cksum & 0xffff0000) >> 16) + (cksum & 0xffff);
  return (uint16_t)cksum;
}

static inline uint16_t
rte_ipv4_udptcp_cksum_mbuf(const struct rte_mbuf *m,
                           const struct rte_ipv4_hdr *ipv4_hdr,
                           uint16_t l4_off)
{
  uint16_t cksum = __rte_ipv4_udptcp_cksum_mbuf(m, ipv4_hdr, l4_off);
  cksum = ~cksum;
  if (cksum == 0 && ipv4_hdr->next_proto_id == IPPROTO_UDP)
    cksum = 0xffff;
  return cksum;
}

static inline int
rte_ipv4_udptcp_cksum_verify(const struct rte_ipv4_hdr *ipv4_hdr,
                             const void *l4_hdr)
{
  uint16_t cksum = __rte_ipv4_udptcp_cksum(ipv4_hdr, l4_hdr);
  if (cksum != 0xffff)
    return -1;
  return 0;
}

static inline int
rte_ipv4_udptcp_cksum_mbuf_verify(const struct rte_mbuf *m,
                                  const struct rte_ipv4_hdr *ipv4_hdr,
                                  uint16_t l4_off)
{
  uint16_t cksum = __rte_ipv4_udptcp_cksum_mbuf(m, ipv4_hdr, l4_off);
  if (cksum != 0xffff)
    return -1;
  return 0;
}

struct rte_ipv6_hdr
{
  rte_be32_t vtc_flow;
  rte_be16_t payload_len;
  uint8_t proto;
  uint8_t hop_limits;
  uint8_t src_addr[16];
  uint8_t dst_addr[16];
} __attribute__((__packed__));
struct rte_ipv6_routing_ext
{
  uint8_t next_hdr;
  uint8_t hdr_len;
  uint8_t type;
  uint8_t segments_left;
  __extension__ union
  {
    rte_be32_t flags;
    struct
    {
      uint8_t last_entry;
      uint8_t flag;
      rte_be16_t tag;
    };
  };
} __attribute__((__packed__));
static inline uint16_t
rte_ipv6_phdr_cksum(const struct rte_ipv6_hdr *ipv6_hdr, uint64_t ol_flags)
{
  uint32_t sum;
  struct
  {
    rte_be32_t len;
    rte_be32_t proto;
  } psd_hdr;
  psd_hdr.proto = (uint32_t)(ipv6_hdr->proto << 24);
  if (ol_flags & ((1ULL << 50) | (1ULL << 42)))
  {
    psd_hdr.len = 0;
  }
  else
  {
    psd_hdr.len = ipv6_hdr->payload_len;
  }
  sum = __rte_raw_cksum(ipv6_hdr->src_addr,
                        sizeof(ipv6_hdr->src_addr) +
                            sizeof(ipv6_hdr->dst_addr),
                        0);
  sum = __rte_raw_cksum(&psd_hdr, sizeof(psd_hdr), sum);
  return __rte_raw_cksum_reduce(sum);
}

static inline uint16_t
__rte_ipv6_udptcp_cksum(const struct rte_ipv6_hdr *ipv6_hdr,
                        const void *l4_hdr)
{
  uint32_t cksum;
  uint32_t l4_len;
  l4_len = __builtin_bswap16(ipv6_hdr->payload_len);
  cksum = rte_raw_cksum(l4_hdr, l4_len);
  cksum += rte_ipv6_phdr_cksum(ipv6_hdr, 0);
  cksum = ((cksum & 0xffff0000) >> 16) + (cksum & 0xffff);
  return (uint16_t)cksum;
}

static inline uint16_t
rte_ipv6_udptcp_cksum(const struct rte_ipv6_hdr *ipv6_hdr,
                      const void *l4_hdr)
{
  uint16_t cksum = __rte_ipv6_udptcp_cksum(ipv6_hdr, l4_hdr);
  cksum = ~cksum;
  if (cksum == 0 && ipv6_hdr->proto == IPPROTO_UDP)
    cksum = 0xffff;
  return cksum;
}

static inline uint16_t
__rte_ipv6_udptcp_cksum_mbuf(const struct rte_mbuf *m,
                             const struct rte_ipv6_hdr *ipv6_hdr,
                             uint16_t l4_off)
{
  uint16_t raw_cksum;
  uint32_t cksum;
  if (__builtin_expect(!!(l4_off > m->pkt_len), 0))
    return 0;
  if (rte_raw_cksum_mbuf(m, l4_off, __builtin_bswap16(ipv6_hdr->payload_len), &raw_cksum))
    return 0;
  cksum = raw_cksum + rte_ipv6_phdr_cksum(ipv6_hdr, 0);
  cksum = ((cksum & 0xffff0000) >> 16) + (cksum & 0xffff);
  return (uint16_t)cksum;
}

static inline uint16_t
rte_ipv6_udptcp_cksum_mbuf(const struct rte_mbuf *m,
                           const struct rte_ipv6_hdr *ipv6_hdr,
                           uint16_t l4_off)
{
  uint16_t cksum = __rte_ipv6_udptcp_cksum_mbuf(m, ipv6_hdr, l4_off);
  cksum = ~cksum;
  if (cksum == 0 && ipv6_hdr->proto == IPPROTO_UDP)
    cksum = 0xffff;
  return cksum;
}

static inline int
rte_ipv6_udptcp_cksum_verify(const struct rte_ipv6_hdr *ipv6_hdr,
                             const void *l4_hdr)
{
  uint16_t cksum = __rte_ipv6_udptcp_cksum(ipv6_hdr, l4_hdr);
  if (cksum != 0xffff)
    return -1;
  return 0;
}

static inline int
rte_ipv6_udptcp_cksum_mbuf_verify(const struct rte_mbuf *m,
                                  const struct rte_ipv6_hdr *ipv6_hdr,
                                  uint16_t l4_off)
{
  uint16_t cksum = __rte_ipv6_udptcp_cksum_mbuf(m, ipv6_hdr, l4_off);
  if (cksum != 0xffff)
    return -1;
  return 0;
}

struct rte_ipv6_fragment_ext
{
  uint8_t next_header;
  uint8_t reserved;
  rte_be16_t frag_data;
  rte_be32_t id;
} __attribute__((__packed__));
static inline int
rte_ipv6_get_next_ext(const uint8_t *p, int proto, size_t *ext_len)
{
  int next_proto;
  switch (proto)
  {
  case IPPROTO_AH:
    next_proto = *p++;
    *ext_len = (*p + 2) * sizeof(uint32_t);
    break;
  case IPPROTO_HOPOPTS:
  case IPPROTO_ROUTING:
  case IPPROTO_DSTOPTS:
    next_proto = *p++;
    *ext_len = (*p + 1) * sizeof(uint64_t);
    break;
  case IPPROTO_FRAGMENT:
    next_proto = *p;
    *ext_len = sizeof(struct rte_ipv6_fragment_ext);
    break;
  default:
    return -22;
  }
  return next_proto;
}

struct rte_sctp_hdr
{
  rte_be16_t src_port;
  rte_be16_t dst_port;
  rte_be32_t tag;
  rte_be32_t cksum;
} __attribute__((__packed__));
struct rte_tcp_hdr
{
  rte_be16_t src_port;
  rte_be16_t dst_port;
  rte_be32_t sent_seq;
  rte_be32_t recv_ack;
  uint8_t data_off;
  uint8_t tcp_flags;
  rte_be16_t rx_win;
  rte_be16_t cksum;
  rte_be16_t tcp_urp;
} __attribute__((__packed__));
struct rte_udp_hdr
{
  rte_be16_t src_port;
  rte_be16_t dst_port;
  rte_be16_t dgram_len;
  rte_be16_t dgram_cksum;
} __attribute__((__packed__));
__extension__ struct rte_vxlan_hdr
{
  union
  {
    rte_be32_t vx_flags;
    struct
    {
      union
      {
        uint8_t flags;
        struct
        {
          uint8_t flag_o : 1,
              flag_b : 1, flag_p : 1, flag_i : 1, flag_ver : 2, flag_rsvd : 1, flag_g : 1;
        } __attribute__((__packed__));
      };
      union
      {
        uint8_t rsvd0[3];
        struct
        {
          uint8_t rsvd0_gbp3 : 3,
              flag_a : 1, rsvd0_gbp2 : 2, flag_d : 1, rsvd0_gbp1 : 1;
          union
          {
            uint16_t policy_id;
            struct
            {
              uint8_t rsvd0_gpe;
              uint8_t proto;
            } __attribute__((__packed__));
          };
        } __attribute__((__packed__));
      };
    } __attribute__((__packed__));
  };
  union
  {
    rte_be32_t vx_vni;
    struct
    {
      uint8_t vni[3];
      union
      {
        uint8_t rsvd1;
        uint8_t last_rsvd;
      };
    } __attribute__((__packed__));
  };
} __attribute__((__packed__));
__extension__ struct rte_vxlan_gpe_hdr
{
  union
  {
    struct
    {
      uint8_t vx_flags;
      uint8_t reserved[2];
      uint8_t protocol;
      rte_be32_t vx_vni;
    };
    struct
    {
      uint8_t flags;
      uint8_t rsvd0[2];
      uint8_t proto;
      uint8_t vni[3];
      uint8_t rsvd1;
    };
  };
} __attribute__((__packed__));
struct rte_esp_hdr
{
  rte_be32_t spi;
  rte_be32_t seq;
} __attribute__((__packed__));
struct rte_esp_tail
{
  uint8_t pad_len;
  uint8_t next_proto;
} __attribute__((__packed__));
struct rte_higig2_frc
{
  uint32_t ksop : 8;
  uint32_t tc : 4;
  uint32_t mcst : 1;
  uint32_t resv : 3;
  uint32_t dst_modid : 8;
  uint32_t dst_pid : 8;
  uint32_t src_modid : 8;
  uint32_t src_pid : 8;
  uint32_t lbid : 8;
  uint32_t ppd_type : 3;
  uint32_t resv1 : 3;
  uint32_t dp : 2;
};
struct rte_higig2_ppt_type0
{
  uint32_t mirror : 1;
  uint32_t mirror_done : 1;
  uint32_t mirror_only : 1;
  uint32_t ingress_tagged : 1;
  uint32_t dst_tgid : 3;
  uint32_t dst_t : 1;
  uint32_t vc_label2 : 4;
  uint32_t label_present : 1;
  uint32_t l3 : 1;
  uint32_t res : 2;
  uint32_t vc_label1 : 8;
  uint32_t vc_label0 : 8;
  uint32_t vid_high : 8;
  uint32_t vid_low : 8;
  uint32_t opc : 3;
  uint32_t res1 : 2;
  uint32_t srce_t : 1;
  uint32_t pf : 2;
  uint32_t res2 : 5;
  uint32_t hdr_ext_length : 3;
};
__extension__ struct rte_higig2_ppt_type1
{
  rte_be16_t classification;
  rte_be16_t resv;
  rte_be16_t vid;
  uint16_t opcode : 3;
  uint16_t resv1 : 2;
  uint16_t src_t : 1;
  uint16_t pfm : 2;
  uint16_t resv2 : 5;
  uint16_t hdr_ext_len : 3;
};
struct rte_higig2_hdr
{
  struct rte_higig2_frc fcr;
  union
  {
    struct rte_higig2_ppt_type0 ppt0;
    struct rte_higig2_ppt_type1 ppt1;
  };
};
struct rte_ecpri_common_hdr
{
  union
  {
    rte_be32_t u32;
    struct
    {
      uint32_t size : 16;
      uint32_t type : 8;
      uint32_t c : 1;
      uint32_t res : 3;
      uint32_t revision : 4;
    };
  };
};
struct rte_ecpri_msg_iq_data
{
  rte_be16_t pc_id;
  rte_be16_t seq_id;
};
struct rte_ecpri_msg_bit_seq
{
  rte_be16_t pc_id;
  rte_be16_t seq_id;
};
struct rte_ecpri_msg_rtc_ctrl
{
  rte_be16_t rtc_id;
  rte_be16_t seq_id;
};
struct rte_ecpri_msg_gen_data
{
  rte_be32_t pc_id;
  rte_be32_t seq_id;
};
struct rte_ecpri_msg_rm_access
{
  uint32_t ele_id : 16;
  uint32_t rr : 4;
  uint32_t rw : 4;
  uint32_t rma_id : 8;
  uint8_t addr[6];
  rte_be16_t length;
};
struct rte_ecpri_msg_delay_measure
{
  uint8_t msr_id;
  uint8_t act_type;
};
struct rte_ecpri_msg_remote_reset
{
  rte_be16_t rst_id;
  uint8_t rst_op;
};
struct rte_ecpri_msg_event_ind
{
  uint8_t evt_id;
  uint8_t evt_type;
  uint8_t seq;
  uint8_t number;
};
struct rte_ecpri_combined_msg_hdr
{
  struct rte_ecpri_common_hdr common;
  union
  {
    struct rte_ecpri_msg_iq_data type0;
    struct rte_ecpri_msg_bit_seq type1;
    struct rte_ecpri_msg_rtc_ctrl type2;
    struct rte_ecpri_msg_gen_data type3;
    struct rte_ecpri_msg_rm_access type4;
    struct rte_ecpri_msg_delay_measure type5;
    struct rte_ecpri_msg_remote_reset type6;
    struct rte_ecpri_msg_event_ind type7;
    rte_be32_t dummy[3];
  };
};
struct rte_mbuf_dynfield
{
  char name[64];
  size_t size;
  size_t align;
  unsigned int flags;
};
struct rte_mbuf_dynflag
{
  char name[64];
  unsigned int flags;
};
int rte_mbuf_dynfield_register(const struct rte_mbuf_dynfield *params);
int rte_mbuf_dynfield_register_offset(const struct rte_mbuf_dynfield *params,
                                      size_t offset);
int rte_mbuf_dynfield_lookup(const char *name,
                             struct rte_mbuf_dynfield *params);
int rte_mbuf_dynflag_register(const struct rte_mbuf_dynflag *params);
int rte_mbuf_dynflag_register_bitnum(const struct rte_mbuf_dynflag *params,
                                     unsigned int bitnum);
int rte_mbuf_dynflag_lookup(const char *name,
                            struct rte_mbuf_dynflag *params);
void rte_mbuf_dyn_dump(FILE *out);
typedef uint64_t rte_mbuf_timestamp_t;
int rte_mbuf_dyn_rx_timestamp_register(int *field_offset,
                                       uint64_t *rx_flag);
int rte_mbuf_dyn_tx_timestamp_register(int *field_offset,
                                       uint64_t *tx_flag);
enum rte_color
{
  RTE_COLOR_GREEN = 0,
  RTE_COLOR_YELLOW,
  RTE_COLOR_RED,
  RTE_COLORS
};
struct rte_meter_srtcm_params
{
  uint64_t cir;
  uint64_t cbs;
  uint64_t ebs;
};
struct rte_meter_trtcm_params
{
  uint64_t cir;
  uint64_t pir;
  uint64_t cbs;
  uint64_t pbs;
};
struct rte_meter_trtcm_rfc4115_params
{
  uint64_t cir;
  uint64_t eir;
  uint64_t cbs;
  uint64_t ebs;
};
struct rte_meter_srtcm_profile;
struct rte_meter_trtcm_profile;
struct rte_meter_trtcm_rfc4115_profile;
struct rte_meter_srtcm;
struct rte_meter_trtcm;
struct rte_meter_trtcm_rfc4115;
int rte_meter_srtcm_profile_config(struct rte_meter_srtcm_profile *p,
                                   struct rte_meter_srtcm_params *params);
int rte_meter_trtcm_profile_config(struct rte_meter_trtcm_profile *p,
                                   struct rte_meter_trtcm_params *params);
int rte_meter_trtcm_rfc4115_profile_config(struct rte_meter_trtcm_rfc4115_profile
                                               *p,
                                           struct rte_meter_trtcm_rfc4115_params
                                               *params);
int rte_meter_srtcm_config(struct rte_meter_srtcm *m,
                           struct rte_meter_srtcm_profile *p);
int rte_meter_trtcm_config(struct rte_meter_trtcm *m,
                           struct rte_meter_trtcm_profile *p);
int rte_meter_trtcm_rfc4115_config(struct rte_meter_trtcm_rfc4115 *m,
                                   struct rte_meter_trtcm_rfc4115_profile *p);
static inline enum rte_color
rte_meter_srtcm_color_blind_check(struct rte_meter_srtcm *m,
                                  struct rte_meter_srtcm_profile *p,
                                  uint64_t time, uint32_t pkt_len);
static inline enum rte_color
rte_meter_srtcm_color_aware_check(struct rte_meter_srtcm *m,
                                  struct rte_meter_srtcm_profile *p,
                                  uint64_t time,
                                  uint32_t pkt_len,
                                  enum rte_color pkt_color);
static inline enum rte_color
rte_meter_trtcm_color_blind_check(struct rte_meter_trtcm *m,
                                  struct rte_meter_trtcm_profile *p,
                                  uint64_t time, uint32_t pkt_len);
static inline enum rte_color
rte_meter_trtcm_color_aware_check(struct rte_meter_trtcm *m,
                                  struct rte_meter_trtcm_profile *p,
                                  uint64_t time,
                                  uint32_t pkt_len,
                                  enum rte_color pkt_color);
static inline enum rte_color
rte_meter_trtcm_rfc4115_color_blind_check(struct rte_meter_trtcm_rfc4115 *m,
                                          struct
                                          rte_meter_trtcm_rfc4115_profile *p,
                                          uint64_t time, uint32_t pkt_len);
static inline enum rte_color
rte_meter_trtcm_rfc4115_color_aware_check(struct rte_meter_trtcm_rfc4115 *m,
                                          struct
                                          rte_meter_trtcm_rfc4115_profile *p,
                                          uint64_t time, uint32_t pkt_len,
                                          enum rte_color pkt_color);
struct rte_meter_srtcm_profile
{
  uint64_t cbs;
  uint64_t ebs;
  uint64_t cir_period;
  uint64_t cir_bytes_per_period;
};
struct rte_meter_srtcm
{
  uint64_t time;
  uint64_t tc;
  uint64_t te;
};
struct rte_meter_trtcm_profile
{
  uint64_t cbs;
  uint64_t pbs;
  uint64_t cir_period;
  uint64_t cir_bytes_per_period;
  uint64_t pir_period;
  uint64_t pir_bytes_per_period;
};
struct rte_meter_trtcm
{
  uint64_t time_tc;
  uint64_t time_tp;
  uint64_t tc;
  uint64_t tp;
};
struct rte_meter_trtcm_rfc4115_profile
{
  uint64_t cbs;
  uint64_t ebs;
  uint64_t cir_period;
  uint64_t cir_bytes_per_period;
  uint64_t eir_period;
  uint64_t eir_bytes_per_period;
};
struct rte_meter_trtcm_rfc4115
{
  uint64_t time_tc;
  uint64_t time_te;
  uint64_t tc;
  uint64_t te;
};
static inline enum rte_color
rte_meter_srtcm_color_blind_check(struct rte_meter_srtcm *m,
                                  struct rte_meter_srtcm_profile *p,
                                  uint64_t time, uint32_t pkt_len)
{
  uint64_t time_diff, n_periods, tc, te;
  time_diff = time - m->time;
  n_periods = time_diff / p->cir_period;
  m->time += n_periods * p->cir_period;
  tc = m->tc + n_periods * p->cir_bytes_per_period;
  te = m->te;
  if (tc > p->cbs)
  {
    te += (tc - p->cbs);
    if (te > p->ebs)
      te = p->ebs;
    tc = p->cbs;
  }
  if (tc >= pkt_len)
  {
    m->tc = tc - pkt_len;
    m->te = te;
    return RTE_COLOR_GREEN;
  }
  if (te >= pkt_len)
  {
    m->tc = tc;
    m->te = te - pkt_len;
    return RTE_COLOR_YELLOW;
  }
  m->tc = tc;
  m->te = te;
  return RTE_COLOR_RED;
}

static inline enum rte_color
rte_meter_srtcm_color_aware_check(struct rte_meter_srtcm *m,
                                  struct rte_meter_srtcm_profile *p,
                                  uint64_t time,
                                  uint32_t pkt_len, enum rte_color pkt_color)
{
  uint64_t time_diff, n_periods, tc, te;
  time_diff = time - m->time;
  n_periods = time_diff / p->cir_period;
  m->time += n_periods * p->cir_period;
  tc = m->tc + n_periods * p->cir_bytes_per_period;
  te = m->te;
  if (tc > p->cbs)
  {
    te += (tc - p->cbs);
    if (te > p->ebs)
      te = p->ebs;
    tc = p->cbs;
  }
  if ((pkt_color == RTE_COLOR_GREEN) && (tc >= pkt_len))
  {
    m->tc = tc - pkt_len;
    m->te = te;
    return RTE_COLOR_GREEN;
  }
  if ((pkt_color != RTE_COLOR_RED) && (te >= pkt_len))
  {
    m->tc = tc;
    m->te = te - pkt_len;
    return RTE_COLOR_YELLOW;
  }
  m->tc = tc;
  m->te = te;
  return RTE_COLOR_RED;
}

static inline enum rte_color
rte_meter_trtcm_color_blind_check(struct rte_meter_trtcm *m,
                                  struct rte_meter_trtcm_profile *p,
                                  uint64_t time, uint32_t pkt_len)
{
  uint64_t time_diff_tc, time_diff_tp, n_periods_tc, n_periods_tp, tc, tp;
  time_diff_tc = time - m->time_tc;
  time_diff_tp = time - m->time_tp;
  n_periods_tc = time_diff_tc / p->cir_period;
  n_periods_tp = time_diff_tp / p->pir_period;
  m->time_tc += n_periods_tc * p->cir_period;
  m->time_tp += n_periods_tp * p->pir_period;
  tc = m->tc + n_periods_tc * p->cir_bytes_per_period;
  if (tc > p->cbs)
    tc = p->cbs;
  tp = m->tp + n_periods_tp * p->pir_bytes_per_period;
  if (tp > p->pbs)
    tp = p->pbs;
  if (tp < pkt_len)
  {
    m->tc = tc;
    m->tp = tp;
    return RTE_COLOR_RED;
  }
  if (tc < pkt_len)
  {
    m->tc = tc;
    m->tp = tp - pkt_len;
    return RTE_COLOR_YELLOW;
  }
  m->tc = tc - pkt_len;
  m->tp = tp - pkt_len;
  return RTE_COLOR_GREEN;
}

static inline enum rte_color
rte_meter_trtcm_color_aware_check(struct rte_meter_trtcm *m,
                                  struct rte_meter_trtcm_profile *p,
                                  uint64_t time,
                                  uint32_t pkt_len, enum rte_color pkt_color)
{
  uint64_t time_diff_tc, time_diff_tp, n_periods_tc, n_periods_tp, tc, tp;
  time_diff_tc = time - m->time_tc;
  time_diff_tp = time - m->time_tp;
  n_periods_tc = time_diff_tc / p->cir_period;
  n_periods_tp = time_diff_tp / p->pir_period;
  m->time_tc += n_periods_tc * p->cir_period;
  m->time_tp += n_periods_tp * p->pir_period;
  tc = m->tc + n_periods_tc * p->cir_bytes_per_period;
  if (tc > p->cbs)
    tc = p->cbs;
  tp = m->tp + n_periods_tp * p->pir_bytes_per_period;
  if (tp > p->pbs)
    tp = p->pbs;
  if ((pkt_color == RTE_COLOR_RED) || (tp < pkt_len))
  {
    m->tc = tc;
    m->tp = tp;
    return RTE_COLOR_RED;
  }
  if ((pkt_color == RTE_COLOR_YELLOW) || (tc < pkt_len))
  {
    m->tc = tc;
    m->tp = tp - pkt_len;
    return RTE_COLOR_YELLOW;
  }
  m->tc = tc - pkt_len;
  m->tp = tp - pkt_len;
  return RTE_COLOR_GREEN;
}

static inline enum rte_color
rte_meter_trtcm_rfc4115_color_blind_check(struct rte_meter_trtcm_rfc4115 *m,
                                          struct
                                          rte_meter_trtcm_rfc4115_profile *p,
                                          uint64_t time, uint32_t pkt_len)
{
  uint64_t time_diff_tc, time_diff_te, n_periods_tc, n_periods_te, tc, te;
  time_diff_tc = time - m->time_tc;
  time_diff_te = time - m->time_te;
  n_periods_tc = time_diff_tc / p->cir_period;
  n_periods_te = time_diff_te / p->eir_period;
  m->time_tc += n_periods_tc * p->cir_period;
  m->time_te += n_periods_te * p->eir_period;
  tc = m->tc + n_periods_tc * p->cir_bytes_per_period;
  if (tc > p->cbs)
    tc = p->cbs;
  te = m->te + n_periods_te * p->eir_bytes_per_period;
  if (te > p->ebs)
    te = p->ebs;
  if (tc >= pkt_len)
  {
    m->tc = tc - pkt_len;
    m->te = te;
    return RTE_COLOR_GREEN;
  }
  if (te >= pkt_len)
  {
    m->tc = tc;
    m->te = te - pkt_len;
    return RTE_COLOR_YELLOW;
  }
  m->tc = tc;
  m->te = te;
  return RTE_COLOR_RED;
}

static inline enum rte_color
rte_meter_trtcm_rfc4115_color_aware_check(struct rte_meter_trtcm_rfc4115 *m,
                                          struct
                                          rte_meter_trtcm_rfc4115_profile *p,
                                          uint64_t time, uint32_t pkt_len,
                                          enum rte_color pkt_color)
{
  uint64_t time_diff_tc, time_diff_te, n_periods_tc, n_periods_te, tc, te;
  time_diff_tc = time - m->time_tc;
  time_diff_te = time - m->time_te;
  n_periods_tc = time_diff_tc / p->cir_period;
  n_periods_te = time_diff_te / p->eir_period;
  m->time_tc += n_periods_tc * p->cir_period;
  m->time_te += n_periods_te * p->eir_period;
  tc = m->tc + n_periods_tc * p->cir_bytes_per_period;
  if (tc > p->cbs)
    tc = p->cbs;
  te = m->te + n_periods_te * p->eir_bytes_per_period;
  if (te > p->ebs)
    te = p->ebs;
  if ((pkt_color == RTE_COLOR_GREEN) && (tc >= pkt_len))
  {
    m->tc = tc - pkt_len;
    m->te = te;
    return RTE_COLOR_GREEN;
  }
  if ((pkt_color != RTE_COLOR_RED) && (te >= pkt_len))
  {
    m->tc = tc;
    m->te = te - pkt_len;
    return RTE_COLOR_YELLOW;
  }
  m->tc = tc;
  m->te = te;
  return RTE_COLOR_RED;
}

__extension__ struct rte_gtp_hdr
{
  union
  {
    uint8_t gtp_hdr_info;
    struct
    {
      uint8_t pn : 1;
      uint8_t s : 1;
      uint8_t e : 1;
      uint8_t res1 : 1;
      uint8_t pt : 1;
      uint8_t ver : 3;
    };
  };
  uint8_t msg_type;
  rte_be16_t plen;
  rte_be32_t teid;
} __attribute__((__packed__));
struct rte_gtp_hdr_ext_word
{
  rte_be16_t sqn;
  uint8_t npdu;
  uint8_t next_ext;
} __attribute__((__packed__));
__extension__ struct rte_gtp_psc_generic_hdr
{
  uint8_t ext_hdr_len;
  uint8_t pad : 3;
  uint8_t qmp : 1;
  uint8_t type : 4;
  uint8_t qfi : 6;
  uint8_t spare : 2;
  uint8_t data[0];
} __attribute__((__packed__));
__extension__ struct rte_gtp_psc_type0_hdr
{
  uint8_t ext_hdr_len;
  uint8_t spare_dl1 : 2;
  uint8_t snp : 1;
  uint8_t qmp : 1;
  uint8_t type : 4;
  uint8_t qfi : 6;
  uint8_t rqi : 1;
  uint8_t ppp : 1;
  uint8_t data[0];
} __attribute__((__packed__));
__extension__ struct rte_gtp_psc_type1_hdr
{
  uint8_t ext_hdr_len;
  uint8_t snp : 1;
  uint8_t ul_delay_ind : 1;
  uint8_t dl_delay_ind : 1;
  uint8_t qmp : 1;
  uint8_t type : 4;
  uint8_t qfi : 6;
  uint8_t spare_ul2 : 1;
  uint8_t n_delay_ind : 1;
  uint8_t data[0];
} __attribute__((__packed__));
struct rte_l2tpv2_common_hdr
{
  union
  {
    rte_be16_t flags_version;
    __extension__ struct
    {
      uint16_t ver : 4;
      uint16_t res3 : 4;
      uint16_t p : 1;
      uint16_t o : 1;
      uint16_t res2 : 1;
      uint16_t s : 1;
      uint16_t res1 : 2;
      uint16_t l : 1;
      uint16_t t : 1;
    };
  };
};
struct rte_l2tpv2_msg_with_all_options
{
  rte_be16_t length;
  rte_be16_t tunnel_id;
  rte_be16_t session_id;
  rte_be16_t ns;
  rte_be16_t nr;
  rte_be16_t offset_size;
  uint8_t *offset_padding;
} __attribute__((__packed__));
struct rte_l2tpv2_msg_without_length
{
  rte_be16_t tunnel_id;
  rte_be16_t session_id;
  rte_be16_t ns;
  rte_be16_t nr;
  rte_be16_t offset_size;
  uint8_t *offset_padding;
} __attribute__((__packed__));
struct rte_l2tpv2_msg_without_ns_nr
{
  rte_be16_t length;
  rte_be16_t tunnel_id;
  rte_be16_t session_id;
  rte_be16_t offset_size;
  uint8_t *offset_padding;
};
struct rte_l2tpv2_msg_without_offset
{
  rte_be16_t length;
  rte_be16_t tunnel_id;
  rte_be16_t session_id;
  rte_be16_t ns;
  rte_be16_t nr;
};
struct rte_l2tpv2_msg_with_offset
{
  rte_be16_t tunnel_id;
  rte_be16_t session_id;
  rte_be16_t offset_size;
  uint8_t *offset_padding;
} __attribute__((__packed__));
struct rte_l2tpv2_msg_with_ns_nr
{
  rte_be16_t tunnel_id;
  rte_be16_t session_id;
  rte_be16_t ns;
  rte_be16_t nr;
};
struct rte_l2tpv2_msg_with_length
{
  rte_be16_t length;
  rte_be16_t tunnel_id;
  rte_be16_t session_id;
};
struct rte_l2tpv2_msg_without_all_options
{
  rte_be16_t tunnel_id;
  rte_be16_t session_id;
};
struct rte_l2tpv2_combined_msg_hdr
{
  struct rte_l2tpv2_common_hdr common;
  union
  {
    struct rte_l2tpv2_msg_with_all_options type0;
    struct rte_l2tpv2_msg_without_length type1;
    struct rte_l2tpv2_msg_without_ns_nr type2;
    struct rte_l2tpv2_msg_without_offset type3;
    struct rte_l2tpv2_msg_with_offset type4;
    struct rte_l2tpv2_msg_with_ns_nr type5;
    struct rte_l2tpv2_msg_with_length type6;
    struct rte_l2tpv2_msg_without_all_options type7;
  };
} __attribute__((__packed__));
struct rte_ppp_hdr
{
  uint8_t addr;
  uint8_t ctrl;
  rte_be16_t proto_id;
} __attribute__((__packed__));
__extension__ struct rte_gre_hdr
{
  uint16_t res2 : 4;
  uint16_t s : 1;
  uint16_t k : 1;
  uint16_t res1 : 1;
  uint16_t c : 1;
  uint16_t ver : 3;
  uint16_t res3 : 5;
  rte_be16_t proto;
} __attribute__((__packed__));
struct rte_gre_hdr_opt_checksum_rsvd
{
  rte_be16_t checksum;
  rte_be16_t reserved1;
} __attribute__((__packed__));
struct rte_gre_hdr_opt_key
{
  rte_be32_t key;
} __attribute__((__packed__));
struct rte_gre_hdr_opt_sequence
{
  rte_be32_t sequence;
} __attribute__((__packed__));
__extension__ struct rte_macsec_hdr
{
  uint8_t tci_an;
  uint8_t short_length : 6;
  uint8_t unused : 2;
  rte_be32_t packet_number;
} __attribute__((__packed__));
struct rte_macsec_sci_hdr
{
  uint8_t sci[8];
} __attribute__((__packed__));
__extension__ struct rte_ib_bth
{
  uint8_t opcode;
  uint8_t tver : 4;
  uint8_t padcnt : 2;
  uint8_t m : 1;
  uint8_t se : 1;
  rte_be16_t pkey;
  uint8_t rsvd0 : 6;
  uint8_t b : 1;
  uint8_t f : 1;
  uint8_t dst_qp[3];
  uint8_t rsvd1 : 7;
  uint8_t a : 1;
  uint8_t psn[3];
} __attribute__((__packed__));
struct rte_flow_attr
{
  uint32_t group;
  uint32_t priority;
  uint32_t ingress : 1;
  uint32_t egress : 1;
  uint32_t transfer : 1;
  uint32_t reserved : 29;
};
struct rte_flow_group_attr
{
  uint32_t ingress : 1;
  uint32_t egress : 1;
  uint32_t transfer : 1;
};
enum rte_flow_item_type
{
  RTE_FLOW_ITEM_TYPE_END,
  RTE_FLOW_ITEM_TYPE_VOID,
  RTE_FLOW_ITEM_TYPE_INVERT,
  RTE_FLOW_ITEM_TYPE_ANY,
  RTE_FLOW_ITEM_TYPE_PORT_ID,
  RTE_FLOW_ITEM_TYPE_RAW,
  RTE_FLOW_ITEM_TYPE_ETH,
  RTE_FLOW_ITEM_TYPE_VLAN,
  RTE_FLOW_ITEM_TYPE_IPV4,
  RTE_FLOW_ITEM_TYPE_IPV6,
  RTE_FLOW_ITEM_TYPE_ICMP,
  RTE_FLOW_ITEM_TYPE_UDP,
  RTE_FLOW_ITEM_TYPE_TCP,
  RTE_FLOW_ITEM_TYPE_SCTP,
  RTE_FLOW_ITEM_TYPE_VXLAN,
  RTE_FLOW_ITEM_TYPE_E_TAG,
  RTE_FLOW_ITEM_TYPE_NVGRE,
  RTE_FLOW_ITEM_TYPE_MPLS,
  RTE_FLOW_ITEM_TYPE_GRE,
  RTE_FLOW_ITEM_TYPE_FUZZY,
  RTE_FLOW_ITEM_TYPE_GTP,
  RTE_FLOW_ITEM_TYPE_GTPC,
  RTE_FLOW_ITEM_TYPE_GTPU,
  RTE_FLOW_ITEM_TYPE_ESP,
  RTE_FLOW_ITEM_TYPE_GENEVE,
  RTE_FLOW_ITEM_TYPE_VXLAN_GPE,
  RTE_FLOW_ITEM_TYPE_ARP_ETH_IPV4,
  RTE_FLOW_ITEM_TYPE_IPV6_EXT,
  RTE_FLOW_ITEM_TYPE_ICMP6,
  RTE_FLOW_ITEM_TYPE_ICMP6_ND_NS,
  RTE_FLOW_ITEM_TYPE_ICMP6_ND_NA,
  RTE_FLOW_ITEM_TYPE_ICMP6_ND_OPT,
  RTE_FLOW_ITEM_TYPE_ICMP6_ND_OPT_SLA_ETH,
  RTE_FLOW_ITEM_TYPE_ICMP6_ND_OPT_TLA_ETH,
  RTE_FLOW_ITEM_TYPE_MARK,
  RTE_FLOW_ITEM_TYPE_META,
  RTE_FLOW_ITEM_TYPE_GRE_KEY,
  RTE_FLOW_ITEM_TYPE_GTP_PSC,
  RTE_FLOW_ITEM_TYPE_PPPOES,
  RTE_FLOW_ITEM_TYPE_PPPOED,
  RTE_FLOW_ITEM_TYPE_PPPOE_PROTO_ID,
  RTE_FLOW_ITEM_TYPE_NSH,
  RTE_FLOW_ITEM_TYPE_IGMP,
  RTE_FLOW_ITEM_TYPE_AH,
  RTE_FLOW_ITEM_TYPE_HIGIG2,
  RTE_FLOW_ITEM_TYPE_TAG,
  RTE_FLOW_ITEM_TYPE_L2TPV3OIP,
  RTE_FLOW_ITEM_TYPE_PFCP,
  RTE_FLOW_ITEM_TYPE_ECPRI,
  RTE_FLOW_ITEM_TYPE_IPV6_FRAG_EXT,
  RTE_FLOW_ITEM_TYPE_GENEVE_OPT,
  RTE_FLOW_ITEM_TYPE_INTEGRITY,
  RTE_FLOW_ITEM_TYPE_CONNTRACK,
  RTE_FLOW_ITEM_TYPE_PORT_REPRESENTOR,
  RTE_FLOW_ITEM_TYPE_REPRESENTED_PORT,
  RTE_FLOW_ITEM_TYPE_FLEX,
  RTE_FLOW_ITEM_TYPE_L2TPV2,
  RTE_FLOW_ITEM_TYPE_PPP,
  RTE_FLOW_ITEM_TYPE_GRE_OPTION,
  RTE_FLOW_ITEM_TYPE_MACSEC,
  RTE_FLOW_ITEM_TYPE_METER_COLOR,
  RTE_FLOW_ITEM_TYPE_IPV6_ROUTING_EXT,
  RTE_FLOW_ITEM_TYPE_ICMP6_ECHO_REQUEST,
  RTE_FLOW_ITEM_TYPE_ICMP6_ECHO_REPLY,
  RTE_FLOW_ITEM_TYPE_QUOTA,
  RTE_FLOW_ITEM_TYPE_AGGR_AFFINITY,
  RTE_FLOW_ITEM_TYPE_TX_QUEUE,
  RTE_FLOW_ITEM_TYPE_IB_BTH,
  RTE_FLOW_ITEM_TYPE_PTYPE,
  RTE_FLOW_ITEM_TYPE_RANDOM,
  RTE_FLOW_ITEM_TYPE_COMPARE,
};
enum rte_flow_quota_state
{
  RTE_FLOW_QUOTA_STATE_PASS,
  RTE_FLOW_QUOTA_STATE_BLOCK
};
struct rte_flow_item_quota
{
  enum rte_flow_quota_state state;
};
static const struct rte_flow_item_quota rte_flow_item_quota_mask = {
    .state = (enum rte_flow_quota_state)0xff};

struct rte_flow_item_higig2_hdr
{
  struct rte_higig2_hdr hdr;
};
static const struct rte_flow_item_higig2_hdr rte_flow_item_higig2_hdr_mask = {
    .hdr = {
        .ppt1 = {
            .classification = (rte_be16_t)(((((uint16_t)((65535)) &
                                              0x00ff)
                                             << 8) |
                                            (((uint16_t)((65535)) &
                                              0xff00) >>
                                             8))),
            .vid =
                (rte_be16_t)(((((uint16_t)(0xfff) & 0x00ff) << 8) |
                              (((uint16_t)(0xfff) & 0xff00) >> 8))),
        },
    },
};

struct rte_flow_item_any
{
  uint32_t num;
};
static const struct rte_flow_item_any rte_flow_item_any_mask = {
    .num = 0x00000000,
};

struct rte_flow_item_port_id
{
  uint32_t id;
};
static const struct rte_flow_item_port_id rte_flow_item_port_id_mask = {
    .id = 0xffffffff,
};

struct rte_flow_item_raw
{
  uint32_t relative : 1;
  uint32_t search : 1;
  uint32_t reserved : 30;
  int32_t offset;
  uint16_t limit;
  uint16_t length;
  const uint8_t *pattern;
};
static const struct rte_flow_item_raw rte_flow_item_raw_mask = {
    .relative = 1,
    .search = 1,
    .reserved = 0x3fffffff,
    .offset = 0xffffffff,
    .limit = 0xffff,
    .length = 0xffff,
    .pattern = ((void *)0),
};

struct rte_flow_item_eth
{
  union
  {
    struct
    {
      struct rte_ether_addr dst;
      struct rte_ether_addr src;
      rte_be16_t type;
    };
    struct rte_ether_hdr hdr;
  };
  uint32_t has_vlan : 1;
  uint32_t reserved : 31;
};
static const struct rte_flow_item_eth rte_flow_item_eth_mask = {
    .hdr.dst_addr.addr_bytes = "\xff\xff\xff\xff\xff\xff",
    .hdr.src_addr.addr_bytes = "\xff\xff\xff\xff\xff\xff",
    .hdr.ether_type =
        (rte_be16_t)(((((uint16_t)(0x0000) & 0x00ff) << 8) |
                      (((uint16_t)(0x0000) & 0xff00) >> 8))),
};

struct rte_flow_item_vlan
{
  union
  {
    struct
    {
      rte_be16_t tci;
      rte_be16_t inner_type;
    };
    struct rte_vlan_hdr hdr;
  };
  uint32_t has_more_vlan : 1;
  uint32_t reserved : 31;
};
static const struct rte_flow_item_vlan rte_flow_item_vlan_mask = {
    .hdr.vlan_tci =
        (rte_be16_t)(((((uint16_t)(0x0fff) & 0x00ff) << 8) |
                      (((uint16_t)(0x0fff) & 0xff00) >> 8))),
    .hdr.eth_proto =
        (rte_be16_t)(((((uint16_t)(0x0000) & 0x00ff) << 8) |
                      (((uint16_t)(0x0000) & 0xff00) >> 8))),
};

struct rte_flow_item_ipv4
{
  struct rte_ipv4_hdr hdr;
};
static const struct rte_flow_item_ipv4 rte_flow_item_ipv4_mask = {
    .hdr = {
        .src_addr =
            (rte_be32_t)(((((uint32_t)(0xffffffff) & 0x000000ffU) << 24) |
                          (((uint32_t)(0xffffffff) & 0x0000ff00U) << 8) |
                          (((uint32_t)(0xffffffff) & 0x00ff0000U) >> 8) |
                          (((uint32_t)(0xffffffff) & 0xff000000U) >> 24))),
        .dst_addr =
            (rte_be32_t)(((((uint32_t)(0xffffffff) & 0x000000ffU) << 24) |
                          (((uint32_t)(0xffffffff) & 0x0000ff00U) << 8) |
                          (((uint32_t)(0xffffffff) & 0x00ff0000U) >> 8) |
                          (((uint32_t)(0xffffffff) & 0xff000000U) >> 24))),
    },
};

struct rte_flow_item_ipv6
{
  struct rte_ipv6_hdr hdr;
  uint32_t has_hop_ext : 1;
  uint32_t has_route_ext : 1;
  uint32_t has_frag_ext : 1;
  uint32_t has_auth_ext : 1;
  uint32_t has_esp_ext : 1;
  uint32_t has_dest_ext : 1;
  uint32_t has_mobil_ext : 1;
  uint32_t has_hip_ext : 1;
  uint32_t has_shim6_ext : 1;
  uint32_t reserved : 23;
};
static const struct rte_flow_item_ipv6 rte_flow_item_ipv6_mask = {
    .hdr = {
        .src_addr =
            "\xff\xff\xff\xff\xff\xff\xff\xff"
            "\xff\xff\xff\xff\xff\xff\xff\xff",
        .dst_addr =
            "\xff\xff\xff\xff\xff\xff\xff\xff"
            "\xff\xff\xff\xff\xff\xff\xff\xff",
    },
};

struct rte_flow_item_ipv6_routing_ext
{
  struct rte_ipv6_routing_ext hdr;
};
struct rte_flow_item_icmp
{
  struct rte_icmp_hdr hdr;
};
static const struct rte_flow_item_icmp rte_flow_item_icmp_mask = {
    .hdr = {
        .icmp_type = 0xff,
        .icmp_code = 0xff,
    },
};

struct rte_flow_item_udp
{
  struct rte_udp_hdr hdr;
};
static const struct rte_flow_item_udp rte_flow_item_udp_mask = {
    .hdr = {
        .src_port =
            (rte_be16_t)(((((uint16_t)(0xffff) & 0x00ff) << 8) |
                          (((uint16_t)(0xffff) & 0xff00) >> 8))),
        .dst_port =
            (rte_be16_t)(((((uint16_t)(0xffff) & 0x00ff) << 8) |
                          (((uint16_t)(0xffff) & 0xff00) >> 8))),
    },
};

struct rte_flow_item_tcp
{
  struct rte_tcp_hdr hdr;
};
static const struct rte_flow_item_tcp rte_flow_item_tcp_mask = {
    .hdr = {
        .src_port =
            (rte_be16_t)(((((uint16_t)(0xffff) & 0x00ff) << 8) |
                          (((uint16_t)(0xffff) & 0xff00) >> 8))),
        .dst_port =
            (rte_be16_t)(((((uint16_t)(0xffff) & 0x00ff) << 8) |
                          (((uint16_t)(0xffff) & 0xff00) >> 8))),
    },
};

struct rte_flow_item_sctp
{
  struct rte_sctp_hdr hdr;
};
static const struct rte_flow_item_sctp rte_flow_item_sctp_mask = {
    .hdr = {
        .src_port =
            (rte_be16_t)(((((uint16_t)(0xffff) & 0x00ff) << 8) |
                          (((uint16_t)(0xffff) & 0xff00) >> 8))),
        .dst_port =
            (rte_be16_t)(((((uint16_t)(0xffff) & 0x00ff) << 8) |
                          (((uint16_t)(0xffff) & 0xff00) >> 8))),
    },
};

struct rte_flow_item_vxlan
{
  union
  {
    struct
    {
      uint8_t flags;
      uint8_t rsvd0[3];
      uint8_t vni[3];
      uint8_t rsvd1;
    };
    struct rte_vxlan_hdr hdr;
  };
};
static const struct rte_flow_item_vxlan rte_flow_item_vxlan_mask = {
    .hdr.vni = "\xff\xff\xff",
};

struct rte_flow_item_e_tag
{
  rte_be16_t epcp_edei_in_ecid_b;
  rte_be16_t rsvd_grp_ecid_b;
  uint8_t in_ecid_e;
  uint8_t ecid_e;
  rte_be16_t inner_type;
};
static const struct rte_flow_item_e_tag rte_flow_item_e_tag_mask = {
    .rsvd_grp_ecid_b =
        (rte_be16_t)(((((uint16_t)(0x3fff) & 0x00ff) << 8) |
                      (((uint16_t)(0x3fff) & 0xff00) >> 8))),
};

struct rte_flow_item_nvgre
{
  rte_be16_t c_k_s_rsvd0_ver;
  rte_be16_t protocol;
  uint8_t tni[3];
  uint8_t flow_id;
};
static const struct rte_flow_item_nvgre rte_flow_item_nvgre_mask = {
    .tni = "\xff\xff\xff",
};

struct rte_flow_item_mpls
{
  uint8_t label_tc_s[3];
  uint8_t ttl;
};
static const struct rte_flow_item_mpls rte_flow_item_mpls_mask = {
    .label_tc_s = "\xff\xff\xf0",
};

struct rte_flow_item_gre
{
  rte_be16_t c_rsvd0_ver;
  rte_be16_t protocol;
};
static const struct rte_flow_item_gre rte_flow_item_gre_mask = {
    .protocol =
        (rte_be16_t)(((((uint16_t)(0xffff) & 0x00ff) << 8) |
                      (((uint16_t)(0xffff) & 0xff00) >> 8))),
};

struct rte_flow_item_gre_opt
{
  struct rte_gre_hdr_opt_checksum_rsvd checksum_rsvd;
  struct rte_gre_hdr_opt_key key;
  struct rte_gre_hdr_opt_sequence sequence;
};
struct rte_flow_item_macsec
{
  struct rte_macsec_hdr macsec_hdr;
};
struct rte_flow_item_fuzzy
{
  uint32_t thresh;
};
static const struct rte_flow_item_fuzzy rte_flow_item_fuzzy_mask = {
    .thresh = 0xffffffff,
};

struct rte_flow_item_gtp
{
  union
  {
    struct
    {
      uint8_t v_pt_rsv_flags;
      uint8_t msg_type;
      rte_be16_t msg_len;
      rte_be32_t teid;
    };
    struct rte_gtp_hdr hdr;
  };
};
static const struct rte_flow_item_gtp rte_flow_item_gtp_mask = {
    .hdr.teid = (rte_be32_t)(((((uint32_t)((4294967295U)) & 0x000000ffU) << 24) | (((uint32_t)((4294967295U)) & 0x0000ff00U) << 8) |
                              (((uint32_t)((4294967295U)) & 0x00ff0000U) >> 8) | (((uint32_t)((4294967295U)) & 0xff000000U) >> 24))),
};

struct rte_flow_item_esp
{
  struct rte_esp_hdr hdr;
};
static const struct rte_flow_item_esp rte_flow_item_esp_mask = {
    .hdr = {
        .spi =
            (rte_be32_t)(((((uint32_t)(0xffffffff) & 0x000000ffU) << 24) |
                          (((uint32_t)(0xffffffff) & 0x0000ff00U) << 8) |
                          (((uint32_t)(0xffffffff) & 0x00ff0000U) >> 8) |
                          (((uint32_t)(0xffffffff) & 0xff000000U) >> 24))),
    },
};

struct rte_flow_item_geneve
{
  rte_be16_t ver_opt_len_o_c_rsvd0;
  rte_be16_t protocol;
  uint8_t vni[3];
  uint8_t rsvd1;
};
static const struct rte_flow_item_geneve rte_flow_item_geneve_mask = {
    .vni = "\xff\xff\xff",
};

struct rte_flow_item_vxlan_gpe
{
  union
  {
    struct
    {
      uint8_t flags;
      uint8_t rsvd0[2];
      uint8_t protocol;
      uint8_t vni[3];
      uint8_t rsvd1;
    };
    struct rte_vxlan_gpe_hdr hdr;
  };
};
static const struct rte_flow_item_vxlan_gpe rte_flow_item_vxlan_gpe_mask = {
    .hdr.vni = "\xff\xff\xff",
};

struct rte_flow_item_arp_eth_ipv4
{
  union
  {
    struct
    {
      rte_be16_t hrd;
      rte_be16_t pro;
      uint8_t hln;
      uint8_t pln;
      rte_be16_t op;
      struct rte_ether_addr sha;
      rte_be32_t spa;
      struct rte_ether_addr tha;
      rte_be32_t tpa;
    };
    struct rte_arp_hdr hdr;
  };
};
static const struct rte_flow_item_arp_eth_ipv4
    rte_flow_item_arp_eth_ipv4_mask = {
        .hdr.arp_data.arp_sha.addr_bytes = "\xff\xff\xff\xff\xff\xff",
        .hdr.arp_data.arp_sip = (rte_be32_t)(((((uint32_t)((4294967295U)) &
                                                0x000000ffU)
                                               << 24) |
                                              (((uint32_t)((4294967295U)) &
                                                0x0000ff00U)
                                               << 8) |
                                              (((uint32_t)((4294967295U)) &
                                                0x00ff0000U) >>
                                               8) |
                                              (((uint32_t)((4294967295U)) &
                                                0xff000000U) >>
                                               24))),
        .hdr.arp_data.arp_tha.addr_bytes = "\xff\xff\xff\xff\xff\xff",
        .hdr.arp_data.arp_tip = (rte_be32_t)(((((uint32_t)((4294967295U)) &
                                                0x000000ffU)
                                               << 24) |
                                              (((uint32_t)((4294967295U)) &
                                                0x0000ff00U)
                                               << 8) |
                                              (((uint32_t)((4294967295U)) &
                                                0x00ff0000U) >>
                                               8) |
                                              (((uint32_t)((4294967295U)) &
                                                0xff000000U) >>
                                               24))),
};

struct rte_flow_item_ipv6_ext
{
  uint8_t next_hdr;
};
static const struct rte_flow_item_ipv6_ext rte_flow_item_ipv6_ext_mask = {
    .next_hdr = 0xff,
};

struct rte_flow_item_ipv6_frag_ext
{
  struct rte_ipv6_fragment_ext hdr;
};
struct rte_flow_item_icmp6
{
  uint8_t type;
  uint8_t code;
  uint16_t checksum;
};
static const struct rte_flow_item_icmp6 rte_flow_item_icmp6_mask = {
    .type = 0xff,
    .code = 0xff,
};

struct rte_flow_item_icmp6_echo
{
  struct rte_icmp_echo_hdr hdr;
};
struct rte_flow_item_icmp6_nd_ns
{
  uint8_t type;
  uint8_t code;
  rte_be16_t checksum;
  rte_be32_t reserved;
  uint8_t target_addr[16];
};
static const struct rte_flow_item_icmp6_nd_ns rte_flow_item_icmp6_nd_ns_mask = {
    .target_addr =
        "\xff\xff\xff\xff\xff\xff\xff\xff"
        "\xff\xff\xff\xff\xff\xff\xff\xff",
};

struct rte_flow_item_icmp6_nd_na
{
  uint8_t type;
  uint8_t code;
  rte_be16_t checksum;
  rte_be32_t rso_reserved;
  uint8_t target_addr[16];
};
static const struct rte_flow_item_icmp6_nd_na rte_flow_item_icmp6_nd_na_mask = {
    .target_addr =
        "\xff\xff\xff\xff\xff\xff\xff\xff"
        "\xff\xff\xff\xff\xff\xff\xff\xff",
};

struct rte_flow_item_icmp6_nd_opt
{
  uint8_t type;
  uint8_t length;
};
static const struct rte_flow_item_icmp6_nd_opt
    rte_flow_item_icmp6_nd_opt_mask = {
        .type = 0xff,
};

struct rte_flow_item_icmp6_nd_opt_sla_eth
{
  uint8_t type;
  uint8_t length;
  struct rte_ether_addr sla;
};
static const struct rte_flow_item_icmp6_nd_opt_sla_eth
    rte_flow_item_icmp6_nd_opt_sla_eth_mask = {
        .sla.addr_bytes = "\xff\xff\xff\xff\xff\xff",
};

struct rte_flow_item_icmp6_nd_opt_tla_eth
{
  uint8_t type;
  uint8_t length;
  struct rte_ether_addr tla;
};
static const struct rte_flow_item_icmp6_nd_opt_tla_eth
    rte_flow_item_icmp6_nd_opt_tla_eth_mask = {
        .tla.addr_bytes = "\xff\xff\xff\xff\xff\xff",
};

struct rte_flow_item_meta
{
  uint32_t data;
};
static const struct rte_flow_item_meta rte_flow_item_meta_mask = {
    .data = (4294967295U),
};

struct rte_flow_item_gtp_psc
{
  struct rte_gtp_psc_generic_hdr hdr;
};
static const struct rte_flow_item_gtp_psc rte_flow_item_gtp_psc_mask = {
    .hdr.qfi = 0x3f,
};

struct rte_flow_item_pppoe
{
  uint8_t version_type;
  uint8_t code;
  rte_be16_t session_id;
  rte_be16_t length;
};
struct rte_flow_item_pppoe_proto_id
{
  rte_be16_t proto_id;
};
static const struct rte_flow_item_pppoe_proto_id
    rte_flow_item_pppoe_proto_id_mask = {
        .proto_id =
            (rte_be16_t)(((((uint16_t)(0xffff) & 0x00ff) << 8) |
                          (((uint16_t)(0xffff) & 0xff00) >> 8))),
};

struct rte_flow_item_tag
{
  uint32_t data;
  uint8_t index;
};
static const struct rte_flow_item_tag rte_flow_item_tag_mask = {
    .data = 0xffffffff,
    .index = 0xff,
};

struct rte_flow_item_l2tpv3oip
{
  rte_be32_t session_id;
};
static const struct rte_flow_item_l2tpv3oip rte_flow_item_l2tpv3oip_mask = {
    .session_id = (rte_be32_t)(((((uint32_t)((4294967295U)) & 0x000000ffU) << 24) | (((uint32_t)((4294967295U)) & 0x0000ff00U) << 8) |
                                (((uint32_t)((4294967295U)) & 0x00ff0000U) >>
                                 8) |
                                (((uint32_t)((4294967295U)) &
                                  0xff000000U) >>
                                 24))),
};

struct rte_flow_item_mark
{
  uint32_t id;
};
static const struct rte_flow_item_mark rte_flow_item_mark_mask = {
    .id = 0xffffffff,
};

struct rte_flow_item_nsh
{
  uint32_t version : 2;
  uint32_t oam_pkt : 1;
  uint32_t reserved : 1;
  uint32_t ttl : 6;
  uint32_t length : 6;
  uint32_t reserved1 : 4;
  uint32_t mdtype : 4;
  uint32_t next_proto : 8;
  uint32_t spi : 24;
  uint32_t sindex : 8;
};
static const struct rte_flow_item_nsh rte_flow_item_nsh_mask = {
    .mdtype = 0xf,
    .next_proto = 0xff,
    .spi = 0xffffff,
    .sindex = 0xff,
};

struct rte_flow_item_igmp
{
  uint32_t type : 8;
  uint32_t max_resp_time : 8;
  uint32_t checksum : 16;
  uint32_t group_addr;
};
static const struct rte_flow_item_igmp rte_flow_item_igmp_mask = {
    .group_addr = 0xffffffff,
};

struct rte_flow_item_ah
{
  uint32_t next_hdr : 8;
  uint32_t payload_len : 8;
  uint32_t reserved : 16;
  uint32_t spi;
  uint32_t seq_num;
};
static const struct rte_flow_item_ah rte_flow_item_ah_mask = {
    .spi = 0xffffffff,
};

struct rte_flow_item_pfcp
{
  uint8_t s_field;
  uint8_t msg_type;
  rte_be16_t msg_len;
  rte_be64_t seid;
};
static const struct rte_flow_item_pfcp rte_flow_item_pfcp_mask = {
    .s_field = 0x01,
    .seid =
        (rte_be64_t)(((((uint64_t)(0xffffffffffffffffUL) & 0x00000000000000ffUL)
                       << 56) |
                      (((uint64_t)(0xffffffffffffffffUL) &
                        0x000000000000ff00UL)
                       << 40) |
                      (((uint64_t)(0xffffffffffffffffUL) & 0x0000000000ff0000UL)
                       << 24) |
                      (((uint64_t)(0xffffffffffffffffUL) &
                        0x00000000ff000000UL)
                       << 8) |
                      (((uint64_t)(0xffffffffffffffffUL) & 0x000000ff00000000UL) >> 8) | (((uint64_t)(0xffffffffffffffffUL) & 0x0000ff0000000000UL) >> 24) |
                      (((uint64_t)(0xffffffffffffffffUL) & 0x00ff000000000000UL) >> 40) | (((uint64_t)(0xffffffffffffffffUL) & 0xff00000000000000UL) >> 56))),
};

struct rte_flow_item_ecpri
{
  struct rte_ecpri_combined_msg_hdr hdr;
};
static const struct rte_flow_item_ecpri rte_flow_item_ecpri_mask = {
    .hdr = {
        .common = {
            .u32 = 0x0,
        },
    },
};

struct rte_flow_item_geneve_opt
{
  rte_be16_t option_class;
  uint8_t option_type;
  uint8_t option_len;
  uint32_t *data;
};
static const struct rte_flow_item_geneve_opt rte_flow_item_geneve_opt_mask = {
    .option_type = 0xff,
};

struct rte_flow_item_integrity
{
  uint32_t level;
  union
  {
    __extension__ struct
    {
      uint64_t packet_ok : 1;
      uint64_t l2_ok : 1;
      uint64_t l3_ok : 1;
      uint64_t l4_ok : 1;
      uint64_t l2_crc_ok : 1;
      uint64_t ipv4_csum_ok : 1;
      uint64_t l4_csum_ok : 1;
      uint64_t l3_len_ok : 1;
      uint64_t reserved : 56;
    };
    uint64_t value;
  };
};
static const struct rte_flow_item_integrity rte_flow_item_integrity_mask = {
    .level = 0,
    .value = 0,
};

struct rte_flow_item_conntrack
{
  uint32_t flags;
};
static const struct rte_flow_item_conntrack rte_flow_item_conntrack_mask = {
    .flags = 0xffffffff,
};

struct rte_flow_item_ethdev
{
  uint16_t port_id;
};
static const struct rte_flow_item_ethdev rte_flow_item_ethdev_mask = {
    .port_id = 0xffff,
};

struct rte_flow_item_l2tpv2
{
  struct rte_l2tpv2_combined_msg_hdr hdr;
};
static const struct rte_flow_item_l2tpv2 rte_flow_item_l2tpv2_mask = {
    .hdr = {
        .common = {
            .flags_version =
                (rte_be16_t)(((((uint16_t)(0xcb0f) & 0x00ff) << 8) |
                              (((uint16_t)(0xcb0f) & 0xff00) >> 8))),
        },
    },
};

struct rte_flow_item_ppp
{
  struct rte_ppp_hdr hdr;
};
static const struct rte_flow_item_ppp rte_flow_item_ppp_mask = {
    .hdr = {
        .addr = 0xff,
        .ctrl = 0xff,
        .proto_id =
            (rte_be16_t)(((((uint16_t)(0xffff) & 0x00ff) << 8) |
                          (((uint16_t)(0xffff) & 0xff00) >> 8))),
    }};

struct rte_flow_item_ib_bth
{
  struct rte_ib_bth hdr;
};
static const struct rte_flow_item_ib_bth rte_flow_item_ib_bth_mask = {
    .hdr = {
        .opcode = 0xff,
        .dst_qp = "\xff\xff\xff",
    },
};

struct rte_flow_item_random
{
  uint32_t value;
};
static const struct rte_flow_item_random rte_flow_item_random_mask = {
    .value = (4294967295U),
};

struct rte_flow_item
{
  enum rte_flow_item_type type;
  const void *spec;
  const void *last;
  const void *mask;
};
struct rte_flow_item_flex
{
  struct rte_flow_item_flex_handle *handle;
  uint32_t length;
  const uint8_t *pattern;
};
enum rte_flow_item_flex_field_mode
{
  FIELD_MODE_DUMMY = 0,
  FIELD_MODE_FIXED,
  FIELD_MODE_OFFSET,
  FIELD_MODE_BITMASK,
};
enum rte_flow_item_flex_tunnel_mode
{
  FLEX_TUNNEL_MODE_SINGLE = 0,
  FLEX_TUNNEL_MODE_OUTER,
  FLEX_TUNNEL_MODE_INNER,
  FLEX_TUNNEL_MODE_MULTI,
  FLEX_TUNNEL_MODE_TUNNEL,
};
__extension__ struct rte_flow_item_flex_field
{
  enum rte_flow_item_flex_field_mode field_mode;
  uint32_t field_size;
  int32_t field_base;
  uint32_t offset_base;
  uint32_t offset_mask;
  int32_t offset_shift;
  uint32_t field_id : 16;
  uint32_t reserved : 16;
};
struct rte_flow_item_flex_link
{
  struct rte_flow_item item;
  uint32_t next;
};
struct rte_flow_item_flex_conf
{
  enum rte_flow_item_flex_tunnel_mode tunnel;
  struct rte_flow_item_flex_field next_header;
  struct rte_flow_item_flex_field next_protocol;
  struct rte_flow_item_flex_field *sample_data;
  uint32_t nb_samples;
  struct rte_flow_item_flex_link *input_link;
  uint32_t nb_inputs;
  struct rte_flow_item_flex_link *output_link;
  uint32_t nb_outputs;
};
struct rte_flow_item_meter_color
{
  enum rte_color color;
};
static const struct rte_flow_item_meter_color rte_flow_item_meter_color_mask = {
    .color = RTE_COLORS,
};

struct rte_flow_item_aggr_affinity
{
  uint8_t affinity;
};
static const struct rte_flow_item_aggr_affinity
    rte_flow_item_aggr_affinity_mask = {
        .affinity = 0xff,
};

struct rte_flow_item_tx_queue
{
  uint16_t tx_queue;
};
static const struct rte_flow_item_tx_queue rte_flow_item_tx_queue_mask = {
    .tx_queue = 0xffff,
};

struct rte_flow_item_ptype
{
  uint32_t packet_type;
};
static const struct rte_flow_item_ptype rte_flow_item_ptype_mask = {
    .packet_type = 0xffffffff,
};

enum rte_flow_field_id
{
  RTE_FLOW_FIELD_START = 0,
  RTE_FLOW_FIELD_MAC_DST,
  RTE_FLOW_FIELD_MAC_SRC,
  RTE_FLOW_FIELD_VLAN_TYPE,
  RTE_FLOW_FIELD_VLAN_ID,
  RTE_FLOW_FIELD_MAC_TYPE,
  RTE_FLOW_FIELD_IPV4_DSCP,
  RTE_FLOW_FIELD_IPV4_TTL,
  RTE_FLOW_FIELD_IPV4_SRC,
  RTE_FLOW_FIELD_IPV4_DST,
  RTE_FLOW_FIELD_IPV6_DSCP,
  RTE_FLOW_FIELD_IPV6_HOPLIMIT,
  RTE_FLOW_FIELD_IPV6_SRC,
  RTE_FLOW_FIELD_IPV6_DST,
  RTE_FLOW_FIELD_TCP_PORT_SRC,
  RTE_FLOW_FIELD_TCP_PORT_DST,
  RTE_FLOW_FIELD_TCP_SEQ_NUM,
  RTE_FLOW_FIELD_TCP_ACK_NUM,
  RTE_FLOW_FIELD_TCP_FLAGS,
  RTE_FLOW_FIELD_UDP_PORT_SRC,
  RTE_FLOW_FIELD_UDP_PORT_DST,
  RTE_FLOW_FIELD_VXLAN_VNI,
  RTE_FLOW_FIELD_GENEVE_VNI,
  RTE_FLOW_FIELD_GTP_TEID,
  RTE_FLOW_FIELD_TAG,
  RTE_FLOW_FIELD_MARK,
  RTE_FLOW_FIELD_META,
  RTE_FLOW_FIELD_POINTER,
  RTE_FLOW_FIELD_VALUE,
  RTE_FLOW_FIELD_IPV4_ECN,
  RTE_FLOW_FIELD_IPV6_ECN,
  RTE_FLOW_FIELD_GTP_PSC_QFI,
  RTE_FLOW_FIELD_METER_COLOR,
  RTE_FLOW_FIELD_IPV6_PROTO,
  RTE_FLOW_FIELD_FLEX_ITEM,
  RTE_FLOW_FIELD_HASH_RESULT,
  RTE_FLOW_FIELD_GENEVE_OPT_TYPE,
  RTE_FLOW_FIELD_GENEVE_OPT_CLASS,
  RTE_FLOW_FIELD_GENEVE_OPT_DATA,
  RTE_FLOW_FIELD_MPLS,
  RTE_FLOW_FIELD_TCP_DATA_OFFSET,
  RTE_FLOW_FIELD_IPV4_IHL,
  RTE_FLOW_FIELD_IPV4_TOTAL_LEN,
  RTE_FLOW_FIELD_IPV6_PAYLOAD_LEN,
  RTE_FLOW_FIELD_IPV4_PROTO,
  RTE_FLOW_FIELD_IPV6_FLOW_LABEL,
  RTE_FLOW_FIELD_IPV6_TRAFFIC_CLASS,
  RTE_FLOW_FIELD_ESP_SPI,
  RTE_FLOW_FIELD_ESP_SEQ_NUM,
  RTE_FLOW_FIELD_ESP_PROTO,
  RTE_FLOW_FIELD_RANDOM,
  RTE_FLOW_FIELD_VXLAN_LAST_RSVD,
};
struct rte_flow_field_data
{
  enum rte_flow_field_id field;
  union
  {
    struct
    {
      union
      {
        struct
        {
          uint8_t level;
          union
          {
            uint8_t tag_index;
            struct
            {
              uint8_t type;
              rte_be16_t class_id;
            };
          };
        };
        struct rte_flow_item_flex_handle *flex_handle;
      };
      uint32_t offset;
    };
    uint8_t value[16];
    void *pvalue;
  };
};
enum rte_flow_item_compare_op
{
  RTE_FLOW_ITEM_COMPARE_EQ,
  RTE_FLOW_ITEM_COMPARE_NE,
  RTE_FLOW_ITEM_COMPARE_LT,
  RTE_FLOW_ITEM_COMPARE_LE,
  RTE_FLOW_ITEM_COMPARE_GT,
  RTE_FLOW_ITEM_COMPARE_GE,
};
struct rte_flow_item_compare
{
  enum rte_flow_item_compare_op operation;
  struct rte_flow_field_data a;
  struct rte_flow_field_data b;
  uint32_t width;
};
enum rte_flow_action_type
{
  RTE_FLOW_ACTION_TYPE_END,
  RTE_FLOW_ACTION_TYPE_VOID,
  RTE_FLOW_ACTION_TYPE_PASSTHRU,
  RTE_FLOW_ACTION_TYPE_JUMP,
  RTE_FLOW_ACTION_TYPE_MARK,
  RTE_FLOW_ACTION_TYPE_FLAG,
  RTE_FLOW_ACTION_TYPE_QUEUE,
  RTE_FLOW_ACTION_TYPE_DROP,
  RTE_FLOW_ACTION_TYPE_COUNT,
  RTE_FLOW_ACTION_TYPE_RSS,
  RTE_FLOW_ACTION_TYPE_PF,
  RTE_FLOW_ACTION_TYPE_VF,
  RTE_FLOW_ACTION_TYPE_PORT_ID,
  RTE_FLOW_ACTION_TYPE_METER,
  RTE_FLOW_ACTION_TYPE_SECURITY,
  RTE_FLOW_ACTION_TYPE_OF_DEC_NW_TTL,
  RTE_FLOW_ACTION_TYPE_OF_POP_VLAN,
  RTE_FLOW_ACTION_TYPE_OF_PUSH_VLAN,
  RTE_FLOW_ACTION_TYPE_OF_SET_VLAN_VID,
  RTE_FLOW_ACTION_TYPE_OF_SET_VLAN_PCP,
  RTE_FLOW_ACTION_TYPE_OF_POP_MPLS,
  RTE_FLOW_ACTION_TYPE_OF_PUSH_MPLS,
  RTE_FLOW_ACTION_TYPE_VXLAN_ENCAP,
  RTE_FLOW_ACTION_TYPE_VXLAN_DECAP,
  RTE_FLOW_ACTION_TYPE_NVGRE_ENCAP,
  RTE_FLOW_ACTION_TYPE_NVGRE_DECAP,
  RTE_FLOW_ACTION_TYPE_RAW_ENCAP,
  RTE_FLOW_ACTION_TYPE_RAW_DECAP,
  RTE_FLOW_ACTION_TYPE_SET_IPV4_SRC,
  RTE_FLOW_ACTION_TYPE_SET_IPV4_DST,
  RTE_FLOW_ACTION_TYPE_SET_IPV6_SRC,
  RTE_FLOW_ACTION_TYPE_SET_IPV6_DST,
  RTE_FLOW_ACTION_TYPE_SET_TP_SRC,
  RTE_FLOW_ACTION_TYPE_SET_TP_DST,
  RTE_FLOW_ACTION_TYPE_MAC_SWAP,
  RTE_FLOW_ACTION_TYPE_DEC_TTL,
  RTE_FLOW_ACTION_TYPE_SET_TTL,
  RTE_FLOW_ACTION_TYPE_SET_MAC_SRC,
  RTE_FLOW_ACTION_TYPE_SET_MAC_DST,
  RTE_FLOW_ACTION_TYPE_INC_TCP_SEQ,
  RTE_FLOW_ACTION_TYPE_DEC_TCP_SEQ,
  RTE_FLOW_ACTION_TYPE_INC_TCP_ACK,
  RTE_FLOW_ACTION_TYPE_DEC_TCP_ACK,
  RTE_FLOW_ACTION_TYPE_SET_TAG,
  RTE_FLOW_ACTION_TYPE_SET_META,
  RTE_FLOW_ACTION_TYPE_SET_IPV4_DSCP,
  RTE_FLOW_ACTION_TYPE_SET_IPV6_DSCP,
  RTE_FLOW_ACTION_TYPE_AGE,
  RTE_FLOW_ACTION_TYPE_SAMPLE,
  RTE_FLOW_ACTION_TYPE_SHARED,
  RTE_FLOW_ACTION_TYPE_MODIFY_FIELD,
  RTE_FLOW_ACTION_TYPE_INDIRECT,
  RTE_FLOW_ACTION_TYPE_CONNTRACK,
  RTE_FLOW_ACTION_TYPE_METER_COLOR,
  RTE_FLOW_ACTION_TYPE_PORT_REPRESENTOR,
  RTE_FLOW_ACTION_TYPE_REPRESENTED_PORT,
  RTE_FLOW_ACTION_TYPE_METER_MARK,
  RTE_FLOW_ACTION_TYPE_SEND_TO_KERNEL,
  RTE_FLOW_ACTION_TYPE_QUOTA,
  RTE_FLOW_ACTION_TYPE_SKIP_CMAN,
  RTE_FLOW_ACTION_TYPE_IPV6_EXT_PUSH,
  RTE_FLOW_ACTION_TYPE_IPV6_EXT_REMOVE,
  RTE_FLOW_ACTION_TYPE_INDIRECT_LIST,
  RTE_FLOW_ACTION_TYPE_PROG,
  RTE_FLOW_ACTION_TYPE_NAT64,
};
enum rte_flow_quota_mode
{
  RTE_FLOW_QUOTA_MODE_PACKET = 1,
  RTE_FLOW_QUOTA_MODE_L2 = 2,
  RTE_FLOW_QUOTA_MODE_L3 = 3,
};
struct rte_flow_action_quota
{
  enum rte_flow_quota_mode mode;
  int64_t quota;
};
struct rte_flow_query_quota
{
  int64_t quota;
};
enum rte_flow_update_quota_op
{
  RTE_FLOW_UPDATE_QUOTA_SET,
  RTE_FLOW_UPDATE_QUOTA_ADD,
};
struct rte_flow_update_quota
{
  enum rte_flow_update_quota_op op;
  int64_t quota;
};
struct rte_flow_action_mark
{
  uint32_t id;
};
struct rte_flow_action_jump
{
  uint32_t group;
};
struct rte_flow_action_queue
{
  uint16_t index;
};
struct rte_flow_action_age
{
  uint32_t timeout : 24;
  uint32_t reserved : 8;
  void *context;
};
struct rte_flow_query_age
{
  uint32_t reserved : 6;
  uint32_t aged : 1;
  uint32_t sec_since_last_hit_valid : 1;
  uint32_t sec_since_last_hit : 24;
};
struct rte_flow_update_age
{
  uint32_t reserved : 6;
  uint32_t timeout_valid : 1;
  uint32_t timeout : 24;
  uint32_t touch : 1;
};
struct rte_flow_action_count
{
  uint32_t id;
};
struct rte_flow_query_count
{
  uint32_t reset : 1;
  uint32_t hits_set : 1;
  uint32_t bytes_set : 1;
  uint32_t reserved : 29;
  uint64_t hits;
  uint64_t bytes;
};
struct rte_flow_action_rss
{
  enum rte_eth_hash_function func;
  uint32_t level;
  uint64_t types;
  uint32_t key_len;
  uint32_t queue_num;
  const uint8_t *key;
  const uint16_t *queue;
};
struct rte_flow_action_vf
{
  uint32_t original : 1;
  uint32_t reserved : 31;
  uint32_t id;
};
struct rte_flow_action_port_id
{
  uint32_t original : 1;
  uint32_t reserved : 31;
  uint32_t id;
};
struct rte_flow_action_meter
{
  uint32_t mtr_id;
};
struct rte_flow_action_security
{
  void *security_session;
};
enum rte_flow_nat64_type
{
  RTE_FLOW_NAT64_6TO4 = 0,
  RTE_FLOW_NAT64_4TO6 = 1,
};
struct rte_flow_action_nat64
{
  enum rte_flow_nat64_type type;
};
struct rte_flow_action_of_push_vlan
{
  rte_be16_t ethertype;
};
struct rte_flow_action_of_set_vlan_vid
{
  rte_be16_t vlan_vid;
};
struct rte_flow_action_of_set_vlan_pcp
{
  uint8_t vlan_pcp;
};
struct rte_flow_action_of_pop_mpls
{
  rte_be16_t ethertype;
};
struct rte_flow_action_of_push_mpls
{
  rte_be16_t ethertype;
};
struct rte_flow_action_vxlan_encap
{
  struct rte_flow_item *definition;
};
struct rte_flow_action_nvgre_encap
{
  struct rte_flow_item *definition;
};
struct rte_flow_action_raw_encap
{
  uint8_t *data;
  uint8_t *preserve;
  size_t size;
};
struct rte_flow_action_raw_decap
{
  uint8_t *data;
  size_t size;
};
struct rte_flow_action_set_ipv4
{
  rte_be32_t ipv4_addr;
};
struct rte_flow_action_set_ipv6
{
  uint8_t ipv6_addr[16];
};
struct rte_flow_action_ipv6_ext_push
{
  uint8_t *data;
  size_t size;
  uint8_t type;
};
struct rte_flow_action_ipv6_ext_remove
{
  uint8_t type;
};
struct rte_flow_action_set_tp
{
  rte_be16_t port;
};
struct rte_flow_action_set_ttl
{
  uint8_t ttl_value;
};
struct rte_flow_action_set_mac
{
  uint8_t mac_addr[6];
};
struct rte_flow_action_set_tag
{
  uint32_t data;
  uint32_t mask;
  uint8_t index;
};
struct rte_flow_action_set_meta
{
  uint32_t data;
  uint32_t mask;
};
struct rte_flow_action_set_dscp
{
  uint8_t dscp;
};
struct rte_flow_action_handle;
enum rte_flow_conntrack_state
{
  RTE_FLOW_CONNTRACK_STATE_SYN_RECV,
  RTE_FLOW_CONNTRACK_STATE_ESTABLISHED,
  RTE_FLOW_CONNTRACK_STATE_FIN_WAIT,
  RTE_FLOW_CONNTRACK_STATE_CLOSE_WAIT,
  RTE_FLOW_CONNTRACK_STATE_LAST_ACK,
  RTE_FLOW_CONNTRACK_STATE_TIME_WAIT,
};
enum rte_flow_conntrack_tcp_last_index
{
  RTE_FLOW_CONNTRACK_FLAG_NONE = 0,
  RTE_FLOW_CONNTRACK_FLAG_SYN = (1U << (0)),
  RTE_FLOW_CONNTRACK_FLAG_SYNACK = (1U << (1)),
  RTE_FLOW_CONNTRACK_FLAG_FIN = (1U << (2)),
  RTE_FLOW_CONNTRACK_FLAG_ACK = (1U << (3)),
  RTE_FLOW_CONNTRACK_FLAG_RST = (1U << (4)),
};
struct rte_flow_tcp_dir_param
{
  uint32_t scale : 4;
  uint32_t close_initiated : 1;
  uint32_t last_ack_seen : 1;
  uint32_t data_unacked : 1;
  uint32_t sent_end;
  uint32_t reply_end;
  uint32_t max_win;
  uint32_t max_ack;
};
struct rte_flow_action_conntrack
{
  uint16_t peer_port;
  uint32_t is_original_dir : 1;
  uint32_t enable : 1;
  uint32_t live_connection : 1;
  uint32_t selective_ack : 1;
  uint32_t challenge_ack_passed : 1;
  uint32_t last_direction : 1;
  uint32_t liberal_mode : 1;
  enum rte_flow_conntrack_state state;
  uint8_t max_ack_window;
  uint8_t retransmission_limit;
  struct rte_flow_tcp_dir_param original_dir;
  struct rte_flow_tcp_dir_param reply_dir;
  uint16_t last_window;
  enum rte_flow_conntrack_tcp_last_index last_index;
  uint32_t last_seq;
  uint32_t last_ack;
  uint32_t last_end;
};
struct rte_flow_modify_conntrack
{
  struct rte_flow_action_conntrack new_ct;
  uint32_t direction : 1;
  uint32_t state : 1;
  uint32_t reserved : 30;
};
struct rte_flow_action_meter_color
{
  enum rte_color color;
};
struct rte_flow_action_ethdev
{
  uint16_t port_id;
};
enum rte_flow_modify_op
{
  RTE_FLOW_MODIFY_SET = 0,
  RTE_FLOW_MODIFY_ADD,
  RTE_FLOW_MODIFY_SUB,
};
struct rte_flow_action_modify_field
{
  enum rte_flow_modify_op operation;
  struct rte_flow_field_data dst;
  struct rte_flow_field_data src;
  uint32_t width;
};
struct rte_flow_action_meter_mark
{
  struct rte_flow_meter_profile *profile;
  struct rte_flow_meter_policy *policy;
  int color_mode;
  int state;
};
struct rte_flow_update_meter_mark
{
  struct rte_flow_action_meter_mark meter_mark;
  uint32_t profile_valid : 1;
  uint32_t policy_valid : 1;
  uint32_t color_mode_valid : 1;
  uint32_t state_valid : 1;
  uint32_t reserved : 28;
};
struct rte_flow_indirect_update_flow_meter_mark
{
  enum rte_color init_color;
};
struct rte_flow_action_prog_argument
{
  const char *name;
  uint32_t size;
  const uint8_t *value;
};
struct rte_flow_action_prog
{
  const char *name;
  uint32_t args_num;
  const struct rte_flow_action_prog_argument *args;
};
extern int32_t rte_flow_dynf_metadata_offs;
extern uint64_t rte_flow_dynf_metadata_mask;
__attribute__((section(".text.experimental"))) static inline uint32_t rte_flow_dynf_metadata_get(struct rte_mbuf *m)
{
  return *((uint32_t *)((uintptr_t)((m)) + (rte_flow_dynf_metadata_offs)));
}

__attribute__((section(".text.experimental"))) static inline void
rte_flow_dynf_metadata_set(struct rte_mbuf *m, uint32_t v)
{
  *((uint32_t *)((uintptr_t)((m)) + (rte_flow_dynf_metadata_offs))) = v;
}

struct rte_flow_action
{
  enum rte_flow_action_type type;
  const void *conf;
};
struct rte_flow;
struct rte_flow_meter_profile;
struct rte_flow_meter_policy;
struct rte_flow_action_sample
{
  uint32_t ratio;
  const struct rte_flow_action *actions;
};
enum rte_flow_error_type
{
  RTE_FLOW_ERROR_TYPE_NONE,
  RTE_FLOW_ERROR_TYPE_UNSPECIFIED,
  RTE_FLOW_ERROR_TYPE_HANDLE,
  RTE_FLOW_ERROR_TYPE_ATTR_GROUP,
  RTE_FLOW_ERROR_TYPE_ATTR_PRIORITY,
  RTE_FLOW_ERROR_TYPE_ATTR_INGRESS,
  RTE_FLOW_ERROR_TYPE_ATTR_EGRESS,
  RTE_FLOW_ERROR_TYPE_ATTR_TRANSFER,
  RTE_FLOW_ERROR_TYPE_ATTR,
  RTE_FLOW_ERROR_TYPE_ITEM_NUM,
  RTE_FLOW_ERROR_TYPE_ITEM_SPEC,
  RTE_FLOW_ERROR_TYPE_ITEM_LAST,
  RTE_FLOW_ERROR_TYPE_ITEM_MASK,
  RTE_FLOW_ERROR_TYPE_ITEM,
  RTE_FLOW_ERROR_TYPE_ACTION_NUM,
  RTE_FLOW_ERROR_TYPE_ACTION_CONF,
  RTE_FLOW_ERROR_TYPE_ACTION,
  RTE_FLOW_ERROR_TYPE_STATE,
};
struct rte_flow_error
{
  enum rte_flow_error_type type;
  const void *cause;
  const char *message;
};
struct rte_flow_conv_rule
{
  union
  {
    const struct rte_flow_attr *attr_ro;
    struct rte_flow_attr *attr;
  };
  union
  {
    const struct rte_flow_item *pattern_ro;
    struct rte_flow_item *pattern;
  };
  union
  {
    const struct rte_flow_action *actions_ro;
    struct rte_flow_action *actions;
  };
};
enum rte_flow_conv_op
{
  RTE_FLOW_CONV_OP_NONE,
  RTE_FLOW_CONV_OP_ATTR,
  RTE_FLOW_CONV_OP_ITEM,
  RTE_FLOW_CONV_OP_ITEM_MASK,
  RTE_FLOW_CONV_OP_ACTION,
  RTE_FLOW_CONV_OP_PATTERN,
  RTE_FLOW_CONV_OP_ACTIONS,
  RTE_FLOW_CONV_OP_RULE,
  RTE_FLOW_CONV_OP_ITEM_NAME,
  RTE_FLOW_CONV_OP_ACTION_NAME,
  RTE_FLOW_CONV_OP_ITEM_NAME_PTR,
  RTE_FLOW_CONV_OP_ACTION_NAME_PTR,
};
__attribute__((section(".text.experimental"))) int
rte_flow_dev_dump(uint16_t port_id, struct rte_flow *flow,
                  FILE *file, struct rte_flow_error *error);
__attribute__((section(".text.experimental"))) static inline int rte_flow_dynf_metadata_avail(void)
{
  return !!rte_flow_dynf_metadata_mask;
}

__attribute__((section(".text.experimental"))) int rte_flow_dynf_metadata_register(void);
int rte_flow_validate(uint16_t port_id,
                      const struct rte_flow_attr *attr,
                      const struct rte_flow_item pattern[],
                      const struct rte_flow_action actions[],
                      struct rte_flow_error *error);
struct rte_flow *rte_flow_create(uint16_t port_id,
                                 const struct rte_flow_attr *attr,
                                 const struct rte_flow_item pattern[],
                                 const struct rte_flow_action actions[],
                                 struct rte_flow_error *error);
int rte_flow_destroy(uint16_t port_id,
                     struct rte_flow *flow, struct rte_flow_error *error);
__attribute__((section(".text.experimental"))) int
rte_flow_actions_update(uint16_t port_id,
                        struct rte_flow *flow,
                        const struct rte_flow_action actions[],
                        struct rte_flow_error *error);
int rte_flow_flush(uint16_t port_id, struct rte_flow_error *error);
int rte_flow_query(uint16_t port_id,
                   struct rte_flow *flow,
                   const struct rte_flow_action *action,
                   void *data, struct rte_flow_error *error);
int rte_flow_isolate(uint16_t port_id, int set,
                     struct rte_flow_error *error);
int rte_flow_error_set(struct rte_flow_error *error,
                       int code,
                       enum rte_flow_error_type type,
                       const void *cause, const char *message);
struct rte_flow_desc
{
  size_t size;
  struct rte_flow_attr attr;
  struct rte_flow_item *items;
  struct rte_flow_action *actions;
  uint8_t data[];
};
__attribute__((__deprecated__))
size_t
rte_flow_copy(struct rte_flow_desc *fd, size_t len,
              const struct rte_flow_attr *attr,
              const struct rte_flow_item *items,
              const struct rte_flow_action *actions);
__attribute__((section(".text.experimental"))) int
rte_flow_conv(enum rte_flow_conv_op op,
              void *dst,
              size_t size,
              const void *src, struct rte_flow_error *error);
__attribute__((section(".text.experimental"))) int
rte_flow_get_aged_flows(uint16_t port_id, void **contexts,
                        uint32_t nb_contexts,
                        struct rte_flow_error *error);
__attribute__((section(".text.experimental"))) int
rte_flow_get_q_aged_flows(uint16_t port_id, uint32_t queue_id,
                          void **contexts, uint32_t nb_contexts,
                          struct rte_flow_error *error);
struct rte_flow_indir_action_conf
{
  uint32_t ingress : 1;
  uint32_t egress : 1;
  uint32_t transfer : 1;
};
__attribute__((section(".text.experimental"))) struct rte_flow_action_handle *rte_flow_action_handle_create(uint16_t
                                                                                                                port_id,
                                                                                                            const struct
                                                                                                            rte_flow_indir_action_conf
                                                                                                                *conf,
                                                                                                            const struct
                                                                                                            rte_flow_action
                                                                                                                *action,
                                                                                                            struct
                                                                                                            rte_flow_error
                                                                                                                *error);
__attribute__((section(".text.experimental"))) int
rte_flow_action_handle_destroy(uint16_t port_id,
                               struct rte_flow_action_handle *handle,
                               struct rte_flow_error *error);
__attribute__((section(".text.experimental"))) int
rte_flow_action_handle_update(uint16_t port_id,
                              struct rte_flow_action_handle *handle,
                              const void *update,
                              struct rte_flow_error *error);
__attribute__((section(".text.experimental"))) int
rte_flow_action_handle_query(uint16_t port_id,
                             const struct rte_flow_action_handle
                                 *handle,
                             void *data,
                             struct rte_flow_error *error);
struct rte_flow_tunnel
{
  enum rte_flow_item_type type;
  uint64_t tun_id;
  union
  {
    struct
    {
      rte_be32_t src_addr;
      rte_be32_t dst_addr;
    } ipv4;
    struct
    {
      uint8_t src_addr[16];
      uint8_t dst_addr[16];
    } ipv6;
  };
  rte_be16_t tp_src;
  rte_be16_t tp_dst;
  uint16_t tun_flags;
  _Bool is_ipv6;
  uint8_t tos;
  uint8_t ttl;
  uint32_t label;
};
struct rte_flow_restore_info
{
  uint64_t flags;
  uint32_t group_id;
  struct rte_flow_tunnel tunnel;
};
__attribute__((section(".text.experimental"))) int
rte_flow_tunnel_decap_set(uint16_t port_id,
                          struct rte_flow_tunnel *tunnel,
                          struct rte_flow_action **actions,
                          uint32_t *num_of_actions,
                          struct rte_flow_error *error);
__attribute__((section(".text.experimental"))) int
rte_flow_tunnel_match(uint16_t port_id,
                      struct rte_flow_tunnel *tunnel,
                      struct rte_flow_item **items,
                      uint32_t *num_of_items,
                      struct rte_flow_error *error);
__attribute__((section(".text.experimental"))) uint64_t
rte_flow_restore_info_dynflag(void);
__attribute__((section(".text.experimental"))) int
rte_flow_get_restore_info(uint16_t port_id,
                          struct rte_mbuf *m,
                          struct rte_flow_restore_info *info,
                          struct rte_flow_error *error);
__attribute__((section(".text.experimental"))) int
rte_flow_tunnel_action_decap_release(uint16_t port_id,
                                     struct rte_flow_action *actions,
                                     uint32_t num_of_actions,
                                     struct rte_flow_error *error);
__attribute__((section(".text.experimental"))) int
rte_flow_tunnel_item_release(uint16_t port_id,
                             struct rte_flow_item *items,
                             uint32_t num_of_items,
                             struct rte_flow_error *error);
int rte_flow_pick_transfer_proxy(uint16_t port_id,
                                 uint16_t *proxy_port_id,
                                 struct rte_flow_error *error);
__attribute__((section(".text.experimental"))) struct rte_flow_item_flex_handle *rte_flow_flex_item_create(uint16_t
                                                                                                               port_id,
                                                                                                           const struct
                                                                                                           rte_flow_item_flex_conf
                                                                                                               *conf,
                                                                                                           struct
                                                                                                           rte_flow_error
                                                                                                               *error);
__attribute__((section(".text.experimental"))) int
rte_flow_flex_item_release(uint16_t port_id,
                           const struct rte_flow_item_flex_handle
                               *handle,
                           struct rte_flow_error *error);
struct rte_flow_port_info
{
  uint32_t max_nb_queues;
  uint32_t max_nb_counters;
  uint32_t max_nb_aging_objects;
  uint32_t max_nb_meters;
  uint32_t max_nb_conn_tracks;
  uint32_t max_nb_quotas;
  uint32_t supported_flags;
};
struct rte_flow_queue_info
{
  uint32_t max_size;
};
__attribute__((section(".text.experimental"))) int
rte_flow_info_get(uint16_t port_id,
                  struct rte_flow_port_info *port_info,
                  struct rte_flow_queue_info *queue_info,
                  struct rte_flow_error *error);
struct rte_flow_port_attr
{
  uint32_t nb_counters;
  uint32_t nb_aging_objects;
  uint32_t nb_meters;
  uint32_t nb_conn_tracks;
  uint16_t host_port_id;
  uint32_t nb_quotas;
  uint32_t flags;
};
struct rte_flow_queue_attr
{
  uint32_t size;
};
__attribute__((section(".text.experimental"))) int
rte_flow_configure(uint16_t port_id,
                   const struct rte_flow_port_attr *port_attr,
                   uint16_t nb_queue,
                   const struct rte_flow_queue_attr *queue_attr[],
                   struct rte_flow_error *error);
struct rte_flow_pattern_template;
__extension__ struct rte_flow_pattern_template_attr
{
  uint32_t relaxed_matching : 1;
  uint32_t ingress : 1;
  uint32_t egress : 1;
  uint32_t transfer : 1;
};
__attribute__((section(".text.experimental"))) struct rte_flow_pattern_template *rte_flow_pattern_template_create(uint16_t port_id,
                                                                                                                  const struct
                                                                                                                  rte_flow_pattern_template_attr
                                                                                                                      *template_attr,
                                                                                                                  const struct rte_flow_item
                                                                                                                      pattern[],
                                                                                                                  struct rte_flow_error *error);
__attribute__((section(".text.experimental"))) int
rte_flow_pattern_template_destroy(uint16_t port_id,
                                  struct rte_flow_pattern_template
                                      *pattern_template,
                                  struct rte_flow_error *error);
struct rte_flow_actions_template;
__extension__ struct rte_flow_actions_template_attr
{
  uint32_t ingress : 1;
  uint32_t egress : 1;
  uint32_t transfer : 1;
};
__attribute__((section(".text.experimental"))) struct rte_flow_actions_template *rte_flow_actions_template_create(uint16_t port_id,
                                                                                                                  const struct
                                                                                                                  rte_flow_actions_template_attr
                                                                                                                      *template_attr,
                                                                                                                  const struct rte_flow_action
                                                                                                                      actions[],
                                                                                                                  const struct rte_flow_action
                                                                                                                      masks[],
                                                                                                                  struct rte_flow_error *error);
__attribute__((section(".text.experimental"))) int
rte_flow_actions_template_destroy(uint16_t port_id,
                                  struct rte_flow_actions_template
                                      *actions_template,
                                  struct rte_flow_error *error);
struct rte_flow_template_table;
enum rte_flow_table_insertion_type
{
  RTE_FLOW_TABLE_INSERTION_TYPE_PATTERN,
  RTE_FLOW_TABLE_INSERTION_TYPE_INDEX,
};
enum rte_flow_table_hash_func
{
  RTE_FLOW_TABLE_HASH_FUNC_DEFAULT,
  RTE_FLOW_TABLE_HASH_FUNC_LINEAR,
  RTE_FLOW_TABLE_HASH_FUNC_CRC32,
  RTE_FLOW_TABLE_HASH_FUNC_CRC16,
};
struct rte_flow_template_table_attr
{
  struct rte_flow_attr flow_attr;
  uint32_t nb_flows;
  uint32_t specialize;
  enum rte_flow_table_insertion_type insertion_type;
  enum rte_flow_table_hash_func hash_func;
};
__attribute__((section(".text.experimental")))
_Bool
rte_flow_template_table_resizable(__attribute__((__unused__))
                                  uint16_t port_id,
                                  const struct
                                  rte_flow_template_table_attr
                                      *tbl_attr);
__attribute__((section(".text.experimental"))) struct rte_flow_template_table *rte_flow_template_table_create(uint16_t
                                                                                                                  port_id,
                                                                                                              const struct
                                                                                                              rte_flow_template_table_attr
                                                                                                                  *table_attr,
                                                                                                              struct
                                                                                                              rte_flow_pattern_template
                                                                                                                  *pattern_templates
                                                                                                                      [],
                                                                                                              uint8_t
                                                                                                                  nb_pattern_templates,
                                                                                                              struct
                                                                                                              rte_flow_actions_template
                                                                                                                  *actions_templates
                                                                                                                      [],
                                                                                                              uint8_t
                                                                                                                  nb_actions_templates,
                                                                                                              struct
                                                                                                              rte_flow_error
                                                                                                                  *error);
__attribute__((section(".text.experimental"))) int
rte_flow_template_table_destroy(uint16_t port_id,
                                struct rte_flow_template_table
                                    *template_table,
                                struct rte_flow_error *error);
__attribute__((section(".text.experimental"))) int
rte_flow_group_set_miss_actions(uint16_t port_id,
                                uint32_t group_id,
                                const struct rte_flow_group_attr
                                    *attr,
                                const struct rte_flow_action
                                    actions[],
                                struct rte_flow_error *error);
__extension__ struct rte_flow_op_attr
{
  uint32_t postpone : 1;
};
__attribute__((section(".text.experimental"))) struct rte_flow *rte_flow_async_create(uint16_t port_id,
                                                                                      uint32_t queue_id,
                                                                                      const struct rte_flow_op_attr
                                                                                          *op_attr,
                                                                                      struct rte_flow_template_table
                                                                                          *template_table,
                                                                                      const struct rte_flow_item
                                                                                          pattern[],
                                                                                      uint8_t pattern_template_index,
                                                                                      const struct rte_flow_action
                                                                                          actions[],
                                                                                      uint8_t actions_template_index,
                                                                                      void *user_data,
                                                                                      struct rte_flow_error *error);
__attribute__((section(".text.experimental"))) struct rte_flow *rte_flow_async_create_by_index(uint16_t port_id,
                                                                                               uint32_t queue_id,
                                                                                               const struct
                                                                                               rte_flow_op_attr
                                                                                                   *op_attr,
                                                                                               struct
                                                                                               rte_flow_template_table
                                                                                                   *template_table,
                                                                                               uint32_t rule_index,
                                                                                               const struct
                                                                                               rte_flow_action
                                                                                                   actions[],
                                                                                               uint8_t
                                                                                                   actions_template_index,
                                                                                               void *user_data,
                                                                                               struct rte_flow_error
                                                                                                   *error);
__attribute__((section(".text.experimental"))) int
rte_flow_async_destroy(uint16_t port_id,
                       uint32_t queue_id,
                       const struct rte_flow_op_attr *op_attr,
                       struct rte_flow *flow,
                       void *user_data, struct rte_flow_error *error);
__attribute__((section(".text.experimental"))) int
rte_flow_async_actions_update(uint16_t port_id,
                              uint32_t queue_id,
                              const struct rte_flow_op_attr *op_attr,
                              struct rte_flow *flow,
                              const struct rte_flow_action actions[],
                              uint8_t actions_template_index,
                              void *user_data,
                              struct rte_flow_error *error);
__attribute__((section(".text.experimental"))) int
rte_flow_push(uint16_t port_id,
              uint32_t queue_id, struct rte_flow_error *error);
enum rte_flow_op_status
{
  RTE_FLOW_OP_SUCCESS,
  RTE_FLOW_OP_ERROR,
};
__extension__ struct rte_flow_op_result
{
  enum rte_flow_op_status status;
  void *user_data;
};
__attribute__((section(".text.experimental"))) int
rte_flow_pull(uint16_t port_id,
              uint32_t queue_id,
              struct rte_flow_op_result res[],
              uint16_t n_res, struct rte_flow_error *error);
__attribute__((section(".text.experimental"))) struct rte_flow_action_handle *rte_flow_async_action_handle_create(uint16_t port_id,
                                                                                                                  uint32_t queue_id,
                                                                                                                  const struct rte_flow_op_attr
                                                                                                                      *op_attr,
                                                                                                                  const struct
                                                                                                                  rte_flow_indir_action_conf
                                                                                                                      *indir_action_conf,
                                                                                                                  const struct rte_flow_action
                                                                                                                      *action,
                                                                                                                  void *user_data,
                                                                                                                  struct rte_flow_error *error);
__attribute__((section(".text.experimental"))) int
rte_flow_async_action_handle_destroy(uint16_t port_id,
                                     uint32_t queue_id,
                                     const struct rte_flow_op_attr
                                         *op_attr,
                                     struct rte_flow_action_handle
                                         *action_handle,
                                     void *user_data,
                                     struct rte_flow_error *error);
__attribute__((section(".text.experimental"))) int
rte_flow_async_action_handle_update(uint16_t port_id,
                                    uint32_t queue_id,
                                    const struct rte_flow_op_attr
                                        *op_attr,
                                    struct rte_flow_action_handle
                                        *action_handle,
                                    const void *update,
                                    void *user_data,
                                    struct rte_flow_error *error);
__attribute__((section(".text.experimental"))) int
rte_flow_async_action_handle_query(uint16_t port_id,
                                   uint32_t queue_id,
                                   const struct rte_flow_op_attr
                                       *op_attr,
                                   const struct rte_flow_action_handle
                                       *action_handle,
                                   void *data,
                                   void *user_data,
                                   struct rte_flow_error *error);
enum rte_flow_query_update_mode
{
  RTE_FLOW_QU_QUERY_FIRST = 1,
  RTE_FLOW_QU_UPDATE_FIRST,
};
__attribute__((section(".text.experimental"))) int
rte_flow_action_handle_query_update(uint16_t port_id,
                                    struct rte_flow_action_handle
                                        *handle,
                                    const void *update,
                                    void *query,
                                    enum rte_flow_query_update_mode
                                        mode,
                                    struct rte_flow_error *error);
__attribute__((section(".text.experimental"))) int
rte_flow_async_action_handle_query_update(uint16_t port_id,
                                          uint32_t queue_id,
                                          const struct
                                          rte_flow_op_attr *attr,
                                          struct
                                          rte_flow_action_handle
                                              *handle,
                                          const void *update,
                                          void *query,
                                          enum rte_flow_query_update_mode
                                              mode,
                                          void *user_data,
                                          struct rte_flow_error
                                              *error);
struct rte_flow_action_list_handle;
struct rte_flow_action_indirect_list
{
  struct rte_flow_action_list_handle *handle;
  const void **conf;
};
__attribute__((section(".text.experimental"))) struct rte_flow_action_list_handle *rte_flow_action_list_handle_create(uint16_t port_id,
                                                                                                                      const struct
                                                                                                                      rte_flow_indir_action_conf *conf,
                                                                                                                      const struct rte_flow_action
                                                                                                                          *actions,
                                                                                                                      struct rte_flow_error *error);
__attribute__((section(".text.experimental"))) struct rte_flow_action_list_handle *rte_flow_async_action_list_handle_create(uint16_t port_id,
                                                                                                                            uint32_t queue_id,
                                                                                                                            const struct
                                                                                                                            rte_flow_op_attr *attr,
                                                                                                                            const struct
                                                                                                                            rte_flow_indir_action_conf
                                                                                                                                *conf,
                                                                                                                            const struct rte_flow_action
                                                                                                                                *actions,
                                                                                                                            void *user_data,
                                                                                                                            struct rte_flow_error
                                                                                                                                *error);
__attribute__((section(".text.experimental"))) int
rte_flow_action_list_handle_destroy(uint16_t port_id,
                                    struct rte_flow_action_list_handle
                                        *handle,
                                    struct rte_flow_error *error);
__attribute__((section(".text.experimental"))) int
rte_flow_async_action_list_handle_destroy(uint16_t port_id, uint32_t queue_id,
                                          const struct rte_flow_op_attr *op_attr,
                                          struct rte_flow_action_list_handle *handle,
                                          void *user_data, struct rte_flow_error *error);
__attribute__((section(".text.experimental"))) int
rte_flow_action_list_handle_query_update(uint16_t port_id,
                                         const struct
                                         rte_flow_action_list_handle
                                             *handle,
                                         const void **update,
                                         void **query,
                                         enum rte_flow_query_update_mode
                                             mode,
                                         struct rte_flow_error
                                             *error);
__attribute__((section(".text.experimental"))) int
rte_flow_async_action_list_handle_query_update(uint16_t port_id,
                                               uint32_t queue_id,
                                               const struct
                                               rte_flow_op_attr *attr,
                                               const struct
                                               rte_flow_action_list_handle
                                                   *handle,
                                               const void **update,
                                               void **query,
                                               enum rte_flow_query_update_mode
                                                   mode,
                                               void *user_data,
                                               struct rte_flow_error
                                                   *error);
__attribute__((section(".text.experimental"))) int
rte_flow_calc_table_hash(uint16_t port_id,
                         const struct rte_flow_template_table *table,
                         const struct rte_flow_item pattern[],
                         uint8_t pattern_template_index,
                         uint32_t *hash,
                         struct rte_flow_error *error);
enum rte_flow_encap_hash_field
{
  RTE_FLOW_ENCAP_HASH_FIELD_SRC_PORT,
  RTE_FLOW_ENCAP_HASH_FIELD_NVGRE_FLOW_ID,
};
__attribute__((section(".text.experimental"))) int
rte_flow_calc_encap_hash(uint16_t port_id,
                         const struct rte_flow_item pattern[],
                         enum rte_flow_encap_hash_field dest_field,
                         uint8_t hash_len, uint8_t *hash,
                         struct rte_flow_error *error);
__attribute__((section(".text.experimental"))) int
rte_flow_template_table_resize(uint16_t port_id,
                               struct rte_flow_template_table *table,
                               uint32_t nb_rules,
                               struct rte_flow_error *error);
__attribute__((section(".text.experimental"))) int
rte_flow_async_update_resized(uint16_t port_id, uint32_t queue,
                              const struct rte_flow_op_attr *attr,
                              struct rte_flow *rule, void *user_data,
                              struct rte_flow_error *error);
__attribute__((section(".text.experimental"))) int
rte_flow_template_table_resize_complete(uint16_t port_id,
                                        struct rte_flow_template_table
                                            *table,
                                        struct rte_flow_error *error);
struct rte_eth_ntuple_filter
{
  uint16_t flags;
  uint32_t dst_ip;
  uint32_t dst_ip_mask;
  uint32_t src_ip;
  uint32_t src_ip_mask;
  uint16_t dst_port;
  uint16_t dst_port_mask;
  uint16_t src_port;
  uint16_t src_port_mask;
  uint8_t proto;
  uint8_t proto_mask;
  uint8_t tcp_flags;
  uint16_t priority;
  uint16_t queue;
};
enum rte_eth_input_set_field
{
  RTE_ETH_INPUT_SET_UNKNOWN = 0,
  RTE_ETH_INPUT_SET_L2_SRC_MAC = 1,
  RTE_ETH_INPUT_SET_L2_DST_MAC,
  RTE_ETH_INPUT_SET_L2_OUTER_VLAN,
  RTE_ETH_INPUT_SET_L2_INNER_VLAN,
  RTE_ETH_INPUT_SET_L2_ETHERTYPE,
  RTE_ETH_INPUT_SET_L3_SRC_IP4 = 129,
  RTE_ETH_INPUT_SET_L3_DST_IP4,
  RTE_ETH_INPUT_SET_L3_SRC_IP6,
  RTE_ETH_INPUT_SET_L3_DST_IP6,
  RTE_ETH_INPUT_SET_L3_IP4_TOS,
  RTE_ETH_INPUT_SET_L3_IP4_PROTO,
  RTE_ETH_INPUT_SET_L3_IP6_TC,
  RTE_ETH_INPUT_SET_L3_IP6_NEXT_HEADER,
  RTE_ETH_INPUT_SET_L3_IP4_TTL,
  RTE_ETH_INPUT_SET_L3_IP6_HOP_LIMITS,
  RTE_ETH_INPUT_SET_L4_UDP_SRC_PORT = 257,
  RTE_ETH_INPUT_SET_L4_UDP_DST_PORT,
  RTE_ETH_INPUT_SET_L4_TCP_SRC_PORT,
  RTE_ETH_INPUT_SET_L4_TCP_DST_PORT,
  RTE_ETH_INPUT_SET_L4_SCTP_SRC_PORT,
  RTE_ETH_INPUT_SET_L4_SCTP_DST_PORT,
  RTE_ETH_INPUT_SET_L4_SCTP_VERIFICATION_TAG,
  RTE_ETH_INPUT_SET_TUNNEL_L2_INNER_DST_MAC = 385,
  RTE_ETH_INPUT_SET_TUNNEL_L2_INNER_SRC_MAC,
  RTE_ETH_INPUT_SET_TUNNEL_L2_INNER_VLAN,
  RTE_ETH_INPUT_SET_TUNNEL_L4_UDP_KEY,
  RTE_ETH_INPUT_SET_TUNNEL_GRE_KEY,
  RTE_ETH_INPUT_SET_FLEX_PAYLOAD_1ST_WORD = 641,
  RTE_ETH_INPUT_SET_FLEX_PAYLOAD_2ND_WORD,
  RTE_ETH_INPUT_SET_FLEX_PAYLOAD_3RD_WORD,
  RTE_ETH_INPUT_SET_FLEX_PAYLOAD_4TH_WORD,
  RTE_ETH_INPUT_SET_FLEX_PAYLOAD_5TH_WORD,
  RTE_ETH_INPUT_SET_FLEX_PAYLOAD_6TH_WORD,
  RTE_ETH_INPUT_SET_FLEX_PAYLOAD_7TH_WORD,
  RTE_ETH_INPUT_SET_FLEX_PAYLOAD_8TH_WORD,
  RTE_ETH_INPUT_SET_DEFAULT = 65533,
  RTE_ETH_INPUT_SET_NONE = 65534,
  RTE_ETH_INPUT_SET_MAX = 65535,
};
enum rte_filter_input_set_op
{
  RTE_ETH_INPUT_SET_OP_UNKNOWN,
  RTE_ETH_INPUT_SET_SELECT,
  RTE_ETH_INPUT_SET_ADD,
  RTE_ETH_INPUT_SET_OP_MAX
};
struct rte_eth_input_set_conf
{
  uint16_t flow_type;
  uint16_t inset_size;
  enum rte_eth_input_set_field field[128];
  enum rte_filter_input_set_op op;
};
struct rte_eth_l2_flow
{
  uint16_t ether_type;
};
struct rte_eth_ipv4_flow
{
  uint32_t src_ip;
  uint32_t dst_ip;
  uint8_t tos;
  uint8_t ttl;
  uint8_t proto;
};
struct rte_eth_udpv4_flow
{
  struct rte_eth_ipv4_flow ip;
  uint16_t src_port;
  uint16_t dst_port;
};
struct rte_eth_tcpv4_flow
{
  struct rte_eth_ipv4_flow ip;
  uint16_t src_port;
  uint16_t dst_port;
};
struct rte_eth_sctpv4_flow
{
  struct rte_eth_ipv4_flow ip;
  uint16_t src_port;
  uint16_t dst_port;
  uint32_t verify_tag;
};
struct rte_eth_ipv6_flow
{
  uint32_t src_ip[4];
  uint32_t dst_ip[4];
  uint8_t tc;
  uint8_t proto;
  uint8_t hop_limits;
};
struct rte_eth_udpv6_flow
{
  struct rte_eth_ipv6_flow ip;
  uint16_t src_port;
  uint16_t dst_port;
};
struct rte_eth_tcpv6_flow
{
  struct rte_eth_ipv6_flow ip;
  uint16_t src_port;
  uint16_t dst_port;
};
struct rte_eth_sctpv6_flow
{
  struct rte_eth_ipv6_flow ip;
  uint16_t src_port;
  uint16_t dst_port;
  uint32_t verify_tag;
};
struct rte_eth_mac_vlan_flow
{
  struct rte_ether_addr mac_addr;
};
enum rte_eth_fdir_tunnel_type
{
  RTE_FDIR_TUNNEL_TYPE_UNKNOWN = 0,
  RTE_FDIR_TUNNEL_TYPE_NVGRE,
  RTE_FDIR_TUNNEL_TYPE_VXLAN,
};
struct rte_eth_tunnel_flow
{
  enum rte_eth_fdir_tunnel_type tunnel_type;
  uint32_t tunnel_id;
  struct rte_ether_addr mac_addr;
};
union rte_eth_fdir_flow
{
  struct rte_eth_l2_flow l2_flow;
  struct rte_eth_udpv4_flow udp4_flow;
  struct rte_eth_tcpv4_flow tcp4_flow;
  struct rte_eth_sctpv4_flow sctp4_flow;
  struct rte_eth_ipv4_flow ip4_flow;
  struct rte_eth_udpv6_flow udp6_flow;
  struct rte_eth_tcpv6_flow tcp6_flow;
  struct rte_eth_sctpv6_flow sctp6_flow;
  struct rte_eth_ipv6_flow ipv6_flow;
  struct rte_eth_mac_vlan_flow mac_vlan_flow;
  struct rte_eth_tunnel_flow tunnel_flow;
};
struct rte_eth_fdir_flow_ext
{
  uint16_t vlan_tci;
  uint8_t flexbytes[16];
  uint8_t is_vf;
  uint16_t dst_id;
};
struct rte_eth_fdir_input
{
  uint16_t flow_type;
  union rte_eth_fdir_flow flow;
  struct rte_eth_fdir_flow_ext flow_ext;
};
enum rte_eth_fdir_behavior
{
  RTE_ETH_FDIR_ACCEPT = 0,
  RTE_ETH_FDIR_REJECT,
  RTE_ETH_FDIR_PASSTHRU,
};
enum rte_eth_fdir_status
{
  RTE_ETH_FDIR_NO_REPORT_STATUS = 0,
  RTE_ETH_FDIR_REPORT_ID,
  RTE_ETH_FDIR_REPORT_ID_FLEX_4,
  RTE_ETH_FDIR_REPORT_FLEX_8,
};
struct rte_eth_fdir_action
{
  uint16_t rx_queue;
  enum rte_eth_fdir_behavior behavior;
  enum rte_eth_fdir_status report_status;
  uint8_t flex_off;
};
struct rte_eth_fdir_filter
{
  uint32_t soft_id;
  struct rte_eth_fdir_input input;
  struct rte_eth_fdir_action action;
};
struct rte_eth_fdir_masks
{
  uint16_t vlan_tci_mask;
  struct rte_eth_ipv4_flow ipv4_mask;
  struct rte_eth_ipv6_flow ipv6_mask;
  uint16_t src_port_mask;
  uint16_t dst_port_mask;
  uint8_t mac_addr_byte_mask;
  uint32_t tunnel_id_mask;
  uint8_t tunnel_type_mask;
};
enum rte_eth_payload_type
{
  RTE_ETH_PAYLOAD_UNKNOWN = 0,
  RTE_ETH_RAW_PAYLOAD,
  RTE_ETH_L2_PAYLOAD,
  RTE_ETH_L3_PAYLOAD,
  RTE_ETH_L4_PAYLOAD,
  RTE_ETH_PAYLOAD_MAX = 8,
};
struct rte_eth_flex_payload_cfg
{
  enum rte_eth_payload_type type;
  uint16_t src_offset[16];
};
struct rte_eth_fdir_flex_mask
{
  uint16_t flow_type;
  uint8_t mask[16];
};
struct rte_eth_fdir_flex_conf
{
  uint16_t nb_payloads;
  uint16_t nb_flexmasks;
  struct rte_eth_flex_payload_cfg flex_set[RTE_ETH_PAYLOAD_MAX];
  struct rte_eth_fdir_flex_mask flex_mask[24];
};
enum rte_fdir_mode
{
  RTE_FDIR_MODE_NONE = 0,
  RTE_FDIR_MODE_SIGNATURE,
  RTE_FDIR_MODE_PERFECT,
  RTE_FDIR_MODE_PERFECT_MAC_VLAN,
  RTE_FDIR_MODE_PERFECT_TUNNEL,
};
struct rte_eth_fdir_info
{
  enum rte_fdir_mode mode;
  struct rte_eth_fdir_masks mask;
  struct rte_eth_fdir_flex_conf flex_conf;
  uint32_t guarant_spc;
  uint32_t best_spc;
  uint64_t flow_types_mask[((__typeof__(((24) + ((__typeof__(24))((8 * sizeof(uint64_t))) - 1))))((((24) +
                                                                                                    ((__typeof__(24))((8 * sizeof(uint64_t))) -
                                                                                                     1))) &
                                                                                                  (~((__typeof__(((24) +
                                                                                                                  ((__typeof__(24))((8 * sizeof(uint64_t))) - 1))))(((8 * sizeof(uint64_t))) - 1)))) /
                            (8 * sizeof(uint64_t)))];
  uint32_t max_flexpayload;
  uint32_t flex_payload_unit;
  uint32_t max_flex_payload_segment_num;
  uint16_t flex_payload_limit;
  uint32_t flex_bitmask_unit;
  uint32_t max_flex_bitmask_num;
};
struct rte_eth_fdir_stats
{
  uint32_t collision;
  uint32_t free;
  uint32_t maxhash;
  uint32_t maxlen;
  uint64_t add;
  uint64_t remove;
  uint64_t f_add;
  uint64_t f_remove;
  uint32_t guarant_cnt;
  uint32_t best_cnt;
};
struct rte_eth_udp_tunnel
{
  uint16_t udp_port;
  uint8_t prot_type;
};
struct rte_eth_intr_conf
{
  uint32_t lsc : 1;
  uint32_t rxq : 1;
  uint32_t rmv : 1;
};
struct rte_eth_conf
{
  uint32_t link_speeds;
  struct rte_eth_rxmode rxmode;
  struct rte_eth_txmode txmode;
  uint32_t lpbk_mode;
  struct
  {
    struct rte_eth_rss_conf rss_conf;
    struct rte_eth_vmdq_dcb_conf vmdq_dcb_conf;
    struct rte_eth_dcb_rx_conf dcb_rx_conf;
    struct rte_eth_vmdq_rx_conf vmdq_rx_conf;
  } rx_adv_conf;
  union
  {
    struct rte_eth_vmdq_dcb_tx_conf vmdq_dcb_tx_conf;
    struct rte_eth_dcb_tx_conf dcb_tx_conf;
    struct rte_eth_vmdq_tx_conf vmdq_tx_conf;
  } tx_adv_conf;
  uint32_t dcb_capability_en;
  struct rte_eth_intr_conf intr_conf;
};
struct rte_eth_dev_portconf
{
  uint16_t burst_size;
  uint16_t ring_size;
  uint16_t nb_queues;
};
struct rte_eth_switch_info
{
  const char *name;
  uint16_t domain_id;
  uint16_t port_id;
  uint16_t rx_domain;
};
struct rte_eth_rxseg_capa
{
  __extension__ uint32_t multi_pools : 1;
  uint32_t offset_allowed : 1;
  uint32_t offset_align_log2 : 4;
  uint16_t max_nseg;
  uint16_t reserved;
};
enum rte_eth_representor_type
{
  RTE_ETH_REPRESENTOR_NONE,
  RTE_ETH_REPRESENTOR_VF,
  RTE_ETH_REPRESENTOR_SF,
  RTE_ETH_REPRESENTOR_PF,
};
enum rte_eth_err_handle_mode
{
  RTE_ETH_ERROR_HANDLE_MODE_NONE,
  RTE_ETH_ERROR_HANDLE_MODE_PASSIVE,
  RTE_ETH_ERROR_HANDLE_MODE_PROACTIVE,
};
struct rte_eth_dev_info
{
  struct rte_device *device;
  const char *driver_name;
  unsigned int if_index;
  uint16_t min_mtu;
  uint16_t max_mtu;
  const uint32_t *dev_flags;
  uint32_t min_rx_bufsize;
  uint32_t max_rx_bufsize;
  uint32_t max_rx_pktlen;
  uint32_t max_lro_pkt_size;
  uint16_t max_rx_queues;
  uint16_t max_tx_queues;
  uint32_t max_mac_addrs;
  uint32_t max_hash_mac_addrs;
  uint16_t max_vfs;
  uint16_t max_vmdq_pools;
  struct rte_eth_rxseg_capa rx_seg_capa;
  uint64_t rx_offload_capa;
  uint64_t tx_offload_capa;
  uint64_t rx_queue_offload_capa;
  uint64_t tx_queue_offload_capa;
  uint16_t reta_size;
  uint8_t hash_key_size;
  uint32_t rss_algo_capa;
  uint64_t flow_type_rss_offloads;
  struct rte_eth_rxconf default_rxconf;
  struct rte_eth_txconf default_txconf;
  uint16_t vmdq_queue_base;
  uint16_t vmdq_queue_num;
  uint16_t vmdq_pool_base;
  struct rte_eth_desc_lim rx_desc_lim;
  struct rte_eth_desc_lim tx_desc_lim;
  uint32_t speed_capa;
  uint16_t nb_rx_queues;
  uint16_t nb_tx_queues;
  uint16_t max_rx_mempools;
  struct rte_eth_dev_portconf default_rxportconf;
  struct rte_eth_dev_portconf default_txportconf;
  uint64_t dev_capa;
  struct rte_eth_switch_info switch_info;
  enum rte_eth_err_handle_mode err_handle_mode;
  uint64_t reserved_64s[2];
  void *reserved_ptrs[2];
};
struct __attribute__((__aligned__(64))) rte_eth_rxq_info
{
  struct rte_mempool *mp;
  struct rte_eth_rxconf conf;
  uint8_t scattered_rx;
  uint8_t queue_state;
  uint16_t nb_desc;
  uint16_t rx_buf_size;
  uint8_t avail_thresh;
};

struct __attribute__((__aligned__(64))) rte_eth_txq_info
{
  struct rte_eth_txconf conf;
  uint16_t nb_desc;
  uint8_t queue_state;
};

struct __attribute__((__aligned__(64))) rte_eth_recycle_rxq_info
{
  struct rte_mbuf **mbuf_ring;
  struct rte_mempool *mp;
  uint16_t *refill_head;
  uint16_t *receive_tail;
  uint16_t mbuf_ring_size;
  uint16_t refill_requirement;
};

struct rte_eth_burst_mode
{
  uint64_t flags;
  char info[1024];
};
struct rte_eth_xstat
{
  uint64_t id;
  uint64_t value;
};
struct rte_eth_xstat_name
{
  char name[64];
};
struct rte_eth_dcb_tc_queue_mapping
{
  struct
  {
    uint16_t base;
    uint16_t nb_queue;
  } tc_rxq[64][8];
  struct
  {
    uint16_t base;
    uint16_t nb_queue;
  } tc_txq[64][8];
};
struct rte_eth_dcb_info
{
  uint8_t nb_tcs;
  uint8_t prio_tc[8];
  uint8_t tc_bws[8];
  struct rte_eth_dcb_tc_queue_mapping tc_queue;
};
enum rte_eth_fec_mode
{
  RTE_ETH_FEC_NOFEC = 0,
  RTE_ETH_FEC_AUTO,
  RTE_ETH_FEC_BASER,
  RTE_ETH_FEC_RS,
  RTE_ETH_FEC_LLRS,
};
struct rte_eth_fec_capa
{
  uint32_t speed;
  uint32_t capa;
};
typedef uint16_t (*rte_rx_callback_fn)(uint16_t port_id, uint16_t queue,
                                       struct rte_mbuf *pkts[],
                                       uint16_t nb_pkts, uint16_t max_pkts,
                                       void *user_param);
typedef uint16_t (*rte_tx_callback_fn)(uint16_t port_id, uint16_t queue,
                                       struct rte_mbuf *pkts[],
                                       uint16_t nb_pkts, void *user_param);
enum rte_eth_dev_state
{
  RTE_ETH_DEV_UNUSED = 0,
  RTE_ETH_DEV_ATTACHED,
  RTE_ETH_DEV_REMOVED,
};
struct rte_eth_dev_sriov
{
  uint8_t active;
  uint8_t nb_q_per_pool;
  uint16_t def_vmdq_idx;
  uint16_t def_pool_q_idx;
};
struct rte_eth_dev_owner
{
  uint64_t id;
  char name[64];
};
uint64_t rte_eth_find_next_owned_by(uint16_t port_id,
                                    const uint64_t owner_id);
uint16_t rte_eth_find_next(uint16_t port_id);
uint16_t
rte_eth_find_next_of(uint16_t port_id_start,
                     const struct rte_device *parent);
uint16_t
rte_eth_find_next_sibling(uint16_t port_id_start, uint16_t ref_port_id);
int rte_eth_dev_owner_new(uint64_t *owner_id);
int rte_eth_dev_owner_set(const uint16_t port_id,
                          const struct rte_eth_dev_owner *owner);
int rte_eth_dev_owner_unset(const uint16_t port_id, const uint64_t owner_id);
int rte_eth_dev_owner_delete(const uint64_t owner_id);
int rte_eth_dev_owner_get(const uint16_t port_id,
                          struct rte_eth_dev_owner *owner);
uint16_t rte_eth_dev_count_avail(void);
uint16_t rte_eth_dev_count_total(void);
uint32_t rte_eth_speed_bitflag(uint32_t speed, int duplex);
const char *rte_eth_dev_rx_offload_name(uint64_t offload);
const char *rte_eth_dev_tx_offload_name(uint64_t offload);
__attribute__((section(".text.experimental")))
const char *
rte_eth_dev_capability_name(uint64_t capability);
int rte_eth_dev_configure(uint16_t port_id, uint16_t nb_rx_queue,
                          uint16_t nb_tx_queue,
                          const struct rte_eth_conf *eth_conf);
int rte_eth_dev_is_removed(uint16_t port_id);
int rte_eth_rx_queue_setup(uint16_t port_id, uint16_t rx_queue_id,
                           uint16_t nb_rx_desc, unsigned int socket_id,
                           const struct rte_eth_rxconf *rx_conf,
                           struct rte_mempool *mb_pool);
__attribute__((section(".text.experimental"))) int
rte_eth_rx_hairpin_queue_setup(uint16_t port_id, uint16_t rx_queue_id, uint16_t nb_rx_desc,
                               const struct rte_eth_hairpin_conf *conf);
int rte_eth_tx_queue_setup(uint16_t port_id, uint16_t tx_queue_id,
                           uint16_t nb_tx_desc, unsigned int socket_id,
                           const struct rte_eth_txconf *tx_conf);
__attribute__((section(".text.experimental"))) int
rte_eth_tx_hairpin_queue_setup(uint16_t port_id, uint16_t tx_queue_id, uint16_t nb_tx_desc,
                               const struct rte_eth_hairpin_conf *conf);
__attribute__((section(".text.experimental"))) int
rte_eth_hairpin_get_peer_ports(uint16_t port_id, uint16_t *peer_ports,
                               size_t len, uint32_t direction);
__attribute__((section(".text.experimental"))) int
rte_eth_hairpin_bind(uint16_t tx_port, uint16_t rx_port);
__attribute__((section(".text.experimental"))) int
rte_eth_hairpin_unbind(uint16_t tx_port, uint16_t rx_port);
__attribute__((section(".text.experimental"))) int
rte_eth_dev_count_aggr_ports(uint16_t port_id);
__attribute__((section(".text.experimental"))) int
rte_eth_dev_map_aggr_tx_affinity(uint16_t port_id, uint16_t tx_queue_id,
                                 uint8_t affinity);
int rte_eth_dev_socket_id(uint16_t port_id);
int rte_eth_dev_is_valid_port(uint16_t port_id);
__attribute__((section(".text.experimental"))) int
rte_eth_rx_queue_is_valid(uint16_t port_id, uint16_t queue_id);
__attribute__((section(".text.experimental"))) int
rte_eth_tx_queue_is_valid(uint16_t port_id, uint16_t queue_id);
int rte_eth_dev_rx_queue_start(uint16_t port_id, uint16_t rx_queue_id);
int rte_eth_dev_rx_queue_stop(uint16_t port_id, uint16_t rx_queue_id);
int rte_eth_dev_tx_queue_start(uint16_t port_id, uint16_t tx_queue_id);
int rte_eth_dev_tx_queue_stop(uint16_t port_id, uint16_t tx_queue_id);
int rte_eth_dev_start(uint16_t port_id);
int rte_eth_dev_stop(uint16_t port_id);
int rte_eth_dev_set_link_up(uint16_t port_id);
int rte_eth_dev_set_link_down(uint16_t port_id);
int rte_eth_dev_close(uint16_t port_id);
int rte_eth_dev_reset(uint16_t port_id);
int rte_eth_promiscuous_enable(uint16_t port_id);
int rte_eth_promiscuous_disable(uint16_t port_id);
int rte_eth_promiscuous_get(uint16_t port_id);
int rte_eth_allmulticast_enable(uint16_t port_id);
int rte_eth_allmulticast_disable(uint16_t port_id);
int rte_eth_allmulticast_get(uint16_t port_id);
int rte_eth_link_get(uint16_t port_id, struct rte_eth_link *link);
int rte_eth_link_get_nowait(uint16_t port_id, struct rte_eth_link *link);
__attribute__((section(".text.experimental")))
const char *
rte_eth_link_speed_to_str(uint32_t link_speed);
__attribute__((section(".text.experimental"))) int
rte_eth_link_to_str(char *str, size_t len,
                    const struct rte_eth_link *eth_link);
int rte_eth_stats_get(uint16_t port_id, struct rte_eth_stats *stats);
int rte_eth_stats_reset(uint16_t port_id);
int rte_eth_xstats_get_names(uint16_t port_id,
                             struct rte_eth_xstat_name *xstats_names,
                             unsigned int size);
int rte_eth_xstats_get(uint16_t port_id, struct rte_eth_xstat *xstats,
                       unsigned int n);
int rte_eth_xstats_get_names_by_id(uint16_t port_id,
                                   struct rte_eth_xstat_name *xstats_names,
                                   unsigned int size, uint64_t *ids);
int rte_eth_xstats_get_by_id(uint16_t port_id, const uint64_t *ids,
                             uint64_t *values, unsigned int size);
int rte_eth_xstats_get_id_by_name(uint16_t port_id, const char *xstat_name,
                                  uint64_t *id);
int rte_eth_xstats_reset(uint16_t port_id);
int rte_eth_dev_set_tx_queue_stats_mapping(uint16_t port_id,
                                           uint16_t tx_queue_id,
                                           uint8_t stat_idx);
int rte_eth_dev_set_rx_queue_stats_mapping(uint16_t port_id,
                                           uint16_t rx_queue_id,
                                           uint8_t stat_idx);
int rte_eth_macaddr_get(uint16_t port_id, struct rte_ether_addr *mac_addr);
__attribute__((section(".text.experimental"))) int
rte_eth_macaddrs_get(uint16_t port_id, struct rte_ether_addr *ma,
                     unsigned int num);
int rte_eth_dev_info_get(uint16_t port_id,
                         struct rte_eth_dev_info *dev_info);
__attribute__((section(".text.experimental"))) int
rte_eth_dev_conf_get(uint16_t port_id, struct rte_eth_conf *dev_conf);
int rte_eth_dev_fw_version_get(uint16_t port_id,
                               char *fw_version, size_t fw_size);
int rte_eth_dev_get_supported_ptypes(uint16_t port_id, uint32_t ptype_mask,
                                     uint32_t *ptypes, int num);
int rte_eth_dev_set_ptypes(uint16_t port_id, uint32_t ptype_mask,
                           uint32_t *set_ptypes, unsigned int num);
int rte_eth_dev_get_mtu(uint16_t port_id, uint16_t *mtu);
int rte_eth_dev_set_mtu(uint16_t port_id, uint16_t mtu);
int rte_eth_dev_vlan_filter(uint16_t port_id, uint16_t vlan_id, int on);
int rte_eth_dev_set_vlan_strip_on_queue(uint16_t port_id,
                                        uint16_t rx_queue_id, int on);
int rte_eth_dev_set_vlan_ether_type(uint16_t port_id,
                                    enum rte_vlan_type vlan_type,
                                    uint16_t tag_type);
int rte_eth_dev_set_vlan_offload(uint16_t port_id, int offload_mask);
int rte_eth_dev_get_vlan_offload(uint16_t port_id);
int rte_eth_dev_set_vlan_pvid(uint16_t port_id, uint16_t pvid, int on);
__attribute__((section(".text.experimental"))) int
rte_eth_rx_avail_thresh_set(uint16_t port_id, uint16_t queue_id,
                            uint8_t avail_thresh);
__attribute__((section(".text.experimental"))) int
rte_eth_rx_avail_thresh_query(uint16_t port_id, uint16_t *queue_id,
                              uint8_t *avail_thresh);
typedef void (*buffer_tx_error_fn)(struct rte_mbuf **unsent,
                                   uint16_t count, void *userdata);
struct rte_eth_dev_tx_buffer
{
  buffer_tx_error_fn
      error_callback;
  void *
      error_userdata;
  uint16_t
      size;
  uint16_t
      length;
  struct rte_mbuf *
      pkts[];
};
int rte_eth_tx_buffer_init(struct rte_eth_dev_tx_buffer *buffer,
                           uint16_t size);
int rte_eth_tx_buffer_set_err_callback(struct rte_eth_dev_tx_buffer *buffer,
                                       buffer_tx_error_fn callback,
                                       void *userdata);
void rte_eth_tx_buffer_drop_callback(struct rte_mbuf **pkts, uint16_t unsent,
                                     void *userdata);
void rte_eth_tx_buffer_count_callback(struct rte_mbuf **pkts,
                                      uint16_t unsent, void *userdata);
int rte_eth_tx_done_cleanup(uint16_t port_id, uint16_t queue_id,
                            uint32_t free_cnt);
enum rte_eth_event_macsec_subtype
{
  RTE_ETH_SUBEVENT_MACSEC_UNKNOWN,
  RTE_ETH_SUBEVENT_MACSEC_RX_SECTAG_V_EQ1,
  RTE_ETH_SUBEVENT_MACSEC_RX_SECTAG_E_EQ0_C_EQ1,
  RTE_ETH_SUBEVENT_MACSEC_RX_SECTAG_SL_GTE48,
  RTE_ETH_SUBEVENT_MACSEC_RX_SECTAG_ES_EQ1_SC_EQ1,
  RTE_ETH_SUBEVENT_MACSEC_RX_SECTAG_SC_EQ1_SCB_EQ1,
};
enum rte_eth_event_macsec_type
{
  RTE_ETH_EVENT_MACSEC_UNKNOWN,
  RTE_ETH_EVENT_MACSEC_SECTAG_VAL_ERR,
  RTE_ETH_EVENT_MACSEC_RX_SA_PN_HARD_EXP,
  RTE_ETH_EVENT_MACSEC_RX_SA_PN_SOFT_EXP,
  RTE_ETH_EVENT_MACSEC_TX_SA_PN_HARD_EXP,
  RTE_ETH_EVENT_MACSEC_TX_SA_PN_SOFT_EXP,
  RTE_ETH_EVENT_MACSEC_SA_NOT_VALID,
};
struct rte_eth_event_macsec_desc
{
  enum rte_eth_event_macsec_type
      type;
  enum rte_eth_event_macsec_subtype
      subtype;
  uint64_t
      metadata;
};
enum rte_eth_event_ipsec_subtype
{
  RTE_ETH_EVENT_IPSEC_PMD_ERROR_START = -256,
  RTE_ETH_EVENT_IPSEC_PMD_ERROR_END = -1,
  RTE_ETH_EVENT_IPSEC_UNKNOWN = 0,
  RTE_ETH_EVENT_IPSEC_ESN_OVERFLOW,
  RTE_ETH_EVENT_IPSEC_SA_TIME_EXPIRY,
  RTE_ETH_EVENT_IPSEC_SA_BYTE_EXPIRY,
  RTE_ETH_EVENT_IPSEC_SA_PKT_EXPIRY,
  RTE_ETH_EVENT_IPSEC_SA_BYTE_HARD_EXPIRY,
  RTE_ETH_EVENT_IPSEC_SA_PKT_HARD_EXPIRY,
  RTE_ETH_EVENT_IPSEC_MAX
};
struct rte_eth_event_ipsec_desc
{
  enum rte_eth_event_ipsec_subtype
      subtype;
  uint64_t
      metadata;
};
enum rte_eth_event_type
{
  RTE_ETH_EVENT_UNKNOWN,
  RTE_ETH_EVENT_INTR_LSC,
  RTE_ETH_EVENT_QUEUE_STATE,
  RTE_ETH_EVENT_INTR_RESET,
  RTE_ETH_EVENT_VF_MBOX,
  RTE_ETH_EVENT_MACSEC,
  RTE_ETH_EVENT_INTR_RMV,
  RTE_ETH_EVENT_NEW,
  RTE_ETH_EVENT_DESTROY,
  RTE_ETH_EVENT_IPSEC,
  RTE_ETH_EVENT_FLOW_AGED,
  RTE_ETH_EVENT_RX_AVAIL_THRESH,
  RTE_ETH_EVENT_ERR_RECOVERING,
  RTE_ETH_EVENT_RECOVERY_SUCCESS,
  RTE_ETH_EVENT_RECOVERY_FAILED,
  RTE_ETH_EVENT_MAX
};
typedef int (*rte_eth_dev_cb_fn)(uint16_t port_id,
                                 enum rte_eth_event_type event,
                                 void *cb_arg, void *ret_param);
int rte_eth_dev_callback_register(uint16_t port_id,
                                  enum rte_eth_event_type event,
                                  rte_eth_dev_cb_fn cb_fn, void *cb_arg);
int rte_eth_dev_callback_unregister(uint16_t port_id,
                                    enum rte_eth_event_type event,
                                    rte_eth_dev_cb_fn cb_fn, void *cb_arg);
int rte_eth_dev_rx_intr_enable(uint16_t port_id, uint16_t queue_id);
int rte_eth_dev_rx_intr_disable(uint16_t port_id, uint16_t queue_id);
int rte_eth_dev_rx_intr_ctl(uint16_t port_id, int epfd, int op, void *data);
int rte_eth_dev_rx_intr_ctl_q(uint16_t port_id, uint16_t queue_id,
                              int epfd, int op, void *data);
int rte_eth_dev_rx_intr_ctl_q_get_fd(uint16_t port_id, uint16_t queue_id);
int rte_eth_led_on(uint16_t port_id);
int rte_eth_led_off(uint16_t port_id);
__attribute__((section(".text.experimental"))) int
rte_eth_fec_get_capability(uint16_t port_id,
                           struct rte_eth_fec_capa *speed_fec_capa,
                           unsigned int num);
__attribute__((section(".text.experimental"))) int
rte_eth_fec_get(uint16_t port_id, uint32_t *fec_capa);
__attribute__((section(".text.experimental"))) int
rte_eth_fec_set(uint16_t port_id, uint32_t fec_capa);
int rte_eth_dev_flow_ctrl_get(uint16_t port_id,
                              struct rte_eth_fc_conf *fc_conf);
int rte_eth_dev_flow_ctrl_set(uint16_t port_id,
                              struct rte_eth_fc_conf *fc_conf);
int rte_eth_dev_priority_flow_ctrl_set(uint16_t port_id,
                                       struct rte_eth_pfc_conf *pfc_conf);
int rte_eth_dev_mac_addr_add(uint16_t port_id,
                             struct rte_ether_addr *mac_addr,
                             uint32_t pool);
__attribute__((section(".text.experimental"))) int
rte_eth_dev_priority_flow_ctrl_queue_info_get(uint16_t port_id,
                                              struct
                                              rte_eth_pfc_queue_info
                                                  *pfc_queue_info);
__attribute__((section(".text.experimental"))) int
rte_eth_dev_priority_flow_ctrl_queue_configure(uint16_t port_id,
                                               struct
                                               rte_eth_pfc_queue_conf
                                                   *pfc_queue_conf);
int rte_eth_dev_mac_addr_remove(uint16_t port_id,
                                struct rte_ether_addr *mac_addr);
int rte_eth_dev_default_mac_addr_set(uint16_t port_id,
                                     struct rte_ether_addr *mac_addr);
int rte_eth_dev_rss_reta_update(uint16_t port_id,
                                struct rte_eth_rss_reta_entry64 *reta_conf,
                                uint16_t reta_size);
int rte_eth_dev_rss_reta_query(uint16_t port_id,
                               struct rte_eth_rss_reta_entry64 *reta_conf,
                               uint16_t reta_size);
int rte_eth_dev_uc_hash_table_set(uint16_t port_id,
                                  struct rte_ether_addr *addr, uint8_t on);
int rte_eth_dev_uc_all_hash_table_set(uint16_t port_id, uint8_t on);
int rte_eth_set_queue_rate_limit(uint16_t port_id, uint16_t queue_idx,
                                 uint32_t tx_rate);
int rte_eth_dev_rss_hash_update(uint16_t port_id,
                                struct rte_eth_rss_conf *rss_conf);
int rte_eth_dev_rss_hash_conf_get(uint16_t port_id,
                                  struct rte_eth_rss_conf *rss_conf);
__attribute__((section(".text.experimental")))
const char *
rte_eth_dev_rss_algo_name(enum rte_eth_hash_function rss_algo);
__attribute__((section(".text.experimental"))) int
rte_eth_find_rss_algo(const char *name, uint32_t *algo);
int rte_eth_dev_udp_tunnel_port_add(uint16_t port_id,
                                    struct rte_eth_udp_tunnel *tunnel_udp);
int rte_eth_dev_udp_tunnel_port_delete(uint16_t port_id,
                                       struct rte_eth_udp_tunnel
                                           *tunnel_udp);
int rte_eth_dev_get_dcb_info(uint16_t port_id,
                             struct rte_eth_dcb_info *dcb_info);
struct rte_eth_rxtx_callback;
const struct rte_eth_rxtx_callback *
rte_eth_add_rx_callback(uint16_t port_id, uint16_t queue_id,
                        rte_rx_callback_fn fn, void *user_param);
const struct rte_eth_rxtx_callback *
rte_eth_add_first_rx_callback(uint16_t port_id, uint16_t queue_id,
                              rte_rx_callback_fn fn, void *user_param);
const struct rte_eth_rxtx_callback *
rte_eth_add_tx_callback(uint16_t port_id, uint16_t queue_id,
                        rte_tx_callback_fn fn, void *user_param);
int rte_eth_remove_rx_callback(uint16_t port_id, uint16_t queue_id,
                               const struct rte_eth_rxtx_callback *user_cb);
int rte_eth_remove_tx_callback(uint16_t port_id, uint16_t queue_id,
                               const struct rte_eth_rxtx_callback *user_cb);
int rte_eth_rx_queue_info_get(uint16_t port_id, uint16_t queue_id,
                              struct rte_eth_rxq_info *qinfo);
int rte_eth_tx_queue_info_get(uint16_t port_id, uint16_t queue_id,
                              struct rte_eth_txq_info *qinfo);
__attribute__((section(".text.experimental"))) int
rte_eth_recycle_rx_queue_info_get(uint16_t port_id,
                                  uint16_t queue_id,
                                  struct rte_eth_recycle_rxq_info
                                      *recycle_rxq_info);
int rte_eth_rx_burst_mode_get(uint16_t port_id, uint16_t queue_id,
                              struct rte_eth_burst_mode *mode);
int rte_eth_tx_burst_mode_get(uint16_t port_id, uint16_t queue_id,
                              struct rte_eth_burst_mode *mode);
__attribute__((section(".text.experimental"))) int
rte_eth_get_monitor_addr(uint16_t port_id, uint16_t queue_id,
                         struct rte_power_monitor_cond *pmc);
int rte_eth_dev_get_reg_info(uint16_t port_id,
                             struct rte_dev_reg_info *info);
int rte_eth_dev_get_eeprom_length(uint16_t port_id);
int rte_eth_dev_get_eeprom(uint16_t port_id,
                           struct rte_dev_eeprom_info *info);
int rte_eth_dev_set_eeprom(uint16_t port_id,
                           struct rte_dev_eeprom_info *info);
__attribute__((section(".text.experimental"))) int
rte_eth_dev_get_module_info(uint16_t port_id,
                            struct rte_eth_dev_module_info *modinfo);
__attribute__((section(".text.experimental"))) int
rte_eth_dev_get_module_eeprom(uint16_t port_id,
                              struct rte_dev_eeprom_info *info);
int rte_eth_dev_set_mc_addr_list(uint16_t port_id,
                                 struct rte_ether_addr *mc_addr_set,
                                 uint32_t nb_mc_addr);
int rte_eth_timesync_enable(uint16_t port_id);
int rte_eth_timesync_disable(uint16_t port_id);
int rte_eth_timesync_read_rx_timestamp(uint16_t port_id,
                                       struct timespec *timestamp,
                                       uint32_t flags);
int rte_eth_timesync_read_tx_timestamp(uint16_t port_id,
                                       struct timespec *timestamp);
int rte_eth_timesync_adjust_time(uint16_t port_id, int64_t delta);
int rte_eth_timesync_read_time(uint16_t port_id, struct timespec *time);
int rte_eth_timesync_write_time(uint16_t port_id,
                                const struct timespec *time);
__attribute__((section(".text.experimental"))) int
rte_eth_read_clock(uint16_t port_id, uint64_t *clock);
int rte_eth_dev_get_port_by_name(const char *name, uint16_t *port_id);
int rte_eth_dev_get_name_by_port(uint16_t port_id, char *name);
int rte_eth_dev_adjust_nb_rx_tx_desc(uint16_t port_id,
                                     uint16_t *nb_rx_desc,
                                     uint16_t *nb_tx_desc);
int rte_eth_dev_pool_ops_supported(uint16_t port_id, const char *pool);
void *
rte_eth_dev_get_sec_ctx(uint16_t port_id);
__attribute__((section(".text.experimental"))) int
rte_eth_dev_hairpin_capability_get(uint16_t port_id,
                                   struct rte_eth_hairpin_cap *cap);
struct rte_eth_representor_range
{
  enum rte_eth_representor_type
      type;
  int
      controller;
  int
      pf;
  __extension__ union
  {
    int
        vf;
    int
        sf;
  };
  uint32_t
      id_base;
  uint32_t
      id_end;
  char
      name[64];
};
struct rte_eth_representor_info
{
  uint16_t
      controller;
  uint16_t
      pf;
  uint32_t
      nb_ranges_alloc;
  uint32_t
      nb_ranges;
  struct rte_eth_representor_range
      ranges[];
};
__attribute__((section(".text.experimental"))) int
rte_eth_representor_info_get(uint16_t port_id,
                             struct rte_eth_representor_info *info);
int rte_eth_rx_metadata_negotiate(uint16_t port_id, uint64_t *features);
struct rte_eth_ip_reassembly_params
{
  uint32_t
      timeout_ms;
  uint16_t
      max_frags;
  uint16_t
      flags;
};
__attribute__((section(".text.experimental"))) int
rte_eth_ip_reassembly_capability_get(uint16_t port_id,
                                     struct rte_eth_ip_reassembly_params
                                         *capa);
__attribute__((section(".text.experimental"))) int
rte_eth_ip_reassembly_conf_get(uint16_t port_id,
                               struct rte_eth_ip_reassembly_params
                                   *conf);
__attribute__((section(".text.experimental"))) int
rte_eth_ip_reassembly_conf_set(uint16_t port_id,
                               const struct rte_eth_ip_reassembly_params
                                   *conf);
typedef struct
{
  struct rte_mbuf *
      next_frag;
  uint16_t
      time_spent;
  uint16_t
      nb_frags;
} rte_eth_ip_reassembly_dynfield_t;
__attribute__((section(".text.experimental"))) int
rte_eth_dev_priv_dump(uint16_t port_id, FILE *file);
__attribute__((section(".text.experimental"))) int
rte_eth_rx_descriptor_dump(uint16_t port_id, uint16_t queue_id,
                           uint16_t offset, uint16_t num, FILE *file);
__attribute__((section(".text.experimental"))) int
rte_eth_tx_descriptor_dump(uint16_t port_id, uint16_t queue_id,
                           uint16_t offset, uint16_t num, FILE *file);
enum rte_eth_cman_obj
{
  RTE_ETH_CMAN_OBJ_RX_QUEUE = (1U << (0)),
  RTE_ETH_CMAN_OBJ_RX_QUEUE_MEMPOOL = (1U << (1)),
};
struct rte_eth_cman_info
{
  uint64_t
      modes_supported;
  uint64_t
      objs_supported;
  uint8_t
      rsvd[8];
};
struct rte_eth_cman_config
{
  enum rte_eth_cman_obj
      obj;
  enum rte_cman_mode
      mode;
  union
  {
    uint16_t
        rx_queue;
    uint8_t
        rsvd_obj_params[4];
  } obj_param;
  union
  {
    struct rte_cman_red_params
        red;
    uint8_t
        rsvd_mode_params[4];
  } mode_param;
};
__attribute__((section(".text.experimental"))) int
rte_eth_cman_info_get(uint16_t port_id, struct rte_eth_cman_info *info);
__attribute__((section(".text.experimental"))) int
rte_eth_cman_config_init(uint16_t port_id,
                         struct rte_eth_cman_config *config);
__attribute__((section(".text.experimental"))) int
rte_eth_cman_config_set(uint16_t port_id,
                        const struct rte_eth_cman_config *config);
__attribute__((section(".text.experimental"))) int
rte_eth_cman_config_get(uint16_t port_id,
                        struct rte_eth_cman_config *config);
struct rte_eth_dev_callback;
struct rte_eth_dev_cb_list
{
  struct rte_eth_dev_callback *
      tqh_first;
  struct rte_eth_dev_callback **
      tqh_last;
};
struct rte_eth_dev;
typedef uint16_t (*eth_rx_burst_t)(void *rxq,
                                   struct rte_mbuf **rx_pkts, uint16_t nb_pkts);
typedef uint16_t (*eth_tx_burst_t)(void *txq,
                                   struct rte_mbuf **tx_pkts, uint16_t nb_pkts);
typedef uint16_t (*eth_tx_prep_t)(void *txq,
                                  struct rte_mbuf **tx_pkts, uint16_t nb_pkts);
typedef uint32_t (*eth_rx_queue_count_t)(void *rxq);
typedef int (*eth_rx_descriptor_status_t)(void *rxq, uint16_t offset);
typedef int (*eth_tx_queue_count_t)(void *txq);
typedef int (*eth_tx_descriptor_status_t)(void *txq, uint16_t offset);
typedef uint16_t (*eth_recycle_tx_mbufs_reuse_t)(void *txq,
                                                 struct rte_eth_recycle_rxq_info
                                                     *recycle_rxq_info);
typedef void (*eth_recycle_rx_descriptors_refill_t)(void *rxq,
                                                    uint16_t nb);
struct rte_ethdev_qdata
{
  void **
      data;
  void **
      clbk;
};
struct __attribute__((__aligned__(64))) rte_eth_fp_ops
{
  struct rte_ethdev_qdata rxq;
  eth_rx_burst_t rx_pkt_burst;
  eth_rx_queue_count_t rx_queue_count;
  eth_rx_descriptor_status_t rx_descriptor_status;
  eth_recycle_rx_descriptors_refill_t recycle_rx_descriptors_refill;
  uintptr_t reserved1[2];
  struct rte_ethdev_qdata txq;
  eth_tx_burst_t tx_pkt_burst;
  eth_tx_prep_t tx_pkt_prepare;
  eth_tx_descriptor_status_t tx_descriptor_status;
  eth_recycle_tx_mbufs_reuse_t recycle_tx_mbufs_reuse;
  eth_tx_queue_count_t tx_queue_count;
  uintptr_t reserved2[1];
};

extern struct rte_eth_fp_ops rte_eth_fp_ops[32];
uint16_t rte_eth_call_rx_callbacks(uint16_t port_id, uint16_t queue_id,
                                   struct rte_mbuf **rx_pkts, uint16_t nb_rx,
                                   uint16_t nb_pkts, void *opaque);
static inline uint16_t
rte_eth_rx_burst(uint16_t port_id, uint16_t queue_id,
                 struct rte_mbuf **rx_pkts, const uint16_t nb_pkts)
{
  uint16_t nb_rx;
  struct rte_eth_fp_ops *p;
  void *qd;
  p = &rte_eth_fp_ops[port_id];
  qd = p->rxq.data[queue_id];
  nb_rx = p->rx_pkt_burst(qd, rx_pkts, nb_pkts);
  {
    void *cb;
    cb = __atomic_load_n(&p->rxq.clbk[queue_id], 0);
    if (__builtin_expect(!!(cb != ((void *)0)), 0))
      nb_rx = rte_eth_call_rx_callbacks(port_id, queue_id,
                                        rx_pkts, nb_rx, nb_pkts, cb);
  }
  rte_ethdev_trace_rx_burst(port_id, queue_id, (void **)rx_pkts, nb_rx);
  return nb_rx;
}

static inline int
rte_eth_rx_queue_count(uint16_t port_id, uint16_t queue_id)
{
  struct rte_eth_fp_ops *p;
  void *qd;
  p = &rte_eth_fp_ops[port_id];
  qd = p->rxq.data[queue_id];
  if (*p->rx_queue_count == ((void *)0))
    return -95;
  return (int)(*p->rx_queue_count)(qd);
}

static inline int
rte_eth_rx_descriptor_status(uint16_t port_id, uint16_t queue_id,
                             uint16_t offset)
{
  struct rte_eth_fp_ops *p;
  void *qd;
  p = &rte_eth_fp_ops[port_id];
  qd = p->rxq.data[queue_id];
  if (*p->rx_descriptor_status == ((void *)0))
    return -95;
  return (*p->rx_descriptor_status)(qd, offset);
}

static inline int
rte_eth_tx_descriptor_status(uint16_t port_id,
                             uint16_t queue_id, uint16_t offset)
{
  struct rte_eth_fp_ops *p;
  void *qd;
  p = &rte_eth_fp_ops[port_id];
  qd = p->txq.data[queue_id];
  if (*p->tx_descriptor_status == ((void *)0))
    return -95;
  return (*p->tx_descriptor_status)(qd, offset);
}

uint16_t rte_eth_call_tx_callbacks(uint16_t port_id, uint16_t queue_id,
                                   struct rte_mbuf **tx_pkts,
                                   uint16_t nb_pkts, void *opaque);
static inline uint16_t
rte_eth_tx_burst(uint16_t port_id, uint16_t queue_id,
                 struct rte_mbuf **tx_pkts, uint16_t nb_pkts)
{
  struct rte_eth_fp_ops *p;
  void *qd;
  p = &rte_eth_fp_ops[port_id];
  qd = p->txq.data[queue_id];
  {
    void *cb;
    cb = __atomic_load_n(&p->txq.clbk[queue_id], 0);
    if (__builtin_expect(!!(cb != ((void *)0)), 0))
      nb_pkts = rte_eth_call_tx_callbacks(port_id, queue_id,
                                          tx_pkts, nb_pkts, cb);
  }
  nb_pkts = p->tx_pkt_burst(qd, tx_pkts, nb_pkts);
  rte_ethdev_trace_tx_burst(port_id, queue_id, (void **)tx_pkts, nb_pkts);
  return nb_pkts;
}

static inline uint16_t
rte_eth_tx_prepare(uint16_t port_id, uint16_t queue_id,
                   struct rte_mbuf **tx_pkts, uint16_t nb_pkts)
{
  struct rte_eth_fp_ops *p;
  void *qd;
  p = &rte_eth_fp_ops[port_id];
  qd = p->txq.data[queue_id];
  if (!p->tx_pkt_prepare)
    return nb_pkts;
  return p->tx_pkt_prepare(qd, tx_pkts, nb_pkts);
}

static inline uint16_t
rte_eth_tx_buffer_flush(uint16_t port_id, uint16_t queue_id,
                        struct rte_eth_dev_tx_buffer *buffer)
{
  uint16_t sent;
  uint16_t to_send = buffer->length;
  if (to_send == 0)
    return 0;
  sent = rte_eth_tx_burst(port_id, queue_id, buffer->pkts, to_send);
  buffer->length = 0;
  if (__builtin_expect(!!(sent != to_send), 0))
    buffer->error_callback(&buffer->pkts[sent],
                           (uint16_t)(to_send - sent),
                           buffer->error_userdata);
  return sent;
}

static inline __attribute__((always_inline)) uint16_t
rte_eth_tx_buffer(uint16_t port_id, uint16_t queue_id,
                  struct rte_eth_dev_tx_buffer *buffer,
                  struct rte_mbuf *tx_pkt)
{
  buffer->pkts[buffer->length++] = tx_pkt;
  if (buffer->length < buffer->size)
    return 0;
  return rte_eth_tx_buffer_flush(port_id, queue_id, buffer);
}

__attribute__((section(".text.experimental"))) static inline uint16_t
rte_eth_recycle_mbufs(uint16_t rx_port_id, uint16_t rx_queue_id,
                      uint16_t tx_port_id, uint16_t tx_queue_id,
                      struct rte_eth_recycle_rxq_info
                          *recycle_rxq_info)
{
  struct rte_eth_fp_ops *p1, *p2;
  void *qd1, *qd2;
  uint16_t nb_mbufs;
  p1 = &rte_eth_fp_ops[tx_port_id];
  qd1 = p1->txq.data[tx_queue_id];
  if (p1->recycle_tx_mbufs_reuse == ((void *)0))
    return 0;
  p2 = &rte_eth_fp_ops[rx_port_id];
  qd2 = p2->rxq.data[rx_queue_id];
  if (p2->recycle_rx_descriptors_refill == ((void *)0))
    return 0;
  nb_mbufs = p1->recycle_tx_mbufs_reuse(qd1, recycle_rxq_info);
  if (nb_mbufs == 0)
    return 0;
  p2->recycle_rx_descriptors_refill(qd2, nb_mbufs);
  return nb_mbufs;
}

__attribute__((section(".text.experimental"))) int rte_eth_buffer_split_get_supported_hdr_ptypes(uint16_t port_id,
                                                                                                 uint32_t *ptypes,
                                                                                                 int num);
__attribute__((section(".text.experimental"))) static inline int
rte_eth_tx_queue_count(uint16_t port_id, uint16_t queue_id)
{
  struct rte_eth_fp_ops *fops;
  void *qd;
  int rc;
  fops = &rte_eth_fp_ops[port_id];
  qd = fops->txq.data[queue_id];
  if (fops->tx_queue_count == ((void *)0))
  {
    rc = -95;
    goto out;
  }
  rc = fops->tx_queue_count(qd);
out:
  rte_eth_trace_tx_queue_count(port_id, queue_id, rc);
  return rc;
}

struct rte_eth_rxtx_callback
{
  struct rte_eth_rxtx_callback *next;
  union
  {
    rte_rx_callback_fn rx;
    rte_tx_callback_fn tx;
  } fn;
  void *param;
};
struct __attribute__((__aligned__(64))) rte_eth_dev
{
  eth_rx_burst_t rx_pkt_burst;
  eth_tx_burst_t tx_pkt_burst;
  eth_tx_prep_t tx_pkt_prepare;
  eth_rx_queue_count_t rx_queue_count;
  eth_rx_descriptor_status_t rx_descriptor_status;
  eth_tx_queue_count_t tx_queue_count;
  eth_tx_descriptor_status_t tx_descriptor_status;
  eth_recycle_tx_mbufs_reuse_t recycle_tx_mbufs_reuse;
  eth_recycle_rx_descriptors_refill_t recycle_rx_descriptors_refill;
  struct rte_eth_dev_data *data;
  void *process_private;
  const struct eth_dev_ops *dev_ops;
  const struct rte_flow_fp_ops *flow_fp_ops;
  struct rte_device *device;
  struct rte_intr_handle *intr_handle;
  struct rte_eth_dev_cb_list link_intr_cbs;
  struct rte_eth_rxtx_callback *post_rx_burst_cbs[1024];
  struct rte_eth_rxtx_callback *pre_tx_burst_cbs[1024];
  enum rte_eth_dev_state state;
  void *security_ctx;
};

struct rte_eth_dev_sriov;
struct rte_eth_dev_owner;
struct __attribute__((__aligned__(64))) rte_eth_dev_data
{
  char name[64];
  void **rx_queues;
  void **tx_queues;
  uint16_t nb_rx_queues;
  uint16_t nb_tx_queues;
  struct rte_eth_dev_sriov sriov;
  void *dev_private;
  struct rte_eth_link dev_link;
  struct rte_eth_conf dev_conf;
  uint16_t mtu;
  uint32_t min_rx_buf_size;
  uint64_t rx_mbuf_alloc_failed;
  struct rte_ether_addr *mac_addrs;
  uint64_t mac_pool_sel[128];
  struct rte_ether_addr *hash_mac_addrs;
  uint16_t port_id;
  __extension__ uint8_t promiscuous : 1, scattered_rx : 1, all_multicast : 1,
      dev_started : 1, lro : 1, dev_configured : 1, flow_configured : 1;
  uint8_t rx_queue_state[1024];
  uint8_t tx_queue_state[1024];
  uint32_t dev_flags;
  int numa_node;
  struct rte_vlan_filter_conf vlan_filter_conf;
  struct rte_eth_dev_owner owner;
  uint16_t representor_id;
  uint16_t backer_port_id;
  pthread_mutex_t flow_ops_mutex;
};

extern struct rte_eth_dev rte_eth_devices[];
struct rte_hairpin_peer_info;
typedef int (*eth_dev_configure_t)(struct rte_eth_dev *dev);
typedef int (*eth_dev_start_t)(struct rte_eth_dev *dev);
typedef int (*eth_dev_stop_t)(struct rte_eth_dev *dev);
typedef int (*eth_dev_set_link_up_t)(struct rte_eth_dev *dev);
typedef int (*eth_dev_set_link_down_t)(struct rte_eth_dev *dev);
typedef int (*eth_dev_close_t)(struct rte_eth_dev *dev);
typedef int (*eth_dev_reset_t)(struct rte_eth_dev *dev);
typedef int (*eth_is_removed_t)(struct rte_eth_dev *dev);
typedef int (*eth_promiscuous_enable_t)(struct rte_eth_dev *dev);
typedef int (*eth_promiscuous_disable_t)(struct rte_eth_dev *dev);
typedef int (*eth_allmulticast_enable_t)(struct rte_eth_dev *dev);
typedef int (*eth_allmulticast_disable_t)(struct rte_eth_dev *dev);
typedef int (*eth_link_update_t)(struct rte_eth_dev *dev,
                                 int wait_to_complete);
typedef int (*eth_stats_get_t)(struct rte_eth_dev *dev,
                               struct rte_eth_stats *igb_stats);
typedef int (*eth_stats_reset_t)(struct rte_eth_dev *dev);
typedef int (*eth_xstats_get_t)(struct rte_eth_dev *dev,
                                struct rte_eth_xstat *stats,
                                unsigned int n);
typedef int (*eth_xstats_get_by_id_t)(struct rte_eth_dev *dev,
                                      const uint64_t *ids,
                                      uint64_t *values, unsigned int n);
typedef int (*eth_xstats_reset_t)(struct rte_eth_dev *dev);
typedef int (*eth_xstats_get_names_t)(struct rte_eth_dev *dev,
                                      struct rte_eth_xstat_name *
                                          xstats_names,
                                      unsigned int size);
typedef int (*eth_xstats_get_names_by_id_t)(struct rte_eth_dev *dev,
                                            const uint64_t *ids,
                                            struct rte_eth_xstat_name *
                                                xstats_names,
                                            unsigned int size);
typedef int (*eth_queue_stats_mapping_set_t)(struct rte_eth_dev *dev,
                                             uint16_t queue_id,
                                             uint8_t stat_idx,
                                             uint8_t is_rx);
typedef int (*eth_dev_infos_get_t)(struct rte_eth_dev *dev,
                                   struct rte_eth_dev_info *dev_info);
typedef const uint32_t *(*eth_dev_supported_ptypes_get_t)(struct rte_eth_dev
                                                              *dev,
                                                          size_t
                                                              *no_of_elements);
typedef int (*eth_dev_ptypes_set_t)(struct rte_eth_dev *dev,
                                    uint32_t ptype_mask);
typedef int (*eth_queue_start_t)(struct rte_eth_dev *dev,
                                 uint16_t queue_id);
typedef int (*eth_queue_stop_t)(struct rte_eth_dev *dev, uint16_t queue_id);
typedef int (*eth_rx_queue_setup_t)(struct rte_eth_dev *dev,
                                    uint16_t rx_queue_id,
                                    uint16_t nb_rx_desc,
                                    unsigned int socket_id,
                                    const struct rte_eth_rxconf *rx_conf,
                                    struct rte_mempool *mb_pool);
typedef int (*eth_tx_queue_setup_t)(struct rte_eth_dev *dev,
                                    uint16_t tx_queue_id,
                                    uint16_t nb_tx_desc,
                                    unsigned int socket_id,
                                    const struct rte_eth_txconf *tx_conf);
typedef int (*eth_rx_enable_intr_t)(struct rte_eth_dev *dev,
                                    uint16_t rx_queue_id);
typedef int (*eth_rx_disable_intr_t)(struct rte_eth_dev *dev,
                                     uint16_t rx_queue_id);
typedef void (*eth_queue_release_t)(struct rte_eth_dev *dev,
                                    uint16_t queue_id);
typedef int (*eth_fw_version_get_t)(struct rte_eth_dev *dev,
                                    char *fw_version, size_t fw_size);
typedef int (*eth_tx_done_cleanup_t)(void *txq, uint32_t free_cnt);
typedef void (*eth_rxq_info_get_t)(struct rte_eth_dev *dev,
                                   uint16_t rx_queue_id,
                                   struct rte_eth_rxq_info *qinfo);
typedef void (*eth_txq_info_get_t)(struct rte_eth_dev *dev,
                                   uint16_t tx_queue_id,
                                   struct rte_eth_txq_info *qinfo);
typedef void (*eth_recycle_rxq_info_get_t)(struct rte_eth_dev *dev,
                                           uint16_t rx_queue_id,
                                           struct rte_eth_recycle_rxq_info *
                                               recycle_rxq_info);
typedef int (*eth_burst_mode_get_t)(struct rte_eth_dev *dev,
                                    uint16_t queue_id,
                                    struct rte_eth_burst_mode *mode);
typedef int (*mtu_set_t)(struct rte_eth_dev *dev, uint16_t mtu);
typedef int (*vlan_filter_set_t)(struct rte_eth_dev *dev,
                                 uint16_t vlan_id, int on);
typedef int (*vlan_tpid_set_t)(struct rte_eth_dev *dev,
                               enum rte_vlan_type type, uint16_t tpid);
typedef int (*vlan_offload_set_t)(struct rte_eth_dev *dev, int mask);
typedef int (*vlan_pvid_set_t)(struct rte_eth_dev *dev,
                               uint16_t vlan_id, int on);
typedef void (*vlan_strip_queue_set_t)(struct rte_eth_dev *dev,
                                       uint16_t rx_queue_id, int on);
typedef int (*flow_ctrl_get_t)(struct rte_eth_dev *dev,
                               struct rte_eth_fc_conf *fc_conf);
typedef int (*flow_ctrl_set_t)(struct rte_eth_dev *dev,
                               struct rte_eth_fc_conf *fc_conf);
typedef int (*priority_flow_ctrl_set_t)(struct rte_eth_dev *dev,
                                        struct rte_eth_pfc_conf *pfc_conf);
typedef int (*priority_flow_ctrl_queue_info_get_t)(struct rte_eth_dev *dev,
                                                   struct
                                                   rte_eth_pfc_queue_info *
                                                       pfc_queue_info);
typedef int (*priority_flow_ctrl_queue_config_t)(struct rte_eth_dev *dev,
                                                 struct
                                                 rte_eth_pfc_queue_conf *
                                                     pfc_queue_conf);
typedef int (*reta_update_t)(struct rte_eth_dev *dev,
                             struct rte_eth_rss_reta_entry64 *reta_conf,
                             uint16_t reta_size);
typedef int (*reta_query_t)(struct rte_eth_dev *dev,
                            struct rte_eth_rss_reta_entry64 *reta_conf,
                            uint16_t reta_size);
typedef int (*rss_hash_update_t)(struct rte_eth_dev *dev,
                                 struct rte_eth_rss_conf *rss_conf);
typedef int (*rss_hash_conf_get_t)(struct rte_eth_dev *dev,
                                   struct rte_eth_rss_conf *rss_conf);
typedef int (*eth_dev_led_on_t)(struct rte_eth_dev *dev);
typedef int (*eth_dev_led_off_t)(struct rte_eth_dev *dev);
typedef void (*eth_mac_addr_remove_t)(struct rte_eth_dev *dev,
                                      uint32_t index);
typedef int (*eth_mac_addr_add_t)(struct rte_eth_dev *dev,
                                  struct rte_ether_addr *mac_addr,
                                  uint32_t index, uint32_t vmdq);
typedef int (*eth_mac_addr_set_t)(struct rte_eth_dev *dev,
                                  struct rte_ether_addr *mac_addr);
typedef int (*eth_uc_hash_table_set_t)(struct rte_eth_dev *dev,
                                       struct rte_ether_addr *mac_addr,
                                       uint8_t on);
typedef int (*eth_uc_all_hash_table_set_t)(struct rte_eth_dev *dev,
                                           uint8_t on);
typedef int (*eth_set_queue_rate_limit_t)(struct rte_eth_dev *dev,
                                          uint16_t queue_idx,
                                          uint32_t tx_rate);
typedef int (*eth_udp_tunnel_port_add_t)(struct rte_eth_dev *dev,
                                         struct rte_eth_udp_tunnel *
                                             tunnel_udp);
typedef int (*eth_udp_tunnel_port_del_t)(struct rte_eth_dev *dev,
                                         struct rte_eth_udp_tunnel *
                                             tunnel_udp);
typedef int (*eth_set_mc_addr_list_t)(struct rte_eth_dev *dev,
                                      struct rte_ether_addr *mc_addr_set,
                                      uint32_t nb_mc_addr);
typedef int (*eth_timesync_enable_t)(struct rte_eth_dev *dev);
typedef int (*eth_timesync_disable_t)(struct rte_eth_dev *dev);
typedef int (*eth_timesync_read_rx_timestamp_t)(struct rte_eth_dev *dev,
                                                struct timespec *timestamp,
                                                uint32_t flags);
typedef int (*eth_timesync_read_tx_timestamp_t)(struct rte_eth_dev *dev,
                                                struct timespec *timestamp);
typedef int (*eth_timesync_adjust_time)(struct rte_eth_dev *dev, int64_t);
typedef int (*eth_timesync_read_time)(struct rte_eth_dev *dev,
                                      struct timespec *timestamp);
typedef int (*eth_timesync_write_time)(struct rte_eth_dev *dev,
                                       const struct timespec *timestamp);
typedef int (*eth_read_clock)(struct rte_eth_dev *dev,
                              uint64_t *timestamp);
typedef int (*eth_get_reg_t)(struct rte_eth_dev *dev,
                             struct rte_dev_reg_info *info);
typedef int (*eth_get_eeprom_length_t)(struct rte_eth_dev *dev);
typedef int (*eth_get_eeprom_t)(struct rte_eth_dev *dev,
                                struct rte_dev_eeprom_info *info);
typedef int (*eth_set_eeprom_t)(struct rte_eth_dev *dev,
                                struct rte_dev_eeprom_info *info);
typedef int (*eth_get_module_info_t)(struct rte_eth_dev *dev,
                                     struct rte_eth_dev_module_info *
                                         modinfo);
typedef int (*eth_get_module_eeprom_t)(struct rte_eth_dev *dev,
                                       struct rte_dev_eeprom_info *info);
struct rte_flow_ops;
typedef int (*eth_flow_ops_get_t)(struct rte_eth_dev *dev,
                                  const struct rte_flow_ops **ops);
typedef int (*eth_tm_ops_get_t)(struct rte_eth_dev *dev, void *ops);
typedef int (*eth_mtr_ops_get_t)(struct rte_eth_dev *dev, void *ops);
typedef int (*eth_get_dcb_info)(struct rte_eth_dev *dev,
                                struct rte_eth_dcb_info *dcb_info);
typedef int (*eth_pool_ops_supported_t)(struct rte_eth_dev *dev,
                                        const char *pool);
typedef int (*eth_hairpin_cap_get_t)(struct rte_eth_dev *dev,
                                     struct rte_eth_hairpin_cap *cap);
typedef int (*eth_rx_hairpin_queue_setup_t)(struct rte_eth_dev *dev, uint16_t rx_queue_id,
                                            uint16_t nb_rx_desc, const struct rte_eth_hairpin_conf *conf);
typedef int (*eth_tx_hairpin_queue_setup_t)(struct rte_eth_dev *dev, uint16_t tx_queue_id,
                                            uint16_t nb_tx_desc, const struct rte_eth_hairpin_conf *hairpin_conf);
typedef int (*eth_fec_get_capability_t)(struct rte_eth_dev *dev,
                                        struct rte_eth_fec_capa *
                                            speed_fec_capa,
                                        unsigned int num);
typedef int (*eth_fec_get_t)(struct rte_eth_dev *dev, uint32_t *fec_capa);
typedef int (*eth_fec_set_t)(struct rte_eth_dev *dev, uint32_t fec_capa);
typedef int (*hairpin_get_peer_ports_t)(struct rte_eth_dev *dev,
                                        uint16_t *peer_ports, size_t len,
                                        uint32_t direction);
typedef int (*eth_hairpin_bind_t)(struct rte_eth_dev *dev,
                                  uint16_t rx_port);
typedef int (*eth_hairpin_unbind_t)(struct rte_eth_dev *dev,
                                    uint16_t rx_port);
typedef int (*eth_hairpin_queue_peer_update_t)(struct rte_eth_dev *dev, uint16_t peer_queue,
                                               struct rte_hairpin_peer_info *current_info,
                                               struct rte_hairpin_peer_info *peer_info, uint32_t direction);
typedef int (*eth_hairpin_queue_peer_bind_t)(struct rte_eth_dev *dev, uint16_t cur_queue,
                                             struct rte_hairpin_peer_info *peer_info, uint32_t direction);
typedef int (*eth_hairpin_queue_peer_unbind_t)(struct rte_eth_dev *dev, uint16_t cur_queue, uint32_t direction);
typedef int (*eth_get_monitor_addr_t)(void *rxq,
                                      struct rte_power_monitor_cond *pmc);
typedef int (*eth_representor_info_get_t)(struct rte_eth_dev *dev,
                                          struct rte_eth_representor_info *
                                              info);
typedef int (*eth_rx_metadata_negotiate_t)(struct rte_eth_dev *dev,
                                           uint64_t *features);
typedef int (*eth_ip_reassembly_capability_get_t)(struct rte_eth_dev *dev,
                                                  struct
                                                  rte_eth_ip_reassembly_params
                                                      *capa);
typedef int (*eth_ip_reassembly_conf_get_t)(struct rte_eth_dev *dev,
                                            struct
                                            rte_eth_ip_reassembly_params *
                                                conf);
typedef int (*eth_ip_reassembly_conf_set_t)(struct rte_eth_dev *dev,
                                            const struct
                                            rte_eth_ip_reassembly_params *
                                                conf);
typedef const uint32_t *(*eth_buffer_split_supported_hdr_ptypes_get_t)(struct
                                                                       rte_eth_dev
                                                                           *dev,
                                                                       size_t
                                                                           *no_of_elements);
typedef int (*eth_dev_priv_dump_t)(struct rte_eth_dev *dev, FILE *file);
typedef int (*eth_rx_queue_avail_thresh_set_t)(struct rte_eth_dev *dev,
                                               uint16_t rx_queue_id,
                                               uint8_t avail_thresh);
typedef int (*eth_rx_queue_avail_thresh_query_t)(struct rte_eth_dev *dev,
                                                 uint16_t *rx_queue_id,
                                                 uint8_t *avail_thresh);
typedef int (*eth_cman_info_get_t)(struct rte_eth_dev *dev,
                                   struct rte_eth_cman_info *info);
typedef int (*eth_cman_config_init_t)(struct rte_eth_dev *dev,
                                      struct rte_eth_cman_config *config);
typedef int (*eth_cman_config_set_t)(struct rte_eth_dev *dev,
                                     const struct rte_eth_cman_config *
                                         config);
typedef int (*eth_cman_config_get_t)(struct rte_eth_dev *dev,
                                     struct rte_eth_cman_config *config);
typedef int (*eth_rx_descriptor_dump_t)(const struct rte_eth_dev *dev,
                                        uint16_t queue_id, uint16_t offset,
                                        uint16_t num, FILE *file);
typedef int (*eth_tx_descriptor_dump_t)(const struct rte_eth_dev *dev,
                                        uint16_t queue_id, uint16_t offset,
                                        uint16_t num, FILE *file);
typedef int (*eth_count_aggr_ports_t)(struct rte_eth_dev *dev);
typedef int (*eth_map_aggr_tx_affinity_t)(struct rte_eth_dev *dev,
                                          uint16_t tx_queue_id,
                                          uint8_t affinity);
struct eth_dev_ops
{
  eth_dev_configure_t dev_configure;
  eth_dev_start_t dev_start;
  eth_dev_stop_t dev_stop;
  eth_dev_set_link_up_t dev_set_link_up;
  eth_dev_set_link_down_t dev_set_link_down;
  eth_dev_close_t dev_close;
  eth_dev_reset_t dev_reset;
  eth_link_update_t link_update;
  eth_is_removed_t is_removed;
  eth_promiscuous_enable_t promiscuous_enable;
  eth_promiscuous_disable_t promiscuous_disable;
  eth_allmulticast_enable_t allmulticast_enable;
  eth_allmulticast_disable_t allmulticast_disable;
  eth_mac_addr_remove_t mac_addr_remove;
  eth_mac_addr_add_t mac_addr_add;
  eth_mac_addr_set_t mac_addr_set;
  eth_set_mc_addr_list_t set_mc_addr_list;
  mtu_set_t mtu_set;
  eth_stats_get_t stats_get;
  eth_stats_reset_t stats_reset;
  eth_xstats_get_t xstats_get;
  eth_xstats_reset_t xstats_reset;
  eth_xstats_get_names_t xstats_get_names;
  eth_queue_stats_mapping_set_t queue_stats_mapping_set;
  eth_dev_infos_get_t dev_infos_get;
  eth_rxq_info_get_t rxq_info_get;
  eth_txq_info_get_t txq_info_get;
  eth_recycle_rxq_info_get_t recycle_rxq_info_get;
  eth_burst_mode_get_t rx_burst_mode_get;
  eth_burst_mode_get_t tx_burst_mode_get;
  eth_fw_version_get_t fw_version_get;
  eth_dev_supported_ptypes_get_t dev_supported_ptypes_get;
  eth_dev_ptypes_set_t dev_ptypes_set;
  vlan_filter_set_t vlan_filter_set;
  vlan_tpid_set_t vlan_tpid_set;
  vlan_strip_queue_set_t vlan_strip_queue_set;
  vlan_offload_set_t vlan_offload_set;
  vlan_pvid_set_t vlan_pvid_set;
  eth_queue_start_t rx_queue_start;
  eth_queue_stop_t rx_queue_stop;
  eth_queue_start_t tx_queue_start;
  eth_queue_stop_t tx_queue_stop;
  eth_rx_queue_setup_t rx_queue_setup;
  eth_queue_release_t rx_queue_release;
  eth_rx_enable_intr_t rx_queue_intr_enable;
  eth_rx_disable_intr_t rx_queue_intr_disable;
  eth_tx_queue_setup_t tx_queue_setup;
  eth_queue_release_t tx_queue_release;
  eth_tx_done_cleanup_t tx_done_cleanup;
  eth_dev_led_on_t dev_led_on;
  eth_dev_led_off_t dev_led_off;
  flow_ctrl_get_t flow_ctrl_get;
  flow_ctrl_set_t flow_ctrl_set;
  priority_flow_ctrl_set_t priority_flow_ctrl_set;
  priority_flow_ctrl_queue_info_get_t priority_flow_ctrl_queue_info_get;
  priority_flow_ctrl_queue_config_t priority_flow_ctrl_queue_config;
  eth_uc_hash_table_set_t uc_hash_table_set;
  eth_uc_all_hash_table_set_t uc_all_hash_table_set;
  eth_udp_tunnel_port_add_t udp_tunnel_port_add;
  eth_udp_tunnel_port_del_t udp_tunnel_port_del;
  eth_set_queue_rate_limit_t set_queue_rate_limit;
  rss_hash_update_t rss_hash_update;
  rss_hash_conf_get_t rss_hash_conf_get;
  reta_update_t reta_update;
  reta_query_t reta_query;
  eth_get_reg_t get_reg;
  eth_get_eeprom_length_t get_eeprom_length;
  eth_get_eeprom_t get_eeprom;
  eth_set_eeprom_t set_eeprom;
  eth_get_module_info_t get_module_info;
  eth_get_module_eeprom_t get_module_eeprom;
  eth_flow_ops_get_t flow_ops_get;
  eth_get_dcb_info get_dcb_info;
  eth_timesync_enable_t timesync_enable;
  eth_timesync_disable_t timesync_disable;
  eth_timesync_read_rx_timestamp_t timesync_read_rx_timestamp;
  eth_timesync_read_tx_timestamp_t timesync_read_tx_timestamp;
  eth_timesync_adjust_time timesync_adjust_time;
  eth_timesync_read_time timesync_read_time;
  eth_timesync_write_time timesync_write_time;
  eth_read_clock read_clock;
  eth_xstats_get_by_id_t xstats_get_by_id;
  eth_xstats_get_names_by_id_t xstats_get_names_by_id;
  eth_tm_ops_get_t tm_ops_get;
  eth_mtr_ops_get_t mtr_ops_get;
  eth_pool_ops_supported_t pool_ops_supported;
  eth_hairpin_cap_get_t hairpin_cap_get;
  eth_rx_hairpin_queue_setup_t rx_hairpin_queue_setup;
  eth_tx_hairpin_queue_setup_t tx_hairpin_queue_setup;
  eth_fec_get_capability_t fec_get_capability;
  eth_fec_get_t fec_get;
  eth_fec_set_t fec_set;
  hairpin_get_peer_ports_t hairpin_get_peer_ports;
  eth_hairpin_bind_t hairpin_bind;
  eth_hairpin_unbind_t hairpin_unbind;
  eth_hairpin_queue_peer_update_t hairpin_queue_peer_update;
  eth_hairpin_queue_peer_bind_t hairpin_queue_peer_bind;
  eth_hairpin_queue_peer_unbind_t hairpin_queue_peer_unbind;
  eth_get_monitor_addr_t get_monitor_addr;
  eth_representor_info_get_t representor_info_get;
  eth_rx_metadata_negotiate_t rx_metadata_negotiate;
  eth_ip_reassembly_capability_get_t ip_reassembly_capability_get;
  eth_ip_reassembly_conf_get_t ip_reassembly_conf_get;
  eth_ip_reassembly_conf_set_t ip_reassembly_conf_set;
  eth_buffer_split_supported_hdr_ptypes_get_t
      buffer_split_supported_hdr_ptypes_get;
  eth_dev_priv_dump_t eth_dev_priv_dump;
  eth_rx_queue_avail_thresh_set_t rx_queue_avail_thresh_set;
  eth_rx_queue_avail_thresh_query_t rx_queue_avail_thresh_query;
  eth_rx_descriptor_dump_t eth_rx_descriptor_dump;
  eth_tx_descriptor_dump_t eth_tx_descriptor_dump;
  eth_cman_info_get_t cman_info_get;
  eth_cman_config_init_t cman_config_init;
  eth_cman_config_set_t cman_config_set;
  eth_cman_config_get_t cman_config_get;
  eth_count_aggr_ports_t count_aggr_ports;
  eth_map_aggr_tx_affinity_t map_aggr_tx_affinity;
};
__attribute__((section(".text.internal"))) int rte_eth_dev_is_rx_hairpin_queue(struct rte_eth_dev *dev,
                                                                               uint16_t queue_id);
__attribute__((section(".text.internal"))) int rte_eth_dev_is_tx_hairpin_queue(struct rte_eth_dev *dev,
                                                                               uint16_t queue_id);
__attribute__((section(".text.internal"))) struct rte_eth_dev *rte_eth_dev_allocated(const char *name);
__attribute__((section(".text.internal"))) struct rte_eth_dev *rte_eth_dev_allocate(const char *name);
__attribute__((section(".text.internal"))) struct rte_eth_dev *rte_eth_dev_attach_secondary(const char *name);
__attribute__((section(".text.internal"))) int rte_eth_dev_release_port(struct rte_eth_dev *eth_dev);
__attribute__((section(".text.internal"))) void rte_eth_dev_internal_reset(struct rte_eth_dev *dev);
__attribute__((section(".text.internal"))) int rte_eth_dev_callback_process(struct rte_eth_dev *dev,
                                                                            enum rte_eth_event_type event,
                                                                            void *ret_param);
__attribute__((section(".text.internal"))) void rte_eth_dev_probing_finish(struct rte_eth_dev *dev);
__attribute__((section(".text.internal")))
const struct rte_memzone *
rte_eth_dma_zone_reserve(const struct
                         rte_eth_dev *eth_dev,
                         const char *name,
                         uint16_t queue_id,
                         size_t size,
                         unsigned align,
                         int socket_id);
__attribute__((section(".text.internal"))) int
rte_eth_dma_zone_free(const struct rte_eth_dev *eth_dev,
                      const char *name, uint16_t queue_id);
static inline int
rte_eth_linkstatus_set(struct rte_eth_dev *dev,
                       const struct rte_eth_link *new_link)
{
  struct rte_eth_link old_link;
  old_link.val64 =
      __atomic_exchange_n(&dev->data->dev_link.val64, new_link->val64, 5);
  return (old_link.link_status == new_link->link_status) ? -1 : 0;
}

static inline void
rte_eth_linkstatus_get(const struct rte_eth_dev *dev,
                       struct rte_eth_link *link)
{
  struct rte_eth_link curr_link;
  curr_link.val64 = __atomic_load_n(&dev->data->dev_link.val64, 5);
  __atomic_store_n(&link->val64, curr_link.val64, 5);
}

__attribute__((section(".text.internal")))
uint16_t
rte_eth_pkt_burst_dummy(void *queue __attribute__((__unused__)),
                        struct rte_mbuf **pkts __attribute__((__unused__)),
                        uint16_t nb_pkts __attribute__((__unused__)));
__attribute__((section(".text.internal"))) int rte_eth_switch_domain_alloc(uint16_t *domain_id);
__attribute__((section(".text.internal"))) int rte_eth_switch_domain_free(uint16_t domain_id);
struct rte_eth_devargs
{
  uint16_t mh_controllers[4];
  uint16_t nb_mh_controllers;
  uint16_t ports[32];
  uint16_t nb_ports;
  uint16_t representor_ports[32];
  uint16_t nb_representor_ports;
  enum rte_eth_representor_type type;
};
__attribute__((section(".text.internal"))) int
rte_eth_representor_id_get(uint16_t port_id,
                           enum rte_eth_representor_type type,
                           int controller, int pf,
                           int representor_port, uint16_t *repr_id);
static inline _Bool rte_eth_dev_is_repr(const struct rte_eth_dev *dev)
{
  return ((dev->data->dev_flags & (1U << (4))) != 0);
}

__attribute__((section(".text.internal"))) int
rte_eth_devargs_parse(const char *devargs,
                      struct rte_eth_devargs *eth_devargs,
                      unsigned int nb_da);
typedef int (*ethdev_init_t)(struct rte_eth_dev *ethdev,
                             void *init_params);
typedef int (*ethdev_bus_specific_init)(struct rte_eth_dev *ethdev,
                                        void *bus_specific_init_params);
__attribute__((section(".text.internal"))) int
rte_eth_dev_create(struct rte_device *device, const char *name,
                   size_t priv_data_size,
                   ethdev_bus_specific_init bus_specific_init,
                   void *bus_init_params, ethdev_init_t ethdev_init,
                   void *init_params);
typedef int (*ethdev_uninit_t)(struct rte_eth_dev *ethdev);
__attribute__((section(".text.internal"))) int
rte_eth_dev_destroy(struct rte_eth_dev *ethdev,
                    ethdev_uninit_t ethdev_uninit);
__attribute__((section(".text.internal"))) int
rte_eth_hairpin_queue_peer_update(uint16_t peer_port,
                                  uint16_t peer_queue,
                                  struct rte_hairpin_peer_info
                                      *cur_info,
                                  struct rte_hairpin_peer_info
                                      *peer_info,
                                  uint32_t direction);
__attribute__((section(".text.internal"))) int
rte_eth_hairpin_queue_peer_bind(uint16_t cur_port, uint16_t cur_queue,
                                struct rte_hairpin_peer_info
                                    *peer_info,
                                uint32_t direction);
__attribute__((section(".text.internal"))) struct rte_eth_dev *rte_eth_dev_get_by_name(const char *name);
__attribute__((section(".text.internal"))) int
rte_eth_hairpin_queue_peer_unbind(uint16_t cur_port,
                                  uint16_t cur_queue,
                                  uint32_t direction);
__attribute__((section(".text.internal"))) int
rte_eth_ip_reassembly_dynfield_register(int *field_offset, int *flag);
enum rte_filter_type
{
  RTE_ETH_FILTER_NONE = 0,
  RTE_ETH_FILTER_ETHERTYPE,
  RTE_ETH_FILTER_FLEXIBLE,
  RTE_ETH_FILTER_SYN,
  RTE_ETH_FILTER_NTUPLE,
  RTE_ETH_FILTER_TUNNEL,
  RTE_ETH_FILTER_FDIR,
  RTE_ETH_FILTER_HASH,
  RTE_ETH_FILTER_L2_TUNNEL,
};
struct rte_eth_ethertype_filter
{
  struct rte_ether_addr mac_addr;
  uint16_t ether_type;
  uint16_t flags;
  uint16_t queue;
};
struct rte_eth_syn_filter
{
  uint8_t hig_pri;
  uint16_t queue;
};
enum rte_tunnel_iptype
{
  RTE_TUNNEL_IPTYPE_IPV4 = 0,
  RTE_TUNNEL_IPTYPE_IPV6,
};
struct rte_eth_tunnel_filter_conf
{
  struct rte_ether_addr outer_mac;
  struct rte_ether_addr inner_mac;
  uint16_t inner_vlan;
  enum rte_tunnel_iptype ip_type;
  union
  {
    uint32_t ipv4_addr;
    uint32_t ipv6_addr[4];
  } ip_addr;
  uint16_t filter_type;
  enum rte_eth_tunnel_type tunnel_type;
  uint32_t tenant_id;
  uint16_t queue_id;
};
enum rte_eth_fdir_pballoc_type
{
  RTE_ETH_FDIR_PBALLOC_64K = 0,
  RTE_ETH_FDIR_PBALLOC_128K,
  RTE_ETH_FDIR_PBALLOC_256K,
};
enum rte_fdir_status_mode
{
  RTE_FDIR_NO_REPORT_STATUS = 0,
  RTE_FDIR_REPORT_STATUS,
  RTE_FDIR_REPORT_STATUS_ALWAYS,
};
struct rte_eth_fdir_conf
{
  enum rte_fdir_mode mode;
  enum rte_eth_fdir_pballoc_type pballoc;
  enum rte_fdir_status_mode status;
  uint8_t drop_queue;
  struct rte_eth_fdir_masks mask;
  struct rte_eth_fdir_flex_conf flex_conf;
};
struct rte_net_hdr_lens
{
  uint8_t l2_len;
  uint8_t inner_l2_len;
  uint16_t l3_len;
  uint16_t inner_l3_len;
  uint16_t tunnel_len;
  uint8_t l4_len;
  uint8_t inner_l4_len;
};
int rte_net_skip_ip6_ext(uint16_t proto, const struct rte_mbuf *m,
                         uint32_t *off, int *frag);
uint32_t rte_net_get_ptype(const struct rte_mbuf *m,
                           struct rte_net_hdr_lens *hdr_lens,
                           uint32_t layers);
static inline int
rte_net_intel_cksum_flags_prepare(struct rte_mbuf *m,
                                  uint64_t ol_flags)
{
  const uint64_t inner_requests = (1ULL << 54) | (3ULL << 52) |
                                  (1ULL << 50) | (1ULL << 42);
  const uint64_t outer_requests = (1ULL << 58) | (1ULL << 41);
  struct rte_ipv4_hdr *ipv4_hdr = ((void *)0);
  struct rte_ipv6_hdr *ipv6_hdr;
  struct rte_tcp_hdr *tcp_hdr;
  struct rte_udp_hdr *udp_hdr;
  uint64_t inner_l3_offset = m->l2_len;
  if (!(ol_flags & (inner_requests | outer_requests)))
    return 0;
  if (ol_flags & ((1ULL << 59) | (1ULL << 60)))
  {
    inner_l3_offset += m->outer_l2_len + m->outer_l3_len;
    if (ol_flags & (1ULL << 58))
    {
      ipv4_hdr =
          ((struct rte_ipv4_hdr *)(void *)((char *)(m)->buf_addr +
                                           (m)->data_off +
                                           (m->outer_l2_len)));
      ipv4_hdr->hdr_checksum = 0;
    }
    if (ol_flags & (1ULL << 41) || ol_flags & inner_requests)
    {
      if (ol_flags & (1ULL << 59))
      {
        ipv4_hdr =
            ((struct rte_ipv4_hdr *)(void *)((char *)(m)->buf_addr +
                                             (m)->data_off +
                                             (m->outer_l2_len)));
        udp_hdr =
            (struct rte_udp_hdr *)((char *)ipv4_hdr + m->outer_l3_len);
        if (ol_flags & (1ULL << 41))
          udp_hdr->dgram_cksum = rte_ipv4_phdr_cksum(ipv4_hdr,
                                                     m->ol_flags);
        else if (ipv4_hdr->next_proto_id == IPPROTO_UDP)
          udp_hdr->dgram_cksum = 0;
      }
      else
      {
        ipv6_hdr =
            ((struct rte_ipv6_hdr *)(void *)((char *)(m)->buf_addr +
                                             (m)->data_off +
                                             (m->outer_l2_len)));
        udp_hdr =
            ((struct rte_udp_hdr *)(void *)((char *)(m)->buf_addr +
                                            (m)->data_off +
                                            (m->outer_l2_len +
                                             m->outer_l3_len)));
        if (ol_flags & (1ULL << 41))
          udp_hdr->dgram_cksum = rte_ipv6_phdr_cksum(ipv6_hdr,
                                                     m->ol_flags);
        else if (ipv6_hdr->proto == IPPROTO_UDP)
          udp_hdr->dgram_cksum = 0;
      }
    }
  }
  if (__builtin_expect(!!(((m)->data_len) < inner_l3_offset + m->l3_len + m->l4_len), 0))
    return -95;
  if (ol_flags & (1ULL << 55))
  {
    ipv4_hdr =
        ((struct rte_ipv4_hdr *)(void *)((char *)(m)->buf_addr +
                                         (m)->data_off +
                                         (inner_l3_offset)));
    if (ol_flags & (1ULL << 54))
      ipv4_hdr->hdr_checksum = 0;
  }
  if ((ol_flags & (3ULL << 52)) == (3ULL << 52) || (ol_flags & (1ULL << 42)))
  {
    if (ol_flags & (1ULL << 55))
    {
      udp_hdr = (struct rte_udp_hdr *)((char *)ipv4_hdr + m->l3_len);
      udp_hdr->dgram_cksum = rte_ipv4_phdr_cksum(ipv4_hdr, ol_flags);
    }
    else
    {
      ipv6_hdr =
          ((struct rte_ipv6_hdr *)(void *)((char *)(m)->buf_addr +
                                           (m)->data_off +
                                           (inner_l3_offset)));
      udp_hdr =
          ((struct rte_udp_hdr *)(void *)((char *)(m)->buf_addr +
                                          (m)->data_off +
                                          (inner_l3_offset + m->l3_len)));
      udp_hdr->dgram_cksum = rte_ipv6_phdr_cksum(ipv6_hdr, ol_flags);
    }
  }
  else if ((ol_flags & (3ULL << 52)) == (1ULL << 52) ||
           (ol_flags & (1ULL << 50)))
  {
    if (ol_flags & (1ULL << 55))
    {
      tcp_hdr = (struct rte_tcp_hdr *)((char *)ipv4_hdr + m->l3_len);
      tcp_hdr->cksum = rte_ipv4_phdr_cksum(ipv4_hdr, ol_flags);
    }
    else
    {
      ipv6_hdr =
          ((struct rte_ipv6_hdr *)(void *)((char *)(m)->buf_addr +
                                           (m)->data_off +
                                           (inner_l3_offset)));
      tcp_hdr =
          ((struct rte_tcp_hdr *)(void *)((char *)(m)->buf_addr +
                                          (m)->data_off +
                                          (inner_l3_offset + m->l3_len)));
      tcp_hdr->cksum = rte_ipv6_phdr_cksum(ipv6_hdr, ol_flags);
    }
  }
  return 0;
}

static inline int
rte_net_intel_cksum_prepare(struct rte_mbuf *m)
{
  return rte_net_intel_cksum_flags_prepare(m, m->ol_flags);
}

typedef uint8_t rte_v64u8_t __attribute__((vector_size(8), aligned(8)));
typedef uint16_t rte_v64u16_t __attribute__((vector_size(8), aligned(8)));
typedef uint32_t rte_v64u32_t __attribute__((vector_size(8), aligned(8)));
typedef uint8_t rte_v128u8_t __attribute__((vector_size(16), aligned(16)));
typedef uint16_t rte_v128u16_t
    __attribute__((vector_size(16), aligned(16)));
typedef uint32_t rte_v128u32_t
    __attribute__((vector_size(16), aligned(16)));
typedef uint64_t rte_v128u64_t
    __attribute__((vector_size(16), aligned(16)));
typedef uint8_t rte_v256u8_t __attribute__((vector_size(32), aligned(32)));
typedef uint16_t rte_v256u16_t
    __attribute__((vector_size(32), aligned(32)));
typedef uint32_t rte_v256u32_t
    __attribute__((vector_size(32), aligned(32)));
typedef uint64_t rte_v256u64_t
    __attribute__((vector_size(32), aligned(32)));
typedef int8_t rte_v64s8_t __attribute__((vector_size(8), aligned(8)));
typedef int16_t rte_v64s16_t __attribute__((vector_size(8), aligned(8)));
typedef int32_t rte_v64s32_t __attribute__((vector_size(8), aligned(8)));
typedef int8_t rte_v128s8_t __attribute__((vector_size(16), aligned(16)));
typedef int16_t rte_v128s16_t __attribute__((vector_size(16), aligned(16)));
typedef int32_t rte_v128s32_t __attribute__((vector_size(16), aligned(16)));
typedef int64_t rte_v128s64_t __attribute__((vector_size(16), aligned(16)));
typedef int8_t rte_v256s8_t __attribute__((vector_size(32), aligned(32)));
typedef int16_t rte_v256s16_t __attribute__((vector_size(32), aligned(32)));
typedef int32_t rte_v256s32_t __attribute__((vector_size(32), aligned(32)));
typedef int64_t rte_v256s64_t __attribute__((vector_size(32), aligned(32)));
enum rte_vect_max_simd
{
  RTE_VECT_SIMD_DISABLED = 64,
  RTE_VECT_SIMD_128 = 128,
  RTE_VECT_SIMD_256 = 256,
  RTE_VECT_SIMD_512 = 512,
  RTE_VECT_SIMD_MAX = (32767) + 1,
};
uint16_t rte_vect_get_max_simd_bitwidth(void);
int rte_vect_set_max_simd_bitwidth(uint16_t bitwidth);
typedef int32_t xmm_t __attribute__((vector_size(16)));
typedef union __attribute__((__aligned__(16))) rte_xmm
{
  xmm_t x;
  uint8_t u8[(sizeof(xmm_t)) / sizeof(uint8_t)];
  uint16_t u16[(sizeof(xmm_t)) / sizeof(uint16_t)];
  uint32_t u32[(sizeof(xmm_t)) / sizeof(uint32_t)];
  uint64_t u64[(sizeof(xmm_t)) / sizeof(uint64_t)];
  double pd[(sizeof(xmm_t)) / sizeof(double)];
} rte_xmm_t;

static inline xmm_t
vect_load_128(void *p)
{
  xmm_t ret = *((xmm_t *)p);
  return ret;
}

static inline xmm_t
vect_and(xmm_t data, xmm_t mask)
{
  rte_xmm_t ret = {.x = data};
  rte_xmm_t m = {.x = mask};
  ret.u64[0] &= m.u64[0];
  ret.u64[1] &= m.u64[1];
  return ret.x;
}

__extension__ struct rte_geneve_hdr
{
  uint8_t opt_len : 6;
  uint8_t ver : 2;
  uint8_t reserved1 : 6;
  uint8_t critical : 1;
  uint8_t oam : 1;
  rte_be16_t proto;
  uint8_t vni[3];
  uint8_t reserved2;
  uint32_t opts[];
} __attribute__((__packed__));
typedef int (*arg_handler_t)(const char *key, const char *value,
                             void *opaque);
struct rte_kvargs_pair
{
  char *key;
  char *value;
};
struct rte_kvargs
{
  char *str;
  unsigned count;
  struct rte_kvargs_pair pairs[32];
};
struct rte_kvargs *rte_kvargs_parse(const char *args,
                                    const char *const valid_keys[]);
struct rte_kvargs *rte_kvargs_parse_delim(const char *args,
                                          const char *const valid_keys[],
                                          const char *valid_ends);
void rte_kvargs_free(struct rte_kvargs *kvlist);
const char *rte_kvargs_get(const struct rte_kvargs *kvlist, const char *key);
const char *rte_kvargs_get_with_value(const struct rte_kvargs *kvlist,
                                      const char *key, const char *value);
int rte_kvargs_process(const struct rte_kvargs *kvlist,
                       const char *key_match, arg_handler_t handler,
                       void *opaque_arg);
unsigned rte_kvargs_count(const struct rte_kvargs *kvlist,
                          const char *key_match);
enum rte_tm_stats_type
{
  RTE_TM_STATS_N_PKTS = 1 << 0,
  RTE_TM_STATS_N_BYTES = 1 << 1,
  RTE_TM_STATS_N_PKTS_GREEN_DROPPED = 1 << 2,
  RTE_TM_STATS_N_PKTS_YELLOW_DROPPED = 1 << 3,
  RTE_TM_STATS_N_PKTS_RED_DROPPED = 1 << 4,
  RTE_TM_STATS_N_BYTES_GREEN_DROPPED = 1 << 5,
  RTE_TM_STATS_N_BYTES_YELLOW_DROPPED = 1 << 6,
  RTE_TM_STATS_N_BYTES_RED_DROPPED = 1 << 7,
  RTE_TM_STATS_N_PKTS_QUEUED = 1 << 8,
  RTE_TM_STATS_N_BYTES_QUEUED = 1 << 9,
};
struct rte_tm_node_stats
{
  uint64_t n_pkts;
  uint64_t n_bytes;
  struct
  {
    uint64_t n_pkts_dropped[RTE_COLORS];
    uint64_t n_bytes_dropped[RTE_COLORS];
    uint64_t n_pkts_queued;
    uint64_t n_bytes_queued;
  } leaf;
};
enum rte_tm_dynamic_update_type
{
  RTE_TM_UPDATE_NODE_PARENT_KEEP_LEVEL = 1 << 0,
  RTE_TM_UPDATE_NODE_PARENT_CHANGE_LEVEL = 1 << 1,
  RTE_TM_UPDATE_NODE_ADD_DELETE = 1 << 2,
  RTE_TM_UPDATE_NODE_SUSPEND_RESUME = 1 << 3,
  RTE_TM_UPDATE_NODE_WFQ_WEIGHT_MODE = 1 << 4,
  RTE_TM_UPDATE_NODE_N_SP_PRIORITIES = 1 << 5,
  RTE_TM_UPDATE_NODE_CMAN = 1 << 6,
  RTE_TM_UPDATE_NODE_STATS = 1 << 7,
};
struct rte_tm_capabilities
{
  uint32_t n_nodes_max;
  uint32_t n_levels_max;
  int non_leaf_nodes_identical;
  int leaf_nodes_identical;
  uint32_t shaper_n_max;
  uint32_t shaper_private_n_max;
  int shaper_private_dual_rate_n_max;
  uint64_t shaper_private_rate_min;
  uint64_t shaper_private_rate_max;
  int shaper_private_packet_mode_supported;
  int shaper_private_byte_mode_supported;
  uint32_t shaper_shared_n_max;
  uint32_t shaper_shared_n_nodes_per_shaper_max;
  uint32_t shaper_shared_n_shapers_per_node_max;
  uint32_t shaper_shared_dual_rate_n_max;
  uint64_t shaper_shared_rate_min;
  uint64_t shaper_shared_rate_max;
  int shaper_shared_packet_mode_supported;
  int shaper_shared_byte_mode_supported;
  int shaper_pkt_length_adjust_min;
  int shaper_pkt_length_adjust_max;
  uint32_t sched_n_children_max;
  uint32_t sched_sp_n_priorities_max;
  uint32_t sched_wfq_n_children_per_group_max;
  uint32_t sched_wfq_n_groups_max;
  uint32_t sched_wfq_weight_max;
  int sched_wfq_packet_mode_supported;
  int sched_wfq_byte_mode_supported;
  int cman_wred_packet_mode_supported;
  int cman_wred_byte_mode_supported;
  int cman_head_drop_supported;
  uint32_t cman_wred_context_n_max;
  uint32_t cman_wred_context_private_n_max;
  uint32_t cman_wred_context_shared_n_max;
  uint32_t cman_wred_context_shared_n_nodes_per_context_max;
  uint32_t cman_wred_context_shared_n_contexts_per_node_max;
  int mark_vlan_dei_supported[RTE_COLORS];
  int mark_ip_ecn_tcp_supported[RTE_COLORS];
  int mark_ip_ecn_sctp_supported[RTE_COLORS];
  int mark_ip_dscp_supported[RTE_COLORS];
  uint64_t dynamic_update_mask;
  uint64_t stats_mask;
};
struct rte_tm_level_capabilities
{
  uint32_t n_nodes_max;
  uint32_t n_nodes_nonleaf_max;
  uint32_t n_nodes_leaf_max;
  int non_leaf_nodes_identical;
  int leaf_nodes_identical;
  union
  {
    struct
    {
      int shaper_private_supported;
      int shaper_private_dual_rate_supported;
      uint64_t shaper_private_rate_min;
      uint64_t shaper_private_rate_max;
      int shaper_private_packet_mode_supported;
      int shaper_private_byte_mode_supported;
      uint32_t shaper_shared_n_max;
      int shaper_shared_packet_mode_supported;
      int shaper_shared_byte_mode_supported;
      uint32_t sched_n_children_max;
      uint32_t sched_sp_n_priorities_max;
      uint32_t sched_wfq_n_children_per_group_max;
      uint32_t sched_wfq_n_groups_max;
      uint32_t sched_wfq_weight_max;
      int sched_wfq_packet_mode_supported;
      int sched_wfq_byte_mode_supported;
      uint64_t stats_mask;
    } nonleaf;
    struct
    {
      int shaper_private_supported;
      int shaper_private_dual_rate_supported;
      uint64_t shaper_private_rate_min;
      uint64_t shaper_private_rate_max;
      int shaper_private_packet_mode_supported;
      int shaper_private_byte_mode_supported;
      uint32_t shaper_shared_n_max;
      int shaper_shared_packet_mode_supported;
      int shaper_shared_byte_mode_supported;
      int cman_wred_packet_mode_supported;
      int cman_wred_byte_mode_supported;
      int cman_head_drop_supported;
      int cman_wred_context_private_supported;
      uint32_t cman_wred_context_shared_n_max;
      uint64_t stats_mask;
    } leaf;
  };
};
struct rte_tm_node_capabilities
{
  int shaper_private_supported;
  int shaper_private_dual_rate_supported;
  uint64_t shaper_private_rate_min;
  uint64_t shaper_private_rate_max;
  int shaper_private_packet_mode_supported;
  int shaper_private_byte_mode_supported;
  uint32_t shaper_shared_n_max;
  int shaper_shared_packet_mode_supported;
  int shaper_shared_byte_mode_supported;
  union
  {
    struct
    {
      uint32_t sched_n_children_max;
      uint32_t sched_sp_n_priorities_max;
      uint32_t sched_wfq_n_children_per_group_max;
      uint32_t sched_wfq_n_groups_max;
      uint32_t sched_wfq_weight_max;
      int sched_wfq_packet_mode_supported;
      int sched_wfq_byte_mode_supported;
    } nonleaf;
    struct
    {
      int cman_wred_packet_mode_supported;
      int cman_wred_byte_mode_supported;
      int cman_head_drop_supported;
      int cman_wred_context_private_supported;
      uint32_t cman_wred_context_shared_n_max;
    } leaf;
  };
  uint64_t stats_mask;
};
enum rte_tm_cman_mode
{
  RTE_TM_CMAN_TAIL_DROP = 0,
  RTE_TM_CMAN_HEAD_DROP,
  RTE_TM_CMAN_WRED,
};
struct rte_tm_red_params
{
  uint64_t min_th;
  uint64_t max_th;
  uint16_t maxp_inv;
  uint16_t wq_log2;
};
struct rte_tm_wred_params
{
  struct rte_tm_red_params red_params[RTE_COLORS];
  int packet_mode;
};
struct rte_tm_token_bucket
{
  uint64_t rate;
  uint64_t size;
};
struct rte_tm_shaper_params
{
  struct rte_tm_token_bucket committed;
  struct rte_tm_token_bucket peak;
  int32_t pkt_length_adjust;
  int packet_mode;
};
struct rte_tm_node_params
{
  uint32_t shaper_profile_id;
  uint32_t *shared_shaper_id;
  uint32_t n_shared_shapers;
  union
  {
    struct
    {
      int *wfq_weight_mode;
      uint32_t n_sp_priorities;
    } nonleaf;
    struct
    {
      enum rte_tm_cman_mode cman;
      struct
      {
        uint32_t wred_profile_id;
        uint32_t *shared_wred_context_id;
        uint32_t n_shared_wred_contexts;
      } wred;
    } leaf;
  };
  uint64_t stats_mask;
};
enum rte_tm_error_type
{
  RTE_TM_ERROR_TYPE_NONE,
  RTE_TM_ERROR_TYPE_UNSPECIFIED,
  RTE_TM_ERROR_TYPE_CAPABILITIES,
  RTE_TM_ERROR_TYPE_LEVEL_ID,
  RTE_TM_ERROR_TYPE_WRED_PROFILE,
  RTE_TM_ERROR_TYPE_WRED_PROFILE_GREEN,
  RTE_TM_ERROR_TYPE_WRED_PROFILE_YELLOW,
  RTE_TM_ERROR_TYPE_WRED_PROFILE_RED,
  RTE_TM_ERROR_TYPE_WRED_PROFILE_ID,
  RTE_TM_ERROR_TYPE_SHARED_WRED_CONTEXT_ID,
  RTE_TM_ERROR_TYPE_SHAPER_PROFILE,
  RTE_TM_ERROR_TYPE_SHAPER_PROFILE_COMMITTED_RATE,
  RTE_TM_ERROR_TYPE_SHAPER_PROFILE_COMMITTED_SIZE,
  RTE_TM_ERROR_TYPE_SHAPER_PROFILE_PEAK_RATE,
  RTE_TM_ERROR_TYPE_SHAPER_PROFILE_PEAK_SIZE,
  RTE_TM_ERROR_TYPE_SHAPER_PROFILE_PKT_ADJUST_LEN,
  RTE_TM_ERROR_TYPE_SHAPER_PROFILE_PACKET_MODE,
  RTE_TM_ERROR_TYPE_SHAPER_PROFILE_ID,
  RTE_TM_ERROR_TYPE_SHARED_SHAPER_ID,
  RTE_TM_ERROR_TYPE_NODE_PARENT_NODE_ID,
  RTE_TM_ERROR_TYPE_NODE_PRIORITY,
  RTE_TM_ERROR_TYPE_NODE_WEIGHT,
  RTE_TM_ERROR_TYPE_NODE_PARAMS,
  RTE_TM_ERROR_TYPE_NODE_PARAMS_SHAPER_PROFILE_ID,
  RTE_TM_ERROR_TYPE_NODE_PARAMS_SHARED_SHAPER_ID,
  RTE_TM_ERROR_TYPE_NODE_PARAMS_N_SHARED_SHAPERS,
  RTE_TM_ERROR_TYPE_NODE_PARAMS_WFQ_WEIGHT_MODE,
  RTE_TM_ERROR_TYPE_NODE_PARAMS_N_SP_PRIORITIES,
  RTE_TM_ERROR_TYPE_NODE_PARAMS_CMAN,
  RTE_TM_ERROR_TYPE_NODE_PARAMS_WRED_PROFILE_ID,
  RTE_TM_ERROR_TYPE_NODE_PARAMS_SHARED_WRED_CONTEXT_ID,
  RTE_TM_ERROR_TYPE_NODE_PARAMS_N_SHARED_WRED_CONTEXTS,
  RTE_TM_ERROR_TYPE_NODE_PARAMS_STATS,
  RTE_TM_ERROR_TYPE_NODE_ID,
};
struct rte_tm_error
{
  enum rte_tm_error_type type;
  const void *cause;
  const char *message;
};
int rte_tm_get_number_of_leaf_nodes(uint16_t port_id,
                                    uint32_t *n_leaf_nodes,
                                    struct rte_tm_error *error);
int rte_tm_node_type_get(uint16_t port_id,
                         uint32_t node_id,
                         int *is_leaf, struct rte_tm_error *error);
int rte_tm_capabilities_get(uint16_t port_id,
                            struct rte_tm_capabilities *cap,
                            struct rte_tm_error *error);
int rte_tm_level_capabilities_get(uint16_t port_id,
                                  uint32_t level_id,
                                  struct rte_tm_level_capabilities *cap,
                                  struct rte_tm_error *error);
int rte_tm_node_capabilities_get(uint16_t port_id,
                                 uint32_t node_id,
                                 struct rte_tm_node_capabilities *cap,
                                 struct rte_tm_error *error);
int rte_tm_wred_profile_add(uint16_t port_id,
                            uint32_t wred_profile_id,
                            struct rte_tm_wred_params *profile,
                            struct rte_tm_error *error);
int rte_tm_wred_profile_delete(uint16_t port_id,
                               uint32_t wred_profile_id,
                               struct rte_tm_error *error);
int rte_tm_shared_wred_context_add_update(uint16_t port_id,
                                          uint32_t shared_wred_context_id,
                                          uint32_t wred_profile_id,
                                          struct rte_tm_error *error);
int rte_tm_shared_wred_context_delete(uint16_t port_id,
                                      uint32_t shared_wred_context_id,
                                      struct rte_tm_error *error);
int rte_tm_shaper_profile_add(uint16_t port_id,
                              uint32_t shaper_profile_id,
                              struct rte_tm_shaper_params *profile,
                              struct rte_tm_error *error);
int rte_tm_shaper_profile_delete(uint16_t port_id,
                                 uint32_t shaper_profile_id,
                                 struct rte_tm_error *error);
int rte_tm_shared_shaper_add_update(uint16_t port_id,
                                    uint32_t shared_shaper_id,
                                    uint32_t shaper_profile_id,
                                    struct rte_tm_error *error);
int rte_tm_shared_shaper_delete(uint16_t port_id,
                                uint32_t shared_shaper_id,
                                struct rte_tm_error *error);
int rte_tm_node_add(uint16_t port_id,
                    uint32_t node_id,
                    uint32_t parent_node_id,
                    uint32_t priority,
                    uint32_t weight,
                    uint32_t level_id,
                    struct rte_tm_node_params *params,
                    struct rte_tm_error *error);
int rte_tm_node_delete(uint16_t port_id,
                       uint32_t node_id, struct rte_tm_error *error);
int rte_tm_node_suspend(uint16_t port_id,
                        uint32_t node_id, struct rte_tm_error *error);
int rte_tm_node_resume(uint16_t port_id,
                       uint32_t node_id, struct rte_tm_error *error);
int rte_tm_hierarchy_commit(uint16_t port_id,
                            int clear_on_fail, struct rte_tm_error *error);
int rte_tm_node_parent_update(uint16_t port_id,
                              uint32_t node_id,
                              uint32_t parent_node_id,
                              uint32_t priority,
                              uint32_t weight, struct rte_tm_error *error);
int rte_tm_node_shaper_update(uint16_t port_id,
                              uint32_t node_id,
                              uint32_t shaper_profile_id,
                              struct rte_tm_error *error);
int rte_tm_node_shared_shaper_update(uint16_t port_id,
                                     uint32_t node_id,
                                     uint32_t shared_shaper_id,
                                     int add, struct rte_tm_error *error);
int rte_tm_node_stats_update(uint16_t port_id,
                             uint32_t node_id,
                             uint64_t stats_mask, struct rte_tm_error *error);
int rte_tm_node_wfq_weight_mode_update(uint16_t port_id,
                                       uint32_t node_id,
                                       int *wfq_weight_mode,
                                       uint32_t n_sp_priorities,
                                       struct rte_tm_error *error);
int rte_tm_node_cman_update(uint16_t port_id,
                            uint32_t node_id,
                            enum rte_tm_cman_mode cman,
                            struct rte_tm_error *error);
int rte_tm_node_wred_context_update(uint16_t port_id,
                                    uint32_t node_id,
                                    uint32_t wred_profile_id,
                                    struct rte_tm_error *error);
int rte_tm_node_shared_wred_context_update(uint16_t port_id,
                                           uint32_t node_id,
                                           uint32_t shared_wred_context_id,
                                           int add, struct rte_tm_error *error);
int rte_tm_node_stats_read(uint16_t port_id,
                           uint32_t node_id,
                           struct rte_tm_node_stats *stats,
                           uint64_t *stats_mask,
                           int clear, struct rte_tm_error *error);
int rte_tm_mark_vlan_dei(uint16_t port_id,
                         int mark_green,
                         int mark_yellow,
                         int mark_red, struct rte_tm_error *error);
int rte_tm_mark_ip_ecn(uint16_t port_id,
                       int mark_green,
                       int mark_yellow,
                       int mark_red, struct rte_tm_error *error);
int rte_tm_mark_ip_dscp(uint16_t port_id,
                        int mark_green,
                        int mark_yellow,
                        int mark_red, struct rte_tm_error *error);
typedef int (*rte_tm_node_type_get_t)(struct rte_eth_dev *dev,
                                      uint32_t node_id,
                                      int *is_leaf,
                                      struct rte_tm_error *error);
typedef int (*rte_tm_capabilities_get_t)(struct rte_eth_dev *dev,
                                         struct rte_tm_capabilities *cap,
                                         struct rte_tm_error *error);
typedef int (*rte_tm_level_capabilities_get_t)(struct rte_eth_dev *dev,
                                               uint32_t level_id,
                                               struct
                                               rte_tm_level_capabilities *
                                                   cap,
                                               struct rte_tm_error *error);
typedef int (*rte_tm_node_capabilities_get_t)(struct rte_eth_dev *dev,
                                              uint32_t node_id,
                                              struct rte_tm_node_capabilities
                                                  *cap,
                                              struct rte_tm_error *error);
typedef int (*rte_tm_wred_profile_add_t)(struct rte_eth_dev *dev,
                                         uint32_t wred_profile_id,
                                         struct rte_tm_wred_params *profile,
                                         struct rte_tm_error *error);
typedef int (*rte_tm_wred_profile_delete_t)(struct rte_eth_dev *dev,
                                            uint32_t wred_profile_id,
                                            struct rte_tm_error *error);
typedef int (*rte_tm_shared_wred_context_add_update_t)(struct rte_eth_dev *
                                                           dev,
                                                       uint32_t
                                                           shared_wred_context_id,
                                                       uint32_t
                                                           wred_profile_id,
                                                       struct rte_tm_error *
                                                           error);
typedef int (*rte_tm_shared_wred_context_delete_t)(struct rte_eth_dev *dev,
                                                   uint32_t
                                                       shared_wred_context_id,
                                                   struct rte_tm_error *
                                                       error);
typedef int (*rte_tm_shaper_profile_add_t)(struct rte_eth_dev *dev,
                                           uint32_t shaper_profile_id,
                                           struct rte_tm_shaper_params *
                                               profile,
                                           struct rte_tm_error *error);
typedef int (*rte_tm_shaper_profile_delete_t)(struct rte_eth_dev *dev,
                                              uint32_t shaper_profile_id,
                                              struct rte_tm_error *error);
typedef int (*rte_tm_shared_shaper_add_update_t)(struct rte_eth_dev *dev,
                                                 uint32_t shared_shaper_id,
                                                 uint32_t shaper_profile_id,
                                                 struct rte_tm_error *
                                                     error);
typedef int (*rte_tm_shared_shaper_delete_t)(struct rte_eth_dev *dev,
                                             uint32_t shared_shaper_id,
                                             struct rte_tm_error *error);
typedef int (*rte_tm_node_add_t)(struct rte_eth_dev *dev,
                                 uint32_t node_id,
                                 uint32_t parent_node_id,
                                 uint32_t priority,
                                 uint32_t weight,
                                 uint32_t level_id,
                                 struct rte_tm_node_params *params,
                                 struct rte_tm_error *error);
typedef int (*rte_tm_node_delete_t)(struct rte_eth_dev *dev,
                                    uint32_t node_id,
                                    struct rte_tm_error *error);
typedef int (*rte_tm_node_suspend_t)(struct rte_eth_dev *dev,
                                     uint32_t node_id,
                                     struct rte_tm_error *error);
typedef int (*rte_tm_node_resume_t)(struct rte_eth_dev *dev,
                                    uint32_t node_id,
                                    struct rte_tm_error *error);
typedef int (*rte_tm_hierarchy_commit_t)(struct rte_eth_dev *dev,
                                         int clear_on_fail,
                                         struct rte_tm_error *error);
typedef int (*rte_tm_node_parent_update_t)(struct rte_eth_dev *dev,
                                           uint32_t node_id,
                                           uint32_t parent_node_id,
                                           uint32_t priority,
                                           uint32_t weight,
                                           struct rte_tm_error *error);
typedef int (*rte_tm_node_shaper_update_t)(struct rte_eth_dev *dev,
                                           uint32_t node_id,
                                           uint32_t shaper_profile_id,
                                           struct rte_tm_error *error);
typedef int (*rte_tm_node_shared_shaper_update_t)(struct rte_eth_dev *dev,
                                                  uint32_t node_id,
                                                  uint32_t shared_shaper_id,
                                                  int32_t add,
                                                  struct rte_tm_error *
                                                      error);
typedef int (*rte_tm_node_stats_update_t)(struct rte_eth_dev *dev,
                                          uint32_t node_id,
                                          uint64_t stats_mask,
                                          struct rte_tm_error *error);
typedef int (*rte_tm_node_wfq_weight_mode_update_t)(struct rte_eth_dev *dev,
                                                    uint32_t node_id,
                                                    int *wfq_weight_mode,
                                                    uint32_t n_sp_priorities,
                                                    struct rte_tm_error *
                                                        error);
typedef int (*rte_tm_node_cman_update_t)(struct rte_eth_dev *dev,
                                         uint32_t node_id,
                                         enum rte_tm_cman_mode cman,
                                         struct rte_tm_error *error);
typedef int (*rte_tm_node_wred_context_update_t)(struct rte_eth_dev *dev,
                                                 uint32_t node_id,
                                                 uint32_t wred_profile_id,
                                                 struct rte_tm_error *
                                                     error);
typedef int (*rte_tm_node_shared_wred_context_update_t)(struct rte_eth_dev *
                                                            dev,
                                                        uint32_t node_id,
                                                        uint32_t
                                                            shared_wred_context_id,
                                                        int add,
                                                        struct rte_tm_error *
                                                            error);
typedef int (*rte_tm_node_stats_read_t)(struct rte_eth_dev *dev,
                                        uint32_t node_id,
                                        struct rte_tm_node_stats *stats,
                                        uint64_t *stats_mask,
                                        int clear,
                                        struct rte_tm_error *error);
typedef int (*rte_tm_mark_vlan_dei_t)(struct rte_eth_dev *dev,
                                      int mark_green,
                                      int mark_yellow,
                                      int mark_red,
                                      struct rte_tm_error *error);
typedef int (*rte_tm_mark_ip_ecn_t)(struct rte_eth_dev *dev,
                                    int mark_green,
                                    int mark_yellow,
                                    int mark_red,
                                    struct rte_tm_error *error);
typedef int (*rte_tm_mark_ip_dscp_t)(struct rte_eth_dev *dev,
                                     int mark_green,
                                     int mark_yellow,
                                     int mark_red,
                                     struct rte_tm_error *error);
struct rte_tm_ops
{
  rte_tm_node_type_get_t node_type_get;
  rte_tm_capabilities_get_t capabilities_get;
  rte_tm_level_capabilities_get_t level_capabilities_get;
  rte_tm_node_capabilities_get_t node_capabilities_get;
  rte_tm_wred_profile_add_t wred_profile_add;
  rte_tm_wred_profile_delete_t wred_profile_delete;
  rte_tm_shared_wred_context_add_update_t shared_wred_context_add_update;
  rte_tm_shared_wred_context_delete_t shared_wred_context_delete;
  rte_tm_shaper_profile_add_t shaper_profile_add;
  rte_tm_shaper_profile_delete_t shaper_profile_delete;
  rte_tm_shared_shaper_add_update_t shared_shaper_add_update;
  rte_tm_shared_shaper_delete_t shared_shaper_delete;
  rte_tm_node_add_t node_add;
  rte_tm_node_delete_t node_delete;
  rte_tm_node_suspend_t node_suspend;
  rte_tm_node_resume_t node_resume;
  rte_tm_hierarchy_commit_t hierarchy_commit;
  rte_tm_node_parent_update_t node_parent_update;
  rte_tm_node_shaper_update_t node_shaper_update;
  rte_tm_node_shared_shaper_update_t node_shared_shaper_update;
  rte_tm_node_stats_update_t node_stats_update;
  rte_tm_node_wfq_weight_mode_update_t node_wfq_weight_mode_update;
  rte_tm_node_cman_update_t node_cman_update;
  rte_tm_node_wred_context_update_t node_wred_context_update;
  rte_tm_node_shared_wred_context_update_t node_shared_wred_context_update;
  rte_tm_node_stats_read_t node_stats_read;
  rte_tm_mark_vlan_dei_t mark_vlan_dei;
  rte_tm_mark_ip_ecn_t mark_ip_ecn;
  rte_tm_mark_ip_dscp_t mark_ip_dscp;
};
static inline int
rte_tm_error_set(struct rte_tm_error *error,
                 int code,
                 enum rte_tm_error_type type,
                 const void *cause, const char *message)
{
  if (error)
  {
    *error = (struct rte_tm_error){
        .type = type,
        .cause = cause,
        .message = message,
    };
  }
  (per_lcore__rte_errno) = code;
  return code;
}

const struct rte_tm_ops *rte_tm_ops_get(uint16_t port_id,
                                        struct rte_tm_error *error);
enum iavf_status
{
  IAVF_SUCCESS = 0,
  IAVF_ERR_NVM = -1,
  IAVF_ERR_NVM_CHECKSUM = -2,
  IAVF_ERR_PHY = -3,
  IAVF_ERR_CONFIG = -4,
  IAVF_ERR_PARAM = -5,
  IAVF_ERR_MAC_TYPE = -6,
  IAVF_ERR_UNKNOWN_PHY = -7,
  IAVF_ERR_LINK_SETUP = -8,
  IAVF_ERR_ADAPTER_STOPPED = -9,
  IAVF_ERR_INVALID_MAC_ADDR = -10,
  IAVF_ERR_DEVICE_NOT_SUPPORTED = -11,
  IAVF_ERR_MASTER_REQUESTS_PENDING = -12,
  IAVF_ERR_INVALID_LINK_SETTINGS = -13,
  IAVF_ERR_AUTONEG_NOT_COMPLETE = -14,
  IAVF_ERR_RESET_FAILED = -15,
  IAVF_ERR_SWFW_SYNC = -16,
  IAVF_ERR_NO_AVAILABLE_VSI = -17,
  IAVF_ERR_NO_MEMORY = -18,
  IAVF_ERR_BAD_PTR = -19,
  IAVF_ERR_RING_FULL = -20,
  IAVF_ERR_INVALID_PD_ID = -21,
  IAVF_ERR_INVALID_QP_ID = -22,
  IAVF_ERR_INVALID_CQ_ID = -23,
  IAVF_ERR_INVALID_CEQ_ID = -24,
  IAVF_ERR_INVALID_AEQ_ID = -25,
  IAVF_ERR_INVALID_SIZE = -26,
  IAVF_ERR_INVALID_ARP_INDEX = -27,
  IAVF_ERR_INVALID_FPM_FUNC_ID = -28,
  IAVF_ERR_QP_INVALID_MSG_SIZE = -29,
  IAVF_ERR_QP_TOOMANY_WRS_POSTED = -30,
  IAVF_ERR_INVALID_FRAG_COUNT = -31,
  IAVF_ERR_QUEUE_EMPTY = -32,
  IAVF_ERR_INVALID_ALIGNMENT = -33,
  IAVF_ERR_FLUSHED_QUEUE = -34,
  IAVF_ERR_INVALID_PUSH_PAGE_INDEX = -35,
  IAVF_ERR_INVALID_IMM_DATA_SIZE = -36,
  IAVF_ERR_TIMEOUT = -37,
  IAVF_ERR_OPCODE_MISMATCH = -38,
  IAVF_ERR_CQP_COMPL_ERROR = -39,
  IAVF_ERR_INVALID_VF_ID = -40,
  IAVF_ERR_INVALID_HMCFN_ID = -41,
  IAVF_ERR_BACKING_PAGE_ERROR = -42,
  IAVF_ERR_NO_PBLCHUNKS_AVAILABLE = -43,
  IAVF_ERR_INVALID_PBLE_INDEX = -44,
  IAVF_ERR_INVALID_SD_INDEX = -45,
  IAVF_ERR_INVALID_PAGE_DESC_INDEX = -46,
  IAVF_ERR_INVALID_SD_TYPE = -47,
  IAVF_ERR_MEMCPY_FAILED = -48,
  IAVF_ERR_INVALID_HMC_OBJ_INDEX = -49,
  IAVF_ERR_INVALID_HMC_OBJ_COUNT = -50,
  IAVF_ERR_INVALID_SRQ_ARM_LIMIT = -51,
  IAVF_ERR_SRQ_ENABLED = -52,
  IAVF_ERR_ADMIN_QUEUE_ERROR = -53,
  IAVF_ERR_ADMIN_QUEUE_TIMEOUT = -54,
  IAVF_ERR_BUF_TOO_SHORT = -55,
  IAVF_ERR_ADMIN_QUEUE_FULL = -56,
  IAVF_ERR_ADMIN_QUEUE_NO_WORK = -57,
  IAVF_ERR_BAD_IWARP_CQE = -58,
  IAVF_ERR_NVM_BLANK_MODE = -59,
  IAVF_ERR_NOT_IMPLEMENTED = -60,
  IAVF_ERR_PE_DOORBELL_NOT_ENABLED = -61,
  IAVF_ERR_DIAG_TEST_FAILED = -62,
  IAVF_ERR_NOT_READY = -63,
  IAVF_NOT_SUPPORTED = -64,
  IAVF_ERR_FIRMWARE_API_VERSION = -65,
  IAVF_ERR_ADMIN_QUEUE_CRITICAL_ERROR = -66,
};
static inline __attribute__((always_inline)) uint8_t
rte_read8_relaxed(const volatile void *addr)
{
  return *(const volatile uint8_t *)addr;
}

static inline __attribute__((always_inline)) uint16_t
rte_read16_relaxed(const volatile void *addr)
{
  return *(const volatile uint16_t *)addr;
}

static inline __attribute__((always_inline)) uint32_t
rte_read32_relaxed(const volatile void *addr)
{
  return *(const volatile uint32_t *)addr;
}

static inline __attribute__((always_inline)) uint64_t
rte_read64_relaxed(const volatile void *addr)
{
  return *(const volatile uint64_t *)addr;
}

static inline __attribute__((always_inline)) void rte_write8_relaxed(uint8_t value, volatile void *addr)
{
  *(volatile uint8_t *)addr = value;
}

static inline __attribute__((always_inline)) void rte_write16_relaxed(uint16_t value, volatile void *addr)
{
  *(volatile uint16_t *)addr = value;
}

static inline __attribute__((always_inline)) void rte_write32_relaxed(uint32_t value, volatile void *addr)
{
  *(volatile uint32_t *)addr = value;
}

static inline __attribute__((always_inline)) void rte_write64_relaxed(uint64_t value, volatile void *addr)
{
  *(volatile uint64_t *)addr = value;
}

static inline __attribute__((always_inline)) uint8_t
rte_read8(const volatile void *addr)
{
  uint8_t val;
  val = rte_read8_relaxed(addr);
  __asm__ volatile("fence ir, ir" ::: "memory");
  return val;
}

static inline __attribute__((always_inline)) uint16_t
rte_read16(const volatile void *addr)
{
  uint16_t val;
  val = rte_read16_relaxed(addr);
  __asm__ volatile("fence ir, ir" ::: "memory");
  return val;
}

static inline __attribute__((always_inline)) uint32_t
rte_read32(const volatile void *addr)
{
  uint32_t val;
  val = rte_read32_relaxed(addr);
  __asm__ volatile("fence ir, ir" ::: "memory");
  return val;
}

static inline __attribute__((always_inline)) uint64_t
rte_read64(const volatile void *addr)
{
  uint64_t val;
  val = rte_read64_relaxed(addr);
  __asm__ volatile("fence ir, ir" ::: "memory");
  return val;
}

static inline __attribute__((always_inline)) void rte_write8(uint8_t value, volatile void *addr)
{
  __asm__ volatile("fence orw, ow" ::: "memory");
  rte_write8_relaxed(value, addr);
}

static inline __attribute__((always_inline)) void rte_write16(uint16_t value, volatile void *addr)
{
  __asm__ volatile("fence orw, ow" ::: "memory");
  rte_write16_relaxed(value, addr);
}

static inline __attribute__((always_inline)) void rte_write32(uint32_t value, volatile void *addr)
{
  __asm__ volatile("fence orw, ow" ::: "memory");
  rte_write32_relaxed(value, addr);
}

static inline __attribute__((always_inline)) void rte_write64(uint64_t value, volatile void *addr)
{
  __asm__ volatile("fence orw, ow" ::: "memory");
  rte_write64_relaxed(value, addr);
}

static inline __attribute__((always_inline)) void rte_write32_wc(uint32_t value, volatile void *addr)
{
  rte_write32(value, addr);
}

static inline __attribute__((always_inline)) void rte_write32_wc_relaxed(uint32_t value, volatile void *addr)
{
  rte_write32_relaxed(value, addr);
}

typedef uint8_t u8;
typedef int8_t s8;
typedef uint16_t u16;
typedef int16_t s16;
typedef uint32_t u32;
typedef int32_t s32;
typedef uint64_t u64;
typedef uint64_t s64;
static inline __attribute__((always_inline)) uint32_t
readl(volatile void *addr)
{
  return (rte_read32(addr));
}

static inline __attribute__((always_inline)) void writel(uint32_t value, volatile void *addr)
{
  rte_write32((value), addr);
}

static inline __attribute__((always_inline)) void writel_relaxed(uint32_t value, volatile void *addr)
{
  rte_write32_relaxed((value), addr);
}

static inline __attribute__((always_inline)) uint64_t
readq(volatile void *addr)
{
  return (rte_read64(addr));
}

static inline __attribute__((always_inline)) void writeq(uint64_t value, volatile void *addr)
{
  rte_write64((value), addr);
}

extern int iavf_common_logger;
struct iavf_dma_mem
{
  void *va;
  u64 pa;
  u32 size;
  const void *zone;
} __attribute__((__packed__));
struct iavf_virt_mem
{
  void *va;
  u32 size;
} __attribute__((__packed__));
struct iavf_spinlock
{
  rte_spinlock_t spinlock;
};
struct iavf_aq_desc
{
  uint16_t flags;
  uint16_t opcode;
  uint16_t datalen;
  uint16_t retval;
  uint32_t cookie_high;
  uint32_t cookie_low;
  union
  {
    struct
    {
      uint32_t param0;
      uint32_t param1;
      uint32_t param2;
      uint32_t param3;
    } internal;
    struct
    {
      uint32_t param0;
      uint32_t param1;
      uint32_t addr_high;
      uint32_t addr_low;
    } external;
    u8 raw[16];
  } params;
};
enum iavf_admin_queue_err
{
  IAVF_AQ_RC_OK = 0,
  IAVF_AQ_RC_EPERM = 1,
  IAVF_AQ_RC_ENOENT = 2,
  IAVF_AQ_RC_ESRCH = 3,
  IAVF_AQ_RC_EINTR = 4,
  IAVF_AQ_RC_EIO = 5,
  IAVF_AQ_RC_ENXIO = 6,
  IAVF_AQ_RC_E2BIG = 7,
  IAVF_AQ_RC_EAGAIN = 8,
  IAVF_AQ_RC_ENOMEM = 9,
  IAVF_AQ_RC_EACCES = 10,
  IAVF_AQ_RC_EFAULT = 11,
  IAVF_AQ_RC_EBUSY = 12,
  IAVF_AQ_RC_EEXIST = 13,
  IAVF_AQ_RC_EINVAL = 14,
  IAVF_AQ_RC_ENOTTY = 15,
  IAVF_AQ_RC_ENOSPC = 16,
  IAVF_AQ_RC_ENOSYS = 17,
  IAVF_AQ_RC_ERANGE = 18,
  IAVF_AQ_RC_EFLUSHED = 19,
  IAVF_AQ_RC_BAD_ADDR = 20,
  IAVF_AQ_RC_EMODE = 21,
  IAVF_AQ_RC_EFBIG = 22,
};
enum iavf_admin_queue_opc
{
  iavf_aqc_opc_get_version = 0x0001,
  iavf_aqc_opc_driver_version = 0x0002,
  iavf_aqc_opc_queue_shutdown = 0x0003,
  iavf_aqc_opc_set_pf_context = 0x0004,
  iavf_aqc_opc_request_resource = 0x0008,
  iavf_aqc_opc_release_resource = 0x0009,
  iavf_aqc_opc_list_func_capabilities = 0x000A,
  iavf_aqc_opc_list_dev_capabilities = 0x000B,
  iavf_aqc_opc_set_proxy_config = 0x0104,
  iavf_aqc_opc_set_ns_proxy_table_entry = 0x0105,
  iavf_aqc_opc_mac_address_read = 0x0107,
  iavf_aqc_opc_mac_address_write = 0x0108,
  iavf_aqc_opc_clear_pxe_mode = 0x0110,
  iavf_aqc_opc_set_wol_filter = 0x0120,
  iavf_aqc_opc_get_wake_reason = 0x0121,
  iavf_aqc_opc_clear_all_wol_filters = 0x025E,
  iavf_aqc_opc_get_switch_config = 0x0200,
  iavf_aqc_opc_add_statistics = 0x0201,
  iavf_aqc_opc_remove_statistics = 0x0202,
  iavf_aqc_opc_set_port_parameters = 0x0203,
  iavf_aqc_opc_get_switch_resource_alloc = 0x0204,
  iavf_aqc_opc_set_switch_config = 0x0205,
  iavf_aqc_opc_rx_ctl_reg_read = 0x0206,
  iavf_aqc_opc_rx_ctl_reg_write = 0x0207,
  iavf_aqc_opc_add_vsi = 0x0210,
  iavf_aqc_opc_update_vsi_parameters = 0x0211,
  iavf_aqc_opc_get_vsi_parameters = 0x0212,
  iavf_aqc_opc_add_pv = 0x0220,
  iavf_aqc_opc_update_pv_parameters = 0x0221,
  iavf_aqc_opc_get_pv_parameters = 0x0222,
  iavf_aqc_opc_add_veb = 0x0230,
  iavf_aqc_opc_update_veb_parameters = 0x0231,
  iavf_aqc_opc_get_veb_parameters = 0x0232,
  iavf_aqc_opc_delete_element = 0x0243,
  iavf_aqc_opc_add_macvlan = 0x0250,
  iavf_aqc_opc_remove_macvlan = 0x0251,
  iavf_aqc_opc_add_vlan = 0x0252,
  iavf_aqc_opc_remove_vlan = 0x0253,
  iavf_aqc_opc_set_vsi_promiscuous_modes = 0x0254,
  iavf_aqc_opc_add_tag = 0x0255,
  iavf_aqc_opc_remove_tag = 0x0256,
  iavf_aqc_opc_add_multicast_etag = 0x0257,
  iavf_aqc_opc_remove_multicast_etag = 0x0258,
  iavf_aqc_opc_update_tag = 0x0259,
  iavf_aqc_opc_add_control_packet_filter = 0x025A,
  iavf_aqc_opc_remove_control_packet_filter = 0x025B,
  iavf_aqc_opc_add_cloud_filters = 0x025C,
  iavf_aqc_opc_remove_cloud_filters = 0x025D,
  iavf_aqc_opc_clear_wol_switch_filters = 0x025E,
  iavf_aqc_opc_replace_cloud_filters = 0x025F,
  iavf_aqc_opc_add_mirror_rule = 0x0260,
  iavf_aqc_opc_delete_mirror_rule = 0x0261,
  iavf_aqc_opc_write_personalization_profile = 0x0270,
  iavf_aqc_opc_get_personalization_profile_list = 0x0271,
  iavf_aqc_opc_dcb_ignore_pfc = 0x0301,
  iavf_aqc_opc_dcb_updated = 0x0302,
  iavf_aqc_opc_set_dcb_parameters = 0x0303,
  iavf_aqc_opc_configure_vsi_bw_limit = 0x0400,
  iavf_aqc_opc_configure_vsi_ets_sla_bw_limit = 0x0406,
  iavf_aqc_opc_configure_vsi_tc_bw = 0x0407,
  iavf_aqc_opc_query_vsi_bw_config = 0x0408,
  iavf_aqc_opc_query_vsi_ets_sla_config = 0x040A,
  iavf_aqc_opc_configure_switching_comp_bw_limit = 0x0410,
  iavf_aqc_opc_enable_switching_comp_ets = 0x0413,
  iavf_aqc_opc_modify_switching_comp_ets = 0x0414,
  iavf_aqc_opc_disable_switching_comp_ets = 0x0415,
  iavf_aqc_opc_configure_switching_comp_ets_bw_limit = 0x0416,
  iavf_aqc_opc_configure_switching_comp_bw_config = 0x0417,
  iavf_aqc_opc_query_switching_comp_ets_config = 0x0418,
  iavf_aqc_opc_query_port_ets_config = 0x0419,
  iavf_aqc_opc_query_switching_comp_bw_config = 0x041A,
  iavf_aqc_opc_suspend_port_tx = 0x041B,
  iavf_aqc_opc_resume_port_tx = 0x041C,
  iavf_aqc_opc_configure_partition_bw = 0x041D,
  iavf_aqc_opc_query_hmc_resource_profile = 0x0500,
  iavf_aqc_opc_set_hmc_resource_profile = 0x0501,
  iavf_aqc_opc_get_phy_abilities = 0x0600,
  iavf_aqc_opc_set_phy_config = 0x0601,
  iavf_aqc_opc_set_mac_config = 0x0603,
  iavf_aqc_opc_set_link_restart_an = 0x0605,
  iavf_aqc_opc_get_link_status = 0x0607,
  iavf_aqc_opc_set_phy_int_mask = 0x0613,
  iavf_aqc_opc_get_local_advt_reg = 0x0614,
  iavf_aqc_opc_set_local_advt_reg = 0x0615,
  iavf_aqc_opc_get_partner_advt = 0x0616,
  iavf_aqc_opc_set_lb_modes = 0x0618,
  iavf_aqc_opc_get_phy_wol_caps = 0x0621,
  iavf_aqc_opc_set_phy_debug = 0x0622,
  iavf_aqc_opc_upload_ext_phy_fm = 0x0625,
  iavf_aqc_opc_run_phy_activity = 0x0626,
  iavf_aqc_opc_set_phy_register = 0x0628,
  iavf_aqc_opc_get_phy_register = 0x0629,
  iavf_aqc_opc_nvm_read = 0x0701,
  iavf_aqc_opc_nvm_erase = 0x0702,
  iavf_aqc_opc_nvm_update = 0x0703,
  iavf_aqc_opc_nvm_config_read = 0x0704,
  iavf_aqc_opc_nvm_config_write = 0x0705,
  iavf_aqc_opc_nvm_progress = 0x0706,
  iavf_aqc_opc_oem_post_update = 0x0720,
  iavf_aqc_opc_thermal_sensor = 0x0721,
  iavf_aqc_opc_send_msg_to_pf = 0x0801,
  iavf_aqc_opc_send_msg_to_vf = 0x0802,
  iavf_aqc_opc_send_msg_to_peer = 0x0803,
  iavf_aqc_opc_alternate_write = 0x0900,
  iavf_aqc_opc_alternate_write_indirect = 0x0901,
  iavf_aqc_opc_alternate_read = 0x0902,
  iavf_aqc_opc_alternate_read_indirect = 0x0903,
  iavf_aqc_opc_alternate_write_done = 0x0904,
  iavf_aqc_opc_alternate_set_mode = 0x0905,
  iavf_aqc_opc_alternate_clear_port = 0x0906,
  iavf_aqc_opc_lldp_get_mib = 0x0A00,
  iavf_aqc_opc_lldp_update_mib = 0x0A01,
  iavf_aqc_opc_lldp_add_tlv = 0x0A02,
  iavf_aqc_opc_lldp_update_tlv = 0x0A03,
  iavf_aqc_opc_lldp_delete_tlv = 0x0A04,
  iavf_aqc_opc_lldp_stop = 0x0A05,
  iavf_aqc_opc_lldp_start = 0x0A06,
  iavf_aqc_opc_get_cee_dcb_cfg = 0x0A07,
  iavf_aqc_opc_lldp_set_local_mib = 0x0A08,
  iavf_aqc_opc_lldp_stop_start_spec_agent = 0x0A09,
  iavf_aqc_opc_add_udp_tunnel = 0x0B00,
  iavf_aqc_opc_del_udp_tunnel = 0x0B01,
  iavf_aqc_opc_set_rss_key = 0x0B02,
  iavf_aqc_opc_set_rss_lut = 0x0B03,
  iavf_aqc_opc_get_rss_key = 0x0B04,
  iavf_aqc_opc_get_rss_lut = 0x0B05,
  iavf_aqc_opc_event_lan_overflow = 0x1001,
  iavf_aqc_opc_oem_parameter_change = 0xFE00,
  iavf_aqc_opc_oem_device_status_change = 0xFE01,
  iavf_aqc_opc_oem_ocsd_initialize = 0xFE02,
  iavf_aqc_opc_oem_ocbb_initialize = 0xFE03,
  iavf_aqc_opc_debug_read_reg = 0xFF03,
  iavf_aqc_opc_debug_write_reg = 0xFF04,
  iavf_aqc_opc_debug_modify_reg = 0xFF07,
  iavf_aqc_opc_debug_dump_internals = 0xFF08,
};
struct iavf_aqc_queue_shutdown
{
  uint32_t driver_unloading;
  u8 reserved[12];
};
enum iavf_static_assert_enum_iavf_aqc_queue_shutdown
{
  iavf_static_assert_iavf_aqc_queue_shutdown =
      (16) / ((sizeof(struct iavf_aqc_queue_shutdown) == (16)) ? 1 : 0)
};
struct iavf_aqc_vsi_properties_data
{
  uint16_t valid_sections;
  uint16_t switch_id;
  u8 sw_reserved[2];
  u8 sec_flags;
  u8 sec_reserved;
  uint16_t pvid;
  uint16_t fcoe_pvid;
  u8 port_vlan_flags;
  u8 pvlan_reserved[3];
  uint32_t ingress_table;
  uint32_t egress_table;
  uint16_t cas_pv_tag;
  u8 cas_pv_flags;
  u8 cas_pv_reserved;
  uint16_t mapping_flags;
  uint16_t queue_mapping[16];
  uint16_t tc_mapping[8];
  u8 queueing_opt_flags;
  u8 queueing_opt_reserved[3];
  u8 up_enable_bits;
  u8 sched_reserved;
  uint32_t outer_up_table;
  u8 cmd_reserved[8];
  uint16_t qs_handle[8];
  uint16_t stat_counter_idx;
  uint16_t sched_id;
  u8 resp_reserved[12];
};
enum iavf_static_assert_enum_iavf_aqc_vsi_properties_data
{
  iavf_static_assert_iavf_aqc_vsi_properties_data =
      (128) / ((sizeof(struct iavf_aqc_vsi_properties_data) == (128)) ? 1 : 0)
};
struct iavf_aqc_get_veb_parameters_completion
{
  uint16_t seid;
  uint16_t switch_id;
  uint16_t veb_flags;
  uint16_t statistic_index;
  uint16_t vebs_used;
  uint16_t vebs_free;
  u8 reserved[4];
};
enum iavf_static_assert_enum_iavf_aqc_get_veb_parameters_completion
{
  iavf_static_assert_iavf_aqc_get_veb_parameters_completion =
      (16) /
      ((sizeof(struct iavf_aqc_get_veb_parameters_completion) == (16)) ? 1 : 0)
};
enum iavf_aq_link_speed
{
  IAVF_LINK_SPEED_UNKNOWN = 0,
  IAVF_LINK_SPEED_100MB = (1 << 0x1),
  IAVF_LINK_SPEED_1GB = (1 << 0x2),
  IAVF_LINK_SPEED_2_5GB = (1 << 0x0),
  IAVF_LINK_SPEED_5GB = (1 << 0x7),
  IAVF_LINK_SPEED_10GB = (1 << 0x3),
  IAVF_LINK_SPEED_40GB = (1 << 0x4),
  IAVF_LINK_SPEED_20GB = (1 << 0x5),
  IAVF_LINK_SPEED_25GB = (1 << 0x6),
};
struct iavf_aqc_pf_vf_message
{
  uint32_t id;
  u8 reserved[4];
  uint32_t addr_high;
  uint32_t addr_low;
};
enum iavf_static_assert_enum_iavf_aqc_pf_vf_message
{
  iavf_static_assert_iavf_aqc_pf_vf_message =
      (16) / ((sizeof(struct iavf_aqc_pf_vf_message) == (16)) ? 1 : 0)
};
struct iavf_aqc_get_cee_dcb_cfg_v1_resp
{
  u8 reserved1;
  u8 oper_num_tc;
  u8 oper_prio_tc[4];
  u8 reserved2;
  u8 oper_tc_bw[8];
  u8 oper_pfc_en;
  u8 reserved3[2];
  uint16_t oper_app_prio;
  u8 reserved4[2];
  uint16_t tlv_status;
};
enum iavf_static_assert_enum_iavf_aqc_get_cee_dcb_cfg_v1_resp
{
  iavf_static_assert_iavf_aqc_get_cee_dcb_cfg_v1_resp =
      (0x18) /
      ((sizeof(struct iavf_aqc_get_cee_dcb_cfg_v1_resp) == (0x18)) ? 1 : 0)
};
struct iavf_aqc_get_cee_dcb_cfg_resp
{
  u8 oper_num_tc;
  u8 oper_prio_tc[4];
  u8 oper_tc_bw[8];
  u8 oper_pfc_en;
  uint16_t oper_app_prio;
  uint32_t tlv_status;
  u8 reserved[12];
};
enum iavf_static_assert_enum_iavf_aqc_get_cee_dcb_cfg_resp
{
  iavf_static_assert_iavf_aqc_get_cee_dcb_cfg_resp =
      (0x20) /
      ((sizeof(struct iavf_aqc_get_cee_dcb_cfg_resp) == (0x20)) ? 1 : 0)
};
struct iavf_aqc_lldp_set_local_mib
{
  u8 type;
  u8 reserved0;
  uint16_t length;
  u8 reserved1[4];
  uint32_t address_high;
  uint32_t address_low;
};
enum iavf_static_assert_enum_iavf_aqc_lldp_set_local_mib
{
  iavf_static_assert_iavf_aqc_lldp_set_local_mib =
      (16) / ((sizeof(struct iavf_aqc_lldp_set_local_mib) == (16)) ? 1 : 0)
};
struct iavf_aqc_lldp_set_local_mib_resp
{
  u8 status;
  u8 reserved[15];
};
enum iavf_static_assert_enum_iavf_aqc_lldp_set_local_mib_resp
{
  iavf_static_assert_iavf_aqc_lldp_set_local_mib_resp =
      (0x10) /
      ((sizeof(struct iavf_aqc_lldp_set_local_mib_resp) == (0x10)) ? 1 : 0)
};
struct iavf_aqc_lldp_stop_start_specific_agent
{
  u8 command;
  u8 reserved[15];
};
enum iavf_static_assert_enum_iavf_aqc_lldp_stop_start_specific_agent
{
  iavf_static_assert_iavf_aqc_lldp_stop_start_specific_agent =
      (16) /
      ((sizeof(struct iavf_aqc_lldp_stop_start_specific_agent) ==
        (16))
           ? 1
           : 0)
};
struct iavf_aqc_get_set_rss_key
{
  uint16_t vsi_id;
  u8 reserved[6];
  uint32_t addr_high;
  uint32_t addr_low;
};
enum iavf_static_assert_enum_iavf_aqc_get_set_rss_key
{
  iavf_static_assert_iavf_aqc_get_set_rss_key =
      (16) / ((sizeof(struct iavf_aqc_get_set_rss_key) == (16)) ? 1 : 0)
};
struct iavf_aqc_get_set_rss_key_data
{
  u8 standard_rss_key[0x28];
  u8 extended_hash_key[0xc];
};
enum iavf_static_assert_enum_iavf_aqc_get_set_rss_key_data
{
  iavf_static_assert_iavf_aqc_get_set_rss_key_data =
      (0x34) /
      ((sizeof(struct iavf_aqc_get_set_rss_key_data) == (0x34)) ? 1 : 0)
};
struct iavf_aqc_get_set_rss_lut
{
  uint16_t vsi_id;
  uint16_t flags;
  u8 reserved[4];
  uint32_t addr_high;
  uint32_t addr_low;
};
enum iavf_static_assert_enum_iavf_aqc_get_set_rss_lut
{
  iavf_static_assert_iavf_aqc_get_set_rss_lut =
      (16) / ((sizeof(struct iavf_aqc_get_set_rss_lut) == (16)) ? 1 : 0)
};
struct iavf_adminq_ring
{
  struct iavf_virt_mem dma_head;
  struct iavf_dma_mem desc_buf;
  struct iavf_virt_mem cmd_buf;
  union
  {
    struct iavf_dma_mem *asq_bi;
    struct iavf_dma_mem *arq_bi;
  } r;
  u16 count;
  u16 rx_buf_len;
  u16 next_to_use;
  u16 next_to_clean;
  u32 head;
  u32 tail;
  u32 len;
  u32 bah;
  u32 bal;
};
struct iavf_asq_cmd_details
{
  void *callback;
  u64 cookie;
  u16 flags_ena;
  u16 flags_dis;
  _Bool async;
  _Bool postpone;
  struct iavf_aq_desc *wb_desc;
};
struct iavf_arq_event_info
{
  struct iavf_aq_desc desc;
  u16 msg_len;
  u16 buf_len;
  u8 *msg_buf;
};
struct iavf_adminq_info
{
  struct iavf_adminq_ring arq;
  struct iavf_adminq_ring asq;
  u32 asq_cmd_timeout;
  u16 num_arq_entries;
  u16 num_asq_entries;
  u16 arq_buf_size;
  u16 asq_buf_size;
  u16 fw_maj_ver;
  u16 fw_min_ver;
  u32 fw_build;
  u16 api_maj_ver;
  u16 api_min_ver;
  struct iavf_spinlock asq_spinlock;
  struct iavf_spinlock arq_spinlock;
  enum iavf_admin_queue_err asq_last_status;
  enum iavf_admin_queue_err arq_last_status;
};
void iavf_fill_default_direct_cmd_desc(struct iavf_aq_desc *desc,
                                       u16 opcode);
struct iavf_hw;
typedef void (*IAVF_ADMINQ_CALLBACK)(struct iavf_hw *,
                                     struct iavf_aq_desc *);
enum iavf_debug_mask
{
  IAVF_DEBUG_INIT = 0x00000001,
  IAVF_DEBUG_RELEASE = 0x00000002,
  IAVF_DEBUG_LINK = 0x00000010,
  IAVF_DEBUG_PHY = 0x00000020,
  IAVF_DEBUG_HMC = 0x00000040,
  IAVF_DEBUG_NVM = 0x00000080,
  IAVF_DEBUG_LAN = 0x00000100,
  IAVF_DEBUG_FLOW = 0x00000200,
  IAVF_DEBUG_DCB = 0x00000400,
  IAVF_DEBUG_DIAG = 0x00000800,
  IAVF_DEBUG_FD = 0x00001000,
  IAVF_DEBUG_PACKAGE = 0x00002000,
  IAVF_DEBUG_AQ_MESSAGE = 0x01000000,
  IAVF_DEBUG_AQ_DESCRIPTOR = 0x02000000,
  IAVF_DEBUG_AQ_DESC_BUFFER = 0x04000000,
  IAVF_DEBUG_AQ_COMMAND = 0x06000000,
  IAVF_DEBUG_AQ = 0x0F000000,
  IAVF_DEBUG_USER = 0xF0000000,
  IAVF_DEBUG_ALL = 0xFFFFFFFF
};
enum iavf_memset_type
{
  IAVF_NONDMA_MEM = 0,
  IAVF_DMA_MEM
};
enum iavf_memcpy_type
{
  IAVF_NONDMA_TO_NONDMA = 0,
  IAVF_NONDMA_TO_DMA,
  IAVF_DMA_TO_DMA,
  IAVF_DMA_TO_NONDMA
};
enum iavf_mac_type
{
  IAVF_MAC_UNKNOWN = 0,
  IAVF_MAC_XL710,
  IAVF_MAC_VF,
  IAVF_MAC_X722,
  IAVF_MAC_X722_VF,
  IAVF_MAC_GENERIC,
};
enum iavf_vsi_type
{
  IAVF_VSI_MAIN = 0,
  IAVF_VSI_VMDQ1 = 1,
  IAVF_VSI_VMDQ2 = 2,
  IAVF_VSI_CTRL = 3,
  IAVF_VSI_FCOE = 4,
  IAVF_VSI_MIRROR = 5,
  IAVF_VSI_SRIOV = 6,
  IAVF_VSI_FDIR = 7,
  IAVF_VSI_TYPE_UNKNOWN
};
enum iavf_queue_type
{
  IAVF_QUEUE_TYPE_RX = 0,
  IAVF_QUEUE_TYPE_TX,
  IAVF_QUEUE_TYPE_PE_CEQ,
  IAVF_QUEUE_TYPE_UNKNOWN
};
enum iavf_acpi_programming_method
{
  IAVF_ACPI_PROGRAMMING_METHOD_HW_FVL = 0,
  IAVF_ACPI_PROGRAMMING_METHOD_AQC_FPK = 1
};
struct iavf_hw_capabilities
{
  _Bool dcb;
  _Bool fcoe;
  _Bool iwarp;
  u32 num_vsis;
  u32 num_rx_qp;
  u32 num_tx_qp;
  u32 base_queue;
  u32 num_msix_vectors_vf;
  u32 max_mtu;
  _Bool apm_wol_support;
  enum iavf_acpi_programming_method acpi_prog_method;
  _Bool proxy_support;
};
struct iavf_mac_info
{
  enum iavf_mac_type type;
  u8 addr[6];
  u8 perm_addr[6];
  u8 san_addr[6];
  u8 port_addr[6];
  u16 max_fcoeq;
};
struct iavf_nvmupd_features
{
  u8 major;
  u8 minor;
  u16 size;
  u8 features[12];
};
enum iavf_bus_type
{
  iavf_bus_type_unknown = 0,
  iavf_bus_type_pci,
  iavf_bus_type_pcix,
  iavf_bus_type_pci_express,
  iavf_bus_type_reserved
};
enum iavf_bus_speed
{
  iavf_bus_speed_unknown = 0,
  iavf_bus_speed_33 = 33,
  iavf_bus_speed_66 = 66,
  iavf_bus_speed_100 = 100,
  iavf_bus_speed_120 = 120,
  iavf_bus_speed_133 = 133,
  iavf_bus_speed_2500 = 2500,
  iavf_bus_speed_5000 = 5000,
  iavf_bus_speed_8000 = 8000,
  iavf_bus_speed_reserved
};
enum iavf_bus_width
{
  iavf_bus_width_unknown = 0,
  iavf_bus_width_pcie_x1 = 1,
  iavf_bus_width_pcie_x2 = 2,
  iavf_bus_width_pcie_x4 = 4,
  iavf_bus_width_pcie_x8 = 8,
  iavf_bus_width_32 = 32,
  iavf_bus_width_64 = 64,
  iavf_bus_width_reserved
};
struct iavf_bus_info
{
  enum iavf_bus_speed speed;
  enum iavf_bus_width width;
  enum iavf_bus_type type;
  u16 func;
  u16 device;
  u16 lan_id;
  u16 bus_id;
};
struct iavf_hw
{
  u8 *hw_addr;
  void *back;
  struct iavf_mac_info mac;
  struct iavf_bus_info bus;
  u16 device_id;
  u16 vendor_id;
  u16 subsystem_device_id;
  u16 subsystem_vendor_id;
  u8 revision_id;
  struct iavf_hw_capabilities dev_caps;
  struct iavf_adminq_info aq;
  u16 num_wol_proxy_filters;
  u16 wol_proxy_vsi_seid;
  u64 flags;
  struct iavf_nvmupd_features nvmupd_features;
  u32 debug_mask;
  char err_str[16];
};
struct iavf_driver_version
{
  u8 major_version;
  u8 minor_version;
  u8 build_version;
  u8 subbuild_version;
  u8 driver_string[32];
};
union iavf_16byte_rx_desc
{
  struct
  {
    uint64_t pkt_addr;
    uint64_t hdr_addr;
  } read;
  struct
  {
    struct
    {
      struct
      {
        union
        {
          uint16_t mirroring_status;
          uint16_t fcoe_ctx_id;
        } mirr_fcoe;
        uint16_t l2tag1;
      } lo_dword;
      union
      {
        uint32_t rss;
        uint32_t fd_id;
        uint32_t fcoe_param;
      } hi_dword;
    } qword0;
    struct
    {
      uint64_t status_error_len;
    } qword1;
  } wb;
};
union iavf_32byte_rx_desc
{
  struct
  {
    uint64_t pkt_addr;
    uint64_t hdr_addr;
    uint64_t rsvd1;
    uint64_t rsvd2;
  } read;
  struct
  {
    struct
    {
      struct
      {
        union
        {
          uint16_t mirroring_status;
          uint16_t fcoe_ctx_id;
        } mirr_fcoe;
        uint16_t l2tag1;
      } lo_dword;
      union
      {
        uint32_t rss;
        uint32_t fcoe_param;
        uint32_t fd_id;
      } hi_dword;
    } qword0;
    struct
    {
      uint64_t status_error_len;
    } qword1;
    struct
    {
      uint16_t ext_status;
      uint16_t rsvd;
      uint16_t l2tag2_1;
      uint16_t l2tag2_2;
    } qword2;
    struct
    {
      union
      {
        uint32_t flex_bytes_lo;
        uint32_t pe_status;
      } lo_dword;
      union
      {
        uint32_t flex_bytes_hi;
        uint32_t fd_id;
      } hi_dword;
    } qword3;
  } wb;
};
enum iavf_rx_desc_status_bits
{
  IAVF_RX_DESC_STATUS_DD_SHIFT = 0,
  IAVF_RX_DESC_STATUS_EOF_SHIFT = 1,
  IAVF_RX_DESC_STATUS_L2TAG1P_SHIFT = 2,
  IAVF_RX_DESC_STATUS_L3L4P_SHIFT = 3,
  IAVF_RX_DESC_STATUS_CRCP_SHIFT = 4,
  IAVF_RX_DESC_STATUS_TSYNINDX_SHIFT = 5,
  IAVF_RX_DESC_STATUS_TSYNVALID_SHIFT = 7,
  IAVF_RX_DESC_STATUS_EXT_UDP_0_SHIFT = 8,
  IAVF_RX_DESC_STATUS_UMBCAST_SHIFT = 9,
  IAVF_RX_DESC_STATUS_FLM_SHIFT = 11,
  IAVF_RX_DESC_STATUS_FLTSTAT_SHIFT = 12,
  IAVF_RX_DESC_STATUS_LPBK_SHIFT = 14,
  IAVF_RX_DESC_STATUS_IPV6EXADD_SHIFT = 15,
  IAVF_RX_DESC_STATUS_RESERVED_SHIFT = 16,
  IAVF_RX_DESC_STATUS_INT_UDP_0_SHIFT = 18,
  IAVF_RX_DESC_STATUS_LAST
};
enum iavf_rx_desc_fltstat_values
{
  IAVF_RX_DESC_FLTSTAT_NO_DATA = 0,
  IAVF_RX_DESC_FLTSTAT_RSV_FD_ID = 1,
  IAVF_RX_DESC_FLTSTAT_RSV = 2,
  IAVF_RX_DESC_FLTSTAT_RSS_HASH = 3,
};
enum iavf_rx_desc_error_bits
{
  IAVF_RX_DESC_ERROR_RXE_SHIFT = 0,
  IAVF_RX_DESC_ERROR_RECIPE_SHIFT = 1,
  IAVF_RX_DESC_ERROR_HBO_SHIFT = 2,
  IAVF_RX_DESC_ERROR_L3L4E_SHIFT = 3,
  IAVF_RX_DESC_ERROR_IPE_SHIFT = 3,
  IAVF_RX_DESC_ERROR_L4E_SHIFT = 4,
  IAVF_RX_DESC_ERROR_EIPE_SHIFT = 5,
  IAVF_RX_DESC_ERROR_OVERSIZE_SHIFT = 6,
  IAVF_RX_DESC_ERROR_PPRS_SHIFT = 7
};
enum iavf_rx_desc_error_l3l4e_fcoe_masks
{
  IAVF_RX_DESC_ERROR_L3L4E_NONE = 0,
  IAVF_RX_DESC_ERROR_L3L4E_PROT = 1,
  IAVF_RX_DESC_ERROR_L3L4E_FC = 2,
  IAVF_RX_DESC_ERROR_L3L4E_DMAC_ERR = 3,
  IAVF_RX_DESC_ERROR_L3L4E_DMAC_WARN = 4
};
enum iavf_rx_l2_ptype
{
  IAVF_RX_PTYPE_L2_RESERVED = 0,
  IAVF_RX_PTYPE_L2_MAC_PAY2 = 1,
  IAVF_RX_PTYPE_L2_TIMESYNC_PAY2 = 2,
  IAVF_RX_PTYPE_L2_FIP_PAY2 = 3,
  IAVF_RX_PTYPE_L2_OUI_PAY2 = 4,
  IAVF_RX_PTYPE_L2_MACCNTRL_PAY2 = 5,
  IAVF_RX_PTYPE_L2_LLDP_PAY2 = 6,
  IAVF_RX_PTYPE_L2_ECP_PAY2 = 7,
  IAVF_RX_PTYPE_L2_EVB_PAY2 = 8,
  IAVF_RX_PTYPE_L2_QCN_PAY2 = 9,
  IAVF_RX_PTYPE_L2_EAPOL_PAY2 = 10,
  IAVF_RX_PTYPE_L2_ARP = 11,
  IAVF_RX_PTYPE_L2_FCOE_PAY3 = 12,
  IAVF_RX_PTYPE_L2_FCOE_FCDATA_PAY3 = 13,
  IAVF_RX_PTYPE_L2_FCOE_FCRDY_PAY3 = 14,
  IAVF_RX_PTYPE_L2_FCOE_FCRSP_PAY3 = 15,
  IAVF_RX_PTYPE_L2_FCOE_FCOTHER_PA = 16,
  IAVF_RX_PTYPE_L2_FCOE_VFT_PAY3 = 17,
  IAVF_RX_PTYPE_L2_FCOE_VFT_FCDATA = 18,
  IAVF_RX_PTYPE_L2_FCOE_VFT_FCRDY = 19,
  IAVF_RX_PTYPE_L2_FCOE_VFT_FCRSP = 20,
  IAVF_RX_PTYPE_L2_FCOE_VFT_FCOTHER = 21,
  IAVF_RX_PTYPE_GRENAT4_MAC_PAY3 = 58,
  IAVF_RX_PTYPE_GRENAT4_MACVLAN_IPV6_ICMP_PAY4 = 87,
  IAVF_RX_PTYPE_GRENAT6_MAC_PAY3 = 124,
  IAVF_RX_PTYPE_GRENAT6_MACVLAN_IPV6_ICMP_PAY4 = 153,
  IAVF_RX_PTYPE_PARSER_ABORTED = 255
};
struct iavf_rx_ptype_decoded
{
  u32 ptype : 8;
  u32 known : 1;
  u32 outer_ip : 1;
  u32 outer_ip_ver : 1;
  u32 outer_frag : 1;
  u32 tunnel_type : 3;
  u32 tunnel_end_prot : 2;
  u32 tunnel_end_frag : 1;
  u32 inner_prot : 4;
  u32 payload_layer : 3;
};
enum iavf_rx_ptype_outer_ip
{
  IAVF_RX_PTYPE_OUTER_L2 = 0,
  IAVF_RX_PTYPE_OUTER_IP = 1
};
enum iavf_rx_ptype_outer_ip_ver
{
  IAVF_RX_PTYPE_OUTER_NONE = 0,
  IAVF_RX_PTYPE_OUTER_IPV4 = 0,
  IAVF_RX_PTYPE_OUTER_IPV6 = 1
};
enum iavf_rx_ptype_outer_fragmented
{
  IAVF_RX_PTYPE_NOT_FRAG = 0,
  IAVF_RX_PTYPE_FRAG = 1
};
enum iavf_rx_ptype_tunnel_type
{
  IAVF_RX_PTYPE_TUNNEL_NONE = 0,
  IAVF_RX_PTYPE_TUNNEL_IP_IP = 1,
  IAVF_RX_PTYPE_TUNNEL_IP_GRENAT = 2,
  IAVF_RX_PTYPE_TUNNEL_IP_GRENAT_MAC = 3,
  IAVF_RX_PTYPE_TUNNEL_IP_GRENAT_MAC_VLAN = 4,
};
enum iavf_rx_ptype_tunnel_end_prot
{
  IAVF_RX_PTYPE_TUNNEL_END_NONE = 0,
  IAVF_RX_PTYPE_TUNNEL_END_IPV4 = 1,
  IAVF_RX_PTYPE_TUNNEL_END_IPV6 = 2,
};
enum iavf_rx_ptype_inner_prot
{
  IAVF_RX_PTYPE_INNER_PROT_NONE = 0,
  IAVF_RX_PTYPE_INNER_PROT_UDP = 1,
  IAVF_RX_PTYPE_INNER_PROT_TCP = 2,
  IAVF_RX_PTYPE_INNER_PROT_SCTP = 3,
  IAVF_RX_PTYPE_INNER_PROT_ICMP = 4,
  IAVF_RX_PTYPE_INNER_PROT_TIMESYNC = 5
};
enum iavf_rx_ptype_payload_layer
{
  IAVF_RX_PTYPE_PAYLOAD_LAYER_NONE = 0,
  IAVF_RX_PTYPE_PAYLOAD_LAYER_PAY2 = 1,
  IAVF_RX_PTYPE_PAYLOAD_LAYER_PAY3 = 2,
  IAVF_RX_PTYPE_PAYLOAD_LAYER_PAY4 = 3,
};
enum iavf_rx_desc_ext_status_bits
{
  IAVF_RX_DESC_EXT_STATUS_L2TAG2P_SHIFT = 0,
  IAVF_RX_DESC_EXT_STATUS_L2TAG3P_SHIFT = 1,
  IAVF_RX_DESC_EXT_STATUS_FLEXBL_SHIFT = 2,
  IAVF_RX_DESC_EXT_STATUS_FLEXBH_SHIFT = 4,
  IAVF_RX_DESC_EXT_STATUS_FDLONGB_SHIFT = 9,
  IAVF_RX_DESC_EXT_STATUS_FCOELONGB_SHIFT = 10,
  IAVF_RX_DESC_EXT_STATUS_PELONGB_SHIFT = 11,
};
enum iavf_rx_desc_pe_status_bits
{
  IAVF_RX_DESC_PE_STATUS_QPID_SHIFT = 0,
  IAVF_RX_DESC_PE_STATUS_L4PORT_SHIFT = 0,
  IAVF_RX_DESC_PE_STATUS_IPINDEX_SHIFT = 16,
  IAVF_RX_DESC_PE_STATUS_QPIDHIT_SHIFT = 24,
  IAVF_RX_DESC_PE_STATUS_APBVTHIT_SHIFT = 25,
  IAVF_RX_DESC_PE_STATUS_PORTV_SHIFT = 26,
  IAVF_RX_DESC_PE_STATUS_URG_SHIFT = 27,
  IAVF_RX_DESC_PE_STATUS_IPFRAG_SHIFT = 28,
  IAVF_RX_DESC_PE_STATUS_IPOPT_SHIFT = 29
};
enum iavf_rx_prog_status_desc_status_bits
{
  IAVF_RX_PROG_STATUS_DESC_DD_SHIFT = 0,
  IAVF_RX_PROG_STATUS_DESC_PROG_ID_SHIFT = 2
};
enum iavf_rx_prog_status_desc_prog_id_masks
{
  IAVF_RX_PROG_STATUS_DESC_FD_FILTER_STATUS = 1,
  IAVF_RX_PROG_STATUS_DESC_FCOE_CTXT_PROG_STATUS = 2,
  IAVF_RX_PROG_STATUS_DESC_FCOE_CTXT_INVL_STATUS = 4,
};
enum iavf_rx_prog_status_desc_error_bits
{
  IAVF_RX_PROG_STATUS_DESC_FD_TBL_FULL_SHIFT = 0,
  IAVF_RX_PROG_STATUS_DESC_NO_FD_ENTRY_SHIFT = 1,
  IAVF_RX_PROG_STATUS_DESC_FCOE_TBL_FULL_SHIFT = 2,
  IAVF_RX_PROG_STATUS_DESC_FCOE_CONFLICT_SHIFT = 3
};
struct iavf_tx_desc
{
  uint64_t buffer_addr;
  uint64_t cmd_type_offset_bsz;
};
enum iavf_tx_desc_dtype_value
{
  IAVF_TX_DESC_DTYPE_DATA = 0x0,
  IAVF_TX_DESC_DTYPE_NOP = 0x1,
  IAVF_TX_DESC_DTYPE_CONTEXT = 0x1,
  IAVF_TX_DESC_DTYPE_FCOE_CTX = 0x2,
  IAVF_TX_DESC_DTYPE_IPSEC = 0x3,
  IAVF_TX_DESC_DTYPE_FILTER_PROG = 0x8,
  IAVF_TX_DESC_DTYPE_DDP_CTX = 0x9,
  IAVF_TX_DESC_DTYPE_FLEX_DATA = 0xB,
  IAVF_TX_DESC_DTYPE_FLEX_CTX_1 = 0xC,
  IAVF_TX_DESC_DTYPE_FLEX_CTX_2 = 0xD,
  IAVF_TX_DESC_DTYPE_DESC_DONE = 0xF
};
enum iavf_tx_desc_cmd_bits
{
  IAVF_TX_DESC_CMD_EOP = 0x0001,
  IAVF_TX_DESC_CMD_RS = 0x0002,
  IAVF_TX_DESC_CMD_ICRC = 0x0004,
  IAVF_TX_DESC_CMD_IL2TAG1 = 0x0008,
  IAVF_TX_DESC_CMD_DUMMY = 0x0010,
  IAVF_TX_DESC_CMD_IIPT_NONIP = 0x0000,
  IAVF_TX_DESC_CMD_IIPT_IPV6 = 0x0020,
  IAVF_TX_DESC_CMD_IIPT_IPV4 = 0x0040,
  IAVF_TX_DESC_CMD_IIPT_IPV4_CSUM = 0x0060,
  IAVF_TX_DESC_CMD_FCOET = 0x0080,
  IAVF_TX_DESC_CMD_L4T_EOFT_UNK = 0x0000,
  IAVF_TX_DESC_CMD_L4T_EOFT_TCP = 0x0100,
  IAVF_TX_DESC_CMD_L4T_EOFT_SCTP = 0x0200,
  IAVF_TX_DESC_CMD_L4T_EOFT_UDP = 0x0300,
  IAVF_TX_DESC_CMD_L4T_EOFT_EOF_N = 0x0000,
  IAVF_TX_DESC_CMD_L4T_EOFT_EOF_T = 0x0100,
  IAVF_TX_DESC_CMD_L4T_EOFT_EOF_NI = 0x0200,
  IAVF_TX_DESC_CMD_L4T_EOFT_EOF_A = 0x0300,
};
enum iavf_tx_desc_length_fields
{
  IAVF_TX_DESC_LENGTH_MACLEN_SHIFT = 0,
  IAVF_TX_DESC_LENGTH_IPLEN_SHIFT = 7,
  IAVF_TX_DESC_LENGTH_L4_FC_LEN_SHIFT = 14
};
struct iavf_tx_context_desc
{
  uint32_t tunneling_params;
  uint16_t l2tag2;
  uint16_t rsvd;
  uint64_t type_cmd_tso_mss;
};
enum iavf_tx_ctx_desc_cmd_bits
{
  IAVF_TX_CTX_DESC_TSO = 0x01,
  IAVF_TX_CTX_DESC_TSYN = 0x02,
  IAVF_TX_CTX_DESC_IL2TAG2 = 0x04,
  IAVF_TX_CTX_DESC_IL2TAG2_IL2H = 0x08,
  IAVF_TX_CTX_DESC_SWTCH_NOTAG = 0x00,
  IAVF_TX_CTX_DESC_SWTCH_UPLINK = 0x10,
  IAVF_TX_CTX_DESC_SWTCH_LOCAL = 0x20,
  IAVF_TX_CTX_DESC_SWTCH_VSI = 0x30,
  IAVF_TX_CTX_DESC_SWPE = 0x40
};
struct iavf_nop_desc
{
  uint64_t rsvd;
  uint64_t dtype_cmd;
};
enum iavf_tx_nop_desc_cmd_bits
{
  IAVF_TX_NOP_DESC_EOP_SHIFT = 0,
  IAVF_TX_NOP_DESC_RS_SHIFT = 1,
  IAVF_TX_NOP_DESC_RSV_SHIFT = 2
};
enum iavf_filter_pctype
{
  IAVF_FILTER_PCTYPE_NONF_UNICAST_IPV4_UDP = 29,
  IAVF_FILTER_PCTYPE_NONF_MULTICAST_IPV4_UDP = 30,
  IAVF_FILTER_PCTYPE_NONF_IPV4_UDP = 31,
  IAVF_FILTER_PCTYPE_NONF_IPV4_TCP_SYN_NO_ACK = 32,
  IAVF_FILTER_PCTYPE_NONF_IPV4_TCP = 33,
  IAVF_FILTER_PCTYPE_NONF_IPV4_SCTP = 34,
  IAVF_FILTER_PCTYPE_NONF_IPV4_OTHER = 35,
  IAVF_FILTER_PCTYPE_FRAG_IPV4 = 36,
  IAVF_FILTER_PCTYPE_NONF_UNICAST_IPV6_UDP = 39,
  IAVF_FILTER_PCTYPE_NONF_MULTICAST_IPV6_UDP = 40,
  IAVF_FILTER_PCTYPE_NONF_IPV6_UDP = 41,
  IAVF_FILTER_PCTYPE_NONF_IPV6_TCP_SYN_NO_ACK = 42,
  IAVF_FILTER_PCTYPE_NONF_IPV6_TCP = 43,
  IAVF_FILTER_PCTYPE_NONF_IPV6_SCTP = 44,
  IAVF_FILTER_PCTYPE_NONF_IPV6_OTHER = 45,
  IAVF_FILTER_PCTYPE_FRAG_IPV6 = 46,
  IAVF_FILTER_PCTYPE_FCOE_OX = 48,
  IAVF_FILTER_PCTYPE_FCOE_RX = 49,
  IAVF_FILTER_PCTYPE_FCOE_OTHER = 50,
  IAVF_FILTER_PCTYPE_L2_PAYLOAD = 63,
};
enum iavf_tx_ctx_desc_eipt_offload
{
  IAVF_TX_CTX_EXT_IP_NONE = 0x0,
  IAVF_TX_CTX_EXT_IP_IPV6 = 0x1,
  IAVF_TX_CTX_EXT_IP_IPV4_NO_CSUM = 0x2,
  IAVF_TX_CTX_EXT_IP_IPV4 = 0x3
};
struct iavf_eth_stats
{
  u64 rx_bytes;
  u64 rx_unicast;
  u64 rx_multicast;
  u64 rx_broadcast;
  u64 rx_discards;
  u64 rx_unknown_protocol;
  u64 tx_bytes;
  u64 tx_unicast;
  u64 tx_multicast;
  u64 tx_broadcast;
  u64 tx_discards;
  u64 tx_errors;
};
struct iavf_lldp_variables
{
  u16 length;
  u16 adminstatus;
  u16 msgfasttx;
  u16 msgtxinterval;
  u16 txparams;
  u16 timers;
  u16 crc8;
};
struct iavf_profile_tlv_section_record
{
  u8 rtype;
  u8 type;
  u16 len;
  u8 data[12];
};
struct iavf_profile_aq_section
{
  u16 opcode;
  u16 flags;
  u8 param[16];
  u16 datalen;
  u8 data[1];
};
struct iavf_hw;
enum iavf_memory_type
{
  iavf_mem_arq_buf = 0,
  iavf_mem_asq_buf = 1,
  iavf_mem_atq_buf = 2,
  iavf_mem_arq_ring = 3,
  iavf_mem_atq_ring = 4,
  iavf_mem_pd = 5,
  iavf_mem_bp = 6,
  iavf_mem_bp_jumbo = 7,
  iavf_mem_reserved
};
enum iavf_status iavf_allocate_dma_mem_d(struct iavf_hw *hw,
                                         struct iavf_dma_mem *mem, u64 size,
                                         u32 alignment);
enum iavf_status iavf_free_dma_mem_d(struct iavf_hw *hw,
                                     struct iavf_dma_mem *mem);
enum iavf_status iavf_allocate_virt_mem_d(struct iavf_hw *hw,
                                          struct iavf_virt_mem *mem,
                                          u32 size);
enum iavf_status iavf_free_virt_mem_d(struct iavf_hw *hw,
                                      struct iavf_virt_mem *mem);
enum inline_ipsec_resp
{
  INLINE_IPSEC_SUCCESS = 0,
  INLINE_IPSEC_FAIL = -1,
  INLINE_IPSEC_ERR_FIFO_FULL = -2,
  INLINE_IPSEC_ERR_NOT_READY = -3,
  INLINE_IPSEC_ERR_VF_DOWN = -4,
  INLINE_IPSEC_ERR_INVALID_PARAMS = -5,
  INLINE_IPSEC_ERR_NO_MEM = -6,
};
enum inline_ipsec_ops
{
  INLINE_IPSEC_OP_GET_CAP = 0,
  INLINE_IPSEC_OP_GET_STATUS = 1,
  INLINE_IPSEC_OP_SA_CREATE = 2,
  INLINE_IPSEC_OP_SA_UPDATE = 3,
  INLINE_IPSEC_OP_SA_DESTROY = 4,
  INLINE_IPSEC_OP_SP_CREATE = 5,
  INLINE_IPSEC_OP_SP_DESTROY = 6,
  INLINE_IPSEC_OP_SA_READ = 7,
  INLINE_IPSEC_OP_EVENT = 8,
  INLINE_IPSEC_OP_RESP = 9,
};
struct virtchnl_algo_cap
{
  u32 algo_type;
  u16 block_size;
  u16 min_key_size;
  u16 max_key_size;
  u16 inc_key_size;
  u16 min_iv_size;
  u16 max_iv_size;
  u16 inc_iv_size;
  u16 min_digest_size;
  u16 max_digest_size;
  u16 inc_digest_size;
  u16 min_aad_size;
  u16 max_aad_size;
  u16 inc_aad_size;
} __attribute__((__packed__));
struct virtchnl_sym_crypto_cap
{
  u8 crypto_type;
  u8 algo_cap_num;
  struct virtchnl_algo_cap algo_cap_list[16];
} __attribute__((__packed__));
struct virtchnl_ipsec_cap
{
  u16 max_sa_num;
  u8 virtchnl_protocol_type;
  u8 virtchnl_sa_mode;
  u8 virtchnl_direction;
  u8 termination_mode;
  u8 crypto_cap_num;
  u16 desc_id;
  u32 caps_enabled;
  struct virtchnl_sym_crypto_cap cap[3];
} __attribute__((__packed__));
struct virtchnl_ipsec_crypto_cfg_item
{
  u8 crypto_type;
  u32 algo_type;
  u16 iv_len;
  u16 digest_len;
  u32 salt;
  u16 key_len;
  u8 key_data[128];
} __attribute__((__packed__));
struct virtchnl_ipsec_sym_crypto_cfg
{
  struct virtchnl_ipsec_crypto_cfg_item items[2];
};
struct virtchnl_ipsec_sa_cfg
{
  u8 virtchnl_protocol_type;
  u8 virtchnl_termination;
  u8 virtchnl_ip_type;
  u8 esn_enabled;
  u8 udp_encap_enabled;
  u8 virtchnl_direction;
  u8 reserved1;
  u32 spi;
  u8 src_addr[16];
  u8 dst_addr[16];
  u16 spd_ref;
  u32 esn_hi;
  u32 esn_low;
  u8 sa_index_en;
  u32 sa_index;
  u8 audit_en;
  u8 byte_limit_en;
  u64 byte_limit_hard;
  u64 byte_limit_soft;
  u8 drop_on_auth_fail_en;
  u8 arw_check_en;
  u8 arw_size;
  u8 no_ip_offload_en;
  u16 sa_domain;
  struct virtchnl_ipsec_sym_crypto_cfg crypto_cfg;
} __attribute__((__packed__));
struct virtchnl_ipsec_sa_update
{
  u32 sa_index;
  u32 esn_hi;
  u32 esn_low;
} __attribute__((__packed__));
struct virtchnl_ipsec_sa_destroy
{
  u8 flag;
  u32 sa_index[8];
} __attribute__((__packed__));
struct virtchnl_ipsec_sa_read
{
  u8 valid;
  u8 active;
  u8 sn_rollover;
  u8 virtchnl_protocol_type;
  u8 virtchnl_termination;
  u8 audit_en;
  u8 byte_limit_en;
  u64 byte_limit_hard;
  u64 byte_limit_soft;
  u8 drop_on_auth_fail_en;
  u8 arw_check_en;
  u8 arw_size;
  u8 reserved1;
  u64 arw_top;
  u8 arw[16];
  u64 packets_processed;
  u64 bytes_processed;
  u32 packets_dropped;
  u32 auth_fails;
  u32 arw_fails;
  u8 esn;
  u8 virtchnl_direction;
  u32 spi;
  u32 salt;
  u32 esn_hi;
  u32 esn_low;
  u16 sa_domain;
  u16 spd_ref;
  struct virtchnl_ipsec_sym_crypto_cfg crypto_cfg;
} __attribute__((__packed__));
struct virtchnl_ipsec_sp_cfg
{
  u32 spi;
  u32 dip[4];
  u8 drop;
  u8 cgd;
  u8 table_id;
  u8 set_tc;
  u8 is_udp;
  u8 reserved;
  u16 udp_port;
} __attribute__((__packed__));
struct virtchnl_ipsec_sp_destroy
{
  u8 table_id;
  u32 rule_id;
} __attribute__((__packed__));
struct virtchnl_ipsec_sp_cfg_resp
{
  u32 rule_id;
};
struct virtchnl_ipsec_sa_cfg_resp
{
  u32 sa_handle;
};
struct virtchnl_ipsec_event
{
  u32 ipsec_event_data;
};
struct virtchnl_ipsec_status
{
  u32 status;
};
struct virtchnl_ipsec_resp
{
  u32 resp;
};
struct inline_ipsec_msg
{
  u16 ipsec_opcode;
  u16 req_id;
  union
  {
    struct virtchnl_ipsec_sa_cfg sa_cfg[0];
    struct virtchnl_ipsec_sp_cfg sp_cfg[0];
    struct virtchnl_ipsec_sa_update sa_update[0];
    struct virtchnl_ipsec_sa_destroy sa_destroy[0];
    struct virtchnl_ipsec_sp_destroy sp_destroy[0];
    struct virtchnl_ipsec_sa_cfg_resp sa_cfg_resp[0];
    struct virtchnl_ipsec_sp_cfg_resp sp_cfg_resp[0];
    struct virtchnl_ipsec_cap ipsec_cap[0];
    struct virtchnl_ipsec_status ipsec_status[0];
    struct virtchnl_ipsec_resp ipsec_resp[0];
    struct virtchnl_ipsec_event event[0];
    struct virtchnl_ipsec_sa_read sa_read[0];
  } ipsec_data;
} __attribute__((__packed__));
static inline u16
virtchnl_inline_ipsec_val_msg_len(u16 opcode)
{
  u16 valid_len = sizeof(struct inline_ipsec_msg);
  switch (opcode)
  {
  case INLINE_IPSEC_OP_GET_CAP:
  case INLINE_IPSEC_OP_GET_STATUS:
    break;
  case INLINE_IPSEC_OP_SA_CREATE:
    valid_len += sizeof(struct virtchnl_ipsec_sa_cfg);
    break;
  case INLINE_IPSEC_OP_SP_CREATE:
    valid_len += sizeof(struct virtchnl_ipsec_sp_cfg);
    break;
  case INLINE_IPSEC_OP_SA_UPDATE:
    valid_len += sizeof(struct virtchnl_ipsec_sa_update);
    break;
  case INLINE_IPSEC_OP_SA_DESTROY:
    valid_len += sizeof(struct virtchnl_ipsec_sa_destroy);
    break;
  case INLINE_IPSEC_OP_SP_DESTROY:
    valid_len += sizeof(struct virtchnl_ipsec_sp_destroy);
    break;
  case INLINE_IPSEC_OP_RESP:
    valid_len += sizeof(struct virtchnl_ipsec_resp);
    break;
  default:
    valid_len = 0;
    break;
  }
  return valid_len;
}

enum virtchnl_status_code
{
  VIRTCHNL_STATUS_SUCCESS = 0,
  VIRTCHNL_STATUS_ERR_PARAM = -5,
  VIRTCHNL_STATUS_ERR_NO_MEMORY = -18,
  VIRTCHNL_STATUS_ERR_OPCODE_MISMATCH = -38,
  VIRTCHNL_STATUS_ERR_CQP_COMPL_ERROR = -39,
  VIRTCHNL_STATUS_ERR_INVALID_VF_ID = -40,
  VIRTCHNL_STATUS_ERR_ADMIN_QUEUE_ERROR = -53,
  VIRTCHNL_STATUS_ERR_NOT_SUPPORTED = -64,
};
enum virtchnl_link_speed
{
  VIRTCHNL_LINK_SPEED_UNKNOWN = 0,
  VIRTCHNL_LINK_SPEED_100MB = (1UL << (0x1)),
  VIRTCHNL_LINK_SPEED_1GB = (1UL << (0x2)),
  VIRTCHNL_LINK_SPEED_10GB = (1UL << (0x3)),
  VIRTCHNL_LINK_SPEED_40GB = (1UL << (0x4)),
  VIRTCHNL_LINK_SPEED_20GB = (1UL << (0x5)),
  VIRTCHNL_LINK_SPEED_25GB = (1UL << (0x6)),
  VIRTCHNL_LINK_SPEED_2_5GB = (1UL << (0x0)),
  VIRTCHNL_LINK_SPEED_5GB = (1UL << (0x7)),
};
enum virtchnl_rx_hsplit
{
  VIRTCHNL_RX_HSPLIT_NO_SPLIT = 0,
  VIRTCHNL_RX_HSPLIT_SPLIT_L2 = 1,
  VIRTCHNL_RX_HSPLIT_SPLIT_IP = 2,
  VIRTCHNL_RX_HSPLIT_SPLIT_TCP_UDP = 4,
  VIRTCHNL_RX_HSPLIT_SPLIT_SCTP = 8,
};
enum virtchnl_bw_limit_type
{
  VIRTCHNL_BW_SHAPER = 0,
};
enum virtchnl_ops
{
  VIRTCHNL_OP_UNKNOWN = 0,
  VIRTCHNL_OP_VERSION = 1,
  VIRTCHNL_OP_RESET_VF = 2,
  VIRTCHNL_OP_GET_VF_RESOURCES = 3,
  VIRTCHNL_OP_CONFIG_TX_QUEUE = 4,
  VIRTCHNL_OP_CONFIG_RX_QUEUE = 5,
  VIRTCHNL_OP_CONFIG_VSI_QUEUES = 6,
  VIRTCHNL_OP_CONFIG_IRQ_MAP = 7,
  VIRTCHNL_OP_ENABLE_QUEUES = 8,
  VIRTCHNL_OP_DISABLE_QUEUES = 9,
  VIRTCHNL_OP_ADD_ETH_ADDR = 10,
  VIRTCHNL_OP_DEL_ETH_ADDR = 11,
  VIRTCHNL_OP_ADD_VLAN = 12,
  VIRTCHNL_OP_DEL_VLAN = 13,
  VIRTCHNL_OP_CONFIG_PROMISCUOUS_MODE = 14,
  VIRTCHNL_OP_GET_STATS = 15,
  VIRTCHNL_OP_RSVD = 16,
  VIRTCHNL_OP_EVENT = 17,
  VIRTCHNL_OP_CONFIG_RSS_KEY = 23,
  VIRTCHNL_OP_CONFIG_RSS_LUT = 24,
  VIRTCHNL_OP_GET_RSS_HENA_CAPS = 25,
  VIRTCHNL_OP_SET_RSS_HENA = 26,
  VIRTCHNL_OP_ENABLE_VLAN_STRIPPING = 27,
  VIRTCHNL_OP_DISABLE_VLAN_STRIPPING = 28,
  VIRTCHNL_OP_REQUEST_QUEUES = 29,
  VIRTCHNL_OP_ENABLE_CHANNELS = 30,
  VIRTCHNL_OP_DISABLE_CHANNELS = 31,
  VIRTCHNL_OP_ADD_CLOUD_FILTER = 32,
  VIRTCHNL_OP_DEL_CLOUD_FILTER = 33,
  VIRTCHNL_OP_INLINE_IPSEC_CRYPTO = 34,
  VIRTCHNL_OP_DCF_CONFIG_BW = 37,
  VIRTCHNL_OP_DCF_VLAN_OFFLOAD = 38,
  VIRTCHNL_OP_DCF_CMD_DESC = 39,
  VIRTCHNL_OP_DCF_CMD_BUFF = 40,
  VIRTCHNL_OP_DCF_DISABLE = 41,
  VIRTCHNL_OP_DCF_GET_VSI_MAP = 42,
  VIRTCHNL_OP_DCF_GET_PKG_INFO = 43,
  VIRTCHNL_OP_GET_SUPPORTED_RXDIDS = 44,
  VIRTCHNL_OP_ADD_RSS_CFG = 45,
  VIRTCHNL_OP_DEL_RSS_CFG = 46,
  VIRTCHNL_OP_ADD_FDIR_FILTER = 47,
  VIRTCHNL_OP_DEL_FDIR_FILTER = 48,
  VIRTCHNL_OP_GET_MAX_RSS_QREGION = 50,
  VIRTCHNL_OP_GET_OFFLOAD_VLAN_V2_CAPS = 51,
  VIRTCHNL_OP_ADD_VLAN_V2 = 52,
  VIRTCHNL_OP_DEL_VLAN_V2 = 53,
  VIRTCHNL_OP_ENABLE_VLAN_STRIPPING_V2 = 54,
  VIRTCHNL_OP_DISABLE_VLAN_STRIPPING_V2 = 55,
  VIRTCHNL_OP_ENABLE_VLAN_INSERTION_V2 = 56,
  VIRTCHNL_OP_DISABLE_VLAN_INSERTION_V2 = 57,
  VIRTCHNL_OP_ENABLE_VLAN_FILTERING_V2 = 58,
  VIRTCHNL_OP_DISABLE_VLAN_FILTERING_V2 = 59,
  VIRTCHNL_OP_1588_PTP_GET_CAPS = 60,
  VIRTCHNL_OP_1588_PTP_GET_TIME = 61,
  VIRTCHNL_OP_GET_QOS_CAPS = 66,
  VIRTCHNL_OP_CONFIG_QUEUE_TC_MAP = 67,
  VIRTCHNL_OP_ENABLE_QUEUES_V2 = 107,
  VIRTCHNL_OP_DISABLE_QUEUES_V2 = 108,
  VIRTCHNL_OP_MAP_QUEUE_VECTOR = 111,
  VIRTCHNL_OP_CONFIG_QUEUE_BW = 112,
  VIRTCHNL_OP_CONFIG_QUANTA = 113,
  VIRTCHNL_OP_FLOW_SUBSCRIBE = 114,
  VIRTCHNL_OP_FLOW_UNSUBSCRIBE = 115,
  VIRTCHNL_OP_MAX,
};
static inline const char *
virtchnl_op_str(enum virtchnl_ops v_opcode)
{
  switch (v_opcode)
  {
  case VIRTCHNL_OP_UNKNOWN:
    return "VIRTCHNL_OP_UNKNOWN";
  case VIRTCHNL_OP_VERSION:
    return "VIRTCHNL_OP_VERSION";
  case VIRTCHNL_OP_RESET_VF:
    return "VIRTCHNL_OP_RESET_VF";
  case VIRTCHNL_OP_GET_VF_RESOURCES:
    return "VIRTCHNL_OP_GET_VF_RESOURCES";
  case VIRTCHNL_OP_CONFIG_TX_QUEUE:
    return "VIRTCHNL_OP_CONFIG_TX_QUEUE";
  case VIRTCHNL_OP_CONFIG_RX_QUEUE:
    return "VIRTCHNL_OP_CONFIG_RX_QUEUE";
  case VIRTCHNL_OP_CONFIG_VSI_QUEUES:
    return "VIRTCHNL_OP_CONFIG_VSI_QUEUES";
  case VIRTCHNL_OP_CONFIG_IRQ_MAP:
    return "VIRTCHNL_OP_CONFIG_IRQ_MAP";
  case VIRTCHNL_OP_ENABLE_QUEUES:
    return "VIRTCHNL_OP_ENABLE_QUEUES";
  case VIRTCHNL_OP_DISABLE_QUEUES:
    return "VIRTCHNL_OP_DISABLE_QUEUES";
  case VIRTCHNL_OP_ADD_ETH_ADDR:
    return "VIRTCHNL_OP_ADD_ETH_ADDR";
  case VIRTCHNL_OP_DEL_ETH_ADDR:
    return "VIRTCHNL_OP_DEL_ETH_ADDR";
  case VIRTCHNL_OP_ADD_VLAN:
    return "VIRTCHNL_OP_ADD_VLAN";
  case VIRTCHNL_OP_DEL_VLAN:
    return "VIRTCHNL_OP_DEL_VLAN";
  case VIRTCHNL_OP_CONFIG_PROMISCUOUS_MODE:
    return "VIRTCHNL_OP_CONFIG_PROMISCUOUS_MODE";
  case VIRTCHNL_OP_GET_STATS:
    return "VIRTCHNL_OP_GET_STATS";
  case VIRTCHNL_OP_RSVD:
    return "VIRTCHNL_OP_RSVD";
  case VIRTCHNL_OP_EVENT:
    return "VIRTCHNL_OP_EVENT";
  case VIRTCHNL_OP_CONFIG_RSS_KEY:
    return "VIRTCHNL_OP_CONFIG_RSS_KEY";
  case VIRTCHNL_OP_CONFIG_RSS_LUT:
    return "VIRTCHNL_OP_CONFIG_RSS_LUT";
  case VIRTCHNL_OP_GET_RSS_HENA_CAPS:
    return "VIRTCHNL_OP_GET_RSS_HENA_CAPS";
  case VIRTCHNL_OP_SET_RSS_HENA:
    return "VIRTCHNL_OP_SET_RSS_HENA";
  case VIRTCHNL_OP_ENABLE_VLAN_STRIPPING:
    return "VIRTCHNL_OP_ENABLE_VLAN_STRIPPING";
  case VIRTCHNL_OP_DISABLE_VLAN_STRIPPING:
    return "VIRTCHNL_OP_DISABLE_VLAN_STRIPPING";
  case VIRTCHNL_OP_REQUEST_QUEUES:
    return "VIRTCHNL_OP_REQUEST_QUEUES";
  case VIRTCHNL_OP_ENABLE_CHANNELS:
    return "VIRTCHNL_OP_ENABLE_CHANNELS";
  case VIRTCHNL_OP_DISABLE_CHANNELS:
    return "VIRTCHNL_OP_DISABLE_CHANNELS";
  case VIRTCHNL_OP_ADD_CLOUD_FILTER:
    return "VIRTCHNL_OP_ADD_CLOUD_FILTER";
  case VIRTCHNL_OP_DEL_CLOUD_FILTER:
    return "VIRTCHNL_OP_DEL_CLOUD_FILTER";
  case VIRTCHNL_OP_INLINE_IPSEC_CRYPTO:
    return "VIRTCHNL_OP_INLINE_IPSEC_CRYPTO";
  case VIRTCHNL_OP_DCF_CMD_DESC:
    return "VIRTCHNL_OP_DCF_CMD_DESC";
  case VIRTCHNL_OP_DCF_CMD_BUFF:
    return "VIRTCHNL_OP_DCF_CMD_BUFF";
  case VIRTCHNL_OP_DCF_DISABLE:
    return "VIRTCHNL_OP_DCF_DISABLE";
  case VIRTCHNL_OP_DCF_GET_VSI_MAP:
    return "VIRTCHNL_OP_DCF_GET_VSI_MAP";
  case VIRTCHNL_OP_GET_SUPPORTED_RXDIDS:
    return "VIRTCHNL_OP_GET_SUPPORTED_RXDIDS";
  case VIRTCHNL_OP_ADD_RSS_CFG:
    return "VIRTCHNL_OP_ADD_RSS_CFG";
  case VIRTCHNL_OP_DEL_RSS_CFG:
    return "VIRTCHNL_OP_DEL_RSS_CFG";
  case VIRTCHNL_OP_ADD_FDIR_FILTER:
    return "VIRTCHNL_OP_ADD_FDIR_FILTER";
  case VIRTCHNL_OP_DEL_FDIR_FILTER:
    return "VIRTCHNL_OP_DEL_FDIR_FILTER";
  case VIRTCHNL_OP_GET_MAX_RSS_QREGION:
    return "VIRTCHNL_OP_GET_MAX_RSS_QREGION";
  case VIRTCHNL_OP_ENABLE_QUEUES_V2:
    return "VIRTCHNL_OP_ENABLE_QUEUES_V2";
  case VIRTCHNL_OP_DISABLE_QUEUES_V2:
    return "VIRTCHNL_OP_DISABLE_QUEUES_V2";
  case VIRTCHNL_OP_MAP_QUEUE_VECTOR:
    return "VIRTCHNL_OP_MAP_QUEUE_VECTOR";
  case VIRTCHNL_OP_GET_OFFLOAD_VLAN_V2_CAPS:
    return "VIRTCHNL_OP_GET_OFFLOAD_VLAN_V2_CAPS";
  case VIRTCHNL_OP_ADD_VLAN_V2:
    return "VIRTCHNL_OP_ADD_VLAN_V2";
  case VIRTCHNL_OP_DEL_VLAN_V2:
    return "VIRTCHNL_OP_DEL_VLAN_V2";
  case VIRTCHNL_OP_ENABLE_VLAN_STRIPPING_V2:
    return "VIRTCHNL_OP_ENABLE_VLAN_STRIPPING_V2";
  case VIRTCHNL_OP_DISABLE_VLAN_STRIPPING_V2:
    return "VIRTCHNL_OP_DISABLE_VLAN_STRIPPING_V2";
  case VIRTCHNL_OP_ENABLE_VLAN_INSERTION_V2:
    return "VIRTCHNL_OP_ENABLE_VLAN_INSERTION_V2";
  case VIRTCHNL_OP_DISABLE_VLAN_INSERTION_V2:
    return "VIRTCHNL_OP_DISABLE_VLAN_INSERTION_V2";
  case VIRTCHNL_OP_ENABLE_VLAN_FILTERING_V2:
    return "VIRTCHNL_OP_ENABLE_VLAN_FILTERING_V2";
  case VIRTCHNL_OP_DISABLE_VLAN_FILTERING_V2:
    return "VIRTCHNL_OP_DISABLE_VLAN_FILTERING_V2";
  case VIRTCHNL_OP_1588_PTP_GET_CAPS:
    return "VIRTCHNL_OP_1588_PTP_GET_CAPS";
  case VIRTCHNL_OP_1588_PTP_GET_TIME:
    return "VIRTCHNL_OP_1588_PTP_GET_TIME";
  case VIRTCHNL_OP_FLOW_SUBSCRIBE:
    return "VIRTCHNL_OP_FLOW_SUBSCRIBE";
  case VIRTCHNL_OP_FLOW_UNSUBSCRIBE:
    return "VIRTCHNL_OP_FLOW_UNSUBSCRIBE";
  case VIRTCHNL_OP_MAX:
    return "VIRTCHNL_OP_MAX";
  default:
    return "Unsupported (update virtchnl.h)";
  }
}

struct virtchnl_msg
{
  u8 pad[8];
  enum virtchnl_ops v_opcode;
  enum virtchnl_status_code v_retval;
  u32 vfid;
};
enum virtchnl_static_assert_enum_virtchnl_msg
{
  virtchnl_static_assert_virtchnl_msg =
      (20) / ((sizeof(struct virtchnl_msg) == (20)) ? 1 : 0)
};
struct virtchnl_version_info
{
  u32 major;
  u32 minor;
};
enum virtchnl_static_assert_enum_virtchnl_version_info
{
  virtchnl_static_assert_virtchnl_version_info =
      (8) / ((sizeof(struct virtchnl_version_info) == (8)) ? 1 : 0)
};
enum virtchnl_vsi_type
{
  VIRTCHNL_VSI_TYPE_INVALID = 0,
  VIRTCHNL_VSI_SRIOV = 6,
};
struct virtchnl_vsi_resource
{
  u16 vsi_id;
  u16 num_queue_pairs;
  s32 vsi_type;
  u16 qset_handle;
  u8 default_mac_addr[6];
};
enum virtchnl_static_assert_enum_virtchnl_vsi_resource
{
  virtchnl_static_assert_virtchnl_vsi_resource =
      (16) / ((sizeof(struct virtchnl_vsi_resource) == (16)) ? 1 : 0)
};
struct virtchnl_vf_resource
{
  u16 num_vsis;
  u16 num_queue_pairs;
  u16 max_vectors;
  u16 max_mtu;
  u32 vf_cap_flags;
  u32 rss_key_size;
  u32 rss_lut_size;
  struct virtchnl_vsi_resource vsi_res[1];
};
enum virtchnl_static_assert_enum_virtchnl_vf_resource
{
  virtchnl_static_assert_virtchnl_vf_resource =
      (36) / ((sizeof(struct virtchnl_vf_resource) == (36)) ? 1 : 0)
};
struct virtchnl_txq_info
{
  u16 vsi_id;
  u16 queue_id;
  u16 ring_len;
  u16 headwb_enabled;
  u64 dma_ring_addr;
  u64 dma_headwb_addr;
};
enum virtchnl_static_assert_enum_virtchnl_txq_info
{
  virtchnl_static_assert_virtchnl_txq_info =
      (24) / ((sizeof(struct virtchnl_txq_info) == (24)) ? 1 : 0)
};
enum virtchnl_rx_desc_ids
{
  VIRTCHNL_RXDID_0_16B_BASE = 0,
  VIRTCHNL_RXDID_1_32B_BASE = 1,
  VIRTCHNL_RXDID_1_FLEX_SPLITQ = 1,
  VIRTCHNL_RXDID_2_FLEX_SQ_NIC = 2,
  VIRTCHNL_RXDID_3_FLEX_SQ_SW = 3,
  VIRTCHNL_RXDID_4_FLEX_SQ_NIC_VEB = 4,
  VIRTCHNL_RXDID_5_FLEX_SQ_NIC_ACL = 5,
  VIRTCHNL_RXDID_6_FLEX_SQ_NIC_2 = 6,
  VIRTCHNL_RXDID_7_HW_RSVD = 7,
  VIRTCHNL_RXDID_16_COMMS_GENERIC = 16,
  VIRTCHNL_RXDID_17_COMMS_AUX_VLAN = 17,
  VIRTCHNL_RXDID_18_COMMS_AUX_IPV4 = 18,
  VIRTCHNL_RXDID_19_COMMS_AUX_IPV6 = 19,
  VIRTCHNL_RXDID_20_COMMS_AUX_FLOW = 20,
  VIRTCHNL_RXDID_21_COMMS_AUX_TCP = 21,
};
enum virtchnl_rx_desc_id_bitmasks
{
  VIRTCHNL_RXDID_0_16B_BASE_M = (1UL << (VIRTCHNL_RXDID_0_16B_BASE)),
  VIRTCHNL_RXDID_1_32B_BASE_M = (1UL << (VIRTCHNL_RXDID_1_32B_BASE)),
  VIRTCHNL_RXDID_1_FLEX_SPLITQ_M = (1UL << (VIRTCHNL_RXDID_1_FLEX_SPLITQ)),
  VIRTCHNL_RXDID_2_FLEX_SQ_NIC_M = (1UL << (VIRTCHNL_RXDID_2_FLEX_SQ_NIC)),
  VIRTCHNL_RXDID_3_FLEX_SQ_SW_M = (1UL << (VIRTCHNL_RXDID_3_FLEX_SQ_SW)),
  VIRTCHNL_RXDID_4_FLEX_SQ_NIC_VEB_M =
      (1UL << (VIRTCHNL_RXDID_4_FLEX_SQ_NIC_VEB)),
  VIRTCHNL_RXDID_5_FLEX_SQ_NIC_ACL_M =
      (1UL << (VIRTCHNL_RXDID_5_FLEX_SQ_NIC_ACL)),
  VIRTCHNL_RXDID_6_FLEX_SQ_NIC_2_M =
      (1UL << (VIRTCHNL_RXDID_6_FLEX_SQ_NIC_2)),
  VIRTCHNL_RXDID_7_HW_RSVD_M = (1UL << (VIRTCHNL_RXDID_7_HW_RSVD)),
  VIRTCHNL_RXDID_16_COMMS_GENERIC_M =
      (1UL << (VIRTCHNL_RXDID_16_COMMS_GENERIC)),
  VIRTCHNL_RXDID_17_COMMS_AUX_VLAN_M =
      (1UL << (VIRTCHNL_RXDID_17_COMMS_AUX_VLAN)),
  VIRTCHNL_RXDID_18_COMMS_AUX_IPV4_M =
      (1UL << (VIRTCHNL_RXDID_18_COMMS_AUX_IPV4)),
  VIRTCHNL_RXDID_19_COMMS_AUX_IPV6_M =
      (1UL << (VIRTCHNL_RXDID_19_COMMS_AUX_IPV6)),
  VIRTCHNL_RXDID_20_COMMS_AUX_FLOW_M =
      (1UL << (VIRTCHNL_RXDID_20_COMMS_AUX_FLOW)),
  VIRTCHNL_RXDID_21_COMMS_AUX_TCP_M =
      (1UL << (VIRTCHNL_RXDID_21_COMMS_AUX_TCP)),
};
enum virtchnl_rxq_info_flags
{
  VIRTCHNL_PTP_RX_TSTAMP = (1UL << (0)),
};
struct virtchnl_rxq_info
{
  u16 vsi_id;
  u16 queue_id;
  u32 ring_len;
  u16 hdr_size;
  u16 splithdr_enabled;
  u32 databuffer_size;
  u32 max_pkt_size;
  u8 crc_disable;
  u8 rxdid;
  u8 flags;
  u8 pad1;
  u64 dma_ring_addr;
  s32 rx_split_pos;
  u32 pad2;
};
enum virtchnl_static_assert_enum_virtchnl_rxq_info
{
  virtchnl_static_assert_virtchnl_rxq_info =
      (40) / ((sizeof(struct virtchnl_rxq_info) == (40)) ? 1 : 0)
};
struct virtchnl_queue_pair_info
{
  struct virtchnl_txq_info txq;
  struct virtchnl_rxq_info rxq;
};
enum virtchnl_static_assert_enum_virtchnl_queue_pair_info
{
  virtchnl_static_assert_virtchnl_queue_pair_info =
      (64) / ((sizeof(struct virtchnl_queue_pair_info) == (64)) ? 1 : 0)
};
struct virtchnl_vsi_queue_config_info
{
  u16 vsi_id;
  u16 num_queue_pairs;
  u32 pad;
  struct virtchnl_queue_pair_info qpair[1];
};
enum virtchnl_static_assert_enum_virtchnl_vsi_queue_config_info
{
  virtchnl_static_assert_virtchnl_vsi_queue_config_info =
      (72) / ((sizeof(struct virtchnl_vsi_queue_config_info) == (72)) ? 1 : 0)
};
struct virtchnl_vf_res_request
{
  u16 num_queue_pairs;
};
struct virtchnl_vector_map
{
  u16 vsi_id;
  u16 vector_id;
  u16 rxq_map;
  u16 txq_map;
  u16 rxitr_idx;
  u16 txitr_idx;
};
enum virtchnl_static_assert_enum_virtchnl_vector_map
{
  virtchnl_static_assert_virtchnl_vector_map =
      (12) / ((sizeof(struct virtchnl_vector_map) == (12)) ? 1 : 0)
};
struct virtchnl_irq_map_info
{
  u16 num_vectors;
  struct virtchnl_vector_map vecmap[1];
};
enum virtchnl_static_assert_enum_virtchnl_irq_map_info
{
  virtchnl_static_assert_virtchnl_irq_map_info =
      (14) / ((sizeof(struct virtchnl_irq_map_info) == (14)) ? 1 : 0)
};
struct virtchnl_queue_select
{
  u16 vsi_id;
  u16 pad;
  u32 rx_queues;
  u32 tx_queues;
};
enum virtchnl_static_assert_enum_virtchnl_queue_select
{
  virtchnl_static_assert_virtchnl_queue_select =
      (12) / ((sizeof(struct virtchnl_queue_select) == (12)) ? 1 : 0)
};
struct virtchnl_max_rss_qregion
{
  u16 vport_id;
  u16 qregion_width;
  u8 pad[4];
};
enum virtchnl_static_assert_enum_virtchnl_max_rss_qregion
{
  virtchnl_static_assert_virtchnl_max_rss_qregion =
      (8) / ((sizeof(struct virtchnl_max_rss_qregion) == (8)) ? 1 : 0)
};
struct virtchnl_ether_addr
{
  u8 addr[6];
  u8 type;
  u8 pad;
};
enum virtchnl_static_assert_enum_virtchnl_ether_addr
{
  virtchnl_static_assert_virtchnl_ether_addr =
      (8) / ((sizeof(struct virtchnl_ether_addr) == (8)) ? 1 : 0)
};
struct virtchnl_ether_addr_list
{
  u16 vsi_id;
  u16 num_elements;
  struct virtchnl_ether_addr list[1];
};
enum virtchnl_static_assert_enum_virtchnl_ether_addr_list
{
  virtchnl_static_assert_virtchnl_ether_addr_list =
      (12) / ((sizeof(struct virtchnl_ether_addr_list) == (12)) ? 1 : 0)
};
struct virtchnl_vlan_filter_list
{
  u16 vsi_id;
  u16 num_elements;
  u16 vlan_id[1];
};
enum virtchnl_static_assert_enum_virtchnl_vlan_filter_list
{
  virtchnl_static_assert_virtchnl_vlan_filter_list =
      (6) / ((sizeof(struct virtchnl_vlan_filter_list) == (6)) ? 1 : 0)
};
enum virtchnl_vlan_support
{
  VIRTCHNL_VLAN_UNSUPPORTED = 0,
  VIRTCHNL_VLAN_ETHERTYPE_8100 = 0x00000001,
  VIRTCHNL_VLAN_ETHERTYPE_88A8 = 0x00000002,
  VIRTCHNL_VLAN_ETHERTYPE_9100 = 0x00000004,
  VIRTCHNL_VLAN_TAG_LOCATION_L2TAG1 = 0x00000100,
  VIRTCHNL_VLAN_TAG_LOCATION_L2TAG2 = 0x00000200,
  VIRTCHNL_VLAN_TAG_LOCATION_L2TAG2_2 = 0x00000400,
  VIRTCHNL_VLAN_PRIO = 0x01000000,
  VIRTCHNL_VLAN_FILTER_MASK = 0x10000000,
  VIRTCHNL_VLAN_ETHERTYPE_AND = 0x20000000,
  VIRTCHNL_VLAN_ETHERTYPE_XOR = 0x40000000,
  VIRTCHNL_VLAN_TOGGLE = 0x80000000
};
struct virtchnl_vlan_supported_caps
{
  u32 outer;
  u32 inner;
};
struct virtchnl_vlan_filtering_caps
{
  struct virtchnl_vlan_supported_caps filtering_support;
  u32 ethertype_init;
  u16 max_filters;
  u8 pad[2];
};
enum virtchnl_static_assert_enum_virtchnl_vlan_filtering_caps
{
  virtchnl_static_assert_virtchnl_vlan_filtering_caps =
      (16) / ((sizeof(struct virtchnl_vlan_filtering_caps) == (16)) ? 1 : 0)
};
enum virtchnl_vlan_ethertype_match
{
  VIRTCHNL_ETHERTYPE_STRIPPING_MATCHES_INSERTION = 0,
  VIRTCHNL_ETHERTYPE_MATCH_NOT_REQUIRED = 1,
};
struct virtchnl_vlan_offload_caps
{
  struct virtchnl_vlan_supported_caps stripping_support;
  struct virtchnl_vlan_supported_caps insertion_support;
  u32 ethertype_init;
  u8 ethertype_match;
  u8 pad[3];
};
enum virtchnl_static_assert_enum_virtchnl_vlan_offload_caps
{
  virtchnl_static_assert_virtchnl_vlan_offload_caps =
      (24) / ((sizeof(struct virtchnl_vlan_offload_caps) == (24)) ? 1 : 0)
};
struct virtchnl_vlan_caps
{
  struct virtchnl_vlan_filtering_caps filtering;
  struct virtchnl_vlan_offload_caps offloads;
};
enum virtchnl_static_assert_enum_virtchnl_vlan_caps
{
  virtchnl_static_assert_virtchnl_vlan_caps =
      (40) / ((sizeof(struct virtchnl_vlan_caps) == (40)) ? 1 : 0)
};
struct virtchnl_vlan
{
  u16 tci;
  u16 tci_mask;
  u16 tpid;
  u8 pad[2];
};
enum virtchnl_static_assert_enum_virtchnl_vlan
{
  virtchnl_static_assert_virtchnl_vlan =
      (8) / ((sizeof(struct virtchnl_vlan) == (8)) ? 1 : 0)
};
struct virtchnl_vlan_filter
{
  struct virtchnl_vlan inner;
  struct virtchnl_vlan outer;
  u8 pad[16];
};
enum virtchnl_static_assert_enum_virtchnl_vlan_filter
{
  virtchnl_static_assert_virtchnl_vlan_filter =
      (32) / ((sizeof(struct virtchnl_vlan_filter) == (32)) ? 1 : 0)
};
struct virtchnl_vlan_filter_list_v2
{
  u16 vport_id;
  u16 num_elements;
  u8 pad[4];
  struct virtchnl_vlan_filter filters[1];
};
enum virtchnl_static_assert_enum_virtchnl_vlan_filter_list_v2
{
  virtchnl_static_assert_virtchnl_vlan_filter_list_v2 =
      (40) / ((sizeof(struct virtchnl_vlan_filter_list_v2) == (40)) ? 1 : 0)
};
struct virtchnl_vlan_setting
{
  u32 outer_ethertype_setting;
  u32 inner_ethertype_setting;
  u16 vport_id;
  u8 pad[6];
};
enum virtchnl_static_assert_enum_virtchnl_vlan_setting
{
  virtchnl_static_assert_virtchnl_vlan_setting =
      (16) / ((sizeof(struct virtchnl_vlan_setting) == (16)) ? 1 : 0)
};
struct virtchnl_promisc_info
{
  u16 vsi_id;
  u16 flags;
};
enum virtchnl_static_assert_enum_virtchnl_promisc_info
{
  virtchnl_static_assert_virtchnl_promisc_info =
      (4) / ((sizeof(struct virtchnl_promisc_info) == (4)) ? 1 : 0)
};
struct virtchnl_eth_stats
{
  u64 rx_bytes;
  u64 rx_unicast;
  u64 rx_multicast;
  u64 rx_broadcast;
  u64 rx_discards;
  u64 rx_unknown_protocol;
  u64 tx_bytes;
  u64 tx_unicast;
  u64 tx_multicast;
  u64 tx_broadcast;
  u64 tx_discards;
  u64 tx_errors;
};
struct virtchnl_rss_key
{
  u16 vsi_id;
  u16 key_len;
  u8 key[1];
};
enum virtchnl_static_assert_enum_virtchnl_rss_key
{
  virtchnl_static_assert_virtchnl_rss_key =
      (6) / ((sizeof(struct virtchnl_rss_key) == (6)) ? 1 : 0)
};
struct virtchnl_rss_lut
{
  u16 vsi_id;
  u16 lut_entries;
  u8 lut[1];
};
enum virtchnl_static_assert_enum_virtchnl_rss_lut
{
  virtchnl_static_assert_virtchnl_rss_lut =
      (6) / ((sizeof(struct virtchnl_rss_lut) == (6)) ? 1 : 0)
};
struct virtchnl_rss_hena
{
  u64 hena;
};
enum virtchnl_static_assert_enum_virtchnl_rss_hena
{
  virtchnl_static_assert_virtchnl_rss_hena =
      (8) / ((sizeof(struct virtchnl_rss_hena) == (8)) ? 1 : 0)
};
enum virtchnl_rss_algorithm
{
  VIRTCHNL_RSS_ALG_TOEPLITZ_ASYMMETRIC = 0,
  VIRTCHNL_RSS_ALG_XOR_ASYMMETRIC = 1,
  VIRTCHNL_RSS_ALG_TOEPLITZ_SYMMETRIC = 2,
  VIRTCHNL_RSS_ALG_XOR_SYMMETRIC = 3,
};
struct virtchnl_channel_info
{
  u16 count;
  u16 offset;
  u32 pad;
  u64 max_tx_rate;
};
enum virtchnl_static_assert_enum_virtchnl_channel_info
{
  virtchnl_static_assert_virtchnl_channel_info =
      (16) / ((sizeof(struct virtchnl_channel_info) == (16)) ? 1 : 0)
};
struct virtchnl_tc_info
{
  u32 num_tc;
  u32 pad;
  struct virtchnl_channel_info list[1];
};
enum virtchnl_static_assert_enum_virtchnl_tc_info
{
  virtchnl_static_assert_virtchnl_tc_info =
      (24) / ((sizeof(struct virtchnl_tc_info) == (24)) ? 1 : 0)
};
struct virtchnl_l4_spec
{
  u8 src_mac[6];
  u8 dst_mac[6];
  uint16_t vlan_id;
  uint16_t pad;
  uint32_t src_ip[4];
  uint32_t dst_ip[4];
  uint16_t src_port;
  uint16_t dst_port;
};
enum virtchnl_static_assert_enum_virtchnl_l4_spec
{
  virtchnl_static_assert_virtchnl_l4_spec =
      (52) / ((sizeof(struct virtchnl_l4_spec) == (52)) ? 1 : 0)
};
union virtchnl_flow_spec
{
  struct virtchnl_l4_spec tcp_spec;
  u8 buffer[128];
};
enum virtchnl_static_asset_enum_virtchnl_flow_spec
{
  virtchnl_static_assert_virtchnl_flow_spec =
      (128) / ((sizeof(union virtchnl_flow_spec) == (128)) ? 1 : 0)
};
enum virtchnl_action
{
  VIRTCHNL_ACTION_DROP = 0,
  VIRTCHNL_ACTION_TC_REDIRECT,
  VIRTCHNL_ACTION_PASSTHRU,
  VIRTCHNL_ACTION_QUEUE,
  VIRTCHNL_ACTION_Q_REGION,
  VIRTCHNL_ACTION_MARK,
  VIRTCHNL_ACTION_COUNT,
};
enum virtchnl_flow_type
{
  VIRTCHNL_TCP_V4_FLOW = 0,
  VIRTCHNL_TCP_V6_FLOW,
  VIRTCHNL_UDP_V4_FLOW,
  VIRTCHNL_UDP_V6_FLOW,
};
struct virtchnl_filter
{
  union virtchnl_flow_spec data;
  union virtchnl_flow_spec mask;
  s32 flow_type;
  s32 action;
  u32 action_meta;
  u8 field_flags;
};
enum virtchnl_static_assert_enum_virtchnl_filter
{
  virtchnl_static_assert_virtchnl_filter =
      (272) / ((sizeof(struct virtchnl_filter) == (272)) ? 1 : 0)
};
struct virtchnl_shaper_bw
{
  u32 committed;
  u32 peak;
};
enum virtchnl_static_assert_enum_virtchnl_shaper_bw
{
  virtchnl_static_assert_virtchnl_shaper_bw =
      (8) / ((sizeof(struct virtchnl_shaper_bw) == (8)) ? 1 : 0)
};
struct virtchnl_dcf_vsi_map
{
  u16 pf_vsi;
  u16 num_vfs;
  u16 vf_vsi[1];
};
enum virtchnl_static_assert_enum_virtchnl_dcf_vsi_map
{
  virtchnl_static_assert_virtchnl_dcf_vsi_map =
      (6) / ((sizeof(struct virtchnl_dcf_vsi_map) == (6)) ? 1 : 0)
};
struct pkg_version
{
  u8 major;
  u8 minor;
  u8 update;
  u8 draft;
};
enum virtchnl_static_assert_enum_pkg_version
{
  virtchnl_static_assert_pkg_version =
      (4) / ((sizeof(struct pkg_version) == (4)) ? 1 : 0)
};
struct virtchnl_pkg_info
{
  struct pkg_version pkg_ver;
  u32 track_id;
  char pkg_name[32];
  u8 dsn[8];
};
enum virtchnl_static_assert_enum_virtchnl_pkg_info
{
  virtchnl_static_assert_virtchnl_pkg_info =
      (48) / ((sizeof(struct virtchnl_pkg_info) == (48)) ? 1 : 0)
};
struct virtchnl_dcf_vlan_offload
{
  u16 vf_id;
  u16 tpid;
  u16 vlan_flags;
  u16 vlan_id;
  u16 pad[4];
};
enum virtchnl_static_assert_enum_virtchnl_dcf_vlan_offload
{
  virtchnl_static_assert_virtchnl_dcf_vlan_offload =
      (16) / ((sizeof(struct virtchnl_dcf_vlan_offload) == (16)) ? 1 : 0)
};
struct virtchnl_dcf_bw_cfg
{
  u8 tc_num;
  u8 bw_type;
  u8 pad[2];
  enum virtchnl_bw_limit_type type;
  union
  {
    struct virtchnl_shaper_bw shaper;
    u8 pad2[32];
  };
};
enum virtchnl_static_assert_enum_virtchnl_dcf_bw_cfg
{
  virtchnl_static_assert_virtchnl_dcf_bw_cfg =
      (40) / ((sizeof(struct virtchnl_dcf_bw_cfg) == (40)) ? 1 : 0)
};
struct virtchnl_dcf_bw_cfg_list
{
  u16 vf_id;
  u8 num_elem;
  u8 node_type;
  struct virtchnl_dcf_bw_cfg cfg[1];
};
enum virtchnl_static_assert_enum_virtchnl_dcf_bw_cfg_list
{
  virtchnl_static_assert_virtchnl_dcf_bw_cfg_list =
      (44) / ((sizeof(struct virtchnl_dcf_bw_cfg_list) == (44)) ? 1 : 0)
};
struct virtchnl_supported_rxdids
{
  u64 supported_rxdids;
};
enum virtchnl_static_assert_enum_virtchnl_supported_rxdids
{
  virtchnl_static_assert_virtchnl_supported_rxdids =
      (8) / ((sizeof(struct virtchnl_supported_rxdids) == (8)) ? 1 : 0)
};
enum virtchnl_event_codes
{
  VIRTCHNL_EVENT_UNKNOWN = 0,
  VIRTCHNL_EVENT_LINK_CHANGE,
  VIRTCHNL_EVENT_RESET_IMPENDING,
  VIRTCHNL_EVENT_PF_DRIVER_CLOSE,
  VIRTCHNL_EVENT_DCF_VSI_MAP_UPDATE,
};
struct virtchnl_pf_event
{
  s32 event;
  union
  {
    struct
    {
      enum virtchnl_link_speed link_speed;
      u8 link_status;
    } link_event;
    struct
    {
      u32 link_speed;
      u8 link_status;
    } link_event_adv;
    struct
    {
      u16 vf_id;
      u16 vsi_id;
    } vf_vsi_map;
  } event_data;
  int severity;
};
enum virtchnl_static_assert_enum_virtchnl_pf_event
{
  virtchnl_static_assert_virtchnl_pf_event =
      (16) / ((sizeof(struct virtchnl_pf_event) == (16)) ? 1 : 0)
};
enum virtchnl_vfr_states
{
  VIRTCHNL_VFR_INPROGRESS = 0,
  VIRTCHNL_VFR_COMPLETED,
  VIRTCHNL_VFR_VFACTIVE,
};
enum virtchnl_proto_hdr_type
{
  VIRTCHNL_PROTO_HDR_NONE,
  VIRTCHNL_PROTO_HDR_ETH,
  VIRTCHNL_PROTO_HDR_S_VLAN,
  VIRTCHNL_PROTO_HDR_C_VLAN,
  VIRTCHNL_PROTO_HDR_IPV4,
  VIRTCHNL_PROTO_HDR_IPV6,
  VIRTCHNL_PROTO_HDR_TCP,
  VIRTCHNL_PROTO_HDR_UDP,
  VIRTCHNL_PROTO_HDR_SCTP,
  VIRTCHNL_PROTO_HDR_GTPU_IP,
  VIRTCHNL_PROTO_HDR_GTPU_EH,
  VIRTCHNL_PROTO_HDR_GTPU_EH_PDU_DWN,
  VIRTCHNL_PROTO_HDR_GTPU_EH_PDU_UP,
  VIRTCHNL_PROTO_HDR_PPPOE,
  VIRTCHNL_PROTO_HDR_L2TPV3,
  VIRTCHNL_PROTO_HDR_ESP,
  VIRTCHNL_PROTO_HDR_AH,
  VIRTCHNL_PROTO_HDR_PFCP,
  VIRTCHNL_PROTO_HDR_GTPC,
  VIRTCHNL_PROTO_HDR_ECPRI,
  VIRTCHNL_PROTO_HDR_L2TPV2,
  VIRTCHNL_PROTO_HDR_PPP,
  VIRTCHNL_PROTO_HDR_IPV4_FRAG,
  VIRTCHNL_PROTO_HDR_IPV6_EH_FRAG,
  VIRTCHNL_PROTO_HDR_GRE,
};
enum virtchnl_proto_hdr_field
{
  VIRTCHNL_PROTO_HDR_ETH_SRC = (VIRTCHNL_PROTO_HDR_ETH << 5),
  VIRTCHNL_PROTO_HDR_ETH_DST,
  VIRTCHNL_PROTO_HDR_ETH_ETHERTYPE,
  VIRTCHNL_PROTO_HDR_S_VLAN_ID = (VIRTCHNL_PROTO_HDR_S_VLAN << 5),
  VIRTCHNL_PROTO_HDR_C_VLAN_ID = (VIRTCHNL_PROTO_HDR_C_VLAN << 5),
  VIRTCHNL_PROTO_HDR_IPV4_SRC = (VIRTCHNL_PROTO_HDR_IPV4 << 5),
  VIRTCHNL_PROTO_HDR_IPV4_DST,
  VIRTCHNL_PROTO_HDR_IPV4_DSCP,
  VIRTCHNL_PROTO_HDR_IPV4_TTL,
  VIRTCHNL_PROTO_HDR_IPV4_PROT,
  VIRTCHNL_PROTO_HDR_IPV4_CHKSUM,
  VIRTCHNL_PROTO_HDR_IPV6_SRC = (VIRTCHNL_PROTO_HDR_IPV6 << 5),
  VIRTCHNL_PROTO_HDR_IPV6_DST,
  VIRTCHNL_PROTO_HDR_IPV6_TC,
  VIRTCHNL_PROTO_HDR_IPV6_HOP_LIMIT,
  VIRTCHNL_PROTO_HDR_IPV6_PROT,
  VIRTCHNL_PROTO_HDR_IPV6_PREFIX32_SRC,
  VIRTCHNL_PROTO_HDR_IPV6_PREFIX32_DST,
  VIRTCHNL_PROTO_HDR_IPV6_PREFIX40_SRC,
  VIRTCHNL_PROTO_HDR_IPV6_PREFIX40_DST,
  VIRTCHNL_PROTO_HDR_IPV6_PREFIX48_SRC,
  VIRTCHNL_PROTO_HDR_IPV6_PREFIX48_DST,
  VIRTCHNL_PROTO_HDR_IPV6_PREFIX56_SRC,
  VIRTCHNL_PROTO_HDR_IPV6_PREFIX56_DST,
  VIRTCHNL_PROTO_HDR_IPV6_PREFIX64_SRC,
  VIRTCHNL_PROTO_HDR_IPV6_PREFIX64_DST,
  VIRTCHNL_PROTO_HDR_IPV6_PREFIX96_SRC,
  VIRTCHNL_PROTO_HDR_IPV6_PREFIX96_DST,
  VIRTCHNL_PROTO_HDR_TCP_SRC_PORT = (VIRTCHNL_PROTO_HDR_TCP << 5),
  VIRTCHNL_PROTO_HDR_TCP_DST_PORT,
  VIRTCHNL_PROTO_HDR_TCP_CHKSUM,
  VIRTCHNL_PROTO_HDR_UDP_SRC_PORT = (VIRTCHNL_PROTO_HDR_UDP << 5),
  VIRTCHNL_PROTO_HDR_UDP_DST_PORT,
  VIRTCHNL_PROTO_HDR_UDP_CHKSUM,
  VIRTCHNL_PROTO_HDR_SCTP_SRC_PORT = (VIRTCHNL_PROTO_HDR_SCTP << 5),
  VIRTCHNL_PROTO_HDR_SCTP_DST_PORT,
  VIRTCHNL_PROTO_HDR_SCTP_CHKSUM,
  VIRTCHNL_PROTO_HDR_GTPU_IP_TEID = (VIRTCHNL_PROTO_HDR_GTPU_IP << 5),
  VIRTCHNL_PROTO_HDR_GTPU_EH_PDU = (VIRTCHNL_PROTO_HDR_GTPU_EH << 5),
  VIRTCHNL_PROTO_HDR_GTPU_EH_QFI,
  VIRTCHNL_PROTO_HDR_PPPOE_SESS_ID = (VIRTCHNL_PROTO_HDR_PPPOE << 5),
  VIRTCHNL_PROTO_HDR_L2TPV3_SESS_ID = (VIRTCHNL_PROTO_HDR_L2TPV3 << 5),
  VIRTCHNL_PROTO_HDR_ESP_SPI = (VIRTCHNL_PROTO_HDR_ESP << 5),
  VIRTCHNL_PROTO_HDR_AH_SPI = (VIRTCHNL_PROTO_HDR_AH << 5),
  VIRTCHNL_PROTO_HDR_PFCP_S_FIELD = (VIRTCHNL_PROTO_HDR_PFCP << 5),
  VIRTCHNL_PROTO_HDR_PFCP_SEID,
  VIRTCHNL_PROTO_HDR_GTPC_TEID = (VIRTCHNL_PROTO_HDR_GTPC << 5),
  VIRTCHNL_PROTO_HDR_ECPRI_MSG_TYPE = (VIRTCHNL_PROTO_HDR_ECPRI << 5),
  VIRTCHNL_PROTO_HDR_ECPRI_PC_RTC_ID,
  VIRTCHNL_PROTO_HDR_IPV4_FRAG_PKID = (VIRTCHNL_PROTO_HDR_IPV4_FRAG << 5),
  VIRTCHNL_PROTO_HDR_IPV6_EH_FRAG_PKID =
      (VIRTCHNL_PROTO_HDR_IPV6_EH_FRAG << 5),
  VIRTCHNL_PROTO_HDR_GTPU_DWN_QFI = (VIRTCHNL_PROTO_HDR_GTPU_EH_PDU_DWN << 5),
  VIRTCHNL_PROTO_HDR_GTPU_UP_QFI = (VIRTCHNL_PROTO_HDR_GTPU_EH_PDU_UP << 5),
  VIRTCHNL_PROTO_HDR_L2TPV2_SESS_ID = (VIRTCHNL_PROTO_HDR_L2TPV2 << 5),
  VIRTCHNL_PROTO_HDR_L2TPV2_LEN_SESS_ID,
};
struct virtchnl_proto_hdr
{
  s32 type;
  u32 field_selector;
  u8 buffer[64];
};
enum virtchnl_static_assert_enum_virtchnl_proto_hdr
{
  virtchnl_static_assert_virtchnl_proto_hdr =
      (72) / ((sizeof(struct virtchnl_proto_hdr) == (72)) ? 1 : 0)
};
struct virtchnl_proto_hdr_w_msk
{
  s32 type;
  u32 pad;
  u8 buffer_spec[64];
  u8 buffer_mask[64];
};
enum virtchnl_static_assert_enum_virtchnl_proto_hdr_w_msk
{
  virtchnl_static_assert_virtchnl_proto_hdr_w_msk =
      (136) / ((sizeof(struct virtchnl_proto_hdr_w_msk) == (136)) ? 1 : 0)
};
struct virtchnl_proto_hdrs
{
  u8 tunnel_level;
  int count;
  union
  {
    struct virtchnl_proto_hdr proto_hdr[32];
    struct virtchnl_proto_hdr_w_msk proto_hdr_w_msk[16];
    struct
    {
      u16 pkt_len;
      u8 spec[1024];
      u8 mask[1024];
    } raw;
  };
};
enum virtchnl_static_assert_enum_virtchnl_proto_hdrs
{
  virtchnl_static_assert_virtchnl_proto_hdrs =
      (2312) / ((sizeof(struct virtchnl_proto_hdrs) == (2312)) ? 1 : 0)
};
struct virtchnl_rss_cfg
{
  struct virtchnl_proto_hdrs proto_hdrs;
  s32 rss_algorithm;
  u8 reserved[128];
};
enum virtchnl_static_assert_enum_virtchnl_rss_cfg
{
  virtchnl_static_assert_virtchnl_rss_cfg =
      (2444) / ((sizeof(struct virtchnl_rss_cfg) == (2444)) ? 1 : 0)
};
struct virtchnl_filter_action
{
  s32 type;
  union
  {
    struct
    {
      u16 index;
      u8 region;
    } queue;
    struct
    {
      u8 shared;
      u32 id;
    } count;
    u32 mark_id;
    u8 reserve[32];
  } act_conf;
};
enum virtchnl_static_assert_enum_virtchnl_filter_action
{
  virtchnl_static_assert_virtchnl_filter_action =
      (36) / ((sizeof(struct virtchnl_filter_action) == (36)) ? 1 : 0)
};
struct virtchnl_filter_action_set
{
  int count;
  struct virtchnl_filter_action actions[8];
};
enum virtchnl_static_assert_enum_virtchnl_filter_action_set
{
  virtchnl_static_assert_virtchnl_filter_action_set =
      (292) / ((sizeof(struct virtchnl_filter_action_set) == (292)) ? 1 : 0)
};
struct virtchnl_fdir_rule
{
  struct virtchnl_proto_hdrs proto_hdrs;
  struct virtchnl_filter_action_set action_set;
};
enum virtchnl_static_assert_enum_virtchnl_fdir_rule
{
  virtchnl_static_assert_virtchnl_fdir_rule =
      (2604) / ((sizeof(struct virtchnl_fdir_rule) == (2604)) ? 1 : 0)
};
enum virtchnl_fdir_prgm_status
{
  VIRTCHNL_FDIR_SUCCESS = 0,
  VIRTCHNL_FDIR_FAILURE_RULE_NORESOURCE,
  VIRTCHNL_FDIR_FAILURE_RULE_EXIST,
  VIRTCHNL_FDIR_FAILURE_RULE_CONFLICT,
  VIRTCHNL_FDIR_FAILURE_RULE_NONEXIST,
  VIRTCHNL_FDIR_FAILURE_RULE_INVALID,
  VIRTCHNL_FDIR_FAILURE_RULE_TIMEOUT,
  VIRTCHNL_FDIR_FAILURE_QUERY_INVALID,
};
struct virtchnl_fdir_add
{
  u16 vsi_id;
  u16 validate_only;
  u32 flow_id;
  struct virtchnl_fdir_rule rule_cfg;
  s32 status;
};
enum virtchnl_static_assert_enum_virtchnl_fdir_add
{
  virtchnl_static_assert_virtchnl_fdir_add =
      (2616) / ((sizeof(struct virtchnl_fdir_add) == (2616)) ? 1 : 0)
};
struct virtchnl_fdir_del
{
  u16 vsi_id;
  u16 pad;
  u32 flow_id;
  s32 status;
};
enum virtchnl_static_assert_enum_virtchnl_fdir_del
{
  virtchnl_static_assert_virtchnl_fdir_del =
      (12) / ((sizeof(struct virtchnl_fdir_del) == (12)) ? 1 : 0)
};
enum virtchnl_fsub_prgm_status
{
  VIRTCHNL_FSUB_SUCCESS = 0,
  VIRTCHNL_FSUB_FAILURE_RULE_NORESOURCE,
  VIRTCHNL_FSUB_FAILURE_RULE_EXIST,
  VIRTCHNL_FSUB_FAILURE_RULE_NONEXIST,
  VIRTCHNL_FSUB_FAILURE_RULE_INVALID,
};
struct virtchnl_flow_sub
{
  u16 vsi_id;
  u8 validate_only;
  u8 priority;
  u32 flow_id;
  struct virtchnl_proto_hdrs proto_hdrs;
  struct virtchnl_filter_action_set actions;
  s32 status;
};
enum virtchnl_static_assert_enum_virtchnl_flow_sub
{
  virtchnl_static_assert_virtchnl_flow_sub =
      (2616) / ((sizeof(struct virtchnl_flow_sub) == (2616)) ? 1 : 0)
};
struct virtchnl_flow_unsub
{
  u16 vsi_id;
  u16 pad;
  u32 flow_id;
  s32 status;
};
enum virtchnl_static_assert_enum_virtchnl_flow_unsub
{
  virtchnl_static_assert_virtchnl_flow_unsub =
      (12) / ((sizeof(struct virtchnl_flow_unsub) == (12)) ? 1 : 0)
};
struct virtchnl_qos_cap_elem
{
  u8 tc_num;
  u8 tc_prio;
  u8 arbiter;
  u8 weight;
  enum virtchnl_bw_limit_type type;
  union
  {
    struct virtchnl_shaper_bw shaper;
    u8 pad2[32];
  };
};
enum virtchnl_static_assert_enum_virtchnl_qos_cap_elem
{
  virtchnl_static_assert_virtchnl_qos_cap_elem =
      (40) / ((sizeof(struct virtchnl_qos_cap_elem) == (40)) ? 1 : 0)
};
struct virtchnl_qos_cap_list
{
  u16 vsi_id;
  u16 num_elem;
  struct virtchnl_qos_cap_elem cap[1];
};
enum virtchnl_static_assert_enum_virtchnl_qos_cap_list
{
  virtchnl_static_assert_virtchnl_qos_cap_list =
      (44) / ((sizeof(struct virtchnl_qos_cap_list) == (44)) ? 1 : 0)
};
struct virtchnl_queue_tc_mapping
{
  u16 vsi_id;
  u16 num_tc;
  u16 num_queue_pairs;
  u8 pad[2];
  union
  {
    struct
    {
      u16 start_queue_id;
      u16 queue_count;
    } req;
    struct
    {
      u16 prio_type;
      u16 valid_prio_bitmap;
    } resp;
  } tc[1];
};
enum virtchnl_static_assert_enum_virtchnl_queue_tc_mapping
{
  virtchnl_static_assert_virtchnl_queue_tc_mapping =
      (12) / ((sizeof(struct virtchnl_queue_tc_mapping) == (12)) ? 1 : 0)
};
struct virtchnl_queue_bw
{
  u16 queue_id;
  u8 tc;
  u8 pad;
  struct virtchnl_shaper_bw shaper;
};
enum virtchnl_static_assert_enum_virtchnl_queue_bw
{
  virtchnl_static_assert_virtchnl_queue_bw =
      (12) / ((sizeof(struct virtchnl_queue_bw) == (12)) ? 1 : 0)
};
struct virtchnl_queues_bw_cfg
{
  u16 vsi_id;
  u16 num_queues;
  struct virtchnl_queue_bw cfg[1];
};
enum virtchnl_static_assert_enum_virtchnl_queues_bw_cfg
{
  virtchnl_static_assert_virtchnl_queues_bw_cfg =
      (16) / ((sizeof(struct virtchnl_queues_bw_cfg) == (16)) ? 1 : 0)
};
enum virtchnl_queue_type
{
  VIRTCHNL_QUEUE_TYPE_TX = 0,
  VIRTCHNL_QUEUE_TYPE_RX = 1,
  VIRTCHNL_QUEUE_TYPE_TX_COMPLETION = 2,
  VIRTCHNL_QUEUE_TYPE_RX_BUFFER = 3,
  VIRTCHNL_QUEUE_TYPE_CONFIG_TX = 4,
  VIRTCHNL_QUEUE_TYPE_CONFIG_RX = 5
};
struct virtchnl_queue_chunk
{
  s32 type;
  u16 start_queue_id;
  u16 num_queues;
};
enum virtchnl_static_assert_enum_virtchnl_queue_chunk
{
  virtchnl_static_assert_virtchnl_queue_chunk =
      (8) / ((sizeof(struct virtchnl_queue_chunk) == (8)) ? 1 : 0)
};
struct virtchnl_queue_chunks
{
  u16 num_chunks;
  u16 rsvd;
  struct virtchnl_queue_chunk chunks[1];
};
enum virtchnl_static_assert_enum_virtchnl_queue_chunks
{
  virtchnl_static_assert_virtchnl_queue_chunks =
      (12) / ((sizeof(struct virtchnl_queue_chunks) == (12)) ? 1 : 0)
};
struct virtchnl_del_ena_dis_queues
{
  u16 vport_id;
  u16 pad;
  struct virtchnl_queue_chunks chunks;
};
enum virtchnl_static_assert_enum_virtchnl_del_ena_dis_queues
{
  virtchnl_static_assert_virtchnl_del_ena_dis_queues =
      (16) / ((sizeof(struct virtchnl_del_ena_dis_queues) == (16)) ? 1 : 0)
};
enum virtchnl_itr_idx
{
  VIRTCHNL_ITR_IDX_0 = 0,
  VIRTCHNL_ITR_IDX_1 = 1,
  VIRTCHNL_ITR_IDX_NO_ITR = 3,
};
struct virtchnl_queue_vector
{
  u16 queue_id;
  u16 vector_id;
  u8 pad[4];
  s32 itr_idx;
  s32 queue_type;
};
enum virtchnl_static_assert_enum_virtchnl_queue_vector
{
  virtchnl_static_assert_virtchnl_queue_vector =
      (16) / ((sizeof(struct virtchnl_queue_vector) == (16)) ? 1 : 0)
};
struct virtchnl_queue_vector_maps
{
  u16 vport_id;
  u16 num_qv_maps;
  u8 pad[4];
  struct virtchnl_queue_vector qv_maps[1];
};
enum virtchnl_static_assert_enum_virtchnl_queue_vector_maps
{
  virtchnl_static_assert_virtchnl_queue_vector_maps =
      (24) / ((sizeof(struct virtchnl_queue_vector_maps) == (24)) ? 1 : 0)
};
struct virtchnl_quanta_cfg
{
  u16 quanta_size;
  struct virtchnl_queue_chunk queue_select;
};
enum virtchnl_static_assert_enum_virtchnl_quanta_cfg
{
  virtchnl_static_assert_virtchnl_quanta_cfg =
      (12) / ((sizeof(struct virtchnl_quanta_cfg) == (12)) ? 1 : 0)
};
struct virtchnl_phc_regs
{
  u32 clock_hi;
  u32 clock_lo;
  u8 pcie_region;
  u8 rsvd[15];
};
enum virtchnl_static_assert_enum_virtchnl_phc_regs
{
  virtchnl_static_assert_virtchnl_phc_regs =
      (24) / ((sizeof(struct virtchnl_phc_regs) == (24)) ? 1 : 0)
};
struct virtchnl_ptp_caps
{
  struct virtchnl_phc_regs phc_regs;
  u32 caps;
  s32 max_adj;
  u8 tx_tstamp_idx;
  u8 n_ext_ts;
  u8 n_per_out;
  u8 n_pins;
  u8 tx_tstamp_format;
  u8 rsvd[11];
};
enum virtchnl_static_assert_enum_virtchnl_ptp_caps
{
  virtchnl_static_assert_virtchnl_ptp_caps =
      (48) / ((sizeof(struct virtchnl_ptp_caps) == (48)) ? 1 : 0)
};
struct virtchnl_phc_time
{
  u64 time;
  u8 rsvd[8];
};
enum virtchnl_static_assert_enum_virtchnl_phc_time
{
  virtchnl_static_assert_virtchnl_phc_time =
      (16) / ((sizeof(struct virtchnl_phc_time) == (16)) ? 1 : 0)
};
enum virtchnl_vector_limits
{
  VIRTCHNL_OP_CONFIG_VSI_QUEUES_MAX =
      ((u16)(~0) - sizeof(struct virtchnl_vsi_queue_config_info)) /
      sizeof(struct virtchnl_queue_pair_info),
  VIRTCHNL_OP_CONFIG_IRQ_MAP_MAX =
      ((u16)(~0) - sizeof(struct virtchnl_irq_map_info)) /
      sizeof(struct virtchnl_vector_map),
  VIRTCHNL_OP_ADD_DEL_ETH_ADDR_MAX =
      ((u16)(~0) - sizeof(struct virtchnl_ether_addr_list)) /
      sizeof(struct virtchnl_ether_addr),
  VIRTCHNL_OP_ADD_DEL_VLAN_MAX =
      ((u16)(~0) - sizeof(struct virtchnl_vlan_filter_list)) / sizeof(u16),
  VIRTCHNL_OP_ENABLE_CHANNELS_MAX =
      ((u16)(~0) - sizeof(struct virtchnl_tc_info)) /
      sizeof(struct virtchnl_channel_info),
  VIRTCHNL_OP_ENABLE_DISABLE_DEL_QUEUES_V2_MAX =
      ((u16)(~0) - sizeof(struct virtchnl_del_ena_dis_queues)) /
      sizeof(struct virtchnl_queue_chunk),
  VIRTCHNL_OP_MAP_UNMAP_QUEUE_VECTOR_MAX =
      ((u16)(~0) - sizeof(struct virtchnl_queue_vector_maps)) /
      sizeof(struct virtchnl_queue_vector),
  VIRTCHNL_OP_ADD_DEL_VLAN_V2_MAX =
      ((u16)(~0) - sizeof(struct virtchnl_vlan_filter_list_v2)) /
      sizeof(struct virtchnl_vlan_filter),
};
static inline int
virtchnl_vc_validate_vf_msg(struct virtchnl_version_info *ver, u32 v_opcode,
                            u8 *msg, u16 msglen)
{
  _Bool err_msg_format = 0;
  u32 valid_len = 0;
  switch (v_opcode)
  {
  case VIRTCHNL_OP_VERSION:
    valid_len = sizeof(struct virtchnl_version_info);
    break;
  case VIRTCHNL_OP_RESET_VF:
    break;
  case VIRTCHNL_OP_GET_VF_RESOURCES:
    if ((((ver)->major == 1) && ((ver)->minor == 1)))
      valid_len = sizeof(u32);
    break;
  case VIRTCHNL_OP_CONFIG_TX_QUEUE:
    valid_len = sizeof(struct virtchnl_txq_info);
    break;
  case VIRTCHNL_OP_CONFIG_RX_QUEUE:
    valid_len = sizeof(struct virtchnl_rxq_info);
    break;
  case VIRTCHNL_OP_CONFIG_VSI_QUEUES:
    valid_len = sizeof(struct virtchnl_vsi_queue_config_info);
    if (msglen >= valid_len)
    {
      struct virtchnl_vsi_queue_config_info *vqc =
          (struct virtchnl_vsi_queue_config_info *)msg;
      if (vqc->num_queue_pairs == 0 || vqc->num_queue_pairs >
                                           VIRTCHNL_OP_CONFIG_VSI_QUEUES_MAX)
      {
        err_msg_format = 1;
        break;
      }
      valid_len += (vqc->num_queue_pairs *
                    sizeof(struct virtchnl_queue_pair_info));
    }
    break;
  case VIRTCHNL_OP_CONFIG_IRQ_MAP:
    valid_len = sizeof(struct virtchnl_irq_map_info);
    if (msglen >= valid_len)
    {
      struct virtchnl_irq_map_info *vimi =
          (struct virtchnl_irq_map_info *)msg;
      if (vimi->num_vectors == 0 || vimi->num_vectors >
                                        VIRTCHNL_OP_CONFIG_IRQ_MAP_MAX)
      {
        err_msg_format = 1;
        break;
      }
      valid_len += (vimi->num_vectors *
                    sizeof(struct virtchnl_vector_map));
    }
    break;
  case VIRTCHNL_OP_ENABLE_QUEUES:
  case VIRTCHNL_OP_DISABLE_QUEUES:
    valid_len = sizeof(struct virtchnl_queue_select);
    break;
  case VIRTCHNL_OP_GET_MAX_RSS_QREGION:
    break;
  case VIRTCHNL_OP_ADD_ETH_ADDR:
  case VIRTCHNL_OP_DEL_ETH_ADDR:
    valid_len = sizeof(struct virtchnl_ether_addr_list);
    if (msglen >= valid_len)
    {
      struct virtchnl_ether_addr_list *veal =
          (struct virtchnl_ether_addr_list *)msg;
      if (veal->num_elements == 0 || veal->num_elements >
                                         VIRTCHNL_OP_ADD_DEL_ETH_ADDR_MAX)
      {
        err_msg_format = 1;
        break;
      }
      valid_len += veal->num_elements *
                   sizeof(struct virtchnl_ether_addr);
    }
    break;
  case VIRTCHNL_OP_ADD_VLAN:
  case VIRTCHNL_OP_DEL_VLAN:
    valid_len = sizeof(struct virtchnl_vlan_filter_list);
    if (msglen >= valid_len)
    {
      struct virtchnl_vlan_filter_list *vfl =
          (struct virtchnl_vlan_filter_list *)msg;
      if (vfl->num_elements == 0 || vfl->num_elements >
                                        VIRTCHNL_OP_ADD_DEL_VLAN_MAX)
      {
        err_msg_format = 1;
        break;
      }
      valid_len += vfl->num_elements * sizeof(u16);
    }
    break;
  case VIRTCHNL_OP_CONFIG_PROMISCUOUS_MODE:
    valid_len = sizeof(struct virtchnl_promisc_info);
    break;
  case VIRTCHNL_OP_GET_STATS:
    valid_len = sizeof(struct virtchnl_queue_select);
    break;
  case VIRTCHNL_OP_CONFIG_RSS_KEY:
    valid_len = sizeof(struct virtchnl_rss_key);
    if (msglen >= valid_len)
    {
      struct virtchnl_rss_key *vrk = (struct virtchnl_rss_key *)msg;
      if (vrk->key_len == 0)
      {
        break;
      }
      valid_len += vrk->key_len - 1;
    }
    break;
  case VIRTCHNL_OP_CONFIG_RSS_LUT:
    valid_len = sizeof(struct virtchnl_rss_lut);
    if (msglen >= valid_len)
    {
      struct virtchnl_rss_lut *vrl = (struct virtchnl_rss_lut *)msg;
      if (vrl->lut_entries == 0)
      {
        break;
      }
      valid_len += vrl->lut_entries - 1;
    }
    break;
  case VIRTCHNL_OP_GET_RSS_HENA_CAPS:
    break;
  case VIRTCHNL_OP_SET_RSS_HENA:
    valid_len = sizeof(struct virtchnl_rss_hena);
    break;
  case VIRTCHNL_OP_ENABLE_VLAN_STRIPPING:
  case VIRTCHNL_OP_DISABLE_VLAN_STRIPPING:
    break;
  case VIRTCHNL_OP_REQUEST_QUEUES:
    valid_len = sizeof(struct virtchnl_vf_res_request);
    break;
  case VIRTCHNL_OP_ENABLE_CHANNELS:
    valid_len = sizeof(struct virtchnl_tc_info);
    if (msglen >= valid_len)
    {
      struct virtchnl_tc_info *vti = (struct virtchnl_tc_info *)msg;
      if (vti->num_tc == 0 || vti->num_tc >
                                  VIRTCHNL_OP_ENABLE_CHANNELS_MAX)
      {
        err_msg_format = 1;
        break;
      }
      valid_len += (vti->num_tc - 1) *
                   sizeof(struct virtchnl_channel_info);
    }
    break;
  case VIRTCHNL_OP_DISABLE_CHANNELS:
    break;
  case VIRTCHNL_OP_ADD_CLOUD_FILTER:
  case VIRTCHNL_OP_DEL_CLOUD_FILTER:
    valid_len = sizeof(struct virtchnl_filter);
    break;
  case VIRTCHNL_OP_DCF_VLAN_OFFLOAD:
    valid_len = sizeof(struct virtchnl_dcf_vlan_offload);
    break;
  case VIRTCHNL_OP_DCF_CMD_DESC:
  case VIRTCHNL_OP_DCF_CMD_BUFF:
    valid_len = msglen;
    break;
  case VIRTCHNL_OP_DCF_DISABLE:
  case VIRTCHNL_OP_DCF_GET_VSI_MAP:
  case VIRTCHNL_OP_DCF_GET_PKG_INFO:
    break;
  case VIRTCHNL_OP_DCF_CONFIG_BW:
    valid_len = sizeof(struct virtchnl_dcf_bw_cfg_list);
    if (msglen >= valid_len)
    {
      struct virtchnl_dcf_bw_cfg_list *cfg_list =
          (struct virtchnl_dcf_bw_cfg_list *)msg;
      if (cfg_list->num_elem == 0)
      {
        err_msg_format = 1;
        break;
      }
      valid_len += (cfg_list->num_elem - 1) *
                   sizeof(struct virtchnl_dcf_bw_cfg);
    }
    break;
  case VIRTCHNL_OP_GET_SUPPORTED_RXDIDS:
    break;
  case VIRTCHNL_OP_ADD_RSS_CFG:
  case VIRTCHNL_OP_DEL_RSS_CFG:
    valid_len = sizeof(struct virtchnl_rss_cfg);
    break;
  case VIRTCHNL_OP_ADD_FDIR_FILTER:
    valid_len = sizeof(struct virtchnl_fdir_add);
    break;
  case VIRTCHNL_OP_DEL_FDIR_FILTER:
    valid_len = sizeof(struct virtchnl_fdir_del);
    break;
  case VIRTCHNL_OP_FLOW_SUBSCRIBE:
    valid_len = sizeof(struct virtchnl_flow_sub);
    break;
  case VIRTCHNL_OP_FLOW_UNSUBSCRIBE:
    valid_len = sizeof(struct virtchnl_flow_unsub);
    break;
  case VIRTCHNL_OP_GET_QOS_CAPS:
    break;
  case VIRTCHNL_OP_CONFIG_QUEUE_TC_MAP:
    valid_len = sizeof(struct virtchnl_queue_tc_mapping);
    if (msglen >= valid_len)
    {
      struct virtchnl_queue_tc_mapping *q_tc =
          (struct virtchnl_queue_tc_mapping *)msg;
      if (q_tc->num_tc == 0)
      {
        err_msg_format = 1;
        break;
      }
      valid_len += (q_tc->num_tc - 1) * sizeof(q_tc->tc[0]);
    }
    break;
  case VIRTCHNL_OP_CONFIG_QUEUE_BW:
    valid_len = sizeof(struct virtchnl_queues_bw_cfg);
    if (msglen >= valid_len)
    {
      struct virtchnl_queues_bw_cfg *q_bw =
          (struct virtchnl_queues_bw_cfg *)msg;
      if (q_bw->num_queues == 0)
      {
        err_msg_format = 1;
        break;
      }
      valid_len += (q_bw->num_queues - 1) * sizeof(q_bw->cfg[0]);
    }
    break;
  case VIRTCHNL_OP_CONFIG_QUANTA:
    valid_len = sizeof(struct virtchnl_quanta_cfg);
    if (msglen >= valid_len)
    {
      struct virtchnl_quanta_cfg *q_quanta =
          (struct virtchnl_quanta_cfg *)msg;
      if (q_quanta->quanta_size == 0 ||
          q_quanta->queue_select.num_queues == 0)
      {
        err_msg_format = 1;
        break;
      }
    }
    break;
  case VIRTCHNL_OP_GET_OFFLOAD_VLAN_V2_CAPS:
    break;
  case VIRTCHNL_OP_ADD_VLAN_V2:
  case VIRTCHNL_OP_DEL_VLAN_V2:
    valid_len = sizeof(struct virtchnl_vlan_filter_list_v2);
    if (msglen >= valid_len)
    {
      struct virtchnl_vlan_filter_list_v2 *vfl =
          (struct virtchnl_vlan_filter_list_v2 *)msg;
      if (vfl->num_elements == 0 || vfl->num_elements >
                                        VIRTCHNL_OP_ADD_DEL_VLAN_V2_MAX)
      {
        err_msg_format = 1;
        break;
      }
      valid_len += (vfl->num_elements - 1) *
                   sizeof(struct virtchnl_vlan_filter);
    }
    break;
  case VIRTCHNL_OP_ENABLE_VLAN_STRIPPING_V2:
  case VIRTCHNL_OP_DISABLE_VLAN_STRIPPING_V2:
  case VIRTCHNL_OP_ENABLE_VLAN_INSERTION_V2:
  case VIRTCHNL_OP_DISABLE_VLAN_INSERTION_V2:
  case VIRTCHNL_OP_ENABLE_VLAN_FILTERING_V2:
  case VIRTCHNL_OP_DISABLE_VLAN_FILTERING_V2:
    valid_len = sizeof(struct virtchnl_vlan_setting);
    break;
  case VIRTCHNL_OP_1588_PTP_GET_CAPS:
    valid_len = sizeof(struct virtchnl_ptp_caps);
    break;
  case VIRTCHNL_OP_1588_PTP_GET_TIME:
    valid_len = sizeof(struct virtchnl_phc_time);
    break;
  case VIRTCHNL_OP_ENABLE_QUEUES_V2:
  case VIRTCHNL_OP_DISABLE_QUEUES_V2:
    valid_len = sizeof(struct virtchnl_del_ena_dis_queues);
    if (msglen >= valid_len)
    {
      struct virtchnl_del_ena_dis_queues *qs =
          (struct virtchnl_del_ena_dis_queues *)msg;
      if (qs->chunks.num_chunks == 0 ||
          qs->chunks.num_chunks >
              VIRTCHNL_OP_ENABLE_DISABLE_DEL_QUEUES_V2_MAX)
      {
        err_msg_format = 1;
        break;
      }
      valid_len += (qs->chunks.num_chunks - 1) *
                   sizeof(struct virtchnl_queue_chunk);
    }
    break;
  case VIRTCHNL_OP_MAP_QUEUE_VECTOR:
    valid_len = sizeof(struct virtchnl_queue_vector_maps);
    if (msglen >= valid_len)
    {
      struct virtchnl_queue_vector_maps *v_qp =
          (struct virtchnl_queue_vector_maps *)msg;
      if (v_qp->num_qv_maps == 0 ||
          v_qp->num_qv_maps > VIRTCHNL_OP_MAP_UNMAP_QUEUE_VECTOR_MAX)
      {
        err_msg_format = 1;
        break;
      }
      valid_len += (v_qp->num_qv_maps - 1) *
                   sizeof(struct virtchnl_queue_vector);
    }
    break;
  case VIRTCHNL_OP_INLINE_IPSEC_CRYPTO:
  {
    struct inline_ipsec_msg *iim = (struct inline_ipsec_msg *)msg;
    valid_len = virtchnl_inline_ipsec_val_msg_len(iim->ipsec_opcode);
    break;
  }
  case VIRTCHNL_OP_EVENT:
  case VIRTCHNL_OP_UNKNOWN:
  default:
    return VIRTCHNL_STATUS_ERR_PARAM;
  }
  if (err_msg_format || valid_len != msglen)
    return VIRTCHNL_STATUS_ERR_OPCODE_MISMATCH;
  return 0;
}

__attribute__((section(".text.internal"))) enum iavf_status iavf_init_adminq(struct iavf_hw *hw);
__attribute__((section(".text.internal"))) enum iavf_status iavf_shutdown_adminq(struct iavf_hw *hw);
enum iavf_status iavf_init_asq(struct iavf_hw *hw);
enum iavf_status iavf_init_arq(struct iavf_hw *hw);
enum iavf_status iavf_alloc_adminq_asq_ring(struct iavf_hw *hw);
enum iavf_status iavf_alloc_adminq_arq_ring(struct iavf_hw *hw);
enum iavf_status iavf_shutdown_asq(struct iavf_hw *hw);
enum iavf_status iavf_shutdown_arq(struct iavf_hw *hw);
u16 iavf_clean_asq(struct iavf_hw *hw);
void iavf_free_adminq_asq(struct iavf_hw *hw);
void iavf_free_adminq_arq(struct iavf_hw *hw);
enum iavf_status iavf_validate_mac_addr(u8 *mac_addr);
void iavf_adminq_init_ring_data(struct iavf_hw *hw);
__attribute__((section(".text.internal"))) enum iavf_status iavf_clean_arq_element(struct iavf_hw *hw,
                                                                                   struct iavf_arq_event_info *e,
                                                                                   u16 *events_pending);
enum iavf_status iavf_asq_send_command(struct iavf_hw *hw,
                                       struct iavf_aq_desc *desc,
                                       void *buff,
                                       u16 buff_size,
                                       struct iavf_asq_cmd_details
                                           *cmd_details);
_Bool iavf_asq_done(struct iavf_hw *hw);
void iavf_debug_aq(struct iavf_hw *hw, enum iavf_debug_mask mask,
                   void *desc, void *buffer, u16 buf_len);
void iavf_idle_aq(struct iavf_hw *hw);
_Bool iavf_check_asq_alive(struct iavf_hw *hw);
enum iavf_status iavf_aq_queue_shutdown(struct iavf_hw *hw,
                                        _Bool unloading);
enum iavf_status iavf_aq_get_rss_lut(struct iavf_hw *hw, u16 seid,
                                     _Bool
                                         pf_lut,
                                     u8 *lut, u16 lut_size);
enum iavf_status iavf_aq_set_rss_lut(struct iavf_hw *hw, u16 seid,
                                     _Bool
                                         pf_lut,
                                     u8 *lut, u16 lut_size);
enum iavf_status iavf_aq_get_rss_key(struct iavf_hw *hw,
                                     u16 seid,
                                     struct
                                     iavf_aqc_get_set_rss_key_data
                                         *key);
enum iavf_status iavf_aq_set_rss_key(struct iavf_hw *hw, u16 seid,
                                     struct
                                     iavf_aqc_get_set_rss_key_data
                                         *key);
const char *iavf_aq_str(struct iavf_hw *hw,
                        enum iavf_admin_queue_err aq_err);
const char *iavf_stat_str(struct iavf_hw *hw,
                          enum iavf_status stat_err);
__attribute__((section(".text.internal"))) enum iavf_status iavf_set_mac_type(struct iavf_hw *hw);
extern struct iavf_rx_ptype_decoded iavf_ptype_lookup[];
static inline struct iavf_rx_ptype_decoded decode_rx_desc_ptype(u8
                                                                    ptype)
{
  return iavf_ptype_lookup[ptype];
}

__attribute__((section(".text.internal"))) void iavf_vf_parse_hw_config(struct iavf_hw *hw,
                                                                        struct virtchnl_vf_resource *msg);
enum iavf_status iavf_vf_reset(struct iavf_hw *hw);
__attribute__((section(".text.internal"))) enum iavf_status iavf_aq_send_msg_to_pf(struct iavf_hw *hw,
                                                                                   enum virtchnl_ops v_opcode,
                                                                                   enum iavf_status v_retval,
                                                                                   u8 *msg, u16 msglen,
                                                                                   struct iavf_asq_cmd_details
                                                                                       *cmd_details);
enum iavf_status iavf_aq_debug_dump(struct iavf_hw *hw, u8 cluster_id,
                                    u8 table_id, u32 start_index,
                                    u16 buff_size, void *buff,
                                    u16 *ret_buff_size,
                                    u8 *ret_next_table,
                                    u32 *ret_next_index,
                                    struct iavf_asq_cmd_details
                                        *cmd_details);
enum iavf_status iavf_aq_clear_all_wol_filters(struct iavf_hw *hw,
                                               struct
                                               iavf_asq_cmd_details
                                                   *cmd_details);
extern int iavf_logtype_init;
extern int iavf_logtype_driver;
struct iavf_adapter;
struct iavf_rx_queue;
struct iavf_tx_queue;
struct iavf_ipsec_crypto_stats
{
  uint64_t icount;
  uint64_t ibytes;
  struct
  {
    uint64_t count;
    uint64_t sad_miss;
    uint64_t not_processed;
    uint64_t icv_check;
    uint64_t ipsec_length;
    uint64_t misc;
  } ierrors;
};
struct iavf_mbuf_stats
{
  uint64_t tx_pkt_errors;
};
struct iavf_eth_xstats
{
  struct virtchnl_eth_stats eth_stats;
  struct iavf_ipsec_crypto_stats ips_stats;
  struct iavf_mbuf_stats mbuf_stats;
};
struct iavf_vsi
{
  struct iavf_adapter *adapter;
  uint16_t vsi_id;
  uint16_t nb_qps;
  uint16_t nb_used_qps;
  uint16_t max_macaddrs;
  uint16_t base_vector;
  uint16_t msix_intr;
  struct iavf_eth_xstats eth_stats_offset;
};
struct rte_flow;
struct iavf_flow_list
{
  struct rte_flow *tqh_first;
  struct rte_flow **tqh_last;
};
struct iavf_flow_parser_node;
struct iavf_parser_list
{
  struct iavf_flow_parser_node *tqh_first;
  struct iavf_flow_parser_node **tqh_last;
};
struct iavf_fdir_conf
{
  struct virtchnl_fdir_add add_fltr;
  struct virtchnl_fdir_del del_fltr;
  uint64_t input_set;
  uint32_t flow_id;
  uint32_t mark_flag;
};
struct iavf_fdir_info
{
  struct iavf_fdir_conf conf;
};
struct iavf_fsub_conf
{
  struct virtchnl_flow_sub sub_fltr;
  struct virtchnl_flow_unsub unsub_fltr;
  uint64_t input_set;
  uint32_t flow_id;
};
struct iavf_qv_map
{
  uint16_t queue_id;
  uint16_t vector_id;
};
enum iavf_aq_result
{
  IAVF_MSG_ERR = -1,
  IAVF_MSG_NON,
  IAVF_MSG_SYS,
  IAVF_MSG_CMD,
};
struct iavf_tm_node
{
  struct
  {
    struct iavf_tm_node *tqe_next;
    struct iavf_tm_node **tqe_prev;
  } node;
  uint32_t id;
  uint32_t tc;
  uint32_t priority;
  uint32_t weight;
  uint32_t reference_count;
  struct iavf_tm_node *parent;
  struct iavf_tm_shaper_profile *shaper_profile;
  struct rte_tm_node_params params;
};
struct iavf_tm_node_list
{
  struct iavf_tm_node *tqh_first;
  struct iavf_tm_node **tqh_last;
};
struct iavf_tm_shaper_profile
{
  struct
  {
    struct iavf_tm_shaper_profile *tqe_next;
    struct iavf_tm_shaper_profile **tqe_prev;
  } node;
  uint32_t shaper_profile_id;
  uint32_t reference_count;
  struct rte_tm_shaper_params profile;
};
struct iavf_shaper_profile_list
{
  struct iavf_tm_shaper_profile *tqh_first;
  struct iavf_tm_shaper_profile **tqh_last;
};
enum iavf_tm_node_type
{
  IAVF_TM_NODE_TYPE_PORT,
  IAVF_TM_NODE_TYPE_TC,
  IAVF_TM_NODE_TYPE_QUEUE,
  IAVF_TM_NODE_TYPE_MAX,
};
struct iavf_tm_conf
{
  struct iavf_tm_node *root;
  struct iavf_tm_node_list tc_list;
  struct iavf_tm_node_list queue_list;
  struct iavf_shaper_profile_list shaper_profile_list;
  uint32_t nb_tc_node;
  uint32_t nb_queue_node;
  _Bool committed;
};
struct iavf_qtc_map
{
  uint8_t tc;
  uint16_t start_queue_id;
  uint16_t queue_count;
};
struct iavf_info
{
  uint16_t num_queue_pairs;
  uint16_t max_pkt_len;
  uint16_t mac_num;
  _Bool promisc_unicast_enabled;
  _Bool promisc_multicast_enabled;
  struct virtchnl_version_info virtchnl_version;
  struct virtchnl_vf_resource *vf_res;
  struct virtchnl_vsi_resource *vsi_res;
  struct virtchnl_vlan_caps vlan_v2_caps;
  uint64_t supported_rxdid;
  uint8_t *proto_xtr;
  volatile enum virtchnl_ops pend_cmd;
  uint32_t pend_cmd_count;
  int cmd_retval;
  uint8_t *aq_resp;
  _Bool watchdog_enabled;
  _Bool dev_closed;
  _Bool link_up;
  uint32_t link_speed;
  struct rte_ether_addr mc_addrs[64];
  uint16_t mc_addrs_num;
  struct iavf_vsi vsi;
  _Bool vf_reset;
  uint64_t flags;
  uint8_t *rss_lut;
  uint8_t *rss_key;
  uint64_t rss_hf;
  uint16_t nb_msix;
  uint16_t msix_base;
  uint16_t max_rss_qregion;
  struct iavf_qv_map *qv_map;
  struct iavf_flow_list flow_list;
  rte_spinlock_t flow_ops_lock;
  rte_spinlock_t aq_lock;
  struct iavf_parser_list rss_parser_list;
  struct iavf_parser_list dist_parser_list;
  struct iavf_parser_list ipsec_crypto_parser_list;
  struct iavf_fdir_info fdir;
  _Bool lv_enabled;
  struct virtchnl_qos_cap_list *qos_cap;
  struct iavf_qtc_map *qtc_map;
  struct iavf_tm_conf tm_conf;
  struct rte_eth_dev *eth_dev;
  _Bool in_reset_recovery;
  uint32_t ptp_caps;
  rte_spinlock_t phc_time_aq_lock;
};
enum iavf_proto_xtr_type
{
  IAVF_PROTO_XTR_NONE,
  IAVF_PROTO_XTR_VLAN,
  IAVF_PROTO_XTR_IPV4,
  IAVF_PROTO_XTR_IPV6,
  IAVF_PROTO_XTR_IPV6_FLOW,
  IAVF_PROTO_XTR_TCP,
  IAVF_PROTO_XTR_IP_OFFSET,
  IAVF_PROTO_XTR_IPSEC_CRYPTO_SAID,
  IAVF_PROTO_XTR_MAX,
};
struct iavf_devargs
{
  uint8_t proto_xtr_dflt;
  uint8_t proto_xtr[2048];
  uint16_t quanta_size;
  uint32_t watchdog_period;
  int auto_reset;
  int no_poll_on_link_down;
  uint64_t mbuf_check;
};
struct iavf_security_ctx;
enum iavf_rx_burst_type
{
  IAVF_RX_DEFAULT,
  IAVF_RX_FLEX_RXD,
  IAVF_RX_BULK_ALLOC,
  IAVF_RX_SCATTERED,
  IAVF_RX_SCATTERED_FLEX_RXD,
  IAVF_RX_SSE,
  IAVF_RX_AVX2,
  IAVF_RX_AVX2_OFFLOAD,
  IAVF_RX_SSE_FLEX_RXD,
  IAVF_RX_AVX2_FLEX_RXD,
  IAVF_RX_AVX2_FLEX_RXD_OFFLOAD,
  IAVF_RX_SSE_SCATTERED,
  IAVF_RX_AVX2_SCATTERED,
  IAVF_RX_AVX2_SCATTERED_OFFLOAD,
  IAVF_RX_SSE_SCATTERED_FLEX_RXD,
  IAVF_RX_AVX2_SCATTERED_FLEX_RXD,
  IAVF_RX_AVX2_SCATTERED_FLEX_RXD_OFFLOAD,
  IAVF_RX_AVX512,
  IAVF_RX_AVX512_OFFLOAD,
  IAVF_RX_AVX512_FLEX_RXD,
  IAVF_RX_AVX512_FLEX_RXD_OFFLOAD,
  IAVF_RX_AVX512_SCATTERED,
  IAVF_RX_AVX512_SCATTERED_OFFLOAD,
  IAVF_RX_AVX512_SCATTERED_FLEX_RXD,
  IAVF_RX_AVX512_SCATTERED_FLEX_RXD_OFFLOAD,
};
enum iavf_tx_burst_type
{
  IAVF_TX_DEFAULT,
  IAVF_TX_SSE,
  IAVF_TX_AVX2,
  IAVF_TX_AVX2_OFFLOAD,
  IAVF_TX_AVX512,
  IAVF_TX_AVX512_OFFLOAD,
  IAVF_TX_AVX512_CTX,
  IAVF_TX_AVX512_CTX_OFFLOAD,
};
struct iavf_adapter
{
  struct iavf_hw hw;
  struct rte_eth_dev_data *dev_data;
  struct iavf_info vf;
  struct iavf_security_ctx *security_ctx;
  _Bool rx_bulk_alloc_allowed;
  _Bool rx_vec_allowed;
  _Bool tx_vec_allowed;
  _Alignas(64) uint32_t ptype_tbl[1024];
  _Bool stopped;
  _Bool closed;
  _Bool no_poll;
  enum iavf_rx_burst_type rx_burst_type;
  enum iavf_tx_burst_type tx_burst_type;
  uint16_t fdir_ref_cnt;
  struct iavf_devargs devargs;
};
static inline void iavf_init_adminq_parameter(struct iavf_hw *hw)
{
  hw->aq.num_arq_entries = 32;
  hw->aq.num_asq_entries = 32;
  hw->aq.arq_buf_size = 4096;
  hw->aq.asq_buf_size = 4096;
}

static inline uint16_t
iavf_calc_itr_interval(int16_t interval)
{
  if (interval < 0 || interval > 8160)
    interval = 32;
  return interval / 2;
}

struct iavf_cmd_info
{
  enum virtchnl_ops ops;
  uint8_t *in_args;
  uint32_t in_args_size;
  uint8_t *out_buffer;
  uint32_t out_size;
};
static inline void
_notify_cmd(struct iavf_info *vf, int msg_ret)
{
  vf->cmd_retval = msg_ret;
  __asm__ volatile("fence w, w" ::: "memory");
  vf->pend_cmd = VIRTCHNL_OP_UNKNOWN;
}

static inline void
_clear_cmd(struct iavf_info *vf)
{
  __asm__ volatile("fence w, w" ::: "memory");
  vf->pend_cmd = VIRTCHNL_OP_UNKNOWN;
  vf->cmd_retval = VIRTCHNL_STATUS_SUCCESS;
}

static inline int
_atomic_set_cmd(struct iavf_info *vf, enum virtchnl_ops ops)
{
  enum virtchnl_ops op_unk = VIRTCHNL_OP_UNKNOWN;
  int ret =
      __atomic_compare_exchange_n(&vf->pend_cmd, &op_unk, ops, 0, 2, 2);
  if (!ret)
    rte_log(4U, iavf_logtype_driver,
            "%s(): "
            "There is incomplete cmd %d"
            "\n",
            __func__,
            vf->pend_cmd);
  __atomic_store_n(&vf->pend_cmd_count, 1, 0);
  return !ret;
}

static inline int
_atomic_set_async_response_cmd(struct iavf_info *vf, enum virtchnl_ops ops)
{
  enum virtchnl_ops op_unk = VIRTCHNL_OP_UNKNOWN;
  int ret =
      __atomic_compare_exchange_n(&vf->pend_cmd, &op_unk, ops, 0, 2, 2);
  if (!ret)
    rte_log(4U, iavf_logtype_driver,
            "%s(): "
            "There is incomplete cmd %d"
            "\n",
            __func__,
            vf->pend_cmd);
  __atomic_store_n(&vf->pend_cmd_count, 2, 0);
  return !ret;
}

int iavf_check_api_version(struct iavf_adapter *adapter);
int iavf_get_vf_resource(struct iavf_adapter *adapter);
void iavf_dev_event_post(struct rte_eth_dev *dev,
                         enum rte_eth_event_type event,
                         void *param, size_t param_alloc_size);
void iavf_dev_event_handler_fini(void);
int iavf_dev_event_handler_init(void);
void iavf_handle_virtchnl_msg(struct rte_eth_dev *dev);
int iavf_enable_vlan_strip(struct iavf_adapter *adapter);
int iavf_disable_vlan_strip(struct iavf_adapter *adapter);
int iavf_switch_queue(struct iavf_adapter *adapter, uint16_t qid,
                      _Bool rx, _Bool on);
int iavf_switch_queue_lv(struct iavf_adapter *adapter, uint16_t qid,
                         _Bool rx, _Bool on);
int iavf_enable_queues(struct iavf_adapter *adapter);
int iavf_enable_queues_lv(struct iavf_adapter *adapter);
int iavf_disable_queues(struct iavf_adapter *adapter);
int iavf_disable_queues_lv(struct iavf_adapter *adapter);
int iavf_configure_rss_lut(struct iavf_adapter *adapter);
int iavf_configure_rss_key(struct iavf_adapter *adapter);
int iavf_configure_queues(struct iavf_adapter *adapter,
                          uint16_t num_queue_pairs, uint16_t index);
int iavf_get_supported_rxdid(struct iavf_adapter *adapter);
int iavf_config_vlan_strip_v2(struct iavf_adapter *adapter, _Bool enable);
int iavf_config_vlan_insert_v2(struct iavf_adapter *adapter, _Bool enable);
int iavf_add_del_vlan_v2(struct iavf_adapter *adapter, uint16_t vlanid,
                         _Bool add);
int iavf_get_vlan_offload_caps_v2(struct iavf_adapter *adapter);
int iavf_config_irq_map(struct iavf_adapter *adapter);
int iavf_config_irq_map_lv(struct iavf_adapter *adapter, uint16_t num,
                           uint16_t index);
void iavf_add_del_all_mac_addr(struct iavf_adapter *adapter, _Bool add);
int iavf_dev_link_update(struct rte_eth_dev *dev, __attribute__((__unused__)) int wait_to_complete);
void iavf_dev_alarm_handler(void *param);
int iavf_query_stats(struct iavf_adapter *adapter,
                     struct virtchnl_eth_stats **pstats);
int iavf_config_promisc(struct iavf_adapter *adapter,
                        _Bool enable_unicast, _Bool enable_multicast);
int iavf_add_del_eth_addr(struct iavf_adapter *adapter,
                          struct rte_ether_addr *addr,
                          _Bool add, uint8_t type);
int iavf_add_del_vlan(struct iavf_adapter *adapter, uint16_t vlanid,
                      _Bool add);
int iavf_fdir_add(struct iavf_adapter *adapter,
                  struct iavf_fdir_conf *filter);
int iavf_fdir_del(struct iavf_adapter *adapter,
                  struct iavf_fdir_conf *filter);
int iavf_fdir_check(struct iavf_adapter *adapter,
                    struct iavf_fdir_conf *filter);
int iavf_add_del_rss_cfg(struct iavf_adapter *adapter,
                         struct virtchnl_rss_cfg *rss_cfg, _Bool add);
int iavf_get_hena_caps(struct iavf_adapter *adapter, uint64_t *caps);
int iavf_set_hena(struct iavf_adapter *adapter, uint64_t hena);
int iavf_rss_hash_set(struct iavf_adapter *ad, uint64_t rss_hf, _Bool add);
int iavf_add_del_mc_addr_list(struct iavf_adapter *adapter,
                              struct rte_ether_addr *mc_addrs,
                              uint32_t mc_addrs_num, _Bool add);
int iavf_request_queues(struct rte_eth_dev *dev, uint16_t num);
int iavf_get_max_rss_queue_region(struct iavf_adapter *adapter);
int iavf_get_qos_cap(struct iavf_adapter *adapter);
int iavf_set_q_bw(struct rte_eth_dev *dev,
                  struct virtchnl_queues_bw_cfg *q_bw, uint16_t size);
int iavf_set_q_tc_map(struct rte_eth_dev *dev,
                      struct virtchnl_queue_tc_mapping *q_tc_mapping,
                      uint16_t size);
int iavf_set_vf_quanta_size(struct iavf_adapter *adapter,
                            u16 start_queue_id, u16 num_queues);
void iavf_tm_conf_init(struct rte_eth_dev *dev);
void iavf_tm_conf_uninit(struct rte_eth_dev *dev);
int iavf_ipsec_crypto_request(struct iavf_adapter *adapter,
                              uint8_t *msg, size_t msg_len,
                              uint8_t *resp_msg, size_t resp_msg_len);
extern const struct rte_tm_ops
    iavf_tm_ops;
int iavf_get_ptp_cap(struct iavf_adapter *adapter);
int iavf_get_phc_time(struct iavf_rx_queue *rxq);
int iavf_flow_sub(struct iavf_adapter *adapter,
                  struct iavf_fsub_conf *filter);
int iavf_flow_unsub(struct iavf_adapter *adapter,
                    struct iavf_fsub_conf *filter);
int iavf_flow_sub_check(struct iavf_adapter *adapter,
                        struct iavf_fsub_conf *filter);
void iavf_dev_watchdog_enable(struct iavf_adapter *adapter);
void iavf_dev_watchdog_disable(struct iavf_adapter *adapter);
void iavf_handle_hw_reset(struct rte_eth_dev *dev);
void iavf_set_no_poll(struct iavf_adapter *adapter, _Bool link_change);
extern uint64_t
    iavf_timestamp_dynflag;
extern int
    iavf_timestamp_dynfield_offset;
extern int
    rte_pmd_iavf_tx_lldp_dynfield_offset;
union iavf_16b_rx_flex_desc
{
  struct
  {
    uint64_t
        pkt_addr;
    uint64_t
        hdr_addr;
  } read;
  struct
  {
    u8
        rxdid;
    u8
        mir_id_umb_cast;
    uint16_t
        ptype_flex_flags0;
    uint16_t
        pkt_len;
    uint16_t
        hdr_len_sph_flex_flags1;
    uint16_t
        status_error0;
    uint16_t
        l2tag1;
    uint16_t
        flex_meta0;
    uint16_t
        flex_meta1;
  } wb;
};
union iavf_32b_rx_flex_desc
{
  struct
  {
    uint64_t
        pkt_addr;
    uint64_t
        hdr_addr;
    uint64_t
        rsvd1;
    uint64_t
        rsvd2;
  } read;
  struct
  {
    u8
        rxdid;
    u8
        mir_id_umb_cast;
    uint16_t
        ptype_flex_flags0;
    uint16_t
        pkt_len;
    uint16_t
        hdr_len_sph_flex_flags1;
    uint16_t
        status_error0;
    uint16_t
        l2tag1;
    uint16_t
        flex_meta0;
    uint16_t
        flex_meta1;
    uint16_t
        status_error1;
    u8
        flex_flags2;
    u8
        time_stamp_low;
    uint16_t
        l2tag2_1st;
    uint16_t
        l2tag2_2nd;
    uint16_t
        flex_meta2;
    uint16_t
        flex_meta3;
    union
    {
      struct
      {
        uint16_t
            flex_meta4;
        uint16_t
            flex_meta5;
      } flex;
      uint32_t
          ts_high;
    } flex_ts;
  } wb;
};
typedef void (*iavf_rxd_to_pkt_fields_t)(struct iavf_rx_queue *rxq,
                                         struct rte_mbuf *mb,
                                         volatile union iavf_32b_rx_flex_desc *rxdp);
struct iavf_rxq_ops
{
  void (*release_mbufs)(struct iavf_rx_queue *rxq);
};
struct iavf_txq_ops
{
  void (*release_mbufs)(struct iavf_tx_queue *txq);
};
struct iavf_rx_queue_stats
{
  uint64_t
      reserved;
  struct iavf_ipsec_crypto_stats
      ipsec_crypto;
};
struct iavf_rx_queue
{
  struct rte_mempool *
      mp;
  const struct rte_memzone *
      mz;
  volatile union iavf_32byte_rx_desc *
      rx_ring;
  uint64_t
      rx_ring_phys_addr;
  struct rte_mbuf **
      sw_ring;
  uint16_t
      nb_rx_desc;
  uint16_t
      rx_tail;
  volatile uint8_t *
      qrx_tail;
  uint16_t
      rx_free_thresh;
  uint16_t
      nb_rx_hold;
  struct rte_mbuf *
      pkt_first_seg;
  struct rte_mbuf *
      pkt_last_seg;
  struct rte_mbuf
      fake_mbuf;
  uint8_t
      rxdid;
  uint8_t
      rel_mbufs_type;
  uint16_t
      rxrearm_nb;
  uint16_t
      rxrearm_start;
  uint64_t
      mbuf_initializer;
  uint16_t
      rx_nb_avail;
  uint16_t
      rx_next_avail;
  uint16_t
      rx_free_trigger;
  struct rte_mbuf *
      rx_stage[32 * 2];
  uint16_t
      port_id;
  uint8_t
      crc_len;
  uint8_t
      fdir_enabled;
  uint16_t
      queue_id;
  uint16_t
      rx_buf_len;
  uint16_t
      rx_hdr_len;
  uint16_t
      max_pkt_len;
  struct iavf_vsi *
      vsi;
  _Bool
      q_set;
  _Bool
      rx_deferred_start;
  const struct iavf_rxq_ops *
      ops;
  uint8_t
      rx_flags;
  uint8_t
      proto_xtr;
  uint64_t
      xtr_ol_flag;
  struct iavf_rx_queue_stats
      stats;
  uint64_t
      offloads;
  uint64_t
      phc_time;
  uint64_t
      hw_time_update;
};
struct iavf_tx_entry
{
  struct rte_mbuf *
      mbuf;
  uint16_t
      next_id;
  uint16_t
      last_id;
};
struct iavf_tx_vec_entry
{
  struct rte_mbuf *
      mbuf;
};
struct iavf_tx_queue
{
  const struct rte_memzone *
      mz;
  volatile struct iavf_tx_desc *
      tx_ring;
  uint64_t
      tx_ring_phys_addr;
  struct iavf_tx_entry *
      sw_ring;
  uint16_t
      nb_tx_desc;
  uint16_t
      tx_tail;
  volatile uint8_t *
      qtx_tail;
  uint16_t
      nb_used;
  uint16_t
      nb_free;
  uint16_t
      last_desc_cleaned;
  uint16_t
      free_thresh;
  uint16_t
      rs_thresh;
  uint8_t
      rel_mbufs_type;
  struct iavf_vsi *
      vsi;
  uint16_t
      port_id;
  uint16_t
      queue_id;
  uint64_t
      offloads;
  uint16_t
      next_dd;
  uint16_t
      next_rs;
  uint16_t
      ipsec_crypto_pkt_md_offset;
  uint64_t
      mbuf_errors;
  _Bool
      q_set;
  _Bool
      tx_deferred_start;
  const struct iavf_txq_ops *
      ops;
  uint8_t
      vlan_flag;
  uint8_t
      tc;
  uint8_t
      use_ctx : 1;
};
union iavf_tx_offload
{
  uint64_t
      data;
  struct
  {
    uint64_t
        l2_len : 7;
    uint64_t
        l3_len : 9;
    uint64_t
        l4_len : 8;
    uint64_t
        tso_segsz : 16;
  };
};
struct iavf_32b_rx_flex_desc_comms
{
  u8
      rxdid;
  u8
      mir_id_umb_cast;
  uint16_t
      ptype_flexi_flags0;
  uint16_t
      pkt_len;
  uint16_t
      hdr_len_sph_flex_flags1;
  uint16_t
      status_error0;
  uint16_t
      l2tag1;
  uint32_t
      rss_hash;
  uint16_t
      status_error1;
  u8
      flexi_flags2;
  u8
      ts_low;
  uint16_t
      l2tag2_1st;
  uint16_t
      l2tag2_2nd;
  uint32_t
      flow_id;
  union
  {
    struct
    {
      uint16_t
          aux0;
      uint16_t
          aux1;
    } flex;
    uint32_t
        ts_high;
  } flex_ts;
};
struct iavf_32b_rx_flex_desc_comms_ovs
{
  u8
      rxdid;
  u8
      mir_id_umb_cast;
  uint16_t
      ptype_flexi_flags0;
  uint16_t
      pkt_len;
  uint16_t
      hdr_len_sph_flex_flags1;
  uint16_t
      status_error0;
  uint16_t
      l2tag1;
  uint32_t
      flow_id;
  uint16_t
      status_error1;
  u8
      flexi_flags2;
  u8
      ts_low;
  uint16_t
      l2tag2_1st;
  uint16_t
      l2tag2_2nd;
  uint32_t
      rss_hash;
  union
  {
    struct
    {
      uint16_t
          aux0;
      uint16_t
          aux1;
    } flex;
    uint32_t
        ts_high;
  } flex_ts;
};
struct iavf_32b_rx_flex_desc_comms_ipsec
{
  u8
      rxdid;
  u8
      mir_id_umb_cast;
  uint16_t
      ptype_flexi_flags0;
  uint16_t
      pkt_len;
  uint16_t
      hdr_len_sph_flex_flags1;
  uint16_t
      status_error0;
  uint16_t
      l2tag1;
  uint32_t
      rss_hash;
  uint16_t
      status_error1;
  u8
      flexi_flags2;
  u8
      ts_low;
  uint16_t
      l2tag2_1st;
  uint16_t
      l2tag2_2nd;
  uint32_t
      flow_id;
  uint32_t
      ipsec_said;
};
enum iavf_rxtx_rel_mbufs_type
{
  IAVF_REL_MBUFS_DEFAULT = 0,
  IAVF_REL_MBUFS_SSE_VEC = 1,
  IAVF_REL_MBUFS_AVX512_VEC = 2,
};
enum iavf_rxdid
{
  IAVF_RXDID_LEGACY_0 = 0,
  IAVF_RXDID_LEGACY_1 = 1,
  IAVF_RXDID_FLEX_NIC = 2,
  IAVF_RXDID_FLEX_NIC_2 = 6,
  IAVF_RXDID_HW = 7,
  IAVF_RXDID_COMMS_GENERIC = 16,
  IAVF_RXDID_COMMS_AUX_VLAN = 17,
  IAVF_RXDID_COMMS_AUX_IPV4 = 18,
  IAVF_RXDID_COMMS_AUX_IPV6 = 19,
  IAVF_RXDID_COMMS_AUX_IPV6_FLOW = 20,
  IAVF_RXDID_COMMS_AUX_TCP = 21,
  IAVF_RXDID_COMMS_OVS_1 = 22,
  IAVF_RXDID_COMMS_OVS_2 = 23,
  IAVF_RXDID_COMMS_IPSEC_CRYPTO = 24,
  IAVF_RXDID_COMMS_AUX_IP_OFFSET = 25,
  IAVF_RXDID_LAST = 63,
};
enum iavf_rx_flex_desc_status_error_0_bits
{
  IAVF_RX_FLEX_DESC_STATUS0_DD_S = 0,
  IAVF_RX_FLEX_DESC_STATUS0_EOF_S,
  IAVF_RX_FLEX_DESC_STATUS0_HBO_S,
  IAVF_RX_FLEX_DESC_STATUS0_L3L4P_S,
  IAVF_RX_FLEX_DESC_STATUS0_XSUM_IPE_S,
  IAVF_RX_FLEX_DESC_STATUS0_XSUM_L4E_S,
  IAVF_RX_FLEX_DESC_STATUS0_XSUM_EIPE_S,
  IAVF_RX_FLEX_DESC_STATUS0_XSUM_EUDPE_S,
  IAVF_RX_FLEX_DESC_STATUS0_LPBK_S,
  IAVF_RX_FLEX_DESC_STATUS0_IPV6EXADD_S,
  IAVF_RX_FLEX_DESC_STATUS0_RXE_S,
  IAVF_RX_FLEX_DESC_STATUS0_CRCP_S,
  IAVF_RX_FLEX_DESC_STATUS0_RSS_VALID_S,
  IAVF_RX_FLEX_DESC_STATUS0_L2TAG1P_S,
  IAVF_RX_FLEX_DESC_STATUS0_XTRMD0_VALID_S,
  IAVF_RX_FLEX_DESC_STATUS0_XTRMD1_VALID_S,
  IAVF_RX_FLEX_DESC_STATUS0_LAST
};
enum iavf_rx_flex_desc_status_error_1_bits
{
  IAVF_RX_FLEX_DESC_STATUS1_IPSEC_CRYPTO_STATUS_0 = 0,
  IAVF_RX_FLEX_DESC_STATUS1_IPSEC_CRYPTO_STATUS_1,
  IAVF_RX_FLEX_DESC_STATUS1_IPSEC_CRYPTO_STATUS_2,
  IAVF_RX_FLEX_DESC_STATUS1_IPSEC_CRYPTO_STATUS_3,
  IAVF_RX_FLEX_DESC_STATUS1_NAT_S,
  IAVF_RX_FLEX_DESC_STATUS1_IPSEC_CRYPTO_PROCESSED,
  IAVF_RX_FLEX_DESC_STATUS1_L2TAG2P_S = 11,
  IAVF_RX_FLEX_DESC_STATUS1_XTRMD2_VALID_S = 12,
  IAVF_RX_FLEX_DESC_STATUS1_XTRMD3_VALID_S = 13,
  IAVF_RX_FLEX_DESC_STATUS1_XTRMD4_VALID_S = 14,
  IAVF_RX_FLEX_DESC_STATUS1_XTRMD5_VALID_S = 15,
  IAVF_RX_FLEX_DESC_STATUS1_LAST
};
enum iavf_rx_flex_desc_ipsec_crypto_status
{
  IAVF_IPSEC_CRYPTO_STATUS_SUCCESS = 0,
  IAVF_IPSEC_CRYPTO_STATUS_SAD_MISS,
  IAVF_IPSEC_CRYPTO_STATUS_NOT_PROCESSED,
  IAVF_IPSEC_CRYPTO_STATUS_ICV_CHECK_FAIL,
  IAVF_IPSEC_CRYPTO_STATUS_LENGTH_ERR,
  IAVF_IPSEC_CRYPTO_STATUS_MISC_ERR = 0xF
};
enum iavf_tx_ctx_desc_tunnel_external_ip_type
{
  IAVF_TX_CTX_DESC_EIPT_NONE,
  IAVF_TX_CTX_DESC_EIPT_IPV6,
  IAVF_TX_CTX_DESC_EIPT_IPV4_NO_CHECKSUM_OFFLOAD,
  IAVF_TX_CTX_DESC_EIPT_IPV4_CHECKSUM_OFFLOAD
};
enum iavf_tx_ctx_desc_tunnel_l4_tunnel_type
{
  IAVF_TX_CTX_DESC_L4_TUN_TYP_NO_UDP_GRE,
  IAVF_TX_CTX_DESC_L4_TUN_TYP_UDP,
  IAVF_TX_CTX_DESC_L4_TUN_TYP_GRE
};
int iavf_dev_rx_queue_setup(struct rte_eth_dev *dev,
                            uint16_t queue_idx,
                            uint16_t nb_desc,
                            unsigned int socket_id,
                            const struct rte_eth_rxconf *rx_conf,
                            struct rte_mempool *mp);
int iavf_dev_rx_queue_start(struct rte_eth_dev *dev, uint16_t rx_queue_id);
int iavf_dev_rx_queue_stop(struct rte_eth_dev *dev, uint16_t rx_queue_id);
void iavf_dev_rx_queue_release(struct rte_eth_dev *dev, uint16_t qid);
int iavf_dev_tx_queue_setup(struct rte_eth_dev *dev,
                            uint16_t queue_idx,
                            uint16_t nb_desc,
                            unsigned int socket_id,
                            const struct rte_eth_txconf *tx_conf);
int iavf_dev_tx_queue_start(struct rte_eth_dev *dev, uint16_t tx_queue_id);
int iavf_dev_tx_queue_stop(struct rte_eth_dev *dev, uint16_t tx_queue_id);
int iavf_dev_tx_done_cleanup(void *txq, uint32_t free_cnt);
void iavf_dev_tx_queue_release(struct rte_eth_dev *dev, uint16_t qid);
void iavf_stop_queues(struct rte_eth_dev *dev);
uint16_t
iavf_recv_pkts(void *rx_queue, struct rte_mbuf **rx_pkts, uint16_t nb_pkts);
uint16_t
iavf_recv_pkts_flex_rxd(void *rx_queue,
                        struct rte_mbuf **rx_pkts, uint16_t nb_pkts);
uint16_t
iavf_recv_scattered_pkts(void *rx_queue,
                         struct rte_mbuf **rx_pkts, uint16_t nb_pkts);
uint16_t
iavf_recv_scattered_pkts_flex_rxd(void *rx_queue,
                                  struct rte_mbuf **rx_pkts,
                                  uint16_t nb_pkts);
uint16_t
iavf_xmit_pkts(void *tx_queue, struct rte_mbuf **tx_pkts, uint16_t nb_pkts);
uint16_t
iavf_prep_pkts(void *tx_queue, struct rte_mbuf **tx_pkts, uint16_t nb_pkts);
void iavf_set_rx_function(struct rte_eth_dev *dev);
void iavf_set_tx_function(struct rte_eth_dev *dev);
void iavf_dev_rxq_info_get(struct rte_eth_dev *dev, uint16_t queue_id,
                           struct rte_eth_rxq_info *qinfo);
void iavf_dev_txq_info_get(struct rte_eth_dev *dev, uint16_t queue_id,
                           struct rte_eth_txq_info *qinfo);
uint32_t
iavf_dev_rxq_count(void *rx_queue);
int iavf_dev_rx_desc_status(void *rx_queue, uint16_t offset);
int iavf_dev_tx_desc_status(void *tx_queue, uint16_t offset);
uint16_t
iavf_recv_pkts_vec(void *rx_queue, struct rte_mbuf **rx_pkts,
                   uint16_t nb_pkts);
uint16_t
iavf_recv_pkts_vec_flex_rxd(void *rx_queue, struct rte_mbuf **rx_pkts,
                            uint16_t nb_pkts);
uint16_t
iavf_recv_scattered_pkts_vec(void *rx_queue,
                             struct rte_mbuf **rx_pkts, uint16_t nb_pkts);
uint16_t
iavf_recv_scattered_pkts_vec_flex_rxd(void *rx_queue,
                                      struct rte_mbuf **rx_pkts,
                                      uint16_t nb_pkts);
uint16_t
iavf_xmit_fixed_burst_vec(void *tx_queue, struct rte_mbuf **tx_pkts,
                          uint16_t nb_pkts);
uint16_t
iavf_recv_pkts_vec_avx2(void *rx_queue, struct rte_mbuf **rx_pkts,
                        uint16_t nb_pkts);
uint16_t
iavf_recv_pkts_vec_avx2_offload(void *rx_queue,
                                struct rte_mbuf **rx_pkts, uint16_t nb_pkts);
uint16_t
iavf_recv_pkts_vec_avx2_flex_rxd(void *rx_queue,
                                 struct rte_mbuf **rx_pkts,
                                 uint16_t nb_pkts);
uint16_t
iavf_recv_pkts_vec_avx2_flex_rxd_offload(void *rx_queue,
                                         struct rte_mbuf **rx_pkts,
                                         uint16_t nb_pkts);
uint16_t
iavf_recv_scattered_pkts_vec_avx2(void *rx_queue,
                                  struct rte_mbuf **rx_pkts,
                                  uint16_t nb_pkts);
uint16_t
iavf_recv_scattered_pkts_vec_avx2_offload(void *rx_queue,
                                          struct rte_mbuf **rx_pkts,
                                          uint16_t nb_pkts);
uint16_t
iavf_recv_scattered_pkts_vec_avx2_flex_rxd(void *rx_queue,
                                           struct rte_mbuf **rx_pkts,
                                           uint16_t nb_pkts);
uint16_t
iavf_recv_scattered_pkts_vec_avx2_flex_rxd_offload(void *rx_queue,
                                                   struct rte_mbuf
                                                       **rx_pkts,
                                                   uint16_t nb_pkts);
uint16_t
iavf_xmit_pkts_vec(void *tx_queue, struct rte_mbuf **tx_pkts,
                   uint16_t nb_pkts);
uint16_t
iavf_xmit_pkts_vec_avx2(void *tx_queue, struct rte_mbuf **tx_pkts,
                        uint16_t nb_pkts);
uint16_t
iavf_xmit_pkts_vec_avx2_offload(void *tx_queue,
                                struct rte_mbuf **tx_pkts, uint16_t nb_pkts);
int iavf_get_monitor_addr(void *rx_queue,
                          struct rte_power_monitor_cond *pmc);
int iavf_rx_vec_dev_check(struct rte_eth_dev *dev);
int iavf_tx_vec_dev_check(struct rte_eth_dev *dev);
int iavf_rxq_vec_setup(struct iavf_rx_queue *rxq);
int iavf_txq_vec_setup(struct iavf_tx_queue *txq);
uint16_t
iavf_recv_pkts_vec_avx512(void *rx_queue, struct rte_mbuf **rx_pkts,
                          uint16_t nb_pkts);
uint16_t
iavf_recv_pkts_vec_avx512_offload(void *rx_queue,
                                  struct rte_mbuf **rx_pkts,
                                  uint16_t nb_pkts);
uint16_t
iavf_recv_pkts_vec_avx512_flex_rxd(void *rx_queue,
                                   struct rte_mbuf **rx_pkts,
                                   uint16_t nb_pkts);
uint16_t
iavf_recv_pkts_vec_avx512_flex_rxd_offload(void *rx_queue,
                                           struct rte_mbuf **rx_pkts,
                                           uint16_t nb_pkts);
uint16_t
iavf_recv_scattered_pkts_vec_avx512(void *rx_queue,
                                    struct rte_mbuf **rx_pkts,
                                    uint16_t nb_pkts);
uint16_t
iavf_recv_scattered_pkts_vec_avx512_offload(void *rx_queue,
                                            struct rte_mbuf **rx_pkts,
                                            uint16_t nb_pkts);
uint16_t
iavf_recv_scattered_pkts_vec_avx512_flex_rxd(void *rx_queue,
                                             struct rte_mbuf **rx_pkts,
                                             uint16_t nb_pkts);
uint16_t
iavf_recv_scattered_pkts_vec_avx512_flex_rxd_offload(void *rx_queue,
                                                     struct rte_mbuf
                                                         **rx_pkts,
                                                     uint16_t nb_pkts);
uint16_t
iavf_xmit_pkts_vec_avx512(void *tx_queue, struct rte_mbuf **tx_pkts,
                          uint16_t nb_pkts);
uint16_t
iavf_xmit_pkts_vec_avx512_offload(void *tx_queue,
                                  struct rte_mbuf **tx_pkts,
                                  uint16_t nb_pkts);
uint16_t
iavf_xmit_pkts_vec_avx512_ctx_offload(void *tx_queue,
                                      struct rte_mbuf **tx_pkts,
                                      uint16_t nb_pkts);
uint16_t
iavf_xmit_pkts_vec_avx512_ctx(void *tx_queue, struct rte_mbuf **tx_pkts,
                              uint16_t nb_pkts);
int iavf_txq_vec_setup_avx512(struct iavf_tx_queue *txq);
uint8_t
iavf_proto_xtr_type_to_rxdid(uint8_t xtr_type);
void iavf_set_default_ptype_table(struct rte_eth_dev *dev);
void iavf_tx_queue_release_mbufs_avx512(struct iavf_tx_queue *txq);
void iavf_rx_queue_release_mbufs_sse(struct iavf_rx_queue *rxq);
void iavf_tx_queue_release_mbufs_sse(struct iavf_tx_queue *txq);
static inline void
iavf_dump_rx_descriptor(struct iavf_rx_queue *rxq,
                        const volatile void *desc, uint16_t rx_id)
{
  const volatile union iavf_32byte_rx_desc *rx_desc = desc;
  printf("Queue %d Rx_desc %d: QW0: 0x%016"
         "l"
         "x"
         " QW1: 0x%016"
         "l"
         "x"
         " QW2: 0x%016"
         "l"
         "x"
         " QW3: 0x%016"
         "l"
         "x"
         "\n",
         rxq->queue_id,
         rx_id, rx_desc->read.pkt_addr, rx_desc->read.hdr_addr,
         rx_desc->read.rsvd1, rx_desc->read.rsvd2);
}

static inline void
iavf_dump_tx_descriptor(const struct iavf_tx_queue *txq,
                        const volatile void *desc, uint16_t tx_id)
{
  const char *name;
  const volatile struct iavf_tx_desc *tx_desc = desc;
  enum iavf_tx_desc_dtype_value type;
  type = (enum iavf_tx_desc_dtype_value)(tx_desc->cmd_type_offset_bsz & ((0xFUL << 0)));
  switch (type)
  {
  case IAVF_TX_DESC_DTYPE_DATA:
    name = "Tx_data_desc";
    break;
  case IAVF_TX_DESC_DTYPE_CONTEXT:
    name = "Tx_context_desc";
    break;
  case IAVF_TX_DESC_DTYPE_IPSEC:
    name = "Tx_IPsec_desc";
    break;
  default:
    name = "unknown_desc";
    break;
  }
  printf("Queue %d %s %d: QW0: 0x%016"
         "l"
         "x"
         " QW1: 0x%016"
         "l"
         "x"
         "\n",
         txq->queue_id, name, tx_id, tx_desc->buffer_addr,
         tx_desc->cmd_type_offset_bsz);
}

static inline void
iavf_fdir_rx_proc_enable(struct iavf_adapter *ad, _Bool on)
{
  if (on)
  {
    do
    {
      int i;
      for (i = 0; i < (ad)->dev_data->nb_rx_queues; i++)
      {
        struct iavf_rx_queue *rxq = (ad)->dev_data->rx_queues[i];
        if (!rxq)
          continue;
        rxq->fdir_enabled = on;
      }
      rte_log(8U, iavf_logtype_driver,
              "%s(): "
              "FDIR processing on RX set to %d"
              "\n",
              __func__,
              on);
    } while (0);
    ad->fdir_ref_cnt++;
  }
  else
  {
    if (ad->fdir_ref_cnt >= 1)
    {
      ad->fdir_ref_cnt--;
      if (ad->fdir_ref_cnt == 0)
        do
        {
          int i;
          for (i = 0; i < (ad)->dev_data->nb_rx_queues; i++)
          {
            struct iavf_rx_queue *rxq = (ad)->dev_data->rx_queues[i];
            if (!rxq)
              continue;
            rxq->fdir_enabled = on;
          }
          rte_log(8U, iavf_logtype_driver,
                  "%s(): "
                  "FDIR processing on RX set to %d"
                  "\n",
                  __func__, on);
        } while (0);
    }
  }
}

static inline uint64_t
iavf_tstamp_convert_32b_64b(uint64_t time, uint32_t in_timestamp)
{
  const uint64_t mask = 0xFFFFFFFF;
  uint32_t delta;
  uint64_t ns;
  delta = (in_timestamp - (uint32_t)(time & mask));
  if (delta > (mask / 2))
  {
    delta = ((uint32_t)(time & mask) - in_timestamp);
    ns = time - delta;
  }
  else
  {
    ns = time + delta;
  }
  return ns;
}

struct rte_crypto_vec
{
  void *base;
  rte_iova_t iova;
  uint32_t len;
  uint32_t tot_len;
};
struct rte_crypto_sgl
{
  struct rte_crypto_vec *vec;
  uint32_t num;
};
struct rte_crypto_va_iova_ptr
{
  void *va;
  rte_iova_t iova;
};
struct rte_crypto_sym_vec
{
  uint32_t num;
  struct rte_crypto_sgl *src_sgl;
  struct rte_crypto_sgl *dest_sgl;
  struct rte_crypto_va_iova_ptr *iv;
  struct rte_crypto_va_iova_ptr *digest;
  __extension__ union
  {
    struct rte_crypto_va_iova_ptr *auth_iv;
    struct rte_crypto_va_iova_ptr *aad;
  };
  int32_t *status;
};
union rte_crypto_sym_ofs
{
  uint64_t raw;
  struct
  {
    struct
    {
      uint16_t head;
      uint16_t tail;
    } auth, cipher;
  } ofs;
};
enum rte_crypto_cipher_algorithm
{
  RTE_CRYPTO_CIPHER_NULL = 1,
  RTE_CRYPTO_CIPHER_3DES_CBC,
  RTE_CRYPTO_CIPHER_3DES_CTR,
  RTE_CRYPTO_CIPHER_3DES_ECB,
  RTE_CRYPTO_CIPHER_AES_CBC,
  RTE_CRYPTO_CIPHER_AES_CTR,
  RTE_CRYPTO_CIPHER_AES_ECB,
  RTE_CRYPTO_CIPHER_AES_F8,
  RTE_CRYPTO_CIPHER_AES_XTS,
  RTE_CRYPTO_CIPHER_ARC4,
  RTE_CRYPTO_CIPHER_KASUMI_F8,
  RTE_CRYPTO_CIPHER_SNOW3G_UEA2,
  RTE_CRYPTO_CIPHER_ZUC_EEA3,
  RTE_CRYPTO_CIPHER_DES_CBC,
  RTE_CRYPTO_CIPHER_AES_DOCSISBPI,
  RTE_CRYPTO_CIPHER_DES_DOCSISBPI,
  RTE_CRYPTO_CIPHER_SM4_ECB,
  RTE_CRYPTO_CIPHER_SM4_CBC,
  RTE_CRYPTO_CIPHER_SM4_CTR,
  RTE_CRYPTO_CIPHER_SM4_OFB,
  RTE_CRYPTO_CIPHER_SM4_CFB
};
enum rte_crypto_cipher_operation
{
  RTE_CRYPTO_CIPHER_OP_ENCRYPT,
  RTE_CRYPTO_CIPHER_OP_DECRYPT
};
extern const char *rte_crypto_cipher_operation_strings[];
struct rte_crypto_cipher_xform
{
  enum rte_crypto_cipher_operation op;
  enum rte_crypto_cipher_algorithm algo;
  struct
  {
    const uint8_t *data;
    uint16_t length;
  } key;
  struct
  {
    uint16_t offset;
    uint16_t length;
  } iv;
  uint32_t dataunit_len;
};
enum rte_crypto_auth_algorithm
{
  RTE_CRYPTO_AUTH_NULL = 1,
  RTE_CRYPTO_AUTH_AES_CBC_MAC,
  RTE_CRYPTO_AUTH_AES_CMAC,
  RTE_CRYPTO_AUTH_AES_GMAC,
  RTE_CRYPTO_AUTH_AES_XCBC_MAC,
  RTE_CRYPTO_AUTH_KASUMI_F9,
  RTE_CRYPTO_AUTH_MD5,
  RTE_CRYPTO_AUTH_MD5_HMAC,
  RTE_CRYPTO_AUTH_SHA1,
  RTE_CRYPTO_AUTH_SHA1_HMAC,
  RTE_CRYPTO_AUTH_SHA224,
  RTE_CRYPTO_AUTH_SHA224_HMAC,
  RTE_CRYPTO_AUTH_SHA256,
  RTE_CRYPTO_AUTH_SHA256_HMAC,
  RTE_CRYPTO_AUTH_SHA384,
  RTE_CRYPTO_AUTH_SHA384_HMAC,
  RTE_CRYPTO_AUTH_SHA512,
  RTE_CRYPTO_AUTH_SHA512_HMAC,
  RTE_CRYPTO_AUTH_SNOW3G_UIA2,
  RTE_CRYPTO_AUTH_ZUC_EIA3,
  RTE_CRYPTO_AUTH_SHA3_224,
  RTE_CRYPTO_AUTH_SHA3_224_HMAC,
  RTE_CRYPTO_AUTH_SHA3_256,
  RTE_CRYPTO_AUTH_SHA3_256_HMAC,
  RTE_CRYPTO_AUTH_SHA3_384,
  RTE_CRYPTO_AUTH_SHA3_384_HMAC,
  RTE_CRYPTO_AUTH_SHA3_512,
  RTE_CRYPTO_AUTH_SHA3_512_HMAC,
  RTE_CRYPTO_AUTH_SM3,
  RTE_CRYPTO_AUTH_SHAKE_128,
  RTE_CRYPTO_AUTH_SHAKE_256,
  RTE_CRYPTO_AUTH_SM3_HMAC,
};
enum rte_crypto_auth_operation
{
  RTE_CRYPTO_AUTH_OP_VERIFY,
  RTE_CRYPTO_AUTH_OP_GENERATE
};
extern const char *rte_crypto_auth_operation_strings[];
struct rte_crypto_auth_xform
{
  enum rte_crypto_auth_operation op;
  enum rte_crypto_auth_algorithm algo;
  struct
  {
    const uint8_t *data;
    uint16_t length;
  } key;
  struct
  {
    uint16_t offset;
    uint16_t length;
  } iv;
  uint16_t digest_length;
};
enum rte_crypto_aead_algorithm
{
  RTE_CRYPTO_AEAD_AES_CCM = 1,
  RTE_CRYPTO_AEAD_AES_GCM,
  RTE_CRYPTO_AEAD_CHACHA20_POLY1305
};
enum rte_crypto_aead_operation
{
  RTE_CRYPTO_AEAD_OP_ENCRYPT,
  RTE_CRYPTO_AEAD_OP_DECRYPT
};
extern const char *rte_crypto_aead_operation_strings[];
struct rte_crypto_aead_xform
{
  enum rte_crypto_aead_operation op;
  enum rte_crypto_aead_algorithm algo;
  struct
  {
    const uint8_t *data;
    uint16_t length;
  } key;
  struct
  {
    uint16_t offset;
    uint16_t length;
  } iv;
  uint16_t digest_length;
  uint16_t aad_length;
};
enum rte_crypto_sym_xform_type
{
  RTE_CRYPTO_SYM_XFORM_NOT_SPECIFIED = 0,
  RTE_CRYPTO_SYM_XFORM_AUTH,
  RTE_CRYPTO_SYM_XFORM_CIPHER,
  RTE_CRYPTO_SYM_XFORM_AEAD
};
struct rte_crypto_sym_xform
{
  struct rte_crypto_sym_xform *next;
  enum rte_crypto_sym_xform_type type;
  union
  {
    struct rte_crypto_auth_xform auth;
    struct rte_crypto_cipher_xform cipher;
    struct rte_crypto_aead_xform aead;
  };
};
struct rte_crypto_sym_op
{
  struct rte_mbuf *m_src;
  struct rte_mbuf *m_dst;
  union
  {
    void *session;
    struct rte_crypto_sym_xform *xform;
  };
  union
  {
    struct
    {
      struct
      {
        uint32_t offset;
        uint32_t length;
      } data;
      struct
      {
        uint8_t *data;
        rte_iova_t phys_addr;
      } digest;
      struct
      {
        uint8_t *data;
        rte_iova_t phys_addr;
      } aad;
    } aead;
    struct
    {
      struct
      {
        struct
        {
          uint32_t offset;
          uint32_t length;
        } data;
      } cipher;
      struct
      {
        struct
        {
          uint32_t offset;
          uint32_t length;
        } data;
        struct
        {
          uint8_t *data;
          rte_iova_t phys_addr;
        } digest;
      } auth;
    };
  };
};
static inline void
__rte_crypto_sym_op_reset(struct rte_crypto_sym_op *op)
{
  memset(op, 0, sizeof(*op));
}

static inline struct rte_crypto_sym_xform *
__rte_crypto_sym_op_sym_xforms_alloc(struct rte_crypto_sym_op *sym_op,
                                     void *priv_data, uint8_t nb_xforms)
{
  struct rte_crypto_sym_xform *xform;
  sym_op->xform = xform = (struct rte_crypto_sym_xform *)priv_data;
  do
  {
    xform->type = RTE_CRYPTO_SYM_XFORM_NOT_SPECIFIED;
    xform = xform->next = --nb_xforms > 0 ? xform + 1 : ((void *)0);
  } while (xform);
  return sym_op->xform;
}

static inline int
__rte_crypto_sym_op_attach_sym_session(struct rte_crypto_sym_op *sym_op,
                                       void *sess)
{
  sym_op->session = sess;
  return 0;
}

__attribute__((section(".text.experimental"))) static inline int
rte_crypto_mbuf_to_vec(const struct rte_mbuf *mb, uint32_t ofs,
                       uint32_t len, struct rte_crypto_vec vec[],
                       uint32_t num)
{
  uint32_t i;
  struct rte_mbuf *nseg;
  uint32_t left;
  uint32_t seglen;
  do
  {
  } while (0);
  if (mb->nb_segs > num)
    return -mb->nb_segs;
  vec[0].base =
      ((void *)(void *)((char *)(mb)->buf_addr + (mb)->data_off + (ofs)));
  vec[0].iova =
      (rte_iova_t)(rte_mbuf_iova_get(mb) + (mb)->data_off + (ofs));
  vec[0].tot_len = mb->buf_len - rte_pktmbuf_headroom(mb) - ofs;
  seglen = mb->data_len - ofs;
  if (len <= seglen)
  {
    vec[0].len = len;
    return 1;
  }
  vec[0].len = seglen;
  left = len - seglen;
  for (i = 1, nseg = mb->next; nseg != ((void *)0); nseg = nseg->next, i++)
  {
    vec[i].base =
        ((void *)(void *)((char *)(nseg)->buf_addr + (nseg)->data_off +
                          (0)));
    vec[i].iova =
        (rte_iova_t)(rte_mbuf_iova_get(nseg) + (nseg)->data_off + (0));
    vec[i].tot_len = mb->buf_len - rte_pktmbuf_headroom(mb) - ofs;
    seglen = nseg->data_len;
    if (left <= seglen)
    {
      vec[i].len = left;
      left = 0;
      i++;
      break;
    }
    vec[i].len = seglen;
    left -= seglen;
  }
  do
  {
  } while (0);
  return i;
}

struct rte_cryptodev_asym_session;
extern const char *rte_crypto_asym_ke_strings[];
extern const char *rte_crypto_asym_op_strings[];
enum rte_crypto_curve_id
{
  RTE_CRYPTO_EC_GROUP_SECP192R1 = 19,
  RTE_CRYPTO_EC_GROUP_SECP224R1 = 21,
  RTE_CRYPTO_EC_GROUP_SECP256R1 = 23,
  RTE_CRYPTO_EC_GROUP_SECP384R1 = 24,
  RTE_CRYPTO_EC_GROUP_SECP521R1 = 25,
  RTE_CRYPTO_EC_GROUP_SM2 = 41,
};
enum rte_crypto_asym_xform_type
{
  RTE_CRYPTO_ASYM_XFORM_UNSPECIFIED = 0,
  RTE_CRYPTO_ASYM_XFORM_NONE,
  RTE_CRYPTO_ASYM_XFORM_RSA,
  RTE_CRYPTO_ASYM_XFORM_DH,
  RTE_CRYPTO_ASYM_XFORM_DSA,
  RTE_CRYPTO_ASYM_XFORM_MODINV,
  RTE_CRYPTO_ASYM_XFORM_MODEX,
  RTE_CRYPTO_ASYM_XFORM_ECDSA,
  RTE_CRYPTO_ASYM_XFORM_ECDH,
  RTE_CRYPTO_ASYM_XFORM_ECPM,
  RTE_CRYPTO_ASYM_XFORM_ECFPM,
  RTE_CRYPTO_ASYM_XFORM_SM2,
  RTE_CRYPTO_ASYM_XFORM_TYPE_LIST_END
};
enum rte_crypto_asym_op_type
{
  RTE_CRYPTO_ASYM_OP_ENCRYPT,
  RTE_CRYPTO_ASYM_OP_DECRYPT,
  RTE_CRYPTO_ASYM_OP_SIGN,
  RTE_CRYPTO_ASYM_OP_VERIFY,
  RTE_CRYPTO_ASYM_OP_LIST_END
};
enum rte_crypto_asym_ke_type
{
  RTE_CRYPTO_ASYM_KE_PRIV_KEY_GENERATE,
  RTE_CRYPTO_ASYM_KE_PUB_KEY_GENERATE,
  RTE_CRYPTO_ASYM_KE_SHARED_SECRET_COMPUTE,
  RTE_CRYPTO_ASYM_KE_PUB_KEY_VERIFY
};
enum rte_crypto_rsa_padding_type
{
  RTE_CRYPTO_RSA_PADDING_NONE = 0,
  RTE_CRYPTO_RSA_PADDING_PKCS1_5,
  RTE_CRYPTO_RSA_PADDING_OAEP,
  RTE_CRYPTO_RSA_PADDING_PSS,
  RTE_CRYPTO_RSA_PADDING_TYPE_LIST_END
};
enum rte_crypto_rsa_priv_key_type
{
  RTE_RSA_KEY_TYPE_EXP,
  RTE_RSA_KEY_TYPE_QT,
};
typedef struct rte_crypto_param_t
{
  uint8_t *data;
  rte_iova_t iova;
  size_t length;
} rte_crypto_param;
typedef rte_crypto_param rte_crypto_uint;
struct rte_crypto_ec_point
{
  rte_crypto_param x;
  rte_crypto_param y;
};
struct rte_crypto_rsa_priv_key_qt
{
  rte_crypto_uint p;
  rte_crypto_uint q;
  rte_crypto_uint dP;
  rte_crypto_uint dQ;
  rte_crypto_uint qInv;
};
struct rte_crypto_rsa_padding
{
  enum rte_crypto_rsa_padding_type type;
  enum rte_crypto_auth_algorithm hash;
  enum rte_crypto_auth_algorithm mgf1hash;
  uint16_t pss_saltlen;
  rte_crypto_param oaep_label;
};
struct rte_crypto_rsa_xform
{
  rte_crypto_uint n;
  rte_crypto_uint e;
  enum rte_crypto_rsa_priv_key_type key_type;
  union
  {
    rte_crypto_uint d;
    struct rte_crypto_rsa_priv_key_qt qt;
  };
};
struct rte_crypto_modex_xform
{
  rte_crypto_uint modulus;
  rte_crypto_uint exponent;
};
struct rte_crypto_modinv_xform
{
  rte_crypto_uint modulus;
};
struct rte_crypto_dh_xform
{
  rte_crypto_uint p;
  rte_crypto_uint g;
};
struct rte_crypto_dsa_xform
{
  rte_crypto_uint p;
  rte_crypto_uint q;
  rte_crypto_uint g;
  rte_crypto_uint x;
};
struct rte_crypto_ec_xform
{
  enum rte_crypto_curve_id curve_id;
  rte_crypto_uint pkey;
  struct rte_crypto_ec_point q;
};
struct rte_crypto_mod_op_param
{
  rte_crypto_uint base;
  rte_crypto_uint result;
};
struct rte_crypto_rsa_op_param
{
  enum rte_crypto_asym_op_type op_type;
  rte_crypto_param message;
  rte_crypto_param cipher;
  rte_crypto_param sign;
  struct rte_crypto_rsa_padding padding;
};
struct rte_crypto_dh_op_param
{
  enum rte_crypto_asym_ke_type ke_type;
  rte_crypto_uint priv_key;
  rte_crypto_uint pub_key;
  rte_crypto_uint shared_secret;
};
struct rte_crypto_ecdh_op_param
{
  enum rte_crypto_asym_ke_type ke_type;
  rte_crypto_uint priv_key;
  struct rte_crypto_ec_point pub_key;
  struct rte_crypto_ec_point shared_secret;
};
struct rte_crypto_dsa_op_param
{
  enum rte_crypto_asym_op_type op_type;
  rte_crypto_param message;
  rte_crypto_uint k;
  rte_crypto_uint r;
  rte_crypto_uint s;
  rte_crypto_uint y;
};
struct rte_crypto_ecdsa_op_param
{
  enum rte_crypto_asym_op_type op_type;
  rte_crypto_param message;
  rte_crypto_uint k;
  rte_crypto_uint r;
  rte_crypto_uint s;
};
struct rte_crypto_ecpm_op_param
{
  struct rte_crypto_ec_point p;
  struct rte_crypto_ec_point r;
  rte_crypto_param scalar;
};
struct rte_crypto_asym_xform
{
  struct rte_crypto_asym_xform *next;
  enum rte_crypto_asym_xform_type xform_type;
  union
  {
    struct rte_crypto_rsa_xform rsa;
    struct rte_crypto_modex_xform modex;
    struct rte_crypto_modinv_xform modinv;
    struct rte_crypto_dh_xform dh;
    struct rte_crypto_dsa_xform dsa;
    struct rte_crypto_ec_xform ec;
  };
};
struct rte_crypto_sm2_op_param
{
  enum rte_crypto_asym_op_type op_type;
  enum rte_crypto_auth_algorithm hash;
  rte_crypto_param message;
  rte_crypto_param cipher;
  rte_crypto_uint id;
  rte_crypto_uint k;
  rte_crypto_uint r;
  rte_crypto_uint s;
};
struct rte_crypto_asym_op
{
  union
  {
    struct rte_cryptodev_asym_session *session;
    struct rte_crypto_asym_xform *xform;
  };
  union
  {
    struct rte_crypto_rsa_op_param rsa;
    struct rte_crypto_mod_op_param modex;
    struct rte_crypto_mod_op_param modinv;
    struct rte_crypto_dh_op_param dh;
    struct rte_crypto_ecdh_op_param ecdh;
    struct rte_crypto_dsa_op_param dsa;
    struct rte_crypto_ecdsa_op_param ecdsa;
    struct rte_crypto_ecpm_op_param ecpm;
    struct rte_crypto_sm2_op_param sm2;
  };
  uint16_t flags;
};
enum rte_crypto_op_type
{
  RTE_CRYPTO_OP_TYPE_UNDEFINED,
  RTE_CRYPTO_OP_TYPE_SYMMETRIC,
  RTE_CRYPTO_OP_TYPE_ASYMMETRIC
};
enum rte_crypto_op_status
{
  RTE_CRYPTO_OP_STATUS_SUCCESS,
  RTE_CRYPTO_OP_STATUS_NOT_PROCESSED,
  RTE_CRYPTO_OP_STATUS_AUTH_FAILED,
  RTE_CRYPTO_OP_STATUS_INVALID_SESSION,
  RTE_CRYPTO_OP_STATUS_INVALID_ARGS,
  RTE_CRYPTO_OP_STATUS_ERROR,
};
enum rte_crypto_op_sess_type
{
  RTE_CRYPTO_OP_WITH_SESSION,
  RTE_CRYPTO_OP_SESSIONLESS,
  RTE_CRYPTO_OP_SECURITY_SESSION
};
struct rte_crypto_op
{
  __extension__ union
  {
    uint64_t raw;
    __extension__ struct
    {
      uint8_t type;
      uint8_t status;
      uint8_t sess_type;
      uint8_t aux_flags;
      union
      {
        struct
        {
          uint8_t content_type;
        } tls_record;
      } param1;
      uint8_t reserved[1];
      uint16_t private_data_offset;
    };
  };
  struct rte_mempool *mempool;
  rte_iova_t phys_addr;
  __extension__ union
  {
    struct rte_crypto_sym_op sym[0];
    struct rte_crypto_asym_op asym[0];
  };
};
static inline void
__rte_crypto_op_reset(struct rte_crypto_op *op, enum rte_crypto_op_type type)
{
  op->type = type;
  op->status = RTE_CRYPTO_OP_STATUS_NOT_PROCESSED;
  op->sess_type = RTE_CRYPTO_OP_SESSIONLESS;
  switch (type)
  {
  case RTE_CRYPTO_OP_TYPE_SYMMETRIC:
    __rte_crypto_sym_op_reset(op->sym);
    break;
  case RTE_CRYPTO_OP_TYPE_ASYMMETRIC:
    memset(op->asym, 0, sizeof(struct rte_crypto_asym_op));
    break;
  case RTE_CRYPTO_OP_TYPE_UNDEFINED:
  default:
    break;
  }
}

struct rte_crypto_op_pool_private
{
  enum rte_crypto_op_type type;
  uint16_t priv_size;
};
static inline uint16_t
__rte_crypto_op_get_priv_data_size(struct rte_mempool *mempool)
{
  struct rte_crypto_op_pool_private *priv =
      (struct rte_crypto_op_pool_private *)rte_mempool_get_priv(mempool);
  return priv->priv_size;
}

struct rte_mempool *rte_crypto_op_pool_create(const char *name,
                                              enum rte_crypto_op_type type,
                                              unsigned nb_elts,
                                              unsigned cache_size,
                                              uint16_t priv_size,
                                              int socket_id);
static inline int
__rte_crypto_op_raw_bulk_alloc(struct rte_mempool *mempool,
                               enum rte_crypto_op_type type,
                               struct rte_crypto_op **ops, uint16_t nb_ops)
{
  struct rte_crypto_op_pool_private *priv;
  priv = (struct rte_crypto_op_pool_private *)rte_mempool_get_priv(mempool);
  if (__builtin_expect(!!(priv->type != type && priv->type != RTE_CRYPTO_OP_TYPE_UNDEFINED),
                       0))
    return -22;
  if (rte_mempool_get_bulk(mempool, (void **)ops, nb_ops) == 0)
    return nb_ops;
  return 0;
}

static inline struct rte_crypto_op *
rte_crypto_op_alloc(struct rte_mempool *mempool,
                    enum rte_crypto_op_type type)
{
  struct rte_crypto_op *op = ((void *)0);
  int retval;
  retval = __rte_crypto_op_raw_bulk_alloc(mempool, type, &op, 1);
  if (__builtin_expect(!!(retval != 1), 0))
    return ((void *)0);
  __rte_crypto_op_reset(op, type);
  return op;
}

static inline unsigned
rte_crypto_op_bulk_alloc(struct rte_mempool *mempool,
                         enum rte_crypto_op_type type,
                         struct rte_crypto_op **ops, uint16_t nb_ops)
{
  int i;
  if (__builtin_expect(!!(__rte_crypto_op_raw_bulk_alloc(mempool, type, ops, nb_ops) !=
                          nb_ops),
                       0))
    return 0;
  for (i = 0; i < nb_ops; i++)
    __rte_crypto_op_reset(ops[i], type);
  return nb_ops;
}

static inline void *
__rte_crypto_op_get_priv_data(struct rte_crypto_op *op, uint32_t size)
{
  uint32_t priv_size;
  if (__builtin_expect(!!(op->mempool != ((void *)0)), 1))
  {
    priv_size = __rte_crypto_op_get_priv_data_size(op->mempool);
    if (__builtin_expect(!!(priv_size >= size), 1))
    {
      if (op->type == RTE_CRYPTO_OP_TYPE_SYMMETRIC)
        return (void *)((uint8_t *)(op + 1) +
                        sizeof(struct rte_crypto_sym_op));
      if (op->type == RTE_CRYPTO_OP_TYPE_ASYMMETRIC)
        return (void *)((uint8_t *)(op + 1) +
                        sizeof(struct rte_crypto_asym_op));
    }
  }
  return ((void *)0);
}

static inline void
rte_crypto_op_free(struct rte_crypto_op *op)
{
  if (op != ((void *)0) && op->mempool != ((void *)0))
    rte_mempool_put(op->mempool, op);
}

static inline struct rte_crypto_op *
rte_crypto_sym_op_alloc_from_mbuf_priv_data(struct rte_mbuf *m)
{
  if (__builtin_expect(!!(m == ((void *)0)), 0))
    return ((void *)0);
  if (__builtin_expect(!!(m->priv_size <
                          (sizeof(struct rte_crypto_op) + sizeof(struct rte_crypto_sym_op))),
                       0))
    return ((void *)0);
  struct rte_crypto_op *op = (struct rte_crypto_op *)(m + 1);
  __rte_crypto_op_reset(op, RTE_CRYPTO_OP_TYPE_SYMMETRIC);
  op->mempool = ((void *)0);
  op->sym->m_src = m;
  return op;
}

static inline struct rte_crypto_sym_xform *
rte_crypto_op_sym_xforms_alloc(struct rte_crypto_op *op, uint8_t nb_xforms)
{
  void *priv_data;
  uint32_t size;
  if (__builtin_expect(!!(op->type != RTE_CRYPTO_OP_TYPE_SYMMETRIC), 0))
    return ((void *)0);
  size = sizeof(struct rte_crypto_sym_xform) * nb_xforms;
  priv_data = __rte_crypto_op_get_priv_data(op, size);
  if (priv_data == ((void *)0))
    return ((void *)0);
  return __rte_crypto_sym_op_sym_xforms_alloc(op->sym, priv_data, nb_xforms);
}

static inline int
rte_crypto_op_attach_sym_session(struct rte_crypto_op *op, void *sess)
{
  if (__builtin_expect(!!(op->type != RTE_CRYPTO_OP_TYPE_SYMMETRIC), 0))
    return -1;
  op->sess_type = RTE_CRYPTO_OP_WITH_SESSION;
  return __rte_crypto_sym_op_attach_sym_session(op->sym, sess);
}

static inline int
rte_crypto_op_attach_asym_session(struct rte_crypto_op *op,
                                  struct rte_cryptodev_asym_session *sess)
{
  if (__builtin_expect(!!(op->type != RTE_CRYPTO_OP_TYPE_ASYMMETRIC), 0))
    return -1;
  op->sess_type = RTE_CRYPTO_OP_WITH_SESSION;
  op->asym->session = sess;
  return 0;
}

enum rte_security_ipsec_sa_mode
{
  RTE_SECURITY_IPSEC_SA_MODE_TRANSPORT = 1,
  RTE_SECURITY_IPSEC_SA_MODE_TUNNEL,
};
enum rte_security_ipsec_sa_protocol
{
  RTE_SECURITY_IPSEC_SA_PROTO_AH = 1,
  RTE_SECURITY_IPSEC_SA_PROTO_ESP,
};
enum rte_security_ipsec_tunnel_type
{
  RTE_SECURITY_IPSEC_TUNNEL_IPV4 = 1,
  RTE_SECURITY_IPSEC_TUNNEL_IPV6,
};
struct rte_security_ipsec_tunnel_param
{
  enum rte_security_ipsec_tunnel_type type;
  union
  {
    struct
    {
      struct in_addr src_ip;
      struct in_addr dst_ip;
      uint8_t dscp;
      uint8_t df;
      uint8_t ttl;
    } ipv4;
    struct
    {
      struct in6_addr src_addr;
      struct in6_addr dst_addr;
      uint8_t dscp;
      uint32_t flabel;
      uint8_t hlimit;
    } ipv6;
  };
};
struct rte_security_ipsec_udp_param
{
  uint16_t sport;
  uint16_t dport;
};
struct rte_security_ipsec_sa_options
{
  uint32_t esn : 1;
  uint32_t udp_encap : 1;
  uint32_t copy_dscp : 1;
  uint32_t copy_flabel : 1;
  uint32_t copy_df : 1;
  uint32_t dec_ttl : 1;
  uint32_t ecn : 1;
  uint32_t stats : 1;
  uint32_t iv_gen_disable : 1;
  uint32_t tunnel_hdr_verify : 2;
  uint32_t udp_ports_verify : 1;
  uint32_t ip_csum_enable : 1;
  uint32_t l4_csum_enable : 1;
  uint32_t ip_reassembly_en : 1;
  uint32_t ingress_oop : 1;
};
enum rte_security_ipsec_sa_direction
{
  RTE_SECURITY_IPSEC_SA_DIR_EGRESS,
  RTE_SECURITY_IPSEC_SA_DIR_INGRESS,
};
struct rte_security_ipsec_lifetime
{
  uint64_t packets_soft_limit;
  uint64_t bytes_soft_limit;
  uint64_t packets_hard_limit;
  uint64_t bytes_hard_limit;
};
struct rte_security_ipsec_xform
{
  uint32_t spi;
  uint32_t salt;
  struct rte_security_ipsec_sa_options options;
  enum rte_security_ipsec_sa_direction direction;
  enum rte_security_ipsec_sa_protocol proto;
  enum rte_security_ipsec_sa_mode mode;
  struct rte_security_ipsec_tunnel_param tunnel;
  struct rte_security_ipsec_lifetime life;
  uint32_t replay_win_sz;
  union
  {
    uint64_t value;
    struct
    {
      uint32_t low;
      uint32_t hi;
    };
  } esn;
  struct rte_security_ipsec_udp_param udp;
};
enum rte_security_macsec_direction
{
  RTE_SECURITY_MACSEC_DIR_TX,
  RTE_SECURITY_MACSEC_DIR_RX,
};
struct rte_security_macsec_sa
{
  enum rte_security_macsec_direction dir;
  struct
  {
    const uint8_t *data;
    uint16_t length;
  } key;
  uint8_t salt[12];
  uint8_t an : 2;
  uint32_t ssci;
  uint32_t xpn;
  uint32_t next_pn;
};
struct rte_security_macsec_sc
{
  enum rte_security_macsec_direction dir;
  uint64_t pn_threshold;
  union
  {
    struct
    {
      uint16_t sa_id[4];
      uint8_t sa_in_use[4];
      uint8_t active : 1;
      uint8_t is_xpn : 1;
      uint8_t reserved : 6;
    } sc_rx;
    struct
    {
      uint16_t sa_id;
      uint16_t sa_id_rekey;
      uint64_t sci;
      uint8_t active : 1;
      uint8_t re_key_en : 1;
      uint8_t is_xpn : 1;
      uint8_t reserved : 5;
    } sc_tx;
  };
};
enum rte_security_macsec_alg
{
  RTE_SECURITY_MACSEC_ALG_GCM_128,
  RTE_SECURITY_MACSEC_ALG_GCM_256,
  RTE_SECURITY_MACSEC_ALG_GCM_XPN_128,
  RTE_SECURITY_MACSEC_ALG_GCM_XPN_256,
};
struct rte_security_macsec_xform
{
  enum rte_security_macsec_direction dir;
  enum rte_security_macsec_alg alg;
  uint8_t cipher_off;
  uint64_t sci;
  uint16_t sc_id;
  union
  {
    struct
    {
      uint16_t mtu;
      uint8_t sectag_off;
      uint16_t protect_frames : 1;
      uint16_t sectag_insert_mode : 1;
      uint16_t icv_include_da_sa : 1;
      uint16_t ctrl_port_enable : 1;
      uint16_t sectag_version : 1;
      uint16_t end_station : 1;
      uint16_t send_sci : 1;
      uint16_t scb : 1;
      uint16_t encrypt : 1;
      uint16_t reserved : 7;
    } tx_secy;
    struct
    {
      uint32_t replay_win_sz;
      uint16_t validate_frames : 2;
      uint16_t icv_include_da_sa : 1;
      uint16_t ctrl_port_enable : 1;
      uint16_t preserve_sectag : 1;
      uint16_t preserve_icv : 1;
      uint16_t replay_protect : 1;
      uint16_t reserved : 9;
    } rx_secy;
  };
};
enum rte_security_pdcp_domain
{
  RTE_SECURITY_PDCP_MODE_CONTROL,
  RTE_SECURITY_PDCP_MODE_DATA,
  RTE_SECURITY_PDCP_MODE_SHORT_MAC,
};
enum rte_security_pdcp_direction
{
  RTE_SECURITY_PDCP_UPLINK,
  RTE_SECURITY_PDCP_DOWNLINK,
};
enum rte_security_pdcp_sn_size
{
  RTE_SECURITY_PDCP_SN_SIZE_5 = 5,
  RTE_SECURITY_PDCP_SN_SIZE_7 = 7,
  RTE_SECURITY_PDCP_SN_SIZE_12 = 12,
  RTE_SECURITY_PDCP_SN_SIZE_15 = 15,
  RTE_SECURITY_PDCP_SN_SIZE_18 = 18
};
struct rte_security_pdcp_xform
{
  int8_t bearer;
  uint8_t en_ordering;
  uint8_t remove_duplicates;
  enum rte_security_pdcp_domain domain;
  enum rte_security_pdcp_direction pkt_dir;
  enum rte_security_pdcp_sn_size sn_size;
  uint32_t hfn;
  uint32_t hfn_threshold;
  uint8_t hfn_ovrd;
  uint8_t sdap_enabled;
  uint16_t reserved;
};
enum rte_security_docsis_direction
{
  RTE_SECURITY_DOCSIS_UPLINK,
  RTE_SECURITY_DOCSIS_DOWNLINK,
};
struct rte_security_docsis_xform
{
  enum rte_security_docsis_direction direction;
};
enum rte_security_tls_version
{
  RTE_SECURITY_VERSION_TLS_1_2,
  RTE_SECURITY_VERSION_TLS_1_3,
  RTE_SECURITY_VERSION_DTLS_1_2,
};
enum rte_security_tls_sess_type
{
  RTE_SECURITY_TLS_SESS_TYPE_READ,
  RTE_SECURITY_TLS_SESS_TYPE_WRITE,
};
struct rte_security_tls_record_sess_options
{
  uint32_t iv_gen_disable : 1;
  uint32_t extra_padding_enable : 1;
};
struct rte_security_tls_record_lifetime
{
  uint64_t packets_soft_limit;
  uint64_t packets_hard_limit;
};
struct rte_security_tls_record_xform
{
  enum rte_security_tls_version ver;
  enum rte_security_tls_sess_type type;
  struct rte_security_tls_record_sess_options options;
  struct rte_security_tls_record_lifetime life;
  union
  {
    struct
    {
      uint64_t seq_no;
      uint8_t imp_nonce[4];
    } tls_1_2;
    struct
    {
      uint64_t seq_no;
      uint8_t imp_nonce[12];
      uint32_t min_payload_len;
    } tls_1_3;
    struct
    {
      uint16_t epoch;
      uint64_t seq_no;
      uint8_t imp_nonce[4];
      uint32_t ar_win_sz;
    } dtls_1_2;
  };
};
enum rte_security_session_action_type
{
  RTE_SECURITY_ACTION_TYPE_NONE,
  RTE_SECURITY_ACTION_TYPE_INLINE_CRYPTO,
  RTE_SECURITY_ACTION_TYPE_INLINE_PROTOCOL,
  RTE_SECURITY_ACTION_TYPE_LOOKASIDE_PROTOCOL,
  RTE_SECURITY_ACTION_TYPE_CPU_CRYPTO
};
enum rte_security_session_protocol
{
  RTE_SECURITY_PROTOCOL_IPSEC = 1,
  RTE_SECURITY_PROTOCOL_MACSEC,
  RTE_SECURITY_PROTOCOL_PDCP,
  RTE_SECURITY_PROTOCOL_DOCSIS,
  RTE_SECURITY_PROTOCOL_TLS_RECORD,
};
struct rte_security_session_conf
{
  enum rte_security_session_action_type action_type;
  enum rte_security_session_protocol protocol;
  union
  {
    struct rte_security_ipsec_xform ipsec;
    struct rte_security_macsec_xform macsec;
    struct rte_security_pdcp_xform pdcp;
    struct rte_security_docsis_xform docsis;
    struct rte_security_tls_record_xform tls_record;
  };
  struct rte_crypto_sym_xform *crypto_xform;
  void *userdata;
};
void *rte_security_session_create(void *instance,
                                  struct rte_security_session_conf *conf,
                                  struct rte_mempool *mp);
int rte_security_session_update(void *instance,
                                void *sess,
                                struct rte_security_session_conf *conf);
unsigned int rte_security_session_get_size(void *instance);
int rte_security_session_destroy(void *instance, void *sess);
int rte_security_macsec_sc_create(void *instance,
                                  struct rte_security_macsec_sc *conf);
int rte_security_macsec_sc_destroy(void *instance, uint16_t sc_id,
                                   enum rte_security_macsec_direction dir);
int rte_security_macsec_sa_create(void *instance,
                                  struct rte_security_macsec_sa *conf);
int rte_security_macsec_sa_destroy(void *instance, uint16_t sa_id,
                                   enum rte_security_macsec_direction dir);
typedef uint64_t rte_security_dynfield_t;
extern int rte_security_dynfield_offset;
typedef struct rte_mbuf *rte_security_oop_dynfield_t;
extern int rte_security_oop_dynfield_offset;
static inline rte_security_dynfield_t *
rte_security_dynfield(struct rte_mbuf *mbuf)
{
  return ((rte_security_dynfield_t *)((uintptr_t)(mbuf) +
                                      (rte_security_dynfield_offset)));
}

__attribute__((section(".text.experimental"))) static inline rte_security_oop_dynfield_t *rte_security_oop_dynfield(struct rte_mbuf *mbuf)
{
  return ((rte_security_oop_dynfield_t *)((uintptr_t)(mbuf) +
                                          (rte_security_oop_dynfield_offset)));
}

static inline _Bool
rte_security_dynfield_is_registered(void)
{
  return rte_security_dynfield_offset >= 0;
}

static inline uint32_t
rte_security_ctx_flags_get(void *ctx)
{
  return *((uint32_t *)ctx + 4);
}

static inline void
rte_security_ctx_flags_set(void *ctx, uint32_t flags)
{
  uint32_t *data;
  data = (((uint32_t *)ctx) + 4);
  *data = flags;
}

static inline uint64_t
rte_security_session_opaque_data_get(void *sess)
{
  return *((uint64_t *)sess + 0);
}

static inline void
rte_security_session_opaque_data_set(void *sess, uint64_t opaque)
{
  uint64_t *data;
  data = (((uint64_t *)sess) + 0);
  *data = opaque;
}

static inline uint64_t
rte_security_session_fast_mdata_get(void *sess)
{
  return *((uint64_t *)sess + 1);
}

static inline void
rte_security_session_fast_mdata_set(void *sess, uint64_t fdata)
{
  uint64_t *data;
  data = (((uint64_t *)sess) + 1);
  *data = fdata;
}

int __rte_security_set_pkt_metadata(void *instance,
                                    void *sess,
                                    struct rte_mbuf *m, void *params);
static inline int
rte_security_set_pkt_metadata(void *instance,
                              void *sess, struct rte_mbuf *mb, void *params)
{
  if (rte_security_ctx_flags_get(instance) & 0x00000001)
  {
    *rte_security_dynfield(mb) = (rte_security_dynfield_t)
        rte_security_session_fast_mdata_get(sess);
    return 0;
  }
  return __rte_security_set_pkt_metadata(instance, sess, mb, params);
}

static inline int
__rte_security_attach_session(struct rte_crypto_sym_op *sym_op, void *sess)
{
  sym_op->session = sess;
  return 0;
}

static inline int
rte_security_attach_session(struct rte_crypto_op *op, void *sess)
{
  if (__builtin_expect(!!(op->type != RTE_CRYPTO_OP_TYPE_SYMMETRIC), 0))
    return -22;
  op->sess_type = RTE_CRYPTO_OP_SECURITY_SESSION;
  return __rte_security_attach_session(op->sym, sess);
}

struct rte_security_macsec_secy_stats
{
  uint64_t ctl_pkt_bcast_cnt;
  uint64_t ctl_pkt_mcast_cnt;
  uint64_t ctl_pkt_ucast_cnt;
  uint64_t ctl_octet_cnt;
  uint64_t unctl_pkt_bcast_cnt;
  uint64_t unctl_pkt_mcast_cnt;
  uint64_t unctl_pkt_ucast_cnt;
  uint64_t unctl_octet_cnt;
  uint64_t octet_decrypted_cnt;
  uint64_t octet_validated_cnt;
  uint64_t pkt_port_disabled_cnt;
  uint64_t pkt_badtag_cnt;
  uint64_t pkt_nosa_cnt;
  uint64_t pkt_nosaerror_cnt;
  uint64_t pkt_tagged_ctl_cnt;
  uint64_t pkt_untaged_cnt;
  uint64_t pkt_ctl_cnt;
  uint64_t pkt_notag_cnt;
  uint64_t octet_encrypted_cnt;
  uint64_t octet_protected_cnt;
  uint64_t pkt_noactivesa_cnt;
  uint64_t pkt_toolong_cnt;
  uint64_t pkt_untagged_cnt;
};
struct rte_security_macsec_sc_stats
{
  uint64_t hit_cnt;
  uint64_t pkt_invalid_cnt;
  uint64_t pkt_late_cnt;
  uint64_t pkt_notvalid_cnt;
  uint64_t pkt_unchecked_cnt;
  uint64_t pkt_delay_cnt;
  uint64_t pkt_ok_cnt;
  uint64_t octet_decrypt_cnt;
  uint64_t octet_validate_cnt;
  uint64_t pkt_encrypt_cnt;
  uint64_t pkt_protected_cnt;
  uint64_t octet_encrypt_cnt;
  uint64_t octet_protected_cnt;
};
struct rte_security_macsec_sa_stats
{
  uint64_t pkt_invalid_cnt;
  uint64_t pkt_nosaerror_cnt;
  uint64_t pkt_notvalid_cnt;
  uint64_t pkt_ok_cnt;
  uint64_t pkt_nosa_cnt;
  uint64_t pkt_encrypt_cnt;
  uint64_t pkt_protected_cnt;
};
struct rte_security_ipsec_stats
{
  uint64_t ipackets;
  uint64_t opackets;
  uint64_t ibytes;
  uint64_t obytes;
  uint64_t ierrors;
  uint64_t oerrors;
  uint64_t reserved1;
  uint64_t reserved2;
};
struct rte_security_pdcp_stats
{
  uint64_t reserved;
};
struct rte_security_docsis_stats
{
  uint64_t reserved;
};
struct rte_security_stats
{
  enum rte_security_session_protocol protocol;
  union
  {
    struct rte_security_macsec_secy_stats macsec;
    struct rte_security_ipsec_stats ipsec;
    struct rte_security_pdcp_stats pdcp;
    struct rte_security_docsis_stats docsis;
  };
};
int rte_security_session_stats_get(void *instance,
                                   void *sess, struct rte_security_stats *stats);
int rte_security_macsec_sa_stats_get(void *instance,
                                     uint16_t sa_id,
                                     enum rte_security_macsec_direction dir,
                                     struct rte_security_macsec_sa_stats *stats);
int rte_security_macsec_sc_stats_get(void *instance,
                                     uint16_t sc_id,
                                     enum rte_security_macsec_direction dir,
                                     struct rte_security_macsec_sc_stats *stats);
struct rte_security_capability
{
  enum rte_security_session_action_type action;
  enum rte_security_session_protocol protocol;
  union
  {
    struct
    {
      enum rte_security_ipsec_sa_protocol proto;
      enum rte_security_ipsec_sa_mode mode;
      enum rte_security_ipsec_sa_direction direction;
      struct rte_security_ipsec_sa_options options;
      uint32_t replay_win_sz_max;
    } ipsec;
    struct
    {
      uint16_t mtu;
      enum rte_security_macsec_alg alg;
      uint16_t max_nb_sc;
      uint16_t max_nb_sa;
      uint16_t max_nb_sess;
      uint32_t replay_win_sz;
      uint16_t relative_sectag_insert : 1;
      uint16_t fixed_sectag_insert : 1;
      uint16_t icv_include_da_sa : 1;
      uint16_t ctrl_port_enable : 1;
      uint16_t preserve_sectag : 1;
      uint16_t preserve_icv : 1;
      uint16_t validate_frames : 1;
      uint16_t re_key : 1;
      uint16_t anti_replay : 1;
      uint16_t reserved : 7;
    } macsec;
    struct
    {
      enum rte_security_pdcp_domain domain;
      uint32_t capa_flags;
    } pdcp;
    struct
    {
      enum rte_security_docsis_direction direction;
    } docsis;
    struct
    {
      enum rte_security_tls_version ver;
      enum rte_security_tls_sess_type type;
      uint32_t ar_win_size;
    } tls_record;
  };
  const struct rte_cryptodev_capabilities *crypto_capabilities;
  uint32_t ol_flags;
};
struct rte_security_capability_idx
{
  enum rte_security_session_action_type action;
  enum rte_security_session_protocol protocol;
  union
  {
    struct
    {
      enum rte_security_ipsec_sa_protocol proto;
      enum rte_security_ipsec_sa_mode mode;
      enum rte_security_ipsec_sa_direction direction;
    } ipsec;
    struct
    {
      enum rte_security_pdcp_domain domain;
      uint32_t capa_flags;
    } pdcp;
    struct
    {
      enum rte_security_docsis_direction direction;
    } docsis;
    struct
    {
      enum rte_security_macsec_alg alg;
    } macsec;
    struct
    {
      enum rte_security_tls_version ver;
      enum rte_security_tls_sess_type type;
    } tls_record;
  };
};
const struct rte_security_capability *rte_security_capabilities_get(void
                                                                        *instance);
const struct rte_security_capability *rte_security_capability_get(void
                                                                      *instance,
                                                                  struct
                                                                  rte_security_capability_idx
                                                                      *idx);
__attribute__((section(".text.experimental"))) int
rte_security_rx_inject_configure(void *ctx, uint16_t port_id,
                                 _Bool enable);
__attribute__((section(".text.experimental"))) uint16_t
rte_security_inb_pkt_rx_inject(void *ctx, struct rte_mbuf **pkts,
                               void **sess, uint16_t nb_pkts);
struct rte_security_session
{
  uint64_t opaque_data;
  uint64_t fast_mdata;
  rte_iova_t driver_priv_data_iova;
  _Alignas(64) uint8_t driver_priv_data[];
};
struct rte_security_ctx
{
  void *device;
  const struct rte_security_ops *ops;
  uint32_t flags;
  uint16_t sess_cnt;
  uint16_t macsec_sc_cnt;
  uint16_t macsec_sa_cnt;
};
typedef int (*security_session_create_t)(void *device,
                                         struct
                                         rte_security_session_conf
                                             *conf,
                                         struct rte_security_session
                                             *sess);
typedef int (*security_session_destroy_t)(void *device,
                                          struct rte_security_session
                                              *sess);
typedef int (*security_session_update_t)(void *device,
                                         struct rte_security_session
                                             *sess,
                                         struct
                                         rte_security_session_conf
                                             *conf);
typedef int (*security_macsec_sc_create_t)(void *device,
                                           struct rte_security_macsec_sc
                                               *conf);
typedef int (*security_macsec_sc_destroy_t)(void *device,
                                            uint16_t sc_id,
                                            enum rte_security_macsec_direction
                                                dir);
typedef int (*security_macsec_sa_create_t)(void *device,
                                           struct rte_security_macsec_sa
                                               *conf);
typedef int (*security_macsec_sa_destroy_t)(void *device,
                                            uint16_t sa_id,
                                            enum rte_security_macsec_direction
                                                dir);
typedef unsigned int (*security_session_get_size)(void *device);
typedef int (*security_session_stats_get_t)(void *device,
                                            struct rte_security_session
                                                *sess,
                                            struct rte_security_stats
                                                *stats);
typedef int (*security_macsec_sc_stats_get_t)(void *device,
                                              uint16_t sc_id,
                                              enum rte_security_macsec_direction
                                                  dir,
                                              struct
                                              rte_security_macsec_sc_stats
                                                  *stats);
typedef int (*security_macsec_sa_stats_get_t)(void *device,
                                              uint16_t sa_id,
                                              enum rte_security_macsec_direction
                                                  dir,
                                              struct
                                              rte_security_macsec_sa_stats
                                                  *stats);
__attribute__((section(".text.internal"))) int rte_security_dynfield_register(void);
__attribute__((section(".text.internal"))) int rte_security_oop_dynfield_register(void);
typedef int (*security_set_pkt_metadata_t)(void *device,
                                           struct rte_security_session
                                               *sess,
                                           struct rte_mbuf *mb,
                                           void *params);
typedef const struct rte_security_capability
    *(*security_capabilities_get_t)(void *device);
typedef int (*security_rx_inject_configure)(void *device,
                                            uint16_t port_id,
                                            _Bool enable);
typedef uint16_t (*security_inb_pkt_rx_inject)(void *device,
                                               struct rte_mbuf **pkts,
                                               struct
                                               rte_security_session
                                                   **sess,
                                               uint16_t nb_pkts);
struct rte_security_ops
{
  security_session_create_t session_create;
  security_session_update_t session_update;
  security_session_get_size session_get_size;
  security_session_stats_get_t session_stats_get;
  security_session_destroy_t session_destroy;
  security_set_pkt_metadata_t set_pkt_metadata;
  security_capabilities_get_t capabilities_get;
  security_macsec_sc_create_t macsec_sc_create;
  security_macsec_sc_destroy_t macsec_sc_destroy;
  security_macsec_sa_create_t macsec_sa_create;
  security_macsec_sa_destroy_t macsec_sa_destroy;
  security_macsec_sc_stats_get_t macsec_sc_stats_get;
  security_macsec_sa_stats_get_t macsec_sa_stats_get;
  security_rx_inject_configure rx_inject_configure;
  security_inb_pkt_rx_inject inb_pkt_rx_inject;
};
struct iavf_tx_ipsec_desc
{
  union
  {
    struct
    {
      uint64_t qw0;
      uint64_t qw1;
    };
    struct
    {
      uint16_t l4payload_length;
      uint32_t esn;
      uint16_t trailer_length;
      u8 type : 4;
      u8 rsv : 1;
      u8 udp : 1;
      u8 ivlen : 2;
      u8 next_header;
      uint16_t ipv6_ext_hdr_length;
      uint32_t said;
    } __attribute__((__packed__));
  };
} __attribute__((__packed__));
enum iavf_ipsec_iv_len
{
  IAVF_IPSEC_IV_LEN_NONE,
  IAVF_IPSEC_IV_LEN_DW,
  IAVF_IPSEC_IV_LEN_DDW,
  IAVF_IPSEC_IV_LEN_QDW,
};
struct iavf_ipsec_crypto_pkt_metadata
{
  uint32_t sa_idx;
  uint8_t ol_flags;
  uint8_t len_iv;
  uint8_t ctx_desc_ipsec_params;
  uint8_t esp_trailer_len;
  uint16_t l4_payload_len;
  uint8_t ipv6_ext_hdrs_len;
  uint8_t next_proto;
  uint32_t esn;
} __attribute__((__packed__));
int iavf_ipsec_crypto_supported(struct iavf_adapter *adapter);
int iavf_security_ctx_create(struct iavf_adapter *adapter);
int iavf_security_init(struct iavf_adapter *adapter);
int iavf_ipsec_crypto_set_security_capabililites(struct
                                                 iavf_security_ctx
                                                     *iavf_sctx,
                                                 struct
                                                 virtchnl_ipsec_cap
                                                     *virtchl_capabilities);
int iavf_security_get_pkt_md_offset(struct iavf_adapter *adapter);
int iavf_security_ctx_destroy(struct iavf_adapter *adapterv);
uint32_t
iavf_ipsec_crypto_action_valid(struct rte_eth_dev *ethdev,
                               const struct rte_security_session *session,
                               uint32_t spi);
int iavf_ipsec_crypto_inbound_security_policy_add(struct iavf_adapter
                                                      *adapter,
                                                  uint32_t esp_spi,
                                                  uint8_t is_v4,
                                                  rte_be32_t v4_dst_addr,
                                                  uint8_t *v6_dst_addr,
                                                  uint8_t drop,
                                                  _Bool
                                                      is_udp,
                                                  uint16_t udp_port);
int iavf_ipsec_crypto_security_policy_delete(struct iavf_adapter *adapter,
                                             uint8_t is_v4,
                                             uint32_t flow_id);
int iavf_security_get_pkt_md_offset(struct iavf_adapter *adapter);
union rte_pmd_ifd_proto_xtr_metadata
{
  uint32_t metadata;
  struct
  {
    uint16_t data0;
    uint16_t data1;
  } raw;
  struct
  {
    uint16_t stag_vid : 12, stag_dei : 1, stag_pcp : 3;
    uint16_t ctag_vid : 12, ctag_dei : 1, ctag_pcp : 3;
  } vlan;
  struct
  {
    uint16_t protocol : 8, ttl : 8;
    uint16_t tos : 8, ihl : 4, version : 4;
  } ipv4;
  struct
  {
    uint16_t hoplimit : 8, nexthdr : 8;
    uint16_t flowhi4 : 4, tc : 8, version : 4;
  } ipv6;
  struct
  {
    uint16_t flowlo16;
    uint16_t flowhi4 : 4, tc : 8, version : 4;
  } ipv6_flow;
  struct
  {
    uint16_t fin : 1,
        syn : 1, rst : 1, psh : 1, ack : 1, urg : 1, ece : 1, cwr : 1, res1 : 4, doff : 4;
    uint16_t rsvd;
  } tcp;
  uint32_t ip_ofs;
};
extern int rte_pmd_ifd_dynfield_proto_xtr_metadata_offs;
extern uint64_t rte_pmd_ifd_dynflag_proto_xtr_vlan_mask;
extern uint64_t rte_pmd_ifd_dynflag_proto_xtr_ipv4_mask;
extern uint64_t rte_pmd_ifd_dynflag_proto_xtr_ipv6_mask;
extern uint64_t rte_pmd_ifd_dynflag_proto_xtr_ipv6_flow_mask;
extern uint64_t rte_pmd_ifd_dynflag_proto_xtr_tcp_mask;
extern uint64_t rte_pmd_ifd_dynflag_proto_xtr_ip_offset_mask;
extern uint64_t rte_pmd_ifd_dynflag_proto_xtr_ipsec_crypto_said_mask;
__attribute__((section(".text.experimental"))) static inline __attribute__((always_inline)) int rte_pmd_ifd_dynf_proto_xtr_metadata_avail(void)
{
  return rte_pmd_ifd_dynfield_proto_xtr_metadata_offs != -1;
}

__attribute__((section(".text.experimental"))) static inline __attribute__((always_inline)) uint32_t
rte_pmd_ifd_dynf_proto_xtr_metadata_get(struct rte_mbuf *m)
{
  return *((uint32_t *)((uintptr_t)((m)) +
                        (rte_pmd_ifd_dynfield_proto_xtr_metadata_offs)));
}

__attribute__((section(".text.experimental"))) static inline void
rte_pmd_ifd_dump_proto_xtr_metadata(struct rte_mbuf *m)
{
  union rte_pmd_ifd_proto_xtr_metadata data;
  if (!rte_pmd_ifd_dynf_proto_xtr_metadata_avail())
    return;
  data.metadata = rte_pmd_ifd_dynf_proto_xtr_metadata_get(m);
  if (m->ol_flags & (rte_pmd_ifd_dynflag_proto_xtr_vlan_mask))
    printf(" - Flexible descriptor's Metadata: [0x%04x:0x%04x],"
           "vlan,stag=%u:%u:%u,ctag=%u:%u:%u",
           data.raw.data0, data.raw.data1,
           data.vlan.stag_pcp,
           data.vlan.stag_dei,
           data.vlan.stag_vid,
           data.vlan.ctag_pcp, data.vlan.ctag_dei, data.vlan.ctag_vid);
  else if (m->ol_flags & (rte_pmd_ifd_dynflag_proto_xtr_ipv4_mask))
    printf(" - Flexible descriptor's Metadata: [0x%04x:0x%04x],"
           "ipv4,ver=%u,hdrlen=%u,tos=%u,ttl=%u,proto=%u",
           data.raw.data0, data.raw.data1,
           data.ipv4.version,
           data.ipv4.ihl, data.ipv4.tos, data.ipv4.ttl, data.ipv4.protocol);
  else if (m->ol_flags & (rte_pmd_ifd_dynflag_proto_xtr_ipv6_mask))
    printf(" - Flexible descriptor's Metadata: [0x%04x:0x%04x],"
           "ipv6,ver=%u,tc=%u,flow_hi4=0x%x,nexthdr=%u,hoplimit=%u",
           data.raw.data0, data.raw.data1,
           data.ipv6.version,
           data.ipv6.tc,
           data.ipv6.flowhi4, data.ipv6.nexthdr, data.ipv6.hoplimit);
  else if (m->ol_flags & (rte_pmd_ifd_dynflag_proto_xtr_ipv6_flow_mask))
    printf(" - Flexible descriptor's Metadata: [0x%04x:0x%04x],"
           "ipv6_flow,ver=%u,tc=%u,flow=0x%x%04x",
           data.raw.data0, data.raw.data1,
           data.ipv6_flow.version,
           data.ipv6_flow.tc,
           data.ipv6_flow.flowhi4, data.ipv6_flow.flowlo16);
  else if (m->ol_flags & (rte_pmd_ifd_dynflag_proto_xtr_tcp_mask))
    printf(" - Flexible descriptor's Metadata: [0x%04x:0x%04x],"
           "tcp,doff=%u,flags=%s%s%s%s%s%s%s%s",
           data.raw.data0, data.raw.data1,
           data.tcp.doff,
           data.tcp.cwr ? "C" : "",
           data.tcp.ece ? "E" : "",
           data.tcp.urg ? "U" : "",
           data.tcp.ack ? "A" : "",
           data.tcp.psh ? "P" : "",
           data.tcp.rst ? "R" : "",
           data.tcp.syn ? "S" : "", data.tcp.fin ? "F" : "");
  else if (m->ol_flags & (rte_pmd_ifd_dynflag_proto_xtr_ip_offset_mask))
    printf(" - Flexible descriptor's Extraction: ip_offset=%u", data.ip_ofs);
}

static uint16_t vxlan_gpe_udp_port = 4790;
static uint16_t geneve_udp_port = 6081;
struct simple_gre_hdr
{
  uint16_t flags;
  uint16_t proto;
} __attribute__((__packed__));
struct offload_info
{
  uint16_t ethertype;
  uint8_t gso_enable;
  uint16_t l2_len;
  uint16_t l3_len;
  uint16_t l4_len;
  uint8_t l4_proto;
  uint8_t is_tunnel;
  uint16_t outer_ethertype;
  uint16_t outer_l2_len;
  uint16_t outer_l3_len;
  uint8_t outer_l4_proto;
  uint16_t tso_segsz;
  uint16_t tunnel_tso_segsz;
  uint32_t pkt_len;
};
int rte_pmd_ifd_dynfield_proto_xtr_metadata_offs = -1;
uint64_t rte_pmd_ifd_dynflag_proto_xtr_vlan_mask;
uint64_t rte_pmd_ifd_dynflag_proto_xtr_ipv4_mask;
uint64_t rte_pmd_ifd_dynflag_proto_xtr_ipv6_mask;
uint64_t rte_pmd_ifd_dynflag_proto_xtr_ipv6_flow_mask;
uint64_t rte_pmd_ifd_dynflag_proto_xtr_tcp_mask;
uint64_t rte_pmd_ifd_dynflag_proto_xtr_ip_offset_mask;
uint64_t rte_pmd_ifd_dynflag_proto_xtr_ipsec_crypto_said_mask;
uint8_t
iavf_proto_xtr_type_to_rxdid(uint8_t flex_type)
{
  static uint8_t rxdid_map[] = {
      [IAVF_PROTO_XTR_NONE] = IAVF_RXDID_COMMS_OVS_1,
      [IAVF_PROTO_XTR_VLAN] = IAVF_RXDID_COMMS_AUX_VLAN,
      [IAVF_PROTO_XTR_IPV4] = IAVF_RXDID_COMMS_AUX_IPV4,
      [IAVF_PROTO_XTR_IPV6] = IAVF_RXDID_COMMS_AUX_IPV6,
      [IAVF_PROTO_XTR_IPV6_FLOW] = IAVF_RXDID_COMMS_AUX_IPV6_FLOW,
      [IAVF_PROTO_XTR_TCP] = IAVF_RXDID_COMMS_AUX_TCP,
      [IAVF_PROTO_XTR_IP_OFFSET] = IAVF_RXDID_COMMS_AUX_IP_OFFSET,
      [IAVF_PROTO_XTR_IPSEC_CRYPTO_SAID] = IAVF_RXDID_COMMS_IPSEC_CRYPTO,
  };
  return flex_type < (sizeof(rxdid_map) / sizeof((rxdid_map)[0])) ? rxdid_map[flex_type] : IAVF_RXDID_COMMS_OVS_1;
}

static int
iavf_monitor_callback(const uint64_t value,
                      const uint64_t arg[4] __attribute__((__unused__)))
{
  const uint64_t m = (1 << IAVF_RX_DESC_STATUS_DD_SHIFT);
  return (value & m) == m ? -1 : 0;
}

int iavf_get_monitor_addr(void *rx_queue, struct rte_power_monitor_cond *pmc)
{
  struct iavf_rx_queue *rxq = rx_queue;
  volatile union iavf_32byte_rx_desc *rxdp;
  uint16_t desc;
  desc = rxq->rx_tail;
  rxdp = &rxq->rx_ring[desc];
  pmc->addr = &rxdp->wb.qword1.status_error_len;
  pmc->fn = iavf_monitor_callback;
  pmc->size = sizeof(uint64_t);
  return 0;
}

static inline int
check_rx_thresh(uint16_t nb_desc, uint16_t thresh)
{
  if (thresh >= nb_desc)
  {
    rte_log(4U, iavf_logtype_init,
            "%s(): "
            "rx_free_thresh (%u) must be less than %u"
            "\n",
            __func__, thresh, nb_desc);
    return -22;
  }
  return 0;
}

static inline int
check_tx_thresh(uint16_t nb_desc, uint16_t tx_rs_thresh,
                uint16_t tx_free_thresh)
{
  if (tx_rs_thresh >= (nb_desc - 2))
  {
    rte_log(4U, iavf_logtype_init,
            "%s(): "
            "tx_rs_thresh (%u) must be less than the "
            "number of TX descriptors (%u) minus 2"
            "\n",
            __func__,
            tx_rs_thresh, nb_desc);
    return -22;
  }
  if (tx_free_thresh >= (nb_desc - 3))
  {
    rte_log(4U, iavf_logtype_init,
            "%s(): "
            "tx_free_thresh (%u) must be less than the "
            "number of TX descriptors (%u) minus 3."
            "\n",
            __func__,
            tx_free_thresh, nb_desc);
    return -22;
  }
  if (tx_rs_thresh > tx_free_thresh)
  {
    rte_log(4U, iavf_logtype_init,
            "%s(): "
            "tx_rs_thresh (%u) must be less than or "
            "equal to tx_free_thresh (%u)."
            "\n",
            __func__, tx_rs_thresh,
            tx_free_thresh);
    return -22;
  }
  if ((nb_desc % tx_rs_thresh) != 0)
  {
    rte_log(4U, iavf_logtype_init,
            "%s(): "
            "tx_rs_thresh (%u) must be a divisor of the "
            "number of TX descriptors (%u)."
            "\n",
            __func__, tx_rs_thresh,
            nb_desc);
    return -22;
  }
  return 0;
}

static inline _Bool
check_rx_vec_allow(struct iavf_rx_queue *rxq)
{
  if (rxq->rx_free_thresh >= 32 && rxq->nb_rx_desc % rxq->rx_free_thresh == 0)
  {
    rte_log(8U, iavf_logtype_init,
            "%s(): "
            "Vector Rx can be enabled on this rxq."
            "\n",
            __func__);
    return 1;
  }
  rte_log(8U, iavf_logtype_init,
          "%s(): "
          "Vector Rx cannot be enabled on this rxq."
          "\n",
          __func__);
  return 0;
}

static inline _Bool
check_tx_vec_allow(struct iavf_tx_queue *txq)
{
  if (!(txq->offloads &
        ((1UL << (0)) | (1UL << (8)) | (1UL << (15)) | (1UL << (5)) |
         (1UL << (9)) | (1UL << (10)) | (1UL << (11)) | (1UL << (12)) | (1UL << (17)))) &&
      txq->rs_thresh >= 32 && txq->rs_thresh <= 64)
  {
    rte_log(8U, iavf_logtype_init,
            "%s(): "
            "Vector tx can be enabled on this txq."
            "\n",
            __func__);
    return 1;
  }
  rte_log(8U, iavf_logtype_init,
          "%s(): "
          "Vector Tx cannot be enabled on this txq."
          "\n",
          __func__);
  return 0;
}

static inline _Bool
check_rx_bulk_allow(struct iavf_rx_queue *rxq)
{
  int ret = 1;
  if (!(rxq->rx_free_thresh >= 32))
  {
    rte_log(8U, iavf_logtype_init,
            "%s(): "
            "Rx Burst Bulk Alloc Preconditions: "
            "rxq->rx_free_thresh=%d, "
            "IAVF_RX_MAX_BURST=%d"
            "\n",
            __func__, rxq->rx_free_thresh, 32);
    ret = 0;
  }
  else if (rxq->nb_rx_desc % rxq->rx_free_thresh != 0)
  {
    rte_log(8U, iavf_logtype_init,
            "%s(): "
            "Rx Burst Bulk Alloc Preconditions: "
            "rxq->nb_rx_desc=%d, "
            "rxq->rx_free_thresh=%d"
            "\n",
            __func__,
            rxq->nb_rx_desc, rxq->rx_free_thresh);
    ret = 0;
  }
  return ret;
}

static inline void
reset_rx_queue(struct iavf_rx_queue *rxq)
{
  uint16_t len;
  uint32_t i;
  if (!rxq)
    return;
  len = rxq->nb_rx_desc + 32;
  for (i = 0; i < len * sizeof(union iavf_32byte_rx_desc); i++)
    ((volatile char *)rxq->rx_ring)[i] = 0;
  memset(&rxq->fake_mbuf, 0x0, sizeof(rxq->fake_mbuf));
  for (i = 0; i < 32; i++)
    rxq->sw_ring[rxq->nb_rx_desc + i] = &rxq->fake_mbuf;
  rxq->rx_nb_avail = 0;
  rxq->rx_next_avail = 0;
  rxq->rx_free_trigger = (uint16_t)(rxq->rx_free_thresh - 1);
  rxq->rx_tail = 0;
  rxq->nb_rx_hold = 0;
  rte_pktmbuf_free(rxq->pkt_first_seg);
  rxq->pkt_first_seg = ((void *)0);
  rxq->pkt_last_seg = ((void *)0);
  rxq->rxrearm_nb = 0;
  rxq->rxrearm_start = 0;
}

static inline void
reset_tx_queue(struct iavf_tx_queue *txq)
{
  struct iavf_tx_entry *txe;
  uint32_t i, size;
  uint16_t prev;
  if (!txq)
  {
    rte_log(8U, iavf_logtype_driver,
            "%s(): "
            "Pointer to txq is NULL"
            "\n",
            __func__);
    return;
  }
  txe = txq->sw_ring;
  size = sizeof(struct iavf_tx_desc) * txq->nb_tx_desc;
  for (i = 0; i < size; i++)
    ((volatile char *)txq->tx_ring)[i] = 0;
  prev = (uint16_t)(txq->nb_tx_desc - 1);
  for (i = 0; i < txq->nb_tx_desc; i++)
  {
    txq->tx_ring[i].cmd_type_offset_bsz = (IAVF_TX_DESC_DTYPE_DESC_DONE);
    txe[i].mbuf = ((void *)0);
    txe[i].last_id = i;
    txe[prev].next_id = i;
    prev = i;
  }
  txq->tx_tail = 0;
  txq->nb_used = 0;
  txq->last_desc_cleaned = txq->nb_tx_desc - 1;
  txq->nb_free = txq->nb_tx_desc - 1;
  txq->next_dd = txq->rs_thresh - 1;
  txq->next_rs = txq->rs_thresh - 1;
}

static int
alloc_rxq_mbufs(struct iavf_rx_queue *rxq)
{
  volatile union iavf_32byte_rx_desc *rxd;
  struct rte_mbuf *mbuf = ((void *)0);
  uint64_t dma_addr;
  uint16_t i, j;
  for (i = 0; i < rxq->nb_rx_desc; i++)
  {
    mbuf = rte_mbuf_raw_alloc(rxq->mp);
    if (__builtin_expect(!!(!mbuf), 0))
    {
      for (j = 0; j < i; j++)
      {
        rte_pktmbuf_free_seg(rxq->sw_ring[j]);
        rxq->sw_ring[j] = ((void *)0);
      }
      rte_log(4U, iavf_logtype_driver,
              "%s(): "
              "Failed to allocate mbuf for RX"
              "\n",
              __func__);
      return -12;
    }
    rte_mbuf_refcnt_set(mbuf, 1);
    mbuf->next = ((void *)0);
    mbuf->data_off = 128;
    mbuf->nb_segs = 1;
    mbuf->port = rxq->port_id;
    dma_addr = (rte_mbuf_data_iova_default(mbuf));
    rxd = &rxq->rx_ring[i];
    rxd->read.pkt_addr = dma_addr;
    rxd->read.hdr_addr = 0;
    rxd->read.rsvd1 = 0;
    rxd->read.rsvd2 = 0;
    rxq->sw_ring[i] = mbuf;
  }
  return 0;
}

static inline void
release_rxq_mbufs(struct iavf_rx_queue *rxq)
{
  uint16_t i;
  if (!rxq->sw_ring)
    return;
  for (i = 0; i < rxq->nb_rx_desc; i++)
  {
    if (rxq->sw_ring[i])
    {
      rte_pktmbuf_free_seg(rxq->sw_ring[i]);
      rxq->sw_ring[i] = ((void *)0);
    }
  }
  if (rxq->rx_nb_avail == 0)
    return;
  for (i = 0; i < rxq->rx_nb_avail; i++)
  {
    struct rte_mbuf *mbuf;
    mbuf = rxq->rx_stage[rxq->rx_next_avail + i];
    rte_pktmbuf_free_seg(mbuf);
  }
  rxq->rx_nb_avail = 0;
}

static inline void
release_txq_mbufs(struct iavf_tx_queue *txq)
{
  uint16_t i;
  if (!txq || !txq->sw_ring)
  {
    rte_log(8U, iavf_logtype_driver,
            "%s(): "
            "Pointer to rxq or sw_ring is NULL"
            "\n",
            __func__);
    return;
  }
  for (i = 0; i < txq->nb_tx_desc; i++)
  {
    if (txq->sw_ring[i].mbuf)
    {
      rte_pktmbuf_free_seg(txq->sw_ring[i].mbuf);
      txq->sw_ring[i].mbuf = ((void *)0);
    }
  }
}

static const struct iavf_rxq_ops iavf_rxq_release_mbufs_ops[] = {
    [IAVF_REL_MBUFS_DEFAULT].release_mbufs = release_rxq_mbufs,
};

static const struct iavf_txq_ops iavf_txq_release_mbufs_ops[] = {
    [IAVF_REL_MBUFS_DEFAULT].release_mbufs = release_txq_mbufs,
};

static inline void
iavf_rxd_to_pkt_fields_by_comms_ovs(__attribute__((__unused__)) struct iavf_rx_queue *rxq,
                                    struct rte_mbuf *mb,
                                    volatile union iavf_32b_rx_flex_desc
                                        *rxdp)
{
  volatile struct iavf_32b_rx_flex_desc_comms_ovs *desc =
      (volatile struct iavf_32b_rx_flex_desc_comms_ovs *)rxdp;
  uint16_t stat_err;
  if (desc->flow_id != 0xFFFFFFFF)
  {
    mb->ol_flags |= (1ULL << 2) | (1ULL << 13);
    mb->hash.fdir.hi = (desc->flow_id);
  }
  stat_err = (desc->status_error0);
  if (__builtin_expect(!!(stat_err & (1 << IAVF_RX_FLEX_DESC_STATUS0_RSS_VALID_S)), 1))
  {
    mb->ol_flags |= (1ULL << 1);
    mb->hash.rss = (desc->rss_hash);
  }
}

static inline void
iavf_rxd_to_pkt_fields_by_comms_aux_v1(struct iavf_rx_queue *rxq,
                                       struct rte_mbuf *mb,
                                       volatile union iavf_32b_rx_flex_desc
                                           *rxdp)
{
  volatile struct iavf_32b_rx_flex_desc_comms *desc =
      (volatile struct iavf_32b_rx_flex_desc_comms *)rxdp;
  uint16_t stat_err;
  stat_err = (desc->status_error0);
  if (__builtin_expect(!!(stat_err & (1 << IAVF_RX_FLEX_DESC_STATUS0_RSS_VALID_S)), 1))
  {
    mb->ol_flags |= (1ULL << 1);
    mb->hash.rss = (desc->rss_hash);
  }
  if (desc->flow_id != 0xFFFFFFFF)
  {
    mb->ol_flags |= (1ULL << 2) | (1ULL << 13);
    mb->hash.fdir.hi = (desc->flow_id);
  }
  if (rxq->xtr_ol_flag)
  {
    uint32_t metadata = 0;
    stat_err = (desc->status_error1);
    if (stat_err & (1 << IAVF_RX_FLEX_DESC_STATUS1_XTRMD4_VALID_S))
      metadata = (desc->flex_ts.flex.aux0);
    if (stat_err & (1 << IAVF_RX_FLEX_DESC_STATUS1_XTRMD5_VALID_S))
      metadata |= (desc->flex_ts.flex.aux1) << 16;
    if (metadata)
    {
      mb->ol_flags |= rxq->xtr_ol_flag;
      *((uint32_t *)((uintptr_t)((mb)) +
                     (rte_pmd_ifd_dynfield_proto_xtr_metadata_offs))) =
          metadata;
    }
  }
}

static inline void
iavf_rxd_to_pkt_fields_by_comms_aux_v2(struct iavf_rx_queue *rxq,
                                       struct rte_mbuf *mb,
                                       volatile union iavf_32b_rx_flex_desc
                                           *rxdp)
{
  volatile struct iavf_32b_rx_flex_desc_comms *desc =
      (volatile struct iavf_32b_rx_flex_desc_comms *)rxdp;
  uint16_t stat_err;
  stat_err = (desc->status_error0);
  if (__builtin_expect(!!(stat_err & (1 << IAVF_RX_FLEX_DESC_STATUS0_RSS_VALID_S)), 1))
  {
    mb->ol_flags |= (1ULL << 1);
    mb->hash.rss = (desc->rss_hash);
  }
  if (desc->flow_id != 0xFFFFFFFF)
  {
    mb->ol_flags |= (1ULL << 2) | (1ULL << 13);
    mb->hash.fdir.hi = (desc->flow_id);
  }
  if (rxq->xtr_ol_flag)
  {
    uint32_t metadata = 0;
    if (desc->flex_ts.flex.aux0 != 0xFFFF)
      metadata = (desc->flex_ts.flex.aux0);
    else if (desc->flex_ts.flex.aux1 != 0xFFFF)
      metadata = (desc->flex_ts.flex.aux1);
    if (metadata)
    {
      mb->ol_flags |= rxq->xtr_ol_flag;
      *((uint32_t *)((uintptr_t)((mb)) +
                     (rte_pmd_ifd_dynfield_proto_xtr_metadata_offs))) =
          metadata;
    }
  }
}

static const iavf_rxd_to_pkt_fields_t rxd_to_pkt_fields_ops[IAVF_RXDID_LAST + 1] = {
    [IAVF_RXDID_LEGACY_0] = iavf_rxd_to_pkt_fields_by_comms_ovs,
    [IAVF_RXDID_LEGACY_1] = iavf_rxd_to_pkt_fields_by_comms_ovs,
    [IAVF_RXDID_COMMS_AUX_VLAN] = iavf_rxd_to_pkt_fields_by_comms_aux_v1,
    [IAVF_RXDID_COMMS_AUX_IPV4] = iavf_rxd_to_pkt_fields_by_comms_aux_v1,
    [IAVF_RXDID_COMMS_AUX_IPV6] = iavf_rxd_to_pkt_fields_by_comms_aux_v1,
    [IAVF_RXDID_COMMS_AUX_IPV6_FLOW] = iavf_rxd_to_pkt_fields_by_comms_aux_v1,
    [IAVF_RXDID_COMMS_AUX_TCP] = iavf_rxd_to_pkt_fields_by_comms_aux_v1,
    [IAVF_RXDID_COMMS_AUX_IP_OFFSET] = iavf_rxd_to_pkt_fields_by_comms_aux_v2,
    [IAVF_RXDID_COMMS_IPSEC_CRYPTO] = iavf_rxd_to_pkt_fields_by_comms_aux_v2,
    [IAVF_RXDID_COMMS_OVS_1] = iavf_rxd_to_pkt_fields_by_comms_ovs,
};

static void
iavf_select_rxd_to_pkt_fields_handler(struct iavf_rx_queue *rxq,
                                      uint32_t rxdid)
{
  rxq->rxdid = rxdid;
  switch (rxdid)
  {
  case IAVF_RXDID_COMMS_AUX_VLAN:
    rxq->xtr_ol_flag = rte_pmd_ifd_dynflag_proto_xtr_vlan_mask;
    break;
  case IAVF_RXDID_COMMS_AUX_IPV4:
    rxq->xtr_ol_flag = rte_pmd_ifd_dynflag_proto_xtr_ipv4_mask;
    break;
  case IAVF_RXDID_COMMS_AUX_IPV6:
    rxq->xtr_ol_flag = rte_pmd_ifd_dynflag_proto_xtr_ipv6_mask;
    break;
  case IAVF_RXDID_COMMS_AUX_IPV6_FLOW:
    rxq->xtr_ol_flag = rte_pmd_ifd_dynflag_proto_xtr_ipv6_flow_mask;
    break;
  case IAVF_RXDID_COMMS_AUX_TCP:
    rxq->xtr_ol_flag = rte_pmd_ifd_dynflag_proto_xtr_tcp_mask;
    break;
  case IAVF_RXDID_COMMS_AUX_IP_OFFSET:
    rxq->xtr_ol_flag = rte_pmd_ifd_dynflag_proto_xtr_ip_offset_mask;
    break;
  case IAVF_RXDID_COMMS_IPSEC_CRYPTO:
    rxq->xtr_ol_flag = rte_pmd_ifd_dynflag_proto_xtr_ipsec_crypto_said_mask;
    break;
  case IAVF_RXDID_COMMS_OVS_1:
  case IAVF_RXDID_LEGACY_0:
  case IAVF_RXDID_LEGACY_1:
    break;
  default:
    rxq->rxdid = IAVF_RXDID_COMMS_OVS_1;
    break;
  }
  if (!rte_pmd_ifd_dynf_proto_xtr_metadata_avail())
    rxq->xtr_ol_flag = 0;
}

int iavf_dev_rx_queue_setup(struct rte_eth_dev *dev, uint16_t queue_idx,
                            uint16_t nb_desc, unsigned int socket_id,
                            const struct rte_eth_rxconf *rx_conf,
                            struct rte_mempool *mp)
{
  struct iavf_hw *hw =
      (&((struct iavf_adapter *)dev->data->dev_private)->hw);
  struct iavf_adapter *ad = ((struct iavf_adapter *)dev->data->dev_private);
  struct iavf_info *vf =
      (&((struct iavf_adapter *)dev->data->dev_private)->vf);
  struct iavf_vsi *vsi = &vf->vsi;
  struct iavf_rx_queue *rxq;
  const struct rte_memzone *mz;
  uint32_t ring_size;
  uint8_t proto_xtr;
  uint16_t len;
  uint16_t rx_free_thresh;
  uint64_t offloads;
  rte_log(8U, iavf_logtype_init, "%s(): "
                                 " >>"
                                 "\n",
          __func__);
  if (ad->closed)
    return -5;
  offloads = rx_conf->offloads | dev->data->dev_conf.rxmode.offloads;
  if (nb_desc % 32 != 0 || nb_desc > 4096 || nb_desc < 64)
  {
    rte_log(4U, iavf_logtype_init,
            "%s(): "
            "Number (%u) of receive descriptors is "
            "invalid"
            "\n",
            __func__, nb_desc);
    return -22;
  }
  rx_free_thresh = (rx_conf->rx_free_thresh == 0) ? 32 : rx_conf->rx_free_thresh;
  if (check_rx_thresh(nb_desc, rx_free_thresh) != 0)
    return -22;
  if (dev->data->rx_queues[queue_idx])
  {
    iavf_dev_rx_queue_release(dev, queue_idx);
    dev->data->rx_queues[queue_idx] = ((void *)0);
  }
  rxq = rte_zmalloc_socket("iavf rxq",
                           sizeof(struct iavf_rx_queue), 64, socket_id);
  if (!rxq)
  {
    rte_log(4U, iavf_logtype_init,
            "%s(): "
            "Failed to allocate memory for "
            "rx queue data structure"
            "\n",
            __func__);
    return -12;
  }
  if (vf->vf_res->vf_cap_flags & (1UL << (26)))
  {
    proto_xtr = vf->proto_xtr ? vf->proto_xtr[queue_idx] : IAVF_PROTO_XTR_NONE;
    rxq->rxdid = iavf_proto_xtr_type_to_rxdid(proto_xtr);
    rxq->proto_xtr = proto_xtr;
  }
  else
  {
    rxq->rxdid = IAVF_RXDID_LEGACY_1;
    rxq->proto_xtr = IAVF_PROTO_XTR_NONE;
  }
  if (vf->vf_res->vf_cap_flags & (1UL << (15)))
  {
    struct virtchnl_vlan_supported_caps *stripping_support =
        &vf->vlan_v2_caps.offloads.stripping_support;
    uint32_t stripping_cap;
    if (stripping_support->outer)
      stripping_cap = stripping_support->outer;
    else
      stripping_cap = stripping_support->inner;
    if (stripping_cap & VIRTCHNL_VLAN_TAG_LOCATION_L2TAG1)
      rxq->rx_flags = (1UL << (0));
    else if (stripping_cap & VIRTCHNL_VLAN_TAG_LOCATION_L2TAG2_2)
      rxq->rx_flags = (1UL << (1));
  }
  else
  {
    rxq->rx_flags = (1UL << (0));
  }
  iavf_select_rxd_to_pkt_fields_handler(rxq, rxq->rxdid);
  rxq->mp = mp;
  rxq->nb_rx_desc = nb_desc;
  rxq->rx_free_thresh = rx_free_thresh;
  rxq->queue_id = queue_idx;
  rxq->port_id = dev->data->port_id;
  rxq->rx_deferred_start = rx_conf->rx_deferred_start;
  rxq->rx_hdr_len = 0;
  rxq->vsi = vsi;
  rxq->offloads = offloads;
  if (dev->data->dev_conf.rxmode.offloads & (1UL << (16)))
    rxq->crc_len = 4;
  else
    rxq->crc_len = 0;
  len = rte_pktmbuf_data_room_size(rxq->mp) - 128;
  rxq->rx_buf_len =
      (__typeof__(len))((len) & (~((__typeof__(len))(((1 << 7)) - 1))));
  rxq->rx_buf_len = __extension__(
      {
				    __typeof__ (rxq->rx_buf_len) _a =
				    (rxq->rx_buf_len);
				    __typeof__ ((16 * 1024 - 128)) _b =
				    ((16 * 1024 - 128)); _a < _b ? _a : _b; });
  len = nb_desc + 32;
  rxq->sw_ring =
      rte_zmalloc_socket("iavf rx sw ring",
                         sizeof(struct rte_mbuf *) * len, 64, socket_id);
  if (!rxq->sw_ring)
  {
    rte_log(4U, iavf_logtype_init,
            "%s(): "
            "Failed to allocate memory for SW ring"
            "\n",
            __func__);
    rte_free(rxq);
    return -12;
  }
  len = 4096 + 32;
  ring_size =
      (__typeof__(((len * sizeof(union iavf_32byte_rx_desc)) +
                   ((__typeof__(len * sizeof(union iavf_32byte_rx_desc)))(4096) -
                    1))))((((len * sizeof(union iavf_32byte_rx_desc)) +
                            ((__typeof__(len * sizeof(union iavf_32byte_rx_desc)))(4096) -
                             1))) &
                          (~((__typeof__(((len * sizeof(union iavf_32byte_rx_desc)) +
                                          ((__typeof__(len * sizeof(union iavf_32byte_rx_desc)))(4096) - 1))))((4096) - 1))));
  mz =
      rte_eth_dma_zone_reserve(dev, "rx_ring", queue_idx, ring_size, 128,
                               socket_id);
  if (!mz)
  {
    rte_log(4U, iavf_logtype_init,
            "%s(): "
            "Failed to reserve DMA memory for RX"
            "\n",
            __func__);
    rte_free(rxq->sw_ring);
    rte_free(rxq);
    return -12;
  }
  memset(mz->addr, 0, ring_size);
  rxq->rx_ring_phys_addr = mz->iova;
  rxq->rx_ring = (union iavf_32byte_rx_desc *)mz->addr;
  rxq->mz = mz;
  reset_rx_queue(rxq);
  rxq->q_set = 1;
  dev->data->rx_queues[queue_idx] = rxq;
  rxq->qrx_tail = hw->hw_addr + (0x00002000 + ((rxq->queue_id) * 4));
  rxq->rel_mbufs_type = IAVF_REL_MBUFS_DEFAULT;
  if (check_rx_bulk_allow(rxq) == 1)
  {
    rte_log(8U, iavf_logtype_init,
            "%s(): "
            "Rx Burst Bulk Alloc Preconditions are "
            "satisfied. Rx Burst Bulk Alloc function will be "
            "used on port=%d, queue=%d."
            "\n",
            __func__, rxq->port_id,
            rxq->queue_id);
  }
  else
  {
    rte_log(8U, iavf_logtype_init,
            "%s(): "
            "Rx Burst Bulk Alloc Preconditions are "
            "not satisfied, Scattered Rx is requested "
            "on port=%d, queue=%d."
            "\n",
            __func__, rxq->port_id,
            rxq->queue_id);
    ad->rx_bulk_alloc_allowed = 0;
  }
  if (check_rx_vec_allow(rxq) == 0)
    ad->rx_vec_allowed = 0;
  return 0;
}

int iavf_dev_tx_queue_setup(struct rte_eth_dev *dev,
                            uint16_t queue_idx,
                            uint16_t nb_desc,
                            unsigned int socket_id,
                            const struct rte_eth_txconf *tx_conf)
{
  struct iavf_hw *hw =
      (&((struct iavf_adapter *)dev->data->dev_private)->hw);
  struct iavf_adapter *adapter =
      ((struct iavf_adapter *)dev->data->dev_private);
  struct iavf_info *vf =
      (&((struct iavf_adapter *)dev->data->dev_private)->vf);
  struct iavf_vsi *vsi = &vf->vsi;
  struct iavf_tx_queue *txq;
  const struct rte_memzone *mz;
  uint32_t ring_size;
  uint16_t tx_rs_thresh, tx_free_thresh;
  uint64_t offloads;
  rte_log(8U, iavf_logtype_init, "%s(): "
                                 " >>"
                                 "\n",
          __func__);
  if (adapter->closed)
    return -5;
  offloads = tx_conf->offloads | dev->data->dev_conf.txmode.offloads;
  if (nb_desc % 32 != 0 || nb_desc > 4096 || nb_desc < 64)
  {
    rte_log(4U, iavf_logtype_init,
            "%s(): "
            "Number (%u) of transmit descriptors is "
            "invalid"
            "\n",
            __func__, nb_desc);
    return -22;
  }
  tx_rs_thresh = (uint16_t)((tx_conf->tx_rs_thresh) ? tx_conf->tx_rs_thresh : 32);
  tx_free_thresh = (uint16_t)((tx_conf->tx_free_thresh) ? tx_conf->tx_free_thresh : 32);
  if (check_tx_thresh(nb_desc, tx_rs_thresh, tx_free_thresh) != 0)
    return -22;
  if (dev->data->tx_queues[queue_idx])
  {
    iavf_dev_tx_queue_release(dev, queue_idx);
    dev->data->tx_queues[queue_idx] = ((void *)0);
  }
  txq = rte_zmalloc_socket("iavf txq",
                           sizeof(struct iavf_tx_queue), 64, socket_id);
  if (!txq)
  {
    rte_log(4U, iavf_logtype_init,
            "%s(): "
            "Failed to allocate memory for "
            "tx queue structure"
            "\n",
            __func__);
    return -12;
  }
  if (adapter->vf.vf_res->vf_cap_flags & (1UL << (15)))
  {
    struct virtchnl_vlan_supported_caps *insertion_support =
        &adapter->vf.vlan_v2_caps.offloads.insertion_support;
    uint32_t insertion_cap;
    if (insertion_support->outer)
      insertion_cap = insertion_support->outer;
    else
      insertion_cap = insertion_support->inner;
    if (insertion_cap & VIRTCHNL_VLAN_TAG_LOCATION_L2TAG1)
    {
      txq->vlan_flag = (1UL << (0));
      rte_log(8U, iavf_logtype_init,
              "%s(): "
              "VLAN insertion_cap: L2TAG1"
              "\n",
              __func__);
    }
    else if (insertion_cap & VIRTCHNL_VLAN_TAG_LOCATION_L2TAG2)
    {
      txq->vlan_flag = (1UL << (1));
      rte_log(8U, iavf_logtype_init,
              "%s(): "
              "VLAN insertion_cap: L2TAG2"
              "\n",
              __func__);
    }
  }
  else
  {
    txq->vlan_flag = (1UL << (0));
  }
  txq->nb_tx_desc = nb_desc;
  txq->rs_thresh = tx_rs_thresh;
  txq->free_thresh = tx_free_thresh;
  txq->queue_id = queue_idx;
  txq->port_id = dev->data->port_id;
  txq->offloads = offloads;
  txq->tx_deferred_start = tx_conf->tx_deferred_start;
  txq->vsi = vsi;
  if (iavf_ipsec_crypto_supported(adapter))
    txq->ipsec_crypto_pkt_md_offset =
        iavf_security_get_pkt_md_offset(adapter);
  txq->sw_ring =
      rte_zmalloc_socket("iavf tx sw ring",
                         sizeof(struct iavf_tx_entry) * nb_desc,
                         64, socket_id);
  if (!txq->sw_ring)
  {
    rte_log(4U, iavf_logtype_init,
            "%s(): "
            "Failed to allocate memory for SW TX ring"
            "\n",
            __func__);
    rte_free(txq);
    return -12;
  }
  ring_size = sizeof(struct iavf_tx_desc) * 4096;
  ring_size =
      (__typeof__(((ring_size) + ((__typeof__(ring_size))(4096) - 1))))((((ring_size) + ((__typeof__(ring_size))(4096) - 1))) & (~((__typeof__(((ring_size) + ((__typeof__(ring_size))(4096) - 1))))((4096) - 1))));
  mz =
      rte_eth_dma_zone_reserve(dev, "tx_ring", queue_idx, ring_size, 128,
                               socket_id);
  if (!mz)
  {
    rte_log(4U, iavf_logtype_init,
            "%s(): "
            "Failed to reserve DMA memory for TX"
            "\n",
            __func__);
    rte_free(txq->sw_ring);
    rte_free(txq);
    return -12;
  }
  txq->tx_ring_phys_addr = mz->iova;
  txq->tx_ring = (struct iavf_tx_desc *)mz->addr;
  txq->mz = mz;
  reset_tx_queue(txq);
  txq->q_set = 1;
  dev->data->tx_queues[queue_idx] = txq;
  txq->qtx_tail = hw->hw_addr + (0x00000000 + ((queue_idx) * 4));
  txq->rel_mbufs_type = IAVF_REL_MBUFS_DEFAULT;
  if (check_tx_vec_allow(txq) == 0)
  {
    struct iavf_adapter *ad =
        ((struct iavf_adapter *)dev->data->dev_private);
    ad->tx_vec_allowed = 0;
  }
  if (vf->vf_res->vf_cap_flags & (1UL << (29)) && vf->tm_conf.committed)
  {
    int tc;
    for (tc = 0; tc < vf->qos_cap->num_elem; tc++)
    {
      if (txq->queue_id >= vf->qtc_map[tc].start_queue_id &&
          txq->queue_id < (vf->qtc_map[tc].start_queue_id +
                           vf->qtc_map[tc].queue_count))
        break;
    }
    if (tc >= vf->qos_cap->num_elem)
    {
      rte_log(4U, iavf_logtype_init,
              "%s(): "
              "Queue TC mapping is not correct"
              "\n",
              __func__);
      return -22;
    }
    txq->tc = tc;
  }
  return 0;
}

int iavf_dev_rx_queue_start(struct rte_eth_dev *dev, uint16_t rx_queue_id)
{
  struct iavf_adapter *adapter =
      ((struct iavf_adapter *)dev->data->dev_private);
  struct iavf_info *vf =
      (&((struct iavf_adapter *)dev->data->dev_private)->vf);
  struct iavf_hw *hw =
      (&((struct iavf_adapter *)dev->data->dev_private)->hw);
  struct iavf_rx_queue *rxq;
  int err = 0;
  rte_log(8U, iavf_logtype_driver, "%s(): "
                                   " >>"
                                   "\n",
          __func__);
  if (rx_queue_id >= dev->data->nb_rx_queues)
    return -22;
  rxq = dev->data->rx_queues[rx_queue_id];
  err = alloc_rxq_mbufs(rxq);
  if (err)
  {
    rte_log(4U, iavf_logtype_driver,
            "%s(): "
            "Failed to allocate RX queue mbuf"
            "\n",
            __func__);
    return err;
  }
  __asm__ volatile("fence w, w" ::: "memory");
  writel(rxq->nb_rx_desc - 1, rxq->qrx_tail);
  readl((hw)->hw_addr + (0x00008800));
  if (!vf->lv_enabled)
    err = iavf_switch_queue(adapter, rx_queue_id, 1, 1);
  else
    err = iavf_switch_queue_lv(adapter, rx_queue_id, 1, 1);
  if (err)
  {
    release_rxq_mbufs(rxq);
    rte_log(4U, iavf_logtype_driver,
            "%s(): "
            "Failed to switch RX queue %u on"
            "\n",
            __func__,
            rx_queue_id);
  }
  else
  {
    dev->data->rx_queue_state[rx_queue_id] = 1;
  }
  if (dev->data->dev_conf.rxmode.offloads & (1UL << (14)))
  {
    if (iavf_get_phc_time(rxq))
    {
      rte_log(4U, iavf_logtype_driver,
              "%s(): "
              "get physical time failed"
              "\n",
              __func__);
      return err;
    }
    rxq->hw_time_update =
        rte_get_timer_cycles() / (rte_get_timer_hz() / 1000);
  }
  return err;
}

int iavf_dev_tx_queue_start(struct rte_eth_dev *dev, uint16_t tx_queue_id)
{
  struct iavf_adapter *adapter =
      ((struct iavf_adapter *)dev->data->dev_private);
  struct iavf_info *vf =
      (&((struct iavf_adapter *)dev->data->dev_private)->vf);
  struct iavf_hw *hw =
      (&((struct iavf_adapter *)dev->data->dev_private)->hw);
  struct iavf_tx_queue *txq;
  int err = 0;
  rte_log(8U, iavf_logtype_driver, "%s(): "
                                   " >>"
                                   "\n",
          __func__);
  if (tx_queue_id >= dev->data->nb_tx_queues)
    return -22;
  txq = dev->data->tx_queues[tx_queue_id];
  writel(0, txq->qtx_tail);
  readl((hw)->hw_addr + (0x00008800));
  if (!vf->lv_enabled)
    err = iavf_switch_queue(adapter, tx_queue_id, 0, 1);
  else
    err = iavf_switch_queue_lv(adapter, tx_queue_id, 0, 1);
  if (err)
    rte_log(4U, iavf_logtype_driver,
            "%s(): "
            "Failed to switch TX queue %u on"
            "\n",
            __func__,
            tx_queue_id);
  else
    dev->data->tx_queue_state[tx_queue_id] = 1;
  return err;
}

int iavf_dev_rx_queue_stop(struct rte_eth_dev *dev, uint16_t rx_queue_id)
{
  struct iavf_adapter *adapter =
      ((struct iavf_adapter *)dev->data->dev_private);
  struct iavf_info *vf =
      (&((struct iavf_adapter *)dev->data->dev_private)->vf);
  struct iavf_rx_queue *rxq;
  int err;
  rte_log(8U, iavf_logtype_driver, "%s(): "
                                   " >>"
                                   "\n",
          __func__);
  if (rx_queue_id >= dev->data->nb_rx_queues)
    return -22;
  if (!vf->lv_enabled)
    err = iavf_switch_queue(adapter, rx_queue_id, 1, 0);
  else
    err = iavf_switch_queue_lv(adapter, rx_queue_id, 1, 0);
  if (err)
  {
    rte_log(4U, iavf_logtype_driver,
            "%s(): "
            "Failed to switch RX queue %u off"
            "\n",
            __func__,
            rx_queue_id);
    return err;
  }
  rxq = dev->data->rx_queues[rx_queue_id];
  iavf_rxq_release_mbufs_ops[rxq->rel_mbufs_type].release_mbufs(rxq);
  reset_rx_queue(rxq);
  dev->data->rx_queue_state[rx_queue_id] = 0;
  return 0;
}

int iavf_dev_tx_queue_stop(struct rte_eth_dev *dev, uint16_t tx_queue_id)
{
  struct iavf_adapter *adapter =
      ((struct iavf_adapter *)dev->data->dev_private);
  struct iavf_info *vf =
      (&((struct iavf_adapter *)dev->data->dev_private)->vf);
  struct iavf_tx_queue *txq;
  int err;
  rte_log(8U, iavf_logtype_driver, "%s(): "
                                   " >>"
                                   "\n",
          __func__);
  if (tx_queue_id >= dev->data->nb_tx_queues)
    return -22;
  if (!vf->lv_enabled)
    err = iavf_switch_queue(adapter, tx_queue_id, 0, 0);
  else
    err = iavf_switch_queue_lv(adapter, tx_queue_id, 0, 0);
  if (err)
  {
    rte_log(4U, iavf_logtype_driver,
            "%s(): "
            "Failed to switch TX queue %u off"
            "\n",
            __func__,
            tx_queue_id);
    return err;
  }
  txq = dev->data->tx_queues[tx_queue_id];
  iavf_txq_release_mbufs_ops[txq->rel_mbufs_type].release_mbufs(txq);
  reset_tx_queue(txq);
  dev->data->tx_queue_state[tx_queue_id] = 0;
  return 0;
}

void iavf_dev_rx_queue_release(struct rte_eth_dev *dev, uint16_t qid)
{
  struct iavf_rx_queue *q = dev->data->rx_queues[qid];
  if (!q)
    return;
  iavf_rxq_release_mbufs_ops[q->rel_mbufs_type].release_mbufs(q);
  rte_free(q->sw_ring);
  rte_memzone_free(q->mz);
  rte_free(q);
}

void iavf_dev_tx_queue_release(struct rte_eth_dev *dev, uint16_t qid)
{
  struct iavf_tx_queue *q = dev->data->tx_queues[qid];
  if (!q)
    return;
  iavf_txq_release_mbufs_ops[q->rel_mbufs_type].release_mbufs(q);
  rte_free(q->sw_ring);
  rte_memzone_free(q->mz);
  rte_free(q);
}

static void
iavf_reset_queues(struct rte_eth_dev *dev)
{
  struct iavf_rx_queue *rxq;
  struct iavf_tx_queue *txq;
  int i;
  for (i = 0; i < dev->data->nb_tx_queues; i++)
  {
    txq = dev->data->tx_queues[i];
    if (!txq)
      continue;
    iavf_txq_release_mbufs_ops[txq->rel_mbufs_type].release_mbufs(txq);
    reset_tx_queue(txq);
    dev->data->tx_queue_state[i] = 0;
  }
  for (i = 0; i < dev->data->nb_rx_queues; i++)
  {
    rxq = dev->data->rx_queues[i];
    if (!rxq)
      continue;
    iavf_rxq_release_mbufs_ops[rxq->rel_mbufs_type].release_mbufs(rxq);
    reset_rx_queue(rxq);
    dev->data->rx_queue_state[i] = 0;
  }
}

void iavf_stop_queues(struct rte_eth_dev *dev)
{
  struct iavf_adapter *adapter =
      ((struct iavf_adapter *)dev->data->dev_private);
  struct iavf_info *vf =
      (&((struct iavf_adapter *)dev->data->dev_private)->vf);
  int ret;
  if (vf->in_reset_recovery)
  {
    iavf_reset_queues(dev);
    return;
  }
  if (!vf->lv_enabled)
  {
    ret = iavf_disable_queues(adapter);
    if (ret)
      rte_log(5U, iavf_logtype_driver, "%s(): "
                                       "Fail to stop queues"
                                       "\n",
              __func__);
  }
  else
  {
    ret = iavf_disable_queues_lv(adapter);
    if (ret)
      rte_log(5U, iavf_logtype_driver,
              "%s(): "
              "Fail to stop queues for large VF"
              "\n",
              __func__);
  }
  if (ret)
    rte_log(5U, iavf_logtype_driver, "%s(): "
                                     "Fail to stop queues"
                                     "\n",
            __func__);
  iavf_reset_queues(dev);
}

static inline void
iavf_rxd_to_vlan_tci(struct rte_mbuf *mb,
                     volatile union iavf_32byte_rx_desc *rxdp)
{
  if ((rxdp->wb.qword1.status_error_len) &
      (1 << IAVF_RX_DESC_STATUS_L2TAG1P_SHIFT))
  {
    mb->ol_flags |= (1ULL << 0) | (1ULL << 6);
    mb->vlan_tci = (rxdp->wb.qword0.lo_dword.l2tag1);
  }
  else
  {
    mb->vlan_tci = 0;
  }
}

static inline void
iavf_flex_rxd_to_vlan_tci(struct rte_mbuf *mb,
                          volatile union iavf_32b_rx_flex_desc *rxdp)
{
  if ((rxdp->wb.status_error0) & (1 << IAVF_RX_FLEX_DESC_STATUS0_L2TAG1P_S))
  {
    mb->ol_flags |= (1ULL << 0) | (1ULL << 6);
    mb->vlan_tci = (rxdp->wb.l2tag1);
  }
  else
  {
    mb->vlan_tci = 0;
  }
  if ((rxdp->wb.status_error1) & (1 << IAVF_RX_FLEX_DESC_STATUS1_L2TAG2P_S))
  {
    mb->ol_flags |= (1ULL << 15) | (1ULL << 20) | (1ULL << 6) | (1ULL << 0);
    mb->vlan_tci_outer = mb->vlan_tci;
    mb->vlan_tci = (rxdp->wb.l2tag2_2nd);
    do
    {
    } while (0);
  }
  else
  {
    mb->vlan_tci_outer = 0;
  }
}

static inline void
iavf_flex_rxd_to_ipsec_crypto_said_get(struct rte_mbuf *mb,
                                       volatile union iavf_32b_rx_flex_desc
                                           *rxdp)
{
  volatile struct iavf_32b_rx_flex_desc_comms_ipsec *desc =
      (volatile struct iavf_32b_rx_flex_desc_comms_ipsec *)rxdp;
  mb->dynfield1[0] = desc->ipsec_said & (0xFFFFF);
}

static inline void
iavf_flex_rxd_to_ipsec_crypto_status(struct rte_mbuf *mb,
                                     volatile union iavf_32b_rx_flex_desc
                                         *rxdp,
                                     struct iavf_ipsec_crypto_stats *stats)
{
  uint16_t status1 = (rxdp->wb.status_error1);
  if (status1 & (1UL << (IAVF_RX_FLEX_DESC_STATUS1_IPSEC_CRYPTO_PROCESSED)))
  {
    uint16_t ipsec_status;
    mb->ol_flags |= (1ULL << 18);
    ipsec_status = status1 &
                   ((1UL << (IAVF_RX_FLEX_DESC_STATUS1_IPSEC_CRYPTO_STATUS_0)) |
                    (1UL << (IAVF_RX_FLEX_DESC_STATUS1_IPSEC_CRYPTO_STATUS_1)) | (1UL << (IAVF_RX_FLEX_DESC_STATUS1_IPSEC_CRYPTO_STATUS_2)) | (1UL << (IAVF_RX_FLEX_DESC_STATUS1_IPSEC_CRYPTO_STATUS_3)));
    if (__builtin_expect(!!(ipsec_status != IAVF_IPSEC_CRYPTO_STATUS_SUCCESS), 0))
    {
      mb->ol_flags |= (1ULL << 19);
      switch (ipsec_status)
      {
      case IAVF_IPSEC_CRYPTO_STATUS_SAD_MISS:
        stats->ierrors.sad_miss++;
        break;
      case IAVF_IPSEC_CRYPTO_STATUS_NOT_PROCESSED:
        stats->ierrors.not_processed++;
        break;
      case IAVF_IPSEC_CRYPTO_STATUS_ICV_CHECK_FAIL:
        stats->ierrors.icv_check++;
        break;
      case IAVF_IPSEC_CRYPTO_STATUS_LENGTH_ERR:
        stats->ierrors.ipsec_length++;
        break;
      case IAVF_IPSEC_CRYPTO_STATUS_MISC_ERR:
        stats->ierrors.misc++;
        break;
      }
      stats->ierrors.count++;
      return;
    }
    stats->icount++;
    stats->ibytes += rxdp->wb.pkt_len & 0x3FFF;
    if (rxdp->wb.rxdid == IAVF_RXDID_COMMS_IPSEC_CRYPTO &&
        ipsec_status != IAVF_IPSEC_CRYPTO_STATUS_SAD_MISS)
      iavf_flex_rxd_to_ipsec_crypto_said_get(mb, rxdp);
  }
}

static inline uint64_t
iavf_rxd_to_pkt_flags(uint64_t qword)
{
  uint64_t flags;
  uint64_t error_bits = (qword >> 19);
  flags = (((qword >> IAVF_RX_DESC_STATUS_FLTSTAT_SHIFT) &
            IAVF_RX_DESC_FLTSTAT_RSS_HASH) ==
           IAVF_RX_DESC_FLTSTAT_RSS_HASH)
              ? (1ULL << 1)
              : 0;
  flags |= (qword & (1 << IAVF_RX_DESC_STATUS_FLM_SHIFT) ? (1ULL << 2) : 0);
  if (__builtin_expect(!!((error_bits & 0x3f) == 0), 1))
  {
    flags |= ((1ULL << 7) | (1ULL << 8));
    return flags;
  }
  if (__builtin_expect(!!(error_bits & (1 << IAVF_RX_DESC_ERROR_IPE_SHIFT)), 0))
    flags |= (1ULL << 4);
  else
    flags |= (1ULL << 7);
  if (__builtin_expect(!!(error_bits & (1 << IAVF_RX_DESC_ERROR_L4E_SHIFT)), 0))
    flags |= (1ULL << 3);
  else
    flags |= (1ULL << 8);
  return flags;
}

static inline uint64_t
iavf_rxd_build_fdir(volatile union iavf_32byte_rx_desc *rxdp,
                    struct rte_mbuf *mb)
{
  uint64_t flags = 0;
  uint16_t flexbh;
  flexbh = ((rxdp->wb.qword2.ext_status) >>
            IAVF_RX_DESC_EXT_STATUS_FLEXBH_SHIFT) &
           0x03;
  if (flexbh == 0x01)
  {
    mb->hash.fdir.hi = (rxdp->wb.qword3.hi_dword.fd_id);
    flags |= (1ULL << 13);
  }
  return flags;
}

static inline uint64_t
iavf_flex_rxd_error_to_pkt_flags(uint16_t stat_err0)
{
  uint64_t flags = 0;
  if (__builtin_expect(!!(!(stat_err0 & (1 << IAVF_RX_FLEX_DESC_STATUS0_L3L4P_S))), 0))
    return 0;
  if (__builtin_expect(!!(!(stat_err0 &
                            ((1 << IAVF_RX_FLEX_DESC_STATUS0_HBO_S) |
                             (1 << IAVF_RX_FLEX_DESC_STATUS0_XSUM_IPE_S) | (1 << IAVF_RX_FLEX_DESC_STATUS0_XSUM_L4E_S) | (1 << IAVF_RX_FLEX_DESC_STATUS0_XSUM_EIPE_S) | (1 << IAVF_RX_FLEX_DESC_STATUS0_XSUM_EUDPE_S) | (1 << IAVF_RX_FLEX_DESC_STATUS0_RXE_S)))),
                       1))
  {
    flags |= ((1ULL << 7) | (1ULL << 8) | (1ULL << 22));
    return flags;
  }
  if (__builtin_expect(!!(stat_err0 & (1 << IAVF_RX_FLEX_DESC_STATUS0_XSUM_IPE_S)), 0))
    flags |= (1ULL << 4);
  else
    flags |= (1ULL << 7);
  if (__builtin_expect(!!(stat_err0 & (1 << IAVF_RX_FLEX_DESC_STATUS0_XSUM_L4E_S)), 0))
    flags |= (1ULL << 3);
  else
    flags |= (1ULL << 8);
  if (__builtin_expect(!!(stat_err0 & (1 << IAVF_RX_FLEX_DESC_STATUS0_XSUM_EIPE_S)), 0))
    flags |= (1ULL << 5);
  if (__builtin_expect(!!(stat_err0 & (1 << IAVF_RX_FLEX_DESC_STATUS0_XSUM_EUDPE_S)), 0))
    flags |= (1ULL << 21);
  else
    flags |= (1ULL << 22);
  return flags;
}

static inline void
iavf_update_rx_tail(struct iavf_rx_queue *rxq, uint16_t nb_hold,
                    uint16_t rx_id)
{
  nb_hold = (uint16_t)(nb_hold + rxq->nb_rx_hold);
  if (nb_hold > rxq->rx_free_thresh)
  {
    do
    {
    } while (0);
    rx_id = (uint16_t)((rx_id == 0) ? (rxq->nb_rx_desc - 1) : (rx_id - 1));
    rte_write32_wc(((rx_id)), rxq->qrx_tail);
    nb_hold = 0;
  }
  rxq->nb_rx_hold = nb_hold;
}

uint16_t
iavf_recv_pkts(void *rx_queue, struct rte_mbuf **rx_pkts, uint16_t nb_pkts)
{
  volatile union iavf_32byte_rx_desc *rx_ring;
  volatile union iavf_32byte_rx_desc *rxdp;
  struct iavf_rx_queue *rxq;
  union iavf_32byte_rx_desc rxd;
  struct rte_mbuf *rxe;
  struct rte_eth_dev *dev;
  struct rte_mbuf *rxm;
  struct rte_mbuf *nmb;
  uint16_t nb_rx;
  uint32_t rx_status;
  uint64_t qword1;
  uint16_t rx_packet_len;
  uint16_t rx_id, nb_hold;
  uint64_t dma_addr;
  uint64_t pkt_flags;
  const uint32_t *ptype_tbl;
  nb_rx = 0;
  nb_hold = 0;
  rxq = rx_queue;
  rx_id = rxq->rx_tail;
  rx_ring = rxq->rx_ring;
  ptype_tbl = rxq->vsi->adapter->ptype_tbl;
  while (nb_rx < nb_pkts)
  {
    rxdp = &rx_ring[rx_id];
    qword1 = (rxdp->wb.qword1.status_error_len);
    rx_status =
        (qword1 & (((1UL << (IAVF_RX_DESC_STATUS_LAST)) - 1) << 0)) >> 0;
    if (!(rx_status & (1 << IAVF_RX_DESC_STATUS_DD_SHIFT)))
      break;
    do
    {
    } while (0);
    nmb = rte_mbuf_raw_alloc(rxq->mp);
    if (__builtin_expect(!!(!nmb), 0))
    {
      dev = &rte_eth_devices[rxq->port_id];
      dev->data->rx_mbuf_alloc_failed++;
      do
      {
      } while (0);
      break;
    }
    rxd = *rxdp;
    nb_hold++;
    rxe = rxq->sw_ring[rx_id];
    rxq->sw_ring[rx_id] = nmb;
    rx_id++;
    if (__builtin_expect(!!(rx_id == rxq->nb_rx_desc), 0))
      rx_id = 0;
    rte_prefetch0(rxq->sw_ring[rx_id]);
    if ((rx_id & 0x3) == 0)
    {
      rte_prefetch0(&rx_ring[rx_id]);
      rte_prefetch0(rxq->sw_ring[rx_id]);
    }
    rxm = rxe;
    dma_addr = (rte_mbuf_data_iova_default(nmb));
    rxdp->read.hdr_addr = 0;
    rxdp->read.pkt_addr = dma_addr;
    rx_packet_len = ((qword1 & (0x3FFFULL << 38)) >> 38) - rxq->crc_len;
    rxm->data_off = 128;
    rte_prefetch0(((void *)((uintptr_t)(rxm->buf_addr) + (128))));
    rxm->nb_segs = 1;
    rxm->next = ((void *)0);
    rxm->pkt_len = rx_packet_len;
    rxm->data_len = rx_packet_len;
    rxm->port = rxq->port_id;
    rxm->ol_flags = 0;
    iavf_rxd_to_vlan_tci(rxm, &rxd);
    pkt_flags = iavf_rxd_to_pkt_flags(qword1);
    rxm->packet_type =
        ptype_tbl[(uint8_t)((qword1 & (0xFFULL << 30)) >> 30)];
    if (pkt_flags & (1ULL << 1))
      rxm->hash.rss = (rxd.wb.qword0.hi_dword.rss);
    if (pkt_flags & (1ULL << 2))
      pkt_flags |= iavf_rxd_build_fdir(&rxd, rxm);
    rxm->ol_flags |= pkt_flags;
    rx_pkts[nb_rx++] = rxm;
  }
  rxq->rx_tail = rx_id;
  iavf_update_rx_tail(rxq, nb_hold, rx_id);
  return nb_rx;
}

uint16_t
iavf_recv_pkts_flex_rxd(void *rx_queue,
                        struct rte_mbuf **rx_pkts, uint16_t nb_pkts)
{
  volatile union iavf_32byte_rx_desc *rx_ring;
  volatile union iavf_32b_rx_flex_desc *rxdp;
  struct iavf_rx_queue *rxq;
  union iavf_32b_rx_flex_desc rxd;
  struct rte_mbuf *rxe;
  struct rte_eth_dev *dev;
  struct rte_mbuf *rxm;
  struct rte_mbuf *nmb;
  uint16_t nb_rx;
  uint16_t rx_stat_err0;
  uint16_t rx_packet_len;
  uint16_t rx_id, nb_hold;
  uint64_t dma_addr;
  uint64_t pkt_flags;
  const uint32_t *ptype_tbl;
  uint64_t ts_ns;
  nb_rx = 0;
  nb_hold = 0;
  rxq = rx_queue;
  rx_id = rxq->rx_tail;
  rx_ring = rxq->rx_ring;
  ptype_tbl = rxq->vsi->adapter->ptype_tbl;
  if (rxq->offloads & (1UL << (14)))
  {
    uint64_t sw_cur_time =
        rte_get_timer_cycles() / (rte_get_timer_hz() / 1000);
    if (sw_cur_time - rxq->hw_time_update > 4)
    {
      if (iavf_get_phc_time(rxq))
        rte_log(4U, iavf_logtype_driver,
                "%s(): "
                "get physical time failed"
                "\n",
                __func__);
      rxq->hw_time_update = sw_cur_time;
    }
  }
  while (nb_rx < nb_pkts)
  {
    rxdp = (volatile union iavf_32b_rx_flex_desc *)&rx_ring[rx_id];
    rx_stat_err0 = (rxdp->wb.status_error0);
    if (!(rx_stat_err0 & (1 << IAVF_RX_FLEX_DESC_STATUS0_DD_S)))
      break;
    do
    {
    } while (0);
    nmb = rte_mbuf_raw_alloc(rxq->mp);
    if (__builtin_expect(!!(!nmb), 0))
    {
      dev = &rte_eth_devices[rxq->port_id];
      dev->data->rx_mbuf_alloc_failed++;
      do
      {
      } while (0);
      break;
    }
    rxd = *rxdp;
    nb_hold++;
    rxe = rxq->sw_ring[rx_id];
    rxq->sw_ring[rx_id] = nmb;
    rx_id++;
    if (__builtin_expect(!!(rx_id == rxq->nb_rx_desc), 0))
      rx_id = 0;
    rte_prefetch0(rxq->sw_ring[rx_id]);
    if ((rx_id & 0x3) == 0)
    {
      rte_prefetch0(&rx_ring[rx_id]);
      rte_prefetch0(rxq->sw_ring[rx_id]);
    }
    rxm = rxe;
    dma_addr = (rte_mbuf_data_iova_default(nmb));
    rxdp->read.hdr_addr = 0;
    rxdp->read.pkt_addr = dma_addr;
    rx_packet_len = ((rxd.wb.pkt_len) & (0x3FFF)) - rxq->crc_len;
    rxm->data_off = 128;
    rte_prefetch0(((void *)((uintptr_t)(rxm->buf_addr) + (128))));
    rxm->nb_segs = 1;
    rxm->next = ((void *)0);
    rxm->pkt_len = rx_packet_len;
    rxm->data_len = rx_packet_len;
    rxm->port = rxq->port_id;
    rxm->ol_flags = 0;
    rxm->packet_type = ptype_tbl[(0x3FF) & (rxd.wb.ptype_flex_flags0)];
    iavf_flex_rxd_to_vlan_tci(rxm, &rxd);
    iavf_flex_rxd_to_ipsec_crypto_status(rxm, &rxd,
                                         &rxq->stats.ipsec_crypto);
    rxd_to_pkt_fields_ops[rxq->rxdid](rxq, rxm, &rxd);
    pkt_flags = iavf_flex_rxd_error_to_pkt_flags(rx_stat_err0);
    if (iavf_timestamp_dynflag > 0)
    {
      ts_ns = iavf_tstamp_convert_32b_64b(rxq->phc_time,
                                          (rxd.wb.flex_ts.ts_high));
      rxq->phc_time = ts_ns;
      rxq->hw_time_update =
          rte_get_timer_cycles() / (rte_get_timer_hz() / 1000);
      *((rte_mbuf_timestamp_t *)((uintptr_t)(rxm) +
                                 (iavf_timestamp_dynfield_offset))) =
          ts_ns;
      rxm->ol_flags |= iavf_timestamp_dynflag;
    }
    rxm->ol_flags |= pkt_flags;
    rx_pkts[nb_rx++] = rxm;
  }
  rxq->rx_tail = rx_id;
  iavf_update_rx_tail(rxq, nb_hold, rx_id);
  return nb_rx;
}

uint16_t
iavf_recv_scattered_pkts_flex_rxd(void *rx_queue, struct rte_mbuf **rx_pkts,
                                  uint16_t nb_pkts)
{
  struct iavf_rx_queue *rxq = rx_queue;
  union iavf_32b_rx_flex_desc rxd;
  struct rte_mbuf *rxe;
  struct rte_mbuf *first_seg = rxq->pkt_first_seg;
  struct rte_mbuf *last_seg = rxq->pkt_last_seg;
  struct rte_mbuf *nmb, *rxm;
  uint16_t rx_id = rxq->rx_tail;
  uint16_t nb_rx = 0, nb_hold = 0, rx_packet_len;
  struct rte_eth_dev *dev;
  uint16_t rx_stat_err0;
  uint64_t dma_addr;
  uint64_t pkt_flags;
  uint64_t ts_ns;
  volatile union iavf_32byte_rx_desc *rx_ring = rxq->rx_ring;
  volatile union iavf_32b_rx_flex_desc *rxdp;
  const uint32_t *ptype_tbl = rxq->vsi->adapter->ptype_tbl;
  if (rxq->offloads & (1UL << (14)))
  {
    uint64_t sw_cur_time =
        rte_get_timer_cycles() / (rte_get_timer_hz() / 1000);
    if (sw_cur_time - rxq->hw_time_update > 4)
    {
      if (iavf_get_phc_time(rxq))
        rte_log(4U, iavf_logtype_driver,
                "%s(): "
                "get physical time failed"
                "\n",
                __func__);
      rxq->hw_time_update = sw_cur_time;
    }
  }
  while (nb_rx < nb_pkts)
  {
    rxdp = (volatile union iavf_32b_rx_flex_desc *)&rx_ring[rx_id];
    rx_stat_err0 = (rxdp->wb.status_error0);
    if (!(rx_stat_err0 & (1 << IAVF_RX_FLEX_DESC_STATUS0_DD_S)))
      break;
    do
    {
    } while (0);
    nmb = rte_mbuf_raw_alloc(rxq->mp);
    if (__builtin_expect(!!(!nmb), 0))
    {
      do
      {
      } while (0);
      dev = &rte_eth_devices[rxq->port_id];
      dev->data->rx_mbuf_alloc_failed++;
      break;
    }
    rxd = *rxdp;
    nb_hold++;
    rxe = rxq->sw_ring[rx_id];
    rxq->sw_ring[rx_id] = nmb;
    rx_id++;
    if (rx_id == rxq->nb_rx_desc)
      rx_id = 0;
    rte_prefetch0(rxq->sw_ring[rx_id]);
    if ((rx_id & 0x3) == 0)
    {
      rte_prefetch0(&rx_ring[rx_id]);
      rte_prefetch0(rxq->sw_ring[rx_id]);
    }
    rxm = rxe;
    dma_addr = (rte_mbuf_data_iova_default(nmb));
    rxdp->read.hdr_addr = 0;
    rxdp->read.pkt_addr = dma_addr;
    rx_packet_len = (rxd.wb.pkt_len) & (0x3FFF);
    rxm->data_len = rx_packet_len;
    rxm->data_off = 128;
    if (!first_seg)
    {
      first_seg = rxm;
      first_seg->nb_segs = 1;
      first_seg->pkt_len = rx_packet_len;
    }
    else
    {
      first_seg->pkt_len =
          (uint16_t)(first_seg->pkt_len + rx_packet_len);
      first_seg->nb_segs++;
      last_seg->next = rxm;
    }
    if (!(rx_stat_err0 & (1 << IAVF_RX_FLEX_DESC_STATUS0_EOF_S)))
    {
      last_seg = rxm;
      continue;
    }
    rxm->next = ((void *)0);
    if (__builtin_expect(!!(rxq->crc_len > 0), 0))
    {
      first_seg->pkt_len -= 4;
      if (rx_packet_len <= 4)
      {
        rte_pktmbuf_free_seg(rxm);
        first_seg->nb_segs--;
        last_seg->data_len =
            (uint16_t)(last_seg->data_len - (4 - rx_packet_len));
        last_seg->next = ((void *)0);
      }
      else
      {
        rxm->data_len = (uint16_t)(rx_packet_len - 4);
      }
    }
    first_seg->port = rxq->port_id;
    first_seg->ol_flags = 0;
    first_seg->packet_type = ptype_tbl[(0x3FF) &
                                       (rxd.wb.ptype_flex_flags0)];
    iavf_flex_rxd_to_vlan_tci(first_seg, &rxd);
    iavf_flex_rxd_to_ipsec_crypto_status(first_seg, &rxd,
                                         &rxq->stats.ipsec_crypto);
    rxd_to_pkt_fields_ops[rxq->rxdid](rxq, first_seg, &rxd);
    pkt_flags = iavf_flex_rxd_error_to_pkt_flags(rx_stat_err0);
    if (iavf_timestamp_dynflag > 0)
    {
      ts_ns = iavf_tstamp_convert_32b_64b(rxq->phc_time,
                                          (rxd.wb.flex_ts.ts_high));
      rxq->phc_time = ts_ns;
      rxq->hw_time_update =
          rte_get_timer_cycles() / (rte_get_timer_hz() / 1000);
      *((rte_mbuf_timestamp_t *)((uintptr_t)(first_seg) +
                                 (iavf_timestamp_dynfield_offset))) =
          ts_ns;
      first_seg->ol_flags |= iavf_timestamp_dynflag;
    }
    first_seg->ol_flags |= pkt_flags;
    rte_prefetch0(((void *)((uintptr_t)(first_seg->buf_addr) +
                            (first_seg->data_off))));
    rx_pkts[nb_rx++] = first_seg;
    first_seg = ((void *)0);
  }
  rxq->rx_tail = rx_id;
  rxq->pkt_first_seg = first_seg;
  rxq->pkt_last_seg = last_seg;
  iavf_update_rx_tail(rxq, nb_hold, rx_id);
  return nb_rx;
}

uint16_t
iavf_recv_scattered_pkts(void *rx_queue, struct rte_mbuf **rx_pkts,
                         uint16_t nb_pkts)
{
  struct iavf_rx_queue *rxq = rx_queue;
  union iavf_32byte_rx_desc rxd;
  struct rte_mbuf *rxe;
  struct rte_mbuf *first_seg = rxq->pkt_first_seg;
  struct rte_mbuf *last_seg = rxq->pkt_last_seg;
  struct rte_mbuf *nmb, *rxm;
  uint16_t rx_id = rxq->rx_tail;
  uint16_t nb_rx = 0, nb_hold = 0, rx_packet_len;
  struct rte_eth_dev *dev;
  uint32_t rx_status;
  uint64_t qword1;
  uint64_t dma_addr;
  uint64_t pkt_flags;
  volatile union iavf_32byte_rx_desc *rx_ring = rxq->rx_ring;
  volatile union iavf_32byte_rx_desc *rxdp;
  const uint32_t *ptype_tbl = rxq->vsi->adapter->ptype_tbl;
  while (nb_rx < nb_pkts)
  {
    rxdp = &rx_ring[rx_id];
    qword1 = (rxdp->wb.qword1.status_error_len);
    rx_status =
        (qword1 & (((1UL << (IAVF_RX_DESC_STATUS_LAST)) - 1) << 0)) >> 0;
    if (!(rx_status & (1 << IAVF_RX_DESC_STATUS_DD_SHIFT)))
      break;
    do
    {
    } while (0);
    nmb = rte_mbuf_raw_alloc(rxq->mp);
    if (__builtin_expect(!!(!nmb), 0))
    {
      do
      {
      } while (0);
      dev = &rte_eth_devices[rxq->port_id];
      dev->data->rx_mbuf_alloc_failed++;
      break;
    }
    rxd = *rxdp;
    nb_hold++;
    rxe = rxq->sw_ring[rx_id];
    rxq->sw_ring[rx_id] = nmb;
    rx_id++;
    if (rx_id == rxq->nb_rx_desc)
      rx_id = 0;
    rte_prefetch0(rxq->sw_ring[rx_id]);
    if ((rx_id & 0x3) == 0)
    {
      rte_prefetch0(&rx_ring[rx_id]);
      rte_prefetch0(rxq->sw_ring[rx_id]);
    }
    rxm = rxe;
    dma_addr = (rte_mbuf_data_iova_default(nmb));
    rxdp->read.hdr_addr = 0;
    rxdp->read.pkt_addr = dma_addr;
    rx_packet_len = (qword1 & (0x3FFFULL << 38)) >> 38;
    rxm->data_len = rx_packet_len;
    rxm->data_off = 128;
    if (!first_seg)
    {
      first_seg = rxm;
      first_seg->nb_segs = 1;
      first_seg->pkt_len = rx_packet_len;
    }
    else
    {
      first_seg->pkt_len =
          (uint16_t)(first_seg->pkt_len + rx_packet_len);
      first_seg->nb_segs++;
      last_seg->next = rxm;
    }
    if (!(rx_status & (1 << IAVF_RX_DESC_STATUS_EOF_SHIFT)))
    {
      last_seg = rxm;
      continue;
    }
    rxm->next = ((void *)0);
    if (__builtin_expect(!!(rxq->crc_len > 0), 0))
    {
      first_seg->pkt_len -= 4;
      if (rx_packet_len <= 4)
      {
        rte_pktmbuf_free_seg(rxm);
        first_seg->nb_segs--;
        last_seg->data_len =
            (uint16_t)(last_seg->data_len - (4 - rx_packet_len));
        last_seg->next = ((void *)0);
      }
      else
        rxm->data_len = (uint16_t)(rx_packet_len - 4);
    }
    first_seg->port = rxq->port_id;
    first_seg->ol_flags = 0;
    iavf_rxd_to_vlan_tci(first_seg, &rxd);
    pkt_flags = iavf_rxd_to_pkt_flags(qword1);
    first_seg->packet_type =
        ptype_tbl[(uint8_t)((qword1 & (0xFFULL << 30)) >> 30)];
    if (pkt_flags & (1ULL << 1))
      first_seg->hash.rss = (rxd.wb.qword0.hi_dword.rss);
    if (pkt_flags & (1ULL << 2))
      pkt_flags |= iavf_rxd_build_fdir(&rxd, first_seg);
    first_seg->ol_flags |= pkt_flags;
    rte_prefetch0(((void *)((uintptr_t)(first_seg->buf_addr) +
                            (first_seg->data_off))));
    rx_pkts[nb_rx++] = first_seg;
    first_seg = ((void *)0);
  }
  rxq->rx_tail = rx_id;
  rxq->pkt_first_seg = first_seg;
  rxq->pkt_last_seg = last_seg;
  iavf_update_rx_tail(rxq, nb_hold, rx_id);
  return nb_rx;
}

static inline int
iavf_rx_scan_hw_ring_flex_rxd(struct iavf_rx_queue *rxq,
                              struct rte_mbuf **rx_pkts, uint16_t nb_pkts)
{
  volatile union iavf_32b_rx_flex_desc *rxdp;
  struct rte_mbuf **rxep;
  struct rte_mbuf *mb;
  uint16_t stat_err0;
  uint16_t pkt_len;
  int32_t s[8], var, nb_dd;
  int32_t i, j, nb_rx = 0;
  int32_t nb_staged = 0;
  uint64_t pkt_flags;
  const uint32_t *ptype_tbl = rxq->vsi->adapter->ptype_tbl;
  uint64_t ts_ns;
  rxdp = (volatile union iavf_32b_rx_flex_desc *)&rxq->rx_ring[rxq->rx_tail];
  rxep = &rxq->sw_ring[rxq->rx_tail];
  stat_err0 = (rxdp->wb.status_error0);
  if (!(stat_err0 & (1 << IAVF_RX_FLEX_DESC_STATUS0_DD_S)))
    return 0;
  if (rxq->offloads & (1UL << (14)))
  {
    uint64_t sw_cur_time =
        rte_get_timer_cycles() / (rte_get_timer_hz() / 1000);
    if (sw_cur_time - rxq->hw_time_update > 4)
    {
      if (iavf_get_phc_time(rxq))
        rte_log(4U, iavf_logtype_driver,
                "%s(): "
                "get physical time failed"
                "\n",
                __func__);
      rxq->hw_time_update = sw_cur_time;
    }
  }
  for (i = 0; i < 32; i += 8, rxdp += 8, rxep += 8)
  {
    for (j = 8 - 1; j >= 0; j--)
      s[j] = (rxdp[j].wb.status_error0);
    rte_atomic_thread_fence(2);
    for (j = 0, nb_dd = 0; j < 8; j++)
    {
      var = s[j] & (1 << IAVF_RX_FLEX_DESC_STATUS0_DD_S);
      nb_dd += var;
    }
    for (j = 0; j < nb_dd; j++)
    {
      do
      {
      } while (0);
      mb = rxep[j];
      pkt_len = ((rxdp[j].wb.pkt_len) & (0x3FFF)) - rxq->crc_len;
      mb->data_len = pkt_len;
      mb->pkt_len = pkt_len;
      mb->ol_flags = 0;
      mb->packet_type = ptype_tbl[(0x3FF) &
                                  (rxdp[j].wb.ptype_flex_flags0)];
      iavf_flex_rxd_to_vlan_tci(mb, &rxdp[j]);
      iavf_flex_rxd_to_ipsec_crypto_status(mb, &rxdp[j],
                                           &rxq->stats.ipsec_crypto);
      rxd_to_pkt_fields_ops[rxq->rxdid](rxq, mb, &rxdp[j]);
      stat_err0 = (rxdp[j].wb.status_error0);
      pkt_flags = iavf_flex_rxd_error_to_pkt_flags(stat_err0);
      if (iavf_timestamp_dynflag > 0)
      {
        ts_ns = iavf_tstamp_convert_32b_64b(rxq->phc_time,
                                            (rxdp[j].wb.flex_ts.ts_high));
        rxq->phc_time = ts_ns;
        rxq->hw_time_update = rte_get_timer_cycles() /
                              (rte_get_timer_hz() / 1000);
        *((rte_mbuf_timestamp_t *)((uintptr_t)(mb) +
                                   (iavf_timestamp_dynfield_offset))) =
            ts_ns;
        mb->ol_flags |= iavf_timestamp_dynflag;
      }
      mb->ol_flags |= pkt_flags;
      if ((i + j) < nb_pkts)
      {
        rx_pkts[i + j] = rxep[j];
        nb_rx++;
      }
      else
      {
        rxq->rx_stage[nb_staged] = rxep[j];
        nb_staged++;
      }
    }
    if (nb_dd != 8)
      break;
  }
  rxq->rx_nb_avail = nb_staged;
  for (i = 0; i < (nb_rx + nb_staged); i++)
    rxq->sw_ring[rxq->rx_tail + i] = ((void *)0);
  return nb_rx;
}

static inline int
iavf_rx_scan_hw_ring(struct iavf_rx_queue *rxq, struct rte_mbuf **rx_pkts,
                     uint16_t nb_pkts)
{
  volatile union iavf_32byte_rx_desc *rxdp;
  struct rte_mbuf **rxep;
  struct rte_mbuf *mb;
  uint16_t pkt_len;
  uint64_t qword1;
  uint32_t rx_status;
  int32_t s[8], var, nb_dd;
  int32_t i, j, nb_rx = 0;
  int32_t nb_staged = 0;
  uint64_t pkt_flags;
  const uint32_t *ptype_tbl = rxq->vsi->adapter->ptype_tbl;
  rxdp = &rxq->rx_ring[rxq->rx_tail];
  rxep = &rxq->sw_ring[rxq->rx_tail];
  qword1 = (rxdp->wb.qword1.status_error_len);
  rx_status = (qword1 & (((1UL << (IAVF_RX_DESC_STATUS_LAST)) - 1) << 0)) >>
              0;
  if (!(rx_status & (1 << IAVF_RX_DESC_STATUS_DD_SHIFT)))
    return 0;
  for (i = 0; i < 32; i += 8, rxdp += 8, rxep += 8)
  {
    for (j = 8 - 1; j >= 0; j--)
    {
      qword1 = (rxdp[j].wb.qword1.status_error_len);
      s[j] =
          (qword1 & (((1UL << (IAVF_RX_DESC_STATUS_LAST)) - 1) << 0)) >> 0;
    }
    rte_atomic_thread_fence(2);
    for (j = 0, nb_dd = 0; j < 8; j++)
    {
      var = s[j] & (1 << IAVF_RX_DESC_STATUS_DD_SHIFT);
      nb_dd += var;
    }
    for (j = 0; j < nb_dd; j++)
    {
      do
      {
      } while (0);
      mb = rxep[j];
      qword1 = (rxdp[j].wb.qword1.status_error_len);
      pkt_len = ((qword1 & (0x3FFFULL << 38)) >> 38) - rxq->crc_len;
      mb->data_len = pkt_len;
      mb->pkt_len = pkt_len;
      mb->ol_flags = 0;
      iavf_rxd_to_vlan_tci(mb, &rxdp[j]);
      pkt_flags = iavf_rxd_to_pkt_flags(qword1);
      mb->packet_type =
          ptype_tbl[(uint8_t)((qword1 & (0xFFULL << 30)) >> 30)];
      if (pkt_flags & (1ULL << 1))
        mb->hash.rss = (rxdp[j].wb.qword0.hi_dword.rss);
      if (pkt_flags & (1ULL << 2))
        pkt_flags |= iavf_rxd_build_fdir(&rxdp[j], mb);
      mb->ol_flags |= pkt_flags;
      if ((i + j) < nb_pkts)
      {
        rx_pkts[i + j] = rxep[j];
        nb_rx++;
      }
      else
      {
        rxq->rx_stage[nb_staged] = rxep[j];
        nb_staged++;
      }
    }
    if (nb_dd != 8)
      break;
  }
  rxq->rx_nb_avail = nb_staged;
  for (i = 0; i < (nb_rx + nb_staged); i++)
    rxq->sw_ring[rxq->rx_tail + i] = ((void *)0);
  return nb_rx;
}

static inline uint16_t
iavf_rx_fill_from_stage(struct iavf_rx_queue *rxq,
                        struct rte_mbuf **rx_pkts, uint16_t nb_pkts)
{
  uint16_t i;
  struct rte_mbuf **stage = &rxq->rx_stage[rxq->rx_next_avail];
  nb_pkts = (uint16_t) __extension__(
      {
				       __typeof__ (nb_pkts) _a = (nb_pkts);
				       __typeof__ (rxq->rx_nb_avail) _b =
				       (rxq->rx_nb_avail);
				       _a < _b ? _a : _b; });
  for (i = 0; i < nb_pkts; i++)
    rx_pkts[i] = stage[i];
  rxq->rx_nb_avail = (uint16_t)(rxq->rx_nb_avail - nb_pkts);
  rxq->rx_next_avail = (uint16_t)(rxq->rx_next_avail + nb_pkts);
  return nb_pkts;
}

static inline int
iavf_rx_alloc_bufs(struct iavf_rx_queue *rxq)
{
  volatile union iavf_32byte_rx_desc *rxdp;
  struct rte_mbuf **rxep;
  struct rte_mbuf *mb;
  uint16_t alloc_idx, i;
  uint64_t dma_addr;
  int diag;
  alloc_idx = (uint16_t)(rxq->rx_free_trigger - (rxq->rx_free_thresh - 1));
  rxep = &rxq->sw_ring[alloc_idx];
  diag = rte_mempool_get_bulk(rxq->mp, (void *)rxep, rxq->rx_free_thresh);
  if (__builtin_expect(!!(diag != 0), 0))
  {
    do
    {
    } while (0);
    return -12;
  }
  rxdp = &rxq->rx_ring[alloc_idx];
  for (i = 0; i < rxq->rx_free_thresh; i++)
  {
    if (__builtin_expect(!!(i < (rxq->rx_free_thresh - 1)), 1))
      rte_prefetch0(rxep[i + 1]);
    mb = rxep[i];
    rte_mbuf_refcnt_set(mb, 1);
    mb->next = ((void *)0);
    mb->data_off = 128;
    mb->nb_segs = 1;
    mb->port = rxq->port_id;
    dma_addr = (rte_mbuf_data_iova_default(mb));
    rxdp[i].read.hdr_addr = 0;
    rxdp[i].read.pkt_addr = dma_addr;
  }
  __asm__ volatile("fence w, w" ::: "memory");
  rte_write32_wc_relaxed(((rxq->rx_free_trigger)), rxq->qrx_tail);
  rxq->rx_free_trigger =
      (uint16_t)(rxq->rx_free_trigger + rxq->rx_free_thresh);
  if (rxq->rx_free_trigger >= rxq->nb_rx_desc)
    rxq->rx_free_trigger = (uint16_t)(rxq->rx_free_thresh - 1);
  return 0;
}

static inline uint16_t
rx_recv_pkts(void *rx_queue, struct rte_mbuf **rx_pkts, uint16_t nb_pkts)
{
  struct iavf_rx_queue *rxq = (struct iavf_rx_queue *)rx_queue;
  uint16_t nb_rx = 0;
  if (!nb_pkts)
    return 0;
  if (rxq->rx_nb_avail)
    return iavf_rx_fill_from_stage(rxq, rx_pkts, nb_pkts);
  if (rxq->rxdid >= IAVF_RXDID_FLEX_NIC && rxq->rxdid <= IAVF_RXDID_LAST)
    nb_rx = (uint16_t)iavf_rx_scan_hw_ring_flex_rxd(rxq, rx_pkts, nb_pkts);
  else
    nb_rx = (uint16_t)iavf_rx_scan_hw_ring(rxq, rx_pkts, nb_pkts);
  rxq->rx_next_avail = 0;
  rxq->rx_tail = (uint16_t)(rxq->rx_tail + nb_rx + rxq->rx_nb_avail);
  if (rxq->rx_tail > rxq->rx_free_trigger)
  {
    if (iavf_rx_alloc_bufs(rxq) != 0)
    {
      uint16_t i, j, nb_staged;
      nb_staged = rxq->rx_nb_avail;
      rxq->rx_nb_avail = 0;
      rxq->rx_tail = (uint16_t)(rxq->rx_tail - (nb_rx + nb_staged));
      for (i = 0, j = rxq->rx_tail; i < nb_rx; i++, j++)
      {
        rxq->sw_ring[j] = rx_pkts[i];
        rx_pkts[i] = ((void *)0);
      }
      for (i = 0, j = rxq->rx_tail + nb_rx; i < nb_staged; i++, j++)
      {
        rxq->sw_ring[j] = rxq->rx_stage[i];
        rx_pkts[i] = ((void *)0);
      }
      return 0;
    }
  }
  if (rxq->rx_tail >= rxq->nb_rx_desc)
    rxq->rx_tail = 0;
  do
  {
  } while (0);
  return nb_rx;
}

static uint16_t
iavf_recv_pkts_bulk_alloc(void *rx_queue,
                          struct rte_mbuf **rx_pkts, uint16_t nb_pkts)
{
  uint16_t nb_rx = 0, n, count;
  if (__builtin_expect(!!(nb_pkts == 0), 0))
    return 0;
  if (__builtin_expect(!!(nb_pkts <= 32), 1))
    return rx_recv_pkts(rx_queue, rx_pkts, nb_pkts);
  while (nb_pkts)
  {
    n = __extension__(
        {
			  __typeof__ (nb_pkts) _a = (nb_pkts);
			  __typeof__ (32) _b = (32); _a < _b ? _a : _b; });
    count = rx_recv_pkts(rx_queue, &rx_pkts[nb_rx], n);
    nb_rx = (uint16_t)(nb_rx + count);
    nb_pkts = (uint16_t)(nb_pkts - count);
    if (count < n)
      break;
  }
  return nb_rx;
}

static inline int
iavf_xmit_cleanup(struct iavf_tx_queue *txq)
{
  struct iavf_tx_entry *sw_ring = txq->sw_ring;
  uint16_t last_desc_cleaned = txq->last_desc_cleaned;
  uint16_t nb_tx_desc = txq->nb_tx_desc;
  uint16_t desc_to_clean_to;
  uint16_t nb_tx_to_clean;
  volatile struct iavf_tx_desc *txd = txq->tx_ring;
  desc_to_clean_to = (uint16_t)(last_desc_cleaned + txq->rs_thresh);
  if (desc_to_clean_to >= nb_tx_desc)
    desc_to_clean_to = (uint16_t)(desc_to_clean_to - nb_tx_desc);
  desc_to_clean_to = sw_ring[desc_to_clean_to].last_id;
  if ((txd[desc_to_clean_to].cmd_type_offset_bsz &
       ((0xFUL << 0))) != (IAVF_TX_DESC_DTYPE_DESC_DONE))
  {
    do
    {
    } while (0);
    return -1;
  }
  if (last_desc_cleaned > desc_to_clean_to)
    nb_tx_to_clean = (uint16_t)((nb_tx_desc - last_desc_cleaned) +
                                desc_to_clean_to);
  else
    nb_tx_to_clean = (uint16_t)(desc_to_clean_to - last_desc_cleaned);
  txd[desc_to_clean_to].cmd_type_offset_bsz = 0;
  txq->last_desc_cleaned = desc_to_clean_to;
  txq->nb_free = (uint16_t)(txq->nb_free + nb_tx_to_clean);
  return 0;
}

static inline uint16_t
iavf_calc_context_desc(struct rte_mbuf *mb, uint8_t vlan_flag)
{
  uint64_t flags = mb->ol_flags;
  if (flags & ((1ULL << 50) | (1ULL << 42) |
               (0xFULL << 45) | (1ULL << 58) | (1ULL << 41)))
    return 1;
  if (flags & (1ULL << 57) && vlan_flag & (1UL << (1)))
    return 1;
  if (((rte_pmd_iavf_tx_lldp_dynfield_offset > 0) &&
       (*((uint8_t *)((uintptr_t)((mb)) +
                      (rte_pmd_iavf_tx_lldp_dynfield_offset))))))
    return 1;
  return 0;
}

static inline void
iavf_fill_ctx_desc_cmd_field(volatile uint64_t *field, struct rte_mbuf *m,
                             uint8_t vlan_flag)
{
  uint64_t cmd = 0;
  if (m->ol_flags & ((1ULL << 50) | (1ULL << 42)))
    cmd = IAVF_TX_CTX_DESC_TSO << 4;
  if (m->ol_flags & (1ULL << 57) && vlan_flag & (1UL << (1)))
  {
    cmd |= IAVF_TX_CTX_DESC_IL2TAG2 << 4;
  }
  if (((rte_pmd_iavf_tx_lldp_dynfield_offset > 0) &&
       (*((uint8_t *)((uintptr_t)((m)) +
                      (rte_pmd_iavf_tx_lldp_dynfield_offset))))))
    cmd |= IAVF_TX_CTX_DESC_SWTCH_UPLINK << 4;
  *field |= cmd;
}

static inline void
iavf_fill_ctx_desc_ipsec_field(volatile uint64_t *field,
                               struct iavf_ipsec_crypto_pkt_metadata
                                   *ipsec_md)
{
  uint64_t ipsec_field = (uint64_t)ipsec_md->ctx_desc_ipsec_params << (11);
  *field |= ipsec_field;
}

static inline void
iavf_fill_ctx_desc_tunnelling_field(volatile uint64_t *qw0,
                                    const struct rte_mbuf *m)
{
  uint64_t eip_typ = IAVF_TX_CTX_DESC_EIPT_NONE;
  uint64_t eip_len = 0;
  uint64_t eip_noinc = 0;
  switch (m->ol_flags & ((1ULL << 59) | (1ULL << 60) | (1ULL << 58)))
  {
  case (1ULL << 59):
    eip_typ = IAVF_TX_CTX_DESC_EIPT_IPV4_NO_CHECKSUM_OFFLOAD;
    eip_len = m->outer_l3_len >> 2;
    break;
  case (1ULL << 59) | (1ULL << 58):
    eip_typ = IAVF_TX_CTX_DESC_EIPT_IPV4_CHECKSUM_OFFLOAD;
    eip_len = m->outer_l3_len >> 2;
    break;
  case (1ULL << 60):
    eip_typ = IAVF_TX_CTX_DESC_EIPT_IPV6;
    eip_len = m->outer_l3_len >> 2;
    break;
  }
  if (!(m->ol_flags & (1ULL << 43)))
  {
    switch (m->ol_flags & (0xFULL << 45))
    {
    case (0x3ULL << 45):
      break;
    case (0x1ULL << 45):
    case (0x6ULL << 45):
    case (0x7ULL << 45):
    case (0x4ULL << 45):
      eip_typ |= (1ULL << (9));
      break;
    case (0x2ULL << 45):
      eip_typ |= (0x2ULL << 9);
      break;
    default:
      do
      {
      } while (0);
      return;
    }
    eip_typ |= (m->l2_len >> 1) << 12;
    if ((eip_typ & (IAVF_TX_CTX_EXT_IP_IPV6 |
                    IAVF_TX_CTX_EXT_IP_IPV4 |
                    IAVF_TX_CTX_EXT_IP_IPV4_NO_CSUM)) &&
        (eip_typ & (1ULL << (9))) && (m->ol_flags & (1ULL << 41)))
      eip_typ |= (1ULL << (23));
  }
  *qw0 = eip_typ << (0) | eip_len << (2) | eip_noinc << (11);
}

static inline uint16_t
iavf_fill_ctx_desc_segmentation_field(volatile uint64_t *field,
                                      struct rte_mbuf *m,
                                      struct iavf_ipsec_crypto_pkt_metadata
                                          *ipsec_md)
{
  uint64_t segmentation_field = 0;
  uint64_t total_length = 0;
  if (m->ol_flags & (1ULL << 43))
  {
    total_length = ipsec_md->l4_payload_len;
  }
  else
  {
    total_length = m->pkt_len - (m->l2_len + m->l3_len + m->l4_len);
    if (m->ol_flags & (0xFULL << 45))
      total_length -= m->outer_l3_len + m->outer_l2_len;
  }
  segmentation_field =
      (((uint64_t)total_length << 30) &
       (0x3FFFFULL << 30)) |
      (((uint64_t)m->tso_segsz << 50) & (0x3FFFULL << 50));
  *field |= segmentation_field;
  return total_length;
}

struct iavf_tx_context_desc_qws
{
  uint64_t qw0;
  uint64_t qw1;
};
static inline void
iavf_fill_context_desc(volatile struct iavf_tx_context_desc *desc,
                       struct rte_mbuf *m,
                       struct iavf_ipsec_crypto_pkt_metadata *ipsec_md,
                       uint16_t *tlen, uint8_t vlan_flag)
{
  volatile struct iavf_tx_context_desc_qws *desc_qws =
      (volatile struct iavf_tx_context_desc_qws *)desc;
  desc_qws->qw1 = IAVF_TX_DESC_DTYPE_CONTEXT;
  iavf_fill_ctx_desc_cmd_field(&desc_qws->qw1, m, vlan_flag);
  if (m->ol_flags & ((1ULL << 50) | (1ULL << 42)))
  {
    if (m->ol_flags & (1ULL << 43))
      iavf_fill_ctx_desc_ipsec_field(&desc_qws->qw1, ipsec_md);
    *tlen = iavf_fill_ctx_desc_segmentation_field(&desc_qws->qw1,
                                                  m, ipsec_md);
  }
  if (m->ol_flags & (0xFULL << 45))
    iavf_fill_ctx_desc_tunnelling_field(&desc_qws->qw0, m);
  else
    desc_qws->qw0 = 0;
  desc_qws->qw0 = (desc_qws->qw0);
  desc_qws->qw1 = (desc_qws->qw1);
  if (vlan_flag & (1UL << (1)))
    desc->l2tag2 = m->vlan_tci;
}

static inline void
iavf_fill_ipsec_desc(volatile struct iavf_tx_ipsec_desc *desc,
                     const struct iavf_ipsec_crypto_pkt_metadata *md,
                     uint16_t *ipsec_len)
{
  desc->qw0 =
      (((uint64_t)md->l4_payload_len << 0) | ((uint64_t)md->esn << 16) | ((uint64_t)md->esp_trailer_len << 48));
  desc->qw1 =
      (((uint64_t)md->sa_idx << 32) | ((uint64_t)md->next_proto << 8) |
       ((uint64_t)(md->len_iv & 0x3) << 6) |
       ((uint64_t)(md->ol_flags & (0x1 << 3) ? 1ULL : 0ULL) << 5) | (uint64_t)IAVF_TX_DESC_DTYPE_IPSEC);
  *ipsec_len =
      sizeof(struct rte_esp_hdr) + (md->len_iv >> 2) +
      (md->ol_flags & (0x1 << 3) ? sizeof(struct rte_udp_hdr) : 0);
}

static inline void
iavf_build_data_desc_cmd_offset_fields(volatile uint64_t *qw1,
                                       struct rte_mbuf *m, uint8_t vlan_flag)
{
  uint64_t command = 0;
  uint64_t offset = 0;
  uint64_t l2tag1 = 0;
  *qw1 = IAVF_TX_DESC_DTYPE_DATA;
  command = (uint64_t)IAVF_TX_DESC_CMD_ICRC;
  if ((vlan_flag & (1UL << (0))) && m->ol_flags & (1ULL << 57))
  {
    command |= (uint64_t)IAVF_TX_DESC_CMD_IL2TAG1;
    l2tag1 |= m->vlan_tci;
  }
  if ((m->ol_flags &
       (((1ULL << 54) | (3ULL << 52) | (1ULL << 50) | (1ULL << 42) |
         (1ULL << 58) | (1ULL << 41)) |
        (1ULL << 43))) == 0)
    goto skip_cksum;
  if (m->ol_flags & (0xFULL << 45) && !(m->ol_flags & (1ULL << 43)))
    offset |= (m->outer_l2_len >> 1) << IAVF_TX_DESC_LENGTH_MACLEN_SHIFT;
  else
    offset |= (m->l2_len >> 1) << IAVF_TX_DESC_LENGTH_MACLEN_SHIFT;
  if (m->ol_flags & (1ULL << 54))
  {
    if (m->ol_flags & (1ULL << 55))
    {
      command |= IAVF_TX_DESC_CMD_IIPT_IPV4_CSUM;
      offset |= (m->l3_len >> 2) << IAVF_TX_DESC_LENGTH_IPLEN_SHIFT;
    }
  }
  else if (m->ol_flags & (1ULL << 55))
  {
    command |= IAVF_TX_DESC_CMD_IIPT_IPV4;
    offset |= (m->l3_len >> 2) << IAVF_TX_DESC_LENGTH_IPLEN_SHIFT;
  }
  else if (m->ol_flags & (1ULL << 56))
  {
    command |= IAVF_TX_DESC_CMD_IIPT_IPV6;
    offset |= (m->l3_len >> 2) << IAVF_TX_DESC_LENGTH_IPLEN_SHIFT;
  }
  if (m->ol_flags & ((1ULL << 50) | (1ULL << 42)))
  {
    if (m->ol_flags & (1ULL << 50))
      command |= IAVF_TX_DESC_CMD_L4T_EOFT_TCP;
    else
      command |= IAVF_TX_DESC_CMD_L4T_EOFT_UDP;
    offset |= (m->l4_len >> 2) << IAVF_TX_DESC_LENGTH_L4_FC_LEN_SHIFT;
    *qw1 =
        ((((uint64_t)command << (4)) & (0x3FFUL << (4))) |
         (((uint64_t)offset << (16)) & (0x3FFFFULL << (16))) | ((uint64_t)l2tag1 << (48)));
    return;
  }
  switch (m->ol_flags & (3ULL << 52))
  {
  case (1ULL << 52):
    command |= IAVF_TX_DESC_CMD_L4T_EOFT_TCP;
    offset |= (sizeof(struct rte_tcp_hdr) >> 2) << IAVF_TX_DESC_LENGTH_L4_FC_LEN_SHIFT;
    break;
  case (2ULL << 52):
    command |= IAVF_TX_DESC_CMD_L4T_EOFT_SCTP;
    offset |= (sizeof(struct rte_sctp_hdr) >> 2) << IAVF_TX_DESC_LENGTH_L4_FC_LEN_SHIFT;
    break;
  case (3ULL << 52):
    command |= IAVF_TX_DESC_CMD_L4T_EOFT_UDP;
    offset |= (sizeof(struct rte_udp_hdr) >> 2) << IAVF_TX_DESC_LENGTH_L4_FC_LEN_SHIFT;
    break;
  }
skip_cksum:
  *qw1 =
      ((((uint64_t)command << (4)) & (0x3FFUL << (4))) |
       (((uint64_t)offset << (16)) & (0x3FFFFULL << (16))) | ((uint64_t)l2tag1 << (48)));
}

static inline uint16_t
iavf_calc_pkt_desc(struct rte_mbuf *tx_pkt)
{
  struct rte_mbuf *txd = tx_pkt;
  uint16_t count = 0;
  while (txd != ((void *)0))
  {
    count += (txd->data_len + ((0x3FFFULL << 34) >> 34) - 1) /
             ((0x3FFFULL << 34) >> 34);
    txd = txd->next;
  }
  return count;
}

static inline void
iavf_fill_data_desc(volatile struct iavf_tx_desc *desc,
                    uint64_t desc_template, uint16_t buffsz,
                    uint64_t buffer_addr)
{
  desc->cmd_type_offset_bsz = desc_template;
  desc->cmd_type_offset_bsz |=
      (((uint64_t)buffsz << (34)) & (0x3FFFULL << (34)));
  desc->buffer_addr = (buffer_addr);
  desc->cmd_type_offset_bsz = (desc->cmd_type_offset_bsz);
}

static struct iavf_ipsec_crypto_pkt_metadata *
iavf_ipsec_crypto_get_pkt_metadata(const struct iavf_tx_queue *txq,
                                   struct rte_mbuf *m)
{
  if (m->ol_flags & (1ULL << 43))
    return ((struct iavf_ipsec_crypto_pkt_metadata *)((uintptr_t)(m) +
                                                      (txq->ipsec_crypto_pkt_md_offset)));
  return ((void *)0);
}

uint16_t
iavf_xmit_pkts(void *tx_queue, struct rte_mbuf **tx_pkts, uint16_t nb_pkts)
{
  struct iavf_tx_queue *txq = tx_queue;
  volatile struct iavf_tx_desc *txr = txq->tx_ring;
  struct iavf_tx_entry *txe_ring = txq->sw_ring;
  struct iavf_tx_entry *txe, *txn;
  struct rte_mbuf *mb, *mb_seg;
  uint64_t buf_dma_addr;
  uint16_t desc_idx, desc_idx_last;
  uint16_t idx;
  uint16_t slen;
  if (txq->nb_free < txq->free_thresh)
    iavf_xmit_cleanup(txq);
  desc_idx = txq->tx_tail;
  txe = &txe_ring[desc_idx];
  for (idx = 0; idx < nb_pkts; idx++)
  {
    volatile struct iavf_tx_desc *ddesc;
    struct iavf_ipsec_crypto_pkt_metadata *ipsec_md;
    uint16_t nb_desc_ctx, nb_desc_ipsec;
    uint16_t nb_desc_data, nb_desc_required;
    uint16_t tlen = 0, ipseclen = 0;
    uint64_t ddesc_template = 0;
    uint64_t ddesc_cmd = 0;
    mb = tx_pkts[idx];
    do
    {
      if ((txe->mbuf) != ((void *)0))
        rte_prefetch0(txe->mbuf);
    } while (0);
    ipsec_md = iavf_ipsec_crypto_get_pkt_metadata(txq, mb);
    nb_desc_data = mb->nb_segs;
    nb_desc_ctx = iavf_calc_context_desc(mb, txq->vlan_flag);
    nb_desc_ipsec = !!(mb->ol_flags & (1ULL << 43));
    if (mb->ol_flags & (1ULL << 50))
      nb_desc_required =
          iavf_calc_pkt_desc(mb) + nb_desc_ctx + nb_desc_ipsec;
    else
      nb_desc_required = nb_desc_data + nb_desc_ctx + nb_desc_ipsec;
    desc_idx_last = (uint16_t)(desc_idx + nb_desc_required - 1);
    if (desc_idx_last >= txq->nb_tx_desc)
      desc_idx_last = (uint16_t)(desc_idx_last - txq->nb_tx_desc);
    do
    {
    } while (0);
    if (nb_desc_required > txq->nb_free)
    {
      if (iavf_xmit_cleanup(txq))
      {
        if (idx == 0)
          return 0;
        goto end_of_tx;
      }
      if (__builtin_expect(!!(nb_desc_required > txq->rs_thresh), 0))
      {
        while (nb_desc_required > txq->nb_free)
        {
          if (iavf_xmit_cleanup(txq))
          {
            if (idx == 0)
              return 0;
            goto end_of_tx;
          }
        }
      }
    }
    iavf_build_data_desc_cmd_offset_fields(&ddesc_template, mb,
                                           txq->vlan_flag);
    if (nb_desc_ctx)
    {
      volatile struct iavf_tx_context_desc *ctx_desc =
          (volatile struct iavf_tx_context_desc *)&txr[desc_idx];
      *(volatile uint64_t *)ctx_desc = 0;
      txn = &txe_ring[txe->next_id];
      do
      {
        if ((txn->mbuf) != ((void *)0))
          rte_prefetch0(txn->mbuf);
      } while (0);
      if (txe->mbuf)
      {
        rte_pktmbuf_free_seg(txe->mbuf);
        txe->mbuf = ((void *)0);
      }
      iavf_fill_context_desc(ctx_desc, mb, ipsec_md, &tlen,
                             txq->vlan_flag);
      do
      {
      } while (0);
      txe->last_id = desc_idx_last;
      desc_idx = txe->next_id;
      txe = txn;
    }
    if (nb_desc_ipsec)
    {
      volatile struct iavf_tx_ipsec_desc *ipsec_desc =
          (volatile struct iavf_tx_ipsec_desc *)&txr[desc_idx];
      txn = &txe_ring[txe->next_id];
      do
      {
        if ((txn->mbuf) != ((void *)0))
          rte_prefetch0(txn->mbuf);
      } while (0);
      if (txe->mbuf)
      {
        rte_pktmbuf_free_seg(txe->mbuf);
        txe->mbuf = ((void *)0);
      }
      iavf_fill_ipsec_desc(ipsec_desc, ipsec_md, &ipseclen);
      do
      {
      } while (0);
      txe->last_id = desc_idx_last;
      desc_idx = txe->next_id;
      txe = txn;
    }
    mb_seg = mb;
    do
    {
      ddesc = (volatile struct iavf_tx_desc *)&txr[desc_idx];
      txn = &txe_ring[txe->next_id];
      do
      {
        if ((txn->mbuf) != ((void *)0))
          rte_prefetch0(txn->mbuf);
      } while (0);
      if (txe->mbuf)
        rte_pktmbuf_free_seg(txe->mbuf);
      txe->mbuf = mb_seg;
      if ((mb_seg->ol_flags & (1ULL << 43)) &&
          (mb_seg->ol_flags & ((1ULL << 50) | (1ULL << 42))))
      {
        slen = tlen + mb_seg->l2_len + mb_seg->l3_len +
               mb_seg->outer_l3_len + ipseclen;
        if (mb_seg->ol_flags & (3ULL << 52))
          slen += mb_seg->l4_len;
      }
      else
      {
        slen = mb_seg->data_len;
      }
      buf_dma_addr = rte_mbuf_data_iova(mb_seg);
      while ((mb_seg->ol_flags & ((1ULL << 50) |
                                  (1ULL << 42))) &&
             __builtin_expect(!!(slen > ((0x3FFFULL << 34) >> 34)), 0))
      {
        iavf_fill_data_desc(ddesc, ddesc_template,
                            ((0x3FFFULL << 34) >> 34), buf_dma_addr);
        do
        {
        } while (0);
        buf_dma_addr += ((0x3FFFULL << 34) >> 34);
        slen -= ((0x3FFFULL << 34) >> 34);
        txe->last_id = desc_idx_last;
        desc_idx = txe->next_id;
        txe = txn;
        ddesc = &txr[desc_idx];
        txn = &txe_ring[txe->next_id];
      }
      iavf_fill_data_desc(ddesc, ddesc_template, slen, buf_dma_addr);
      do
      {
      } while (0);
      txe->last_id = desc_idx_last;
      desc_idx = txe->next_id;
      txe = txn;
      mb_seg = mb_seg->next;
    } while (mb_seg);
    ddesc_cmd = IAVF_TX_DESC_CMD_EOP;
    txq->nb_used = (uint16_t)(txq->nb_used + nb_desc_required);
    txq->nb_free = (uint16_t)(txq->nb_free - nb_desc_required);
    if (txq->nb_used >= txq->rs_thresh)
    {
      do
      {
      } while (0);
      ddesc_cmd |= IAVF_TX_DESC_CMD_RS;
      txq->nb_used = 0;
    }
    ddesc->cmd_type_offset_bsz |= (ddesc_cmd << (4));
    do
    {
    } while (0);
  }
end_of_tx:
  __asm__ volatile("fence w, w" ::: "memory");
  do
  {
  } while (0);
  writel_relaxed(desc_idx, txq->qtx_tail);
  txq->tx_tail = desc_idx;
  return idx;
}

static int
iavf_check_vlan_up2tc(struct iavf_tx_queue *txq, struct rte_mbuf *m)
{
  struct rte_eth_dev *dev = &rte_eth_devices[txq->port_id];
  struct iavf_info *vf =
      (&((struct iavf_adapter *)dev->data->dev_private)->vf);
  uint16_t up;
  up = m->vlan_tci >> 13;
  if (!(vf->qos_cap->cap[txq->tc].tc_prio & (1UL << (up))))
  {
    do
    {
    } while (0);
    return -1;
  }
  else
  {
    return 0;
  }
}

static inline void
parse_ipv4(struct rte_ipv4_hdr *ipv4_hdr, struct offload_info *info)
{
  struct rte_tcp_hdr *tcp_hdr;
  info->l3_len = rte_ipv4_hdr_len(ipv4_hdr);
  info->l4_proto = ipv4_hdr->next_proto_id;
  if (info->l4_proto == IPPROTO_TCP)
  {
    tcp_hdr = (struct rte_tcp_hdr *)((char *)ipv4_hdr + info->l3_len);
    info->l4_len = (tcp_hdr->data_off & 0xf0) >> 2;
  }
  else if (info->l4_proto == IPPROTO_UDP)
  {
    info->l4_len = sizeof(struct rte_udp_hdr);
  }
  else
  {
    info->l4_len = 0;
  }
}

static inline void
parse_ipv6(struct rte_ipv6_hdr *ipv6_hdr, struct offload_info *info)
{
  struct rte_tcp_hdr *tcp_hdr;
  info->l3_len = sizeof(struct rte_ipv6_hdr);
  info->l4_proto = ipv6_hdr->proto;
  if (info->l4_proto == IPPROTO_TCP)
  {
    tcp_hdr = (struct rte_tcp_hdr *)((char *)ipv6_hdr + info->l3_len);
    info->l4_len = (tcp_hdr->data_off & 0xf0) >> 2;
  }
  else if (info->l4_proto == IPPROTO_UDP)
  {
    info->l4_len = sizeof(struct rte_udp_hdr);
  }
  else
  {
    info->l4_len = 0;
  }
}

static inline void
parse_ethernet(struct rte_ether_hdr *eth_hdr, struct offload_info *info)
{
  struct rte_ipv4_hdr *ipv4_hdr;
  struct rte_ipv6_hdr *ipv6_hdr;
  struct rte_vlan_hdr *vlan_hdr;
  info->l2_len = sizeof(struct rte_ether_hdr);
  info->ethertype = eth_hdr->ether_type;
  while (info->ethertype == __builtin_bswap16(0x8100) ||
         info->ethertype == __builtin_bswap16(0x88A8))
  {
    vlan_hdr = (struct rte_vlan_hdr *)((char *)eth_hdr + info->l2_len);
    info->l2_len += sizeof(struct rte_vlan_hdr);
    info->ethertype = vlan_hdr->eth_proto;
  }
  switch (info->ethertype)
  {
  case ((((uint16_t)(0x0800) & 0x00ff) << 8) | (((uint16_t)(0x0800) & 0xff00) >> 8)):
    ipv4_hdr = (struct rte_ipv4_hdr *)((char *)eth_hdr + info->l2_len);
    parse_ipv4(ipv4_hdr, info);
    break;
  case ((((uint16_t)(0x86DD) & 0x00ff) << 8) | (((uint16_t)(0x86DD) & 0xff00) >> 8)):
    ipv6_hdr = (struct rte_ipv6_hdr *)((char *)eth_hdr + info->l2_len);
    parse_ipv6(ipv6_hdr, info);
    break;
  default:
    info->l4_len = 0;
    info->l3_len = 0;
    info->l4_proto = 0;
    break;
  }
}

static inline void
update_tunnel_outer(struct offload_info *info)
{
  info->is_tunnel = 1;
  info->outer_ethertype = info->ethertype;
  info->outer_l2_len = info->l2_len;
  info->outer_l3_len = info->l3_len;
  info->outer_l4_proto = info->l4_proto;
}

static inline void
parse_gtp(struct rte_udp_hdr *udp_hdr, struct offload_info *info)
{
  struct rte_ipv4_hdr *ipv4_hdr;
  struct rte_ipv6_hdr *ipv6_hdr;
  struct rte_gtp_hdr *gtp_hdr;
  uint8_t gtp_len = sizeof(*gtp_hdr);
  uint8_t ip_ver;
  if (udp_hdr->dst_port != __builtin_bswap16(2123) &&
      udp_hdr->src_port != __builtin_bswap16(2123) &&
      udp_hdr->dst_port != __builtin_bswap16(2152))
    return;
  update_tunnel_outer(info);
  info->l2_len = 0;
  gtp_hdr = (struct rte_gtp_hdr *)((char *)udp_hdr +
                                   sizeof(struct rte_udp_hdr));
  if (gtp_hdr->msg_type == 0xff)
  {
    ip_ver = *(uint8_t *)((char *)udp_hdr +
                          sizeof(struct rte_udp_hdr) +
                          sizeof(struct rte_gtp_hdr));
    ip_ver = (ip_ver) & 0xf0;
    if (ip_ver == 0x40)
    {
      ipv4_hdr = (struct rte_ipv4_hdr *)((char *)gtp_hdr + gtp_len);
      info->ethertype = __builtin_bswap16(0x0800);
      parse_ipv4(ipv4_hdr, info);
    }
    else if (ip_ver == 0x60)
    {
      ipv6_hdr = (struct rte_ipv6_hdr *)((char *)gtp_hdr + gtp_len);
      info->ethertype = __builtin_bswap16(0x86DD);
      parse_ipv6(ipv6_hdr, info);
    }
  }
  else
  {
    info->ethertype = 0;
    info->l4_len = 0;
    info->l3_len = 0;
    info->l4_proto = 0;
  }
  info->l2_len += (sizeof(struct rte_udp_hdr) + sizeof(struct rte_gtp_hdr));
}

static inline void
parse_vxlan(struct rte_udp_hdr *udp_hdr, struct offload_info *info)
{
  struct rte_ether_hdr *eth_hdr;
  if (udp_hdr->dst_port != __builtin_bswap16(4789))
    return;
  update_tunnel_outer(info);
  eth_hdr = (struct rte_ether_hdr *)((char *)udp_hdr +
                                     sizeof(struct rte_udp_hdr) +
                                     sizeof(struct rte_vxlan_hdr));
  parse_ethernet(eth_hdr, info);
  info->l2_len +=
      (sizeof(struct rte_udp_hdr) + sizeof(struct rte_vxlan_hdr));
}

static inline void
parse_vxlan_gpe(struct rte_udp_hdr *udp_hdr, struct offload_info *info)
{
  struct rte_ether_hdr *eth_hdr;
  struct rte_ipv4_hdr *ipv4_hdr;
  struct rte_ipv6_hdr *ipv6_hdr;
  struct rte_vxlan_gpe_hdr *vxlan_gpe_hdr;
  uint8_t vxlan_gpe_len = sizeof(*vxlan_gpe_hdr);
  if (udp_hdr->dst_port != __builtin_bswap16(vxlan_gpe_udp_port))
    return;
  vxlan_gpe_hdr = (struct rte_vxlan_gpe_hdr *)((char *)udp_hdr +
                                               sizeof(struct rte_udp_hdr));
  if (!vxlan_gpe_hdr->proto || vxlan_gpe_hdr->proto == 1)
  {
    update_tunnel_outer(info);
    ipv4_hdr = (struct rte_ipv4_hdr *)((char *)vxlan_gpe_hdr +
                                       vxlan_gpe_len);
    parse_ipv4(ipv4_hdr, info);
    info->ethertype = __builtin_bswap16(0x0800);
    info->l2_len = 0;
  }
  else if (vxlan_gpe_hdr->proto == 2)
  {
    update_tunnel_outer(info);
    ipv6_hdr = (struct rte_ipv6_hdr *)((char *)vxlan_gpe_hdr +
                                       vxlan_gpe_len);
    info->ethertype = __builtin_bswap16(0x86DD);
    parse_ipv6(ipv6_hdr, info);
    info->l2_len = 0;
  }
  else if (vxlan_gpe_hdr->proto == 3)
  {
    update_tunnel_outer(info);
    eth_hdr = (struct rte_ether_hdr *)((char *)vxlan_gpe_hdr +
                                       vxlan_gpe_len);
    parse_ethernet(eth_hdr, info);
  }
  else
  {
    return;
  }
  info->l2_len +=
      (sizeof(struct rte_udp_hdr) + sizeof(struct rte_vxlan_gpe_hdr));
}

static inline void
parse_geneve(struct rte_udp_hdr *udp_hdr, struct offload_info *info)
{
  struct rte_ether_hdr *eth_hdr;
  struct rte_ipv4_hdr *ipv4_hdr;
  struct rte_ipv6_hdr *ipv6_hdr;
  struct rte_geneve_hdr *geneve_hdr;
  uint16_t geneve_len;
  if (udp_hdr->dst_port != __builtin_bswap16(geneve_udp_port))
    return;
  geneve_hdr = (struct rte_geneve_hdr *)((char *)udp_hdr +
                                         sizeof(struct rte_udp_hdr));
  geneve_len = sizeof(struct rte_geneve_hdr) + geneve_hdr->opt_len * 4;
  if (!geneve_hdr->proto || geneve_hdr->proto == __builtin_bswap16(0x0800))
  {
    update_tunnel_outer(info);
    ipv4_hdr = (struct rte_ipv4_hdr *)((char *)geneve_hdr + geneve_len);
    parse_ipv4(ipv4_hdr, info);
    info->ethertype = __builtin_bswap16(0x0800);
    info->l2_len = 0;
  }
  else if (geneve_hdr->proto == __builtin_bswap16(0x86DD))
  {
    update_tunnel_outer(info);
    ipv6_hdr = (struct rte_ipv6_hdr *)((char *)geneve_hdr + geneve_len);
    info->ethertype = __builtin_bswap16(0x86DD);
    parse_ipv6(ipv6_hdr, info);
    info->l2_len = 0;
  }
  else if (geneve_hdr->proto == __builtin_bswap16(0x6558))
  {
    update_tunnel_outer(info);
    eth_hdr = (struct rte_ether_hdr *)((char *)geneve_hdr + geneve_len);
    parse_ethernet(eth_hdr, info);
  }
  else
  {
    return;
  }
  info->l2_len +=
      (sizeof(struct rte_udp_hdr) + sizeof(struct rte_geneve_hdr) +
       ((struct rte_geneve_hdr *)geneve_hdr)->opt_len * 4);
}

static inline void
parse_gre(struct simple_gre_hdr *gre_hdr, struct offload_info *info)
{
  struct rte_ether_hdr *eth_hdr;
  struct rte_ipv4_hdr *ipv4_hdr;
  struct rte_ipv6_hdr *ipv6_hdr;
  uint8_t gre_len = 0;
  gre_len += sizeof(struct simple_gre_hdr);
  if (gre_hdr->flags & __builtin_bswap16(0x2000))
    gre_len += 4;
  if (gre_hdr->flags & __builtin_bswap16(0x1000))
    gre_len += 4;
  if (gre_hdr->flags & __builtin_bswap16(0x8000))
    gre_len += 4;
  if (gre_hdr->proto == __builtin_bswap16(0x0800))
  {
    update_tunnel_outer(info);
    ipv4_hdr = (struct rte_ipv4_hdr *)((char *)gre_hdr + gre_len);
    parse_ipv4(ipv4_hdr, info);
    info->ethertype = __builtin_bswap16(0x0800);
    info->l2_len = 0;
  }
  else if (gre_hdr->proto == __builtin_bswap16(0x86DD))
  {
    update_tunnel_outer(info);
    ipv6_hdr = (struct rte_ipv6_hdr *)((char *)gre_hdr + gre_len);
    info->ethertype = __builtin_bswap16(0x86DD);
    parse_ipv6(ipv6_hdr, info);
    info->l2_len = 0;
  }
  else if (gre_hdr->proto == __builtin_bswap16(0x6558))
  {
    update_tunnel_outer(info);
    eth_hdr = (struct rte_ether_hdr *)((char *)gre_hdr + gre_len);
    parse_ethernet(eth_hdr, info);
  }
  else
  {
    return;
  }
  info->l2_len += gre_len;
}

static inline void
parse_encap_ip(void *encap_ip, struct offload_info *info)
{
  struct rte_ipv4_hdr *ipv4_hdr = encap_ip;
  struct rte_ipv6_hdr *ipv6_hdr = encap_ip;
  uint8_t ip_version;
  ip_version = (ipv4_hdr->version_ihl & 0xf0) >> 4;
  if (ip_version != 4 && ip_version != 6)
    return;
  info->is_tunnel = 1;
  info->outer_ethertype = info->ethertype;
  info->outer_l2_len = info->l2_len;
  info->outer_l3_len = info->l3_len;
  if (ip_version == 4)
  {
    parse_ipv4(ipv4_hdr, info);
    info->ethertype = __builtin_bswap16(0x0800);
  }
  else
  {
    parse_ipv6(ipv6_hdr, info);
    info->ethertype = __builtin_bswap16(0x86DD);
  }
  info->l2_len = 0;
}

static inline int
check_mbuf_len(struct offload_info *info, struct rte_mbuf *m)
{
  if (m->ol_flags & (0xFULL << 45))
  {
    if (info->outer_l2_len != m->outer_l2_len)
    {
      do
      {
      } while (0);
      return -1;
    }
    if (info->outer_l3_len != m->outer_l3_len)
    {
      do
      {
      } while (0);
      return -1;
    }
  }
  if (info->l2_len != m->l2_len)
  {
    do
    {
    } while (0);
    return -1;
  }
  if (info->l3_len != m->l3_len)
  {
    do
    {
    } while (0);
    return -1;
  }
  if (info->l4_len != m->l4_len)
  {
    do
    {
    } while (0);
    return -1;
  }
  return 0;
}

static inline int
check_ether_type(struct offload_info *info, struct rte_mbuf *m)
{
  int ret = 0;
  if (m->ol_flags & (0xFULL << 45))
  {
    if (info->outer_ethertype == __builtin_bswap16(0x0800))
    {
      if (!(m->ol_flags & (1ULL << 59)))
      {
        do
        {
        } while (0);
        ret = -1;
      }
      if (m->ol_flags & (1ULL << 60))
      {
        do
        {
        } while (0);
        ret = -1;
      }
    }
    else if (info->outer_ethertype == __builtin_bswap16(0x86DD))
    {
      if (!(m->ol_flags & (1ULL << 60)))
      {
        do
        {
        } while (0);
        ret = -1;
      }
      if (m->ol_flags & (1ULL << 59))
      {
        do
        {
        } while (0);
        ret = -1;
      }
    }
  }
  if (info->ethertype == __builtin_bswap16(0x0800))
  {
    if (!(m->ol_flags & (1ULL << 55)))
    {
      do
      {
      } while (0);
      ret = -1;
    }
    if (m->ol_flags & (1ULL << 56))
    {
      do
      {
      } while (0);
      ret = -1;
    }
  }
  else if (info->ethertype == __builtin_bswap16(0x86DD))
  {
    if (!(m->ol_flags & (1ULL << 56)))
    {
      do
      {
      } while (0);
      ret = -1;
    }
    if (m->ol_flags & (1ULL << 55))
    {
      do
      {
      } while (0);
      ret = -1;
    }
  }
  return ret;
}

__attribute__((__unused__)) static inline int iavf_check_mbuf(struct rte_mbuf *m)
{
  struct rte_ether_hdr *eth_hdr;
  void *l3_hdr = ((void *)0);
  struct offload_info info = {0};
  uint64_t ol_flags = m->ol_flags;
  uint64_t tunnel_type = ol_flags & (0xFULL << 45);
  eth_hdr =
      ((struct rte_ether_hdr *)(void *)((char *)(m)->buf_addr +
                                        (m)->data_off + (0)));
  parse_ethernet(eth_hdr, &info);
  l3_hdr = (char *)eth_hdr + info.l2_len;
  if (info.l4_proto == IPPROTO_UDP)
  {
    struct rte_udp_hdr *udp_hdr;
    udp_hdr = (struct rte_udp_hdr *)((char *)l3_hdr + info.l3_len);
    parse_gtp(udp_hdr, &info);
    if (info.is_tunnel)
    {
      if (!tunnel_type)
      {
        do
        {
        } while (0);
        return -1;
      }
      if (tunnel_type != (0x7ULL << 45))
      {
        do
        {
        } while (0);
        return -1;
      }
      goto check_len;
    }
    parse_vxlan_gpe(udp_hdr, &info);
    if (info.is_tunnel)
    {
      if (!tunnel_type)
      {
        do
        {
        } while (0);
        return -1;
      }
      if (tunnel_type != (0x6ULL << 45))
      {
        do
        {
        } while (0);
        return -1;
      }
      goto check_len;
    }
    parse_vxlan(udp_hdr, &info);
    if (info.is_tunnel)
    {
      if (!tunnel_type)
      {
        do
        {
        } while (0);
        return -1;
      }
      if (tunnel_type != (0x1ULL << 45))
      {
        do
        {
        } while (0);
        return -1;
      }
      goto check_len;
    }
    parse_geneve(udp_hdr, &info);
    if (info.is_tunnel)
    {
      if (!tunnel_type)
      {
        do
        {
        } while (0);
        return -1;
      }
      if (tunnel_type != (0x4ULL << 45))
      {
        do
        {
        } while (0);
        return -1;
      }
      goto check_len;
    }
    if (__builtin_expect(!!(((m->packet_type) & (0x0000f000 | 0x000f0000 | 0x00f00000 |
                                                 0x0f000000)) != 0),
                         0))
    {
      do
      {
      } while (0);
      return -1;
    }
  }
  else if (info.l4_proto == IPPROTO_GRE)
  {
    struct simple_gre_hdr *gre_hdr;
    gre_hdr = (struct simple_gre_hdr *)((char *)l3_hdr + info.l3_len);
    parse_gre(gre_hdr, &info);
    if (info.is_tunnel)
    {
      if (!tunnel_type)
      {
        do
        {
        } while (0);
        return -1;
      }
      if (tunnel_type != (0x2ULL << 45))
      {
        do
        {
        } while (0);
        return -1;
      }
      goto check_len;
    }
  }
  else if (info.l4_proto == IPPROTO_IPIP)
  {
    void *encap_ip_hdr;
    encap_ip_hdr = (char *)l3_hdr + info.l3_len;
    parse_encap_ip(encap_ip_hdr, &info);
    if (info.is_tunnel)
    {
      if (!tunnel_type)
      {
        do
        {
        } while (0);
        return -1;
      }
      if (tunnel_type != (0x3ULL << 45))
      {
        do
        {
        } while (0);
        return -1;
      }
      goto check_len;
    }
  }
check_len:
  if (check_mbuf_len(&info, m) != 0)
    return -1;
  return check_ether_type(&info, m);
}

uint16_t
iavf_prep_pkts(__attribute__((__unused__)) void *tx_queue, struct rte_mbuf **tx_pkts, uint16_t nb_pkts)
{
  int i, ret;
  uint64_t ol_flags;
  struct rte_mbuf *m;
  struct iavf_tx_queue *txq = tx_queue;
  struct rte_eth_dev *dev = &rte_eth_devices[txq->port_id];
  struct iavf_info *vf =
      (&((struct iavf_adapter *)dev->data->dev_private)->vf);
  struct iavf_adapter *adapter =
      ((struct iavf_adapter *)dev->data->dev_private);
  if (adapter->closed)
    return 0;
  for (i = 0; i < nb_pkts; i++)
  {
    m = tx_pkts[i];
    ol_flags = m->ol_flags;
    if (!(ol_flags & ((1ULL << 50) | (1ULL << 42))))
    {
      if (m->nb_segs > 8)
      {
        (per_lcore__rte_errno) = 22;
        return i;
      }
    }
    else if ((m->tso_segsz < 256) ||
             (m->tso_segsz > 9668) || (m->nb_segs > txq->nb_tx_desc))
    {
      (per_lcore__rte_errno) = 22;
      return i;
    }
    if (ol_flags &
        (((1ULL << 60) | (1ULL << 59) | (1ULL << 58) | (1ULL << 57) |
          (1ULL << 56) | (1ULL << 55) | (1ULL << 54) | (3ULL << 52) | (1ULL << 51) |
          (1ULL << 50) | (1ULL << 49) | (0xFULL << 45) | (1ULL << 44) |
          (1ULL << 43) | (1ULL << 42) | (1ULL << 41)) ^
         ((1ULL << 60) |
          (1ULL << 59) |
          (1ULL << 56) |
          (1ULL << 55) |
          (1ULL << 57) |
          (1ULL << 54) |
          (3ULL << 52) |
          (1ULL << 50) |
          (1ULL << 42) |
          (0xFULL << 45) |
          (1ULL << 58) |
          (1ULL << 41) |
          (1ULL << 43))))
    {
      (per_lcore__rte_errno) = 95;
      return i;
    }
    if (m->pkt_len < 17)
    {
      (per_lcore__rte_errno) = 22;
      return i;
    }
    ret = rte_net_intel_cksum_prepare(m);
    if (ret != 0)
    {
      (per_lcore__rte_errno) = -ret;
      return i;
    }
    if (vf->vf_res->vf_cap_flags & (1UL << (29)) &&
        ol_flags & ((1ULL << 6) | (1ULL << 0)))
    {
      ret = iavf_check_vlan_up2tc(txq, m);
      if (ret != 0)
      {
        (per_lcore__rte_errno) = -ret;
        return i;
      }
    }
  }
  return i;
}

static const eth_rx_burst_t iavf_rx_pkt_burst_ops[] = {
    [IAVF_RX_DEFAULT] = iavf_recv_pkts,
    [IAVF_RX_FLEX_RXD] = iavf_recv_pkts_flex_rxd,
    [IAVF_RX_BULK_ALLOC] = iavf_recv_pkts_bulk_alloc,
    [IAVF_RX_SCATTERED] = iavf_recv_scattered_pkts,
    [IAVF_RX_SCATTERED_FLEX_RXD] = iavf_recv_scattered_pkts_flex_rxd,
};

static const eth_tx_burst_t iavf_tx_pkt_burst_ops[] = {
    [IAVF_TX_DEFAULT] = iavf_xmit_pkts,
};

static uint16_t
iavf_recv_pkts_no_poll(void *rx_queue, struct rte_mbuf **rx_pkts,
                       uint16_t nb_pkts)
{
  struct iavf_rx_queue *rxq = rx_queue;
  enum iavf_rx_burst_type rx_burst_type;
  if (!rxq->vsi || rxq->vsi->adapter->no_poll)
    return 0;
  rx_burst_type = rxq->vsi->adapter->rx_burst_type;
  return iavf_rx_pkt_burst_ops[rx_burst_type](rx_queue, rx_pkts, nb_pkts);
}

static uint16_t
iavf_xmit_pkts_no_poll(void *tx_queue, struct rte_mbuf **tx_pkts,
                       uint16_t nb_pkts)
{
  struct iavf_tx_queue *txq = tx_queue;
  enum iavf_tx_burst_type tx_burst_type;
  if (!txq->vsi || txq->vsi->adapter->no_poll)
    return 0;
  tx_burst_type = txq->vsi->adapter->tx_burst_type;
  return iavf_tx_pkt_burst_ops[tx_burst_type](tx_queue, tx_pkts, nb_pkts);
}

static uint16_t
iavf_xmit_pkts_check(void *tx_queue, struct rte_mbuf **tx_pkts,
                     uint16_t nb_pkts)
{
  uint16_t idx;
  uint64_t ol_flags;
  struct rte_mbuf *mb;
  uint16_t good_pkts = nb_pkts;
  const char *reason = ((void *)0);
  _Bool pkt_error = 0;
  struct iavf_tx_queue *txq = tx_queue;
  struct iavf_adapter *adapter = txq->vsi->adapter;
  enum iavf_tx_burst_type tx_burst_type = txq->vsi->adapter->tx_burst_type;
  for (idx = 0; idx < nb_pkts; idx++)
  {
    mb = tx_pkts[idx];
    ol_flags = mb->ol_flags;
    if ((adapter->devargs.mbuf_check & (1ULL << 0)) &&
        (rte_mbuf_check(mb, 1, &reason) != 0))
    {
      do
      {
      } while (0);
      pkt_error = 1;
      break;
    }
    if ((adapter->devargs.mbuf_check & (1ULL << 1)) &&
        (mb->data_len < 17 || mb->data_len > adapter->vf.max_pkt_len))
    {
      do
      {
      } while (0);
      pkt_error = 1;
      break;
    }
    if (adapter->devargs.mbuf_check & (1ULL << 2))
    {
      if (!(ol_flags & ((1ULL << 50) | (1ULL << 42))))
      {
        if (mb->nb_segs > 8)
        {
          do
          {
          } while (0);
          pkt_error = 1;
          break;
        }
      }
      else if ((mb->tso_segsz < 256) || (mb->tso_segsz > 9668))
      {
        do
        {
        } while (0);
        pkt_error = 1;
        break;
      }
      else if (mb->nb_segs > txq->nb_tx_desc)
      {
        do
        {
        } while (0);
        pkt_error = 1;
        break;
      }
    }
    if (adapter->devargs.mbuf_check & (1ULL << 3))
    {
      if (ol_flags &
          (((1ULL << 60) | (1ULL << 59) | (1ULL << 58) | (1ULL << 57) |
            (1ULL << 56) | (1ULL << 55) | (1ULL << 54) | (3ULL << 52) |
            (1ULL << 51) | (1ULL << 50) | (1ULL << 49) | (0xFULL << 45) |
            (1ULL << 44) | (1ULL << 43) | (1ULL << 42) | (1ULL << 41)) ^
           ((1ULL << 60) | (1ULL << 59) | (1ULL << 56) | (1ULL << 55) |
            (1ULL << 57) | (1ULL << 54) | (3ULL << 52) | (1ULL << 50) |
            (1ULL << 42) | (0xFULL << 45) | (1ULL << 58) | (1ULL << 41) |
            (1ULL << 43))))
      {
        do
        {
        } while (0);
        pkt_error = 1;
        break;
      }
      if (!rte_validate_tx_offload(mb))
      {
        do
        {
        } while (0);
        pkt_error = 1;
        break;
      }
    }
  }
  if (pkt_error)
  {
    txq->mbuf_errors++;
    good_pkts = idx;
    if (good_pkts == 0)
      return 0;
  }
  return iavf_tx_pkt_burst_ops[tx_burst_type](tx_queue, tx_pkts, good_pkts);
}

void iavf_set_rx_function(struct rte_eth_dev *dev)
{
  struct iavf_adapter *adapter =
      ((struct iavf_adapter *)dev->data->dev_private);
  struct iavf_info *vf =
      (&((struct iavf_adapter *)dev->data->dev_private)->vf);
  enum iavf_rx_burst_type rx_burst_type;
  int no_poll_on_link_down = adapter->devargs.no_poll_on_link_down;
  int i;
  struct iavf_rx_queue *rxq;
  _Bool use_flex = 1;
  for (i = 0; i < dev->data->nb_rx_queues; i++)
  {
    rxq = dev->data->rx_queues[i];
    if (rxq->rxdid <= IAVF_RXDID_LEGACY_1)
    {
      rte_log(6U, iavf_logtype_driver,
              "%s(): "
              "request RXDID[%d] in Queue[%d] is legacy, "
              "set rx_pkt_burst as legacy for all queues"
              "\n",
              __func__,
              rxq->rxdid, i);
      use_flex = 0;
    }
    else if (!(vf->supported_rxdid & (1UL << (rxq->rxdid))))
    {
      rte_log(6U, iavf_logtype_driver,
              "%s(): "
              "request RXDID[%d] in Queue[%d] is not supported, "
              "set rx_pkt_burst as legacy for all queues"
              "\n",
              __func__,
              rxq->rxdid, i);
      use_flex = 0;
    }
  }
  if (dev->data->scattered_rx)
  {
    rte_log(8U, iavf_logtype_driver,
            "%s(): "
            "Using a Scattered Rx callback (port=%d)."
            "\n",
            __func__, dev->data->port_id);
    if (use_flex)
      rx_burst_type = IAVF_RX_SCATTERED_FLEX_RXD;
    else
      rx_burst_type = IAVF_RX_SCATTERED;
  }
  else if (adapter->rx_bulk_alloc_allowed)
  {
    rte_log(8U, iavf_logtype_driver,
            "%s(): "
            "Using bulk Rx callback (port=%d)."
            "\n",
            __func__,
            dev->data->port_id);
    rx_burst_type = IAVF_RX_BULK_ALLOC;
  }
  else
  {
    rte_log(8U, iavf_logtype_driver,
            "%s(): "
            "Using Basic Rx callback (port=%d)."
            "\n",
            __func__,
            dev->data->port_id);
    if (use_flex)
      rx_burst_type = IAVF_RX_FLEX_RXD;
    else
      rx_burst_type = IAVF_RX_DEFAULT;
  }
  if (no_poll_on_link_down)
  {
    adapter->rx_burst_type = rx_burst_type;
    dev->rx_pkt_burst = iavf_recv_pkts_no_poll;
  }
  else
  {
    dev->rx_pkt_burst = iavf_rx_pkt_burst_ops[rx_burst_type];
  }
}

void iavf_set_tx_function(struct rte_eth_dev *dev)
{
  struct iavf_adapter *adapter =
      ((struct iavf_adapter *)dev->data->dev_private);
  enum iavf_tx_burst_type tx_burst_type;
  int mbuf_check = adapter->devargs.mbuf_check;
  int no_poll_on_link_down = adapter->devargs.no_poll_on_link_down;
  rte_log(8U, iavf_logtype_driver,
          "%s(): "
          "Using Basic Tx callback (port=%d)."
          "\n",
          __func__,
          dev->data->port_id);
  tx_burst_type = IAVF_TX_DEFAULT;
  dev->tx_pkt_prepare = iavf_prep_pkts;
  if (no_poll_on_link_down)
  {
    adapter->tx_burst_type = tx_burst_type;
    dev->tx_pkt_burst = iavf_xmit_pkts_no_poll;
  }
  else if (mbuf_check)
  {
    adapter->tx_burst_type = tx_burst_type;
    dev->tx_pkt_burst = iavf_xmit_pkts_check;
  }
  else
  {
    dev->tx_pkt_burst = iavf_tx_pkt_burst_ops[tx_burst_type];
  }
}

static int
iavf_tx_done_cleanup_full(struct iavf_tx_queue *txq, uint32_t free_cnt)
{
  struct iavf_tx_entry *swr_ring = txq->sw_ring;
  uint16_t tx_last, tx_id;
  uint16_t nb_tx_free_last;
  uint16_t nb_tx_to_clean;
  uint32_t pkt_cnt = 0;
  tx_id = txq->tx_tail;
  tx_last = tx_id;
  if (txq->nb_free == 0 && iavf_xmit_cleanup(txq))
    return 0;
  nb_tx_to_clean = txq->nb_free;
  nb_tx_free_last = txq->nb_free;
  if (!free_cnt)
    free_cnt = txq->nb_tx_desc;
  while (pkt_cnt < free_cnt)
  {
    do
    {
      if (swr_ring[tx_id].mbuf != ((void *)0))
      {
        rte_pktmbuf_free_seg(swr_ring[tx_id].mbuf);
        swr_ring[tx_id].mbuf = ((void *)0);
        pkt_cnt += (swr_ring[tx_id].last_id == tx_id);
      }
      tx_id = swr_ring[tx_id].next_id;
    } while (--nb_tx_to_clean && pkt_cnt < free_cnt && tx_id != tx_last);
    if (txq->rs_thresh > txq->nb_tx_desc - txq->nb_free || tx_id == tx_last)
      break;
    if (pkt_cnt < free_cnt)
    {
      if (iavf_xmit_cleanup(txq))
        break;
      nb_tx_to_clean = txq->nb_free - nb_tx_free_last;
      nb_tx_free_last = txq->nb_free;
    }
  }
  return (int)pkt_cnt;
}

int iavf_dev_tx_done_cleanup(void *txq, uint32_t free_cnt)
{
  struct iavf_tx_queue *q = (struct iavf_tx_queue *)txq;
  return iavf_tx_done_cleanup_full(q, free_cnt);
}

void iavf_dev_rxq_info_get(struct rte_eth_dev *dev, uint16_t queue_id,
                           struct rte_eth_rxq_info *qinfo)
{
  struct iavf_rx_queue *rxq;
  rxq = dev->data->rx_queues[queue_id];
  qinfo->mp = rxq->mp;
  qinfo->scattered_rx = dev->data->scattered_rx;
  qinfo->nb_desc = rxq->nb_rx_desc;
  qinfo->conf.rx_free_thresh = rxq->rx_free_thresh;
  qinfo->conf.rx_drop_en = 1;
  qinfo->conf.rx_deferred_start = rxq->rx_deferred_start;
}

void iavf_dev_txq_info_get(struct rte_eth_dev *dev, uint16_t queue_id,
                           struct rte_eth_txq_info *qinfo)
{
  struct iavf_tx_queue *txq;
  txq = dev->data->tx_queues[queue_id];
  qinfo->nb_desc = txq->nb_tx_desc;
  qinfo->conf.tx_free_thresh = txq->free_thresh;
  qinfo->conf.tx_rs_thresh = txq->rs_thresh;
  qinfo->conf.offloads = txq->offloads;
  qinfo->conf.tx_deferred_start = txq->tx_deferred_start;
}

uint32_t
iavf_dev_rxq_count(void *rx_queue)
{
  volatile union iavf_32byte_rx_desc *rxdp;
  struct iavf_rx_queue *rxq;
  uint16_t desc = 0;
  rxq = rx_queue;
  rxdp = &rxq->rx_ring[rxq->rx_tail];
  while ((desc < rxq->nb_rx_desc) &&
         (((rxdp->wb.qword1.status_error_len) &
           (((1UL << (IAVF_RX_DESC_STATUS_LAST)) - 1) << 0)) >>
          0) &
             (1 << IAVF_RX_DESC_STATUS_DD_SHIFT))
  {
    desc += 4;
    rxdp += 4;
    if (rxq->rx_tail + desc >= rxq->nb_rx_desc)
      rxdp = &(rxq->rx_ring[rxq->rx_tail + desc - rxq->nb_rx_desc]);
  }
  return desc;
}

int iavf_dev_rx_desc_status(void *rx_queue, uint16_t offset)
{
  struct iavf_rx_queue *rxq = rx_queue;
  volatile uint64_t *status;
  uint64_t mask;
  uint32_t desc;
  if (__builtin_expect(!!(offset >= rxq->nb_rx_desc), 0))
    return -22;
  if (offset >= rxq->nb_rx_desc - rxq->nb_rx_hold)
    return 2;
  desc = rxq->rx_tail + offset;
  if (desc >= rxq->nb_rx_desc)
    desc -= rxq->nb_rx_desc;
  status = &rxq->rx_ring[desc].wb.qword1.status_error_len;
  mask = ((1ULL << IAVF_RX_DESC_STATUS_DD_SHIFT) << 0);
  if (*status & mask)
    return 1;
  return 0;
}

int iavf_dev_tx_desc_status(void *tx_queue, uint16_t offset)
{
  struct iavf_tx_queue *txq = tx_queue;
  volatile uint64_t *status;
  uint64_t mask, expect;
  uint32_t desc;
  if (__builtin_expect(!!(offset >= txq->nb_tx_desc), 0))
    return -22;
  desc = txq->tx_tail + offset;
  desc = ((desc + txq->rs_thresh - 1) / txq->rs_thresh) * txq->rs_thresh;
  if (desc >= txq->nb_tx_desc)
  {
    desc -= txq->nb_tx_desc;
    if (desc >= txq->nb_tx_desc)
      desc -= txq->nb_tx_desc;
  }
  status = &txq->tx_ring[desc].cmd_type_offset_bsz;
  mask = ((0xFUL << 0));
  expect = (IAVF_TX_DESC_DTYPE_DESC_DONE << 0);
  if ((*status & mask) == expect)
    return 1;
  return 0;
}

static inline uint32_t
iavf_get_default_ptype(uint16_t ptype)
{
  static const _Alignas(64) uint32_t ptype_tbl[1024] = {
      [1] = 0x00000001,
      [2] = 0x00000002,
      [6] = 0x00000004,
      [11] = 0x00000003,
      [22] = 0x00000001 | 0x00000090 | 0x00000300,
      [23] = 0x00000001 | 0x00000090 | 0x00000600,
      [24] = 0x00000001 | 0x00000090 | 0x00000200,
      [26] = 0x00000001 | 0x00000090 | 0x00000100,
      [27] = 0x00000001 | 0x00000090 | 0x00000400,
      [28] = 0x00000001 | 0x00000090 | 0x00000500,
      [29] = 0x00000001 | 0x00000090 | 0x00001000 | 0x00400000 | 0x03000000,
      [30] = 0x00000001 | 0x00000090 | 0x00001000 | 0x00400000 | 0x06000000,
      [31] = 0x00000001 | 0x00000090 | 0x00001000 | 0x00400000 | 0x02000000,
      [33] = 0x00000001 | 0x00000090 | 0x00001000 | 0x00400000 | 0x01000000,
      [34] = 0x00000001 | 0x00000090 | 0x00001000 | 0x00400000 | 0x04000000,
      [35] = 0x00000001 | 0x00000090 | 0x00001000 | 0x00400000 | 0x05000000,
      [36] = 0x00000001 | 0x00000090 | 0x00001000 | 0x00600000 | 0x03000000,
      [37] = 0x00000001 | 0x00000090 | 0x00001000 | 0x00600000 | 0x06000000,
      [38] = 0x00000001 | 0x00000090 | 0x00001000 | 0x00600000 | 0x02000000,
      [40] = 0x00000001 | 0x00000090 | 0x00001000 | 0x00600000 | 0x01000000,
      [41] = 0x00000001 | 0x00000090 | 0x00001000 | 0x00600000 | 0x04000000,
      [42] = 0x00000001 | 0x00000090 | 0x00001000 | 0x00600000 | 0x05000000,
      [43] = 0x00000001 | 0x00000090 | 0x00006000,
      [44] = 0x00000001 | 0x00000090 | 0x00006000 | 0x00400000 | 0x03000000,
      [45] = 0x00000001 | 0x00000090 | 0x00006000 | 0x00400000 | 0x06000000,
      [46] = 0x00000001 | 0x00000090 | 0x00006000 | 0x00400000 | 0x02000000,
      [48] = 0x00000001 | 0x00000090 | 0x00006000 | 0x00400000 | 0x01000000,
      [49] = 0x00000001 | 0x00000090 | 0x00006000 | 0x00400000 | 0x04000000,
      [50] = 0x00000001 | 0x00000090 | 0x00006000 | 0x00400000 | 0x05000000,
      [51] = 0x00000001 | 0x00000090 | 0x00006000 | 0x00600000 | 0x03000000,
      [52] = 0x00000001 | 0x00000090 | 0x00006000 | 0x00600000 | 0x06000000,
      [53] = 0x00000001 | 0x00000090 | 0x00006000 | 0x00600000 | 0x02000000,
      [55] = 0x00000001 | 0x00000090 | 0x00006000 | 0x00600000 | 0x01000000,
      [56] = 0x00000001 | 0x00000090 | 0x00006000 | 0x00600000 | 0x04000000,
      [57] = 0x00000001 | 0x00000090 | 0x00006000 | 0x00600000 | 0x05000000,
      [58] = 0x00000001 | 0x00000090 | 0x00006000 | 0x00010000,
      [59] = 0x00000001 | 0x00000090 |
             0x00006000 | 0x00010000 | 0x00400000 | 0x03000000,
      [60] = 0x00000001 | 0x00000090 |
             0x00006000 | 0x00010000 | 0x00400000 | 0x06000000,
      [61] = 0x00000001 | 0x00000090 |
             0x00006000 | 0x00010000 | 0x00400000 | 0x02000000,
      [63] = 0x00000001 | 0x00000090 |
             0x00006000 | 0x00010000 | 0x00400000 | 0x01000000,
      [64] = 0x00000001 | 0x00000090 |
             0x00006000 | 0x00010000 | 0x00400000 | 0x04000000,
      [65] = 0x00000001 | 0x00000090 |
             0x00006000 | 0x00010000 | 0x00400000 | 0x05000000,
      [66] = 0x00000001 | 0x00000090 |
             0x00006000 | 0x00010000 | 0x00600000 | 0x03000000,
      [67] = 0x00000001 | 0x00000090 |
             0x00006000 | 0x00010000 | 0x00600000 | 0x06000000,
      [68] = 0x00000001 | 0x00000090 |
             0x00006000 | 0x00010000 | 0x00600000 | 0x02000000,
      [70] = 0x00000001 | 0x00000090 |
             0x00006000 | 0x00010000 | 0x00600000 | 0x01000000,
      [71] = 0x00000001 | 0x00000090 |
             0x00006000 | 0x00010000 | 0x00600000 | 0x04000000,
      [72] = 0x00000001 | 0x00000090 |
             0x00006000 | 0x00010000 | 0x00600000 | 0x05000000,
      [88] = 0x00000001 | 0x000000e0 | 0x00000300,
      [89] = 0x00000001 | 0x000000e0 | 0x00000600,
      [90] = 0x00000001 | 0x000000e0 | 0x00000200,
      [92] = 0x00000001 | 0x000000e0 | 0x00000100,
      [93] = 0x00000001 | 0x000000e0 | 0x00000400,
      [94] = 0x00000001 | 0x000000e0 | 0x00000500,
      [95] = 0x00000001 | 0x000000e0 | 0x00001000 | 0x00400000 | 0x03000000,
      [96] = 0x00000001 | 0x000000e0 | 0x00001000 | 0x00400000 | 0x06000000,
      [97] = 0x00000001 | 0x000000e0 | 0x00001000 | 0x00400000 | 0x02000000,
      [99] = 0x00000001 | 0x000000e0 | 0x00001000 | 0x00400000 | 0x01000000,
      [100] = 0x00000001 | 0x000000e0 | 0x00001000 | 0x00400000 | 0x04000000,
      [101] = 0x00000001 | 0x000000e0 | 0x00001000 | 0x00400000 | 0x05000000,
      [102] = 0x00000001 | 0x000000e0 | 0x00001000 | 0x00600000 | 0x03000000,
      [103] = 0x00000001 | 0x000000e0 | 0x00001000 | 0x00600000 | 0x06000000,
      [104] = 0x00000001 | 0x000000e0 | 0x00001000 | 0x00600000 | 0x02000000,
      [106] = 0x00000001 | 0x000000e0 | 0x00001000 | 0x00600000 | 0x01000000,
      [107] = 0x00000001 | 0x000000e0 | 0x00001000 | 0x00600000 | 0x04000000,
      [108] = 0x00000001 | 0x000000e0 | 0x00001000 | 0x00600000 | 0x05000000,
      [109] = 0x00000001 | 0x000000e0 | 0x00006000,
      [110] = 0x00000001 | 0x000000e0 | 0x00006000 | 0x00400000 | 0x03000000,
      [111] = 0x00000001 | 0x000000e0 | 0x00006000 | 0x00400000 | 0x06000000,
      [112] = 0x00000001 | 0x000000e0 | 0x00006000 | 0x00400000 | 0x02000000,
      [114] = 0x00000001 | 0x000000e0 | 0x00006000 | 0x00400000 | 0x01000000,
      [115] = 0x00000001 | 0x000000e0 | 0x00006000 | 0x00400000 | 0x04000000,
      [116] = 0x00000001 | 0x000000e0 | 0x00006000 | 0x00400000 | 0x05000000,
      [117] = 0x00000001 | 0x000000e0 | 0x00006000 | 0x00600000 | 0x03000000,
      [118] = 0x00000001 | 0x000000e0 | 0x00006000 | 0x00600000 | 0x06000000,
      [119] = 0x00000001 | 0x000000e0 | 0x00006000 | 0x00600000 | 0x02000000,
      [121] = 0x00000001 | 0x000000e0 | 0x00006000 | 0x00600000 | 0x01000000,
      [122] = 0x00000001 | 0x000000e0 | 0x00006000 | 0x00600000 | 0x04000000,
      [123] = 0x00000001 | 0x000000e0 | 0x00006000 | 0x00600000 | 0x05000000,
      [124] = 0x00000001 | 0x000000e0 | 0x00006000 | 0x00010000,
      [125] = 0x00000001 | 0x000000e0 |
              0x00006000 | 0x00010000 | 0x00400000 | 0x03000000,
      [126] = 0x00000001 | 0x000000e0 |
              0x00006000 | 0x00010000 | 0x00400000 | 0x06000000,
      [127] = 0x00000001 | 0x000000e0 |
              0x00006000 | 0x00010000 | 0x00400000 | 0x02000000,
      [129] = 0x00000001 | 0x000000e0 |
              0x00006000 | 0x00010000 | 0x00400000 | 0x01000000,
      [130] = 0x00000001 | 0x000000e0 |
              0x00006000 | 0x00010000 | 0x00400000 | 0x04000000,
      [131] = 0x00000001 | 0x000000e0 |
              0x00006000 | 0x00010000 | 0x00400000 | 0x05000000,
      [132] = 0x00000001 | 0x000000e0 |
              0x00006000 | 0x00010000 | 0x00600000 | 0x03000000,
      [133] = 0x00000001 | 0x000000e0 |
              0x00006000 | 0x00010000 | 0x00600000 | 0x06000000,
      [134] = 0x00000001 | 0x000000e0 |
              0x00006000 | 0x00010000 | 0x00600000 | 0x02000000,
      [136] = 0x00000001 | 0x000000e0 |
              0x00006000 | 0x00010000 | 0x00600000 | 0x01000000,
      [137] = 0x00000001 | 0x000000e0 |
              0x00006000 | 0x00010000 | 0x00600000 | 0x04000000,
      [138] = 0x00000001 | 0x000000e0 |
              0x00006000 | 0x00010000 | 0x00600000 | 0x05000000,
      [300] = 0x00000008,
      [301] = 0x00000008,
      [302] = 0x00000008 | 0x00000090 | 0x00000300,
      [303] = 0x00000008 | 0x00000090 | 0x00000600,
      [304] = 0x00000008 | 0x00000090 | 0x00000200,
      [305] = 0x00000008 | 0x00000090 | 0x00000100,
      [306] = 0x00000008 | 0x00000090 | 0x00000400,
      [307] = 0x00000008 | 0x00000090 | 0x00000500,
      [308] = 0x00000008 | 0x000000e0 | 0x00000300,
      [309] = 0x00000008 | 0x000000e0 | 0x00000600,
      [310] = 0x00000008 | 0x000000e0 | 0x00000200,
      [311] = 0x00000008 | 0x000000e0 | 0x00000100,
      [312] = 0x00000008 | 0x000000e0 | 0x00000400,
      [313] = 0x00000008 | 0x000000e0 | 0x00000500,
      [325] = 0x00000001 | 0x00000090 | 0x00007000,
      [326] = 0x00000001 | 0x000000e0 | 0x00007000,
      [327] = 0x00000001 | 0x00000090 | 0x00007000,
      [328] = 0x00000001 | 0x000000e0 | 0x00007000,
      [329] = 0x00000001 | 0x00000090 | 0x00008000,
      [330] = 0x00000001 | 0x000000e0 | 0x00008000,
      [331] = 0x00000001 | 0x00000090 | 0x00008000 | 0x00400000 | 0x03000000,
      [332] = 0x00000001 | 0x00000090 | 0x00008000 | 0x00400000 | 0x06000000,
      [333] = 0x00000001 | 0x00000090 | 0x00008000 | 0x00400000 | 0x02000000,
      [334] = 0x00000001 | 0x00000090 | 0x00008000 | 0x00400000 | 0x01000000,
      [335] = 0x00000001 | 0x00000090 | 0x00008000 | 0x00400000 | 0x05000000,
      [336] = 0x00000001 | 0x000000e0 | 0x00008000 | 0x00400000 | 0x03000000,
      [337] = 0x00000001 | 0x000000e0 | 0x00008000 | 0x00400000 | 0x06000000,
      [338] = 0x00000001 | 0x000000e0 | 0x00008000 | 0x00400000 | 0x02000000,
      [339] = 0x00000001 | 0x000000e0 | 0x00008000 | 0x00400000 | 0x01000000,
      [340] = 0x00000001 | 0x000000e0 | 0x00008000 | 0x00400000 | 0x05000000,
      [341] = 0x00000001 | 0x00000090 | 0x00008000 | 0x00600000 | 0x03000000,
      [342] = 0x00000001 | 0x00000090 | 0x00008000 | 0x00600000 | 0x06000000,
      [343] = 0x00000001 | 0x00000090 | 0x00008000 | 0x00600000 | 0x02000000,
      [344] = 0x00000001 | 0x00000090 | 0x00008000 | 0x00600000 | 0x01000000,
      [345] = 0x00000001 | 0x00000090 | 0x00008000 | 0x00600000 | 0x05000000,
      [346] = 0x00000001 | 0x000000e0 | 0x00008000 | 0x00600000 | 0x03000000,
      [347] = 0x00000001 | 0x000000e0 | 0x00008000 | 0x00600000 | 0x06000000,
      [348] = 0x00000001 | 0x000000e0 | 0x00008000 | 0x00600000 | 0x02000000,
      [349] = 0x00000001 | 0x000000e0 | 0x00008000 | 0x00600000 | 0x01000000,
      [350] = 0x00000001 | 0x000000e0 | 0x00008000 | 0x00600000 | 0x05000000,
      [372] = 0x00000001 | 0x00000090 | 0x00000200,
      [373] = 0x00000001 | 0x00000090 | 0x00000200,
      [374] = 0x00000001 | 0x00000090 | 0x00000200,
      [375] = 0x00000001 | 0x00000090 | 0x00000200,
      [376] = 0x00000001 | 0x00000090 | 0x00000200,
      [377] = 0x00000001 | 0x00000090 | 0x00000200,
      [378] = 0x00000001 | 0x00000090 | 0x00000200,
      [379] = 0x00000001 | 0x00000090 | 0x00000200,
      [380] = 0x00000001 | 0x00000090 | 0x00000200,
      [381] = 0x00000001 | 0x00000090 | 0x00000200,
      [382] = 0x00000001 | 0x000000e0 | 0x00000200,
      [383] = 0x00000001 | 0x000000e0 | 0x00000200,
      [384] = 0x00000001 | 0x000000e0 | 0x00000200,
      [385] = 0x00000001 | 0x000000e0 | 0x00000200,
      [386] = 0x00000001 | 0x000000e0 | 0x00000200,
      [387] = 0x00000001 | 0x000000e0 | 0x00000200,
      [388] = 0x00000001 | 0x000000e0 | 0x00000200,
      [389] = 0x00000001 | 0x000000e0 | 0x00000200,
      [390] = 0x00000001 | 0x000000e0 | 0x00000200,
      [391] = 0x00000001 | 0x000000e0 | 0x00000200,
  };
  return ptype_tbl[ptype];
}

void __attribute__((cold))
iavf_set_default_ptype_table(struct rte_eth_dev *dev)
{
  struct iavf_adapter *ad = ((struct iavf_adapter *)dev->data->dev_private);
  int i;
  for (i = 0; i < 1024; i++)
    ad->ptype_tbl[i] = iavf_get_default_ptype(i);
}
