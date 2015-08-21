/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
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

/* Line 2068 of yacc.c  */
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



/* Line 2068 of yacc.c  */
#line 346 "parser_gram.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


