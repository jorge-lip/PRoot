#include "syscall/sysnum.h"

static const Sysnum sysnums_arm[] = {
	[ 0 ] = PR_restart_syscall,
	[ 1 ] = PR_exit,
	[ 2 ] = PR_fork,
	[ 3 ] = PR_read,
	[ 4 ] = PR_write,
	[ 5 ] = PR_open,
	[ 6 ] = PR_close,
	[ 8 ] = PR_creat,
	[ 9 ] = PR_link,
	[ 10 ] = PR_unlink,
	[ 11 ] = PR_execve,
	[ 12 ] = PR_chdir,
	[ 14 ] = PR_mknod,
	[ 15 ] = PR_chmod,
	[ 16 ] = PR_lchown,
	[ 19 ] = PR_lseek,
	[ 20 ] = PR_getpid,
	[ 21 ] = PR_mount,
	[ 23 ] = PR_setuid,
	[ 24 ] = PR_getuid,
	[ 26 ] = PR_ptrace,
	[ 29 ] = PR_pause,
	[ 33 ] = PR_access,
	[ 34 ] = PR_nice,
	[ 36 ] = PR_sync,
	[ 37 ] = PR_kill,
	[ 38 ] = PR_rename,
	[ 39 ] = PR_mkdir,
	[ 40 ] = PR_rmdir,
	[ 41 ] = PR_dup,
	[ 42 ] = PR_pipe,
	[ 43 ] = PR_times,
	[ 45 ] = PR_brk,
	[ 46 ] = PR_setgid,
	[ 47 ] = PR_getgid,
	[ 49 ] = PR_geteuid,
	[ 50 ] = PR_getegid,
	[ 51 ] = PR_acct,
	[ 52 ] = PR_umount2,
	[ 54 ] = PR_ioctl,
	[ 55 ] = PR_fcntl,
	[ 57 ] = PR_setpgid,
	[ 60 ] = PR_umask,
	[ 61 ] = PR_chroot,
	[ 62 ] = PR_ustat,
	[ 63 ] = PR_dup2,
	[ 64 ] = PR_getppid,
	[ 65 ] = PR_getpgrp,
	[ 66 ] = PR_setsid,
	[ 67 ] = PR_sigaction,
	[ 70 ] = PR_setreuid,
	[ 71 ] = PR_setregid,
	[ 72 ] = PR_sigsuspend,
	[ 73 ] = PR_sigpending,
	[ 74 ] = PR_sethostname,
	[ 75 ] = PR_setrlimit,
	[ 77 ] = PR_getrusage,
	[ 78 ] = PR_gettimeofday,
	[ 79 ] = PR_settimeofday,
	[ 80 ] = PR_getgroups,
	[ 81 ] = PR_setgroups,
	[ 83 ] = PR_symlink,
	[ 85 ] = PR_readlink,
	[ 86 ] = PR_uselib,
	[ 87 ] = PR_swapon,
	[ 88 ] = PR_reboot,
	[ 91 ] = PR_munmap,
	[ 92 ] = PR_truncate,
	[ 93 ] = PR_ftruncate,
	[ 94 ] = PR_fchmod,
	[ 95 ] = PR_fchown,
	[ 96 ] = PR_getpriority,
	[ 97 ] = PR_setpriority,
	[ 99 ] = PR_statfs,
	[ 100 ] = PR_fstatfs,
	[ 103 ] = PR_syslog,
	[ 104 ] = PR_setitimer,
	[ 105 ] = PR_getitimer,
	[ 106 ] = PR_stat,
	[ 107 ] = PR_lstat,
	[ 108 ] = PR_fstat,
	[ 111 ] = PR_vhangup,
	[ 114 ] = PR_wait4,
	[ 115 ] = PR_swapoff,
	[ 116 ] = PR_sysinfo,
	[ 118 ] = PR_fsync,
	[ 119 ] = PR_sigreturn,
	[ 120 ] = PR_clone,
	[ 121 ] = PR_setdomainname,
	[ 122 ] = PR_uname,
	[ 124 ] = PR_adjtimex,
	[ 125 ] = PR_mprotect,
	[ 126 ] = PR_sigprocmask,
	[ 128 ] = PR_init_module,
	[ 129 ] = PR_delete_module,
	[ 131 ] = PR_quotactl,
	[ 132 ] = PR_getpgid,
	[ 133 ] = PR_fchdir,
	[ 134 ] = PR_bdflush,
	[ 135 ] = PR_sysfs,
	[ 136 ] = PR_personality,
	[ 138 ] = PR_setfsuid,
	[ 139 ] = PR_setfsgid,
	[ 140 ] = PR__llseek,
	[ 141 ] = PR_getdents,
	[ 142 ] = PR__newselect,
	[ 143 ] = PR_flock,
	[ 144 ] = PR_msync,
	[ 145 ] = PR_readv,
	[ 146 ] = PR_writev,
	[ 147 ] = PR_getsid,
	[ 148 ] = PR_fdatasync,
	[ 149 ] = PR__sysctl,
	[ 150 ] = PR_mlock,
	[ 151 ] = PR_munlock,
	[ 152 ] = PR_mlockall,
	[ 153 ] = PR_munlockall,
	[ 154 ] = PR_sched_setparam,
	[ 155 ] = PR_sched_getparam,
	[ 156 ] = PR_sched_setscheduler,
	[ 157 ] = PR_sched_getscheduler,
	[ 158 ] = PR_sched_yield,
	[ 159 ] = PR_sched_get_priority_max,
	[ 160 ] = PR_sched_get_priority_min,
	[ 161 ] = PR_sched_rr_get_interval,
	[ 162 ] = PR_nanosleep,
	[ 163 ] = PR_mremap,
	[ 164 ] = PR_setresuid,
	[ 165 ] = PR_getresuid,
	[ 168 ] = PR_poll,
	[ 169 ] = PR_nfsservctl,
	[ 170 ] = PR_setresgid,
	[ 171 ] = PR_getresgid,
	[ 172 ] = PR_prctl,
	[ 173 ] = PR_rt_sigreturn,
	[ 174 ] = PR_rt_sigaction,
	[ 175 ] = PR_rt_sigprocmask,
	[ 176 ] = PR_rt_sigpending,
	[ 177 ] = PR_rt_sigtimedwait,
	[ 178 ] = PR_rt_sigqueueinfo,
	[ 179 ] = PR_rt_sigsuspend,
	[ 180 ] = PR_pread64,
	[ 181 ] = PR_pwrite64,
	[ 182 ] = PR_chown,
	[ 183 ] = PR_getcwd,
	[ 184 ] = PR_capget,
	[ 185 ] = PR_capset,
	[ 186 ] = PR_sigaltstack,
	[ 187 ] = PR_sendfile,
	[ 190 ] = PR_vfork,
	[ 191 ] = PR_ugetrlimit,
	[ 192 ] = PR_mmap2,
	[ 193 ] = PR_truncate64,
	[ 194 ] = PR_ftruncate64,
	[ 195 ] = PR_stat64,
	[ 196 ] = PR_lstat64,
	[ 197 ] = PR_fstat64,
	[ 198 ] = PR_lchown32,
	[ 199 ] = PR_getuid32,
	[ 200 ] = PR_getgid32,
	[ 201 ] = PR_geteuid32,
	[ 202 ] = PR_getegid32,
	[ 203 ] = PR_setreuid32,
	[ 204 ] = PR_setregid32,
	[ 205 ] = PR_getgroups32,
	[ 206 ] = PR_setgroups32,
	[ 207 ] = PR_fchown32,
	[ 208 ] = PR_setresuid32,
	[ 209 ] = PR_getresuid32,
	[ 210 ] = PR_setresgid32,
	[ 211 ] = PR_getresgid32,
	[ 212 ] = PR_chown32,
	[ 213 ] = PR_setuid32,
	[ 214 ] = PR_setgid32,
	[ 215 ] = PR_setfsuid32,
	[ 216 ] = PR_setfsgid32,
	[ 217 ] = PR_getdents64,
	[ 218 ] = PR_pivot_root,
	[ 219 ] = PR_mincore,
	[ 220 ] = PR_madvise,
	[ 221 ] = PR_fcntl64,
	[ 222 ] = PR_void,
	[ 224 ] = PR_gettid,
	[ 225 ] = PR_readahead,
	[ 226 ] = PR_setxattr,
	[ 227 ] = PR_lsetxattr,
	[ 228 ] = PR_fsetxattr,
	[ 229 ] = PR_getxattr,
	[ 230 ] = PR_lgetxattr,
	[ 231 ] = PR_fgetxattr,
	[ 232 ] = PR_listxattr,
	[ 233 ] = PR_llistxattr,
	[ 234 ] = PR_flistxattr,
	[ 235 ] = PR_removexattr,
	[ 236 ] = PR_lremovexattr,
	[ 237 ] = PR_fremovexattr,
	[ 238 ] = PR_tkill,
	[ 239 ] = PR_sendfile64,
	[ 240 ] = PR_futex,
	[ 241 ] = PR_sched_setaffinity,
	[ 242 ] = PR_sched_getaffinity,
	[ 243 ] = PR_io_setup,
	[ 244 ] = PR_io_destroy,
	[ 245 ] = PR_io_getevents,
	[ 246 ] = PR_io_submit,
	[ 247 ] = PR_io_cancel,
	[ 248 ] = PR_exit_group,
	[ 249 ] = PR_lookup_dcookie,
	[ 250 ] = PR_epoll_create,
	[ 251 ] = PR_epoll_ctl,
	[ 252 ] = PR_epoll_wait,
	[ 253 ] = PR_remap_file_pages,
	[ 256 ] = PR_set_tid_address,
	[ 257 ] = PR_timer_create,
	[ 258 ] = PR_timer_settime,
	[ 259 ] = PR_timer_gettime,
	[ 260 ] = PR_timer_getoverrun,
	[ 261 ] = PR_timer_delete,
	[ 262 ] = PR_clock_settime,
	[ 263 ] = PR_clock_gettime,
	[ 264 ] = PR_clock_getres,
	[ 265 ] = PR_clock_nanosleep,
	[ 266 ] = PR_statfs64,
	[ 267 ] = PR_fstatfs64,
	[ 268 ] = PR_tgkill,
	[ 269 ] = PR_utimes,
	[ 270 ] = PR_arm_fadvise64_64,
	[ 271 ] = PR_pciconfig_iobase,
	[ 272 ] = PR_pciconfig_read,
	[ 273 ] = PR_pciconfig_write,
	[ 274 ] = PR_mq_open,
	[ 275 ] = PR_mq_unlink,
	[ 276 ] = PR_mq_timedsend,
	[ 277 ] = PR_mq_timedreceive,
	[ 278 ] = PR_mq_notify,
	[ 279 ] = PR_mq_getsetattr,
	[ 280 ] = PR_waitid,
	[ 281 ] = PR_socket,
	[ 282 ] = PR_bind,
	[ 283 ] = PR_connect,
	[ 284 ] = PR_listen,
	[ 285 ] = PR_accept,
	[ 286 ] = PR_getsockname,
	[ 287 ] = PR_getpeername,
	[ 288 ] = PR_socketpair,
	[ 289 ] = PR_send,
	[ 290 ] = PR_sendto,
	[ 291 ] = PR_recv,
	[ 292 ] = PR_recvfrom,
	[ 293 ] = PR_shutdown,
	[ 294 ] = PR_setsockopt,
	[ 295 ] = PR_getsockopt,
	[ 296 ] = PR_sendmsg,
	[ 297 ] = PR_recvmsg,
	[ 298 ] = PR_semop,
	[ 299 ] = PR_semget,
	[ 300 ] = PR_semctl,
	[ 301 ] = PR_msgsnd,
	[ 302 ] = PR_msgrcv,
	[ 303 ] = PR_msgget,
	[ 304 ] = PR_msgctl,
	[ 305 ] = PR_shmat,
	[ 306 ] = PR_shmdt,
	[ 307 ] = PR_shmget,
	[ 308 ] = PR_shmctl,
	[ 309 ] = PR_add_key,
	[ 310 ] = PR_request_key,
	[ 311 ] = PR_keyctl,
	[ 312 ] = PR_semtimedop,
	[ 313 ] = PR_vserver,
	[ 314 ] = PR_ioprio_set,
	[ 315 ] = PR_ioprio_get,
	[ 316 ] = PR_inotify_init,
	[ 317 ] = PR_inotify_add_watch,
	[ 318 ] = PR_inotify_rm_watch,
	[ 319 ] = PR_mbind,
	[ 320 ] = PR_get_mempolicy,
	[ 321 ] = PR_set_mempolicy,
	[ 322 ] = PR_openat,
	[ 323 ] = PR_mkdirat,
	[ 324 ] = PR_mknodat,
	[ 325 ] = PR_fchownat,
	[ 326 ] = PR_futimesat,
	[ 327 ] = PR_fstatat64,
	[ 328 ] = PR_unlinkat,
	[ 329 ] = PR_renameat,
	[ 330 ] = PR_linkat,
	[ 331 ] = PR_symlinkat,
	[ 332 ] = PR_readlinkat,
	[ 333 ] = PR_fchmodat,
	[ 334 ] = PR_faccessat,
	[ 335 ] = PR_pselect6,
	[ 336 ] = PR_ppoll,
	[ 337 ] = PR_unshare,
	[ 338 ] = PR_set_robust_list,
	[ 339 ] = PR_get_robust_list,
	[ 340 ] = PR_splice,
	[ 341 ] = PR_arm_sync_file_range,
	[ 342 ] = PR_tee,
	[ 343 ] = PR_vmsplice,
	[ 344 ] = PR_move_pages,
	[ 345 ] = PR_getcpu,
	[ 346 ] = PR_epoll_pwait,
	[ 347 ] = PR_kexec_load,
	[ 348 ] = PR_utimensat,
	[ 349 ] = PR_signalfd,
	[ 350 ] = PR_timerfd_create,
	[ 351 ] = PR_eventfd,
	[ 352 ] = PR_fallocate,
	[ 353 ] = PR_timerfd_settime,
	[ 354 ] = PR_timerfd_gettime,
	[ 355 ] = PR_signalfd4,
	[ 356 ] = PR_eventfd2,
	[ 357 ] = PR_epoll_create1,
	[ 358 ] = PR_dup3,
	[ 359 ] = PR_pipe2,
	[ 360 ] = PR_inotify_init1,
	[ 361 ] = PR_preadv,
	[ 362 ] = PR_pwritev,
	[ 363 ] = PR_rt_tgsigqueueinfo,
	[ 364 ] = PR_perf_event_open,
	[ 365 ] = PR_recvmmsg,
	[ 366 ] = PR_accept4,
	[ 367 ] = PR_fanotify_init,
	[ 368 ] = PR_fanotify_mark,
	[ 369 ] = PR_prlimit64,
	[ 370 ] = PR_name_to_handle_at,
	[ 371 ] = PR_open_by_handle_at,
	[ 372 ] = PR_clock_adjtime,
	[ 373 ] = PR_syncfs,
	[ 374 ] = PR_sendmmsg,
	[ 375 ] = PR_setns,
	[ 376 ] = PR_process_vm_readv,
	[ 377 ] = PR_process_vm_writev,
	[ 378 ] = PR_kcmp,
	[ 379 ] = PR_finit_module,
	[ 380 ] = PR_sched_setattr,
	[ 381 ] = PR_sched_getattr,
	[ 382 ] = PR_renameat2,
/* */
        [ 383 ] =  PR_seccomp,
        [ 384 ] =  PR_getrandom,
        [ 385 ] =  PR_memfd_create,
        [ 386 ] =  PR_bpf,
        [ 387 ] =  PR_execveat,
        [ 388 ] =  PR_userfaultfd,
        [ 389 ] =  PR_membarrier,
        [ 390 ] =  PR_mlock2,
        [ 391 ] =  PR_copy_file_range,
        [ 392 ] =  PR_preadv2,
        [ 393 ] =  PR_pwritev2,
        [ 394 ] =  PR_pkey_mprotect,
        [ 395 ] =  PR_pkey_alloc,
        [ 396 ] =  PR_pkey_free,
        [ 397 ] =  PR_statx,
};
