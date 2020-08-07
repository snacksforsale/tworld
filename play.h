/* play.c: Functions to drive game-play and manage the game state.
 *
 * Copyright (C) 2001-2004 by Brian Raiter, under the GNU General Public
 * License. No warranty. See COPYING for details.
 */

#ifndef	_play_h_
#define	_play_h_

#include	"defs.h"

/* The different modes of the program with respect to gameplay.
 */
enum { BeginPlay, EndPlay, SuspendPlay, ResumePlay, BeginVerify, EndVerify,
       BeginInput, EndInput };

/* Change the current gameplay mode. This affects the running of the
 * timer and the handling of the keyboard.
 */
extern void setgameplaymode(int mode);

/* Initialize the current state to the starting position of the
 * given level.
 */
extern int initgamestate(gamesetup *game, int ruleset);

/* Set up the current state to play from its prerecorded solution.
 * FALSE is returned if no solution is available for playback.
 */
extern int prepareplayback(void);

extern int setstepping(int stepping, int display);
extern int changestepping(int delta, int display);

/* Return the amount of time passed in the current game, in seconds.
 */
extern int secondsplayed(void);

/* Handle one tick of the game. cmd is the current keyboard command
 * supplied by the user, or CmdPreserve if any pending command is to
 * be retained. The return value is positive if the game was completed
 * successfully, negative if the game ended unsuccessfully, and zero
 * if the game remains in progress.
 */
extern int doturn(int cmd);

/* Update the display during game play. If showframe is FALSE, then
 * nothing is actually displayed.
 */
extern int drawscreen(int showframe);

/* Quit game play early.
 */
extern int quitgamestate(void);

/* Free any resources associates with the current game state.
 */
extern int endgamestate(void);

/* Free all persistent resources in the module.
 */
extern void shutdowngamestate(void);

/* Return TRUE if a solution exists for the given level.
 */
extern int hassolution(gamesetup const *game);

/* Replace the user's solution with the just-executed solution if it
 * beats the existing solution for shortest time. FALSE is returned if
 * nothing was changed.
 */
extern int replacesolution(void);

/* Double-checks the timing for a solution that has just been played
 * back. If the timing is incorrect, but the cause of the discrepancy
 * can be reasonably ascertained to be benign, the timings will be
 * corrected and the return value will be TRUE.
 */
extern int checksolution(void);

/* Slow down the game clock by the given factor. Used for debugging
 * purposes.
 */
extern int setmudsuckingfactor(int mud);

#endif
