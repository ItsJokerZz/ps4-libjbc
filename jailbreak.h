#pragma once
#include <stdint.h>
#include "defs.h"

struct jbc_cred
{
    uid_t uid;
    uid_t ruid;
    uid_t svuid;
    gid_t rgid;
    gid_t svgid;
    uintptr_t prison;
    uintptr_t cdir;
    uintptr_t rdir;
    uintptr_t jdir;
    uint64_t sceProcType;
    uint64_t sonyCred;
    uint64_t sceProcCap;
};

extern int jailbroken;

struct jbc_jail_state
{
    struct jbc_cred original;
    struct jbc_cred root;
};

uintptr_t jbc_get_prison0(void);
uintptr_t jbc_get_rootvnode(void);
int jbc_get_cred(struct jbc_cred *);
int jbc_jailbreak_cred(struct jbc_cred *);
int jbc_set_cred(const struct jbc_cred *);
int jbc_jailbreak(struct jbc_jail_state *state);
int jbc_unjailbreak(struct jbc_jail_state *state);