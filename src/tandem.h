/*
 * tandem.h
 *
 */

#ifndef _EGG_TANDEM_H
#define _EGG_TANDEM_H

/* Keep track of tandem-bots in the chain */
typedef struct tand_t_struct {
  char bot[HANDLEN + 1];
  char *not_chans;
  struct tand_t_struct *via;
  struct tand_t_struct *uplink;
  struct tand_t_struct *next;
  char *version;
  time_t buildts;
  int localhub;
  char share;
} tand_t;

/* Keep track of party-line members */
typedef struct {
  char nick[HANDLEN + 1];
  char bot[HANDLEN + 1];
  int sock;
  int chan;
  char *from;
  char flag;
  char status;
  time_t timer;			/* Track idle time */
  char *away;
} party_t;

/* Status: */
#define PLSTAT_AWAY   0x001
#define IS_PARTY      0x002

/* Minimum version that uses tokens & base64 ints
 * for channel msg's
 */
#define NEAT_BOTNET 1000000
#define GLOBAL_CHANS 100000


void botnet_send_chan(int, char *, char *, int, char *);
void botnet_send_chat(int, char *, char *);
void botnet_send_act(int, char *, char *, int, char *);
void botnet_send_ping(int);
void botnet_send_pong(int);
void botnet_send_priv (int, ...);
void botnet_send_who(int, char *, char *, int);
void botnet_send_infoq(int, char *);
void botnet_send_unlinked(int, char *, char *);
void botnet_send_traced(int, char *, char *);
void botnet_send_trace(int, char *, char *, char *);
void botnet_send_unlink(int, char *, char *, char *, char *);
void botnet_send_link(int, char *, char *, char *);
void botnet_send_update(int, tand_t *);
void botnet_send_nlinked(int, char *, char *, char, int, time_t, char *);
void botnet_send_reject(int, char *, char *, char *, char *, char *);
void botnet_send_zapf(int, char *, char *, char *);
void botnet_send_zapf_broad(int, char *, char *, char *);
void botnet_send_away(int, char *, int, char *, int);
void botnet_send_idle(int, char *, int, int, char *);
void botnet_send_join_idx(int, int);
void botnet_send_join_party(int, int, int, int);
void botnet_send_part_idx(int, char *);
void botnet_send_part_party(int, int, char *, int);
void botnet_send_bye();
void botnet_send_nkch_part(int, int, char *);
void botnet_send_nkch(int, char *);
int bots_in_subtree(tand_t *);
int users_in_subtree(tand_t *);
int botnet_send_cmd(char * fbot, char * bot, char * from, int fromidx, char * cmd);
void botnet_send_cmd_broad(int idx, char * fbot, char * from, int fromidx, char * cmd);
void botnet_send_cmdreply(char * fbot, char * bot, char * to, char * toidx, char * ln);

#define b_status(a)	(dcc[a].status)

#endif				/* _EGG_TANDEM_H */
