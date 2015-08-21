/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 29 "parser_gram.y"


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <locale.h>
#include <sys/utsname.h>
#include <sys/statvfs.h>
#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
#ifdef HAVE_LIBTECLA
#include <libtecla.h>
#endif
#include "parsertypes.h"
#include "filebench.h"
#include "utils.h"
#include "stats.h"
#include "vars.h"
#include "eventgen.h"
#ifdef HAVE_LIBTECLA
#include "auto_comp.h"
#endif
#include "multi_client_sync.h"

/* yacc and lex externals */
extern FILE *yyin;
extern int yydebug;
extern void yyerror(char *s);
extern int yylex(void);

/* GetLine resource object */
#ifdef HAVE_LIBTECLA
static GetLine *gl;
#endif

/* executable name to execute worker processes later */
char *execname;

static int dofile = DOFILE_FALSE;
static FILE *parentscript;

static char *fbbasepath = FILEBENCHDIR;
static char cwd[MAXPATHLEN];
static pidlist_t *pidlist;
static int filecreate_done;

/* utilities */
static cmd_t *alloc_cmd(void);
static attr_t *alloc_attr(void);
static attr_t *alloc_lvar_attr(var_t *var);
static attr_t *get_attr(cmd_t *cmd, int64_t name);
static attr_t *get_attr_fileset(cmd_t *cmd, int64_t name);
static attr_t *get_attr_integer(cmd_t *cmd, int64_t name);
static attr_t *get_attr_bool(cmd_t *cmd, int64_t name);
static void get_attr_lvars(cmd_t *cmd, flowop_t *flowop);
static list_t *alloc_list();
static probtabent_t *alloc_probtabent(void);
static void add_lvar_to_list(var_t *newlvar, var_t **lvar_list);

/* Info Commands */
static void parser_list(cmd_t *);
static void parser_flowop_list(cmd_t *);

/* Define Commands */
static void parser_proc_define(cmd_t *);
static void parser_thread_define(cmd_t *, procflow_t *, int instances);
static void parser_flowop_define(cmd_t *, threadflow_t *, flowop_t **, int);
static void parser_file_define(cmd_t *);
static void parser_fileset_define(cmd_t *);
static void parser_posset_define(cmd_t *);
static void parser_randvar_define(cmd_t *);
static void parser_randvar_set(cmd_t *);
static void parser_composite_flowop_define(cmd_t *);

/* Create Commands */
static void parser_proc_create(cmd_t *);
static void parser_fileset_create(cmd_t *);

/* set commands */
static void parser_set_integer(cmd_t *cmd);
static void parser_set_var(cmd_t *cmd);
static void parser_set_var_op_int(cmd_t *cmd);
static void parser_set_int_op_var(cmd_t *cmd);
static void parser_set_var_op_var(cmd_t *cmd);

/* Shutdown Commands */
static void parser_proc_shutdown(cmd_t *);
static void parser_filebench_shutdown(cmd_t *cmd);
static void parser_fileset_shutdown(cmd_t *cmd);

/* Other Commands */
static void parser_echo(cmd_t *cmd);
static void parser_foreach_integer(cmd_t *cmd);
static void parser_foreach_string(cmd_t *cmd);
static void parser_fscheck(cmd_t *cmd);
static void parser_fsflush(cmd_t *cmd);
static void parser_log(cmd_t *cmd);
static void parser_statscmd(cmd_t *cmd);
static void parser_statsdump(cmd_t *cmd);
static void parser_statsxmldump(cmd_t *cmd);
static void parser_statsmultidump(cmd_t *cmd);
static void parser_usage(cmd_t *cmd);
static void parser_vars(cmd_t *cmd);
static void parser_printvars(cmd_t *cmd);
static void parser_system(cmd_t *cmd);
static void parser_statssnap(cmd_t *cmd);
static void parser_directory(cmd_t *cmd);
static void parser_eventgen(cmd_t *cmd);
static void parser_enable_mc(cmd_t *cmd);
static void parser_domultisync(cmd_t *cmd);
static void parser_run(cmd_t *cmd);
static void parser_run_variable(cmd_t *cmd);
static void parser_sleep(cmd_t *cmd);
static void parser_sleep_variable(cmd_t *cmd);
static void parser_warmup(cmd_t *cmd);
static void parser_warmup_variable(cmd_t *cmd);
static void parser_help(cmd_t *cmd);
static void arg_parse(const char *command);
static void parser_abort(int arg);
static void parser_version(cmd_t *cmd);
static void parser_osprof_enable(cmd_t *cmd);
static void parser_osprof_disable(cmd_t *cmd);



/* Line 268 of yacc.c  */
#line 204 "parser_gram.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     FSC_LIST = 258,
     FSC_DEFINE = 259,
     FSC_EXEC = 260,
     FSC_QUIT = 261,
     FSC_DEBUG = 262,
     FSC_CREATE = 263,
     FSC_SLEEP = 264,
     FSC_STATS = 265,
     FSC_FOREACH = 266,
     FSC_SET = 267,
     FSC_SHUTDOWN = 268,
     FSC_LOG = 269,
     FSC_SYSTEM = 270,
     FSC_FLOWOP = 271,
     FSC_EVENTGEN = 272,
     FSC_ECHO = 273,
     FSC_LOAD = 274,
     FSC_RUN = 275,
     FSC_WARMUP = 276,
     FSC_NOUSESTATS = 277,
     FSC_FSCHECK = 278,
     FSC_FSFLUSH = 279,
     FSC_USAGE = 280,
     FSC_HELP = 281,
     FSC_VARS = 282,
     FSC_VERSION = 283,
     FSC_ENABLE = 284,
     FSC_DOMULTISYNC = 285,
     FSV_STRING = 286,
     FSV_VAL_INT = 287,
     FSV_VAL_BOOLEAN = 288,
     FSV_VARIABLE = 289,
     FSV_WHITESTRING = 290,
     FSV_RANDUNI = 291,
     FSV_RANDTAB = 292,
     FSV_RANDVAR = 293,
     FSV_URAND = 294,
     FSV_RAND48 = 295,
     FST_INT = 296,
     FST_BOOLEAN = 297,
     FSE_FILE = 298,
     FSE_PROC = 299,
     FSE_THREAD = 300,
     FSE_CLEAR = 301,
     FSE_ALL = 302,
     FSE_SNAP = 303,
     FSE_DUMP = 304,
     FSE_DIRECTORY = 305,
     FSE_COMMAND = 306,
     FSE_FILESET = 307,
     FSE_POSSET = 308,
     FSE_XMLDUMP = 309,
     FSE_RAND = 310,
     FSE_MODE = 311,
     FSE_MULTI = 312,
     FSE_MULTIDUMP = 313,
     FSK_SEPLST = 314,
     FSK_OPENLST = 315,
     FSK_CLOSELST = 316,
     FSK_ASSIGN = 317,
     FSK_IN = 318,
     FSK_QUOTE = 319,
     FSK_DIRSEPLST = 320,
     FSK_PLUS = 321,
     FSK_MINUS = 322,
     FSK_MULTIPLY = 323,
     FSK_DIVIDE = 324,
     FSA_SIZE = 325,
     FSA_PREALLOC = 326,
     FSA_PARALLOC = 327,
     FSA_PATH = 328,
     FSA_REUSE = 329,
     FSA_DUP = 330,
     FSA_COMP = 331,
     FSA_RANDOMSEED = 332,
     FSA_PAGESIZE = 333,
     FSA_PROCESS = 334,
     FSA_MEMSIZE = 335,
     FSA_RATE = 336,
     FSA_CACHED = 337,
     FSA_READONLY = 338,
     FSA_TRUSTTREE = 339,
     FSA_IOSIZE = 340,
     FSA_FILE = 341,
     FSA_POSSET = 342,
     FSA_WSS = 343,
     FSA_NAME = 344,
     FSA_RANDOM = 345,
     FSA_INSTANCES = 346,
     FSA_DSYNC = 347,
     FSA_TARGET = 348,
     FSA_ITERS = 349,
     FSA_NICE = 350,
     FSA_VALUE = 351,
     FSA_BLOCKING = 352,
     FSA_HIGHWATER = 353,
     FSA_DIRECTIO = 354,
     FSA_DIRWIDTH = 355,
     FSA_FD = 356,
     FSA_SRCFD = 357,
     FSA_ROTATEFD = 358,
     FSA_NAMELENGTH = 359,
     FSA_FILESIZE = 360,
     FSA_ENTRIES = 361,
     FSA_FILESIZEGAMMA = 362,
     FSA_DIRDEPTHRV = 363,
     FSA_DIRGAMMA = 364,
     FSA_USEISM = 365,
     FSA_TYPE = 366,
     FSA_RANDTABLE = 367,
     FSA_RANDSRC = 368,
     FSA_RANDROUND = 369,
     FSA_LEAFDIRS = 370,
     FSA_INDEXED = 371,
     FSA_FSTYPE = 372,
     FSA_RANDSEED = 373,
     FSA_RANDGAMMA = 374,
     FSA_RANDMEAN = 375,
     FSA_RANDMIN = 376,
     FSA_RANDMAX = 377,
     FSA_MASTER = 378,
     FSA_CLIENT = 379,
     FSS_TYPE = 380,
     FSS_SEED = 381,
     FSS_GAMMA = 382,
     FSS_MEAN = 383,
     FSS_MIN = 384,
     FSS_SRC = 385,
     FSS_ROUND = 386,
     FSV_SET_LOCAL_VAR = 387,
     FSA_LVAR_ASSIGN = 388,
     FSA_ALLDONE = 389,
     FSA_FIRSTDONE = 390,
     FSA_TIMEOUT = 391,
     FSC_OSPROF_ENABLE = 392,
     FSC_OSPROF_DISABLE = 393,
     FSA_NOREADAHEAD = 394,
     FSA_IOPRIO = 395,
     FSA_WRITEONLY = 396
   };
#endif
/* Tokens.  */
#define FSC_LIST 258
#define FSC_DEFINE 259
#define FSC_EXEC 260
#define FSC_QUIT 261
#define FSC_DEBUG 262
#define FSC_CREATE 263
#define FSC_SLEEP 264
#define FSC_STATS 265
#define FSC_FOREACH 266
#define FSC_SET 267
#define FSC_SHUTDOWN 268
#define FSC_LOG 269
#define FSC_SYSTEM 270
#define FSC_FLOWOP 271
#define FSC_EVENTGEN 272
#define FSC_ECHO 273
#define FSC_LOAD 274
#define FSC_RUN 275
#define FSC_WARMUP 276
#define FSC_NOUSESTATS 277
#define FSC_FSCHECK 278
#define FSC_FSFLUSH 279
#define FSC_USAGE 280
#define FSC_HELP 281
#define FSC_VARS 282
#define FSC_VERSION 283
#define FSC_ENABLE 284
#define FSC_DOMULTISYNC 285
#define FSV_STRING 286
#define FSV_VAL_INT 287
#define FSV_VAL_BOOLEAN 288
#define FSV_VARIABLE 289
#define FSV_WHITESTRING 290
#define FSV_RANDUNI 291
#define FSV_RANDTAB 292
#define FSV_RANDVAR 293
#define FSV_URAND 294
#define FSV_RAND48 295
#define FST_INT 296
#define FST_BOOLEAN 297
#define FSE_FILE 298
#define FSE_PROC 299
#define FSE_THREAD 300
#define FSE_CLEAR 301
#define FSE_ALL 302
#define FSE_SNAP 303
#define FSE_DUMP 304
#define FSE_DIRECTORY 305
#define FSE_COMMAND 306
#define FSE_FILESET 307
#define FSE_POSSET 308
#define FSE_XMLDUMP 309
#define FSE_RAND 310
#define FSE_MODE 311
#define FSE_MULTI 312
#define FSE_MULTIDUMP 313
#define FSK_SEPLST 314
#define FSK_OPENLST 315
#define FSK_CLOSELST 316
#define FSK_ASSIGN 317
#define FSK_IN 318
#define FSK_QUOTE 319
#define FSK_DIRSEPLST 320
#define FSK_PLUS 321
#define FSK_MINUS 322
#define FSK_MULTIPLY 323
#define FSK_DIVIDE 324
#define FSA_SIZE 325
#define FSA_PREALLOC 326
#define FSA_PARALLOC 327
#define FSA_PATH 328
#define FSA_REUSE 329
#define FSA_DUP 330
#define FSA_COMP 331
#define FSA_RANDOMSEED 332
#define FSA_PAGESIZE 333
#define FSA_PROCESS 334
#define FSA_MEMSIZE 335
#define FSA_RATE 336
#define FSA_CACHED 337
#define FSA_READONLY 338
#define FSA_TRUSTTREE 339
#define FSA_IOSIZE 340
#define FSA_FILE 341
#define FSA_POSSET 342
#define FSA_WSS 343
#define FSA_NAME 344
#define FSA_RANDOM 345
#define FSA_INSTANCES 346
#define FSA_DSYNC 347
#define FSA_TARGET 348
#define FSA_ITERS 349
#define FSA_NICE 350
#define FSA_VALUE 351
#define FSA_BLOCKING 352
#define FSA_HIGHWATER 353
#define FSA_DIRECTIO 354
#define FSA_DIRWIDTH 355
#define FSA_FD 356
#define FSA_SRCFD 357
#define FSA_ROTATEFD 358
#define FSA_NAMELENGTH 359
#define FSA_FILESIZE 360
#define FSA_ENTRIES 361
#define FSA_FILESIZEGAMMA 362
#define FSA_DIRDEPTHRV 363
#define FSA_DIRGAMMA 364
#define FSA_USEISM 365
#define FSA_TYPE 366
#define FSA_RANDTABLE 367
#define FSA_RANDSRC 368
#define FSA_RANDROUND 369
#define FSA_LEAFDIRS 370
#define FSA_INDEXED 371
#define FSA_FSTYPE 372
#define FSA_RANDSEED 373
#define FSA_RANDGAMMA 374
#define FSA_RANDMEAN 375
#define FSA_RANDMIN 376
#define FSA_RANDMAX 377
#define FSA_MASTER 378
#define FSA_CLIENT 379
#define FSS_TYPE 380
#define FSS_SEED 381
#define FSS_GAMMA 382
#define FSS_MEAN 383
#define FSS_MIN 384
#define FSS_SRC 385
#define FSS_ROUND 386
#define FSV_SET_LOCAL_VAR 387
#define FSA_LVAR_ASSIGN 388
#define FSA_ALLDONE 389
#define FSA_FIRSTDONE 390
#define FSA_TIMEOUT 391
#define FSC_OSPROF_ENABLE 392
#define FSC_OSPROF_DISABLE 393
#define FSA_NOREADAHEAD 394
#define FSA_IOPRIO 395
#define FSA_WRITEONLY 396




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 161 "parser_gram.y"

	int64_t		 ival;
	unsigned char	 bval;
	char *		 sval;
	fs_u		 val;
	avd_t		 avd;
	cmd_t		*cmd;
	attr_t		*attr;
	list_t		*list;
	probtabent_t	*rndtb;



/* Line 293 of yacc.c  */
#line 536 "parser_gram.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 548 "parser_gram.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   417

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  142
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  96
/* YYNRULES -- Number of rules.  */
#define YYNRULES  302
/* YYNRULES -- Number of states.  */
#define YYNSTATES  396

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   396

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    10,    12,    15,    17,    19,
      21,    23,    25,    27,    29,    31,    33,    35,    37,    39,
      41,    43,    45,    47,    49,    51,    53,    55,    57,    59,
      61,    63,    65,    67,    69,    71,    73,    75,    77,    79,
      87,    95,    97,   101,   105,   111,   113,   116,   119,   122,
     124,   126,   128,   131,   133,   136,   139,   142,   144,   146,
     148,   151,   154,   157,   160,   163,   166,   169,   172,   176,
     179,   182,   186,   189,   192,   194,   197,   200,   203,   206,
     209,   212,   214,   216,   221,   226,   230,   234,   239,   246,
     251,   256,   261,   266,   270,   276,   282,   288,   291,   294,
     298,   302,   306,   310,   314,   316,   318,   321,   327,   329,
     332,   339,   342,   345,   348,   351,   354,   357,   361,   368,
     371,   374,   377,   380,   383,   386,   389,   392,   395,   397,
     399,   402,   405,   408,   410,   412,   414,   416,   418,   420,
     424,   426,   430,   434,   436,   440,   442,   444,   448,   456,
     460,   462,   466,   470,   478,   480,   484,   486,   490,   494,
     496,   498,   502,   506,   510,   512,   514,   518,   522,   524,
     526,   530,   534,   538,   542,   544,   546,   548,   550,   552,
     554,   556,   558,   560,   562,   564,   566,   568,   570,   572,
     574,   576,   578,   580,   582,   584,   586,   588,   590,   592,
     594,   596,   598,   600,   602,   604,   606,   608,   610,   612,
     614,   616,   618,   620,   622,   624,   626,   628,   630,   632,
     634,   636,   638,   640,   642,   644,   646,   648,   650,   652,
     654,   656,   658,   660,   662,   664,   666,   668,   670,   672,
     674,   676,   678,   680,   682,   684,   686,   688,   690,   692,
     694,   696,   698,   700,   702,   704,   706,   708,   710,   712,
     714,   716,   718,   720,   722,   724,   726,   728,   730,   732,
     734,   736,   738,   740,   742,   744,   746,   748,   750,   752,
     754,   756,   760,   764,   768,   772,   776,   782,   786,   790,
     792,   794,   796,   798,   800,   802,   804,   806,   808,   810,
     812,   814,   816
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     143,     0,    -1,   143,   145,    -1,   143,     1,    -1,    -1,
     145,    -1,   144,   145,    -1,   176,    -1,   177,    -1,   178,
      -1,   179,    -1,   180,    -1,   167,    -1,   149,    -1,   181,
      -1,   151,    -1,   155,    -1,   156,    -1,   146,    -1,   164,
      -1,   165,    -1,   186,    -1,   163,    -1,   188,    -1,   166,
      -1,   185,    -1,   168,    -1,   182,    -1,   184,    -1,   183,
      -1,   171,    -1,   150,    -1,   152,    -1,   153,    -1,   154,
      -1,   157,    -1,   158,    -1,   172,    -1,    11,    -1,   146,
      34,    63,   147,    60,   144,    61,    -1,   146,    34,    63,
     148,    60,   144,    61,    -1,    32,    -1,   147,    59,    32,
      -1,    64,    35,    64,    -1,   148,    59,    64,    35,    64,
      -1,    17,    -1,   149,   203,    -1,    15,   162,    -1,    18,
     162,    -1,    28,    -1,   137,    -1,   138,    -1,    25,   162,
      -1,    27,    -1,    29,    57,    -1,   157,   205,    -1,    30,
     207,    -1,    34,    -1,    31,    -1,   159,    -1,   159,    31,
      -1,   159,    34,    -1,   160,    31,    -1,   160,    34,    -1,
      64,    34,    -1,    64,    35,    -1,   161,    35,    -1,   161,
      34,    -1,   161,    38,   220,    -1,   162,    35,    -1,   162,
      34,    -1,   162,    38,   220,    -1,   162,    64,    -1,   161,
      64,    -1,     3,    -1,   163,    16,    -1,    23,   208,    -1,
     164,   208,    -1,    24,   208,    -1,    14,   162,    -1,     7,
      32,    -1,   169,    -1,   170,    -1,    12,    34,    62,    32,
      -1,    12,    34,    62,    34,    -1,   169,   209,    32,    -1,
     169,   209,    34,    -1,    12,    34,    62,    33,    -1,    12,
      34,    62,    64,    35,    64,    -1,    12,    34,    62,    31,
      -1,    12,    56,     6,   136,    -1,    12,    56,     6,   134,
      -1,    12,    56,     6,   135,    -1,    12,    56,    22,    -1,
      12,    38,   125,    62,   222,    -1,    12,    38,   130,    62,
     224,    -1,    12,    38,   221,    62,   235,    -1,    10,    48,
      -1,    10,    46,    -1,    10,    50,   160,    -1,    10,    51,
     162,    -1,    10,    49,   162,    -1,    10,    54,   162,    -1,
      10,    58,   162,    -1,     6,    -1,   187,    -1,   173,   187,
      -1,    45,   199,    60,   173,    61,    -1,   174,    -1,   175,
     174,    -1,     4,    44,   199,    60,   175,    61,    -1,   176,
     199,    -1,     4,    43,    -1,     4,    52,    -1,   177,   191,
      -1,     4,    53,    -1,   178,   192,    -1,     4,    55,   195,
      -1,     4,    16,   231,    60,   173,    61,    -1,   180,   231,
      -1,     8,   189,    -1,    13,   189,    -1,    21,    32,    -1,
      21,    34,    -1,     9,    32,    -1,     9,    34,    -1,    20,
      32,    -1,    20,    34,    -1,    20,    -1,    26,    -1,    16,
     190,    -1,   187,   201,    -1,    19,    31,    -1,    44,    -1,
      45,    -1,    52,    -1,    43,    -1,    31,    -1,   194,    -1,
     191,    59,   194,    -1,   193,    -1,   192,    59,   193,    -1,
     211,    62,   236,    -1,   211,    -1,   210,    62,   236,    -1,
     210,    -1,   196,    -1,   195,    59,   196,    -1,   195,    59,
     112,    62,    60,   198,    61,    -1,   219,    62,   236,    -1,
     219,    -1,   111,    62,   222,    -1,   113,    62,   224,    -1,
      60,   237,    59,   237,    59,   237,    61,    -1,   197,    -1,
     198,    59,   197,    -1,   200,    -1,   199,    59,   200,    -1,
     212,    62,   235,    -1,   212,    -1,   202,    -1,   201,    59,
     202,    -1,   201,    59,   233,    -1,   213,    62,   235,    -1,
     213,    -1,   204,    -1,   203,    59,   204,    -1,   214,    62,
     235,    -1,   214,    -1,   206,    -1,   205,    59,   206,    -1,
     229,    62,   235,    -1,    96,    62,   235,    -1,   230,    62,
      31,    -1,    66,    -1,    67,    -1,    68,    -1,    69,    -1,
     216,    -1,   217,    -1,   218,    -1,   226,    -1,   215,    -1,
     227,    -1,   228,    -1,    95,    -1,    89,    -1,    91,    -1,
      70,    -1,    89,    -1,    73,    -1,    83,    -1,    84,    -1,
      74,    -1,    75,    -1,    76,    -1,    78,    -1,    77,    -1,
      71,    -1,    72,    -1,   141,    -1,    70,    -1,    89,    -1,
      73,    -1,   100,    -1,   108,    -1,    71,    -1,    72,    -1,
      74,    -1,    75,    -1,    78,    -1,    76,    -1,    77,    -1,
      83,    -1,    84,    -1,   107,    -1,   109,    -1,    82,    -1,
     106,    -1,   115,    -1,   141,    -1,    89,    -1,   111,    -1,
     118,    -1,   106,    -1,   122,    -1,    89,    -1,   118,    -1,
     119,    -1,   120,    -1,   121,    -1,   114,    -1,   125,    -1,
     130,    -1,   126,    -1,   127,    -1,   128,    -1,   129,    -1,
     131,    -1,   126,    -1,   127,    -1,   128,    -1,   129,    -1,
     131,    -1,   223,    -1,    36,    -1,    37,    -1,   119,    -1,
     225,    -1,    39,    -1,    40,    -1,    79,    -1,    89,    -1,
      80,    -1,   110,    -1,    91,    -1,   140,    -1,    88,    -1,
      86,    -1,    87,    -1,    89,    -1,    90,    -1,   101,    -1,
     102,    -1,   103,    -1,    92,    -1,    99,    -1,   116,    -1,
      93,    -1,    94,    -1,    96,    -1,    97,    -1,    98,    -1,
      85,    -1,   139,    -1,    81,    -1,   123,    -1,   124,    -1,
      73,    -1,   117,    -1,   232,    -1,   231,    59,   232,    -1,
     231,    59,   233,    -1,   234,    62,   235,    -1,    34,    62,
      33,    -1,    34,    62,    32,    -1,    34,    62,    64,    35,
      64,    -1,    34,    62,    31,    -1,    34,    62,    34,    -1,
      34,    -1,    89,    -1,    94,    -1,    31,    -1,    32,    -1,
      33,    -1,    34,    -1,   160,    -1,    31,    -1,    32,    -1,
      33,    -1,    34,    -1,    32,    -1,    34,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   256,   256,   263,   268,   270,   275,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   326,   332,
     355,   380,   387,   405,   412,   430,   436,   441,   450,   459,
     466,   473,   480,   489,   497,   504,   509,   542,   549,   557,
     560,   578,   595,   613,   632,   639,   647,   665,   682,   700,
     718,   735,   753,   756,   761,   767,   772,   780,   785,   794,
     802,   813,   814,   816,   826,   838,   862,   873,   884,   894,
     904,   910,   916,   922,   929,   938,   947,   958,   966,   973,
     981,   989,   996,  1003,  1012,  1019,  1022,  1040,  1052,  1055,
    1073,  1082,  1087,  1092,  1098,  1103,  1108,  1113,  1121,  1129,
    1134,  1153,  1172,  1179,  1187,  1194,  1202,  1209,  1216,  1224,
    1231,  1237,  1242,  1270,  1271,  1272,  1273,  1279,  1282,  1286,
    1300,  1304,  1318,  1323,  1330,  1335,  1343,  1347,  1360,  1379,
    1384,  1390,  1395,  1401,  1411,  1415,  1430,  1434,  1448,  1453,
    1461,  1465,  1478,  1492,  1497,  1505,  1509,  1523,  1528,  1536,
    1540,  1554,  1560,  1566,  1575,  1576,  1577,  1578,  1580,  1581,
    1583,  1585,  1586,  1588,  1590,  1593,  1594,  1595,  1598,  1599,
    1600,  1601,  1602,  1603,  1605,  1606,  1607,  1608,  1609,  1610,
    1611,  1614,  1615,  1616,  1617,  1618,  1619,  1620,  1621,  1622,
    1623,  1624,  1625,  1626,  1627,  1628,  1629,  1630,  1631,  1632,
    1633,  1636,  1637,  1638,  1639,  1640,  1643,  1644,  1645,  1646,
    1647,  1648,  1651,  1652,  1653,  1654,  1655,  1656,  1657,  1660,
    1661,  1662,  1663,  1664,  1666,  1674,  1675,  1676,  1678,  1686,
    1687,  1690,  1691,  1692,  1693,  1694,  1695,  1698,  1699,  1700,
    1701,  1702,  1703,  1704,  1705,  1706,  1707,  1708,  1709,  1710,
    1711,  1712,  1713,  1714,  1715,  1718,  1721,  1722,  1725,  1726,
    1728,  1732,  1745,  1759,  1765,  1770,  1775,  1780,  1785,  1790,
    1798,  1799,  1801,  1806,  1810,  1814,  1820,  1824,  1828,  1832,
    1836,  1842,  1845
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FSC_LIST", "FSC_DEFINE", "FSC_EXEC",
  "FSC_QUIT", "FSC_DEBUG", "FSC_CREATE", "FSC_SLEEP", "FSC_STATS",
  "FSC_FOREACH", "FSC_SET", "FSC_SHUTDOWN", "FSC_LOG", "FSC_SYSTEM",
  "FSC_FLOWOP", "FSC_EVENTGEN", "FSC_ECHO", "FSC_LOAD", "FSC_RUN",
  "FSC_WARMUP", "FSC_NOUSESTATS", "FSC_FSCHECK", "FSC_FSFLUSH",
  "FSC_USAGE", "FSC_HELP", "FSC_VARS", "FSC_VERSION", "FSC_ENABLE",
  "FSC_DOMULTISYNC", "FSV_STRING", "FSV_VAL_INT", "FSV_VAL_BOOLEAN",
  "FSV_VARIABLE", "FSV_WHITESTRING", "FSV_RANDUNI", "FSV_RANDTAB",
  "FSV_RANDVAR", "FSV_URAND", "FSV_RAND48", "FST_INT", "FST_BOOLEAN",
  "FSE_FILE", "FSE_PROC", "FSE_THREAD", "FSE_CLEAR", "FSE_ALL", "FSE_SNAP",
  "FSE_DUMP", "FSE_DIRECTORY", "FSE_COMMAND", "FSE_FILESET", "FSE_POSSET",
  "FSE_XMLDUMP", "FSE_RAND", "FSE_MODE", "FSE_MULTI", "FSE_MULTIDUMP",
  "FSK_SEPLST", "FSK_OPENLST", "FSK_CLOSELST", "FSK_ASSIGN", "FSK_IN",
  "FSK_QUOTE", "FSK_DIRSEPLST", "FSK_PLUS", "FSK_MINUS", "FSK_MULTIPLY",
  "FSK_DIVIDE", "FSA_SIZE", "FSA_PREALLOC", "FSA_PARALLOC", "FSA_PATH",
  "FSA_REUSE", "FSA_DUP", "FSA_COMP", "FSA_RANDOMSEED", "FSA_PAGESIZE",
  "FSA_PROCESS", "FSA_MEMSIZE", "FSA_RATE", "FSA_CACHED", "FSA_READONLY",
  "FSA_TRUSTTREE", "FSA_IOSIZE", "FSA_FILE", "FSA_POSSET", "FSA_WSS",
  "FSA_NAME", "FSA_RANDOM", "FSA_INSTANCES", "FSA_DSYNC", "FSA_TARGET",
  "FSA_ITERS", "FSA_NICE", "FSA_VALUE", "FSA_BLOCKING", "FSA_HIGHWATER",
  "FSA_DIRECTIO", "FSA_DIRWIDTH", "FSA_FD", "FSA_SRCFD", "FSA_ROTATEFD",
  "FSA_NAMELENGTH", "FSA_FILESIZE", "FSA_ENTRIES", "FSA_FILESIZEGAMMA",
  "FSA_DIRDEPTHRV", "FSA_DIRGAMMA", "FSA_USEISM", "FSA_TYPE",
  "FSA_RANDTABLE", "FSA_RANDSRC", "FSA_RANDROUND", "FSA_LEAFDIRS",
  "FSA_INDEXED", "FSA_FSTYPE", "FSA_RANDSEED", "FSA_RANDGAMMA",
  "FSA_RANDMEAN", "FSA_RANDMIN", "FSA_RANDMAX", "FSA_MASTER", "FSA_CLIENT",
  "FSS_TYPE", "FSS_SEED", "FSS_GAMMA", "FSS_MEAN", "FSS_MIN", "FSS_SRC",
  "FSS_ROUND", "FSV_SET_LOCAL_VAR", "FSA_LVAR_ASSIGN", "FSA_ALLDONE",
  "FSA_FIRSTDONE", "FSA_TIMEOUT", "FSC_OSPROF_ENABLE",
  "FSC_OSPROF_DISABLE", "FSA_NOREADAHEAD", "FSA_IOPRIO", "FSA_WRITEONLY",
  "$accept", "commands", "inner_commands", "command", "foreach_command",
  "integer_seplist", "string_seplist", "eventgen_command",
  "system_command", "echo_command", "version_command",
  "osprof_enable_command", "osprof_disable_command", "usage_command",
  "vars_command", "enable_command", "multisync_command", "var_string",
  "var_string_list", "whitevar_string", "whitevar_string_list",
  "list_command", "fscheck_command", "fsflush_command", "log_command",
  "debug_command", "set_command", "set_integer_command",
  "set_other_command", "stats_command", "quit_command", "flowop_list",
  "thread", "thread_list", "proc_define_command", "files_define_command",
  "posset_define_command", "randvar_define_command", "fo_define_command",
  "create_command", "shutdown_command", "warmup_command", "sleep_command",
  "run_command", "help_command", "flowop_command", "load_command",
  "entity", "name", "files_attr_ops", "posset_attr_ops", "posset_attr_op",
  "files_attr_op", "randvar_attr_ops", "randvar_attr_op", "probtabentry",
  "probtabentry_list", "pt_attr_ops", "pt_attr_op", "fo_attr_ops",
  "fo_attr_op", "ev_attr_ops", "ev_attr_op", "enable_multi_ops",
  "enable_multi_op", "multisync_op", "fscheck_attr_op", "binary_op",
  "files_attr_name", "posset_attr_name", "pt_attr_name", "fo_attr_name",
  "ev_attr_name", "attrs_define_proc", "attrs_define_file",
  "attrs_define_fileset", "attrs_define_posset", "randvar_attr_name",
  "randvar_attr_tsp", "randvar_attr_param", "randvar_attr_typop",
  "randtype_name", "randvar_attr_srcop", "randsrc_name",
  "attrs_define_thread", "attrs_flowop", "attrs_eventgen", "em_attr_name",
  "fscheck_attr_name", "comp_attr_ops", "comp_attr_op", "comp_lvar_def",
  "attrs_define_comp", "attr_value", "attr_list_value", "var_int_val", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   142,   143,   143,   143,   144,   144,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   146,   146,
     146,   147,   147,   148,   148,   149,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   157,   158,   159,   159,   160,
     160,   160,   160,   160,   161,   161,   162,   162,   162,   162,
     162,   162,   162,   162,   163,   163,   164,   164,   165,   166,
     167,   168,   168,   169,   169,   169,   169,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   171,   171,   171,
     171,   171,   171,   171,   172,   173,   173,   174,   175,   175,
     176,   176,   177,   177,   177,   178,   178,   179,   180,   180,
     181,   182,   183,   183,   184,   184,   185,   185,   185,   186,
     187,   187,   188,   189,   189,   189,   189,   190,   191,   191,
     192,   192,   193,   193,   194,   194,   195,   195,   195,   196,
     196,   196,   196,   197,   198,   198,   199,   199,   200,   200,
     201,   201,   201,   202,   202,   203,   203,   204,   204,   205,
     205,   206,   207,   208,   209,   209,   209,   209,   210,   210,
     211,   212,   212,   213,   214,   215,   215,   215,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   218,   218,   218,   218,   218,   219,   219,   219,   219,
     219,   219,   220,   220,   220,   220,   220,   220,   220,   221,
     221,   221,   221,   221,   222,   223,   223,   223,   224,   225,
     225,   226,   226,   226,   226,   226,   226,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   228,   229,   229,   230,   230,
     231,   231,   231,   232,   233,   233,   233,   233,   233,   233,
     234,   234,   235,   235,   235,   235,   236,   236,   236,   236,
     236,   237,   237
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     7,
       7,     1,     3,     3,     5,     1,     2,     2,     2,     1,
       1,     1,     2,     1,     2,     2,     2,     1,     1,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     3,     2,
       2,     3,     2,     2,     1,     2,     2,     2,     2,     2,
       2,     1,     1,     4,     4,     3,     3,     4,     6,     4,
       4,     4,     4,     3,     5,     5,     5,     2,     2,     3,
       3,     3,     3,     3,     1,     1,     2,     5,     1,     2,
       6,     2,     2,     2,     2,     2,     2,     3,     6,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     3,     1,     3,     1,     1,     3,     7,     3,
       1,     3,     3,     7,     1,     3,     1,     3,     3,     1,
       1,     3,     3,     3,     1,     1,     3,     3,     1,     1,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     5,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     1,     3,    74,     0,   104,     0,     0,     0,
       0,    38,     0,     0,     0,     0,    45,     0,     0,   128,
       0,     0,     0,     0,   129,    53,    49,     0,     0,    50,
      51,     2,    18,    13,    31,    15,    32,    33,    34,    16,
      17,    35,    36,    22,    19,    20,    24,    12,    26,    81,
      82,    30,    37,     7,     8,     9,    10,    11,    14,    27,
      29,    28,    25,    21,    23,     0,   112,     0,   113,   115,
       0,    80,   136,   133,   134,   135,   120,   124,   125,    98,
      97,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,    79,    47,    48,   132,   126,   127,   122,   123,
     278,   279,    76,     0,    78,    52,    54,     0,    56,     0,
     275,    46,   165,   168,   184,   276,   277,    55,   169,     0,
      75,    77,   174,   175,   176,   177,     0,   251,   253,   186,
     187,   185,   254,   256,   111,   156,   159,   182,   181,   188,
     198,   199,   190,   193,   194,   195,   197,   196,   217,   191,
     192,   189,   204,   218,   215,   205,   216,   219,   200,   114,
     138,   145,   178,   179,   221,   224,   222,   223,   225,   116,
     140,   143,   180,   290,   291,   119,   280,     0,     0,     0,
     226,     0,     0,   231,   227,   228,   229,   230,   117,   146,
     150,   101,    58,    57,    59,    99,   100,   102,   103,     0,
       0,   239,   240,   241,   242,     0,   243,     0,     0,    93,
      64,    65,    67,    66,     0,    73,    70,    69,     0,    72,
       0,     0,     0,     0,     0,     0,     0,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    60,    61,    62,    63,    89,    83,    87,
      84,     0,     0,     0,     0,    91,    92,    90,   232,   234,
     235,   236,   237,   233,   238,    68,    71,   173,   292,   293,
     294,   295,   172,    41,     0,     0,     0,   166,   167,   170,
     171,   157,   158,   139,    58,   298,   299,    57,   296,   144,
     141,   142,   289,   281,   282,   283,     0,     0,   105,     0,
     108,     0,   245,   246,   247,   151,   244,   249,   250,   152,
     248,     0,   147,   149,     0,    94,    95,    96,     0,     0,
       0,     0,     0,     0,   137,   130,   118,   106,   273,   258,
     259,   257,   260,   261,   265,   268,   269,   270,   271,   272,
     266,   262,   263,   264,   267,   274,   131,   160,   164,   183,
       0,   110,   109,     0,    88,    43,    42,     0,     5,     0,
       0,   287,   285,   284,   288,     0,     0,     0,     0,     0,
      39,     6,     0,    40,     0,   161,   162,   163,     0,     0,
     154,     0,    44,   286,   107,   301,   302,     0,     0,   148,
       0,   155,     0,     0,     0,   153
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   357,   358,    32,   275,   276,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   194,   288,    91,
      92,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,   297,   300,   301,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,   298,    64,    76,   325,   159,
     169,   170,   160,   188,   189,   380,   381,   134,   135,   346,
     347,   111,   112,   117,   118,   108,   102,   126,   161,   171,
     136,   348,   113,   137,   162,   163,   172,   190,   265,   207,
     305,   306,   309,   310,   138,   349,   114,   119,   103,   175,
     176,   294,   177,   272,   289,   387
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -285
static const yytype_int16 yypact[] =
{
    -285,    16,  -285,  -285,  -285,   122,  -285,   -29,   -34,   136,
     270,  -285,   108,   -34,   -52,   -52,  -285,   -52,     7,   277,
     293,    63,    63,   -52,  -285,  -285,  -285,    -8,   -36,  -285,
    -285,  -285,   106,    74,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,    25,  -285,   143,    63,  -285,  -285,  -285,  -285,   139,
    -285,  -285,  -285,    52,   152,    45,  -285,    89,  -285,  -285,
    -285,  -285,  -285,  -285,  -285,    89,  -285,    52,  -285,  -285,
     194,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,   -52,   208,   -52,   -52,   -52,   110,   206,   138,  -285,
     150,   228,   266,   266,   266,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,  -285,   134,  -285,   266,  -285,   153,  -285,   116,
    -285,   142,  -285,   159,  -285,  -285,  -285,   184,  -285,   195,
    -285,  -285,  -285,  -285,  -285,  -285,   319,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,   205,  -285,   212,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,   232,
    -285,   236,  -285,  -285,  -285,  -285,  -285,  -285,  -285,   243,
    -285,   248,  -285,  -285,  -285,   258,  -285,   267,   172,   302,
    -285,   288,   309,  -285,  -285,  -285,  -285,  -285,   295,  -285,
     311,   266,  -285,  -285,   272,   292,   266,   266,   266,   180,
     312,  -285,  -285,  -285,  -285,   313,  -285,   315,   115,  -285,
    -285,  -285,  -285,  -285,   213,  -285,  -285,  -285,   213,  -285,
     341,   222,   105,    74,   222,    25,   222,  -285,  -285,    52,
     222,   152,   314,    45,   314,    82,   222,   360,   333,   -31,
     324,   176,   314,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,   344,   -31,   324,   222,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,   345,   306,   308,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,   292,  -285,
    -285,  -285,   320,  -285,  -285,  -285,   350,     5,   183,    52,
    -285,   112,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,   321,  -285,  -285,   322,  -285,  -285,  -285,   325,   352,
     100,   326,   100,   214,  -285,  -285,  -285,   183,  -285,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,   328,  -285,   329,  -285,
     310,  -285,  -285,   332,  -285,  -285,  -285,    44,  -285,   353,
      72,  -285,  -285,  -285,  -285,   358,   101,   222,   360,   334,
    -285,  -285,   331,  -285,   335,  -285,  -285,  -285,    61,   323,
    -285,   299,  -285,  -285,  -285,  -285,  -285,   337,   334,  -285,
     323,  -285,   338,   323,   339,  -285
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -285,  -285,    76,    -1,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,   303,  -285,
     135,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,    33,   102,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,  -285,  -284,  -285,   389,  -285,  -285,
    -285,   171,   174,  -285,   165,    19,  -285,   -66,   179,  -285,
      43,  -285,   187,  -285,   186,  -285,   117,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,   196,  -285,
     160,  -285,   162,  -285,  -285,  -285,  -285,  -285,  -285,   348,
     181,    51,  -285,  -222,  -227,   -41
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      31,   179,   278,    71,   280,   302,   303,   291,   282,    72,
      73,    74,    90,   327,   295,   313,     2,     3,    75,     4,
       5,   296,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,   317,    16,    17,    18,    19,    20,    95,    21,
      22,    23,    24,    25,    26,    27,    28,     4,     5,   106,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
     107,    16,    17,    18,    19,    20,   326,    21,    22,    23,
      24,    25,    26,    27,    28,     4,     5,   296,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,   304,    16,
      17,    18,    19,    20,   327,    21,    22,    23,    24,    25,
      26,    27,    28,     4,     5,   370,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,   292,    16,    17,    18,
      19,    20,   384,    21,    22,    23,    24,    25,    26,    27,
      28,   127,   128,   373,   164,   292,   100,   273,    65,   104,
     109,   129,    86,   130,   208,   377,    87,   131,   115,   116,
      93,   165,    94,    29,    30,   110,   166,   299,   105,   120,
     209,   121,   132,   167,    88,    66,    67,   168,    77,   274,
      78,   173,   199,   351,    68,    69,   174,    70,   173,   222,
     101,    29,    30,   174,   210,   211,   328,   329,   330,   331,
     332,   333,   133,   334,   335,   336,   220,   337,   338,   339,
     340,   223,   341,   342,   343,   122,   123,   124,   125,    29,
      30,   247,   248,   249,   250,   221,   191,   344,   196,   197,
     198,   224,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   235,   237,   350,   148,   149,   150,    29,    30,   192,
     345,   151,   193,   225,   251,   361,   362,   363,   364,   255,
     256,   257,   152,   268,   269,   270,   271,   226,   153,   154,
     155,   156,   212,   213,   229,   180,   214,   157,   328,   329,
     330,   331,   332,   333,   230,   334,   335,   336,   365,   337,
     338,   339,   340,   180,   341,   342,   343,   181,   311,   182,
     183,   231,   215,   158,   184,   185,   186,   187,   232,   344,
     216,   217,   233,   243,   218,   181,   244,   182,   183,    96,
     234,    97,   184,   185,   186,   187,    79,   235,    80,    81,
      82,    83,   345,   245,    84,    98,   246,    99,    85,   236,
     219,   200,   201,   202,   203,   204,   205,   206,   258,   259,
     260,   261,   262,   263,   264,   284,   285,   286,   287,   392,
     239,   227,   394,   228,   241,   385,   371,   386,   388,   371,
     389,   229,   238,   307,   308,   319,   320,   321,   322,   229,
     368,   240,   267,   242,   252,   253,   296,   254,   299,   314,
     318,   324,   323,   353,   356,   195,   354,   366,   372,   355,
     359,   367,   369,   374,   379,   382,   390,   393,   360,   383,
     395,   378,    89,   352,   290,   283,   312,   391,   281,   375,
     277,   279,   315,   178,   266,   316,   293,   376
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-285))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_uint16 yycheck[] =
{
       1,    67,   224,    32,   226,    36,    37,   234,   230,    43,
      44,    45,    64,   297,   236,   242,     0,     1,    52,     3,
       4,    16,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,   254,    17,    18,    19,    20,    21,    31,    23,
      24,    25,    26,    27,    28,    29,    30,     3,     4,    57,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      96,    17,    18,    19,    20,    21,    61,    23,    24,    25,
      26,    27,    28,    29,    30,     3,     4,    16,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,   119,    17,
      18,    19,    20,    21,   378,    23,    24,    25,    26,    27,
      28,    29,    30,     3,     4,    61,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    34,    17,    18,    19,
      20,    21,    61,    23,    24,    25,    26,    27,    28,    29,
      30,    79,    80,    61,    89,    34,    73,    32,    16,    22,
      34,    89,    34,    91,     6,   367,    38,    95,   123,   124,
      15,   106,    17,   137,   138,    81,   111,    45,    23,    16,
      22,    44,   110,   118,    56,    43,    44,   122,    32,    64,
      34,    89,    62,    61,    52,    53,    94,    55,    89,    63,
     117,   137,   138,    94,    34,    35,    85,    86,    87,    88,
      89,    90,   140,    92,    93,    94,    62,    96,    97,    98,
      99,    59,   101,   102,   103,    66,    67,    68,    69,   137,
     138,    31,    32,    33,    34,    62,    81,   116,    83,    84,
      85,    62,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    59,    60,   299,    82,    83,    84,   137,   138,    31,
     139,    89,    34,    59,    64,    31,    32,    33,    34,   134,
     135,   136,   100,    31,    32,    33,    34,    62,   106,   107,
     108,   109,    34,    35,    59,    89,    38,   115,    85,    86,
      87,    88,    89,    90,    62,    92,    93,    94,    64,    96,
      97,    98,    99,    89,   101,   102,   103,   111,   112,   113,
     114,    59,    64,   141,   118,   119,   120,   121,    62,   116,
      34,    35,    59,    31,    38,   111,    34,   113,   114,    32,
      62,    34,   118,   119,   120,   121,    46,    59,    48,    49,
      50,    51,   139,    31,    54,    32,    34,    34,    58,    62,
      64,   125,   126,   127,   128,   129,   130,   131,   125,   126,
     127,   128,   129,   130,   131,    31,    32,    33,    34,   390,
      62,    32,   393,    34,    59,    32,   357,    34,    59,   360,
      61,    59,    60,    39,    40,    59,    60,    59,    60,    59,
      60,    62,    31,    62,    62,    62,    16,    62,    45,    35,
      35,    31,    62,    62,    32,    82,    64,    59,    35,    64,
      64,    62,    60,    35,    60,    64,    59,    59,   322,    64,
      61,   368,    13,   301,   233,   231,   241,   388,   229,   366,
     223,   225,   252,    65,   218,   253,   235,   366
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   143,     0,     1,     3,     4,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    17,    18,    19,    20,
      21,    23,    24,    25,    26,    27,    28,    29,    30,   137,
     138,   145,   146,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   188,    16,    43,    44,    52,    53,
      55,    32,    43,    44,    45,    52,   189,    32,    34,    46,
      48,    49,    50,    51,    54,    58,    34,    38,    56,   189,
      64,   161,   162,   162,   162,    31,    32,    34,    32,    34,
      73,   117,   208,   230,   208,   162,    57,    96,   207,    34,
      81,   203,   204,   214,   228,   123,   124,   205,   206,   229,
      16,   208,    66,    67,    68,    69,   209,    79,    80,    89,
      91,    95,   110,   140,   199,   200,   212,   215,   226,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    82,    83,
      84,    89,   100,   106,   107,   108,   109,   115,   141,   191,
     194,   210,   216,   217,    89,   106,   111,   118,   122,   192,
     193,   211,   218,    89,    94,   231,   232,   234,   231,   199,
      89,   111,   113,   114,   118,   119,   120,   121,   195,   196,
     219,   162,    31,    34,   159,   160,   162,   162,   162,    62,
     125,   126,   127,   128,   129,   130,   131,   221,     6,    22,
      34,    35,    34,    35,    38,    64,    34,    35,    38,    64,
      62,    62,    63,    59,    62,    59,    62,    32,    34,    59,
      62,    59,    62,    59,    62,    59,    62,    60,    60,    62,
      62,    59,    62,    31,    34,    31,    34,    31,    32,    33,
      34,    64,    62,    62,    62,   134,   135,   136,   125,   126,
     127,   128,   129,   130,   131,   220,   220,    31,    31,    32,
      33,    34,   235,    32,    64,   147,   148,   204,   235,   206,
     235,   200,   235,   194,    31,    32,    33,    34,   160,   236,
     193,   236,    34,   232,   233,   235,    16,   173,   187,    45,
     174,   175,    36,    37,   119,   222,   223,    39,    40,   224,
     225,   112,   196,   236,    35,   222,   224,   235,    35,    59,
      60,    59,    60,    62,    31,   190,    61,   187,    85,    86,
      87,    88,    89,    90,    92,    93,    94,    96,    97,    98,
      99,   101,   102,   103,   116,   139,   201,   202,   213,   227,
     199,    61,   174,    62,    64,    64,    32,   144,   145,    64,
     144,    31,    32,    33,    34,    64,    59,    62,    60,    60,
      61,   145,    35,    61,    35,   202,   233,   235,   173,    60,
     197,   198,    64,    64,    61,    32,    34,   237,    59,    61,
      59,   197,   237,    59,   237,    61
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 257 "parser_gram.y"
    {
	if ((yyvsp[(2) - (2)].cmd)->cmd != NULL)
		(yyvsp[(2) - (2)].cmd)->cmd((yyvsp[(2) - (2)].cmd));

	free((yyvsp[(2) - (2)].cmd));
}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 264 "parser_gram.y"
    {
	if (dofile == DOFILE_TRUE)
		YYABORT;
}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 271 "parser_gram.y"
    {
	filebench_log(LOG_DEBUG_IMPL, "inner_command %zx", (yyvsp[(1) - (1)].cmd));
	(yyval.cmd) = (yyvsp[(1) - (1)].cmd);
}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 276 "parser_gram.y"
    {
	cmd_t *list = NULL;
	cmd_t *list_end = NULL;

	/* Find end of list */
	for (list = (yyvsp[(1) - (2)].cmd); list != NULL;
	    list = list->cmd_next)
		list_end = list;

	list_end->cmd_next = (yyvsp[(2) - (2)].cmd);

	filebench_log(LOG_DEBUG_IMPL,
	    "inner_commands adding cmd %zx to list %zx", (yyvsp[(2) - (2)].cmd), (yyvsp[(1) - (2)].cmd));

	(yyval.cmd) = (yyvsp[(1) - (2)].cmd);
}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 327 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	filebench_log(LOG_DEBUG_IMPL, "foreach_command %zx", (yyval.cmd));
}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 333 "parser_gram.y"
    {
	cmd_t *inner_cmd;
	list_t *list;

	(yyval.cmd) = (yyvsp[(1) - (7)].cmd);
	(yyval.cmd)->cmd_list = (yyvsp[(6) - (7)].cmd);
	(yyval.cmd)->cmd_tgt1 = (yyvsp[(2) - (7)].sval);
	(yyval.cmd)->cmd_param_list = (yyvsp[(4) - (7)].list);
	(yyval.cmd)->cmd = parser_foreach_integer;

	for (list = (yyval.cmd)->cmd_param_list; list != NULL;
	    list = list->list_next) {
		for (inner_cmd = (yyval.cmd)->cmd_list;
		    inner_cmd != NULL;
		    inner_cmd = inner_cmd->cmd_next) {
			filebench_log(LOG_DEBUG_IMPL,
			    "packing foreach: %zx %s=%llu, cmd %zx",
			    (yyval.cmd), (yyval.cmd)->cmd_tgt1,
			    (u_longlong_t)avd_get_int(list->list_integer),
			    inner_cmd);
		}
	}
}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 356 "parser_gram.y"
    {
	cmd_t *inner_cmd;
	list_t *list;

	(yyval.cmd) = (yyvsp[(1) - (7)].cmd);
	(yyval.cmd)->cmd_list = (yyvsp[(6) - (7)].cmd);
	(yyval.cmd)->cmd_tgt1 = (yyvsp[(2) - (7)].sval);
	(yyval.cmd)->cmd_param_list = (yyvsp[(4) - (7)].list);
	(yyval.cmd)->cmd = parser_foreach_string;

	for (list = (yyval.cmd)->cmd_param_list; list != NULL;
	    list = list->list_next) {
		for (inner_cmd = (yyval.cmd)->cmd_list;
		    inner_cmd != NULL;
		    inner_cmd = inner_cmd->cmd_next) {
			filebench_log(LOG_DEBUG_IMPL,
			    "packing foreach: %zx %s=%s, cmd %zx",
			    (yyval.cmd),
			    (yyval.cmd)->cmd_tgt1,
			    *list->list_string, inner_cmd);
		}
	}
}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 381 "parser_gram.y"
    {
	if (((yyval.list) = alloc_list()) == NULL)
		YYERROR;

	(yyval.list)->list_integer = avd_int_alloc((yyvsp[(1) - (1)].ival));
}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 388 "parser_gram.y"
    {
	list_t *list = NULL;
	list_t *list_end = NULL;

	if (((yyval.list) = alloc_list()) == NULL)
		YYERROR;

	(yyval.list)->list_integer = avd_int_alloc((yyvsp[(3) - (3)].ival));

	/* Find end of list */
	for (list = (yyvsp[(1) - (3)].list); list != NULL;
	    list = list->list_next)
		list_end = list;
	list_end->list_next = (yyval.list);
	(yyval.list) = (yyvsp[(1) - (3)].list);
}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 406 "parser_gram.y"
    {
	if (((yyval.list) = alloc_list()) == NULL)
		YYERROR;

	(yyval.list)->list_string = avd_str_alloc((yyvsp[(2) - (3)].sval));
}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 413 "parser_gram.y"
    {
	list_t *list = NULL;
	list_t *list_end = NULL;

	if (((yyval.list) = alloc_list()) == NULL)
			YYERROR;

	(yyval.list)->list_string = avd_str_alloc((yyvsp[(4) - (5)].sval));

	/* Find end of list */
	for (list = (yyvsp[(1) - (5)].list); list != NULL;
	    list = list->list_next)
		list_end = list;
	list_end->list_next = (yyval.list);
	(yyval.list) = (yyvsp[(1) - (5)].list);
}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 431 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = &parser_eventgen;
}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 437 "parser_gram.y"
    {
	(yyvsp[(1) - (2)].cmd)->cmd_attr_list = (yyvsp[(2) - (2)].attr);
}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 442 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;

	(yyval.cmd)->cmd_param_list = (yyvsp[(2) - (2)].list);
	(yyval.cmd)->cmd = parser_system;
}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 451 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;

	(yyval.cmd)->cmd_param_list = (yyvsp[(2) - (2)].list);
	(yyval.cmd)->cmd = parser_echo;
}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 460 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_version;
}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 467 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_osprof_enable;
}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 474 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_osprof_disable;
}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 481 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;

	(yyval.cmd)->cmd_param_list = (yyvsp[(2) - (2)].list);
	(yyval.cmd)->cmd = parser_usage;
}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 490 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;

	(yyval.cmd)->cmd = parser_printvars;
}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 498 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;

	(yyval.cmd)->cmd = parser_enable_mc;
}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 505 "parser_gram.y"
    {
	(yyvsp[(1) - (2)].cmd)->cmd_attr_list = (yyvsp[(2) - (2)].attr);
}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 510 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;

	(yyval.cmd)->cmd = parser_domultisync;
	(yyval.cmd)->cmd_attr_list = (yyvsp[(2) - (2)].attr);
}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 543 "parser_gram.y"
    {
	if (((yyval.list) = alloc_list()) == NULL)
			YYERROR;

	(yyval.list)->list_string = avd_str_alloc((yyvsp[(1) - (1)].sval));
}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 550 "parser_gram.y"
    {
	if (((yyval.list) = alloc_list()) == NULL)
			YYERROR;

	(yyval.list)->list_string = avd_str_alloc((yyvsp[(1) - (1)].sval));
}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 558 "parser_gram.y"
    {
	(yyval.list) = (yyvsp[(1) - (1)].list);
}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 561 "parser_gram.y"
    {
	list_t *list = NULL;
	list_t *list_end = NULL;

	/* Add string */
	if (((yyval.list) = alloc_list()) == NULL)
		YYERROR;

	(yyval.list)->list_string = avd_str_alloc((yyvsp[(2) - (2)].sval));

	/* Find end of list */
	for (list = (yyvsp[(1) - (2)].list); list != NULL;
	    list = list->list_next)
		list_end = list;
	list_end->list_next = (yyval.list);
	(yyval.list) = (yyvsp[(1) - (2)].list);

}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 579 "parser_gram.y"
    {
	list_t *list = NULL;
	list_t *list_end = NULL;

	/* Add variable */
	if (((yyval.list) = alloc_list()) == NULL)
		YYERROR;

	(yyval.list)->list_string = avd_str_alloc((yyvsp[(2) - (2)].sval));

	/* Find end of list */
	for (list = (yyvsp[(1) - (2)].list); list != NULL;
	    list = list->list_next)
		list_end = list;
	list_end->list_next = (yyval.list);
	(yyval.list) = (yyvsp[(1) - (2)].list);
}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 596 "parser_gram.y"
    {
	list_t *list = NULL;
	list_t *list_end = NULL;

	/* Add string */
	if (((yyval.list) = alloc_list()) == NULL)
		YYERROR;

	(yyval.list)->list_string = avd_str_alloc((yyvsp[(2) - (2)].sval));

	/* Find end of list */
	for (list = (yyvsp[(1) - (2)].list); list != NULL;
	    list = list->list_next)
		list_end = list;
	list_end->list_next = (yyval.list);
	(yyval.list) = (yyvsp[(1) - (2)].list);

}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 614 "parser_gram.y"
    {
	list_t *list = NULL;
	list_t *list_end = NULL;

	/* Add variable */
	if (((yyval.list) = alloc_list()) == NULL)
		YYERROR;

	(yyval.list)->list_string = avd_str_alloc((yyvsp[(2) - (2)].sval));

	/* Find end of list */
	for (list = (yyvsp[(1) - (2)].list); list != NULL;
	    list = list->list_next)
		list_end = list;
	list_end->list_next = (yyval.list);
	(yyval.list) = (yyvsp[(1) - (2)].list);
}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 633 "parser_gram.y"
    {
	if (((yyval.list) = alloc_list()) == NULL)
			YYERROR;

	(yyval.list)->list_string = avd_str_alloc((yyvsp[(2) - (2)].sval));
}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 640 "parser_gram.y"
    {
	if (((yyval.list) = alloc_list()) == NULL)
			YYERROR;

	(yyval.list)->list_string = avd_str_alloc((yyvsp[(2) - (2)].sval));
}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 648 "parser_gram.y"
    {
	list_t *list = NULL;
	list_t *list_end = NULL;

	/* Add string */
	if (((yyval.list) = alloc_list()) == NULL)
		YYERROR;

	(yyval.list)->list_string = avd_str_alloc((yyvsp[(2) - (2)].sval));

	/* Find end of list */
	for (list = (yyvsp[(1) - (2)].list); list != NULL;
	    list = list->list_next)
		list_end = list;
	list_end->list_next = (yyval.list);
	(yyval.list) = (yyvsp[(1) - (2)].list);

}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 666 "parser_gram.y"
    {
	list_t *list = NULL;
	list_t *list_end = NULL;

	/* Add variable */
	if (((yyval.list) = alloc_list()) == NULL)
		YYERROR;

	(yyval.list)->list_string = avd_str_alloc((yyvsp[(2) - (2)].sval));

	/* Find end of list */
	for (list = (yyvsp[(1) - (2)].list); list != NULL;
	    list = list->list_next)
		list_end = list;
	list_end->list_next = (yyval.list);
	(yyval.list) = (yyvsp[(1) - (2)].list);
}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 683 "parser_gram.y"
    {
	list_t *list = NULL;
	list_t *list_end = NULL;

	/* Add variable */
	if (((yyval.list) = alloc_list()) == NULL)
		YYERROR;

	(yyval.list)->list_string = avd_str_alloc((yyvsp[(2) - (3)].sval));
	(yyval.list)->list_integer = avd_int_alloc((yyvsp[(3) - (3)].ival));

	/* Find end of list */
	for (list = (yyvsp[(1) - (3)].list); list != NULL;
	    list = list->list_next)
		list_end = list;
	list_end->list_next = (yyval.list);
	(yyval.list) = (yyvsp[(1) - (3)].list);
}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 701 "parser_gram.y"
    {
	list_t *list = NULL;
	list_t *list_end = NULL;

	/* Add string */
	if (((yyval.list) = alloc_list()) == NULL)
		YYERROR;

	(yyval.list)->list_string = avd_str_alloc((yyvsp[(2) - (2)].sval));

	/* Find end of list */
	for (list = (yyvsp[(1) - (2)].list); list != NULL;
	    list = list->list_next)
		list_end = list;
	list_end->list_next = (yyval.list);
	(yyval.list) = (yyvsp[(1) - (2)].list);

}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 719 "parser_gram.y"
    {
	list_t *list = NULL;
	list_t *list_end = NULL;

	/* Add variable */
	if (((yyval.list) = alloc_list()) == NULL)
		YYERROR;

	(yyval.list)->list_string = avd_str_alloc((yyvsp[(2) - (2)].sval));

	/* Find end of list */
	for (list = (yyvsp[(1) - (2)].list); list != NULL;
	    list = list->list_next)
		list_end = list;
	list_end->list_next = (yyval.list);
	(yyval.list) = (yyvsp[(1) - (2)].list);
}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 736 "parser_gram.y"
    {
	list_t *list = NULL;
	list_t *list_end = NULL;

	/* Add variable */
	if (((yyval.list) = alloc_list()) == NULL)
		YYERROR;

	(yyval.list)->list_string = avd_str_alloc((yyvsp[(2) - (3)].sval));
	(yyval.list)->list_integer = avd_int_alloc((yyvsp[(3) - (3)].ival));

	/* Find end of list */
	for (list = (yyvsp[(1) - (3)].list); list != NULL;
	    list = list->list_next)
		list_end = list;
	list_end->list_next = (yyval.list);
	(yyval.list) = (yyvsp[(1) - (3)].list);
}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 754 "parser_gram.y"
    {
	(yyval.list) = (yyvsp[(1) - (2)].list);
}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 757 "parser_gram.y"
    {
	(yyval.list) = (yyvsp[(1) - (2)].list);
}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 762 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = &parser_list;
}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 768 "parser_gram.y"
    {
	(yyvsp[(1) - (2)].cmd)->cmd = &parser_flowop_list;
}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 773 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = &parser_fscheck;

	(yyval.cmd)->cmd_attr_list = (yyvsp[(2) - (2)].attr);
}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 781 "parser_gram.y"
    {
	(yyvsp[(1) - (2)].cmd)->cmd_attr_list->attr_next = (yyvsp[(2) - (2)].attr);
}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 786 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = &parser_fsflush;

	(yyval.cmd)->cmd_attr_list = (yyvsp[(2) - (2)].attr);
}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 795 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = &parser_log;
	(yyval.cmd)->cmd_param_list = (yyvsp[(2) - (2)].list);
}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 803 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = NULL;
	filebench_shm->shm_debug_level = (yyvsp[(2) - (2)].ival);
	if (filebench_shm->shm_debug_level > 9)
		yydebug = 1;
}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 817 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd_tgt1 = (yyvsp[(2) - (4)].sval);
	(yyval.cmd)->cmd_qty = (yyvsp[(4) - (4)].ival);
	if (parentscript) {
		parser_vars((yyval.cmd));
	}
	(yyval.cmd)->cmd = parser_set_integer;
}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 827 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	var_assign_var((yyvsp[(2) - (4)].sval), (yyvsp[(4) - (4)].sval));
	(yyval.cmd)->cmd_tgt1 = (yyvsp[(2) - (4)].sval);
	(yyval.cmd)->cmd_tgt2 = (yyvsp[(4) - (4)].sval);
	if (parentscript) {
		parser_vars((yyval.cmd));
	}
	(yyval.cmd)->cmd = parser_set_var;
}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 839 "parser_gram.y"
    {
	if ((yyvsp[(1) - (3)].cmd)->cmd == parser_set_integer) {
		switch ((yyvsp[(2) - (3)].ival)) {
		case FSK_PLUS:
			var_assign_integer((yyvsp[(1) - (3)].cmd)->cmd_tgt1, (yyvsp[(1) - (3)].cmd)->cmd_qty + (yyvsp[(3) - (3)].ival));
			break;
		case FSK_MINUS:
			var_assign_integer((yyvsp[(1) - (3)].cmd)->cmd_tgt1, (yyvsp[(1) - (3)].cmd)->cmd_qty - (yyvsp[(3) - (3)].ival));
			break;
		case FSK_MULTIPLY:
			var_assign_integer((yyvsp[(1) - (3)].cmd)->cmd_tgt1, (yyvsp[(1) - (3)].cmd)->cmd_qty * (yyvsp[(3) - (3)].ival));
			break;
		case FSK_DIVIDE:
			var_assign_integer((yyvsp[(1) - (3)].cmd)->cmd_tgt1, (yyvsp[(1) - (3)].cmd)->cmd_qty / (yyvsp[(3) - (3)].ival));
			break;
		}
		(yyval.cmd)->cmd = NULL;
	} else {
		(yyvsp[(1) - (3)].cmd)->cmd_qty = (yyvsp[(3) - (3)].ival);
		(yyvsp[(1) - (3)].cmd)->cmd_subtype = (yyvsp[(2) - (3)].ival);
		(yyvsp[(1) - (3)].cmd)->cmd = parser_set_var_op_int;
	}
}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 863 "parser_gram.y"
    {
	(yyvsp[(1) - (3)].cmd)->cmd_tgt3 = (yyvsp[(3) - (3)].sval);
	(yyvsp[(1) - (3)].cmd)->cmd_subtype = (yyvsp[(2) - (3)].ival);
	if ((yyvsp[(1) - (3)].cmd)->cmd == parser_set_integer) {
		(yyval.cmd)->cmd = parser_set_int_op_var;
	} else {
		(yyvsp[(1) - (3)].cmd)->cmd = parser_set_var_op_var;
	}
}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 874 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	var_assign_boolean((yyvsp[(2) - (4)].sval), (yyvsp[(4) - (4)].bval));
	if (parentscript) {
		(yyval.cmd)->cmd_tgt1 = (yyvsp[(2) - (4)].sval);
		parser_vars((yyval.cmd));
	}
	(yyval.cmd)->cmd = NULL;
}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 885 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	var_assign_string((yyvsp[(2) - (6)].sval), (yyvsp[(5) - (6)].sval));
	if (parentscript) {
		(yyval.cmd)->cmd_tgt1 = (yyvsp[(2) - (6)].sval);
		parser_vars((yyval.cmd));
	}
	(yyval.cmd)->cmd = NULL;
}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 895 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	var_assign_string((yyvsp[(2) - (4)].sval), (yyvsp[(4) - (4)].sval));
	if (parentscript) {
		(yyval.cmd)->cmd_tgt1 = (yyvsp[(2) - (4)].sval);
		parser_vars((yyval.cmd));
	}
	(yyval.cmd)->cmd = NULL;
}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 905 "parser_gram.y"
    {
	filebench_shm->shm_rmode = FILEBENCH_MODE_TIMEOUT;
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = NULL;
}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 911 "parser_gram.y"
    {
	filebench_shm->shm_rmode = FILEBENCH_MODE_QALLDONE;
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = NULL;
}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 917 "parser_gram.y"
    {
	filebench_shm->shm_rmode = FILEBENCH_MODE_Q1STDONE;
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = NULL;
}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 923 "parser_gram.y"
    {
	filebench_shm->shm_mmode |= FILEBENCH_MODE_NOUSAGE;
	filebench_log(LOG_INFO, "disabling CPU usage statistics");
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = NULL;
}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 930 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = &parser_randvar_set;
	(yyval.cmd)->cmd_tgt1 = (yyvsp[(2) - (5)].sval);
	(yyval.cmd)->cmd_qty = FSS_TYPE;
	(yyval.cmd)->cmd_attr_list = (yyvsp[(5) - (5)].attr);

}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 939 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = &parser_randvar_set;
	(yyval.cmd)->cmd_tgt1 = (yyvsp[(2) - (5)].sval);
	(yyval.cmd)->cmd_qty = FSS_SRC;
	(yyval.cmd)->cmd_attr_list = (yyvsp[(5) - (5)].attr);

}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 948 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = &parser_randvar_set;
	(yyval.cmd)->cmd_tgt1 = (yyvsp[(2) - (5)].sval);
	(yyval.cmd)->cmd_qty = (yyvsp[(3) - (5)].ival);
	(yyval.cmd)->cmd_attr_list = (yyvsp[(5) - (5)].attr);
	
}
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 959 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = (void (*)(struct cmd *))&parser_statssnap;
	break;

}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 967 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = (void (*)(struct cmd *))&stats_clear;

}
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 974 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd_param_list = (yyvsp[(3) - (3)].list);
	(yyval.cmd)->cmd = (void (*)(struct cmd *))&parser_directory;

}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 982 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;

	(yyval.cmd)->cmd_param_list = (yyvsp[(3) - (3)].list);
	(yyval.cmd)->cmd = parser_statscmd;

}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 990 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;

	(yyval.cmd)->cmd_param_list = (yyvsp[(3) - (3)].list);
	(yyval.cmd)->cmd = parser_statsdump;
}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 997 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;

	(yyval.cmd)->cmd_param_list = (yyvsp[(3) - (3)].list);
	(yyval.cmd)->cmd = parser_statsxmldump;
}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 1004 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;

	(yyval.cmd)->cmd_param_list = (yyvsp[(3) - (3)].list);
	(yyval.cmd)->cmd = parser_statsmultidump;
}
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 1013 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_filebench_shutdown;
}
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 1020 "parser_gram.y"
    {
	(yyval.cmd) = (yyvsp[(1) - (1)].cmd);
}
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 1023 "parser_gram.y"
    {
	cmd_t *list = NULL;
	cmd_t *list_end = NULL;

	/* Find end of list */
	for (list = (yyvsp[(1) - (2)].cmd); list != NULL;
	    list = list->cmd_next)
		list_end = list;

	list_end->cmd_next = (yyvsp[(2) - (2)].cmd);

	filebench_log(LOG_DEBUG_IMPL,
	    "flowop_list adding cmd %zx to list %zx", (yyvsp[(2) - (2)].cmd), (yyvsp[(1) - (2)].cmd));

	(yyval.cmd) = (yyvsp[(1) - (2)].cmd);
}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 1041 "parser_gram.y"
    {
	/*
	 * Allocate a cmd node per thread, with a
	 * list of flowops attached to the cmd_list
	 */
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd_list = (yyvsp[(4) - (5)].cmd);
	(yyval.cmd)->cmd_attr_list = (yyvsp[(2) - (5)].attr);
}
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 1053 "parser_gram.y"
    {
	(yyval.cmd) = (yyvsp[(1) - (1)].cmd);
}
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 1056 "parser_gram.y"
    {
	cmd_t *list = NULL;
	cmd_t *list_end = NULL;

	/* Find end of list */
	for (list = (yyvsp[(1) - (2)].cmd); list != NULL;
	    list = list->cmd_next)
		list_end = list;

	list_end->cmd_next = (yyvsp[(2) - (2)].cmd);

	filebench_log(LOG_DEBUG_IMPL,
	    "thread_list adding cmd %zx to list %zx", (yyvsp[(2) - (2)].cmd), (yyvsp[(1) - (2)].cmd));

	(yyval.cmd) = (yyvsp[(1) - (2)].cmd);
}
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 1074 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = &parser_proc_define;
	(yyval.cmd)->cmd_list = (yyvsp[(5) - (6)].cmd);
	(yyval.cmd)->cmd_attr_list = (yyvsp[(3) - (6)].attr);

}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 1083 "parser_gram.y"
    {
	(yyvsp[(1) - (2)].cmd)->cmd_attr_list = (yyvsp[(2) - (2)].attr);
}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 1088 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = &parser_file_define;
}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 1093 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = &parser_fileset_define;
}
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 1099 "parser_gram.y"
    {
	(yyvsp[(1) - (2)].cmd)->cmd_attr_list = (yyvsp[(2) - (2)].attr);
}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 1104 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = &parser_posset_define;
}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 1109 "parser_gram.y"
    {
	(yyvsp[(1) - (2)].cmd)->cmd_attr_list = (yyvsp[(2) - (2)].attr);
}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 1114 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = &parser_randvar_define;
	(yyval.cmd)->cmd_attr_list = (yyvsp[(3) - (3)].attr);
}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 1122 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = &parser_composite_flowop_define;
	(yyval.cmd)->cmd_list = (yyvsp[(5) - (6)].cmd);
	(yyval.cmd)->cmd_attr_list = (yyvsp[(3) - (6)].attr);
}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 1130 "parser_gram.y"
    {
	(yyvsp[(1) - (2)].cmd)->cmd_attr_list = (yyvsp[(2) - (2)].attr);
}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 1135 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	switch ((yyvsp[(2) - (2)].ival)) {
	case FSE_PROC:
		(yyval.cmd)->cmd = &parser_proc_create;
		break;
	case FSE_FILESET:
	case FSE_FILE:
		(yyval.cmd)->cmd = &parser_fileset_create;
		break;
	default:
		filebench_log(LOG_ERROR, "unknown entity", (yyvsp[(2) - (2)].ival));
		YYERROR;
	}

}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 1154 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	switch ((yyvsp[(2) - (2)].ival)) {
	case FSE_PROC:
		(yyval.cmd)->cmd = &parser_proc_shutdown;
		break;
	case FSE_FILE:
	case FSE_FILESET:
		(yyval.cmd)->cmd = &parser_fileset_shutdown;
		break;
	default:
		filebench_log(LOG_ERROR, "unknown entity", (yyvsp[(2) - (2)].ival));
		YYERROR;
	}

}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 1173 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_warmup;
	(yyval.cmd)->cmd_qty = (yyvsp[(2) - (2)].ival);
}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 1180 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_warmup_variable;
	(yyval.cmd)->cmd_tgt1 = fb_stralloc((yyvsp[(2) - (2)].sval));
}
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 1188 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_sleep;
	(yyval.cmd)->cmd_qty = (yyvsp[(2) - (2)].ival);
}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 1195 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_sleep_variable;
	(yyval.cmd)->cmd_tgt1 = fb_stralloc((yyvsp[(2) - (2)].sval));
}
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 1203 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_run;
	(yyval.cmd)->cmd_qty = (yyvsp[(2) - (2)].ival);
}
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 1210 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_run_variable;
	(yyval.cmd)->cmd_tgt1 = fb_stralloc((yyvsp[(2) - (2)].sval));
}
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 1217 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_run;
	(yyval.cmd)->cmd_qty = 60UL;
}
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 1225 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_help;
}
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 1232 "parser_gram.y"
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd_name = fb_stralloc((yyvsp[(2) - (2)].sval));
}
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 1238 "parser_gram.y"
    {
	(yyvsp[(1) - (2)].cmd)->cmd_attr_list = (yyvsp[(2) - (2)].attr);
}
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 1243 "parser_gram.y"
    {
	FILE *newfile;
	char loadfile[128];

	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;

	(void) strcpy(loadfile, (yyvsp[(2) - (2)].sval));
	(void) strcat(loadfile, ".f");

	if ((newfile = fopen(loadfile, "r")) == NULL) {
		(void) strcpy(loadfile, fbbasepath);
		(void) strcat(loadfile, "/workloads/");
		(void) strcat(loadfile, (yyvsp[(2) - (2)].sval));
		(void) strcat(loadfile, ".f");
		if ((newfile = fopen(loadfile, "r")) == NULL) {
			filebench_log(LOG_ERROR, "Cannot open %s", loadfile);
			YYERROR;
		}
	}

	parentscript = yyin;
	yyin = newfile;
	yy_switchfileparent(yyin);
}
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 1270 "parser_gram.y"
    {(yyval.ival) = FSE_PROC;}
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 1271 "parser_gram.y"
    {(yyval.ival) = FSE_THREAD;}
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 1272 "parser_gram.y"
    {(yyval.ival) = FSE_FILESET;}
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 1273 "parser_gram.y"
    {(yyval.ival) = FSE_FILE;}
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 1283 "parser_gram.y"
    {
	(yyval.attr) = (yyvsp[(1) - (1)].attr);
}
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 1287 "parser_gram.y"
    {
	attr_t *attr = NULL;
	attr_t *list_end = NULL;

	for (attr = (yyvsp[(1) - (3)].attr); attr != NULL;
	    attr = attr->attr_next)
		list_end = attr; /* Find end of list */

	list_end->attr_next = (yyvsp[(3) - (3)].attr);

	(yyval.attr) = (yyvsp[(1) - (3)].attr);
}
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 1301 "parser_gram.y"
    {
	(yyval.attr) = (yyvsp[(1) - (1)].attr);
}
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 1305 "parser_gram.y"
    {
	attr_t *attr = NULL;
	attr_t *list_end = NULL;

	for (attr = (yyvsp[(1) - (3)].attr); attr != NULL;
	    attr = attr->attr_next)
		list_end = attr; /* Find end of list */

	list_end->attr_next = (yyvsp[(3) - (3)].attr);

	(yyval.attr) = (yyvsp[(1) - (3)].attr);
}
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 1319 "parser_gram.y"
    {
	(yyval.attr) = (yyvsp[(3) - (3)].attr);
	(yyval.attr)->attr_name = (yyvsp[(1) - (3)].ival);
}
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 1324 "parser_gram.y"
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_name = (yyvsp[(1) - (1)].ival);
}
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 1331 "parser_gram.y"
    {
	(yyval.attr) = (yyvsp[(3) - (3)].attr);
	(yyval.attr)->attr_name = (yyvsp[(1) - (3)].ival);
}
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 1336 "parser_gram.y"
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_name = (yyvsp[(1) - (1)].ival);
}
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 1344 "parser_gram.y"
    {
	(yyval.attr) = (yyvsp[(1) - (1)].attr);
}
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 1348 "parser_gram.y"
    {
	attr_t *attr = NULL;
	attr_t *list_end = NULL;

	for (attr = (yyvsp[(1) - (3)].attr); attr != NULL;
	    attr = attr->attr_next)
		list_end = attr; /* Find end of list */

	list_end->attr_next = (yyvsp[(3) - (3)].attr);

	(yyval.attr) = (yyvsp[(1) - (3)].attr);
}
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 1361 "parser_gram.y"
    {
	attr_t *attr = NULL;
	attr_t *list_end = NULL;

	for (attr = (yyvsp[(1) - (7)].attr); attr != NULL;
	    attr = attr->attr_next)
		list_end = attr; /* Find end of list */

	
	if ((attr = alloc_attr()) == NULL)
		YYERROR;

	attr->attr_name = FSA_RANDTABLE;
	attr->attr_obj = (void *)(yyvsp[(6) - (7)].rndtb);
	list_end->attr_next = attr;
	(yyval.attr) = (yyvsp[(1) - (7)].attr);
}
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 1380 "parser_gram.y"
    {
	(yyval.attr) = (yyvsp[(3) - (3)].attr);
	(yyval.attr)->attr_name = (yyvsp[(1) - (3)].ival);
}
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 1385 "parser_gram.y"
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_name = (yyvsp[(1) - (1)].ival);
}
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 1391 "parser_gram.y"
    {
	(yyval.attr) = (yyvsp[(3) - (3)].attr);
	(yyval.attr)->attr_name = FSA_TYPE;
}
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 1396 "parser_gram.y"
    {
	(yyval.attr) = (yyvsp[(3) - (3)].attr);
	(yyval.attr)->attr_name = FSA_RANDSRC;
}
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 1402 "parser_gram.y"
    {
	if (((yyval.rndtb) = alloc_probtabent()) == NULL)
		YYERROR;
	(yyval.rndtb)->pte_percent = (yyvsp[(2) - (7)].avd);
	(yyval.rndtb)->pte_segmin  = (yyvsp[(4) - (7)].avd);
	(yyval.rndtb)->pte_segmax  = (yyvsp[(6) - (7)].avd);
}
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 1412 "parser_gram.y"
    {
	(yyval.rndtb) = (yyvsp[(1) - (1)].rndtb);
}
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 1416 "parser_gram.y"
    {
	probtabent_t *pte = NULL;
	probtabent_t *ptelist_end = NULL;

	for (pte = (yyvsp[(1) - (3)].rndtb); pte != NULL;
	    pte = pte->pte_next)
		ptelist_end = pte; /* Find end of prob table entry list */

	ptelist_end->pte_next = (yyvsp[(3) - (3)].rndtb);

	(yyval.rndtb) = (yyvsp[(1) - (3)].rndtb);
}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 1431 "parser_gram.y"
    {
	(yyval.attr) = (yyvsp[(1) - (1)].attr);
}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 1435 "parser_gram.y"
    {
	attr_t *attr = NULL;
	attr_t *list_end = NULL;

	for (attr = (yyvsp[(1) - (3)].attr); attr != NULL;
	    attr = attr->attr_next)
		list_end = attr; /* Find end of list */

	list_end->attr_next = (yyvsp[(3) - (3)].attr);

	(yyval.attr) = (yyvsp[(1) - (3)].attr);
}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 1449 "parser_gram.y"
    {
	(yyval.attr) = (yyvsp[(3) - (3)].attr);
	(yyval.attr)->attr_name = (yyvsp[(1) - (3)].ival);
}
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 1454 "parser_gram.y"
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_name = (yyvsp[(1) - (1)].ival);
}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 1462 "parser_gram.y"
    {
	(yyval.attr) = (yyvsp[(1) - (1)].attr);
}
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 1466 "parser_gram.y"
    {
	attr_t *attr = NULL;
	attr_t *list_end = NULL;

	for (attr = (yyvsp[(1) - (3)].attr); attr != NULL;
	    attr = attr->attr_next)
		list_end = attr; /* Find end of list */

	list_end->attr_next = (yyvsp[(3) - (3)].attr);

	(yyval.attr) = (yyvsp[(1) - (3)].attr);
}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 1479 "parser_gram.y"
    {
	attr_t *attr = NULL;
	attr_t *list_end = NULL;

	for (attr = (yyvsp[(1) - (3)].attr); attr != NULL;
	    attr = attr->attr_next)
		list_end = attr; /* Find end of list */

	list_end->attr_next = (yyvsp[(3) - (3)].attr);

	(yyval.attr) = (yyvsp[(1) - (3)].attr);
}
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 1493 "parser_gram.y"
    {
	(yyval.attr) = (yyvsp[(3) - (3)].attr);
	(yyval.attr)->attr_name = (yyvsp[(1) - (3)].ival);
}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 1498 "parser_gram.y"
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_name = (yyvsp[(1) - (1)].ival);
}
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 1506 "parser_gram.y"
    {
	(yyval.attr) = (yyvsp[(1) - (1)].attr);
}
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 1510 "parser_gram.y"
    {
	attr_t *attr = NULL;
	attr_t *list_end = NULL;

	for (attr = (yyvsp[(1) - (3)].attr); attr != NULL;
	    attr = attr->attr_next)
		list_end = attr; /* Find end of list */

	list_end->attr_next = (yyvsp[(3) - (3)].attr);

	(yyval.attr) = (yyvsp[(1) - (3)].attr);
}
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 1524 "parser_gram.y"
    {
	(yyval.attr) = (yyvsp[(3) - (3)].attr);
	(yyval.attr)->attr_name = (yyvsp[(1) - (3)].ival);
}
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 1529 "parser_gram.y"
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_name = (yyvsp[(1) - (1)].ival);
}
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 1537 "parser_gram.y"
    {
	(yyval.attr) = (yyvsp[(1) - (1)].attr);
}
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 1541 "parser_gram.y"
    {
	attr_t *attr = NULL;
	attr_t *list_end = NULL;

	for (attr = (yyvsp[(1) - (3)].attr); attr != NULL;
	    attr = attr->attr_next)
		list_end = attr; /* Find end of list */

	list_end->attr_next = (yyvsp[(3) - (3)].attr);

	(yyval.attr) = (yyvsp[(1) - (3)].attr);
}
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 1555 "parser_gram.y"
    {
	(yyval.attr) = (yyvsp[(3) - (3)].attr);
	(yyval.attr)->attr_name = (yyvsp[(1) - (3)].ival);
}
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 1561 "parser_gram.y"
    {
	(yyval.attr) = (yyvsp[(3) - (3)].attr);
	(yyval.attr)->attr_name = FSA_VALUE;
}
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 1567 "parser_gram.y"
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_avd = avd_str_alloc((yyvsp[(3) - (3)].sval));
	(yyval.attr)->attr_name = (yyvsp[(1) - (3)].ival);
}
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 1575 "parser_gram.y"
    {(yyval.ival) = FSK_PLUS;}
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 1576 "parser_gram.y"
    {(yyval.ival) = FSK_MINUS;}
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 1577 "parser_gram.y"
    {(yyval.ival) = FSK_MULTIPLY;}
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 1578 "parser_gram.y"
    {(yyval.ival) = FSK_DIVIDE;}
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 1593 "parser_gram.y"
    { (yyval.ival) = FSA_NICE;}
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 1594 "parser_gram.y"
    { (yyval.ival) = FSA_NAME;}
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 1595 "parser_gram.y"
    { (yyval.ival) = FSA_INSTANCES;}
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 1598 "parser_gram.y"
    { (yyval.ival) = FSA_SIZE;}
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 1599 "parser_gram.y"
    { (yyval.ival) = FSA_NAME;}
    break;

  case 190:

/* Line 1806 of yacc.c  */
#line 1600 "parser_gram.y"
    { (yyval.ival) = FSA_PATH;}
    break;

  case 191:

/* Line 1806 of yacc.c  */
#line 1601 "parser_gram.y"
    { (yyval.ival) = FSA_READONLY;}
    break;

  case 192:

/* Line 1806 of yacc.c  */
#line 1602 "parser_gram.y"
    { (yyval.ival) = FSA_TRUSTTREE;}
    break;

  case 193:

/* Line 1806 of yacc.c  */
#line 1603 "parser_gram.y"
    { (yyval.ival) = FSA_REUSE;}
    break;

  case 194:

/* Line 1806 of yacc.c  */
#line 1605 "parser_gram.y"
    { (yyval.ival) = FSA_DUP;}
    break;

  case 195:

/* Line 1806 of yacc.c  */
#line 1606 "parser_gram.y"
    { (yyval.ival) = FSA_COMP; }
    break;

  case 196:

/* Line 1806 of yacc.c  */
#line 1607 "parser_gram.y"
    { (yyval.ival) = FSA_PAGESIZE; }
    break;

  case 197:

/* Line 1806 of yacc.c  */
#line 1608 "parser_gram.y"
    { (yyval.ival) = FSA_RANDOMSEED; }
    break;

  case 198:

/* Line 1806 of yacc.c  */
#line 1609 "parser_gram.y"
    { (yyval.ival) = FSA_PREALLOC;}
    break;

  case 199:

/* Line 1806 of yacc.c  */
#line 1610 "parser_gram.y"
    { (yyval.ival) = FSA_PARALLOC;}
    break;

  case 200:

/* Line 1806 of yacc.c  */
#line 1611 "parser_gram.y"
    { (yyval.ival) = FSA_WRITEONLY;}
    break;

  case 201:

/* Line 1806 of yacc.c  */
#line 1614 "parser_gram.y"
    { (yyval.ival) = FSA_SIZE;}
    break;

  case 202:

/* Line 1806 of yacc.c  */
#line 1615 "parser_gram.y"
    { (yyval.ival) = FSA_NAME;}
    break;

  case 203:

/* Line 1806 of yacc.c  */
#line 1616 "parser_gram.y"
    { (yyval.ival) = FSA_PATH;}
    break;

  case 204:

/* Line 1806 of yacc.c  */
#line 1617 "parser_gram.y"
    { (yyval.ival) = FSA_DIRWIDTH;}
    break;

  case 205:

/* Line 1806 of yacc.c  */
#line 1618 "parser_gram.y"
    { (yyval.ival) = FSA_DIRDEPTHRV;}
    break;

  case 206:

/* Line 1806 of yacc.c  */
#line 1619 "parser_gram.y"
    { (yyval.ival) = FSA_PREALLOC;}
    break;

  case 207:

/* Line 1806 of yacc.c  */
#line 1620 "parser_gram.y"
    { (yyval.ival) = FSA_PARALLOC;}
    break;

  case 208:

/* Line 1806 of yacc.c  */
#line 1621 "parser_gram.y"
    { (yyval.ival) = FSA_REUSE;}
    break;

  case 209:

/* Line 1806 of yacc.c  */
#line 1622 "parser_gram.y"
    { (yyval.ival) = FSA_DUP;}
    break;

  case 210:

/* Line 1806 of yacc.c  */
#line 1623 "parser_gram.y"
    { (yyval.ival) = FSA_PAGESIZE; }
    break;

  case 211:

/* Line 1806 of yacc.c  */
#line 1624 "parser_gram.y"
    { (yyval.ival) = FSA_COMP;}
    break;

  case 212:

/* Line 1806 of yacc.c  */
#line 1625 "parser_gram.y"
    { (yyval.ival) = FSA_RANDOMSEED;}
    break;

  case 213:

/* Line 1806 of yacc.c  */
#line 1626 "parser_gram.y"
    { (yyval.ival) = FSA_READONLY;}
    break;

  case 214:

/* Line 1806 of yacc.c  */
#line 1627 "parser_gram.y"
    { (yyval.ival) = FSA_TRUSTTREE;}
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 1628 "parser_gram.y"
    { (yyval.ival) = FSA_FILESIZEGAMMA;}
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 1629 "parser_gram.y"
    { (yyval.ival) = FSA_DIRGAMMA;}
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 1630 "parser_gram.y"
    { (yyval.ival) = FSA_CACHED;}
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 1631 "parser_gram.y"
    { (yyval.ival) = FSA_ENTRIES;}
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 1632 "parser_gram.y"
    { (yyval.ival) = FSA_LEAFDIRS;}
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 1633 "parser_gram.y"
    { (yyval.ival) = FSA_WRITEONLY;}
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 1636 "parser_gram.y"
    { (yyval.ival) = FSA_NAME;}
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 1637 "parser_gram.y"
    { (yyval.ival) = FSA_TYPE;}
    break;

  case 223:

/* Line 1806 of yacc.c  */
#line 1638 "parser_gram.y"
    { (yyval.ival) = FSA_RANDSEED;}
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 1639 "parser_gram.y"
    { (yyval.ival) = FSA_ENTRIES;}
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 1640 "parser_gram.y"
    { (yyval.ival) = FSA_RANDMAX;}
    break;

  case 226:

/* Line 1806 of yacc.c  */
#line 1643 "parser_gram.y"
    { (yyval.ival) = FSA_NAME;}
    break;

  case 227:

/* Line 1806 of yacc.c  */
#line 1644 "parser_gram.y"
    { (yyval.ival) = FSA_RANDSEED;}
    break;

  case 228:

/* Line 1806 of yacc.c  */
#line 1645 "parser_gram.y"
    { (yyval.ival) = FSA_RANDGAMMA;}
    break;

  case 229:

/* Line 1806 of yacc.c  */
#line 1646 "parser_gram.y"
    { (yyval.ival) = FSA_RANDMEAN;}
    break;

  case 230:

/* Line 1806 of yacc.c  */
#line 1647 "parser_gram.y"
    { (yyval.ival) = FSA_RANDMIN;}
    break;

  case 231:

/* Line 1806 of yacc.c  */
#line 1648 "parser_gram.y"
    { (yyval.ival) = FSA_RANDROUND;}
    break;

  case 232:

/* Line 1806 of yacc.c  */
#line 1651 "parser_gram.y"
    { (yyval.ival) = FSS_TYPE;}
    break;

  case 233:

/* Line 1806 of yacc.c  */
#line 1652 "parser_gram.y"
    { (yyval.ival) = FSS_SRC;}
    break;

  case 234:

/* Line 1806 of yacc.c  */
#line 1653 "parser_gram.y"
    { (yyval.ival) = FSS_SEED;}
    break;

  case 235:

/* Line 1806 of yacc.c  */
#line 1654 "parser_gram.y"
    { (yyval.ival) = FSS_GAMMA;}
    break;

  case 236:

/* Line 1806 of yacc.c  */
#line 1655 "parser_gram.y"
    { (yyval.ival) = FSS_MEAN;}
    break;

  case 237:

/* Line 1806 of yacc.c  */
#line 1656 "parser_gram.y"
    { (yyval.ival) = FSS_MIN;}
    break;

  case 238:

/* Line 1806 of yacc.c  */
#line 1657 "parser_gram.y"
    { (yyval.ival) = FSS_ROUND;}
    break;

  case 239:

/* Line 1806 of yacc.c  */
#line 1660 "parser_gram.y"
    { (yyval.ival) = FSS_SEED;}
    break;

  case 240:

/* Line 1806 of yacc.c  */
#line 1661 "parser_gram.y"
    { (yyval.ival) = FSS_GAMMA;}
    break;

  case 241:

/* Line 1806 of yacc.c  */
#line 1662 "parser_gram.y"
    { (yyval.ival) = FSS_MEAN;}
    break;

  case 242:

/* Line 1806 of yacc.c  */
#line 1663 "parser_gram.y"
    { (yyval.ival) = FSS_MIN;}
    break;

  case 243:

/* Line 1806 of yacc.c  */
#line 1664 "parser_gram.y"
    { (yyval.ival) = FSS_ROUND;}
    break;

  case 244:

/* Line 1806 of yacc.c  */
#line 1667 "parser_gram.y"
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_avd = avd_int_alloc((yyvsp[(1) - (1)].ival));
}
    break;

  case 245:

/* Line 1806 of yacc.c  */
#line 1674 "parser_gram.y"
    { (yyval.ival) = FSV_RANDUNI;}
    break;

  case 246:

/* Line 1806 of yacc.c  */
#line 1675 "parser_gram.y"
    { (yyval.ival) = FSV_RANDTAB;}
    break;

  case 247:

/* Line 1806 of yacc.c  */
#line 1676 "parser_gram.y"
    { (yyval.ival) = FSA_RANDGAMMA;}
    break;

  case 248:

/* Line 1806 of yacc.c  */
#line 1679 "parser_gram.y"
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_avd = avd_int_alloc((yyvsp[(1) - (1)].ival));
}
    break;

  case 249:

/* Line 1806 of yacc.c  */
#line 1686 "parser_gram.y"
    { (yyval.ival) = FSV_URAND;}
    break;

  case 250:

/* Line 1806 of yacc.c  */
#line 1687 "parser_gram.y"
    { (yyval.ival) = FSV_RAND48;}
    break;

  case 251:

/* Line 1806 of yacc.c  */
#line 1690 "parser_gram.y"
    { (yyval.ival) = FSA_PROCESS;}
    break;

  case 252:

/* Line 1806 of yacc.c  */
#line 1691 "parser_gram.y"
    { (yyval.ival) = FSA_NAME;}
    break;

  case 253:

/* Line 1806 of yacc.c  */
#line 1692 "parser_gram.y"
    { (yyval.ival) = FSA_MEMSIZE;}
    break;

  case 254:

/* Line 1806 of yacc.c  */
#line 1693 "parser_gram.y"
    { (yyval.ival) = FSA_USEISM;}
    break;

  case 255:

/* Line 1806 of yacc.c  */
#line 1694 "parser_gram.y"
    { (yyval.ival) = FSA_INSTANCES;}
    break;

  case 256:

/* Line 1806 of yacc.c  */
#line 1695 "parser_gram.y"
    { (yyval.ival) = FSA_IOPRIO;}
    break;

  case 257:

/* Line 1806 of yacc.c  */
#line 1698 "parser_gram.y"
    { (yyval.ival) = FSA_WSS;}
    break;

  case 258:

/* Line 1806 of yacc.c  */
#line 1699 "parser_gram.y"
    { (yyval.ival) = FSA_FILE;}
    break;

  case 259:

/* Line 1806 of yacc.c  */
#line 1700 "parser_gram.y"
    { (yyval.ival) = FSA_POSSET;}
    break;

  case 260:

/* Line 1806 of yacc.c  */
#line 1701 "parser_gram.y"
    { (yyval.ival) = FSA_NAME;}
    break;

  case 261:

/* Line 1806 of yacc.c  */
#line 1702 "parser_gram.y"
    { (yyval.ival) = FSA_RANDOM;}
    break;

  case 262:

/* Line 1806 of yacc.c  */
#line 1703 "parser_gram.y"
    { (yyval.ival) = FSA_FD;}
    break;

  case 263:

/* Line 1806 of yacc.c  */
#line 1704 "parser_gram.y"
    { (yyval.ival) = FSA_SRCFD;}
    break;

  case 264:

/* Line 1806 of yacc.c  */
#line 1705 "parser_gram.y"
    { (yyval.ival) = FSA_ROTATEFD;}
    break;

  case 265:

/* Line 1806 of yacc.c  */
#line 1706 "parser_gram.y"
    { (yyval.ival) = FSA_DSYNC;}
    break;

  case 266:

/* Line 1806 of yacc.c  */
#line 1707 "parser_gram.y"
    { (yyval.ival) = FSA_DIRECTIO;}
    break;

  case 267:

/* Line 1806 of yacc.c  */
#line 1708 "parser_gram.y"
    { (yyval.ival) = FSA_INDEXED;}
    break;

  case 268:

/* Line 1806 of yacc.c  */
#line 1709 "parser_gram.y"
    { (yyval.ival) = FSA_TARGET;}
    break;

  case 269:

/* Line 1806 of yacc.c  */
#line 1710 "parser_gram.y"
    { (yyval.ival) = FSA_ITERS;}
    break;

  case 270:

/* Line 1806 of yacc.c  */
#line 1711 "parser_gram.y"
    { (yyval.ival) = FSA_VALUE;}
    break;

  case 271:

/* Line 1806 of yacc.c  */
#line 1712 "parser_gram.y"
    { (yyval.ival) = FSA_BLOCKING;}
    break;

  case 272:

/* Line 1806 of yacc.c  */
#line 1713 "parser_gram.y"
    { (yyval.ival) = FSA_HIGHWATER;}
    break;

  case 273:

/* Line 1806 of yacc.c  */
#line 1714 "parser_gram.y"
    { (yyval.ival) = FSA_IOSIZE;}
    break;

  case 274:

/* Line 1806 of yacc.c  */
#line 1715 "parser_gram.y"
    { (yyval.ival) = FSA_NOREADAHEAD;}
    break;

  case 275:

/* Line 1806 of yacc.c  */
#line 1718 "parser_gram.y"
    { (yyval.ival) = FSA_RATE;}
    break;

  case 276:

/* Line 1806 of yacc.c  */
#line 1721 "parser_gram.y"
    { (yyval.ival) = FSA_MASTER;}
    break;

  case 277:

/* Line 1806 of yacc.c  */
#line 1722 "parser_gram.y"
    { (yyval.ival) = FSA_CLIENT;}
    break;

  case 278:

/* Line 1806 of yacc.c  */
#line 1725 "parser_gram.y"
    { (yyval.ival) = FSA_PATH;}
    break;

  case 279:

/* Line 1806 of yacc.c  */
#line 1726 "parser_gram.y"
    { (yyval.ival) = FSA_FSTYPE;}
    break;

  case 280:

/* Line 1806 of yacc.c  */
#line 1729 "parser_gram.y"
    {
	(yyval.attr) = (yyvsp[(1) - (1)].attr);
}
    break;

  case 281:

/* Line 1806 of yacc.c  */
#line 1733 "parser_gram.y"
    {
	attr_t *attr = NULL;
	attr_t *list_end = NULL;

	for (attr = (yyvsp[(1) - (3)].attr); attr != NULL;
	    attr = attr->attr_next)
		list_end = attr; /* Find end of list */

	list_end->attr_next = (yyvsp[(3) - (3)].attr);

	(yyval.attr) = (yyvsp[(1) - (3)].attr);
}
    break;

  case 282:

/* Line 1806 of yacc.c  */
#line 1746 "parser_gram.y"
    {
	attr_t *attr = NULL;
	attr_t *list_end = NULL;

	for (attr = (yyvsp[(1) - (3)].attr); attr != NULL;
	    attr = attr->attr_next)
		list_end = attr; /* Find end of list */

	list_end->attr_next = (yyvsp[(3) - (3)].attr);

	(yyval.attr) = (yyvsp[(1) - (3)].attr);
}
    break;

  case 283:

/* Line 1806 of yacc.c  */
#line 1760 "parser_gram.y"
    {
	(yyval.attr) = (yyvsp[(3) - (3)].attr);
	(yyval.attr)->attr_name = (yyvsp[(1) - (3)].ival);
}
    break;

  case 284:

/* Line 1806 of yacc.c  */
#line 1766 "parser_gram.y"
    {
	if (((yyval.attr) = alloc_lvar_attr(var_lvar_assign_boolean((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].bval)))) == NULL)
		YYERROR;
}
    break;

  case 285:

/* Line 1806 of yacc.c  */
#line 1771 "parser_gram.y"
    {
	if (((yyval.attr) = alloc_lvar_attr(var_lvar_assign_integer((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].ival)))) == NULL)
		YYERROR;
}
    break;

  case 286:

/* Line 1806 of yacc.c  */
#line 1776 "parser_gram.y"
    {
	if (((yyval.attr) = alloc_lvar_attr(var_lvar_assign_string((yyvsp[(1) - (5)].sval), (yyvsp[(4) - (5)].sval)))) == NULL)
		YYERROR;
}
    break;

  case 287:

/* Line 1806 of yacc.c  */
#line 1781 "parser_gram.y"
    {
	if (((yyval.attr) = alloc_lvar_attr(var_lvar_assign_string((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval)))) == NULL)
		YYERROR;
}
    break;

  case 288:

/* Line 1806 of yacc.c  */
#line 1786 "parser_gram.y"
    {
	if (((yyval.attr) = alloc_lvar_attr(var_lvar_assign_var((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval)))) == NULL)
		YYERROR;
}
    break;

  case 289:

/* Line 1806 of yacc.c  */
#line 1791 "parser_gram.y"
    {
	if (((yyval.attr) = alloc_lvar_attr(var_lvar_alloc_local((yyvsp[(1) - (1)].sval)))) == NULL)
		YYERROR;
}
    break;

  case 290:

/* Line 1806 of yacc.c  */
#line 1798 "parser_gram.y"
    { (yyval.ival) = FSA_NAME;}
    break;

  case 291:

/* Line 1806 of yacc.c  */
#line 1799 "parser_gram.y"
    { (yyval.ival) = FSA_ITERS;}
    break;

  case 292:

/* Line 1806 of yacc.c  */
#line 1802 "parser_gram.y"
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_avd = avd_str_alloc((yyvsp[(1) - (1)].sval));
}
    break;

  case 293:

/* Line 1806 of yacc.c  */
#line 1806 "parser_gram.y"
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_avd = avd_int_alloc((yyvsp[(1) - (1)].ival));
}
    break;

  case 294:

/* Line 1806 of yacc.c  */
#line 1810 "parser_gram.y"
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_avd = avd_bool_alloc((yyvsp[(1) - (1)].bval));
}
    break;

  case 295:

/* Line 1806 of yacc.c  */
#line 1814 "parser_gram.y"
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_avd = var_ref_attr((yyvsp[(1) - (1)].sval));
}
    break;

  case 296:

/* Line 1806 of yacc.c  */
#line 1820 "parser_gram.y"
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_param_list = (yyvsp[(1) - (1)].list);
}
    break;

  case 297:

/* Line 1806 of yacc.c  */
#line 1824 "parser_gram.y"
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_avd = avd_str_alloc((yyvsp[(1) - (1)].sval));
}
    break;

  case 298:

/* Line 1806 of yacc.c  */
#line 1828 "parser_gram.y"
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_avd = avd_int_alloc((yyvsp[(1) - (1)].ival));
}
    break;

  case 299:

/* Line 1806 of yacc.c  */
#line 1832 "parser_gram.y"
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_avd = avd_bool_alloc((yyvsp[(1) - (1)].bval));
}
    break;

  case 300:

/* Line 1806 of yacc.c  */
#line 1836 "parser_gram.y"
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_avd = var_ref_attr((yyvsp[(1) - (1)].sval));
}
    break;

  case 301:

/* Line 1806 of yacc.c  */
#line 1843 "parser_gram.y"
    {
	(yyval.avd) = avd_int_alloc((yyvsp[(1) - (1)].ival));
}
    break;

  case 302:

/* Line 1806 of yacc.c  */
#line 1846 "parser_gram.y"
    {
	(yyval.avd) = var_ref_attr((yyvsp[(1) - (1)].sval));
}
    break;



/* Line 1806 of yacc.c  */
#line 5100 "parser_gram.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 1850 "parser_gram.y"


/*
 * The following C routines implement the various commands defined in the above
 * yacc parser code. The yacc portion checks the syntax of the commands found in
 * a workload file (or typed interactively) and parses the commands' parameters
 * into lists. The lists are then passed in a cmd_t struct for each command to
 * its related routine in the following section for actual execution.  This
 * section also includes a few utility routines and the main entry point for the
 * program.
 */

#define	USAGE1	\
"Usage:\n" \
"filebench: interprets WML script and generates apporpriate workload\n" \
"Options:\n" \
"   [-h] Display verbose help\n" \
"   [-f <filename>] use specified file as an input instead of stdin\n"

#define	PARSER_CMDS \
"create [files|filesets|processes]\n" \
"stats [clear|snap]\n" \
"stats command \"shell command $var1,$var2...\"\n" \
"stats directory <directory>\n" \
"sleep <sleep-value>\n" \
"quit\n\n" \
"Variables:\n" \
"set $var = value\n" \
"    $var   - regular variables\n" \
"    ${var} - internal special variables\n" \
"    $(var) - environment variables\n\n"

#define	PARSER_EXAMPLE \
"Example:\n\n" \
"#!" FILEBENCHDIR "/bin/filebench -f\n" \
"\n" \
"define file name=bigfile,path=bigfile,size=1g,prealloc,reuse\n" \
"define process name=randomizer\n" \
"{\n" \
"  thread random-thread procname=randomizer\n"	\
"  {\n" \
"    flowop read name=random-read,filename=bigfile,iosize=16k,random\n" \
"  }\n" \
"}\n" \
"create files\n" \
"create processes\n" \
"stats clear\n" \
"sleep 30\n" \
"stats snap\n"

/*
 * Displays brief or verbose help for Filebench.
 */
static void
usage(int help)
{
	if (help >= 1)
		(void) fprintf(stderr, USAGE1);

	if (help >= 2) {
		(void) fprintf(stderr,
		    "\n'f' language definition:\n\n");
		fileset_usage();
		procflow_usage();
		threadflow_usage();
		flowoplib_usage();
		eventgen_usage();
		(void) fprintf(stderr, PARSER_CMDS);
		(void) fprintf(stderr, PARSER_EXAMPLE);
	}

	exit(1);
}

/*
 * mmap() call with MAP_FIXED argument does not guarantee
 * that the allocated memory region is not overlapped with
 * the previously existant mappings. According to POSIX, old mappings
 * are just disregarded. There is no generic way to detect
 * overlap. If overlap occurs strange runtime errors might happen,
 * because we might overlap stack, libraries, anything else.
 *
 * Since we always fork+exec same binary (filebench), theoretically
 * all the mappings should be the same, so no overlap should happen.
 * However, if virtual address space randomization is enabled on the target
 * machine - overlap is very likely (especially if workload defines a lot of
 * processes).  We observed numerous segmentation faults on CentOS because of
 * that.
 *
 * The function below checks if virtual address space randomization is
 * enabled on Linux. In case it is enabled, we print a warning and continue
 * execution.
 */
static void
check_va_randomization()
{
	char buf[4];
	int val;
	int ret;
	int fd;

	fd = open("/proc/sys/kernel/randomize_va_space", O_RDONLY);
	if (fd == -1) {
		/*
		 * probably this file just doesn't exist, so we conclude that the
		 * system does not support virtual address space randomization
		 * and silently return.
		 */
		return;
	}

	ret = read(fd, buf, sizeof(buf));
	if (ret == -1) {
		filebench_log(LOG_FATAL, "Coud not read from "
			"/proc/sys/kernel/randomize_va_space file!");
		return;
	}

	sscanf(buf, "%d", &val);
	if (val != 0) {
		filebench_log(LOG_FATAL, "IMPORTANT: Virtual address space "
			"randomization is enabled on this machine!\n"
			"It is highly recommended to disable randomization "
			"to provide stable Filebench runs.\n"
			"Echo 0 to /proc/sys/kernel/randomize_va_space file "
			"to disable the randomization.");

	}
}

#ifdef HAVE_PROC_SYS_KERNEL_SHMMAX
/*
 * Increase the maximum shared memory segment size till some large value.  We do
 * not restore it to the old value when the Filebench run is over. If we could
 * not change the value - we continue execution.
 */
void
fb_set_shmmax(void)
{
	FILE *f;
	int ret;

	f = fopen("/proc/sys/kernel/shmmax", "r+");
	if (!f) {
		filebench_log(LOG_FATAL, "WARNING: Could not open "
				"/proc/sys/kernel/shmmax file!\n"
				"It means that you probably ran Filebench not "
				"as a root. Filebench will not increase shared\n"
				"region limits in this case, which can lead "
				"to the failures on certain workloads.");
		return; 
	}

	/* writing new value */
#define SOME_LARGE_SHMAX "268435456" /* 256 MB */
	ret = fwrite(SOME_LARGE_SHMAX, sizeof(SOME_LARGE_SHMAX), 1, f);
	if (ret != 1) 
		filebench_log(LOG_ERROR, "Coud not write to "
				"/proc/sys/kernel/shmmax file!");
#undef SOME_LARGE_SHMAX

	return;
}
#else /* HAVE_PROC_SYS_KERNEL_SHMMAX */
void
fb_set_shmmax(void)
{
	return;
}
#endif /* HAVE_PROC_SYS_KERNEL_SHMMAX */

#ifdef HAVE_SETRLIMIT
/*
 * Increase the limit of opened files.
 *
 * We first set the limit to the hardlimit reported by the kernel; this call
 * will always succeed.  Then we try to set the limit to some large number of
 * files (unfortunately we can't set this ulimit to infinity), this will only
 * succeed if the process is ran by root.  Therefore, we always set the maximum
 * possible value for the limit for this given process (well, only if hardlimit
 * is greater then the large number of files defined by us, it is not true).
 *
 * Increasing this limit is especially important when we use thread model,
 * because opened files are accounted per-process, not per-thread.
 */
void
fb_set_rlimit(void)
{
	struct rlimit rlp;

	(void)getrlimit(RLIMIT_NOFILE, &rlp);
	rlp.rlim_cur = rlp.rlim_max;
	(void)setrlimit(RLIMIT_NOFILE, &rlp);
#define SOME_LARGE_NUMBER_OF_FILES 50000
	rlp.rlim_cur = rlp.rlim_max = SOME_LARGE_NUMBER_OF_FILES;
#undef SOME_LARGE_NUMBER_OF_FILES
	(void)setrlimit(RLIMIT_NOFILE, &rlp);
	return;
}
#else /* HAVE_SETRLIMIT */
void
fb_set_rlimit(void)
{
	return;
}
#endif /* HAVE_SETRLIMIT */

/*
 * Entry point for Filebench. Processes command line arguments. The -f option
 * will read in a workload file (the full name and extension must must be
 * given). The -a, -s, -m and -i options are used by the worker process to
 * receive the name, the base address of shared memory, its path, and the
 * process' instance number, respectively. This information is supplied by the
 * master process when it execs worker processes. If the worker process
 * arguments are passed then main will call the procflow_exec() routine which
 * creates worker threadflows and flowops and executes the procflow's portion of
 * the workload model until completion. If worker process arguments are not
 * passed to the process, then it becomes the master process for a filebench
 * run. It initializes the various filebench components and either executes the
 * supplied workload file, or enters interactive mode.
 */
int
main(int argc, char *argv[])
{
	const char cmd_options[] = "m:s:a:i:hf:";
	int opt;
	char *procname = NULL;
	int instance;
        int myrandom=1;
        static int urandomfd=0;
	void *shmaddr;
	char *cwdret;
	char *fscriptname = NULL;
#ifdef HAVE_LIBTECLA
	char *line;
#else /* HAVE_LIBTECLA */
	char line[1024];
#endif

	 /* parsing the parameters */
	while ((opt = getopt(argc, argv, cmd_options)) > 0) {
		switch (opt) {
		/* public parameters */
		case 'h':
			usage(2);
			break;
		case 'f':
			if (!optarg)
				usage(1);

			yyin = fopen(optarg, "r");
			if (!yyin) {
				filebench_log(LOG_FATAL,
				    "Cannot open file %s!", optarg);
				exit(1);
			}

			dofile = DOFILE_TRUE;
			fscriptname = optarg;
			break;
		/* private parameters: when filebench calls itself */
		case 'a':
			if (!optarg)
				usage(1);

			procname = optarg;
			break;
		case 's':
			if (!optarg)
				usage(1);
			sscanf(optarg, "%p", &shmaddr);
			break;
		case 'm':
			if (!optarg)
				usage(1);
			sscanf(optarg, "%s", shmpath);
			break;
		case 'i':
			if (!optarg)
				usage(1);
			sscanf(optarg, "%d", &instance);
			break;
		case '?':
		default:
			usage(1);
			break;
		}
	}

        /* Before init, you may wish to set random variable    
         */

        urandomfd = open("/random_seed", O_RDONLY);
        if (urandomfd < 0) {
                filebench_log(LOG_ERROR, "open /random_seed failed: (please make a file on root '/' named random_seed and put your random seed there %s \n Default randomseed being Used \n",
                    strerror(errno));
                
                myrandom=10007;
        }
        else
        {
            opt=read(urandomfd,&myrandom,sizeof(myrandom));
        }

	/*
	 * Init things common to all processes: master and workers
	 */
	my_pid = getpid();
        fb_set_rlimit();
	fb_urandom_init(myrandom);
	clock_init();

	if (procname) {
		/* A child Filebench instance */
		if (ipc_attach(shmaddr) < 0) {
			filebench_log(LOG_FATAL, "Cannot attach shm for %s",
			    procname);
			exit(1);
		}

		/* get correct function pointer for each working process */
		filebench_plugin_funcvecinit();

		/* execute corresponding procflow */
		if (procflow_exec(procname, instance) < 0) {
			filebench_log(LOG_FATAL, "Cannot startup process %s",
			    procname);
			exit(1);
		}

		exit(0);
	}

	/*
	 * Master process
	 */
	printf("Filebench Version %s\n", FILEBENCH_VERSION);
	check_va_randomization();

	/* saving executable name to exec it later as worker processes */
	execname = argv[0];

	/* saving current working directory */
	cwdret = getcwd(cwd, MAXPATHLEN);
	if (cwdret != cwd) {
		filebench_log(LOG_FATAL, "Cannot save current "
					 "working directory!");
		exit(1);
	}

	fb_set_shmmax();

	ipc_init();

	if (fscriptname)
		(void)strcpy(filebench_shm->shm_fscriptname, fscriptname);

	flowop_init();
	stats_init();
	eventgen_init();

	signal(SIGINT, parser_abort);

	if (dofile == DOFILE_TRUE)
		yyparse();
	else {
#ifdef HAVE_LIBTECLA
		if ((gl = new_GetLine(MAX_LINE_LEN, MAX_CMD_HIST)) == NULL) {
			filebench_log(LOG_ERROR,
			    "Failed to create GetLine object");
			filebench_shutdown(1);
		}

		if (gl_customize_completion(gl, NULL, command_complete)) {
			filebench_log(LOG_ERROR,
			    "Failed to register auto-completion function");
			filebench_shutdown(1);
		}

		while ((line = gl_get_line(gl, FILEBENCH_PROMPT, NULL, -1))) {
			arg_parse(line);
			yyparse();
		}

		del_GetLine(gl);
#else
		while (!feof(stdin)) {
			printf(FILEBENCH_PROMPT);
			fflush(stdout);
			if (fgets(line, sizeof (line), stdin) == NULL) {
				if (errno == EINTR)
					continue;
				else
					break;
			}
			arg_parse(line);
			yyparse();
		}
		printf("\n");
#endif	/* HAVE_LIBTECLA */
	}

	parser_filebench_shutdown((cmd_t *)0);

	return 0;
}

/*
 * arg_parse() puts the parser into command parsing mode. Create a tmpfile
 * and instruct the parser to read instructions from this location by setting
 * yyin to the value returned by tmpfile. Write the command into the file.
 * Then seek back to to the start of the file so that the parser can read
 * the instructions.
 */
static void
arg_parse(const char *command)
{
	if ((yyin = tmpfile()) == NULL) {
		filebench_log(LOG_FATAL,
		    "Exiting: Cannot create tmpfile: %s", strerror(errno));
		exit(1);
	}

	if (fwrite(command, strlen(command), 1, yyin) != 1)
		filebench_log(LOG_FATAL,
		    "Cannot write tmpfile: %s", strerror(errno));

	if (fseek(yyin, 0, SEEK_SET) != 0)
		filebench_log(LOG_FATAL,
		    "Cannot seek tmpfile: %s", strerror(errno));
}

/*
 * Converts a list of var_strings or ordinary strings to a single ordinary
 * string. It returns a pointer to the string (in malloc'd memory) if found,
 * or NULL otherwise.
 */
char *
parser_list2string(list_t *list)
{
	list_t *l;
	char *string;
	char *tmp;
	if ((string = malloc(MAXPATHLEN)) == NULL) {
		filebench_log(LOG_ERROR, "Failed to allocate memory");
		return (NULL);
	}

	*string = 0;

	/*	printf("parser_list2string: called\n"); */
	/* Format args */
	for (l = list; l != NULL; l = l->list_next) {
		char *lstr = avd_get_str(l->list_string);

		filebench_log(LOG_DEBUG_SCRIPT,
		    "converting string '%s'", lstr);

		/* see if it is a random variable */
		if (l->list_integer) {
			fbint_t param_name;

			tmp = NULL;
			param_name = avd_get_int(l->list_integer);
			switch (param_name) {
			case FSS_TYPE:
				tmp = var_randvar_to_string(lstr,
				    RAND_PARAM_TYPE);
				break;

			case FSS_SRC:
				tmp = var_randvar_to_string(lstr,
				    RAND_PARAM_SRC);
				break;

			case FSS_SEED:
				tmp = var_randvar_to_string(lstr,
				    RAND_PARAM_SEED);
				break;

			case FSS_MIN:
				tmp = var_randvar_to_string(lstr,
				    RAND_PARAM_MIN);
				break;

			case FSS_MEAN:
				tmp = var_randvar_to_string(lstr,
				    RAND_PARAM_MEAN);
				break;

			case FSS_GAMMA:
				tmp = var_randvar_to_string(lstr,
				    RAND_PARAM_GAMMA);
				break;

			case FSS_ROUND:
				tmp = var_randvar_to_string(lstr,
				    RAND_PARAM_ROUND);
				break;
			}

			if (tmp) {
				(void) strcat(string, tmp);
				free(tmp);
			} else {
				(void) strcat(string, lstr);
			}
		} else {
			/* perhaps a normal variable? */
			if ((tmp = var_to_string(lstr)) != NULL) {
				(void) strcat(string, tmp);
				free(tmp);
			} else {
				(void) strcat(string, lstr);
			}
		}
	}
	return (string);
}

/*
 * If the list just contains a single string starting with '$', then find
 * or create the named var and return the var's var_string component.
 * Otherwise, convert the list to a string, and allocate a var_string
 * containing a copy of that string. On failure either returns NULL
 * or shuts down the run.
 */
avd_t
parser_list2varstring(list_t *list)
{
	char *lstr = avd_get_str(list->list_string);

	/*	printf("parser_list2varstring: Called\n"); */
	/* Special case - variable name */
	if ((list->list_next == NULL) && (*lstr == '$'))
		return (var_ref_attr(lstr));

	return (avd_str_alloc(parser_list2string(list)));
}

/*
 * Looks for the var named in list_string of the first element of the
 * supplied list. If found, returns the var_val portion of the var in
 * an attribute value descriptor. If the var is not found, cannot be
 * allocated, the supplied list is NULL, or the list_string filed is
 * empty, returns NULL.
 */
avd_t
parser_list2avd(list_t *list)
{
	avd_t avd;
	char *lstr;

	if (list && ((lstr = avd_get_str(list->list_string)) != NULL)) {
		avd = var_ref_attr(lstr);
		return (avd);
	}

	return (NULL);
}

/*
 * Sets the event generator rate from the attribute supplied with the
 * command. If the attribute doesn't exist the routine does nothing.
 */
static void
parser_eventgen(cmd_t *cmd)
{
	attr_t *attr;

	/* Get the rate from attribute */
	if ((attr = get_attr_integer(cmd, FSA_RATE))) {
		if (attr->attr_avd) {
			eventgen_setrate(attr->attr_avd);
		}
	}
}

/*
 * Assigns the designated integer variable successive values from the
 * supplied comma seperated integer list. After each successive integer
 * assignment, it executes the bracket enclosed list of commands. For
 * example, repeated runs of a workload with increasing io sizes can
 * be done using the following command line:
 * 	foreach $iosize in 2k, 4k, 8k {run 60}
 */
static void
parser_foreach_integer(cmd_t *cmd)
{
	list_t *list = cmd->cmd_param_list;
	cmd_t *inner_cmd;

	for (; list != NULL; list = list->list_next) {
		fbint_t list_int = avd_get_int(list->list_integer);

		var_assign_integer(cmd->cmd_tgt1, list_int);
		filebench_log(LOG_VERBOSE, "Iterating %s=%llu",
		    cmd->cmd_tgt1, (u_longlong_t)list_int);
		for (inner_cmd = cmd->cmd_list; inner_cmd != NULL;
		    inner_cmd = inner_cmd->cmd_next) {
			inner_cmd->cmd(inner_cmd);
		}
	}
}

/*
 * Similar to parser_foreach_integer(), except takes a list of strings after
 * the "in" token. For example, to run twice using a different directory,
 * perhaps using a different filesystem, the following command line
 * could be used:
 * 	foreach $dir in "/ufs_top/fbt", "/zfs_top/fbt" {run 60)
 */
static void
parser_foreach_string(cmd_t *cmd)
{
	list_t *list = cmd->cmd_param_list;

	for (; list != NULL; list = list->list_next) {
		cmd_t *inner_cmd;
		char *lstr = avd_get_str(list->list_string);
		var_assign_string(cmd->cmd_tgt1, lstr);
		filebench_log(LOG_VERBOSE, "Iterating %s=%s",
		    cmd->cmd_tgt1, lstr);
		for (inner_cmd = cmd->cmd_list; inner_cmd != NULL;
		    inner_cmd = inner_cmd->cmd_next) {
			inner_cmd->cmd(inner_cmd);
		}
	}
}

/*
 * Lists the fileset name, path name and average size for all defined
 * filesets.
 */
static void
parser_list(cmd_t *cmd)
{
	(void) fileset_iter(fileset_print);
}

/*
 * Lists the flowop name and instance number for all flowops.
 */
static void
parser_flowop_list(cmd_t *cmd)
{
	flowop_printall();
}

/*
 * Calls procflow_define() to allocate "instances" number of  procflow(s)
 * (processes) with the supplied name. The default number of instances is
 * one. An optional priority level attribute can be supplied and is stored in
 * pf_nice. Finally the routine loops through the list of inner commands, if
 * any, which are defines for threadflows, and passes them one at a time to
 * parser_thread_define() to allocate threadflow entities for the process(es).
 */
static void
parser_proc_define(cmd_t *cmd)
{
	procflow_t *procflow;
	char *name = NULL;
	attr_t *attr;
	avd_t var_instances;
	fbint_t instances;
	cmd_t *inner_cmd;

	/* Get the name of the process */
	if ((attr = get_attr(cmd, FSA_NAME))) {
		name = avd_get_str(attr->attr_avd);
	} else {
		filebench_log(LOG_ERROR,
		    "define proc: proc specifies no name");
		filebench_shutdown(1);
	}

	/* Get the memory size from attribute */
	if ((attr = get_attr_integer(cmd, FSA_INSTANCES))) {
		if (AVD_IS_RANDOM(attr->attr_avd)) {
			filebench_log(LOG_ERROR,
			    "proc_define: Instances attr cannot be random");
			filebench_shutdown(1);
		}
		var_instances = attr->attr_avd;
		instances = avd_get_int(var_instances);
		filebench_log(LOG_DEBUG_IMPL,
		    "Setting instances = %llu", (u_longlong_t)instances);
	} else {
		filebench_log(LOG_DEBUG_IMPL,
		    "Defaulting to instances = 1");
		var_instances = avd_int_alloc(1);
		instances = 1;
	}

	if ((procflow = procflow_define(name, NULL, var_instances)) == NULL) {
		filebench_log(LOG_ERROR,
		    "Failed to instantiate %d %s process(es)\n",
		    instances, name);
		filebench_shutdown(1);
	}

	/* Get the pri from attribute */
	if ((attr = get_attr_integer(cmd, FSA_NICE))) {
		if (AVD_IS_RANDOM(attr->attr_avd)) {
			filebench_log(LOG_ERROR,
			    "proc_define: priority cannot be random");
			filebench_shutdown(1);
		}
		filebench_log(LOG_DEBUG_IMPL, "Setting pri = %llu",
		    (u_longlong_t)avd_get_int(attr->attr_avd));
		procflow->pf_nice = attr->attr_avd;
	} else
		procflow->pf_nice = avd_int_alloc(0);


	/* Create the list of threads for this process  */
	for (inner_cmd = cmd->cmd_list; inner_cmd != NULL;
	    inner_cmd = inner_cmd->cmd_next) {
		parser_thread_define(inner_cmd, procflow, instances);
	}
}

/*
 * Calls threadflow_define() to allocate "instances" number of  threadflow(s)
 * (threads) with the supplied name. The default number of instances is
 * one. Two other optional attributes may be supplied, one to set the memory
 * size, stored in tf_memsize, and to select the use of Interprocess Shared
 * Memory, which sets the THREADFLOW_USEISM flag in tf_attrs. Finally
 * the routine loops through the list of inner commands, if any, which are
 * defines for flowops, and passes them one at a time to
 * parser_flowop_define() to allocate flowop entities for the threadflows.
 */
static void
parser_thread_define(cmd_t *cmd, procflow_t *procflow, int procinstances)
{
	threadflow_t *threadflow, template;
	attr_t *attr;
	avd_t instances;
	cmd_t *inner_cmd;
	char *name = NULL;

	memset(&template, 0, sizeof (threadflow_t));

	/* Get the name of the thread */
	if ((attr = get_attr(cmd, FSA_NAME))) {
		name = avd_get_str(attr->attr_avd);
	} else {
		filebench_log(LOG_ERROR,
		    "define thread: thread in process %s specifies no name",
		    procflow->pf_name);
		filebench_shutdown(1);
	}

	/* Get the number of instances from attribute */
	if ((attr = get_attr_integer(cmd, FSA_INSTANCES))) {
		if (AVD_IS_RANDOM(attr->attr_avd)) {
			filebench_log(LOG_ERROR,
			    "define thread: Instances attr cannot be random");
			filebench_shutdown(1);
		}
		filebench_log(LOG_DEBUG_IMPL,
		    "define thread: Setting instances = %llu",
		    (u_longlong_t)avd_get_int(attr->attr_avd));
		instances = attr->attr_avd;
	} else
		instances = avd_int_alloc(1);

	/* Get the memory size from attribute */
	if ((attr = get_attr_integer(cmd, FSA_MEMSIZE))) {
		if (AVD_IS_RANDOM(attr->attr_avd)) {
			filebench_log(LOG_ERROR,
			    "define thread: Memory size cannot be random");
			filebench_shutdown(1);
		}
		filebench_log(LOG_DEBUG_IMPL,
		    "define thread: Setting memsize = %llu",
		    (u_longlong_t)avd_get_int(attr->attr_avd));
		template.tf_memsize = attr->attr_avd;
	} else
		template.tf_memsize = avd_int_alloc(0);

	/* Get ioprio parameters from attribute */
	if ((attr = get_attr_integer(cmd, FSA_IOPRIO))) {
		if (AVD_IS_RANDOM(attr->attr_avd)) {
			filebench_log(LOG_ERROR,
			    "define thread: ioprio cannot be random");
			filebench_shutdown(1);
		}
		filebench_log(LOG_DEBUG_IMPL,
		    "define thread: Setting ioprio = %llu",
		    (u_longlong_t)avd_get_int(attr->attr_avd));
		template.tf_ioprio = attr->attr_avd;
	} else
		template.tf_ioprio = avd_int_alloc(8);

	if ((threadflow = threadflow_define(procflow, name,
	    &template, instances)) == NULL) {
		filebench_log(LOG_ERROR,
		    "define thread: Failed to instantiate thread\n");
		filebench_shutdown(1);
	}

	/* Use ISM Memory? */
	if ((attr = get_attr(cmd, FSA_USEISM))) {
		threadflow->tf_attrs |= THREADFLOW_USEISM;
	}

	/* Create the list of flowops */
	for (inner_cmd = cmd->cmd_list; inner_cmd != NULL;
	    inner_cmd = inner_cmd->cmd_next) {
		parser_flowop_define(inner_cmd, threadflow,
		    &threadflow->tf_thrd_fops, FLOW_MASTER);
	}
}

/*
 * Fills in the attributes for a newly allocated flowop
 */
static void
parser_flowop_get_attrs(cmd_t *cmd, flowop_t *flowop)
{
	attr_t *attr;

	/* Get the filename from attribute */
	if ((attr = get_attr(cmd, FSA_FILE))) {
		flowop->fo_filename = attr->attr_avd;
		if (flowop->fo_filename == NULL) {
			filebench_log(LOG_ERROR,
			    "define flowop: no filename specfied");
			filebench_shutdown(1);
		}
	} else {
		/* no filename attribute specified */
		flowop->fo_filename = NULL;
	}

	/* Get the possetname from attribute */
	if ((attr = get_attr(cmd, FSA_POSSET))) {
		flowop->fo_possetname = attr->attr_avd;
		if (flowop->fo_possetname == NULL) {
			filebench_log(LOG_ERROR,
			    "parser_flowop_get_attrs: no "
				"posset name specfied");
			filebench_shutdown(1);
		}
	} else {
		/* no possetname attribute specified */
		flowop->fo_possetname = NULL;
	}

	/* Get the iosize of the op */
	if ((attr = get_attr_integer(cmd, FSA_IOSIZE)))
		flowop->fo_iosize = attr->attr_avd;
	else
		flowop->fo_iosize = avd_int_alloc(0);

	/* Get the working set size of the op */
	if ((attr = get_attr_integer(cmd, FSA_WSS)))
		flowop->fo_wss = attr->attr_avd;
	else
		flowop->fo_wss = avd_int_alloc(0);

	/* Random I/O? */
	if ((attr = get_attr_bool(cmd, FSA_RANDOM)))
		flowop->fo_random = attr->attr_avd;
	else
		flowop->fo_random = avd_bool_alloc(FALSE);

	/* Sync I/O? */
	if ((attr = get_attr_bool(cmd, FSA_DSYNC)))
		flowop->fo_dsync = attr->attr_avd;
	else
		flowop->fo_dsync = avd_bool_alloc(FALSE);

	/* Target, for wakeup etc */
	if ((attr = get_attr(cmd, FSA_TARGET)))
		(void) strcpy(flowop->fo_targetname,
		    avd_get_str(attr->attr_avd));

	/* Value */
	if ((attr = get_attr_integer(cmd, FSA_VALUE)))
		flowop->fo_value = attr->attr_avd;
	else
		flowop->fo_value = avd_int_alloc(0);

	/* FD */
	if ((attr = get_attr_integer(cmd, FSA_FD))) {
		flowop->fo_fdnumber = avd_get_int(attr->attr_avd);
		if (flowop->fo_filename != NULL)
			filebench_log(LOG_DEBUG_SCRIPT, "It is not "
			    "advisable to supply both an fd number "
			    "and a fileset name in most cases");
	}

	/* Rotatefd? */
	if ((attr = get_attr_bool(cmd, FSA_ROTATEFD)))
		flowop->fo_rotatefd = attr->attr_avd;
	else
		flowop->fo_rotatefd = avd_bool_alloc(FALSE);

	/* SRC FD, for copies etc... */
	if ((attr = get_attr_integer(cmd, FSA_SRCFD)))
		flowop->fo_srcfdnumber = avd_get_int(attr->attr_avd);

	/* Blocking operation? */
	if ((attr = get_attr_bool(cmd, FSA_BLOCKING)))
		flowop->fo_blocking = attr->attr_avd;
	else
		flowop->fo_blocking = avd_bool_alloc(FALSE);

	/* Direct I/O Operation */
	if ((attr = get_attr_bool(cmd, FSA_DIRECTIO)))
		flowop->fo_directio = attr->attr_avd;
	else
		flowop->fo_directio = avd_bool_alloc(FALSE);

	/* Highwater mark */
	if ((attr = get_attr_integer(cmd, FSA_HIGHWATER))) {
		flowop->fo_highwater = attr->attr_avd;
		if (AVD_IS_RANDOM(attr->attr_avd)) {
			filebench_log(LOG_ERROR,
			    "define flowop: Highwater attr cannot be random");
			filebench_shutdown(1);
		}
	} else {
		flowop->fo_highwater = avd_int_alloc(1);
	}

	/* find file or leaf directory by index number */
	if ((attr = get_attr_integer(cmd, FSA_INDEXED)))
		flowop->fo_fileindex = attr->attr_avd;
	else
		flowop->fo_fileindex = NULL;

	/* Read Ahead Diable */
	if ((attr = get_attr_bool(cmd, FSA_NOREADAHEAD)))
		flowop->fo_noreadahead = attr->attr_avd;
	else
		flowop->fo_noreadahead = avd_bool_alloc(FALSE);


}

/*
 * defines the FLOW_MASTER flowops within a FLOW_MASTER instance of
 * a composit flowop. Default attributes from the FLOW_INNER_DEF instances
 * of the composit flowop's inner flowops are used if set. Otherwise
 * default attributes from the FLOW_MASTER instance of the composit flowop
 * are used, which may include defaults from the original FLOW_DEFINITION
 * of the composit flowop.
 */
static void
parser_inner_flowop_define(threadflow_t *thread, flowop_t *comp0_flow,
			   flowop_t *comp_mstr_flow)
{
	flowop_t *inner_flowtype, *inner_flowop;

	/* follow flowop list, creating composit names */
	inner_flowtype = comp0_flow->fo_comp_fops;
	comp_mstr_flow->fo_comp_fops = NULL;

	while (inner_flowtype) {
		char fullname[MAXPATHLEN];

		/* create composite_name.name for new flowop */
		snprintf(fullname, MAXPATHLEN, "%s.%s",
		    comp_mstr_flow->fo_name, inner_flowtype->fo_name);

		if ((inner_flowop = flowop_define(thread, fullname,
		    inner_flowtype, &comp_mstr_flow->fo_comp_fops,
		    FLOW_MASTER, 0)) == NULL) {
			filebench_log(LOG_ERROR,
			    "define flowop: Failed to instantiate flowop %s\n",
			    fullname);
			filebench_shutdown(1);
		}

		/* if applicable, update filename attribute */
		if (inner_flowop->fo_filename) {
			char *name;

			/* fix up avd_t */
			avd_update(&inner_flowop->fo_filename,
			    comp_mstr_flow->fo_lvar_list);

			/* see if ready to get the file or fileset */
			name = avd_get_str(inner_flowop->fo_filename);
			if (name) {

				inner_flowop->fo_fileset = fileset_find(name);

				if (inner_flowop->fo_fileset == NULL) {
					filebench_log(LOG_ERROR,
					    "inr flowop %s: file %s not found",
					    inner_flowop->fo_name, name);
					filebench_shutdown(1);
				}
			}
		}

		/* update attributes from local variables */
		avd_update(&inner_flowop->fo_iters,
		    comp_mstr_flow->fo_lvar_list);

		/* if the inner flowop is a composit flowop, recurse */
		if (inner_flowtype->fo_type == FLOW_TYPE_COMPOSITE) {
			var_t *newlvar, *proto_lvars, *lvar_ptr;

			proto_lvars = inner_flowop->fo_lvar_list;
			inner_flowop->fo_lvar_list = 0;

			for (lvar_ptr = inner_flowtype->fo_lvar_list; lvar_ptr;
			    lvar_ptr = lvar_ptr->var_next) {

				if ((newlvar = var_lvar_alloc_local(
				    lvar_ptr->var_name)) != NULL) {

					add_lvar_to_list(newlvar,
					    &inner_flowop->fo_lvar_list);

					var_update_comp_lvars(newlvar,
					    proto_lvars,
					    comp_mstr_flow->fo_lvar_list);
				}
			}
		  
			parser_inner_flowop_define(thread,
			    inner_flowtype,
			    inner_flowop);

			inner_flowtype = inner_flowtype->fo_exec_next;
			continue;
		}

		avd_update(&inner_flowop->fo_iosize,
		    comp_mstr_flow->fo_lvar_list);
		avd_update(&inner_flowop->fo_wss,
		    comp_mstr_flow->fo_lvar_list);
		avd_update(&inner_flowop->fo_iters,
		    comp_mstr_flow->fo_lvar_list);
		avd_update(&inner_flowop->fo_value,
		    comp_mstr_flow->fo_lvar_list);
		avd_update(&inner_flowop->fo_random,
		    comp_mstr_flow->fo_lvar_list);
		avd_update(&inner_flowop->fo_dsync,
		    comp_mstr_flow->fo_lvar_list);
		avd_update(&inner_flowop->fo_rotatefd,
		    comp_mstr_flow->fo_lvar_list);
		avd_update(&inner_flowop->fo_blocking,
		    comp_mstr_flow->fo_lvar_list);
		avd_update(&inner_flowop->fo_directio,
		    comp_mstr_flow->fo_lvar_list);
		avd_update(&inner_flowop->fo_highwater,
		    comp_mstr_flow->fo_lvar_list);

		inner_flowtype = inner_flowtype->fo_exec_next;
	}
}

/*
 * Calls flowop_define() to allocate a flowop with the supplied name.
 * The allocated flowop inherits attributes from a base flowop of the
 * same type.  If the new flowop has a file or fileset attribute specified,
 * it must specify a defined fileobj or fileset or an error will be logged.
 * The new flowop may  also have the following attributes set by
 * the program:
 *  - file size (fo_iosize)
 *  - working set size (fo_wss)
 *  - do random io (fo_random)
 *  - do synchronous io (fo_dsync)
 *  - perform each operation multiple times before advancing (fo_iter)
 *  - target name (fo_targetname)
 *  - An integer value (fo_value)
 *  - a file descriptor (fo_fd)
 *  - specify to rotate file descriptors (fo_rotatefd)
 *  - a source fd (fo_srcfdnumber)
 *  - specify a blocking operation (fo_blocking)
 *  - specify a highwater mark (fo_highwater)
 *
 * After all the supplied attributes are stored in their respective locations
 * in the flowop object, the flowop's init function is called. No errors are
 * returned, but the filebench run will be terminated if the flowtype is not
 * specified, a name for the new flowop is not supplied, the flowop_define
 * call fails, or a file or fileset name is supplied but the corresponding
 * fileobj or fileset cannot be located.
 */
static void
parser_flowop_define(cmd_t *cmd, threadflow_t *thread,
    flowop_t **flowoplist_hdp, int category)
{
	flowop_t *flowop, *flowop_type;
	char *type = (char *)cmd->cmd_name;
	char *name = NULL;
	attr_t *attr;

	/* Get the inherited flowop */
	flowop_type = flowop_find(type);
	if (flowop_type == NULL) {
		filebench_log(LOG_ERROR,
		    "define flowop: flowop type %s not found",
		    type);
		filebench_shutdown(1);
	}

	/* Get the name of the flowop */
	if ((attr = get_attr(cmd, FSA_NAME))) {
		name = avd_get_str(attr->attr_avd);
	} else {
		filebench_log(LOG_ERROR,
		    "define flowop: flowop %s specifies no name",
		    flowop_type->fo_name);
		filebench_shutdown(1);
	}

	if ((flowop = flowop_define(thread, name,
	    flowop_type, flowoplist_hdp, category, 0)) == NULL) {
		filebench_log(LOG_ERROR,
		    "define flowop: Failed to instantiate flowop %s\n",
		    cmd->cmd_name);
		filebench_shutdown(1);
	}

	/* Iterations */
	if ((attr = get_attr_integer(cmd, FSA_ITERS)))
		flowop->fo_iters = attr->attr_avd;
	else
		flowop->fo_iters = avd_int_alloc(1);


	/* if this is a use of a composit flowop, create inner FLOW MASTERS */
	if (flowop_type->fo_type == FLOW_TYPE_COMPOSITE) {
		get_attr_lvars(cmd, flowop);
		if (category == FLOW_MASTER)
			parser_inner_flowop_define(thread,
			    flowop_type, flowop);
	}
	else {
		parser_flowop_get_attrs(cmd, flowop);
	}
}

static void
parser_composite_flowop_define(cmd_t *cmd)
{
	flowop_t *flowop;
	cmd_t *inner_cmd;
	char *name = NULL;
	attr_t *attr;

	/* Get the name of the flowop */
	if ((attr = get_attr(cmd, FSA_NAME))) {
		name = avd_get_str(attr->attr_avd);
	} else {
		filebench_log(LOG_ERROR,
		    "define flowop: Composit flowop specifies no name");

		filebench_shutdown(1);
	}

	if ((flowop = flowop_new_composite_define(name)) == NULL) {
		filebench_log(LOG_ERROR,
		    "define flowop: Failed to instantiate flowop %s\n",
		    cmd->cmd_name);
		filebench_shutdown(1);
	}

	/* place any local var_t variables on the flowop's local list */
	get_attr_lvars(cmd, flowop);

	/* Iterations */
	if ((attr = get_attr_integer(cmd, FSA_ITERS)))
		flowop->fo_iters = attr->attr_avd;
	else
		flowop->fo_iters = avd_int_alloc(1);

	/* define inner flowops */
	for (inner_cmd = cmd->cmd_list; inner_cmd != NULL;
	    inner_cmd = inner_cmd->cmd_next) {
		parser_flowop_define(inner_cmd, NULL,
		    &flowop->fo_comp_fops, FLOW_INNER_DEF);
	}
}


/*
 * Calls fileset_define() to allocate a fileset with the supplied name and
 * initializes the fileset's pathname attribute, and optionally the
 * fileset_cached, fileset_reuse, fileset_prealloc and fileset_size attributes.
 *
 */
static fileset_t *
parser_fileset_define_common(cmd_t *cmd)
{
	fileset_t *fileset;
	avd_t name;
	attr_t *attr;
	avd_t pathname;

	/*
	 * Make sure all plugin flowops are initialized.
	 * Defaults to local fs for now
	 */
	flowop_plugin_flowinit();

	/* Get the name of the file */
	if ((attr = get_attr_fileset(cmd, FSA_NAME))) {
		name = attr->attr_avd;
	} else {
		filebench_log(LOG_ERROR,
		    "define fileset: file or fileset specifies no name");
		return (NULL);
	}

	if ((fileset = fileset_define(name)) == NULL) {
		filebench_log(LOG_ERROR,
		    "define file: failed to instantiate file %s\n",
		    avd_get_str(name));
		return (NULL);
	}

	/* Get the pathname from attribute */
	if ((attr = get_attr(cmd, FSA_PATH)) == NULL) {
		filebench_log(LOG_ERROR, "define file: no pathname specified");
		return (NULL);
	}

	/* Expand variables in pathname */
	if ((pathname = parser_list2varstring(attr->attr_param_list))
	    == NULL) {
		filebench_log(LOG_ERROR, "Cannot interpret path");
		return (NULL);
	}

	fileset->fs_path = pathname;

	/* How much should we preallocate? */
	if ((attr = get_attr_integer(cmd, FSA_PREALLOC)) &&
	    attr->attr_avd) {
		if (AVD_IS_RANDOM(attr->attr_avd)) {
			filebench_log(LOG_ERROR,
			    "define fileset: Prealloc attr cannot be random");
			filebench_shutdown(1);
		}
		fileset->fs_preallocpercent = attr->attr_avd;
	} else if (attr && !attr->attr_avd) {
		fileset->fs_preallocpercent = avd_int_alloc(100);
	} else {
		fileset->fs_preallocpercent = avd_int_alloc(0);
	}

	/* Should we preallocate? */
	if ((attr = get_attr_bool(cmd, FSA_PREALLOC)))
		fileset->fs_prealloc = attr->attr_avd;
	else
		fileset->fs_prealloc = avd_bool_alloc(FALSE);

	/* Should DEDUP? */
	if ((attr = get_attr_bool(cmd, FSA_DUP)))
        {
	        fileset->fs_dup = avd_get_int(attr->attr_avd);
                //printf(" XLR (xlr) : Dup value %d\n",fileset->fs_dup);
        }
        else
	        fileset->fs_dup=0;

	/* Should COMPRESS? */
	if ((attr = get_attr_bool(cmd, FSA_COMP)))
        {
	        fileset->fs_comp = avd_get_int(attr->attr_avd);
                //printf(" XLR (xlr) : Dup value %d\n",fileset->fs_dup);
        }
        else
	        fileset->fs_comp=0;

        /* Pagesize given ? */
	if ((attr = get_attr_bool(cmd, FSA_PAGESIZE)))
        {
	        fileset->fs_pagesize = avd_get_int(attr->attr_avd);
                //printf(" XLR (xlr) : Dup value %d\n",fileset->fs_dup);
        }
        else
	        fileset->fs_pagesize=4096;
    
        
        /* if random seed is given */
	if ((attr = get_attr_bool(cmd, FSA_RANDOMSEED)))
        {
                //randomseed=avd_get_int(attr->attr_avd);
                //srand(avd_get_int(attr->attr_avd));
                //printf(" XLR (xlr) random variable is set now %d \n", (avd_get_int(attr->attr_avd)));
        }
        else
        {
                //srand(10007);
            
        }
        
        
	/* Should we prealloc in parallel? */
	if ((attr = get_attr_bool(cmd, FSA_PARALLOC)))
		fileset->fs_paralloc = attr->attr_avd;
	else
		fileset->fs_paralloc = avd_bool_alloc(FALSE);

	/* Should we allow writes to the file? */
	if ((attr = get_attr_bool(cmd, FSA_READONLY)))
		fileset->fs_readonly = attr->attr_avd;
	else
		fileset->fs_readonly = avd_bool_alloc(FALSE);

	if ((attr = get_attr_bool(cmd, FSA_WRITEONLY)))
		fileset->fs_writeonly = attr->attr_avd;
	else
		fileset->fs_writeonly = avd_bool_alloc(FALSE);

	if ((avd_get_bool(fileset->fs_readonly) == TRUE) &&
		(avd_get_bool(fileset->fs_writeonly) == TRUE)) {
		filebench_log(LOG_ERROR, "fileset can't be read-only and "
					"write-only at the same time!");
		return NULL;
	}

	/* Should we reuse the existing file? */
	if ((attr = get_attr_bool(cmd, FSA_REUSE)))
		fileset->fs_reuse = attr->attr_avd;
	else
		fileset->fs_reuse = avd_bool_alloc(FALSE);

	/* Should we check for files actual existance? */
	if ((attr = get_attr_bool(cmd, FSA_TRUSTTREE)))
		fileset->fs_trust_tree = attr->attr_avd;
	else
		fileset->fs_trust_tree = avd_bool_alloc(FALSE);

	/* Should we leave in cache? */
	if ((attr = get_attr_bool(cmd, FSA_CACHED)))
		fileset->fs_cached = attr->attr_avd;
	else
		fileset->fs_cached = avd_bool_alloc(FALSE);

	/* Get the mean or absolute size of the file */
	if ((attr = get_attr_integer(cmd, FSA_SIZE)))
		fileset->fs_size = attr->attr_avd;
	else
		fileset->fs_size = avd_int_alloc(0);

	return (fileset);
}

/*
 * Calls parser_fileset_define_common() to allocate a fileset with
 * one entry and optionally the fileset_prealloc. sets the fileset_entries,
 * fileset_dirwidth, fileset_dirgamma, and fileset_sizegamma attributes
 * to appropriate values for emulating the old "fileobj" entity
 */
static void
parser_file_define(cmd_t *cmd)
{
	fileset_t *fileset;

	if ((fileset = parser_fileset_define_common(cmd)) == NULL) {
		filebench_log(LOG_ERROR,
		    "define file: failed to instantiate file");
		filebench_shutdown(1);
		return;
	}

	/* fileset is emulating a single file */
	fileset->fs_attrs = FILESET_IS_FILE;

	/* Set the size of the fileset to 1 */
	fileset->fs_entries = avd_int_alloc(1);

	/* Set the mean dir width to more than 1 */
	fileset->fs_dirwidth = avd_int_alloc(10);

	/* Set the dir and size gammas to 0 */
	fileset->fs_dirgamma = avd_int_alloc(0);
	fileset->fs_sizegamma = avd_int_alloc(0);
}

/*
 * Calls parser_fileset_define_common() to allocate a fileset with the
 * supplied name and initializes the fileset's fileset_preallocpercent,
 * fileset_prealloc, fileset_entries, fileset_dirwidth, fileset_dirgamma,
 * and fileset_sizegamma attributes.
 */
static void
parser_fileset_define(cmd_t *cmd)
{
	fileset_t *fileset;
	attr_t *attr;

	if ((fileset = parser_fileset_define_common(cmd)) == NULL) {
		filebench_log(LOG_ERROR,
		    "define fileset: failed to instantiate fileset");
		filebench_shutdown(1);
		return;
	}
	/* Get the number of files in the fileset */
	if ((attr = get_attr_integer(cmd, FSA_ENTRIES))) {
		fileset->fs_entries = attr->attr_avd;
	} else {
		fileset->fs_entries = avd_int_alloc(0);
	}

	/* Get the number of leafdirs in the fileset */
	if ((attr = get_attr_integer(cmd, FSA_LEAFDIRS))) {
		fileset->fs_leafdirs = attr->attr_avd;
	} else {
		fileset->fs_leafdirs = avd_int_alloc(0);
	}

	if ((avd_get_int(fileset->fs_entries) == 0) &&
	    (avd_get_int(fileset->fs_leafdirs) == 0)) {
		filebench_log(LOG_ERROR, "Fileset has no files or leafdirs");
	}

	/* Get the mean dir width of the fileset */
	if ((attr = get_attr_integer(cmd, FSA_DIRWIDTH))) {
		fileset->fs_dirwidth = attr->attr_avd;
	} else {
		filebench_log(LOG_ERROR, "Fileset has zero directory width");
		fileset->fs_dirwidth = avd_int_alloc(0);
	}

	/* Get the random variable for dir depth, if supplied */
	if ((attr = get_attr_integer(cmd, FSA_DIRDEPTHRV))) {
		if (!AVD_IS_RANDOM(attr->attr_avd)) {
			filebench_log(LOG_ERROR,
			    "Define fileset: dirdepthrv must be random var");
			filebench_shutdown(1);
		}
		fileset->fs_dirdepthrv = attr->attr_avd;
	} else {
		fileset->fs_dirdepthrv = NULL;
	}

	/* Get the gamma value for dir depth distributions */
	if ((attr = get_attr_integer(cmd, FSA_DIRGAMMA))) {
		if (AVD_IS_RANDOM(attr->attr_avd)) {
			filebench_log(LOG_ERROR,
			    "Define fileset: dirgamma attr cannot be random");
			filebench_shutdown(1);
		}
		fileset->fs_dirgamma = attr->attr_avd;
	} else
		fileset->fs_dirgamma = avd_int_alloc(1500);

	/* Get the gamma value for dir width distributions */
	if ((attr = get_attr_integer(cmd, FSA_FILESIZEGAMMA))) {
		if (AVD_IS_RANDOM(attr->attr_avd)) {
			filebench_log(LOG_ERROR,
			    "Define fileset: filesizegamma cannot be random");
			filebench_shutdown(1);
		}
		fileset->fs_sizegamma = attr->attr_avd;
	} else
		fileset->fs_sizegamma = avd_int_alloc(1500);
}

static void
parser_posset_define(cmd_t *cmd)
{
	attr_t *attr;
	avd_t name;
	avd_t type;
	avd_t seed;
	avd_t max;
	avd_t entries;
	int i;

	struct posset *ps;
	
	if ((attr = get_attr(cmd, FSA_NAME))) {
		name = attr->attr_avd;
	} else {
		filebench_log(LOG_ERROR,
		   "parser_posset_define: no name specified for the posset");
		filebench_shutdown(1);
		return;
	}

	if ((attr = get_attr(cmd, FSA_TYPE))) {
		type = attr->attr_avd;
	} else {
		filebench_log(LOG_ERROR,
		   "parser_posset_define: no type specified for the posset");
		filebench_shutdown(1);
		return;
	}

	if ((attr = get_attr_integer(cmd, FSA_ENTRIES))) {
		entries = attr->attr_avd;
	} else {
		filebench_log(LOG_ERROR,
		   "parser_posset_define: no entries number "
					"specified for the posset");
		filebench_shutdown(1);
		return;
	}

	/*
	 * two attributes below are mandatory only for specific types
	 * of possets, so postpone their validation for posset type
	 * specific functions.
	 */
	if ((attr = get_attr_integer(cmd, FSA_RANDSEED)))
		seed = attr->attr_avd;
	else
		seed = avd_int_alloc(0);

	if ((attr = get_attr_integer(cmd, FSA_RANDMAX)))
		max = attr->attr_avd;
	else
		max = avd_int_alloc(0);

	filebench_log(LOG_INFO,"Defining position set: %s type: %s",
				 avd_get_str(name), avd_get_str(type));

	ps = posset_alloc(name, type, seed, max, entries);
	if (!ps) {
		filebench_log(LOG_ERROR, "Cannot define fileset");
		filebench_shutdown(1);
		/* NOT REACHABLE */
		return;
	}

	/* printing all positions */
	for (i = 0; i < avd_get_int(ps->ps_entries); i++)
		filebench_log(LOG_INFO,"pos %d: %llu", i, ps->ps_positions[i]);

}

/*
 * Creates and starts all defined procflow processes. The call to
 * procflow_init() results in creation of the requested number of
 * process instances for each previously defined procflow. The
 * child processes exec() a new instance of filebench, passing it
 * the instance number and address of the shared memory region.
 * The child processes will then create their threads and flowops.
 * The routine then unlocks the run_lock to allow all the processes'
 * threads to start and  waits for all of them to begin execution.
 * Finally, it records the start time and resets the event generation
 * system.
 */
static void
parser_proc_create(cmd_t *cmd)
{
	filebench_shm->shm_1st_err = 0;
	filebench_shm->shm_f_abort = FILEBENCH_OK;

	if (procflow_init() != 0) {
		filebench_log(LOG_ERROR, "Failed to create processes\n");
		filebench_shutdown(1);
	}

	/* Wait for all threads to start */
	if (procflow_allstarted() != 0) {
		filebench_log(LOG_ERROR, "Could not start run");
		return;
	}

	/* Release the read lock, allowing threads to start */
	(void) pthread_rwlock_unlock(&filebench_shm->shm_run_lock);

	if (filebench_shm->shm_required &&
	    (ipc_ismcreate(filebench_shm->shm_required) < 0)) {
		filebench_log(LOG_ERROR, "Could not allocate shared memory");
		return;
	}

	filebench_shm->shm_starttime = gethrtime();
	eventgen_reset();
}

/*
 * Calls fileset_createset() to populate all files and filesets and
 * create all associated, initially existant,  files and subdirectories.
 * If errors are encountered, calls filebench_shutdown()
 * to exit filebench.
 */
static void
parser_fileset_create(cmd_t *cmd)
{
	if (!filecreate_done) {
		filecreate_done = 1;

		/* initialize the random number system first */
		randdist_init();

		/* create all the filesets */
		if (fileset_createset(NULL) != 0) {
			filebench_log(LOG_ERROR, "Failed to create filesets");
			filebench_shutdown(1);
		}
	} else {
		filebench_log(LOG_INFO,
		    "Attempting to create fileset more than once, ignoring");
	}

}

/*
 * Deletes the files and directories that represent files and filesets on the
 * storage medium.
 */
static void
parser_fileset_shutdown(cmd_t *cmd)
{
	filebench_log(LOG_INFO, "Shutting down filesets");
	fileset_delete_all_filesets();
}

/*
 * Shuts down all processes and their associated threads. When finished
 * it deletes interprocess shared memory and resets the event generator.
 * It does not exit the filebench program though.
 */
static void
parser_proc_shutdown(cmd_t *cmd)
{
	filebench_log(LOG_INFO, "Shutting down processes");
	filecreate_done = 0;
	procflow_shutdown();
	if (filebench_shm->shm_required)
		ipc_ismdelete();
	eventgen_reset();
}

/*
 * Ends filebench run after first destoring any interprocess
 * shared memory. The call to filebench_shutdown()
 * also causes filebench to exit.
 */
static void
parser_filebench_shutdown(cmd_t *cmd)
{
	int f_abort = filebench_shm->shm_f_abort;

	ipc_fini();

	if (f_abort == FILEBENCH_ABORT_ERROR)
		filebench_shutdown(1);
	else
		filebench_shutdown(0);
}

/*
 * This is Used for timing runs.Pauses the master thread in one second
 * intervals until the supplied ptime runs out or the f_abort flag
 * is raised. If given a time of zero or less, or the mode is stop on
 * lack of resources, it will pause until f_abort is raised.
 */
static int
parser_pause(int ptime)
{
	int timeslept = 0;

	if ((filebench_shm->shm_rmode == FILEBENCH_MODE_TIMEOUT) &&
	    (ptime > 0)) {
		while (timeslept < ptime) {
			(void) sleep(1);
			timeslept++;
			if (filebench_shm->shm_f_abort)
				break;
		}
	} else {
		/* initial runtime of 0 means run till abort */
		/* CONSTCOND */
		while (1) {
			(void) sleep(1);
			timeslept++;
			if (filebench_shm->shm_f_abort)
				break;
		}
	}
	return (timeslept);
}

/*
 * Do a file bench run. Calls routines to create file sets, files, and
 * processes. It resets the statistics counters, then sleeps for the runtime
 * passed as an argument to it on the command line in 1 second increments.
 * When it is finished sleeping, it collects a snapshot of the statistics
 * and ends the run.
 */
static void
parser_run(cmd_t *cmd)
{
	int runtime;
	int timeslept;

	runtime = cmd->cmd_qty;

	parser_fileset_create(cmd);
	parser_proc_create(cmd);

	/* check for startup errors */
	if (filebench_shm->shm_f_abort)
		return;

	filebench_log(LOG_INFO, "Running...");
	stats_clear();

	timeslept = parser_pause(runtime);

	filebench_log(LOG_INFO, "Run took %d seconds...", timeslept);
	parser_statssnap(cmd);
	parser_proc_shutdown(cmd);
	parser_filebench_shutdown((cmd_t *)0);
}

/*
 * Similar to parser_run, but gets the sleep time from a variable
 * whose name is supplied as an argument to the command.
 */
static void
parser_run_variable(cmd_t *cmd)
{
	avd_t integer = var_ref_attr(cmd->cmd_tgt1);
	int runtime;
	int timeslept;

	if (integer == NULL) {
		filebench_log(LOG_ERROR, "Unknown variable %s",
		cmd->cmd_tgt1);
		return;
	}

	runtime = avd_get_int(integer);

	/* check for startup errors */
	if (filebench_shm->shm_f_abort)
		return;

	filebench_log(LOG_INFO, "Running...");
	stats_clear();

	timeslept = parser_pause(runtime);

	filebench_log(LOG_INFO, "Run took %d seconds...", timeslept);
	parser_statssnap(cmd);
	parser_proc_shutdown(cmd);
}

char *usagestr = NULL;

/*
 * Prints usage string if defined, else just a message requesting load of a
 * personality.
 */
static void
parser_help(cmd_t *cmd)
{
	if (usagestr) {
		filebench_log(LOG_INFO, "%s", usagestr);
	} else {
		filebench_log(LOG_INFO,
		    "load <personality> (ls "
		    "%s/workloads for list)", fbbasepath);
	}
}

char *varstr = NULL;

/*
 * Prints the string of all var definitions, if there is one.
 */
static void
parser_printvars(cmd_t *cmd)
{
	char *str, *c;

	if (varstr) {
		str = strdup(varstr);
		for (c = str; *c != '\0'; c++) {
			if ((char)*c == '$')
				*c = ' ';
		}
		filebench_log(LOG_INFO, "%s", str);
		free(str);
	}
}

/*
 * Establishes multi-client synchronization socket with synch server.
 */
static void
parser_enable_mc(cmd_t *cmd)
{
	attr_t *attr;
	char *master;
	char *client;

	if ((attr= get_attr(cmd, FSA_MASTER))) {
		master = avd_get_str(attr->attr_avd);
	} else {
		filebench_log(LOG_ERROR,
		    "enable multi: no master specified");
		return;
	}

	if ((attr= get_attr(cmd, FSA_CLIENT))) {
		client = avd_get_str(attr->attr_avd);
	} else {
		filebench_log(LOG_ERROR,
		    "enable multi: no client specified");
		return;
	}

	mc_sync_open_sock(master, 8001, client);
}

/*
 * Exchanges multi-client synchronization message with synch server.
 */
static void
parser_domultisync(cmd_t *cmd)
{
	attr_t *attr;
	fbint_t value;

	if ((attr = get_attr(cmd, FSA_VALUE)))
		value = avd_get_int(attr->attr_avd);
	else
		value = 1;

	mc_sync_synchronize((int)value);
}

/*
 * Used by the SET command to add a var and default value string to the
 * varstr string. It allocates a new, larger varstr string, copies the
 * old contents of varstr into it, then adds the new var string on the end.
 */
static void
parser_vars(cmd_t *cmd)
{
	char *string = cmd->cmd_tgt1;
	char *newvars;

	if (string == NULL)
		return;

	if (dofile == DOFILE_TRUE)
		return;

	if (varstr == NULL) {
		newvars = malloc(strlen(string) + 2);
		*newvars = 0;
	} else {
		newvars = malloc(strlen(varstr) + strlen(string) + 2);
		(void) strcpy(newvars, varstr);
	}
	(void) strcat(newvars, string);
	(void) strcat(newvars, " ");

	if (varstr)
		free(varstr);

	varstr = newvars;
}

/*
 * used by the set command to set the integer part of a regular
 * variable, or the appropriate field of a random variable
 */
static void
parser_set_integer(cmd_t *cmd)
{
	var_assign_integer(cmd->cmd_tgt1, cmd->cmd_qty);
}

/*
 * used by the set command to set the integer part of a regular
 * variable from another variable, or the appropriate field of a
 * random variable from another variable
 */
static void
parser_set_var(cmd_t *cmd)
{
	var_assign_var(cmd->cmd_tgt1, cmd->cmd_tgt2);
}

/*
 * Used by the set command to set up for a binary operation of a
 * variable from a var, with an integer
 */
static void
parser_set_var_op_int(cmd_t *cmd)
{
	printf("parser_set_var_op_int: Called\n");
	switch (cmd->cmd_subtype) {
	case FSK_PLUS:
		var_assign_op_var_int(cmd->cmd_tgt1, VAR_IND_INT_SUM_IV,
		    cmd->cmd_tgt2, cmd->cmd_qty);
		break;

	case FSK_MINUS:
		var_assign_op_var_int(cmd->cmd_tgt1, VAR_IND_IV_DIF_INT,
		    cmd->cmd_tgt2, cmd->cmd_qty);
		break;

	case FSK_MULTIPLY:
		var_assign_op_var_int(cmd->cmd_tgt1, VAR_IND_INT_MUL_IV,
		    cmd->cmd_tgt2, cmd->cmd_qty);
		break;

	case FSK_DIVIDE:
		var_assign_op_var_int(cmd->cmd_tgt1, VAR_IND_IV_DIV_INT,
		    cmd->cmd_tgt2, cmd->cmd_qty);
		break;
	}
}

/*
 * Used by the set command to set up for a binary operation of an
 * integer with a variable from a var
 */
static void
parser_set_int_op_var(cmd_t *cmd)
{
	switch (cmd->cmd_subtype) {
	case FSK_PLUS:
		var_assign_op_var_int(cmd->cmd_tgt1, VAR_IND_INT_SUM_IV,
		    cmd->cmd_tgt3, cmd->cmd_qty);
		break;

	case FSK_MINUS:
		var_assign_op_var_int(cmd->cmd_tgt1, VAR_IND_INT_DIF_IV,
		    cmd->cmd_tgt3, cmd->cmd_qty);
		break;

	case FSK_MULTIPLY:
		var_assign_op_var_int(cmd->cmd_tgt1, VAR_IND_INT_MUL_IV,
		    cmd->cmd_tgt3, cmd->cmd_qty);
		break;

	case FSK_DIVIDE:
		var_assign_op_var_int(cmd->cmd_tgt1, VAR_IND_INT_DIV_IV,
		    cmd->cmd_tgt3, cmd->cmd_qty);
		break;
	}
}

/*
 * Used by the set command to set up for a binary operation of two
 * variables from other vars.
 */
static void
parser_set_var_op_var(cmd_t *cmd)
{
	switch (cmd->cmd_subtype) {
	case FSK_PLUS:
		var_assign_op_var_var(cmd->cmd_tgt1, VAR_IND_IV_SUM_IV,
		    cmd->cmd_tgt2, cmd->cmd_tgt3);
		break;

	case FSK_MINUS:
		var_assign_op_var_var(cmd->cmd_tgt1, VAR_IND_IV_DIF_IV,
		    cmd->cmd_tgt2, cmd->cmd_tgt3);
		break;

	case FSK_MULTIPLY:
		var_assign_op_var_var(cmd->cmd_tgt1, VAR_IND_IV_MUL_IV,
		    cmd->cmd_tgt2, cmd->cmd_tgt3);
		break;

	case FSK_DIVIDE:
		var_assign_op_var_var(cmd->cmd_tgt1, VAR_IND_IV_DIV_IV,
		    cmd->cmd_tgt2, cmd->cmd_tgt3);
		break;
	}
}


/*
 * Sleeps for cmd->cmd_qty seconds, one second at a time.
 */
static void
parser_warmup(cmd_t *cmd)
{
	int sleeptime;

	/* check for startup errors */
	if (filebench_shm->shm_f_abort)
		return;

	sleeptime = cmd->cmd_qty;
	filebench_log(LOG_INFO, "Warming up...");

	(void) parser_pause(sleeptime);
}

/*
 * Same as parser_sleep, except the sleep time is obtained from a variable
 * whose name is passed to it as an argument on the command line.
 */
static void
parser_warmup_variable(cmd_t *cmd)
{
	avd_t integer = var_ref_attr(cmd->cmd_tgt1);
	int sleeptime;

	if (integer == NULL) {
		filebench_log(LOG_ERROR, "Unknown variable %s",
		cmd->cmd_tgt1);
		return;
	}

	sleeptime = avd_get_int(integer);

	/* check for startup errors */
	if (filebench_shm->shm_f_abort)
		return;

	filebench_log(LOG_INFO, "Warming up...");

	(void) parser_pause(sleeptime);
}

/*
 * Sleeps for cmd->cmd_qty seconds, one second at a time.
 */
static void
parser_sleep(cmd_t *cmd)
{
	int sleeptime;
	int timeslept;

	/* check for startup errors */
	if (filebench_shm->shm_f_abort)
		return;

	sleeptime = cmd->cmd_qty;
	filebench_log(LOG_INFO, "Running...");

	timeslept = parser_pause(sleeptime);

	filebench_log(LOG_INFO, "Run took %d seconds...", timeslept);
}

/*
 * Same as parser_sleep, except the sleep time is obtained from a variable
 * whose name is passed to it as an argument on the command line.
 */
static void
parser_sleep_variable(cmd_t *cmd)
{
	avd_t integer = var_ref_attr(cmd->cmd_tgt1);
	int sleeptime;
	int timeslept;

	if (integer == NULL) {
		filebench_log(LOG_ERROR, "Unknown variable %s",
		cmd->cmd_tgt1);
		return;
	}

	sleeptime = avd_get_int(integer);

	/* check for startup errors */
	if (filebench_shm->shm_f_abort)
		return;

	filebench_log(LOG_INFO, "Running...");

	timeslept = parser_pause(sleeptime);

	filebench_log(LOG_INFO, "Run took %d seconds...", timeslept);
}

/*
 * Parser log prints the values of a list of variables to the log file.
 * The list of variables is placed on the command line, separated
 * by comas and the entire list is enclosed in quotes.
 * For example, if $dir contains "/export/home/tmp" and $filesize = 1048576,
 * then typing: log "$dir, $filesize" prints: log /export/home/tmp, 1048576
 */
static void
parser_log(cmd_t *cmd)
{
	char *string;

	if (cmd->cmd_param_list == NULL)
		return;

	string = parser_list2string(cmd->cmd_param_list);

	if (string == NULL)
		return;

	filebench_log(LOG_VERBOSE, "log %s", string);
	filebench_log(LOG_LOG, "%s", string);
}

/*
 * Implements the stats directory command. changes the directory for
 * dumping statistics to supplied directory path. For example:
 * 	stats directory /tmp
 * changes the stats directory to "/tmp".
 */
static void
parser_directory(cmd_t *cmd)
{
	char newdir[MAXPATHLEN];
	char *dir;
	int ret;

	if ((dir = parser_list2string(cmd->cmd_param_list)) == NULL) {
		filebench_log(LOG_ERROR, "Cannot interpret directory");
		return;
	}

	*newdir = 0;
	/* Change dir relative to cwd if path not fully qualified */
	if (*dir != '/') {
		(void) strcat(newdir, cwd);
		(void) strcat(newdir, "/");
	}
	(void) strcat(newdir, dir);
	(void) mkdir(newdir, 0755);
	filebench_log(LOG_VERBOSE, "Change dir to %s", newdir);
	ret = chdir(newdir);
	free(dir);
        
}

#define	PIPE_PARENT 1
#define	PIPE_CHILD  0

/*
 * Runs the quoted unix command as a background process. Intended for
 * running statistics gathering utilities such as mpstat while the filebench
 * workload is running. Also records the pid's of the background processes
 * so that parser_statssnap() can terminate them when the run completes.
 */
static void
parser_statscmd(cmd_t *cmd)
{
	char *string;
	pid_t pid;
	pidlist_t *pidlistent;
	int pipe_fd[2];
	int newstdout;

	if (cmd->cmd_param_list == NULL)
		return;

	string = parser_list2string(cmd->cmd_param_list);

	if (string == NULL)
		return;

	if ((pipe(pipe_fd)) < 0) {
		filebench_log(LOG_ERROR, "statscmd pipe failed");
		return;
	}

#ifdef HAVE_FORK1
	if ((pid = fork1()) < 0) {
		filebench_log(LOG_ERROR, "statscmd fork failed");
		return;
	}
#elif HAVE_FORK
	if ((pid = fork()) < 0) {
		filebench_log(LOG_ERROR, "statscmd fork failed");
		return;
	}
#else
	Crash! - Need code to deal with no fork1!
#endif /* HAVE_FORK1 */

	if (pid == 0) {

		setsid();

		filebench_log(LOG_VERBOSE,
		    "Backgrounding %s", string);
		/*
		 * Child
		 * - close stdout
		 * - dup to create new stdout
		 * - close pipe fds
		 */
		(void) close(1);

		if ((newstdout = dup(pipe_fd[PIPE_CHILD])) < 0) {
			filebench_log(LOG_ERROR,
			    "statscmd dup failed: %s",
			    strerror(errno));
		}

		(void) close(pipe_fd[PIPE_PARENT]);
		(void) close(pipe_fd[PIPE_CHILD]);

		if (system(string) < 0) {
			filebench_log(LOG_ERROR,
			    "statscmd exec failed: %s",
			    strerror(errno));
		}
		/* Failed! */
		exit(1);

	} else {

		/* Record pid in pidlist for subsequent reaping by stats snap */
		if ((pidlistent = (pidlist_t *)malloc(sizeof (pidlist_t)))
		    == NULL) {
			filebench_log(LOG_ERROR, "pidlistent malloc failed");
			return;
		}

		pidlistent->pl_pid = pid;
		pidlistent->pl_fd = pipe_fd[PIPE_PARENT];
		(void) close(pipe_fd[PIPE_CHILD]);

		/* Add fileobj to global list */
		if (pidlist == NULL) {
			pidlist = pidlistent;
			pidlistent->pl_next = NULL;
		} else {
			pidlistent->pl_next = pidlist;
			pidlist = pidlistent;
		}
	}
}

/*
 * Launches a shell to run the unix command supplied in the argument.
 * The command should be enclosed in quotes, as in:
 * 	system "rm xyz"
 * which would run the "rm" utility to delete the file "xyz".
 */
static void
parser_system(cmd_t *cmd)
{
	char *string;

	if (cmd->cmd_param_list == NULL)
		return;

	string = parser_list2string(cmd->cmd_param_list);

	if (string == NULL)
		return;

	filebench_log(LOG_VERBOSE,
	    "Running '%s'", string);

	if (system(string) < 0) {
		filebench_log(LOG_ERROR,
		    "system exec failed: %s",
		    strerror(errno));
		filebench_shutdown(1);
	}
	free(string);
}

/*
 * Echos string supplied with command to the log.
 */
static void
parser_echo(cmd_t *cmd)
{
	char *string;

	if (cmd->cmd_param_list == NULL)
		return;

	string = parser_list2string(cmd->cmd_param_list);

	if (string == NULL)
		return;

	filebench_log(LOG_INFO, "%s", string);
}

static void parser_fscheck(cmd_t *cmd) {
	return;
}

#if 0
/* XXX: do not support this command for now */
/*
 * Checks to see if the specified data directory exists and it's mounted file
 * system is the correct type.
 */
static void
parser_fscheck(cmd_t *cmd)
{
	int fstype_idx;
	char *pathname = NULL;
	char *filesys = "tmpfs";
	char string[MAXPATHLEN];
	struct statvfs64 statbuf;
	attr_t *attr;

	if (cmd->cmd_attr_list == NULL)
		return;

	for (attr = cmd->cmd_attr_list; attr; attr = attr->attr_next) {

		switch(attr->attr_name) {
		case FSA_PATH:
			pathname = avd_get_str(attr->attr_avd);
			break;
		case FSA_FSTYPE:
			filesys = avd_get_str(attr->attr_avd);
			break;
		}
	}

	if (pathname == NULL)
		return;

	if (statvfs64(pathname, &statbuf) < 0) {
		filebench_log(LOG_ERROR,
		    "%s error with supplied data path name: %s; exiting",
		    strerror(errno), pathname);
		filebench_shutdown(1);
		return;
	}

	if (strncmp(filesys, statbuf.f_basetype, FSTYPSZ) != 0) {
		filebench_log(LOG_ERROR,
		    "File System is of type %s, NOT %s as indicated",
		    statbuf.f_basetype, filesys);
		filebench_shutdown(1);
		return;
	}
}
#endif

/*
 * Checks to see if any filesets need to have their caches flushed, and
 * if so invokes the fs_flush script.
 */
static void
parser_fsflush(cmd_t *cmd)
{
	fileset_t *fileset;
	char **fspathlist;
	char *pathname = NULL;
	char *filesys = NULL;
	char string[MAXPATHLEN];
	attr_t *attr;
	int fsidx;

	if ((attr = cmd->cmd_attr_list) == NULL)
		return;

	/* Get supplied file system type */
	if (attr->attr_name == FSA_FSTYPE)
		filesys = avd_get_str(attr->attr_avd);

	if (filesys == NULL) {
		filebench_log(LOG_ERROR,
		    "FSFLUSH command lacks file system type");
		return;
	}

	/* Check all filesets for any that remain cached and count them*/
	fsidx = 0;
	for (fileset = filebench_shm->shm_filesetlist; fileset != NULL;
	     fileset = fileset->fs_next) {

		if (avd_get_bool(fileset->fs_cached))
			return;

		fsidx++;
	}

	/* allocated space for fileset path pointers */
	fspathlist = (char **)malloc(fsidx * sizeof(char *));

	/* If flushing still required, flush all filesets */
	fsidx = 0;
	for (fileset = filebench_shm->shm_filesetlist; fileset != NULL;
	     fileset = fileset->fs_next) {
		int idx;

		if ((pathname = avd_get_str(fileset->fs_path)) == NULL)
			return;

		for (idx = 0; idx < fsidx; idx++) {
			if (strcmp(pathname, fspathlist[idx]) == 0)
				break;
		}

		if (fsidx == idx) {

			/* found a new path */
			fspathlist[fsidx++] = pathname;

			/* now flush it */
			snprintf(string, MAXPATHLEN,
			    "%s/scripts/fs_flush %s %s", fbbasepath,
			    filesys, pathname);

			if (system(string) < 0) {
				filebench_log(LOG_ERROR,
				    "exec of fs_flush script failed: %s",
				    strerror(errno));
				filebench_shutdown(1);
			}
		}
	}
}

/*
 * Prints out the version of Filebench.
 */
static void
parser_version(cmd_t *cmd)
{
	filebench_log(LOG_INFO, "Filebench Version: %s", FILEBENCH_VERSION);
}

/*
 * Sets osprof_enabled option
 */
static void
parser_osprof_enable(cmd_t *cmd)
{
	filebench_shm->osprof_enabled = 1;
	filebench_log(LOG_INFO, "OSprof enabled");
}

/*
 * Resets osprof_enabled option
 */
static void
parser_osprof_disable(cmd_t *cmd)
{
	filebench_shm->osprof_enabled = 0;
	filebench_log(LOG_INFO, "OSprof disabled");
}

/*
 * Adds the string supplied as the argument to the usage command
 * to the end of the string printed by the help command.
 */
static void
parser_usage(cmd_t *cmd)
{
	char *string;
	char *newusage;

	if (cmd->cmd_param_list == NULL)
		return;

	string = parser_list2string(cmd->cmd_param_list);

	if (string == NULL)
		return;

	if (dofile == DOFILE_TRUE)
		return;

	if (usagestr == NULL) {
		newusage = malloc(strlen(string) + 2);
		*newusage = 0;
	} else {
		newusage = malloc(strlen(usagestr) + strlen(string) + 2);
		(void) strcpy(newusage, usagestr);
	}
	(void) strcat(newusage, "\n");
	(void) strcat(newusage, string);

	if (usagestr)
		free(usagestr);

	usagestr = newusage;

	filebench_log(LOG_INFO, "%s", string);
}

/*
 * Updates the global dump filename with the filename supplied
 * as the command's argument. Then dumps the statistics of each
 * worker flowop into the dump file, followed by a summary of
 * overall totals.
 */
static void
parser_statsdump(cmd_t *cmd)
{
	char *string;

	if (cmd->cmd_param_list == NULL)
		return;

	string = parser_list2string(cmd->cmd_param_list);

	if (string == NULL)
		return;

	filebench_log(LOG_VERBOSE,
	    "Stats dump to file '%s'", string);

	stats_dump(string);

	free(string);
}

/*
 * Same as statsdump, but outputs in a computer friendly format.
 */
static void
parser_statsmultidump(cmd_t *cmd)
{
	char *string;

	if (cmd->cmd_param_list == NULL)
		return;

	string = parser_list2string(cmd->cmd_param_list);

	if (string == NULL)
		return;

	filebench_log(LOG_VERBOSE,
	    "Stats dump to file '%s'", string);

	stats_multidump(string);

	free(string);
}

/*
 * Same as parser_statsdump, but in xml format.
 */
static void
parser_statsxmldump(cmd_t *cmd)
{
	char *string;

	if (cmd->cmd_param_list == NULL)
		return;

	string = parser_list2string(cmd->cmd_param_list);

	if (string == NULL)
		return;

	filebench_log(LOG_VERBOSE,
	    "Stats dump to file '%s'", string);

	stats_xmldump(string);

	free(string);
}

/*
 * Kills off background statistics collection processes, then takes a snapshot
 * of the filebench run's collected statistics using stats_snap() from
 * stats.c.
 */
static void
parser_statssnap(cmd_t *cmd)
{
	pidlist_t *pidlistent;
	int stat;
	pid_t pid;

	for (pidlistent = pidlist; pidlistent != NULL;
	    pidlistent = pidlistent->pl_next) {
		filebench_log(LOG_VERBOSE, "Killing session %d for pid %d",
		    getsid(pidlistent->pl_pid),
		    pidlistent->pl_pid);
		if (pidlistent->pl_fd)
			(void) close(pidlistent->pl_fd);
#ifdef HAVE_SIGSEND
		sigsend(P_SID, getsid(pidlistent->pl_pid), SIGTERM);
#else
		(void) kill(-1, SIGTERM);
#endif

		/* Close pipe */
		if (pidlistent->pl_fd)
			(void) close(pidlistent->pl_fd);

		/* Wait for cmd and all its children */
		while ((pid = waitpid(pidlistent->pl_pid * -1, &stat, 0)) > 0)
			filebench_log(LOG_DEBUG_IMPL,
			"Waited for pid %d", (int)pid);
	}

	for (pidlistent = pidlist; pidlistent != NULL;
	    pidlistent = pidlistent->pl_next) {
		free(pidlistent);
	}

	pidlist = NULL;
	stats_snap();
}

/*
 * Shutdown filebench.
 */
static void
parser_abort(int arg)
{
	(void) sigignore(SIGINT);
	filebench_log(LOG_INFO, "Aborting...");
	filebench_shutdown(1);
}

/*
 * define a random variable and initialize the distribution parameters
 */
static void
parser_randvar_define(cmd_t *cmd)
{
	var_t		*var;
	randdist_t	*rndp;
	attr_t		*attr;
	char		*name;

	/* Get the name for the random variable */
	if ((attr = get_attr(cmd, FSA_NAME))) {
		name = avd_get_str(attr->attr_avd);
	} else {
		filebench_log(LOG_ERROR,
		    "define randvar: no name specified");
		return;
	}

	if ((var = var_define_randvar(name)) == NULL) {
		filebench_log(LOG_ERROR,
		    "define randvar: failed for random variable %s",
		    name);
		return;
	}

	rndp = var->var_val.randptr;
	rndp->rnd_type = 0;

	/* Get the source of the random numbers */
	if ((attr = get_attr_integer(cmd, FSA_RANDSRC))) {
		int randsrc = (int)avd_get_int(attr->attr_avd);

		switch (randsrc) {
		case FSV_URAND:
			rndp->rnd_type |= RAND_SRC_URANDOM;
			break;
		case FSV_RAND48:
			rndp->rnd_type |= RAND_SRC_GENERATOR;
			break;
		}
	} else {
		/* default to rand48 random number generator */
		rndp->rnd_type |= RAND_SRC_GENERATOR;
	}

	/* Get the min value of the random distribution */
	if ((attr = get_attr_integer(cmd, FSA_RANDMIN)))
		rndp->rnd_min = attr->attr_avd;
	else
		rndp->rnd_min = avd_int_alloc(0);

	/* Get the roundoff value for the random distribution */
	if ((attr = get_attr_integer(cmd, FSA_RANDROUND)))
		rndp->rnd_round = attr->attr_avd;
	else
		rndp->rnd_round = avd_int_alloc(0);

	/* Get a tablular probablility distribution if there is one */
	if ((attr = get_attr(cmd, FSA_RANDTABLE))) {
		rndp->rnd_probtabs = (probtabent_t *)(attr->attr_obj);
		rndp->rnd_type |= RAND_TYPE_TABLE;

		/* no need for the rest of the attributes */
		return;
	} else {
		rndp->rnd_probtabs = NULL;
	}

	/* Get the type for the random variable */
	if ((attr = get_attr(cmd, FSA_TYPE))) {
		int disttype = (int)avd_get_int(attr->attr_avd);

		switch (disttype) {
		case FSV_RANDUNI:
			rndp->rnd_type |= RAND_TYPE_UNIFORM;
			break;
		case FSA_RANDGAMMA:
			rndp->rnd_type |= RAND_TYPE_GAMMA;
			break;
		case FSV_RANDTAB:
			filebench_log(LOG_ERROR,
			    "Table distribution type without prob table");
			break;
		}
	} else {
		/* default to gamma distribution type */
		rndp->rnd_type |= RAND_TYPE_GAMMA;
	}

	/* Get the seed for the random variable */
	if ((attr = get_attr_integer(cmd, FSA_RANDSEED)))
		rndp->rnd_seed = attr->attr_avd;
	else
		rndp->rnd_seed = avd_int_alloc(0);

	/* Get the gamma value of the random distribution */
	if ((attr = get_attr_integer(cmd, FSA_RANDGAMMA)))
		rndp->rnd_gamma = attr->attr_avd;
	else
		rndp->rnd_gamma = avd_int_alloc(1500);

	/* Get the mean value of the random distribution */
	if ((attr = get_attr_integer(cmd, FSA_RANDMEAN))) {
		rndp->rnd_mean = attr->attr_avd;
	} else if ((rndp->rnd_type & RAND_TYPE_MASK) == RAND_TYPE_GAMMA) {
		rndp->rnd_mean = NULL;
	} else {
		rndp->rnd_mean = avd_int_alloc(0);
	}
}

/*
 * Set a specified random distribution parameter in a random variable.
 */
static void
parser_randvar_set(cmd_t *cmd)
{
	var_t		*randvar;
	randdist_t	*rndp;
	avd_t	value;

	if ((randvar = var_find_randvar(cmd->cmd_tgt1)) == NULL) {
		filebench_log(LOG_ERROR,
		    "set randvar: failed",
		    cmd->cmd_tgt1);
		return;
	}

	rndp = randvar->var_val.randptr;
	value = cmd->cmd_attr_list->attr_avd;

	switch (cmd->cmd_qty) {
	case FSS_TYPE:
		{
			int disttype = (int)avd_get_int(value);

			rndp->rnd_type &= (~RAND_TYPE_MASK);

			switch (disttype) {
			case FSV_RANDUNI:
				rndp->rnd_type |= RAND_TYPE_UNIFORM;
				break;
			case FSA_RANDGAMMA:
				rndp->rnd_type |= RAND_TYPE_GAMMA;
				break;
			case FSV_RANDTAB:
				rndp->rnd_type |= RAND_TYPE_TABLE;
				break;
			}
			break;
		}

	case FSS_SRC:
		{
			int randsrc = (int)avd_get_int(value);

			rndp->rnd_type &=
			    (~(RAND_SRC_URANDOM | RAND_SRC_GENERATOR));

			switch (randsrc) {
			case FSV_URAND:
				rndp->rnd_type |= RAND_SRC_URANDOM;
				break;
			case FSV_RAND48:
				rndp->rnd_type |= RAND_SRC_GENERATOR;
				break;
			}
			break;
		}

	case FSS_SEED:
		rndp->rnd_seed = value;
		break;

	case FSS_GAMMA:
		rndp->rnd_gamma = value;
		break;

	case FSS_MEAN:
		rndp->rnd_mean = value;
		break;

	case FSS_MIN:
		rndp->rnd_min = value;
		break;

	case FSS_ROUND:
		rndp->rnd_round = value;
		break;

	default:
		filebench_log(LOG_ERROR, "setrandvar: undefined attribute");
	}
}

/*
 * alloc_cmd() allocates the required resources for a cmd_t. On failure, a
 * filebench_log is issued and NULL is returned.
 */
static cmd_t *
alloc_cmd(void)
{
	cmd_t *cmd;

	if ((cmd = malloc(sizeof (cmd_t))) == NULL) {
		filebench_log(LOG_ERROR, "Alloc cmd failed");
		return (NULL);
	}

	(void) memset(cmd, 0, sizeof (cmd_t));

	return (cmd);
}

/*
 * Allocates an attr_t structure and zeros it. Returns NULL on failure, or
 * a pointer to the attr_t.
 */
static attr_t *
alloc_attr(void)
{
	attr_t *attr;

	if ((attr = malloc(sizeof (attr_t))) == NULL) {
		return (NULL);
	}

	(void) memset(attr, 0, sizeof (attr_t));
	return (attr);
}

/*
 * Allocates a probtabent_t structure and zeros it. Returns NULL on failure, or
 * a pointer to the probtabent_t.
 */
static probtabent_t *
alloc_probtabent(void)
{
	probtabent_t *rte;

	if ((rte = malloc(sizeof (probtabent_t))) == NULL) {
		return (NULL);
	}

	(void) memset(rte, 0, sizeof (probtabent_t));
	return (rte);
}

/*
 * Allocates an attr_t structure and puts the supplied var_t into
 * its attr_avd location, and sets its name to FSA_LVAR_ASSIGN
 */
static attr_t *
alloc_lvar_attr(var_t *var)
{
	attr_t *attr;

	if ((attr = alloc_attr()) == NULL)
		return (NULL);

	attr->attr_name = FSA_LVAR_ASSIGN;
	attr->attr_avd = (avd_t)var;

	return (attr);
}


/*
 * Searches the attribute list for the command for the named attribute type.
 * The attribute list is created by the parser from the list of attributes
 * supplied with certain commands, such as the define and flowop commands.
 * Returns a pointer to the attribute structure if the named attribute is
 * found, otherwise returns NULL. If the attribute includes a parameter list,
 * the list is converted to a string and stored in the attr_avd field of
 * the returned attr_t struct.
 */
static attr_t *
get_attr_fileset(cmd_t *cmd, int64_t name)
{
	attr_t *attr;
	attr_t *rtn = NULL;

	for (attr = cmd->cmd_attr_list; attr != NULL;
	    attr = attr->attr_next) {
		filebench_log(LOG_DEBUG_IMPL,
		    "attr %d = %d %llx?",
		    attr->attr_name,
		    name,
		    attr->attr_avd);

		if (attr->attr_name == name)
			rtn = attr;
	}

	if (rtn == NULL)
		return (NULL);

	if (rtn->attr_param_list) {
		filebench_log(LOG_DEBUG_SCRIPT, "attr is param list");
		rtn->attr_avd = parser_list2varstring(rtn->attr_param_list);
	}

	return (rtn);
}


/*
 * Searches the attribute list for the command for the named attribute type.
 * The attribute list is created by the parser from the list of attributes
 * supplied with certain commands, such as the define and flowop commands.
 * Returns a pointer to the attribute structure if the named attribute is
 * found, otherwise returns NULL. If the attribute includes a parameter list,
 * the list is converted to a string and stored in the attr_avd field of
 * the returned attr_t struct.
 */
static attr_t *
get_attr(cmd_t *cmd, int64_t name)
{
	attr_t *attr;
	attr_t *rtn = NULL;
	char *string;

	for (attr = cmd->cmd_attr_list; attr != NULL;
	    attr = attr->attr_next) {
		filebench_log(LOG_DEBUG_IMPL,
		    "attr %d = %d %llx?",
		    attr->attr_name,
		    name,
		    attr->attr_avd);

		if (attr->attr_name == name)
			rtn = attr;
	}

	if (rtn == NULL)
		return (NULL);

	if (rtn->attr_param_list) {
		filebench_log(LOG_DEBUG_SCRIPT, "attr is param list");
		string = parser_list2string(rtn->attr_param_list);
		if (string != NULL) {
			rtn->attr_avd = avd_str_alloc(string);
			filebench_log(LOG_DEBUG_SCRIPT,
			    "attr string %s", string);
		}
	}

	return (rtn);
}

/*
 * Similar to get_attr, but converts the parameter string supplied with the
 * named attribute to an integer and stores the integer in the attr_avd
 * portion of the returned attr_t struct.
 */
static attr_t *
get_attr_integer(cmd_t *cmd, int64_t name)
{
	attr_t *attr;
	attr_t *rtn = NULL;

	for (attr = cmd->cmd_attr_list; attr != NULL;
	    attr = attr->attr_next) {
		if (attr->attr_name == name)
			rtn = attr;
	}

	if (rtn == NULL)
		return (NULL);

	if (rtn->attr_param_list)
		rtn->attr_avd = parser_list2avd(rtn->attr_param_list);

	return (rtn);
}

/*
 * Similar to get_attr, but converts the parameter string supplied with the
 * named attribute to an integer and stores the integer in the attr_avd
 * portion of the returned attr_t struct. If no parameter string is supplied
 * then it defaults to TRUE (1).
 */
static attr_t *
get_attr_bool(cmd_t *cmd, int64_t name)
{
	attr_t *attr;
	attr_t *rtn = NULL;

	for (attr = cmd->cmd_attr_list; attr != NULL;
	    attr = attr->attr_next) {
		if (attr->attr_name == name)
			rtn = attr;
	}

	if (rtn == NULL)
		return (NULL);

	if (rtn->attr_param_list) {
		rtn->attr_avd = parser_list2avd(rtn->attr_param_list);

	} else if (rtn->attr_avd == NULL) {
		rtn->attr_avd = avd_bool_alloc(TRUE);
	}

	/* boolean attributes cannot point to random variables */
	if (AVD_IS_RANDOM(rtn->attr_avd)) {
		filebench_log(LOG_ERROR,
		    "define flowop: Boolean attr %s cannot be random", name);
		filebench_shutdown(1);
		return (NULL);
	}

	return (rtn);
}

/*
 * removes the newly allocated local var from the shared local var
 * list, then puts it at the head of the private local var list
 * supplied as the second argument.
 */
static void
add_lvar_to_list(var_t *newlvar, var_t **lvar_list)
{
	var_t *prev;

	/* remove from shared local list, if there */
	if (newlvar == filebench_shm->shm_var_loc_list) {
		/* on top of list, just grap */
		filebench_shm->shm_var_loc_list = newlvar->var_next;
	} else {
		/* find newvar on list and remove */
		for (prev = filebench_shm->shm_var_loc_list; prev;
		    prev = prev->var_next) {
			if (prev->var_next == newlvar)
				prev->var_next = newlvar->var_next;
		}
	}
	newlvar->var_next = NULL;

	/* add to flowop private local list at head */
	newlvar->var_next = *lvar_list;
	*lvar_list = newlvar;
}

/*
 * Searches the attribute list for the command for any allocated local
 * variables. The attribute list is created by the parser from the list of
 * attributes supplied with certain commands, such as the define and flowop
 * commands. Places all found local vars onto the flowop's local variable
 * list. 
 */
static void
get_attr_lvars(cmd_t *cmd, flowop_t *flowop)
{
	attr_t *attr;
	var_t *orig_lvar_list;

	/* save the local var list */
	orig_lvar_list = flowop->fo_lvar_list;

	for (attr = cmd->cmd_attr_list; attr != NULL;
	    attr = attr->attr_next) {

		if (attr->attr_name == FSA_LVAR_ASSIGN) {
			var_t *newvar;

			if ((newvar = (var_t *)attr->attr_avd) == NULL)
				continue;

			add_lvar_to_list(newvar, &flowop->fo_lvar_list);
			var_update_comp_lvars(newvar, orig_lvar_list, NULL);
		}
	}
}

/*
 * Allocates memory for a list_t structure, initializes it to zero, and
 * returns a pointer to it. On failure, returns NULL.
 */
static list_t *
alloc_list()
{
	list_t *list;

	if ((list = malloc(sizeof (list_t))) == NULL) {
		return (NULL);
	}

	(void) memset(list, 0, sizeof (list_t));
	return (list);
}

int
yywrap()
{
	if (parentscript) {
		yyin = parentscript;
		yy_switchfilescript(yyin);
		parentscript = NULL;
		return (0);
	} else
		return (1);
}

