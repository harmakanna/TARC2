PastTown_Port_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PastTown_Port_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PastTown_Port_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PastTown_Port_OnResume
	.byte 0

PastTown_Port_OnLoad:
	call PastTown_Port_EventScript_ResetPortMons
	returnqueststate QUEST_INVESTIGATE_PROSPERITY
	call_if_eq VAR_RESULT, 4, PastTown_Port_EventScript_CheckSpawnCatchMon
	end

PastTown_Port_EventScript_ResetPortMons::
	setflag FLAG_HIDE_PORT_DHELMISE
	setflag FLAG_HIDE_PORT_GRAPPLOCT
	setflag FLAG_HIDE_PORT_CRABOMINABLE
	setflag FLAG_HIDE_PORT_PALOSSAND
	setflag FLAG_HIDE_PORT_PHIONE
	setvar VAR_RESEED_PORT_MON, 0
	return

PastTown_Port_EventScript_CheckSpawnCatchMon::
	call_if_lt VAR_PORT_MONS_CAUGHT, 5, PastTown_Port_EventScript_TrySpawnCatchMon
	return

PastTown_Port_EventScript_TrySpawnCatchMon::
	randompercentage 10
	call_if_eq VAR_RESULT, TRUE, PastTown_Port_EventScript_SpawnPortMon
	return

PastTown_Port_EventScript_SpawnPortMon::
	randomelement SPECIES_DHELMISE, SPECIES_GRAPPLOCT, SPECIES_CRABOMINABLE, SPECIES_PALOSSAND, SPECIES_PHIONE
	call_if_eq VAR_RESULT, SPECIES_DHELMISE, PastTown_Port_EventScript_TrySpawnDhelmise
	call_if_eq VAR_RESULT, SPECIES_GRAPPLOCT, PastTown_Port_EventScript_TrySpawnGrapploct
	call_if_eq VAR_RESULT, SPECIES_CRABOMINABLE, PastTown_Port_EventScript_TrySpawnCrabominable
	call_if_eq VAR_RESULT, SPECIES_PALOSSAND, PastTown_Port_EventScript_TrySpawnPalossand
	call_if_eq VAR_RESULT, SPECIES_PHIONE, PastTown_Port_EventScript_TrySpawnPhione
	return

PastTown_Port_EventScript_ReseedPortMon::
	addvar VAR_RESEED_PORT_MON, 1
	call_if_lt VAR_RESEED_PORT_MON, 10, PastTown_Port_EventScript_SpawnPortMon
	return

PastTown_Port_EventScript_TrySpawnDhelmise::
	call_if_set FLAG_CAUGHT_DHELMISE, PastTown_Port_EventScript_ReseedPortMon
	call_if_unset FLAG_CAUGHT_DHELMISE, PastTown_Port_EventScript_SpawnDhelmise
	return

PastTown_Port_EventScript_SpawnDhelmise::
	clearflag FLAG_HIDE_PORT_DHELMISE
	return

PastTown_Port_EventScript_TrySpawnGrapploct::
	call_if_set FLAG_CAUGHT_GRAPPLOCT, PastTown_Port_EventScript_ReseedPortMon
	call_if_unset FLAG_CAUGHT_GRAPPLOCT, PastTown_Port_EventScript_TrySpawnGrapploct
	return

PastTown_Port_EventScript_SpawnGrapploct::
	clearflag FLAG_HIDE_PORT_GRAPPLOCT
	return

PastTown_Port_EventScript_TrySpawnCrabominable::
	call_if_set FLAG_CAUGHT_CRABOMINABLE, PastTown_Port_EventScript_ReseedPortMon
	call_if_unset FLAG_CAUGHT_CRABOMINABLE, PastTown_Port_EventScript_SpawnCrabominable
	return

PastTown_Port_EventScript_SpawnCrabominable::
	clearflag FLAG_HIDE_PORT_CRABOMINABLE
	return

PastTown_Port_EventScript_TrySpawnPalossand::
	call_if_set FLAG_CAUGHT_PALOSSAND, PastTown_Port_EventScript_ReseedPortMon
call_if_unset FLAG_CAUGHT_PALOSSAND, PastTown_Port_EventScript_SpawnPalossand
	return

PastTown_Port_EventScript_SpawnPalossand::
	clearflag FLAG_HIDE_PORT_PALOSSAND
	return

PastTown_Port_EventScript_TrySpawnPhione::
	call_if_set FLAG_CAUGHT_PHIONE, PastTown_Port_EventScript_ReseedPortMon
	call_if_unset FLAG_CAUGHT_PHIONE, PastTown_Port_EventScript_SpawnPhione
	return

PastTown_Port_EventScript_SpawnPhione::
	clearflag FLAG_HIDE_PORT_PHIONE
	return

PastTown_Port_OnTransition:
	returnqueststate QUEST_SENTIMENTAL
	call_if_eq VAR_RESULT, 2, PastTown_Port_EventScript_ResetHeartScaleSparkle
	@call PastTown_Port_EventScript_ResetPortMons
	@eturnqueststate QUEST_INVESTIGATE_PROSPERITY
	@call_if_eq VAR_RESULT, 4, PastTown_Port_EventScript_CheckSpawnCatchMon
	end

PastTown_Port_EventScript_ResetHeartScaleSparkle::
	setvar VAR_HEART_SCALE_SPARKLE, 1
	return

PastTown_Port_EventScript_DoHeartScaleSparkle::
	lockall
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_FaceDownQuestionMark
	delay 50
	msgbox Looker_Text_WhatsThat, MSGBOX_DEFAULT
	closemessage
	delay 10
	dofieldeffectsparkle 12, 17, 0
	waitfieldeffect FLDEFF_SPARKLE
	delay 20
	setvar VAR_HEART_SCALE_SPARKLE, 2
	releaseall
	end

PastTown_Port_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, PastTown_Port_EventScript_TryRemovePortMon
	end

PastTown_Port_EventScript_TryRemovePortMon::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

PastTown_Port_EventScript_HiddenHeartScale::
	goto_if_eq VAR_HEART_SCALE_SPARKLE, 2, PastTown_Port_EventScript_GiveHeartScale
	end

PastTown_Port_EventScript_GiveHeartScale::
	lock
	waitse
	giveitem ITEM_HEART_SCALE
	setvar VAR_HEART_SCALE_SPARKLE, 3
	questmenu QUEST_MENU_SET_REWARD, QUEST_SENTIMENTAL
	closemessage
	release
	end

PastTown_Port_EventScript_WingFossil::
	lockall
	msgbox PastTown_Port_Text_TakeWingFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PastTown_Port_EventScript_LeaveWingFossil
	giveitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_HIDE_WING_FOSSIL
	removeobject LOCALID_WING_FOSSIL
	delay 30
	setflag FLAG_CHOSE_WING_FOSSIL
	goto PastTown_Port_EventScript_PokemaniacChoosesTuskFossil
	end

PastTown_Port_EventScript_LeaveWingFossil::
	msgbox PastTown_Port_Text_LeftWingFossilAlone, MSGBOX_DEFAULT
	release
	end

PastTown_Port_EventScript_TuskFossil::
	lockall
	faceplayer
	msgbox PastTown_Port_Text_TakeTuskFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PastTown_Port_EventScript_LeaveTuskFossil
	giveitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_HIDE_TUSK_FOSSIL
	removeobject LOCALID_TUSK_FOSSIL
	delay 30
	setflag FLAG_CHOSE_TUSK_FOSSIL
	goto PastTown_Port_EventScript_PokemaniacChoosesWingFossil
	end

PastTown_Port_EventScript_LeaveTuskFossil::
	msgbox PastTown_Port_Text_LeftTuskFossilAlone, MSGBOX_DEFAULT
	release
	end

PastTown_Port_ManiacTrigger1::
	lockall
	playbgm MUS_ENCOUNTER_SUSPICIOUS, FALSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	playse SE_PIN
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, Common_Movement_FaceDownExclamationMark
	message PastTown_Port_Text_ManiacNo
	waitmessage
	delay 80
	closemessage
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, PastTown_Port_Movement_PokemaniacToPlayer1
	waitmovement 0
	setobjectxyperm LOCALID_PASTTOWN_PORT_MANIAC, 18, 19
	goto PastTown_Port_EventScript_TriggerPokemaniacFight
	end

PastTown_Port_ManiacTrigger2::
	lockall
	playbgm MUS_ENCOUNTER_SUSPICIOUS, FALSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	playse SE_PIN
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, Common_Movement_FaceDownExclamationMark
	message PastTown_Port_Text_ManiacNo
	waitmessage
	delay 80
	closemessage
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, PastTown_Port_Movement_PokemaniacToPlayer2
	waitmovement 0
	setobjectxyperm LOCALID_PASTTOWN_PORT_MANIAC, 19, 19
	goto PastTown_Port_EventScript_TriggerPokemaniacFight
	end
	
PastTown_Port_ManiacTrigger3::
	lockall
	playbgm MUS_ENCOUNTER_SUSPICIOUS, FALSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	playse SE_PIN
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, Common_Movement_FaceDownExclamationMark
	message PastTown_Port_Text_ManiacNo
	waitmessage
	delay 80
	closemessage
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, PastTown_Port_Movement_PokemaniacToPlayer3
	waitmovement 0
	setobjectxyperm LOCALID_PASTTOWN_PORT_MANIAC, 20, 19
	goto PastTown_Port_EventScript_TriggerPokemaniacFight
	end
	
PastTown_Port_ManiacTrigger4::
	lockall
	playbgm MUS_ENCOUNTER_SUSPICIOUS, FALSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	playse SE_PIN
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, Common_Movement_FaceDownExclamationMark
	message PastTown_Port_Text_ManiacNo
	waitmessage
	delay 80
	closemessage
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, PastTown_Port_Movement_PokemaniacToPlayer4
	waitmovement 0
	setobjectxyperm LOCALID_PASTTOWN_PORT_MANIAC, 21, 19
	goto PastTown_Port_EventScript_TriggerPokemaniacFight
	end

PastTown_Port_Movement_PokemaniacToPlayer1:
	walk_left
	walk_down
	walk_down
	step_end

PastTown_Port_Movement_PokemaniacToPlayer2:
	walk_down
	walk_down
	step_end

PastTown_Port_Movement_PokemaniacToPlayer3:
	walk_right
	walk_down
	walk_down
	step_end

PastTown_Port_Movement_PokemaniacToPlayer4:
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

PastTown_Port_EventScript_TriggerPokemaniacFight::
	speakername Name_Past_Maniac
	msgbox PastTown_Port_Text_ManiacDoNotApproachThoseFossils, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_EVERETT, PastTown_Port_Text_EverettDefeated
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PastTown_Port_EventScript_RanFromManiac
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, PastTown_Port_EventScript_RanFromManiac
	speakername Name_Past_Maniac
	msgbox PastTown_Port_Text_ManiacOhFine, MSGBOX_DEFAULT
	closemessage
	setvar VAR_MANIAC_TRIGGER, 2
	releaseall
	end

PastTown_Port_EventScript_RanFromManiac::
	speak LOCALID_PASTTOWN_PORT_MANIAC, DIR_SOUTH, Name_Past_Maniac, PastTown_Port_Text_ManiacGetOut
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, PastTown_Port_Text_LookerDrat
	closemessage
	warp MAP_PAST_TOWN, 33, 38
	waitstate
	releaseall
	end
	
PastTown_Port_EventScript_PokemaniacChoosesTuskFossil::
	getobjectcurrentxy LOCALID_PASTTOWN_PORT_MANIAC, CURRENT_POSITION, VAR_0x8000, VAR_0x8001
	call_if_eq VAR_0x8000, 18, PastTown_Port_EventScript_PokemaniacMovesToTusk1
	call_if_eq VAR_0x8000, 19, PastTown_Port_EventScript_PokemaniacMovesToTusk2
	call_if_eq VAR_0x8000, 20, PastTown_Port_EventScript_PokemaniacMovesToTusk3
	call_if_eq VAR_0x8000, 21, PastTown_Port_EventScript_PokemaniacMovesToTusk4
	speakername Name_Past_Maniac
	msgbox PastTown_Port_Text_PokemaniacIllChooseTusk, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_TUSK_FOSSIL
	removeobject LOCALID_TUSK_FOSSIL
	setobjectxyperm LOCALID_PASTTOWN_PORT_MANIAC, 18, 19
	goto PastTown_Port_EventScript_FinishFossilSelection
	end

PastTown_Port_EventScript_PokemaniacMovesToTusk1::
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, PastTown_Port_Movemenet_PokemaniacToTusk1
	waitmovement 0
	return

PastTown_Port_Movemenet_PokemaniacToTusk1:
	walk_down
	face_left
	step_end

PastTown_Port_EventScript_PokemaniacMovesToTusk2::
	call_if_eq VAR_0x8001, 16, PastTown_Port_EventScript_PokemaniacMovesToTuskFromTop
	call_if_eq VAR_0x8001, 18, PastTown_Port_EventScript_PokemaniacMovesToTuskFromLow
	return

PastTown_Port_EventScript_PokemaniacMovesToTuskFromTop::
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, PastTown_Port_Movemenet_PokemaniacToTusk2Top
	waitmovement 0
	return

PastTown_Port_EventScript_PokemaniacMovesToTuskFromLow::
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, PastTown_Port_Movemenet_PokemaniacToTusk2Low
	waitmovement 0
	return

PastTown_Port_Movemenet_PokemaniacToTusk2Low:
	walk_down
	walk_left
	step_end

PastTown_Port_Movemenet_PokemaniacToTusk2Top:
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

PastTown_Port_EventScript_PokemaniacMovesToTusk3::
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, PastTown_Port_Movemenet_PokemaniacToTusk3
	waitmovement 0
	return

PastTown_Port_Movemenet_PokemaniacToTusk3:
	walk_left
	walk_left
	walk_down
	face_left
	step_end

PastTown_Port_EventScript_PokemaniacMovesToTusk4::
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, PastTown_Port_Movemenet_PokemaniacToTusk4
	waitmovement 0
	return

PastTown_Port_Movemenet_PokemaniacToTusk4:
	walk_left
	walk_left
	walk_left
	walk_down
	face_left
	step_end

PastTown_Port_EventScript_PokemaniacChoosesWingFossil::
	getobjectcurrentxy LOCALID_PASTTOWN_PORT_MANIAC, CURRENT_POSITION, VAR_0x8000, VAR_0x8001
	call_if_eq VAR_0x8000, 18, PastTown_Port_EventScript_PokemaniacMovesToWing1
	call_if_eq VAR_0x8000, 19, PastTown_Port_EventScript_PokemaniacMovesToWing2
	call_if_eq VAR_0x8000, 20, PastTown_Port_EventScript_PokemaniacMovesToWing3
	call_if_eq VAR_0x8000, 21, PastTown_Port_EventScript_PokemaniacMovesToWing4
	speakername Name_Past_Maniac
	msgbox PastTown_Port_Text_PokemaniacIllChooseWing, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_WING_FOSSIL
	removeobject LOCALID_WING_FOSSIL
	setobjectxyperm LOCALID_PASTTOWN_PORT_MANIAC, 21, 19
	goto PastTown_Port_EventScript_FinishFossilSelection
	end

PastTown_Port_EventScript_PokemaniacMovesToWing1::
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, PastTown_Port_Movemenet_PokemaniacToWing1
	waitmovement 0
	return

PastTown_Port_Movemenet_PokemaniacToWing1:
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

PastTown_Port_EventScript_PokemaniacMovesToWing2::
	call_if_eq VAR_0x8001, 16, PastTown_Port_EventScript_PokemaniacMovesToWingFromTop
	call_if_eq VAR_0x8001, 18, PastTown_Port_EventScript_PokemaniacMovesToWingFromLow
	return

PastTown_Port_EventScript_PokemaniacMovesToWingFromTop::
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, PastTown_Port_Movemenet_PokemaniacToWing2Top
	waitmovement 0
	return

PastTown_Port_EventScript_PokemaniacMovesToWingFromLow::
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, PastTown_Port_Movemenet_PokemaniacToWing2Low
	waitmovement 0
	return

PastTown_Port_Movemenet_PokemaniacToWing2Low:
	walk_right
	walk_right
	walk_down
	step_end

PastTown_Port_Movemenet_PokemaniacToWing2Top:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	face_down
	step_end

PastTown_Port_EventScript_PokemaniacMovesToWing3::
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, PastTown_Port_Movemenet_PokemaniacToWing3
	waitmovement 0
	return

PastTown_Port_Movemenet_PokemaniacToWing3:
	walk_right
	walk_down
	step_end

PastTown_Port_EventScript_PokemaniacMovesToWing4::
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, PastTown_Port_Movemenet_PokemaniacToWing4
	waitmovement 0
	return

PastTown_Port_Movemenet_PokemaniacToWing4:
	walk_down
	step_end


PastTown_Port_EventScript_FinishFossilSelection::
	delay 40
	speakername Name_Looker
	msgbox PastTown_Port_Text_LookerFossilRevive, MSGBOX_DEFAULT
	startquest QUEST_FORGOTTEN_TO_TIME
	closemessage
	setvar VAR_MANIAC_TRIGGER, 3
	releaseall
	end
	
PastTown_Port_EventScript_Pokemaniac::
	lock
	faceplayer
	goto_if_eq VAR_MANIAC_TRIGGER, 2, PastTown_Port_EventScript_PokemaniacSad
	goto_if_set FLAG_CHOSE_TUSK_FOSSIL, PastTown_Port_EventScript_PokemaniacChoseTuskFossil
	goto_if_set FLAG_CHOSE_WING_FOSSIL, PastTown_Port_EventScript_PokemaniacChoseWingFossil
	goto_if_set FLAG_SYS_MAIN_GAME_START, PastTown_Port_EventScript_PokemaniacOhFossils
	msgbox PastTown_Port_Text_ManiacLookingForFossils, MSGBOX_DEFAULT
	closemessage
	release
	end

PastTown_Port_EventScript_PokemaniacSad:
	speakername Name_Past_Maniac
	msgbox PastTown_Port_Text_ManiacOhFine, MSGBOX_DEFAULT
	closemessage
	release
	end
	
PastTown_Port_EventScript_PokemaniacOhFossils::
	speakername Name_Past_Maniac
	msgbox PastTown_Port_Text_ManiacOhFossils, MSGBOX_DEFAULT
	closemessage
	release
	end

PastTown_Port_EventScript_PokemaniacChoseWingFossil::
	speakername Name_Past_Maniac
	msgbox PastTown_Port_Text_ManiacChoseTuskFossil, MSGBOX_DEFAULT
	closemessage
	release
	end

PastTown_Port_EventScript_PokemaniacChoseTuskFossil::
	speakername Name_Past_Maniac
	msgbox PastTown_Port_Text_ManiacChoseWingFossil, MSGBOX_DEFAULT
	closemessage
	release
	end

PastTown_Port_EventScript_Dhelmise::
	lockall
	faceplayer
	waitse
	playmoncry SPECIES_DHELMISE, CRY_MODE_ENCOUNTER
	msgbox PastTown_Port_Text_Dhelmise, MSGBOX_DEFAULT
	waitmoncry
	createmon 1, 0, SPECIES_DHELMISE, 50, ITEM_METAL_COAT, 1, NATURE_ADAMANT, 0, MON_FEMALE, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, MOVE_ANCHOR_SHOT, MOVE_POWER_WHIP, MOVE_POLTERGEIST, MOVE_PROTECT
	closemessage
	setflag FLAG_SYS_NO_WHITEOUT
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_NO_WHITEOUT
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_2, SPECIES_DHELMISE
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PastTown_Port_EventScript_MonRanAway
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, PastTown_Port_EventScript_MonRanAway
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PastTown_Port_EventScript_MonRanAway
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PastTown_Port_EventScript_MonRanAway
	setflag FLAG_CAUGHT_DHELMISE
	addvar VAR_PORT_MONS_CAUGHT, 1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_CATCHMONS, 7
	returnqueststate QUEST_CATCHMONS
	call_if_ne VAR_RESULT, 4, CutsceneForest_EventScript_CheckCatchMonsCompleted
	releaseall
	end

PastTown_Port_EventScript_Grapploct::
	lockall
	faceplayer
	waitse
	playmoncry SPECIES_GRAPPLOCT, CRY_MODE_ENCOUNTER
	msgbox PastTown_Port_Text_Grapploct, MSGBOX_DEFAULT
	waitmoncry
	createmon 1, 0, SPECIES_GRAPPLOCT, 50, ITEM_BLACK_BELT, 1, NATURE_IMPISH, 0, MON_MALE, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, MOVE_CIRCLE_THROW, MOVE_LIQUIDATION, MOVE_OCTOLOCK, MOVE_PROTECT
	closemessage
	setflag FLAG_SYS_NO_WHITEOUT
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_NO_WHITEOUT
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_2, SPECIES_GRAPPLOCT
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PastTown_Port_EventScript_MonRanAway
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, PastTown_Port_EventScript_MonRanAway
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PastTown_Port_EventScript_MonRanAway
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PastTown_Port_EventScript_MonRanAway
	setflag FLAG_CAUGHT_GRAPPLOCT
	addvar VAR_PORT_MONS_CAUGHT, 1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_CATCHMONS, 8
	returnqueststate QUEST_CATCHMONS
	call_if_ne VAR_RESULT, 4, CutsceneForest_EventScript_CheckCatchMonsCompleted
	releaseall
	end

PastTown_Port_EventScript_Crabominable::
	lockall
	faceplayer
	waitse
	playmoncry SPECIES_CRABOMINABLE, CRY_MODE_ENCOUNTER
	msgbox PastTown_Port_Text_Crabominable, MSGBOX_DEFAULT
	waitmoncry
	createmon 1, 0, SPECIES_CRABOMINABLE, 50, ITEM_NEVER_MELT_ICE, 1, NATURE_JOLLY, 1, MON_MALE, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, MOVE_DRAIN_PUNCH, MOVE_ICE_HAMMER, MOVE_CRABHAMMER, MOVE_PROTECT
	closemessage
	setflag FLAG_SYS_NO_WHITEOUT
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_NO_WHITEOUT
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_2, SPECIES_CRABOMINABLE
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PastTown_Port_EventScript_MonRanAway
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, PastTown_Port_EventScript_MonRanAway
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PastTown_Port_EventScript_MonRanAway
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PastTown_Port_EventScript_MonRanAway
	setflag FLAG_CAUGHT_CRABOMINABLE
	addvar VAR_PORT_MONS_CAUGHT, 1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_CATCHMONS, 10
	returnqueststate QUEST_CATCHMONS
	call_if_ne VAR_RESULT, 4, CutsceneForest_EventScript_CheckCatchMonsCompleted
	releaseall
	end

PastTown_Port_EventScript_Palossand::
	lockall
	faceplayer
	waitse
	playmoncry SPECIES_PALOSSAND, CRY_MODE_ENCOUNTER
	msgbox PastTown_Port_Text_Palossand, MSGBOX_DEFAULT
	waitmoncry
	createmon 1, 0, SPECIES_PALOSSAND, 50, ITEM_SOFT_SAND, 1, NATURE_QUIET, 0, MON_FEMALE, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, MOVE_SHADOW_BALL, MOVE_EARTH_POWER, MOVE_SHORE_UP, MOVE_SANDSTORM
	closemessage
	setflag FLAG_SYS_NO_WHITEOUT
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_NO_WHITEOUT
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_2, SPECIES_PALOSSAND
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PastTown_Port_EventScript_PalossandRanAway
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, PastTown_Port_EventScript_PalossandRanAway
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PastTown_Port_EventScript_PalossandRanAway
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PastTown_Port_EventScript_PalossandRanAway
	setflag FLAG_CAUGHT_PALOSSAND
	addvar VAR_PORT_MONS_CAUGHT, 1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_CATCHMONS, 9
	returnqueststate QUEST_CATCHMONS
	call_if_ne VAR_RESULT, 4, CutsceneForest_EventScript_CheckCatchMonsCompleted
	releaseall
	end

PastTown_Port_EventScript_Phione::
	lockall
	faceplayer
	waitse
	playmoncry SPECIES_PHIONE, CRY_MODE_ENCOUNTER
	msgbox PastTown_Port_Text_Phione, MSGBOX_DEFAULT
	waitmoncry
	createmon 1, 0, SPECIES_PHIONE, 50, ITEM_MYSTIC_WATER, 1, NATURE_QUIRKY, 0, MON_FEMALE, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, MOVE_SCALD, MOVE_ICY_WIND, MOVE_ZEN_HEADBUTT, MOVE_PROTECT
	closemessage
	setflag FLAG_SYS_NO_WHITEOUT
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_NO_WHITEOUT
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_2, SPECIES_PHIONE
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PastTown_Port_EventScript_MonRanAway
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, PastTown_Port_EventScript_MonRanAway
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PastTown_Port_EventScript_MonRanAway
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PastTown_Port_EventScript_MonRanAway
	setflag FLAG_CAUGHT_PHIONE
	addvar VAR_PORT_MONS_CAUGHT, 1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_CATCHMONS, 15
	returnqueststate QUEST_CATCHMONS
	call_if_ne VAR_RESULT, 4, CutsceneForest_EventScript_CheckCatchMonsCompleted
	releaseall
	end

PastTown_Port_EventScript_MonRanAway::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, VAR_TEMP_2
	msgbox PastTown_Port_Text_MonRanAway, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

PastTown_Port_EventScript_PalossandRanAway::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, VAR_TEMP_2
	msgbox PastTown_Port_Text_PalossandRanAway, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

PastTown_Port_Text_LookerFossilRevive:
	.string "Hmm…\p"
	.string "I wonder what I could do with this\n"
	.string "fossil…$"

PastTown_Port_Text_ManiacNo:
	.string "No!$"

PastTown_Port_Text_ManiacGetOut:
	.string "Haha! The spirit of the river has\n"
	.string "bestowed the fossils unto me!$"

PastTown_Port_Text_LookerDrat:
	.string "(Drat, I need to regroup…)$"

PastTown_Port_Text_ManiacDoNotApproachThoseFossils:
	.string "I have been waiting months for new\n"
	.string "fossils to appear on the shores of\l"
	.string "this river delta bay!\p"
	.string "I arrived first, so I claim those two\n"
	.string "fossils, even if I must battle for them!$"

PastTown_Port_Text_EverettDefeated:
	.string "No…\n"
	.string "I had been waiting for so long too…$"

PastTown_Port_Text_ManiacOhFine:
	.string "Oh fine…\p"
	.string "You may have a fossil…\p"
	.string "But please, do not take both…$"

PastTown_Port_Text_ManiacLookingForFossils:
	.string "Oh river delta…\p"
	.string "When will you bestow upon me the gift\n"
	.string "of a fossil?\p"
	.string "I have combed your shores for months,\n"
	.string "yet you bear no fruit…$"

PastTown_Port_Text_ManiacOhFossils:
	.string "Oh great river delta!\p"
	.string "Thank you for bestowing upon me not\n"
	.string "one, but two fossils today!$"

PastTown_Port_Text_PokemaniacIllChooseTusk:
	.string "In that case, I shall study the\n"
	.string "eroded tusk!$"

PastTown_Port_Text_PokemaniacIllChooseWing:
	.string "In that case, I shall study the\n"
	.string "wing imprint!$"

PastTown_Port_Text_ManiacChoseTuskFossil:
	.string "This tusk fossil is fascinating!\p"
	.string "Despite being seemingly thousands\n"
	.string "of years old, the ivory remains as\l"
	.string "sturdy as an Aggron!\p"
	.string "Truly, it was the better fossil!$"

PastTown_Port_Text_ManiacChoseWingFossil:
	.string "This wing fossil is sublime!\p"
	.string "Despite being seemingly thousands\n"
	.string "of years old, the wing's sheen has\l"
	.string "stayed as radiant as a Gholdengo!\p"
	.string "Truly, it was the better fossil!$"

PastTown_Port_Text_TakeTuskFossil:
	.string "Will you take the eroded tooth?$"

PastTown_Port_Text_TakeWingFossil:
	.string "Will you take the wing imprint?$"

PastTown_Port_Text_LeftTuskFossilAlone:
	.string "Looker left the eroded tooth alone.$"

PastTown_Port_Text_LeftWingFossilAlone:
	.string "Looker left the wing imprint alone.$"

PastTown_Port_Text_Dhelmise:
	.string "uuOOooUUoUOOOuuuOooUoo…$"

PastTown_Port_Text_Grapploct:
	.string "Gra?$"

PastTown_Port_Text_Crabominable:
	.string "Blblblbl!$"

PastTown_Port_Text_Palossand:
	.string "Ssssssaaa!$"

PastTown_Port_Text_Phione:
	.string "Phiiiiii!$"

PastTown_Port_Text_MonRanAway:
	.string "{STR_VAR_1} jumped into the bay!$"

PastTown_Port_Text_PalossandRanAway:
	.string "{STR_VAR_1} sank into the ground!$"