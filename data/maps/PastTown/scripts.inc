PastTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PastTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PastTown_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PastTown_OnResume
	.byte 0

PastTown_OnTransition:
	call_if_eq VAR_CUTSCENE_STATE, 7, PastTown_EventScript_LassPlacement
	end

PastTown_EventScript_LassPlacement::
	setobjectxyperm LOCALID_PASTTOWN_LASS, 46, 9
	setobjectmovementtype LOCALID_PASTTOWN_LASS, MOVEMENT_TYPE_FACE_DOWN
	return

PastTown_OnFrame:
	map_script_2 VAR_CUTSCENE_STATE, 5, PastTown_EventScript_LookerEnters
	.2byte 0

PastTown_EventScript_LookerEnters::
	lockall
	speakername Name_Looker
	msgbox PastTown_Text_LookerWhatIsThis, MSGBOX_DEFAULT
	closemessage
	delay 40
	fadescreen FADE_TO_BLACK
	delay 40
	playse SE_EFFECTIVE
	delay 10
	speakername Name_Looker
	msgbox PastTown_Text_LookerYowch, MSGBOX_DEFAULT
	delay 30
	closemessage
	delay 30
	fadescreen FADE_FROM_BLACK
	delay 60
	speakername Name_Looker
	msgbox PastTown_Text_LookerImNotDreaming, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, PastTown_Movement_LookerLookAround
	waitmovement 0
	speakername Name_Looker
	msgbox PastTown_Text_LookerOutOfTheWoods, MSGBOX_DEFAULT
	closemessage
	setvar VAR_CUTSCENE_STATE, 6
	releaseall
	end
	
PastTown_OnResume:
	special HealPlayerParty
	end

PastTown_EventScript_Lass::
	lock
	faceplayer
	goto_if_eq VAR_CUTSCENE_STATE, 7, PastTown_EventScript_LassFight
	speakername Name_Lass
	msgbox PastTown_Text_LassYouCheated, MSGBOX_DEFAULT
	closemessage
	release
	end

PastTown_EventScript_LassTurnLeft::
	lock
	playse SE_PIN
	applymovement LOCALID_PASTTOWN_LASS, Common_Movement_FaceLeftExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	delay 48
	setflag FLAG_SYS_FROM_TRIGGER
	goto PastTown_EventScript_LassFight
	end

PastTown_EventScript_LassTurnRight::
	lock
	playse SE_PIN
	applymovement LOCALID_PASTTOWN_LASS, Common_Movement_FaceRightExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	delay 48
	setflag FLAG_SYS_FROM_TRIGGER
	goto PastTown_EventScript_LassFight
	end

PastTown_EventScript_LassWalkRight::
	lock
	playse SE_PIN
	applymovement LOCALID_PASTTOWN_LASS, Common_Movement_FaceRightExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	delay 48
	applymovement LOCALID_PASTTOWN_LASS, Common_Movement_WalkRight
	waitmovement 0
	setflag FLAG_SYS_FROM_TRIGGER
	goto PastTown_EventScript_LassFight
	end

PastTown_EventScript_LassFight::
	setflag FLAG_SYS_NO_WHITEOUT
	call_if_set FLAG_FOUGHT_LASS, PastTown_EventScript_LassAnotherRound
	call_if_unset FLAG_FOUGHT_LASS, PastTown_EventScript_LassOyGeezer
	trainerbattle_no_intro TRAINER_MARIE, PastTown_Text_LassLoss
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PastTown_EventScript_BeatLass
	special HealPlayerParty
	speakername Name_Lass
	msgbox PastTown_Text_LassNobodyCanBeatMe, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	call_if_eq VAR_TEMP_1, 48, PastTown_EventScript_LassWalkBackToPosition
	call_if_set FLAG_SYS_FROM_TRIGGER, PastTown_EventScript_WalkBackBelowTrigger
	applymovement LOCALID_PASTTOWN_LASS, Common_Movement_FaceDown
	release
	end

PastTown_EventScript_LassWalkBackToPosition::
	applymovement LOCALID_PASTTOWN_LASS, Common_Movement_WalkLeft
	return
	
PastTown_EventScript_LassOyGeezer::
	setflag FLAG_FOUGHT_LASS
	speakername Name_Lass
	msgbox PastTown_Text_LassOyGeezer, MSGBOX_DEFAULT
	return

PastTown_EventScript_LassAnotherRound::
	speakername Name_Lass
	msgbox PastTown_Text_LassAnotherRound, MSGBOX_DEFAULT
	return

PastTown_EventScript_BeatLass::
	speakername Name_Lass
	msgbox PastTown_Text_LassHeyNoFair, MSGBOX_DEFAULT
	speak LOCALID_PLAYER, DIR_SOUTH, Name_Looker, PastTown_Text_LookerThatWasStrange
	closemessage
	setvar VAR_CUTSCENE_STATE, 8
	release
	end

PastTown_EventScript_WalkBackBelowTrigger::
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	clearflag FLAG_SYS_FROM_TRIGGER
	return

PastTown_EventScript_LookerPassOut::
	lockall
	speakername Name_Looker
	msgbox PastTown_Text_LookerUrgh, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	warpsilent MAP_PAST_TOWN_HALL, 2, 2
	delay 48
	end

PastTown_Movement_LookerLookAround:
	walk_down
	delay_16
	delay_16
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

PastTown_Text_LassHeyNoFair:
	.string "What sorcery was that!?\p"
	.string "I have never seen a battler with\n"
	.string "perfect prediction skills such as\l"
	.string "yours!\p"
	.string "Old man, you must be cheating!$"

PastTown_Text_LookerThatWasStrange:
	.string "That was odd…\p"
	.string "Did I see into the future just now?$"
	
PastTown_Text_LassNobodyCanBeatMe:
	.string "Ha! There is not a soul in this\n"
	.string "town who can stand up to me!$"

PastTown_Text_LassYouCheated:
	.string "I may not know how, but you\n"
	.string "CERTAINLY cheated in our fight!\p"
	.string "Cheater!$"

PastTown_Text_LassOyGeezer:
	.string "Oy, geezer!\p"
	.string "You must be an outsider to our\n"
	.string "village!\p"
	.string "Know this, there is nobody\n"
	.string "in this village stronger than\l"
	.string "I in Pokémon battles!\p"
	.string "If you wish to pass through to\n"
	.string "the Shrine of Prosperity, then\l"
	.string "show me your strength!$"

PastTown_Text_LassAnotherRound:
	.string "Are you ready for another round,\n"
	.string "old man?\p"
	.string "Let's fight!$"

PastTown_Text_LookerUrgh:
	.string "Urrrrggghhh…$"

PastTown_Text_LookerImNotDreaming:
	.string "Alright, I am definitely\n"
	.string "not dreaming!$"

PastTown_Text_LookerOutOfTheWoods:
	.string "Not sure where this is, but\n"
	.string "no matter.\p"
	.string "I need to get to a Pokémon Center\n"
	.string "and treat this pain pronto…$"

PastTown_Text_LookerWhatIsThis:
	.string "What…?\p"
	.string "Where am I…?\p"
	.string "I'm positive the city is supposed\n"
	.string "to be right here.\p"
	.string "I'm not dreaming, am I?$"

PastTown_Text_LookerYowch:
	.string "YOWCH!!!$"

PastTown_Text_LassLoss:
	.string "Impossible!\n"
	.string "It was like you knew my every move!$"