CutsceneForest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CutsceneForest_OnTransition
    map_script MAP_SCRIPT_ON_FRAME_TABLE, CutsceneForest_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, CutsceneForest_OnResume
    .byte 0

CutsceneForest_EventScript_CheckCatchMonsCompleted::
	call_if_set FLAG_CAUGHT_RODENT, CutsceneForest_EventScript_ConfirmCaughtRodent
	return

CutsceneForest_EventScript_ConfirmCaughtRodent::
	call_if_set FLAG_CAUGHT_LURANTIS, CutsceneForest_EventScript_ConfirmCaughtLurantis
	return
	
CutsceneForest_EventScript_ConfirmCaughtLurantis::
	call_if_set FLAG_CAUGHT_LUXRAY, CutsceneForest_EventScript_ConfirmCaughtLuxray
	return
	
CutsceneForest_EventScript_ConfirmCaughtLuxray::
	call_if_set FLAG_CAUGHT_TOEDSCRUEL, CutsceneForest_EventScript_ConfirmCaughtToedscruel
	return
	
CutsceneForest_EventScript_ConfirmCaughtToedscruel::
	call_if_set FLAG_CAUGHT_FROSMOTH, CutsceneForest_EventScript_ConfirmCaughtFrosmoth
	return
	
CutsceneForest_EventScript_ConfirmCaughtFrosmoth::
	call_if_set FLAG_CAUGHT_KLEAVOR, CutsceneForest_EventScript_ConfirmCaughtKleavor
	return

CutsceneForest_EventScript_ConfirmCaughtKleavor::
	call_if_set FLAG_CAUGHT_GOODRA_HISUI, CutsceneForest_EventScript_ConfirmCaughtGoodraHisui
	return

CutsceneForest_EventScript_ConfirmCaughtGoodraHisui::
	call_if_set FLAG_CAUGHT_BEHEEYEM, CutsceneForest_EventScript_ConfirmCaughtBeheeyem
	return

CutsceneForest_EventScript_ConfirmCaughtBeheeyem::
	call_if_set FLAG_CAUGHT_AERODACTYL, CutsceneForest_EventScript_ConfirmCaughtAerodactyl
	return

CutsceneForest_EventScript_ConfirmCaughtAerodactyl::
	call_if_set FLAG_CAUGHT_SCREAM_TAIL, CutsceneForest_EventScript_ConfirmCaughtScreamTail
	return

CutsceneForest_EventScript_ConfirmCaughtScreamTail::
	call_if_set FLAG_CAUGHT_AROMATISSE, CutsceneForest_EventScript_ConfirmCaughtAromatisse
	return

CutsceneForest_EventScript_ConfirmCaughtAromatisse::
	call_if_set FLAG_CAUGHT_DHELMISE, CutsceneForest_EventScript_ConfirmCaughtDhelmise
	return

CutsceneForest_EventScript_ConfirmCaughtDhelmise::
	call_if_set FLAG_CAUGHT_GRAPPLOCT, CutsceneForest_EventScript_ConfirmCaughtGrapploct
	return

CutsceneForest_EventScript_ConfirmCaughtGrapploct::
	call_if_set FLAG_CAUGHT_PALOSSAND, CutsceneForest_EventScript_ConfirmCaughtPalossand
	return

CutsceneForest_EventScript_ConfirmCaughtPalossand::
	call_if_set FLAG_CAUGHT_CRABOMINABLE, CutsceneForest_EventScript_ConfirmCaughtCrabominable
	return
	
CutsceneForest_EventScript_ConfirmCaughtCrabominable::
	call_if_set FLAG_CAUGHT_PHIONE, CutsceneForest_EventScript_ConfirmCaughtPhione
	return
	
CutsceneForest_EventScript_ConfirmCaughtPhione::
	call_if_set FLAG_CAUGHT_WO_CHIEN, CutsceneForest_EventScript_ConfirmCaughtDhelmise
	return

CutsceneForest_EventScript_ConfirmCaughtWoChien::
	call CutsceneForest_EventScript_CompleteCatchMonsQuest
	return

CutsceneForest_EventScript_CompleteCatchMonsQuest::
	delay 10
	speak LOCALID_PLAYER, DIR_SOUTH, Name_Looker, CutsceneForest_Text_LookerThatShouldBeIt
	completequest QUEST_CATCHMONS
	return

CutsceneForest_OnResume:
	special HealPlayerParty
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, CutsceneForest_EventScript_TryRemoveCatchMon
	end

CutsceneForest_EventScript_TryRemoveCatchMon::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 3, CutsceneForest_EventScript_RemoveRodent
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 4, CutsceneForest_EventScript_RemoveRodent
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 5, CutsceneForest_EventScript_RemoveLurantis
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 6, CutsceneForest_EventScript_RemoveLuxray
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 7, CutsceneForest_EventScript_RemoveLuxrayDark
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 8, CutsceneForest_EventScript_RemoveToedscruel
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 9, CutsceneForest_EventScript_RemoveFrosmoth
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 10, CutsceneForest_EventScript_RemoveKleavor
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 11, CutsceneForest_EventScript_RemoveGoodraHisui
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 12, CutsceneForest_EventScript_RemoveBeheeyem
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 13, CutsceneForest_EventScript_RemoveAerodactyl
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 14, CutsceneForest_EventScript_RemoveScreamTail
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 15, CutsceneForest_EventScript_RemoveWoChien
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 16, CutsceneForest_EventScript_RemoveAromatisse
	return

CutsceneForest_EventScript_RemoveRodent::
	removeobject LOCALID_FOREST_TOGEDEMARU
	removeobject LOCALID_FOREST_DEDENNE
	return
	
CutsceneForest_EventScript_RemoveLurantis::
	removeobject LOCALID_FOREST_LURANTIS
	return
	
CutsceneForest_EventScript_RemoveLuxray::
	removeobject LOCALID_FOREST_LUXRAY
	return
	
CutsceneForest_EventScript_RemoveLuxrayDark::
	removeobject LOCALID_FOREST_LUXRAY_DARK
	return
	
CutsceneForest_EventScript_RemoveToedscruel::
	removeobject LOCALID_FOREST_TOEDSCRUEL
	return
	
CutsceneForest_EventScript_RemoveFrosmoth::
	removeobject LOCALID_FOREST_FROSMOTH
	return
	
CutsceneForest_EventScript_RemoveKleavor::
	removeobject LOCALID_FOREST_KLEAVOR
	return
	
CutsceneForest_EventScript_RemoveGoodraHisui::
	removeobject LOCALID_FOREST_GOODRA
	return
	
CutsceneForest_EventScript_RemoveBeheeyem::
	removeobject LOCALID_FOREST_BEHEEYEM
	return
	
CutsceneForest_EventScript_RemoveAerodactyl::
	removeobject LOCALID_FOREST_AERODACTYL
	return
	
CutsceneForest_EventScript_RemoveScreamTail::
	removeobject LOCALID_FOREST_SCREAM_TAIL
	return
	
CutsceneForest_EventScript_RemoveWoChien::
	removeobject LOCALID_FOREST_WO_CHIEN
	return
	
CutsceneForest_EventScript_RemoveAromatisse::
	removeobject LOCALID_FOREST_AROMATISSE
	return
	
CutsceneForest_OnTransition:
	setflag FLAG_SYS_PREVENT_MAP_FADE
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetStormWeather
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 1, CutsceneForest_EventScript_AddLostIdol
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 2, CutsceneForest_EventScript_AddSmeargle
	@call_if_eq VAR_CUTSCENE_FOREST_STATE, 3, CutsceneForest_EventScript_AddRodentsInitialEncounter
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 4, CutsceneForest_EventScript_AddRodent
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 5, CutsceneForest_EventScript_AddLurantis
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 6, CutsceneForest_EventScript_AddLuxray
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 7, CutsceneForest_EventScript_AddLuxrayDark
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 8, CutsceneForest_EventScript_AddToedscruel
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 9, CutsceneForest_EventScript_AddFrosmoth
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 10, CutsceneForest_EventScript_AddKleavor
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 11, CutsceneForest_EventScript_AddGoodraHisui
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 12, CutsceneForest_EventScript_AddBeheeyem
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 13, CutsceneForest_EventScript_AddAerodactyl
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 14, CutsceneForest_EventScript_AddScreamTail
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 15, CutsceneForest_EventScript_AddWoChien
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 16, CutsceneForest_EventScript_AddAromatisse
	end

CutsceneForest_EventScript_AddLostIdol::
	clearflag FLAG_HIDE_CUTSCENE_FOREST_IDOL
	addobject LOCALID_FOREST_LOST_IDOL
	return

CutsceneForest_EventScript_AddSmeargle::
	clearflag FLAG_HIDE_CUTSCENE_FOREST_SMEARGLE
	addobject LOCALID_FOREST_SMEARGLE
	return

CutsceneForest_EventScript_AddRodent::
	call_if_set FLAG_CHOSE_DEDENNE, CutsceneForest_EventScript_AddDedenne
	call_if_set FLAG_CHOSE_TOGEDEMARU, CutsceneForest_EventScript_AddTogedemaru
	return

CutsceneForest_EventScript_AddDedenne::
	clearflag FLAG_HIDE_FOREST_DEDENNE
	setobjectxyperm LOCALID_FOREST_DEDENNE, 10, 14
	setobjectmovementtype LOCALID_FOREST_DEDENNE, MOVEMENT_TYPE_FACE_UP
	addobject LOCALID_FOREST_DEDENNE
	return

CutsceneForest_EventScript_AddTogedemaru::
	clearflag FLAG_HIDE_FOREST_TOGEDEMARU
	setobjectxyperm LOCALID_FOREST_TOGEDEMARU, 10, 14
	setobjectmovementtype LOCALID_FOREST_TOGEDEMARU, MOVEMENT_TYPE_FACE_UP
	addobject LOCALID_FOREST_TOGEDEMARU
	return
		
CutsceneForest_EventScript_AddLurantis::
	clearflag FLAG_HIDE_FOREST_LURANTIS
	addobject LOCALID_FOREST_LURANTIS
	return

CutsceneForest_EventScript_AddLuxray::
	clearflag FLAG_HIDE_FOREST_LUXRAY
	addobject LOCALID_FOREST_LUXRAY
	return
	
CutsceneForest_EventScript_AddLuxrayDark::
	clearflag FLAG_HIDE_FOREST_LUXRAY_DARK
	addobject LOCALID_FOREST_LUXRAY_DARK
	return
	
CutsceneForest_EventScript_AddToedscruel::
	clearflag FLAG_HIDE_FOREST_TOEDSCRUEL
	addobject LOCALID_FOREST_TOEDSCRUEL
	return
	
CutsceneForest_EventScript_AddFrosmoth::
	clearflag FLAG_HIDE_FOREST_FROSMOTH
	addobject LOCALID_FOREST_FROSMOTH
	return
	
CutsceneForest_EventScript_AddKleavor::
	clearflag FLAG_HIDE_FOREST_KLEAVOR
	addobject LOCALID_FOREST_KLEAVOR
	return
	
CutsceneForest_EventScript_AddGoodraHisui::
	clearflag FLAG_HIDE_FOREST_GOODRA_HISUI
	addobject LOCALID_FOREST_GOODRA
	return
	
CutsceneForest_EventScript_AddBeheeyem::
	clearflag FLAG_HIDE_FOREST_BEHEEYEM
	addobject LOCALID_FOREST_BEHEEYEM
	return
	
CutsceneForest_EventScript_AddAerodactyl::
	clearflag FLAG_HIDE_FOREST_AERODACTYL
	addobject LOCALID_FOREST_AERODACTYL
	return
	
CutsceneForest_EventScript_AddScreamTail::
	clearflag FLAG_HIDE_FOREST_SCREAM_TAIL
	addobject LOCALID_FOREST_SCREAM_TAIL
	return
	
CutsceneForest_EventScript_AddWoChien::
	clearflag FLAG_HIDE_FOREST_WO_CHIEN
	addobject LOCALID_FOREST_WO_CHIEN
	return

CutsceneForest_EventScript_AddAromatisse::
	clearflag FLAG_HIDE_FOREST_AROMATISSE
	addobject LOCALID_FOREST_AROMATISSE
	return

CutsceneForest_OnFrame:
    map_script_2 VAR_CUTSCENE_STATE, 5, CutsceneForest_EventScript_SearchForEstella
	map_script_2 VAR_CUTSCENE_FOREST_STATE, 1, CutsceneForest_EventScript_FindLostIdol
	map_script_2 VAR_CUTSCENE_FOREST_STATE, 2, CutsceneForest_EventScript_FindSmeargle
	map_script_2 VAR_CUTSCENE_FOREST_STATE, 3, CutsceneForest_EventScript_RodentsInitialEncounter
	map_script_2 VAR_CUTSCENE_FOREST_STATE, 4, CutsceneForest_EventScript_StartEncounter
	map_script_2 VAR_CUTSCENE_FOREST_STATE, 5, CutsceneForest_EventScript_StartEncounter
	map_script_2 VAR_CUTSCENE_FOREST_STATE, 6, CutsceneForest_EventScript_StartEncounter
	map_script_2 VAR_CUTSCENE_FOREST_STATE, 7, CutsceneForest_EventScript_StartEncounter
	map_script_2 VAR_CUTSCENE_FOREST_STATE, 8, CutsceneForest_EventScript_StartEncounter
	map_script_2 VAR_CUTSCENE_FOREST_STATE, 9, CutsceneForest_EventScript_StartEncounter
	map_script_2 VAR_CUTSCENE_FOREST_STATE, 10, CutsceneForest_EventScript_StartEncounter
	map_script_2 VAR_CUTSCENE_FOREST_STATE, 11, CutsceneForest_EventScript_StartEncounter
	map_script_2 VAR_CUTSCENE_FOREST_STATE, 12, CutsceneForest_EventScript_StartEncounter
	map_script_2 VAR_CUTSCENE_FOREST_STATE, 13, CutsceneForest_EventScript_StartEncounter
	map_script_2 VAR_CUTSCENE_FOREST_STATE, 14, CutsceneForest_EventScript_StartEncounter
	map_script_2 VAR_CUTSCENE_FOREST_STATE, 15, CutsceneForest_EventScript_StartEncounter
	map_script_2 VAR_CUTSCENE_FOREST_STATE, 16, CutsceneForest_EventScript_StartEncounter
    .2byte 0

CutsceneForest_EventScript_RodentsInitialEncounter::
	lockall
	clearflag FLAG_SYS_PREVENT_MAP_FADE
	fadescreen FADE_FROM_BLACK
	applymovement LOCALID_PLAYER, CutsceneForest_Movement_WalkUp3
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_QuestionMark
	waitmovement 0
	delay 50
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, CutsceneForest_Movement_WalkUp6
	waitmovement 0
	delay 80
	applymovement LOCALID_CAMERA, CutsceneForest_Movement_WalkDown6
	waitmovement 0
	special RemoveCameraObject
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, CutsceneForest_Text_LookerCatchMons
	closemessage
	applymovement LOCALID_PLAYER, CutsceneForest_Movement_WalkUp3
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FOREST_DEDENNE, Common_Movement_FaceDownExclamationMark
	applymovement LOCALID_FOREST_TOGEDEMARU, Common_Movement_FaceDownExclamationMark
	waitmovement 0
	delay 50
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, CutsceneForest_Text_LookerShoot
	multichoice 0, 6, MULTI_RODENT_CHASEMON, TRUE
	goto_if_eq VAR_RESULT, 0, CutsceneForest_EventScript_ChoseDedenne
	goto_if_eq VAR_RESULT, 1, CutsceneForest_EventScript_ChoseTogedemaru
	end

CutsceneForest_EventScript_ChoseDedenne::
	msgbox CutsceneForest_Text_LookerPursueDedenne, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_CHOSE_DEDENNE
	playse SE_PIN
	applymovement LOCALID_FOREST_DEDENNE, Common_Movement_FaceUpQuestionMark
	applymovement LOCALID_FOREST_TOGEDEMARU, CutsceneForest_Movement_RodentRunAway
	delay 50
	waitmovement LOCALID_FOREST_TOGEDEMARU
	removeobject LOCALID_FOREST_TOGEDEMARU
	delay 40
	applymovement LOCALID_FOREST_DEDENNE, Common_Movement_FaceDown
	applymovement LOCALID_PLAYER, CutsceneForest_Movement_PlayerToDedenne
	waitmovement 0
	playmoncry SPECIES_DEDENNE, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 30
	createmon 1, 0, SPECIES_DEDENNE, 50, ITEM_AIR_BALLOON, 1, NATURE_TIMID, 0, MON_FEMALE, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, MOVE_NUZZLE, MOVE_PARABOLIC_CHARGE, MOVE_DAZZLING_GLEAM, MOVE_SUPER_FANG
	closemessage
	setvar VAR_LAST_TALKED, LOCALID_FOREST_DEDENNE
	setvar VAR_0x8004, SPECIES_DEDENNE
	setvar VAR_TRIGGER_CUTSCENE_FOREST, 3
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CutsceneForest_EventScript_EndRodentRan
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CutsceneForest_EventScript_EndRodentRan
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, CutsceneForest_EventScript_EndRodentRan
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CutsceneForest_EventScript_EndRodentRan
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, CutsceneForest_EventScript_EndRodentRan
	setflag FLAG_CAUGHT_RODENT
	addvar VAR_NUM_MONS_CAUGHT, 1
	speak LOCALID_PLAYER, DIR_SOUTH, Name_Looker, CutsceneForest_Text_LookerCaughtRodent
	startquest QUEST_CATCHMONS
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_CATCHMONS, 0
	goto CutsceneForest_EventScript_FinishRodentEncounter
	end

CutsceneForest_EventScript_ChoseTogedemaru::
	msgbox CutsceneForest_Text_LookerPursueTogedemaru, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_CHOSE_TOGEDEMARU
	playse SE_PIN
	applymovement LOCALID_FOREST_TOGEDEMARU, Common_Movement_FaceUpQuestionMark
	applymovement LOCALID_FOREST_DEDENNE, CutsceneForest_Movement_RodentRunAway
	delay 50
	waitmovement LOCALID_FOREST_DEDENNE
	removeobject LOCALID_FOREST_DEDENNE
	delay 40
	applymovement LOCALID_FOREST_TOGEDEMARU, Common_Movement_FaceDown
	applymovement LOCALID_PLAYER, CutsceneForest_Movement_PlayerToTogedemaru
	waitmovement 0
	playmoncry SPECIES_TOGEDEMARU, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 30
	createmon 1, 0, SPECIES_TOGEDEMARU, 50, ITEM_AIR_BALLOON, 1, NATURE_JOLLY, 0, MON_MALE, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, MOVE_NUZZLE, MOVE_ZING_ZAP, MOVE_IRON_HEAD, MOVE_SUPER_FANG
	closemessage
	setvar VAR_LAST_TALKED, LOCALID_FOREST_TOGEDEMARU
	setvar VAR_0x8004, SPECIES_TOGEDEMARU
	setvar VAR_TRIGGER_CUTSCENE_FOREST, 3
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CutsceneForest_EventScript_EndRodentRan
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CutsceneForest_EventScript_EndRodentRan
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, CutsceneForest_EventScript_EndRodentRan
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CutsceneForest_EventScript_EndRodentRan
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, CutsceneForest_EventScript_EndRodentRan
	setflag FLAG_CAUGHT_RODENT
	addvar VAR_NUM_MONS_CAUGHT, 1
	speak LOCALID_PLAYER, DIR_SOUTH, Name_Looker, CutsceneForest_Text_LookerCaughtRodent
	startquest QUEST_CATCHMONS
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_CATCHMONS, 0
	goto CutsceneForest_EventScript_FinishRodentEncounter
	end

CutsceneForest_Movement_WalkUp3:
	walk_up
	walk_up
	walk_up
	step_end

CutsceneForest_Movement_RodentRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

CutsceneForest_Movement_PlayerToDedenne:
	walk_fast_up
	walk_fast_up
	step_end
	
CutsceneForest_Movement_PlayerToTogedemaru:
	walk_fast_up
	walk_fast_right
	walk_fast_up
	step_end
	
CutsceneForest_EventScript_StartEncounter::
	lockall
	setflag FLAG_SYS_NO_WHITEOUT
	clearflag FLAG_SYS_PREVENT_MAP_FADE
	delay 40
	applymovement LOCALID_PLAYER, CutsceneForest_Movement_WalkDown4
	fadescreen FADE_FROM_BLACK
	waitmovement LOCALID_PLAYER
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 50
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, CutsceneForest_Movement_WalkDown6
	waitmovement 0
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 4, CutsceneForest_EventScript_RodentCry
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 5, CutsceneForest_EventScript_LurantisCry
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 6, CutsceneForest_EventScript_LuxrayCry
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 7, CutsceneForest_EventScript_LuxrayDarkCry
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 8, CutsceneForest_EventScript_ToedscruelCry
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 9, CutsceneForest_EventScript_FrosmothCry
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 10, CutsceneForest_EventScript_KleavorCry
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 11, CutsceneForest_EventScript_GoodraHisuiCry
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 12, CutsceneForest_EventScript_BeheeyemCry
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 13, CutsceneForest_EventScript_AerodactylCry
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 14, CutsceneForest_EventScript_ScreamTailCry
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 15, CutsceneForest_EventScript_WoChienCry
	call_if_eq VAR_CUTSCENE_FOREST_STATE, 16, CutsceneForest_EventScript_AromatisseCry
	closemessage
	applymovement LOCALID_CAMERA, CutsceneForest_Movement_WalkUp6
	waitmovement 0
	special RemoveCameraObject
	delay 60
	applymovement LOCALID_PLAYER, CutsceneForest_Movement_WalkDown4
	waitmovement 0
	delay 60
	switch VAR_CUTSCENE_FOREST_STATE
	case 4, CutsceneForest_EventScript_RodentRematch
	case 5, CutsceneForest_EventScript_Lurantis
	case 6, CutsceneForest_EventScript_Luxray
	case 7, CutsceneForest_EventScript_LuxrayDark
	case 8, CutsceneForest_EventScript_Toedscruel
	case 9, CutsceneForest_EventScript_Frosmoth
	case 10, CutsceneForest_EventScript_Kleavor
	case 11, CutsceneForest_EventScript_GoodraHisui
	case 12, CutsceneForest_EventScript_Beheeyem
	case 13, CutsceneForest_EventScript_Aerodactyl
	case 14, CutsceneForest_EventScript_ScreamTail
	case 15, CutsceneForest_EventScript_WoChien
	case 16, CutsceneForest_EventScript_Aromatisse
	end
	
CutsceneForest_EventScript_RodentCry::
	call_if_set FLAG_CHOSE_DEDENNE, CutsceneForest_EventScript_DedenneCry
	call_if_set FLAG_CHOSE_TOGEDEMARU, CutsceneForest_EventScript_TogedemaruCry
	return

CutsceneForest_EventScript_DedenneCry::
	playmoncry SPECIES_DEDENNE, CRY_MODE_NORMAL
	msgbox CutsceneForest_Text_Dedenne, MSGBOX_DEFAULT
	waitmoncry
	return

CutsceneForest_EventScript_TogedemaruCry::
	playmoncry SPECIES_TOGEDEMARU, CRY_MODE_NORMAL
	msgbox CutsceneForest_Text_Togedemaru, MSGBOX_DEFAULT
	waitmoncry
	return

CutsceneForest_EventScript_LurantisCry::
	playmoncry SPECIES_LURANTIS, CRY_MODE_NORMAL
	msgbox CutsceneForest_Text_Lurantis, MSGBOX_DEFAULT
	waitmoncry
	return

CutsceneForest_EventScript_LuxrayCry::
	playmoncry SPECIES_LUXRAY, CRY_MODE_NORMAL
	msgbox CutsceneForest_Text_Luxray, MSGBOX_DEFAULT
	waitmoncry
	return

CutsceneForest_EventScript_LuxrayDarkCry::
	playmoncry SPECIES_LUXRAY, CRY_MODE_NORMAL
	msgbox CutsceneForest_Text_LuxrayDark, MSGBOX_DEFAULT
	waitmoncry
	return

CutsceneForest_EventScript_ToedscruelCry::
	playmoncry SPECIES_TOEDSCRUEL, CRY_MODE_NORMAL
	msgbox CutsceneForest_Text_Toedscruel, MSGBOX_DEFAULT
	waitmoncry
	return

CutsceneForest_EventScript_FrosmothCry::
	playmoncry SPECIES_FROSMOTH, CRY_MODE_NORMAL
	msgbox CutsceneForest_Text_Frosmoth, MSGBOX_DEFAULT
	waitmoncry
	return

CutsceneForest_EventScript_KleavorCry::
	playmoncry SPECIES_KLEAVOR, CRY_MODE_NORMAL
	msgbox CutsceneForest_Text_Kleavor, MSGBOX_DEFAULT
	waitmoncry
	return

CutsceneForest_EventScript_GoodraHisuiCry::
	playmoncry SPECIES_GOODRA_HISUI, CRY_MODE_NORMAL
	msgbox CutsceneForest_Text_GoodraHisui, MSGBOX_DEFAULT
	waitmoncry
	return

CutsceneForest_EventScript_BeheeyemCry::
	playmoncry SPECIES_BEHEEYEM, CRY_MODE_NORMAL
	msgbox CutsceneForest_Text_Beheeyem, MSGBOX_DEFAULT
	waitmoncry
	return

CutsceneForest_EventScript_AerodactylCry::
	playmoncry SPECIES_AERODACTYL, CRY_MODE_NORMAL
	msgbox CutsceneForest_Text_Aerodactyl, MSGBOX_DEFAULT
	waitmoncry
	return

CutsceneForest_EventScript_ScreamTailCry::
	playmoncry SPECIES_SCREAM_TAIL, CRY_MODE_NORMAL
	msgbox CutsceneForest_Text_ScreamTail, MSGBOX_DEFAULT
	waitmoncry
	return

CutsceneForest_EventScript_WoChienCry::
	playmoncry SPECIES_WO_CHIEN, CRY_MODE_NORMAL
	msgbox CutsceneForest_Text_WoChien, MSGBOX_DEFAULT
	waitmoncry
	return

CutsceneForest_EventScript_AromatisseCry::
	playmoncry SPECIES_AROMATISSE, CRY_MODE_NORMAL
	msgbox CutsceneForest_Text_Aromatisse, MSGBOX_DEFAULT
	waitmoncry
	return

CutsceneForest_EventScript_RodentRematch::
	goto_if_set FLAG_CHOSE_DEDENNE, CutsceneForest_EventScript_DedenneRematch
	goto_if_set FLAG_CHOSE_TOGEDEMARU, CutsceneForest_EventScript_TogedemaruRematch
	goto CutsceneForest_EventScript_FinishEncounter
	end

CutsceneForest_EventScript_DedenneRematch::
	playmoncry SPECIES_DEDENNE, CRY_MODE_ENCOUNTER
	applymovement LOCALID_FOREST_DEDENNE, CutsceneForest_Movement_MonRushPlayer
	delay 40
	waitmovement LOCALID_FOREST_DEDENNE
	waitmoncry
	createmon 1, 0, SPECIES_DEDENNE, 50, ITEM_AIR_BALLOON, 1, NATURE_TIMID, 0, MON_FEMALE, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, MOVE_NUZZLE, MOVE_PARABOLIC_CHARGE, MOVE_DAZZLING_GLEAM, MOVE_SUPER_FANG
	closemessage
	setvar VAR_LAST_TALKED, LOCALID_FOREST_DEDENNE
	setvar VAR_0x8004, SPECIES_DEDENNE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, CutsceneForest_EventScript_EndRan
	setflag FLAG_CAUGHT_RODENT
	addvar VAR_NUM_MONS_CAUGHT, 1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_CATCHMONS, 0
	returnqueststate QUEST_CATCHMONS
	call_if_ne VAR_RESULT, 4, CutsceneForest_EventScript_CheckCatchMonsCompleted
	goto CutsceneForest_EventScript_FinishEncounter
	releaseall
	end

CutsceneForest_EventScript_TogedemaruRematch::
	playmoncry SPECIES_TOGEDEMARU, CRY_MODE_ENCOUNTER
	applymovement LOCALID_FOREST_TOGEDEMARU, CutsceneForest_Movement_MonRushPlayer
	delay 40
	waitmovement LOCALID_FOREST_TOGEDEMARU
	waitmoncry
	createmon 1, 0, SPECIES_TOGEDEMARU, 50, ITEM_AIR_BALLOON, 1, NATURE_JOLLY, 0, MON_MALE, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, MOVE_NUZZLE, MOVE_ZING_ZAP, MOVE_IRON_HEAD, MOVE_SUPER_FANG
	closemessage
	setvar VAR_LAST_TALKED, LOCALID_FOREST_TOGEDEMARU
	setvar VAR_0x8004, SPECIES_TOGEDEMARU
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, CutsceneForest_EventScript_EndRan
	setflag FLAG_CAUGHT_RODENT
	addvar VAR_NUM_MONS_CAUGHT, 1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_CATCHMONS, 0
	returnqueststate QUEST_CATCHMONS
	call_if_ne VAR_RESULT, 4, CutsceneForest_EventScript_CheckCatchMonsCompleted
	goto CutsceneForest_EventScript_FinishEncounter
	releaseall
	end

CutsceneForest_EventScript_Lurantis::
	playmoncry SPECIES_LURANTIS, CRY_MODE_ENCOUNTER
	applymovement LOCALID_FOREST_LURANTIS, CutsceneForest_Movement_MonRushPlayer
	delay 40
	waitmovement LOCALID_FOREST_LURANTIS
	waitmoncry
	createmon 1, 0, SPECIES_LURANTIS, 50, ITEM_COBA_BERRY, 1, NATURE_ADAMANT, 0, MON_FEMALE, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, MOVE_LEAF_BLADE, MOVE_SUPERPOWER, MOVE_LEECH_LIFE, MOVE_SOLAR_BLADE
	closemessage
	setvar VAR_LAST_TALKED, LOCALID_FOREST_LURANTIS
	setvar VAR_0x8004, SPECIES_LURANTIS
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, CutsceneForest_EventScript_EndRan
	setflag FLAG_CAUGHT_LURANTIS
	addvar VAR_NUM_MONS_CAUGHT, 1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_CATCHMONS, 1
	returnqueststate QUEST_CATCHMONS
	call_if_ne VAR_RESULT, 4, CutsceneForest_EventScript_CheckCatchMonsCompleted
	goto CutsceneForest_EventScript_FinishEncounter
	releaseall
	end

CutsceneForest_EventScript_Luxray::
	playmoncry SPECIES_LUXRAY, CRY_MODE_ENCOUNTER
	applymovement LOCALID_FOREST_LUXRAY, CutsceneForest_Movement_MonRushPlayer
	delay 40
	waitmovement LOCALID_FOREST_LUXRAY
	waitmoncry
	createmon 1, 0, SPECIES_LUXRAY, 50, ITEM_SHUCA_BERRY, 1, NATURE_JOLLY, 0, MON_MALE, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, MOVE_SUPERCELL_SLAM, MOVE_CRUNCH, MOVE_PLAY_ROUGH, MOVE_ICE_FANG
	closemessage
	setvar VAR_LAST_TALKED, LOCALID_FOREST_LUXRAY
	setvar VAR_0x8004, SPECIES_LUXRAY
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, CutsceneForest_EventScript_EndRan
	returnqueststate QUEST_LUXRAY
	call_if_eq VAR_RESULT, 2, CutsceneForest_EventScript_SetLuxrayReward
	setflag FLAG_CAUGHT_LUXRAY
	addvar VAR_NUM_MONS_CAUGHT, 1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_CATCHMONS, 2
	returnqueststate QUEST_CATCHMONS
	call_if_ne VAR_RESULT, 4, CutsceneForest_EventScript_CheckCatchMonsCompleted
	goto CutsceneForest_EventScript_FinishEncounter
	releaseall
	end

CutsceneForest_EventScript_LuxrayDark::
	playmoncry SPECIES_LUXRAY, CRY_MODE_ENCOUNTER
	applymovement LOCALID_FOREST_LUXRAY_DARK, CutsceneForest_Movement_MonRushPlayer
	delay 40
	waitmovement LOCALID_FOREST_LUXRAY_DARK
	waitmoncry
	createmon 1, 0, SPECIES_LUXRAY_DARK, 50, ITEM_SHUCA_BERRY, 1, NATURE_ADAMANT, 0, MON_MALE, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, MOVE_WILD_CHARGE, MOVE_CRUNCH, MOVE_PLAY_ROUGH, MOVE_ICE_FANG
	closemessage
	setvar VAR_LAST_TALKED, LOCALID_FOREST_LUXRAY_DARK
	setvar VAR_0x8004, SPECIES_LUXRAY_DARK
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, CutsceneForest_EventScript_EndRan
	speak LOCALID_PLAYER, DIR_SOUTH, Name_Looker, CutsceneForest_Text_LookerLuxraySeemsDifferent
	returnqueststate QUEST_LUXRAY
	call_if_eq VAR_RESULT, 2, CutsceneForest_EventScript_SetLuxrayDarkReward
	closemessage
	setflag FLAG_CAUGHT_LUXRAY_DARK
	addvar VAR_NUM_MONS_CAUGHT, 1
	goto CutsceneForest_EventScript_FinishEncounter
	releaseall
	end

CutsceneForest_EventScript_SetLuxrayReward::
	speak LOCALID_PLAYER, DIR_SOUTH, Name_Looker, CutsceneForest_Text_LuxrayReward
	closemessage
	questmenu QUEST_MENU_SET_REWARD, QUEST_LUXRAY
	return

CutsceneForest_EventScript_SetLuxrayDarkReward::
	playse SE_SELECT
	msgbox CutsceneForest_Text_LuxrayReward, MSGBOX_DEFAULT
	questmenu QUEST_MENU_SET_REWARD, QUEST_LUXRAY
	return

CutsceneForest_EventScript_Toedscruel::
	playmoncry SPECIES_TOEDSCRUEL, CRY_MODE_ENCOUNTER
	applymovement LOCALID_FOREST_TOEDSCRUEL, CutsceneForest_Movement_MonRushPlayer
	delay 40
	waitmovement LOCALID_FOREST_TOEDSCRUEL
	waitmoncry
	createmon 1, 0, SPECIES_TOEDSCRUEL, 50, ITEM_YACHE_BERRY, 1, NATURE_TIMID, 0, MON_MALE, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, MOVE_ENERGY_BALL, MOVE_EARTH_POWER, MOVE_RAGE_POWDER, MOVE_SPIKES
	closemessage
	setvar VAR_LAST_TALKED, LOCALID_FOREST_TOEDSCRUEL
	setvar VAR_0x8004, SPECIES_TOEDSCRUEL
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, CutsceneForest_EventScript_EndRan
	setflag FLAG_CAUGHT_TOEDSCRUEL
	addvar VAR_NUM_MONS_CAUGHT, 1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_CATCHMONS, 3
	returnqueststate QUEST_CATCHMONS
	call_if_ne VAR_RESULT, 4, CutsceneForest_EventScript_CheckCatchMonsCompleted
	goto CutsceneForest_EventScript_FinishEncounter
	releaseall
	end

CutsceneForest_EventScript_Frosmoth::
	playmoncry SPECIES_FROSMOTH, CRY_MODE_ENCOUNTER
	applymovement LOCALID_FOREST_FROSMOTH, CutsceneForest_Movement_MonRushPlayer
	delay 40
	waitmovement LOCALID_FOREST_FROSMOTH
	waitmoncry
	createmon 1, 0, SPECIES_FROSMOTH, 50, ITEM_CHARTI_BERRY, 1, NATURE_BOLD, 0, MON_FEMALE, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, MOVE_ICE_BEAM, MOVE_BUG_BUZZ, MOVE_SNOWSCAPE, MOVE_STRUGGLE_BUG
	closemessage
	setvar VAR_LAST_TALKED, LOCALID_FOREST_FROSMOTH
	setvar VAR_0x8004, SPECIES_FROSMOTH
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CutsceneForest_EventScript_EndFlew
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CutsceneForest_EventScript_EndFlew
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, CutsceneForest_EventScript_EndFlew
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CutsceneForest_EventScript_EndFlew
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, CutsceneForest_EventScript_EndFlew
	setflag FLAG_CAUGHT_FROSMOTH
	addvar VAR_NUM_MONS_CAUGHT, 1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_CATCHMONS, 4
	returnqueststate QUEST_CATCHMONS
	call_if_ne VAR_RESULT, 4, CutsceneForest_EventScript_CheckCatchMonsCompleted
	goto CutsceneForest_EventScript_FinishEncounter
	releaseall
	end

CutsceneForest_EventScript_Kleavor::
	playmoncry SPECIES_KLEAVOR, CRY_MODE_ENCOUNTER
	applymovement LOCALID_FOREST_KLEAVOR, CutsceneForest_Movement_MonRushPlayer
	delay 40
	waitmovement LOCALID_FOREST_KLEAVOR
	waitmoncry
	createmon 1, 0, SPECIES_KLEAVOR, 50, ITEM_BABIRI_BERRY, 1, NATURE_JOLLY, 0, MON_FEMALE, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, MOVE_STONE_AXE, MOVE_LUNGE, MOVE_AERIAL_ACE, MOVE_CROSS_POISON
	closemessage
	setvar VAR_LAST_TALKED, LOCALID_FOREST_KLEAVOR
	setvar VAR_0x8004, SPECIES_KLEAVOR
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, CutsceneForest_EventScript_EndRan
	setflag FLAG_CAUGHT_KLEAVOR
	addvar VAR_NUM_MONS_CAUGHT, 1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_CATCHMONS, 5
	returnqueststate QUEST_CATCHMONS
	call_if_ne VAR_RESULT, 4, CutsceneForest_EventScript_CheckCatchMonsCompleted
	goto CutsceneForest_EventScript_FinishEncounter
	releaseall
	end

CutsceneForest_EventScript_GoodraHisui::
	playmoncry SPECIES_GOODRA_HISUI, CRY_MODE_ENCOUNTER
	applymovement LOCALID_FOREST_GOODRA, CutsceneForest_Movement_MonRushPlayer
	delay 40
	waitmovement LOCALID_FOREST_GOODRA
	waitmoncry
	createmon 1, 0, SPECIES_GOODRA_HISUI, 50, ITEM_CHOPLE_BERRY, 1, NATURE_SASSY, 0, MON_MALE, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, MOVE_IRON_HEAD, MOVE_DRAGON_TAIL, MOVE_SLUDGE_WAVE, MOVE_DRAGON_CLAW
	closemessage
	setvar VAR_LAST_TALKED, LOCALID_FOREST_GOODRA
	setvar VAR_0x8004, SPECIES_GOODRA_HISUI
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CutsceneForest_EventScript_EndSlithered
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CutsceneForest_EventScript_EndSlithered
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, CutsceneForest_EventScript_EndSlithered
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CutsceneForest_EventScript_EndSlithered
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, CutsceneForest_EventScript_EndSlithered
	setflag FLAG_CAUGHT_GOODRA_HISUI
	addvar VAR_NUM_MONS_CAUGHT, 1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_CATCHMONS, 11
	returnqueststate QUEST_CATCHMONS
	call_if_ne VAR_RESULT, 4, CutsceneForest_EventScript_CheckCatchMonsCompleted
	goto CutsceneForest_EventScript_FinishEncounter
	releaseall
	end

CutsceneForest_EventScript_Beheeyem::
	playmoncry SPECIES_BEHEEYEM, CRY_MODE_ENCOUNTER
	applymovement LOCALID_FOREST_BEHEEYEM, CutsceneForest_Movement_MonRushPlayer
	delay 40
	waitmovement LOCALID_FOREST_BEHEEYEM
	waitmoncry
	createmon 1, 0, SPECIES_BEHEEYEM, 50, ITEM_COLBUR_BERRY, 1, NATURE_MODEST, 0, MON_FEMALE, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, MOVE_EXPANDING_FORCE, MOVE_FLASH_CANNON, MOVE_CALM_MIND, MOVE_SHADOW_BALL
	closemessage
	setvar VAR_LAST_TALKED, LOCALID_FOREST_BEHEEYEM
	setvar VAR_0x8004, SPECIES_BEHEEYEM
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, CutsceneForest_EventScript_EndRan
	setflag FLAG_CAUGHT_BEHEEYEM
	addvar VAR_NUM_MONS_CAUGHT, 1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_CATCHMONS, 6
	returnqueststate QUEST_CATCHMONS
	call_if_ne VAR_RESULT, 4, CutsceneForest_EventScript_CheckCatchMonsCompleted
	goto CutsceneForest_EventScript_FinishEncounter
	releaseall
	end

CutsceneForest_EventScript_Aerodactyl::
	playmoncry SPECIES_AERODACTYL, CRY_MODE_ENCOUNTER
	applymovement LOCALID_FOREST_AERODACTYL, CutsceneForest_Movement_MonRushPlayer
	delay 40
	waitmovement LOCALID_FOREST_AERODACTYL
	waitmoncry
	createmon 1, 0, SPECIES_AERODACTYL, 50, ITEM_PASSHO_BERRY, 1, NATURE_ADAMANT, 0, MON_MALE, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, MOVE_STONE_EDGE, MOVE_DOUBLE_EDGE, MOVE_HONE_CLAWS, MOVE_SMACK_DOWN
	closemessage
	setvar VAR_LAST_TALKED, LOCALID_FOREST_AERODACTYL
	setvar VAR_0x8004, SPECIES_AERODACTYL
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CutsceneForest_EventScript_EndFlew
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CutsceneForest_EventScript_EndFlew
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, CutsceneForest_EventScript_EndFlew
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CutsceneForest_EventScript_EndFlew
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, CutsceneForest_EventScript_EndFlew
	setflag FLAG_CAUGHT_AERODACTYL
	addvar VAR_NUM_MONS_CAUGHT, 1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_CATCHMONS, 12
	returnqueststate QUEST_CATCHMONS
	call_if_ne VAR_RESULT, 4, CutsceneForest_EventScript_CheckCatchMonsCompleted
	goto CutsceneForest_EventScript_FinishEncounter
	releaseall
	end

CutsceneForest_EventScript_ScreamTail::
	playmoncry SPECIES_SCREAM_TAIL, CRY_MODE_ENCOUNTER
	applymovement LOCALID_FOREST_SCREAM_TAIL, CutsceneForest_Movement_MonRushPlayer
	delay 40
	waitmovement LOCALID_FOREST_SCREAM_TAIL
	waitmoncry
	createmon 1, 0, SPECIES_SCREAM_TAIL, 50, ITEM_KEBIA_BERRY, 1, NATURE_BASHFUL, 0, MON_GENDERLESS, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, MOVE_PSYCHIC_NOISE, MOVE_MISTY_TERRAIN, MOVE_PERISH_SONG, MOVE_METRONOME
	closemessage
	setvar VAR_LAST_TALKED, LOCALID_FOREST_SCREAM_TAIL
	setvar VAR_0x8004, SPECIES_SCREAM_TAIL
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, CutsceneForest_EventScript_EndRan
	setflag FLAG_CAUGHT_SCREAM_TAIL
	addvar VAR_NUM_MONS_CAUGHT, 1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_CATCHMONS, 13
	returnqueststate QUEST_CATCHMONS
	call_if_ne VAR_RESULT, 4, CutsceneForest_EventScript_CheckCatchMonsCompleted
	goto CutsceneForest_EventScript_FinishEncounter
	releaseall
	end

CutsceneForest_EventScript_WoChien::
	playmoncry SPECIES_WO_CHIEN, CRY_MODE_ENCOUNTER
	applymovement LOCALID_FOREST_WO_CHIEN, CutsceneForest_Movement_MonRushPlayer
	delay 40
	waitmovement LOCALID_FOREST_WO_CHIEN
	waitmoncry
	createmon 1, 0, SPECIES_WO_CHIEN, 50, ITEM_TANGA_BERRY, 1, NATURE_QUIET, 0, MON_GENDERLESS, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, MOVE_GIGA_DRAIN, MOVE_SNARL, MOVE_RUINATION, MOVE_LEECH_SEED
	closemessage
	setvar VAR_LAST_TALKED, LOCALID_FOREST_WO_CHIEN
	setvar VAR_0x8004, SPECIES_WO_CHIEN
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CutsceneForest_EventScript_EndSlithered
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CutsceneForest_EventScript_EndSlithered
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, CutsceneForest_EventScript_EndSlithered
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CutsceneForest_EventScript_EndSlithered
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, CutsceneForest_EventScript_EndSlithered
	setflag FLAG_CAUGHT_WO_CHIEN
	addvar VAR_NUM_MONS_CAUGHT, 1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_CATCHMONS, 16
	returnqueststate QUEST_CATCHMONS
	call_if_ne VAR_RESULT, 4, CutsceneForest_EventScript_CheckCatchMonsCompleted
	goto CutsceneForest_EventScript_FinishEncounter
	releaseall
	end

CutsceneForest_EventScript_Aromatisse::
	playmoncry SPECIES_AROMATISSE, CRY_MODE_ENCOUNTER
	applymovement LOCALID_FOREST_AROMATISSE, CutsceneForest_Movement_MonRushPlayer
	delay 40
	waitmovement LOCALID_FOREST_AROMATISSE
	waitmoncry
	createmon 1, 0, SPECIES_AROMATISSE, 50, ITEM_BRIGHT_POWDER, 1, NATURE_RASH, 0, MON_FEMALE, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, MOVE_MOONBLAST, MOVE_ENERGY_BALL, MOVE_THUNDERBOLT, MOVE_TRICK_ROOM
	closemessage
	setvar VAR_LAST_TALKED, LOCALID_FOREST_AROMATISSE
	setvar VAR_0x8004, SPECIES_AROMATISSE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CutsceneForest_EventScript_EndRan
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, CutsceneForest_EventScript_EndRan
	setflag FLAG_CAUGHT_AROMATISSE
	addvar VAR_NUM_MONS_CAUGHT, 1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_CATCHMONS, 14
	returnqueststate QUEST_CATCHMONS
	call_if_ne VAR_RESULT, 4, CutsceneForest_EventScript_CheckCatchMonsCompleted
	goto CutsceneForest_EventScript_FinishEncounter
	releaseall
	end

CutsceneForest_EventScript_EndRodentRan::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, VAR_0x8004
	message CutsceneForest_Text_MonRanAway
	waitmessage
	delay 80
	closemessage
	delay 40
	speak LOCALID_PLAYER, DIR_SOUTH, Name_Looker, CutsceneForest_Text_LookerThatsUnfortunate
	startquest QUEST_CATCHMONS
	goto CutsceneForest_EventScript_FinishRodentEncounter
	end

CutsceneForest_EventScript_EndRan::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, VAR_0x8004
	message CutsceneForest_Text_MonRanAway
	waitmessage
	delay 80
	closemessage
	delay 40
	goto CutsceneForest_EventScript_FinishEncounter
	end

CutsceneForest_EventScript_EndSlithered::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, VAR_0x8004
	message CutsceneForest_Text_MonSlitheredAway
	waitmessage
	delay 80
	closemessage
	delay 40
	goto CutsceneForest_EventScript_FinishEncounter
	end

CutsceneForest_EventScript_EndFlew::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, VAR_0x8004
	message CutsceneForest_Text_MonFlewAway
	waitmessage
	delay 80
	closemessage
	delay 40
	goto CutsceneForest_EventScript_FinishEncounter
	end

CutsceneForest_EventScript_FinishRodentEncounter::
	delay 60
	special SpawnCameraObject
	applymovement LOCALID_PLAYER, CutsceneForest_Movement_WalkUp6
	delay 30
	fadescreen FADE_TO_BLACK
	waitmovement LOCALID_PLAYER
	special RemoveCameraObject
	setvar VAR_CUTSCENE_FOREST_STATE, 0
	setvar VAR_TRIGGER_CUTSCENE_FOREST, 0
	clearflag FLAG_SYS_NO_WHITEOUT
	warp MAP_SHRINE_OF_PEACE_PRESENT, 14, 20
	waitstate
	releaseall
	end

CutsceneForest_EventScript_FinishEncounter::
	delay 30
	special SpawnCameraObject
	applymovement LOCALID_PLAYER, CutsceneForest_Movement_WalkDown6
	delay 30
	fadescreen FADE_TO_BLACK
	waitmovement LOCALID_PLAYER
	special RemoveCameraObject
	setvar VAR_CUTSCENE_FOREST_STATE, 0
	setvar VAR_TRIGGER_CUTSCENE_FOREST, 0
	clearflag FLAG_SYS_NO_WHITEOUT
	warp MAP_PRESENT_TOWN, 16, 7
	waitstate
	releaseall
	end

CutsceneForest_Movement_MonRushPlayer:
	walk_fast_up
	step_end

CutsceneForest_EventScript_FindSmeargle::
	lockall
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, CutsceneForest_Movement_CameraFastPanDown7
	delay 80
	fadescreen FADE_FROM_BLACK
	delay 20
	applymovement LOCALID_FOREST_SMEARGLE, CutsceneForest_Movement_SmeargleScared
	playmoncry SPECIES_SMEARGLE, CRY_MODE_NORMAL
	speakername Name_Smeargle
	msgbox CutsceneForest_Text_Smeargle, MSGBOX_DEFAULT
	waitmoncry
	waitmovement LOCALID_FOREST_SMEARGLE
	closemessage
	applymovement LOCALID_FOREST_SMEARGLE, CutsceneForest_Movement_SmeargleScared
	waitmovement 0
	delay 50
	playse SE_PIN
	applymovement LOCALID_FOREST_SMEARGLE, Common_Movement_FaceUpQuestionMark
	waitmovement 0
	delay 50
	applymovement LOCALID_PLAYER, CutsceneForest_Movement_WalkDown6
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_FaceDownQuestionMark
	waitmovement 0
	delay 50
	speak LOCALID_PLAYER, DIR_SOUTH, Name_Looker, CutsceneForest_Text_LookerYouMustBeSmeargle
	closemessage
	playse SE_LEDGE
	applymovement LOCALID_FOREST_SMEARGLE, CutsceneForest_Movement_SmeargleExcited
	waitse
	playse SE_LEDGE
	waitse
	waitmovement LOCALID_FOREST_SMEARGLE
	playmoncry SPECIES_SMEARGLE, CRY_MODE_NORMAL
	speak LOCALID_FOREST_SMEARGLE, DIR_NORTH, Name_Smeargle, CutsceneForest_Text_SmeargleHappy
	waitmoncry
	speak LOCALID_PLAYER, DIR_SOUTH, Name_Looker, CutsceneForest_Text_LookerLetsGoHome
	closemessage
	applymovement LOCALID_PLAYER, CutsceneForest_Movement_LookerGuideSmeargleHome
	applymovement LOCALID_FOREST_SMEARGLE, CutsceneForest_Movement_SmeargleFollowLooker
	delay 32
	fadescreen FADE_TO_BLACK
	setflag FLAG_SYS_SPAWN_INVISIBLE
	special RemoveCameraObject
	call_if_set FLAG_SYS_WEATHER_CTRL, CutsceneForest_EventScript_UnhideInsideSmeargle
	call_if_unset FLAG_SYS_WEATHER_CTRL, CutsceneForest_EventScript_UnhideOutsideSmeargle
	warp MAP_PRESENT_TOWN, 16, 5
	waitstate
	releaseall
	end

CutsceneForest_Movement_CameraFastPanDown8:
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end

CutsceneForest_EventScript_UnhideInsideSmeargle::
	clearflag FLAG_HIDE_INSIDE_SMEARGLE
	return
	
CutsceneForest_EventScript_UnhideOutsideSmeargle::
	clearflag FLAG_HIDE_OUTSIDE_SMEARGLE
	return
	
CutsceneForest_EventScript_FindLostIdol::
	lockall
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, CutsceneForest_Movement_CameraFastPanDown7
	delay 80
	fadescreen FADE_FROM_BLACK
	delay 20
	applymovement LOCALID_FOREST_LOST_IDOL, CutsceneForest_Movement_LostIdolLost
	waitmovement 0
	delay 40
	speak LOCALID_FOREST_LOST_IDOL, DIR_EAST, Name_Right_Idol, CutsceneForest_Text_LostIdolLost
	closemessage
	delay 60
	applymovement LOCALID_FOREST_LOST_IDOL, Common_Movement_FaceLeft
	waitmovement 0
	delay 80
	playse SE_PIN
	applymovement LOCALID_FOREST_LOST_IDOL, Common_Movement_FaceUpExclamationMark
	waitmovement 0
	delay 50
	speak LOCALID_FOREST_LOST_IDOL, DIR_NORTH, Name_Right_Idol, CutsceneForest_Text_LostIdolImSaved
	closemessage
	delay 50
	applymovement LOCALID_PLAYER, CutsceneForest_Movement_PlayerWalkIntoFrame
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_FaceDownQuestionMark
	waitmovement 0
	delay 50
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_FOREST_LOST_IDOL, Common_Movement_FaceRight
	speak LOCALID_PLAYER, DIR_WEST, Name_Looker, Looker_Text_Huh
	speak LOCALID_FOREST_LOST_IDOL, DIR_EAST, Name_Right_Idol, CutsceneForest_Text_LostIdolImLost
	speak LOCALID_PLAYER, DIR_WEST, Name_Looker, CutsceneForest_Text_LookerOhLetMeHelp
	closemessage
	applymovement LOCALID_PLAYER, CutsceneForest_Movement_LookerGuideIdolHome
	delay 16
	applymovement LOCALID_FOREST_LOST_IDOL, CutsceneForest_Movement_LookerGuideIdolHome
	delay 32
	fadescreen FADE_TO_BLACK
	setflag FLAG_SYS_SPAWN_INVISIBLE
	special RemoveCameraObject
	warp MAP_PRESENT_TOWN, 16, 5
	waitstate
	releaseall
	end

CutsceneForest_Movement_CameraFastPanDown7:
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end
	
CutsceneForest_Movement_SmeargleExcited:
	jump_in_place_up
	jump_in_place_up
	step_end

CutsceneForest_Movement_SmeargleScared:
	shake_horizontal
	shake_horizontal
	shake_horizontal
	step_end

CutsceneForest_Movement_LostIdolLost:
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	delay_16
	delay_16
	walk_left
	walk_left
	delay_16
	delay_4
	step_end

CutsceneForest_Movement_PlayerWalkIntoFrame:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CutsceneForest_Movement_WalkDown4:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CutsceneForest_Movement_WalkDown6:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CutsceneForest_Movement_WalkUp6:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	
CutsceneForest_Movement_LookerGuideIdolHome:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CutsceneForest_Movement_LookerGuideSmeargleHome:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CutsceneForest_Movement_SmeargleFollowLooker:
	delay_16
	face_right
	delay_16
	delay_16
	face_down
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
	
CutsceneForest_EventScript_SearchForEstella::
	lockall
	special SpawnCameraObject
	setvar VAR_0x8004, 10  @ x
	setvar VAR_0x8005, 9  @ y
	special TeleportCamera
	delay 150
	clearflag FLAG_SYS_PREVENT_MAP_FADE
	fadescreen FADE_FROM_BLACK
	delay 10
	applymovement LOCALID_PLAYER, CutsceneForest_Movement_PlayerRunIntoShot
	applymovement LOCALID_FOREST_RANGER, CutsceneForest_Movement_RangerRunIntoShot
	applymovement LOCALID_FOREST_ANABEL, CutsceneForest_Movement_AnabelRunIntoShot
	waitmovement 0
	delay 10
	applymovement LOCALID_FOREST_ANABEL, CutsceneForest_Movement_LookAround1
	applymovement LOCALID_FOREST_RANGER, CutsceneForest_Movement_LookAround2
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	speakername Name_Looker
	message CutsceneForest_Text_LookerEstella
	delay 60
	closemessage
	delay 40
	applymovement LOCALID_PLAYER, CutsceneForest_Movement_LookAround3
	applymovement LOCALID_FOREST_RANGER, CutsceneForest_Movement_LookAround4
	applymovement LOCALID_FOREST_ANABEL, Common_Movement_WalkInPlaceFasterRight
	speakername Name_Anabel
	message CutsceneForest_Text_AnabelEstella
	waitmessage
	delay 60
	closemessage
	delay 40
	speak LOCALID_FOREST_ANABEL, DIR_WEST, Name_Anabel, CutsceneForest_Text_AnabelDrat
	speak LOCALID_FOREST_RANGER, DIR_EAST, Name_Head_Ranger, CutsceneForest_Text_RangerSeemsLikeShesNotHere
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	playse SE_SELECT
	msgbox CutsceneForest_Text_RangerMeetBackAtCityHall, MSGBOX_DEFAULT
	speak LOCALID_FOREST_ANABEL, DIR_WEST, Name_Anabel, CutsceneForest_Text_AnabelGotIt
	speak LOCALID_PLAYER, DIR_SOUTH, Name_Looker, CutsceneForest_Text_LookerUnderstood
	speak LOCALID_FOREST_RANGER, DIR_EAST, Name_Head_Ranger, CutsceneForest_Text_RangerGreatBeSafe
	closemessage
	delay 10
	applymovement LOCALID_FOREST_RANGER, CutsceneForest_Movement_RangerRunOutOfShot
	applymovement LOCALID_PLAYER, CutsceneForest_Movement_PlayerRunOutOfShot
	applymovement LOCALID_FOREST_ANABEL, CutsceneForest_Movement_AnabelRunOutOfShot
	waitmovement 0
	delay 200
	applymovement LOCALID_FOREST_CELEBI, CutsceneForest_Movement_CelebiFloatInOutOfShot
	waitmovement 0
	setobjectmovementtype LOCALID_FOREST_CELEBI, MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_UP
	playmoncry SPECIES_CELEBI, CRY_MODE_NORMAL
	message CutsceneForest_Text_Celebi
	waitmessage
	delay 80
	closemessage
	applymovement LOCALID_FOREST_CELEBI, CutsceneForest_Movement_CelebiFloatInOutOfShot
	fadescreen FADE_TO_BLACK
	delay 60
	message CutsceneForest_Text_RepelsEffect
	waitmessage
	delay 80
	closemessage
	delay 100
	special ReturnCameraToPlayer
	setflag FLAG_HIDE_CUTSCENE_FOREST_MAINQUEST
	warpsilent MAP_SHRINE_OF_PEACE_PRESENT, 14, 28
	waitstate
	end

CutsceneForest_Movement_LookAround1:
	face_up
	delay_16
	face_down
	delay_16
	delay_16
	face_right
	step_end

CutsceneForest_Movement_LookAround2:
	face_left
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	step_end

CutsceneForest_Movement_LookAround3:
	face_left
	delay_16
	face_down
	delay_16
	delay_8
	face_up
	step_end

CutsceneForest_Movement_LookAround4:
	face_down
	delay_16
	delay_16
	delay_8
	face_left
	step_end

CutsceneForest_Movement_CelebiFloatInOutOfShot:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CutsceneForest_Movement_PlayerRunOutOfShot:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end
	
CutsceneForest_Movement_RangerRunOutOfShot:
	walk_fast_up
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

CutsceneForest_Movement_AnabelRunOutOfShot:
	delay_8
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

CutsceneForest_Movement_PlayerRunIntoShot:
	walk_faster_up
	walk_faster_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	step_end

CutsceneForest_Movement_RangerRunIntoShot:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_8
	face_up
	delay_16
	face_down
	delay_16
	face_left
	step_end

CutsceneForest_Movement_AnabelRunIntoShot:
	delay_8
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	face_right
	delay_16
	face_down
	delay_16
	face_up
	delay_16
	face_left
	step_end

CutsceneForest_Text_Smeargle:
	.string "Smurr…$"

CutsceneForest_Text_SmeargleHappy:
	.string "Smurr!$"

CutsceneForest_Text_LookerYouMustBeSmeargle:
	.string "Ah, you must be Vinnie.$"

CutsceneForest_Text_LookerLetsGoHome:
	.string "Come with me. I can guide you back\n"
	.string "to Porta Bella City.$"

CutsceneForest_Text_LostIdolLost:
	.string "Ohhh…\p"
	.string "No matter which way I turn, every\n"
	.string "path looks the same…$"

CutsceneForest_Text_LostIdolImSaved:
	.string "Oh my gosh!\p"
	.string "Thank Arceus, I'm saved!$"

CutsceneForest_Text_LostIdolImLost:
	.string "Oh sir, I've been lost in these woods\n"
	.string "ever since a group of wild Mightyena\l"
	.string "separated me from the rest of my\l"
	.string "troupe!\p"
	.string "I don't know how long it's been since\n"
	.string "then…$"

CutsceneForest_Text_LookerOhLetMeHelp:
	.string "Ah, I see.\p"
	.string "Here, I can guide you back to Porta\n"
	.string "Bella City.$"

CutsceneForest_Text_RepelsEffect:
	.string "Repels' effect wore off…$"

CutsceneForest_Text_Celebi:
	.string "Biii…$"

CutsceneForest_Text_AnabelEstella:
	.string "Estellaaaa!$"

CutsceneForest_Text_LookerEstella:
	.string "Estella!$"

CutsceneForest_Text_AnabelGotIt:
	.string "Got it.\n"
	.string "Looker?$"

CutsceneForest_Text_LookerUnderstood:
	.string "Understood.$"

CutsceneForest_Text_RangerGreatBeSafe:
	.string "Great. Please be safe out there!$"

CutsceneForest_Text_LookerOfCourse:
	.string "Of course.$"

CutsceneForest_Text_AnabelDrat:
	.string "Drat, there's been no sign of her at\n"
	.string "all out here!$"

CutsceneForest_Text_RangerSeemsLikeShesNotHere:
	.string "She doesn't seem to be in this neck\n"
	.string "of the woods!$"

CutsceneForest_Text_RangerMeetBackAtCityHall:
	.string "Looker.\n"
	.string "Anabel.\p"
	.string "The trail branches off up ahead -\n"
	.string "one way goes to the shrine and the\l"
	.string "other loops back to the entrance.\p"
	.string "I'll take the loop,\n"
	.string "you take the shrine.\p"
	.string "Whether you find her or not, meet me\n"
	.string "back at the Ranger's bureau in City\l"
	.string "Hall later.\p"
	.string "Our office is in the left wing of the\n"
	.string "building. Got it?$"

CutsceneForest_Text_MonFlewAway:
	.string "{STR_VAR_1} flew away!$"

CutsceneForest_Text_MonSlitheredAway:
	.string "{STR_VAR_1} slithered away!$"

CutsceneForest_Text_MonRanAway:
	.string "{STR_VAR_1} ran away!$"

CutsceneForest_Text_Dedenne:
	.string "Tsi? Tsi-tsi!$"

CutsceneForest_Text_Togedemaru:
	.string "To?$"

CutsceneForest_Text_Lurantis:
	.string "Luuuoowaaa!$"

CutsceneForest_Text_Luxray:
	.string "Rrrrrr…?$"

CutsceneForest_Text_LuxrayDark:
	.string "Grr! Grrrrr!$"

CutsceneForest_Text_Toedscruel:
	.string "Skweweee!$"

CutsceneForest_Text_Frosmoth:
	.string "Shhhhhhh…$"

CutsceneForest_Text_Kleavor:
	.string "Kaaaa!$"

CutsceneForest_Text_GoodraHisui:
	.string "Gooo…$"

CutsceneForest_Text_Beheeyem:
	.string "Skreeeeeeee!$"

CutsceneForest_Text_Aerodactyl:
	.string "Raaaaaaa!$"

CutsceneForest_Text_ScreamTail:
	.string "LalalaLAAAAAAAAA!$"

CutsceneForest_Text_Aromatisse:
	.string "Ara?\p"
	.string "Ara-ara-ara-ara-ara!$"

CutsceneForest_Text_WoChien:
	.string "ooOOOoOOoooOOO!$"

CutsceneForest_Text_LookerLuxraySeemsDifferent:
	.string "Hmm? This Luxray seems strange…\p"
	.string "No matter.$"

CutsceneForest_Text_LuxrayReward:
	.string "I should show this Luxray to those two\n"
	.string "children and settle their dispute.$"

CutsceneForest_Text_LookerThatShouldBeIt:
	.string "Hmm! I believe that is all the unique\n"
	.string "Pokémon of this forest!$"

CutsceneForest_Text_LookerCatchMons:
	.string "Hmm…\p"
	.string "Perhaps I could catch some Pokémon in\n"
	.string "this forest to assist in my\l"
	.string "investigation…$"

CutsceneForest_Text_LookerShoot:
	.string "Shoot! They noticed me!\n"
	.string "I think I can only pursue one!\p"
	.string "But which one should I pursue?$"

CutsceneForest_Text_LookerPursueDedenne:
	.string "I think I will try to catch the\n"
	.string "Dedenne!$"

CutsceneForest_Text_LookerPursueTogedemaru:
	.string "I think I will try to catch the\n"
	.string "Togedemaru!$"

CutsceneForest_Text_LookerThatsUnfortunate:
	.string "That's unfortunate.\p"
	.string "Oh well. Perhaps I will get another\n"
	.string "chance at it in the future…$"

CutsceneForest_Text_LookerCaughtRodent:
	.string "Yes! I caught it!\p"
	.string "I wonder what other Pokemon live in\n"
	.string "this strange forest…$"