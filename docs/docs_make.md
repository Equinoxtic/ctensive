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
