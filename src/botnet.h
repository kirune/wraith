#ifndef _BOTNET_H
#define _BOTNET_H

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include "tandem.h"

#ifndef MAKING_MODS

extern tand_t		*tandbot;
extern party_t		*party;
extern int		tands;

void restart_chons();
void lower_bot_linked(int idx);
void higher_bot_linked(int idx);
void answer_local_whom(int, int);
char *lastbot(char *);
int nextbot(char *);
int in_chain(char *);
void tell_bots(int);
void tell_bottree(int, int);
int botlink(char *, int, char *);
int botunlink(int, char *, char *);
void dump_links(int);
void addbot(char *, char *, char *, char, int);
void updatebot(int, char *, char, int);
void rembot(char *);
struct tand_t_struct *findbot(char *);
void unvia(int, struct tand_t_struct *);
void check_botnet_pings();
int partysock(char *, char *);
int addparty(char *, char *, int, char, int, char *, int *);
void remparty(char *, int);
void partystat(char *, int, int, int);
int partynick(char *, int, char *);
int partyidle(char *, char *);
void partysetidle(char *, int, int);
void partyaway(char *, int, char *);
#ifdef S_DCCPASS
void botnet_send_cmdpass(int, char *, char *);
#endif /* S_DCCPASS */
void zapfbot(int);
void tandem_relay(int, char *, int);
int getparty(char *, int);
#endif /* !MAKING_MODS */

#endif /* !_BOTNET_H */
