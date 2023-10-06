## Make (Flags / Options)

### CTENSIVE_ENABLE_ASSERT

* Enables the custom assert function; impassert()

```makefile
# MAKEFILE
build:
    gcc foo.c -DCTENSIVE_ENABLE_ASSERT -o bar.o
```

### DISABLE_SLEEP

* Disables sleep functions

```makefile
# MAKEFILE
build:
    gcc foo.c -DDISABLE_SLEEP -o bar.o
```

### DISABLE_TRACE_LOGGING

* Disables trace / logging functions

```makefile
# MAKEFILE
build:
    gcc foo.c -DDISABLE_TRACE_LOGGING -o bar.o
```

### DISABLE_DRAW_FUNCTIONS

* Disables simple drawing functions

```makefile
# MAKEFILE
build:
    gcc foo.c -DDISABLE_DRAW_FUNCTIONS -o bar.o
```

### DISABLE_CCMDCALL

* Disables the ccmdcall() function

```makefile
# MAKEFILE
build:
    gcc foo.c -DDISABLE_CCMDCALL -o bar.o
```
