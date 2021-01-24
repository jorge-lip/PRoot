How to make a release of PRoot?
===============================

This document summarizes checks that must be performed before
releasing PRoot or CARE.

Checks
------

+ Sanity checks:

  * on ARM and *all* OBS distros (x86 and x86_64): `make -C test`

  * on x86_64, with *and* without seccomp:

    - `make -C test` on *all* OBS distros
    - `make -C test memcheck`
    - `CFLAGS=-fsanitize=address LDFLAGS=-lasan`
    - `make -C test V=1 2>&1 | grep talloc`

+ Functional checks: no regressions must appear with respect to
  test/validation.mk and to the configurations tested in the previous
  release (`git show tags/...`).

+ Performance checks: the following command must not suffer from
  unexpected performance regression::

    time proot -R / perl -e 'system("/usr/bin/true") for (1..10000)'

  where "/usr/bin/true" is a symlink to "/bin/true".

+ Static analysis: Gcov/Lcov and Clang Scan Build must not report
  new issues. All shell scripts must pass shellcheck.
  
Static Binaries
---------------

The following commands will generate statically-linked binaries
which can be optionally distributed for each release:

    make -C src loader.elf loader-m32.elf build.h
    LDFLAGS="${LDFLAGS} -static" make -C proot

Documentation Update
--------------------

0. update "doc/changelog.rst"

1. update the release number in "doc/proot/manual.rst"

2. regenerate the documentation: `make -C doc`

3. regenerate the command-line interface: `cp doc/*.h
   src/cli/; $EDITOR src/cli/{proot,care}.h`

4. upload the generated RPM .spec file to OBS

5. regenerate the website: `SITE_DIR=../../proot-me.github.io
   make -eC doc dist # relative to doc directory`
