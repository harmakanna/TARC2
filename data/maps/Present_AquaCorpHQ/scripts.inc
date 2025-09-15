Present_AquaCorpHQ_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Present_AquaCorpHQ_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, Present_AquaCorpHQ_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Present_AquaCorpHQ_OnResume
	.byte 0

Present_AquaCorpHQ_OnFrame:
	map_script_2 VAR_AQUACORP_STATE, 0, Present_AquaCorpHQ_EventScript_StartAquaGauntlet
	map_script_2 VAR_AQUACORP_STATE, 1, Present_AquaCorpHQ_EventScript_StartAquaGauntletRematch
	.2byte 0

Present_AquaCorpHQ_OnResume:
	call_if_eq VAR_AQUACORP_STATE, 1, Present_AquaCorpHP_EventScript_SaveLookerMusic
	special HealPlayerParty
	end
	
Present_AquaCorpHQ_OnTransition:
	call_if_lt VAR_AQUACORP_STATE, 2, Present_AquaCorpHQ_EventScript_SetAquaCorpNPCsForGauntlet
	call_if_eq VAR_AQUACORP_STATE, 1, Present_AquaCorpHQ_EventScript_SetShellyForGauntletRematch
	end

Present_AquaCorpHP_EventScript_SaveLookerMusic:
	savebgm MUS_PL_LOOKER
	return

Present_AquaCorpHQ_EventScript_SetAquaCorpNPCsForGauntlet::
	setobjectxyperm LOCALID_AQUACORP_WAILMER_SCIENTIST, 3, 12
	setobjectxyperm LOCALID_AQUACORP_WAILMER_GRUNT, 3, 2
	setobjectxyperm LOCALID_AQUACORP_SHELDON, 5, 4
	setobjectxyperm LOCALID_AQUACORP_MATT, 6, 4
	setobjectxyperm LOCALID_AQUACORP_SARAH, 11, 5
	setobjectmovementtype LOCALID_AQUACORP_WAILMER_SCIENTIST, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype LOCALID_AQUACORP_WAILMER_GRUNT, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_AQUACORP_SHELDON, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_AQUACORP_MATT, MOVEMENT_TYPE_FACE_LEFT
	return

Present_AquaCorpHQ_EventScript_SetShellyForGauntletRematch::
	setobjectxyperm LOCALID_AQUACORP_SHELLY, 11, 4
	setobjectmovementtype LOCALID_AQUACORP_SHELLY, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_AQUACORP_SARAH, MOVEMENT_TYPE_FACE_UP
	return

Present_AquaCorpHQ_EventScript_StartAquaGauntlet::
	lockall
	setvar VAR_AQUACORP_STATE, 1
	applymovement LOCALID_PLAYER, Present_AquaCorpHQ_Movement_LookerApproachMatt
	waitmovement 0
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_AquaCorpHQ_Text_LookerMatt
	closemessage
	playse SE_PIN
	applymovement LOCALID_AQUACORP_MATT, Common_Movement_FaceDownExclamationMark
	applymovement LOCALID_AQUACORP_SHELDON, Common_Movement_FaceDownExclamationMark
	delay 60
	speak LOCALID_AQUACORP_MATT, DIR_SOUTH, Name_Matt, Present_AquaCorpHQ_Text_MattWhyAreYouHere
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_AquaCorpHQ_Text_LookerYoureUnderArrest
	closemessage
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp2
	delay 40
	speak LOCALID_AQUACORP_MATT, DIR_SOUTH, Name_Matt, Present_AquaCorpHQ_Text_MattWhat
	closemessage
	fadeoutbgm 1
	delay 60
	applymovement LOCALID_AQUACORP_MATT, Common_Movement_FaceLeft
	delay 60
	applymovement LOCALID_AQUACORP_MATT, Common_Movement_FaceRight
	delay 60
	applymovement LOCALID_AQUACORP_MATT, Common_Movement_FaceDown
	waitmovement 0
	speakername Name_Matt
	msgbox Present_AquaCorpHQ_Text_MattDots, MSGBOX_DEFAULT
	closemessage
	delay 40
	speak LOCALID_AQUACORP_MATT, DIR_SOUTH, Name_Matt, Present_AquaCorpHQ_Text_MattOhComeOn
	playse SE_PIN
	applymovement LOCALID_AQUACORP_WAILMER_GRUNT, Common_Movement_FaceDownQuestionMark
	applymovement LOCALID_AQUACORP_GRUNTM_TABLE, Common_Movement_FaceUp
	applymovement LOCALID_AQUACORP_WAILMER_SCIENTIST, Common_Movement_FaceUp
	applymovement LOCALID_AQUACORP_GRUNTF_TABLE, Common_Movement_FaceUp
	applymovement LOCALID_AQUACORP_GEOFF, Common_Movement_FaceRight
	applymovement LOCALID_AQUACORP_SARAH, Common_Movement_FaceLeftQuestionMark
	applymovement LOCALID_AQUACORP_SHELLY, Common_Movement_FaceLeft
	playbgm MUS_PL_LOOKER, FALSE
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown
	call_if_unset FLAG_SYS_WEATHER_CTRL, Present_AquaCorpHQ_EventScript_LookerWasAStorm
	call_if_set FLAG_SYS_WEATHER_CTRL, Present_AquaCorpHQ_EventScript_LookerIsAStorm
	speak LOCALID_AQUACORP_MATT, DIR_SOUTH, Name_Matt, Present_AquaCorpHQ_Text_MattSoWhatIfTheresAStorm
	call_if_unset FLAG_DEFEATED_SHRINE_GENIES, Present_AquaCorpHQ_EventScript_LookerGoodIntel
	call_if_set FLAG_DEFEATED_SHRINE_GENIES, Present_AquaCorpHQ_EventScript_LookerConfirmed
	playse SE_SELECT
	msgbox Present_AquaCorpHQ_Text_LookerJustThreeMonthsAgo, MSGBOX_DEFAULT
	speak LOCALID_AQUACORP_MATT, DIR_SOUTH, Name_Matt, Present_AquaCorpHQ_Text_MattGrr
	closemessage
	applymovement LOCALID_AQUACORP_SHELLY, Present_AquaCorpHQ_Movement_ShellyApproachGauntlet
	waitmovement 0
	speakername Name_Shelly
	msgbox Present_AquaCorpHQ_Text_ShellyWillYouJustStop, MSGBOX_DEFAULT
	speak LOCALID_AQUACORP_MATT, DIR_EAST, Name_Matt, Present_AquaCorpHQ_Text_MattNoIWillNot
	playse SE_SELECT
	speak LOCALID_AQUACORP_MATT, DIR_SOUTH, Name_Matt, Present_AquaCorpHQ_Text_MattEnoughOfThis
	closemessage
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown
	waitmovement 0
	special RemoveCameraObject
	goto Present_AquaCorpHQ_EventScript_AquaGauntlet
	end

Present_AquaCorpHQ_EventScript_LookerWasAStorm::
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_AquaCorpHQ_Text_LookerThereWasAStorm
	return

Present_AquaCorpHQ_EventScript_LookerIsAStorm::
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_AquaCorpHQ_Text_LookerThereIsAStorm
	return

Present_AquaCorpHQ_EventScript_LookerGoodIntel::
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_AquaCorpHQ_Text_LookerWeHaveItOnGoodIntel
	return

Present_AquaCorpHQ_EventScript_LookerConfirmed::
	call_if_set FLAG_SYS_WEATHER_CTRL, Present_AquaCorpHQ_EventScript_ConfirmedIs
	call_if_unset FLAG_SYS_WEATHER_CTRL, Present_AquaCorpHQ_EventScript_ConfirmedWas
	return

Present_AquaCorpHQ_EventScript_ConfirmedIs::
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_AquaCorpHQ_Text_LookerWeHaveConfirmedAreBeing
	return

Present_AquaCorpHQ_EventScript_ConfirmedWas::
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_AquaCorpHQ_Text_LookerWeHaveConfirmed
	return

Present_AquaCorpHQ_EventScript_StartAquaGauntletRematch::
	lockall
	applymovement LOCALID_PLAYER, Present_AquaCorpHQ_Movement_LookerApproachMattFast
	waitmovement 0
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_AquaCorpHQ_Text_LookerImBack
	closemessage
	playse SE_PIN
	applymovement LOCALID_AQUACORP_MATT, Common_Movement_FaceDownExclamationMark
	applymovement LOCALID_AQUACORP_SHELDON, Common_Movement_FaceDownExclamationMark
	delay 60
	applymovement LOCALID_AQUACORP_GRUNTF_TABLE, Common_Movement_FaceUp
	applymovement LOCALID_AQUACORP_WAILMER_GRUNT, Common_Movement_FaceDown
	applymovement LOCALID_AQUACORP_WAILMER_SCIENTIST, Common_Movement_FaceUp
	applymovement LOCALID_AQUACORP_GRUNTM_TABLE, Common_Movement_FaceUp
	applymovement LOCALID_AQUACORP_GEOFF, Common_Movement_FaceRight
	applymovement LOCALID_AQUACORP_SARAH, Common_Movement_FaceLeft
	applymovement LOCALID_AQUACORP_SHELLY, Common_Movement_FaceLeft
	speak LOCALID_AQUACORP_MATT, DIR_SOUTH, Name_Matt, Present_AquaCorpHQ_Text_MattYouWantMore
	applymovement LOCALID_AQUACORP_SHELLY, Present_AquaCorpHQ_Movement_ShellyApproachGauntlet
	waitmovement 0
	speak LOCALID_AQUACORP_SHELLY, DIR_WEST, Name_Shelly, Present_AquaCorpHQ_Text_ShellyThisIsntHelping
	speak LOCALID_AQUACORP_MATT, DIR_EAST, Name_Matt, Present_AquaCorpHQ_Text_MattTheGuyWontLeaveUsAlone
	playse SE_SELECT
	speak LOCALID_AQUACORP_MATT, DIR_SOUTH, Name_Matt, Present_AquaCorpHQ_Text_MattWeGottaTeachHim
	closemessage
	goto Present_AquaCorpHQ_EventScript_AquaGauntlet
	end

@ First grunt: TRAINER_GRUNT_AQUA_HIDEOUT_1
Present_AquaCorpHQ_EventScript_AquaGauntlet::
	applymovement LOCALID_AQUACORP_SHELDON, Present_AquaCorpHQ_Movement_SheldonRushLooker
	applymovement LOCALID_AQUACORP_GEOFF, Present_AquaCorpHQ_Movement_GeoffRushLooker
	applymovement LOCALID_AQUACORP_SARAH, Present_AquaCorpHQ_Movement_SarahRushLooker
	waitmovement 0
	delay 10
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	speak LOCALID_AQUACORP_GEOFF, DIR_EAST, Name_Aqua_Grunt_M, Present_AquaCorpHQ_Text_GeoffIntro
	savebgm MUS_DUMMY
	trainerbattle_no_intro TRAINER_GRUNT_AQUA_HIDEOUT_1, Present_AquaCorpHQ_Text_GeoffDefeat
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, Present_AquaCorpHQ_EventScript_KickLookerOut
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Present_AquaCorpHQ_EventScript_KickLookerOut
	goto Present_AquaCorpHQ_EventScript_AquaGauntletSecondTrainer
	end

@ Second grunt: TRAINER_GRUNT_AQUA_HIDEOUT_2
Present_AquaCorpHQ_EventScript_AquaGauntletSecondTrainer::
	speak LOCALID_AQUACORP_GEOFF, DIR_EAST, Name_Geoff, Present_AquaCorpHQ_Text_GeoffUnfulfilling
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	speak LOCALID_AQUACORP_SARAH, DIR_WEST, Name_Aqua_Grunt_F, Present_AquaCorpHQ_Text_SarahIntro
	savebgm MUS_DUMMY
	trainerbattle_no_intro TRAINER_GRUNT_AQUA_HIDEOUT_2, Present_AquaCorpHQ_Text_SarahDefeat
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Present_AquaCorpHQ_EventScript_KickLookerOut
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, Present_AquaCorpHQ_EventScript_KickLookerOut
	goto Present_AquaCorpHQ_EventScript_AquaGauntletThirdTrainer
	end

@ Third grunt: TRAINER_GRUNT_AQUA_HIDEOUT_3
Present_AquaCorpHQ_EventScript_AquaGauntletThirdTrainer::
	speak LOCALID_AQUACORP_SARAH, DIR_WEST, Name_Sarah, Present_AquaCorpHQ_Text_SarahCmonGuys
	closemessage
	applymovement LOCALID_AQUACORP_SHELDON, Common_Movement_FaceRight
	applymovement LOCALID_AQUACORP_SARAH, Present_AquaCorpHQ_Movement_SarahLeave
	waitmovement 0
	delay 40
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	speak LOCALID_AQUACORP_SHELDON, DIR_SOUTH, Name_Aqua_Grunt_M, Present_AquaCorpHQ_Text_SheldonIntro
	savebgm MUS_DUMMY
	trainerbattle_no_intro TRAINER_GRUNT_AQUA_HIDEOUT_3, Present_AquaCorpHQ_Text_SheldonDefeat
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Present_AquaCorpHQ_EventScript_KickLookerOut
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, Present_AquaCorpHQ_EventScript_KickLookerOut
	goto Present_AquaCorpHQ_EventScript_AquaGauntletMatt
	end

Present_AquaCorpHQ_EventScript_AquaGauntletMatt::
	speak LOCALID_AQUACORP_SHELDON, DIR_SOUTH, Name_Sheldon, Present_AquaCorpHQ_Text_SheldonMyCrabs
	speak LOCALID_AQUACORP_MATT, DIR_SOUTH, Name_Matt, Present_AquaCorpHQ_Text_MattBunchOfWorthless
	closemessage
	applymovement LOCALID_AQUACORP_MATT, Present_AquaCorpHQ_MattPushSheldon
	playse SE_EFFECTIVE
	applymovement LOCALID_AQUACORP_SHELDON, Present_AquaCorpHQ_SheldonPushed
	waitmovement 0
	speakername Name_Sheldon
	msgbox Present_AquaCorpHQ_Text_SheldonOw, MSGBOX_DEFAULT
	speak LOCALID_AQUACORP_MATT, DIR_SOUTH, Name_Matt, Present_AquaCorpHQ_Text_MattGottaDoItYourself
	trainerbattle_no_intro TRAINER_MATT, Present_AquaCorpHQ_Text_MattDefeat
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Present_AquaCorpHQ_EventScript_KickLookerOut
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, Present_AquaCorpHQ_EventScript_KickLookerOut
	goto Present_AquaCorpHQ_EventScript_AquaGauntletMattDefeated
	end

Present_AquaCorpHQ_EventScript_AquaGauntletMattDefeated::
	speak LOCALID_AQUACORP_MATT, DIR_SOUTH, Name_Matt, Present_AquaCorpHQ_Text_MattAreYouKiddingMe
	playbgm MUS_NONE, FALSE
	speak LOCALID_AQUACORP_SHELLY, DIR_WEST, Name_Shelly, Present_AquaCorpHQ_Text_ShellyEnough
	closemessage
	playse SE_PIN
	applymovement LOCALID_AQUACORP_MATT, Common_Movement_FaceRightExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_FaceRightExclamationMark
	delay 60
	applymovement LOCALID_AQUACORP_SHELLY, Present_AquaCorpHQ_Movement_ShellyWalkToMatt
	waitmovement 0
	speak LOCALID_AQUACORP_SHELLY, DIR_WEST, Name_Shelly, Present_AquaCorpHQ_Text_ShellyHaventYouNoticed
	speak LOCALID_AQUACORP_MATT, DIR_EAST, Name_Matt, Present_AquaCorpHQ_Text_MattSorry
	closemessage
	applymovement LOCALID_AQUACORP_SHELLY, Common_Movement_WalkDown
	waitmovement 0
	speak LOCALID_AQUACORP_SHELLY, DIR_WEST, Name_Shelly, Present_AquaCorpHQ_Text_ShellyAndLookerYou
	speak LOCALID_PLAYER, DIR_EAST, Name_Looker, Present_AquaCorpHQ_Text_LookerSorry
	speak LOCALID_AQUACORP_SHELLY, DIR_WEST, Name_Shelly, Present_AquaCorpHQ_Text_ShellyLookerComeHere
	speak LOCALID_PLAYER, DIR_EAST, Name_Looker, Present_AquaCorpHQ_Text_LookerOkay
	closemessage
	applymovement LOCALID_AQUACORP_SHELLY, Present_AquaCorpHQ_Movement_ShellyWalkToWailmer
	applymovement LOCALID_PLAYER, Present_AquaCorpHQ_Movement_LookerFollowToWailmer
	waitmovement 0
	speak LOCALID_AQUACORP_SHELLY, DIR_EAST, Name_Shelly, Present_AquaCorpHQ_Text_ShellyWeAreResearchers
	speak LOCALID_AQUACORP_SARAH, DIR_SOUTH, Name_Sarah, Present_AquaCorpHQ_Text_SarahShellyDots
	closemessage
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_AQUACORP_SHELLY, Common_Movement_FaceUpQuestionMark
	applymovement LOCALID_AQUACORP_SARAH, Present_AquaCorpHQ_Movement_SarahWalkToShelly
	waitmovement 0
	speak LOCALID_AQUACORP_SARAH, DIR_SOUTH, Name_Sarah, Present_AquaCorpHQ_Text_SarahCanWeClamperl
	speak LOCALID_AQUACORP_SHELLY, DIR_NORTH, Name_Shelly, Present_AquaCorpHQ_Text_ShellyOfCourseWeCan
	speak LOCALID_AQUACORP_SARAH, DIR_SOUTH, Name_Sarah, Present_AquaCorpHQ_Text_SarahIllPrepareTheDeepSea
	closemessage
	applymovement LOCALID_AQUACORP_SHELLY, Common_Movement_FaceUp
	applymovement LOCALID_AQUACORP_SARAH, Present_AquaCorpHQ_Movement_SarahRunToClamperl
	waitmovement 0
	delay 10
	speak LOCALID_AQUACORP_SHELLY, DIR_SOUTH, Name_Shelly, Present_AquaCorpHQ_Text_ShellyLookerComeSeeClamperl
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_AQUACORP_SARAH, Present_AquaCorpHQ_Movement_SarahWalkUpToClam
	applymovement LOCALID_AQUACORP_SHELLY, Present_AquaCorpHQ_Movement_ShellyWalkToClamperl
	applymovement LOCALID_PLAYER, Present_AquaCorpHQ_Movement_LookerFollowToClamperl
	waitmovement 0
	delay 40
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	speak LOCALID_AQUACORP_SHELLY, DIR_SOUTH, Name_Shelly, Present_AquaCorpHQ_Text_ShellyThisClamperl
	applymovement LOCALID_AQUACORP_SHELLY, Common_Movement_FaceUp
	speak LOCALID_AQUACORP_SARAH, DIR_SOUTH, Name_Sarah, Present_AquaCorpHQ_Text_SarahClamperlIsReady
	speak LOCALID_AQUACORP_SHELLY, DIR_NORTH, Name_Shelly, Present_AquaCorpHQ_Text_ShellyLetLookerDecide
	speak LOCALID_AQUACORP_SHELLY, DIR_SOUTH, Name_Shelly, Present_AquaCorpHQ_Text_ShellyWhichItemWouldYouWantToUse
	multichoice 0, 6, MULTI_MATT_GIVEMON, TRUE
	goto_if_eq VAR_RESULT, 0, Present_AquaCorpHQ_EventScript_ShellyGiveGorebyss
	goto_if_eq VAR_RESULT, 1, Present_AquaCorpHQ_EventScript_ShellyGiveHuntail
	end

Present_AquaCorpHQ_EventScript_FinishAquaGauntlet::
	fadescreenswapbuffers FADE_TO_BLACK
	delay 20
	fadeoutbgm 0
	delay 20
	closemessage
	removeobject LOCALID_GOREBYSS
	removeobject LOCALID_HUNTAIL
	clearflag FLAG_HIDE_SHELDON_KRABBY
	addobject LOCALID_KRABBY
	setobjectxy LOCALID_AQUACORP_WAILMER_SCIENTIST, 9, 11
	setobjectxy LOCALID_AQUACORP_WAILMER_GRUNT, 9, 9
	setobjectxy LOCALID_AQUACORP_SHELDON, 14, 6
	setobjectxy LOCALID_AQUACORP_MATT, 7, 3
	setobjectxy LOCALID_AQUACORP_SHELLY, 11, 4
	setobjectxy LOCALID_AQUACORP_SARAH, 11, 5
	setobjectxy LOCALID_AQUACORP_GEOFF, 1, 6
	setobjectxyperm LOCALID_AQUACORP_WAILMER_SCIENTIST, 9, 11
	setobjectxyperm LOCALID_AQUACORP_WAILMER_GRUNT, 9, 9
	setobjectxyperm LOCALID_AQUACORP_SHELDON, 14, 6
	setobjectxyperm LOCALID_AQUACORP_MATT, 7, 3
	setobjectxyperm LOCALID_AQUACORP_SHELLY, 11, 4
	setobjectxyperm LOCALID_AQUACORP_SARAH, 11, 5
	setobjectxyperm LOCALID_AQUACORP_GEOFF, 1, 6
	setobjectmovementtype LOCALID_AQUACORP_WAILMER_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_AQUACORP_WAILMER_GRUNT, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_AQUACORP_SHELDON, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_AQUACORP_MATT, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_AQUACORP_SHELLY, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_AQUACORP_SARAH, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_AQUACORP_GEOFF, MOVEMENT_TYPE_FACE_UP
	applymovement LOCALID_AQUACORP_WAILMER_SCIENTIST, Common_Movement_FaceRight
	applymovement LOCALID_AQUACORP_WAILMER_GRUNT, Common_Movement_FaceRight
	applymovement LOCALID_AQUACORP_SHELDON, Common_Movement_FaceDown
	applymovement LOCALID_AQUACORP_MATT, Common_Movement_FaceUp
	applymovement LOCALID_AQUACORP_SHELLY, Common_Movement_FaceDown
	applymovement LOCALID_AQUACORP_SARAH, Common_Movement_FaceUp
	applymovement LOCALID_AQUACORP_GEOFF, Common_Movement_FaceUp
	applymovement LOCALID_PLAYER, Present_AquaCorpHQ_Movement_MoveLookerToPostCutscene
	waitmovement 0
	setvar VAR_AQUACORP_STATE, 2
	setvar VAR_PLAY_LOOKER_SCENE_ON_TRANSITION, 1
	setflag FLAG_DEFEATED_MATT
	fadescreenswapbuffers FADE_FROM_BLACK
	completequest QUEST_INTERROGATE_MATT
	playbgm MUS_DP_VEILSTONE_DAY, FALSE
	setflag FLAG_SYS_NO_MUSIC_ON_TRANSITION
	setflag FLAG_PLAY_LOOKER_AQUA_ON_TRANSITION
	releaseall
	end

Present_AquaCorpHQ_Movement_MoveLookerToPostCutscene:
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	face_down
	step_end
	
Present_AquaCorpHQ_Movement_LookerApproachMatt:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Present_AquaCorpHQ_Movement_LookerApproachMattFast:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end
	
Present_AquaCorpHQ_Movement_FaceRightQuestionMark:
	face_right
	emote_question_mark
	step_end
	
Present_AquaCorpHQ_Movement_FaceUpQuestionMark:
	face_up
	emote_question_mark
	step_end

Present_AquaCorpHQ_Movement_WailmerScientistWalkToSee:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

Present_AquaCorpHQ_Movement_WailmerGruntWalkToSee:
	walk_left
	walk_left
	face_up
	step_end

Present_AquaCorpHQ_Movement_TableGruntMWalkToSee:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

Present_AquaCorpHQ_Movement_TableGruntFWalkToSee:
	walk_right
	walk_right
	face_up
	step_end

Present_AquaCorpHQ_Movement_ShellyApproachGauntlet:
	walk_left
	walk_left
	step_end

Present_AquaCorpHQ_Movement_SheldonRushLooker:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_down
	step_end

Present_AquaCorpHQ_Movement_GeoffRushLooker:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Present_AquaCorpHQ_Movement_SarahRushLooker:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_left
	step_end

Present_AquaCorpHQ_MattPushSheldon:
	walk_faster_down
	walk_in_place_faster_down
	step_end

Present_AquaCorpHQ_SheldonPushed:
	face_right
	lock_facing_direction
	walk_faster_left
	walk_faster_left
	unlock_facing_direction
	step_end

Present_AquaCorpHQ_Movement_SarahLeave:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end

Present_AquaCorpHQ_Movement_ShellyWalkToMatt:
	walk_down
	walk_left
	walk_left
	step_end

Present_AquaCorpHQ_Movement_ShellyWalkToLooker:
	walk_down
	face_left
	step_end

Present_AquaCorpHQ_Movement_ShellyWalkToWailmer:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

Present_AquaCorpHQ_Movement_LookerFollowToWailmer:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end
	
Present_AquaCorpHQ_Movement_SarahWalkToShelly:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Present_AquaCorpHQ_Movement_SarahRunToClamperl:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Present_AquaCorpHQ_Movement_SarahWalkUpToClam:
	walk_up
	face_down
	step_end

Present_AquaCorpHQ_Movement_ShellyWalkToClamperl:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

Present_AquaCorpHQ_Movement_LookerFollowToClamperl:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_down
	walk_right
	step_end

Present_AquaCorpHQ_Movement_SarahGiveDeepSea:	
	walk_right
	face_down
	step_end

Present_AquaCorpHQ_Movement_MattApproachLooker:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
	
Present_AquaCorpHQ_Movement_MonWalkToPlayer:
	walk_down
	walk_left
	step_end

Present_AquaCorpHQ_EventScript_KickLookerOut::
	speak LOCALID_AQUACORP_MATT, DIR_SOUTH, Name_Matt, Present_AquaCorpHQ_Text_MattTakeThat
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	speakername Name_Looker
	msgbox Present_AquaCorpHQ_Text_LookerThisIsBad
	closemessage
	warp MAP_PRESENT_TOWN, 15, 35
	waitstate
	releaseall
	end

Present_AquaCorpHQ_EventScript_Krabby::
	lock
	@faceplayer
	waitse
	playmoncry SPECIES_KRABBY, CRY_MODE_NORMAL
	msgbox Present_AquaCorpHQ_Text_Krabby, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	release
	end

Present_AquaCorpHQ_EventScript_Sarah::
	lock
	faceplayer
	speakername Name_Sarah
	goto_if_set FLAG_SPOKE_TO_ANGRY_MAN_POST_AQUACORP, Present_AquaCorpHQ_EventScript_SarahBlush
	msgbox Present_AquaCorpHQ_Text_SarahNPC, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_AQUACORP_SARAH, Common_Movement_FaceUp
	waitmovement 0
	release
	end

Present_AquaCorpHQ_EventScript_SarahBlush::
	msgbox Present_AquaCorpHQ_Text_SarahBlushNPC, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_AQUACORP_SARAH, Common_Movement_FaceUp
	waitmovement 0
	release
	end

Present_AquaCorpHQ_EventScript_Geoff::
	speakername Name_Geoff
	msgbox Present_AquaCorpHQ_Text_Geoff, MSGBOX_NPC
	end 

Present_AquaCorpHQ_EventScript_Sheldon::
	lock
	speakername Name_Sheldon
	msgbox Present_AquaCorpHQ_Text_Sheldon, MSGBOX_DEFAULT
	closemessage
	release
	end

Present_AquaCorpHQ_EventScript_Matt::
	lock
	faceplayer
	call Script_GetNPCFacingDirection
	speak LOCALID_AQUACORP_MATT, VAR_0x8005, Name_Matt, Present_AquaCorpHQ_Text_MattNPC
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_AquaCorpHQ_Text_LookerNoneWhatsoever
	closemessage
	release
	end

Present_AquaCorpHQ_EventScript_Shelly::
	lock
	faceplayer
	speakername Name_Shelly
	msgbox Present_AquaCorpHQ_Text_ShellyNPC, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_AQUACORP_SHELLY, Common_Movement_FaceDown
	waitmovement 0
	release
	end

Present_AquaCorpHQ_EventScript_TableGrunts::
	lock
	speak LOCALID_AQUACORP_GRUNTM_TABLE, DIR_EAST, Name_Aqua_Grunt_M, Present_AquaCorpHQ_Text_TableMFeelRelaxed
	speak LOCALID_AQUACORP_GRUNTF_TABLE, DIR_WEST, Name_Aqua_Grunt_F, Present_AquaCorpHQ_Text_TableFThatsNotUs
	speak LOCALID_AQUACORP_GRUNTM_TABLE, DIR_EAST, Name_Aqua_Grunt_M, Present_AquaCorpHQ_Text_TableMHundredPercent
	speak LOCALID_AQUACORP_GRUNTF_TABLE, DIR_WEST, Name_Aqua_Grunt_F, Present_AquaCorpHQ_Text_TableFRanger
	speak LOCALID_AQUACORP_GRUNTM_TABLE, DIR_EAST, Name_Aqua_Grunt_M, Present_AquaCorpHQ_Text_TableMHeckYeah
	speak LOCALID_AQUACORP_GRUNTF_TABLE, DIR_WEST, Name_Aqua_Grunt_F, Present_AquaCorpHQ_Text_TableFAwkward
	speak LOCALID_AQUACORP_GRUNTM_TABLE, DIR_EAST, Name_Aqua_Grunt_M, Present_AquaCorpHQ_Text_TableMDoIt
	speak LOCALID_AQUACORP_GRUNTF_TABLE, DIR_WEST, Name_Aqua_Grunt_F, Present_AquaCorpHQ_Text_TableFAaa
	closemessage
	release
	end

Present_AquaCorpHQ_EventScript_WailmerScientist::
	lock
	faceplayer
	speakername Name_Scientist
	msgbox Present_AquaCorp_Text_WailmerScientist, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_AQUACORP_WAILMER_SCIENTIST, Common_Movement_FaceRight
	waitmovement 0
	release
	end

Present_AquaCorpHQ_EventScript_HappyScientist::
	speakername Name_Scientist
	msgbox Present_AquaCorpHQ_Text_HappyScientist, MSGBOX_NPC
	end

Present_AquaCorpHQ_EventScript_WailmerGrunt::
	lock
	faceplayer
	speakername Name_Aqua_Grunt_M
	msgbox Present_AquaCorpHQ_Text_WailmerGrunt, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, Present_AquaCorpHQ_EventScript_WailmerGruntTellYouAnyway
	msgbox Present_AquaCorpHQ_Text_WailmerGruntNames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_AQUACORP_WAILMER_GRUNT, Common_Movement_FaceRight
	waitmovement 0
	release
	end

Present_AquaCorpHQ_EventScript_WailmerGruntTellYouAnyway::
	msgbox Present_AquaCorpHQ_Text_WailmerGruntTellYouAnyway, MSGBOX_DEFAULT
	playse SE_SELECT
	return

Present_AquaCorpHQ_Text_WailmerGrunt:
	.string "Sshhh…\n"
	.string "They're sleeping…\p"
	.string "Wanna know their names?$"

Present_AquaCorpHQ_Text_WailmerGruntTellYouAnyway:
	.string "Oh.\p"
	.string "I'll tell you anyway!$"

Present_AquaCorpHQ_Text_WailmerGruntNames:
	.string "Their names are Ivana, Mary, and Maya!$"

Present_AquaCorp_Text_WailmerScientist:
	.string "These baby Wailmer were brought into our\n"
	.string "care after their pod abandoned them.\p"
	.string "It's been wonderful watching them grow\n"
	.string "and play these past months!\p"
	.string "Soon they'll be big enough to go off\n"
	.string "into the wild on their own…\p"
	.string "I think I'll miss them.$"

Present_AquaCorpHQ_Text_HappyScientist:
	.string "I was kind of scared to work for Team\n"
	.string "Aqua when they set up shop here.\p"
	.string "But boy, am I glad I took the job!\p"
	.string "They pay well, have great benefits, and\n"
	.string "we're not overworked like those\l"
	.string "government scientists!\p"
	.string "Heck, working directly with the marine\n"
	.string "life here has been fun as heck!$"

Present_AquaCorpHQ_Text_ShellyNPC:
	.string "With the Clamperl experiment being a\n"
	.string "success, we gotta figure out our\l"
	.string "next research goal…\p"
	.string "Perhaps we should coordinate with the\n"
	.string "rangers a bit more moving forward?$"

Present_AquaCorpHQ_Text_TableMFeelRelaxed:
	.string "Y'know, that encounter with Looker\n"
	.string "got me thinkin'.\p"
	.string "Hasn't it been a lot nicer bein' a\n"
	.string "part of Team Aqua since we stopped\l"
	.string "doin' crimes?$"

Present_AquaCorpHQ_Text_TableFThatsNotUs:
	.string "Yeah, I've felt it.\p"
	.string "I honestly felt my heart race when\n"
	.string "the accusations started flying.\p"
	.string "Like, that's not us anymore, right?\p"
	.string "That hasn't been us!$"

Present_AquaCorpHQ_Text_TableMHundredPercent:
	.string "Hundred percent with ya.$"

Present_AquaCorpHQ_Text_TableFRanger:
	.string "Y'know, I always wanted to be a\n"
	.string "Pokémon Ranger when I grew up.\p"
	.string "There's job listings open with City\n"
	.string "Hall. Think I have a chance?$"

Present_AquaCorpHQ_Text_TableMHeckYeah:
	.string "Heck yeah! The worst they can do\n"
	.string "is say no!\p"
	.string "Maybe you can ask Looker to put in a\n"
	.string "good word for you?$"

Present_AquaCorpHQ_Text_TableFAwkward:
	.string "Mmmmm, but we barely even know him!\p"
	.string "That'd feel awwwkwaaaard!$"

Present_AquaCorpHQ_Text_TableMDoIt:
	.string "He's right theeeeeere!\n"
	.string "Doooo iiiiiiiiiit!$"

Present_AquaCorpHQ_Text_TableFAaa:
	.string "Aaaaaaaaaaaaaaa!$"

Present_AquaCorpHQ_Text_MattNPC:
	.string "Heh, how was that taste of true\n"
	.string "Team Aqua power?\p"
	.string "I think we still got it!\p"
	.string "No hard feelings?$"

Present_AquaCorpHQ_Text_Sheldon:
	.string "Oh Krabby…\n"
	.string "I love you so much…$"

Present_AquaCorpHQ_Text_LookerNoneWhatsoever:
	.string "None whatsoever.$"

Present_AquaCorpHQ_Text_Geoff:
	.string "Matt and I joined Team Aqua at the\n"
	.string "same time.\p"
	.string "He was always a hothead, but was loyal\n"
	.string "as heck to every member of the team.\p"
	.string "This change in the Team's goals has\n"
	.string "really thrown him for a loop.$"

Present_AquaCorpHQ_Text_SarahNPC:
	.string "He might be all grown up now, but\n"
	.string "he'll always be lil' Chowdie to me!\p"
	.string "Please take good care of him!$"

Present_AquaCorpHQ_Text_SarahBlushNPC:
	.string "Huh? There's a guy who likes lil'\n"
	.string "Chowder?\p"
	.string "Maybe I should get to know more of the\n"
	.string "people in Porta Bella…$"

Present_AquaCorpHQ_Text_Krabby:
	.string "Blblblblblblbl!$"
	
Present_AquaCorpHQ_Text_LookerMatt:
	.string "Aqua Admin Matt.$"

Present_AquaCorpHQ_Text_MattWhyAreYouHere:
	.string "Huh? Why are you showing your face\n"
	.string "around here?$"

Present_AquaCorpHQ_Text_LookerYoureUnderArrest:
	.string "I am taking you into custody for\n"
	.string "questioning regarding the recent\l"
	.string "downpour in Porta Bella City.\p"
	.string "Team Aqua is under suspicion for being\n"
	.string "the cause of the frenzied weather.$"

Present_AquaCorpHQ_Text_MattWhat:
	.string "… … …\n"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …$"

Present_AquaCorpHQ_Text_LookerComeWithMe:
	.string "Matt, you're gonna have to come with\n"
	.string "me to City Hall.$"

Present_AquaCorpHQ_Text_MattDots:
	.string "… … …\n"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …$"

Present_AquaCorpHQ_Text_MattOhComeOn:
	.string "Oh.\p" 
	.string "Come.\p"
	.string "ON!\p"
	.string "For the last time, we are NOT doing\n"
	.string "anything seedy!\p"
	.string "Will you PLEASE get off our backs!?$"

Present_AquaCorpHQ_Text_LookerThereIsAStorm:
	.string "There is a torrential downpour outside!$"

Present_AquaCorpHQ_Text_LookerThereWasAStorm:
	.string "There was a torrential downpour outside!$"

Present_AquaCorpHQ_Text_MattSoWhatIfTheresAStorm:
	.string "So what if there's a storm outside!?\p"
	.string "We get hit with storms ALL THE TIME\n"
	.string "in Porta Bella!\p"
	.string "You can't just point at the weather\n"
	.string "and put the blame us!$"

Present_AquaCorpHQ_Text_LookerWeHaveItOnGoodIntel:
	.string "We have it on good intel that the\n"
	.string "cause of this storm is most likely\l"
	.string "the result of Tornadus and Thundurus\l"
	.string "rampaging in the absense of Landorus!$"

Present_AquaCorpHQ_Text_LookerWeHaveConfirmed:
	.string "I'll let you know, in fact, we have\n"
	.string "confirmed the storm was caused by\l"
	.string "Tornadus and Thundurus rampaging in\l"
	.string "the absense of Landorus!$"

Present_AquaCorpHQ_Text_LookerWeHaveConfirmedAreBeing:
	.string "I'll let you know, in fact, we have\n"
	.string "confirmed the storms are being caused\l"
	.string "by Tornadus and Thundurus rampaging\l"
	.string "in the absense of Landorus!$"

Present_AquaCorpHQ_Text_LookerJustThreeMonthsAgo:
	.string "Not even three months ago, your group\n"
	.string "threw the whole Hoenn region into\l"
	.string "chaos by awakening Kyogre to what…\p"
	.string "Give water Pokémon more water…?\p"
	.string "I hope you understand Team Aqua is\n"
	.string "public suspect number one right now!$"

Present_AquaCorpHQ_Text_MattGrr:
	.string "Grr…$"

Present_AquaCorpHQ_Text_ShellyWillYouJustStop:
	.string "Matt, cool it…\p"
	.string "We won't get anywhere with you getting\n"
	.string "this angry…$"

Present_AquaCorpHQ_Text_MattNoIWillNot:
	.string "Shut up, Shelly!\p"
	.string "This guy is throwing around baseless\n"
	.string "accusations! Am I wrong to be mad!?$"

Present_AquaCorpHQ_Text_MattEnoughOfThis:
	.string "Enough of this! If you won't get off\n"
	.string "our back, we'll make you!\p"
	.string "Team Aqua! Get him!$"

Present_AquaCorpHQ_Text_LookerImBack:
	.string "Matt, you are being taken into custody\n"
	.string "under suspicion of being the cause of\l"
	.string "the frenzied weather and for attacking\l"
	.string "an officer of the law.$"

Present_AquaCorpHQ_Text_MattYouWantMore:
	.string "Oh, so you want more, old man?$"

Present_AquaCorpHQ_Text_ShellyThisIsntHelping:
	.string "Matt… This isn't helping anyone…$"

Present_AquaCorpHQ_Text_MattTheGuyWontLeaveUsAlone:
	.string "Shelly, the guy won't leave us alone!$"

Present_AquaCorpHQ_Text_MattWeGottaTeachHim:
	.string "We gotta teach him the old-fashioned\n"
	.string "way not to mess with Team Aqua!\p"
	.string "Get him!$"

Present_AquaCorpHQ_Text_GeoffIntro:
	.string "Man, it's been forever since we got\n"
	.string "to do something like this!$"

Present_AquaCorpHQ_Text_GeoffDefeat:
	.string "Huh? That didn't feel right…$"

Present_AquaCorpHQ_Text_GeoffUnfulfilling:
	.string "That was… Unfulfilling…\p"
	.string "Have I grown soft?$"

Present_AquaCorpHQ_Text_SarahIntro:
	.string "I don't wanna do this…\p"
	.string "Let's just get it over with…$"

Present_AquaCorpHQ_Text_SarahDefeat:
	.string "C'mon, do we really have\n"
	.string "to do this?\p"
	.string "I thought we changed…$"

Present_AquaCorpHQ_Text_SarahCmonGuys:
	.string "This isn't worth it…$"

Present_AquaCorpHQ_Text_SheldonIntro:
	.string "Please don't hurt my crabs sir…\p"
	.string "They might look tough, but I assure\n"
	.string "you they're all fragile in their own\l"
	.string "special ways!$"

Present_AquaCorpHQ_Text_SheldonDefeat:
	.string "Aww…\p"
	.string "My crabs…$"

Present_AquaCorpHQ_Text_SheldonMyCrabs:
	.string "My crabs…\p"
	.string "You couldn't have gone easier on\n"
	.string "them, huh…$"

Present_AquaCorpHQ_Text_MattBunchOfWorthless:
	.string "You bunch of worthless…\p"
	.string "Fine! That's what I get for relying on\n"
	.string "a bunch of softies!$"

Present_AquaCorpHQ_Text_SheldonOw:
	.string "Ow…$"

Present_AquaCorpHQ_Text_MattGottaDoItYourself:
	.string "I should've just done this myself\n"
	.string "from the get-go!\p"
	.string "All right, Looker.\p"
	.string "You're going down!$"

Present_AquaCorpHQ_Text_MattDefeat:
	.string "… … …\n"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "Grr…$"

Present_AquaCorpHQ_Text_MattAreYouKiddingMe:
	.string "… … …\n"
	.string "… … …\p"
	.string "You've gotta be kidding me…\p"
	.string "Grah! Looker!\p"
	.string "I'm not going down without a fight,\n"
	.string "mano a mano!\p"
	.string "Bring it on, you-$"

Present_AquaCorpHQ_Text_ShellyEnough:
	.string "ENOUGH!$"

Present_AquaCorpHQ_Text_ShellyHaventYouNoticed:
	.string "Matt, your temper tantrums aren't\n"
	.string "getting you anywhere, they're only\l"
	.string "making everything worse!\p"
	.string "Like, have you even noticed how much\n"
	.string "you've stressed out the Pokémon in\l"
	.string "our care?$"

Present_AquaCorpHQ_Text_MattSorry:
	.string "Sorry Shelly…$"

Present_AquaCorpHQ_Text_ShellyAndLookerYou:
	.string "And Looker.\p"
	.string "I understand you're just trying to do\n"
	.string "your job, but could you PLEASE not\l"
	.string "barge in and throw around baseless\l"
	.string "accusations?\p"
	.string "We're all extremely busy with our\n"
	.string "research right now!$"

Present_AquaCorpHQ_Text_LookerSorry:
	.string "Sorry…$"

Present_AquaCorpHQ_Text_ShellyLookerComeHere:
	.string "Sigh…\p"
	.string "Mr. Looker, come here. I can explain\n"
	.string "everything.$"
	
Present_AquaCorpHQ_Text_LookerOkay:
	.string "Okay…$"

Present_AquaCorpHQ_Text_ShellyWeAreResearchers:
	.string "Our incident with Kyogre stemmed\n"
	.string "from us wanting to do good for all\l"
	.string "the water Pokémon in the region.\p"
	.string "But we went too far.\p"
	.string "After Team Aqua dissolved, Matt and\n"
	.string "I turned to studying marine biology\l"
	.string "with the remnants of Team Aqua.\p"
	.string "That way, we could help aquatic\n"
	.string "Pokémon in need and learn more about\l"
	.string "them in the process.$"

Present_AquaCorpHQ_Text_SarahShellyDots:
	.string "Shelly…$"

Present_AquaCorpHQ_Text_SarahCanWeClamperl:
	.string "Could we get on with the test\n"
	.string "on Chowder?\p"
	.string "Poor thing's been waiting ages for\n"
	.string "his big moment…$"

Present_AquaCorpHQ_Text_ShellyOfCourseWeCan:
	.string "Of course we can.$"

Present_AquaCorpHQ_Text_SarahIllPrepareTheDeepSea:
	.string "Yes!!! I'll prepare the Deep Sea\n"
	.string "items!$"

Present_AquaCorpHQ_Text_ShellyLookerComeSeeClamperl:
	.string "Follow me, Looker. This is gonna\n"
	.string "be exciting!$"

Present_AquaCorpHQ_Text_ShellyThisClamperl:
	.string "This Clamperl has been in our care\n"
	.string "since we set up our base of\l"
	.string "operations here.\p"
	.string "We have been learning about why this\n"
	.string "Pokémon has trouble evolving in\l"
	.string "captivity but can in the wild, and we\l"
	.string "think Sarah cracked the case!$"

Present_AquaCorpHQ_Text_SarahClamperlIsReady:
	.string "He's feeling ready! Which one should\n"
	.string "I use on him first?$"

Present_AquaCorpHQ_Text_ShellyLetLookerDecide:
	.string "How about Looker decides?$"

Present_AquaCorpHQ_Text_ShellyWhichItemWouldYouWantToUse:
	.string "Which item do you want to use on\n"
	.string "lil' Chowder here?$"

Present_AquaCorpHQ_Text_ShellyGorebyssItIs:
	.string "Sarah, give Chowder the Deep Sea\n"
	.string "Scale first!$"

Present_AquaCorpHQ_Text_ShellyHuntailItIs:
	.string "Sarah, give Chowder the Deep Sea\n"
	.string "Tooth first!$"

Present_AquaCorpHQ_Text_SarahHereYouGoClamperl:
	.string "Here you go, Chowdie!$"

Present_AquaCorpHQ_Text_SarahWhoa:
	.string "Whoa!!!$"

Present_AquaCorpHQ_Text_SarahThatWasAwesome:
	.string "Shelly, that was AWESOME!!!!!$"

Present_AquaCorpHQ_Text_ShellyAllBecauseOfYourHardWork:
	.string "All because of your hard work!$"

Present_AquaCorpHQ_Text_ShellySeeLookerNothingMalicious:
	.string "See, Looker? Nothing malicious is\n"
	.string "going on here any more.\p"
	.string "We're caring for Pokémon who are\n"
	.string "struggling out in the wild.\p"
	.string "In return, they help us learn more\n"
	.string "about the world around us.$"

Present_AquaCorpHQ_Text_LookerISupposeAquaIsCleared:
	.string "I see…\p"
	.string "I suppose Team Aqua is off the hook\n"
	.string "then.\p"
	.string "I'll turn a blind eye to the assaults.\p"
	.string "Less paperwork that way…$"

Present_AquaCorpHQ_Text_ShellyImGladToHear:
	.string "I'm glad to hear.\p"
	.string "I guess.$"

Present_AquaCorpHQ_Text_MattImSorry:
	.string "…I'm sorry for before.\n"
	.string "Old habits die hard.$"

Present_AquaCorpHQ_Text_LookerApologyAcceptedImSorry:
	.string "Apology accepted. I apologize for\n"
	.string "my rash assumptions.$"

Present_AquaCorpHQ_Text_SarahGorebyssWantsToComeWithYou:
	.string "I think Gorebyss wants to come\n"
	.string "with you!\p"
	.string "It seems like he wants to try battles\n"
	.string "in his new form.\p"
	.string "Chowder doesn't feel as appropriate\n"
	.string "a name any more though.\p"
	.string "How about…\p"
	.string "Gorb?$"

Present_AquaCorpHQ_Text_GorebyssExcited:
	.string "Gooooooorb!$"

Present_AquaCorpHQ_Text_SarahHuntailWantsToComeWithYou:
	.string "I think Huntail wants to come\n"
	.string "with you!\p"
	.string "It seems like he wants to try battles\n"
	.string "in his new form.\p"
	.string "Chowder doesn't feel as appropriate\n"
	.string "a name any more though.\p"
	.string "How about…\p"
	.string "Huntsman?$"

Present_AquaCorpHQ_Text_HuntailExcited:
	.string "Huntssssss!$"

Present_AquaCorpHQ_Text_LookerIWillTakeGorebyssAlong:
	.string "Gorb is free to come along while I\n"
	.string "stay in the city.\p"
	.string "I could always use another partner.$"
	
Present_AquaCorpHQ_Text_LookerIWillTakeHuntailAlong:
	.string "Huntsman is free to come along\n"
	.string "while I stay in the city.\p"
	.string "I could always use another partner.$"
	
Present_AquaCorpHQ_Text_EvolvedGorebyss:
	.string "Chowder evolved into Gorebyss!$"

Present_AquaCorpHQ_Text_EvolvedHuntail:
	.string "Chowder evolved into Huntail!$"

Present_AquaCorpHQ_Text_MattTakeThat:
	.string "Take that, loser!$"

Present_AquaCorpHQ_Text_LookerThisIsBad:
	.string "(Shoot, this is bad…\n"
	.string "I need to regroup…)$"