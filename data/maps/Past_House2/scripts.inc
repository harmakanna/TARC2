Past_House2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Past_House2_OnLoad
	.byte 0

Past_House2_OnLoad:
	call_if_unset FLAG_SWEET_TOOTH_WENT_CRAZY, Past_House2_EventScript_CloseHole
	end

Past_House2_EventScript_CloseHole::
	setmetatile 11, 0, METATILE_lozinterior_LoZ_Wall_Top, TRUE
	setmetatile 11, 1, METATILE_lozinterior_LoZ_Wall_Bottom, TRUE
	return

Past_House2_EventScript_SweetToothGirl::
	lockall
	faceplayer
	call Script_GetNPCFacingDirection
	goto_if_unset FLAG_SYS_MAIN_GAME_START, Past_House2_EventScript_SweetToothPreGame
	returnqueststate QUEST_FIND_TASTY_MINT
	switch VAR_RESULT
	case 1, Past_House2_EventScript_SweetToothGirlActivate
	case 2, Past_House2_EventScript_SweetToothGirlActive
	case 3, Past_House2_EventScript_SweetToothGirlReward
	case 4, Past_House2_EventScript_SweetToothGirlComplete
	releaseall
	end

Past_House2_EventScript_SweetToothPreGame::
	msgbox Past_House2_Text_SweetToothPreGame, MSGBOX_DEFAULT
	closemessage
	release
	end

Past_House2_EventScript_SweetToothGirlActivate::
	speak LOCALID_SWEET_TOOTH, VAR_0x8005, Name_Sweet_Tooth, Past_House2_Text_SweetToothManIWantATastyMint
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_ThisSeemsSerious
	speak LOCALID_SWEET_TOOTH, VAR_0x8005, Name_Sweet_Tooth, Past_House2_Text_SweetToothIKnowRight
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_Understood
	speak LOCALID_SWEET_TOOTH, VAR_0x8005, Name_Sweet_Tooth, Past_House2_Text_SweetToothYayThanks
	startquest QUEST_FIND_TASTY_MINT
	checkitem ITEM_SERIOUS_MINT
	call_if_eq VAR_RESULT, TRUE, Past_House2_EventScript_SetTastyMintReward
	releaseall
	end
	
Past_House2_EventScript_SetTastyMintReward::
	questmenu QUEST_MENU_SET_REWARD, QUEST_FIND_TASTY_MINT
	return

Past_House2_EventScript_SweetToothGirlActive::
	speak LOCALID_SWEET_TOOTH, VAR_0x8005, Name_Sweet_Tooth, Past_House2_Text_SweetToothIWantATastyMintActive
	closemessage
	releaseall
	end

Past_House2_EventScript_SweetToothGirlReward::
	speak LOCALID_SWEET_TOOTH, VAR_0x8005, Name_Sweet_Tooth, Past_House2_Text_SweetToothGimme
	playbgm MUS_NONE, TRUE
	removeitem ITEM_SERIOUS_MINT, 1
	speakername NULL
	playfanfare MUS_OBTAIN_TMHM
	message Past_House2_Text_LookerGaveTastyMint
	waitmessage
	waitfanfare
	closemessage
	special SpawnCameraObject
	call_if_eq VAR_FACING, DIR_NORTH, Past_House2_EventScript_PanCameraUp
	call_if_eq VAR_FACING, DIR_SOUTH, Past_House2_EventScript_PanCameraDown
	call_if_eq VAR_FACING, DIR_WEST, Past_House2_EventScript_PanCameraLeft	
	delay 80
	speak LOCALID_SWEET_TOOTH, VAR_0x8005, Name_Sweet_Tooth, Past_House2_Text_SweetToothOoo1
	closemessage
	delay 60
	speak LOCALID_SWEET_TOOTH, VAR_0x8005, Name_Sweet_Tooth, Past_House2_Text_SweetToothOoo2
	closemessage
	delay 60
	speak LOCALID_SWEET_TOOTH, VAR_0x8005, Name_Sweet_Tooth, Past_House2_Text_SweetToothOoo3
	closemessage
	applymovement LOCALID_SWEET_TOOTH, Past_House2_Movement_SweetToothKindaFrantic
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement LOCALID_SWEET_TOOTH
	delay 60
	fadedefaultbgm
	call_if_eq VAR_FACING, DIR_NORTH, Past_House2_EventScript_PanCameraDown
	call_if_eq VAR_FACING, DIR_SOUTH, Past_House2_EventScript_PanCameraUp
	call_if_eq VAR_FACING, DIR_WEST, Past_House2_EventScript_PanCameraRight
	special RemoveCameraObject
	speak LOCALID_SWEET_TOOTH, VAR_0x8005, Name_Sweet_Tooth, Past_House2_Text_SweetToothThatWasGood
	speakername NULL
	playfanfare MUS_OBTAIN_ITEM
	message Past_House2_Text_LookerReceivedMints
	waitmessage
	waitfanfare
	completequest QUEST_FIND_TASTY_MINT
	releaseall
	end

Past_House2_Movement_SweetToothKindaFrantic::
	jump_in_place_down
	jump_in_place_down
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_4
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_16
	face_up
	delay_16
	face_left
	delay_16
	step_end	
	
Past_House2_EventScript_SweetToothGirlComplete::
	checkitem ITEM_RARE_CANDY
	goto_if_eq VAR_RESULT, TRUE, Past_House2_EventScript_SweetToothGirlGoesCrazy
	speak LOCALID_SWEET_TOOTH, VAR_0x8005, Name_Sweet_Tooth, Past_House2_Text_SweetToothYay, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Past_House2_EventScript_SweetToothGirlGoesCrazy:
	speak LOCALID_SWEET_TOOTH, VAR_0x8005, Name_Sweet_Tooth, Past_House2_Text_SweetToothSweetSmell
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_Uhh
	closemessage
	delay 80
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	delay 80
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	delay 80
	call_if_eq VAR_FACING, DIR_NORTH, Past_House2_EventScript_LookerFaceUp
	call_if_eq VAR_FACING, DIR_SOUTH, Past_House2_EventScript_LookerFaceDown
	call_if_eq VAR_FACING, DIR_WEST, Past_House2_EventScript_LookerFaceLeft
	playbgm MUS_NONE, TRUE
	speakername NULL
	playfanfare MUS_OBTAIN_TMHM
	message Past_House2_Text_LookerGaveRareCandy
	waitmessage
	waitfanfare
	closemessage
	special SpawnCameraObject
	call_if_eq VAR_FACING, DIR_NORTH, Past_House2_EventScript_PanCameraUp
	call_if_eq VAR_FACING, DIR_SOUTH, Past_House2_EventScript_PanCameraDown
	call_if_eq VAR_FACING, DIR_WEST, Past_House2_EventScript_PanCameraLeft
	delay 80
	speak LOCALID_SWEET_TOOTH, VAR_0x8005, Name_Sweet_Tooth, Past_House2_Text_SweetToothCrazy1
	closemessage
	delay 60
	speak LOCALID_SWEET_TOOTH, VAR_0x8005, Name_Sweet_Tooth, Past_House2_Text_SweetToothCrazy2
	closemessage
	delay 120
	speakername Name_Sweet_Tooth
	messageautoscroll Past_House2_Text_SweetToothCrazy3
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCALID_PAST_PURRLOIN, Common_Movement_FaceUpExclamationMark
	waitmovement 0
	delay 50
	getobjectxy LOCALID_PAST_PURRLOIN, CURRENT_POSITION, VAR_0x8002, VAR_0x8003
	call_if_eq VAR_0x8002, 11, Past_House2_EventScript_MovePurrloin
	call_if_eq VAR_FACING, DIR_WEST, Past_House2_EventScript_SweetToothMovementLookerOnOutside
	setvar VAR_0x8004, 8  @ vertical pan
	setvar VAR_0x8005, 8  @ horizontal pan
	setvar VAR_0x8006, 5  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	applymovement LOCALID_SWEET_TOOTH, Past_House2_Movement_SweetToothCrazy
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	call_if_eq VAR_FACING, DIR_NORTH, Past_House2_EventScript_LookerWatchSweetTooth
	call_if_eq VAR_FACING, DIR_SOUTH, Past_House2_EventScript_LookerWatchSweetTooth
	waitmovement LOCALID_SWEET_TOOTH
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	playse SE_BANG
	special ShakeCamera
	setmetatile 11, 0, METATILE_lozinterior_HighWallBroken, TRUE
	setmetatile 11, 1, METATILE_lozinterior_LowWallBroken, FALSE
	special DrawWholeMapView
	removeobject LOCALID_SWEET_TOOTH
	waitmessage
	delay 40
	closemessage
	delay 60
	call_if_eq VAR_FACING, DIR_NORTH, Past_House2_EventScript_PanCameraDown
	call_if_eq VAR_FACING, DIR_SOUTH, Past_House2_EventScript_PanCameraUp
	call_if_eq VAR_FACING, DIR_WEST, Past_House2_EventScript_PanCameraBackLeft
	special RemoveCameraObject
	delay 60
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	speakername Name_Looker
	msgbox Looker_Text_DotsLong, MSGBOX_DEFAULT
	closemessage
	delay 160
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_WITH_MUCH_GRATITUDE, SUB_QUEST_A_WHOLE_NEW_WORLD
	completequest QUEST_WITH_MUCH_GRATITUDE
	playbgm MUS_DP_ETERNA_NIGHT, TRUE
	setflag FLAG_SWEET_TOOTH_WENT_CRAZY
	clearflag FLAG_HIDE_PRESENT_SWEET_TOOTH
	closemessage
	releaseall
	end

Past_House2_EventScript_LookerFaceUp::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	return

Past_House2_EventScript_LookerFaceDown::
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	return

Past_House2_EventScript_LookerFaceLeft::
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	return

Past_House2_EventScript_LookerWatchSweetTooth::
	applymovement LOCALID_PLAYER, Past_House2_Movement_LookerWatchSweetTooth
	return

Past_House2_EventScript_PanCameraDown::
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown
	waitmovement 0
	return

Past_House2_EventScript_PanCameraUp::
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp
	waitmovement 0
	return

Past_House2_EventScript_PanCameraLeft::
	applymovement LOCALID_CAMERA, Common_Movement_WalkLeft
	waitmovement 0
	return

Past_House2_EventScript_PanCameraRight::
	applymovement LOCALID_CAMERA, Common_Movement_WalkRight
	waitmovement 0
	return

Past_House2_EventScript_PanCameraBackLeft::
	applymovement LOCALID_CAMERA, Common_Movement_WalkRight2
	waitmovement 0
	return

Past_House2_EventScript_SweetToothMovementLookerOnOutside::
	applymovement LOCALID_PLAYER, Common_Movement_WalkFastRight
	waitmovement 0
	return

Past_House2_Movement_LookerWatchSweetTooth:
	face_right
	face_up
	delay_16
	face_left
	delay_16
	delay_8
	face_down
	delay_8
	delay_8
	face_right
	delay_8
	delay_8
	face_up
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_8
	delay_8
	face_right
	delay_8
	delay_8
	face_up
	delay_8
	delay_8
	face_left
	delay_8
	delay_16
	face_down
	delay_8
	delay_8
	face_right
	delay_8
	delay_8
	face_up
	step_end

Past_House2_Movement_SweetToothCrazy:
	jump_in_place_down
	jump_in_place_down
	jump_in_place_down
	jump_in_place_down
	walk_faster_right
	walk_faster_up
	walk_faster_up
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

Past_House2_EventScript_MovePurrloin::
	applymovement LOCALID_PAST_PURRLOIN, Common_Movement_WalkFastRight
	return

Past_House2_EventScript_SleepingMama::
	lock
	faceplayer
	returnqueststate QUEST_FIND_TASTY_MINT
	goto_if_eq VAR_RESULT, 4, Past_House2_EventScript_MamaThankYou
	msgbox Past_House2_Text_MamaTryingToSleep, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLEEPY_MAMA, Common_Movement_FaceRight
	waitmovement 0
	release
	end

Past_House2_EventScript_SleepingMamaLater::
	msgbox Past_House2_Text_MamaWhy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLEEPY_MAMA, Common_Movement_FaceRight
	waitmovement 0
	release
	end

Past_House2_EventScript_MamaThankYou::
	msgbox Past_House2_Text_MamaThankYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLEEPY_MAMA, Common_Movement_FaceRight
	waitmovement 0
	release
	end

Past_House2_Text_SweetToothYayThanks:
	.string "yay thanks$"

Past_House2_Text_SweetToothGimme:
	.string "oooo…\p"
	.string "is that something SWEET i smell?\p"
	.string "gimme gimme gimme$"

Past_House2_Text_SweetToothSweetSmell:
	.string "huh????\p"
	.string "what's that super duper sweet I smell?\p"
	.string "gimme gimme gimme\p"
	.string "GIMME GIMME GIMME$"

Past_House2_Text_SweetToothCrazy1:
	.string "… … …\n"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "…oooooooo…$"

Past_House2_Text_SweetToothCrazy2:
	.string "oooOOOOOOoooooOOOOOooo\n"
	.string "ooOOooOOOoOOOoOOOOOOoO…$"

Past_House2_Text_SweetToothCrazy3:
	.string "oooooooOOOOOOOOOOOOOOOOOOOOOOO\n"
	.string "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\l"
	.string "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\l"
	.string "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\l"
	.string "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\l"
	.string "OOOOOOOOOOOOoooooooooooooooooo\l"
	.string "oooooooooooooooooooooooooooooo\l"
	.string "ooooooooooooooooooo… … …\l"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …$"

Past_House2_Text_LookerGaveRareCandy:
	.string "Looker gave Berryjammy Estella's\n"
	.string "rare candies…$"

Past_House2_Text_SweetToothOoo1:
	.string "oooooo…$"

Past_House2_Text_SweetToothOoo2:
	.string "oooOOOooOoooOO…$"

Past_House2_Text_SweetToothOoo3:
	.string "OOOOOOOOOOOOOOOOOOOOOOOOO!!!!$"

Past_House2_Text_SweetToothPreGame:
	.string "maaaaaaaaaannn!!!\p"
	.string "no fairrrrrr!!!!!$"

Past_House2_Text_SweetToothManIWantATastyMint:
	.string "maaaaaaann!!!!!!!\p"
	.string "my mam reads me tales about the town\n"
	.string "and she read to me a tale about a really\l"
	.string "tasty plant!!!!\p"
	.string "but, that plant doesn't grow all the\n"
	.string "time!!!!\p"
	.string "only one time in a hundred years!!!\p"
	.string "no fair!\p"
	.string "i want a tasty mint!!!!!!$"

Past_House2_Text_SweetToothIKnowRight:
	.string "i know RIIGHT!?\p"
	.string "i want a tasty mint!\p"
	.string "i NEED a tasty mint!!!\p"
	.string "BRING ME A TASTY MINT!!!!!!!!!!$"

Past_House2_Text_SweetToothYay:
	.string "yay$"

Past_House2_Text_SweetToothIWantATastyMintActive:
	.string "I WANT A TASTY MINT!!!$"

Past_House2_Text_LookerGaveTastyMint:
	.string "Looker handed over the Tasty Mint!$"

Past_House2_Text_SweetToothThatWasGood:
	.string "so GOOOOOOOOOOOOOOD\p"
	.string "thanks mister!!!!! have this\n"
	.string "they taste bad$"

Past_House2_Text_MamaTryingToSleep:
	.string "Sir, could you kindly tell my little\n"
	.string "girl to shut up?\p"
	.string "She has desolated my sleep schedule\n"
	.string "ever since I told her the story of the\l"
	.string "legendary Tasty Mint…$"

Past_House2_Text_MamaThankYou:
	.string "Thank you…\p"
	.string "Uuuuuuuugh…\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "…zzzzzz…$"

Past_House2_Text_MamaWhy:
	.string "Uggghhhh…\p"
	.string "I can fix that tomorrow…$"

Past_House2_Text_LookerReceivedMints:
	.string "Looker recieved five Adamant, Modest,\n"
	.string "Jolly, and Timid Mints each!$"