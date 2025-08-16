Present_Cafe_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PresentCafe_OnTransition
	.byte 0

PresentCafe_OnTransition:
	call_if_set FLAG_SWEET_TOOTH_WENT_CRAZY, PresentCafe_EventScript_PlaceCook
	end

PresentCafe_EventScript_PlaceCook::
	setobjectxyperm LOCALID_CAFE_COOK, 9, 5
	setobjectmovementtype LOCALID_CAFE_COOK, MOVEMENT_TYPE_FACE_RIGHT
	return

Present_Cafe_EventScript_Emma::
	lock
	goto_if_unset FLAG_SYS_MAIN_GAME_START, Present_Cafe_EventScript_EmmaPreGame
	returnqueststate QUEST_BONJOUR_EMMA
	goto_if_eq VAR_RESULT, 4, Present_Cafe_EventScript_EmmaPostQuest
	call Script_GetNPCFacingDirection
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaBonjour
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerBonjour
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaComoCaVa
	speakername Name_Looker
	msgbox Present_Cafe_Text_LookerWhatDoISayHere, MSGBOX_DEFAULT
	multichoice 0, 3, MULTI_SPEAK_WITH_EMMA_1, TRUE
	goto_if_eq VAR_RESULT, 0, Present_Cafe_EventScript_EmmaDontKnowFrench_1_1
	goto_if_eq VAR_RESULT, 2, Present_Cafe_EventScript_EmmaLeaveYouAlone
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerBienMerci
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaTresBien
	speakername Name_Looker
	msgbox Present_Cafe_Text_LookerWhatDoISayHere, MSGBOX_DEFAULT
	multichoice 0, 3, MULTI_SPEAK_WITH_EMMA_2, TRUE
	goto_if_eq VAR_RESULT, 0, Present_Cafe_EventScript_EmmaDontKnowFrench_2_1
	goto_if_eq VAR_RESULT, 1, Present_Cafe_EventScript_EmmaDontKnowFrench_2_2
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerJeMappelle
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaEnchantee
	speakername Name_Looker
	msgbox Present_Cafe_Text_LookerHuh, MSGBOX_DEFAULT
	multichoice 0, 6, MULTI_SPEAK_WITH_EMMA_3, TRUE
	goto_if_eq VAR_RESULT, 0, Present_Cafe_EventScript_EmmaDontKnowFrench_3_1
	goto_if_eq VAR_RESULT, 1, Present_Cafe_EventScript_EmmaSad
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerJePeux
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaMerciBeaucoup
	multichoice 0, 6, MULTI_EMMA_GIVEMON, TRUE
	switch VAR_RESULT
	goto_if_eq VAR_RESULT, 0, Present_Cafe_EventScript_EmmaGiveGumshoos
	goto_if_eq VAR_RESULT, 1, Present_Cafe_EventScript_EmmaGiveMeowstic
	release
	end

Present_Cafe_EventScript_EmmaPreGame::
	msgbox Present_Cafe_Text_EmmaCoffeeDelicious, MSGBOX_DEFAULT
	closemessage
	release
	end

Present_Cafe_EventScript_EmmaPostQuest::
	faceplayer
	goto_if_unset FLAG_HIDE_PRESENT_LUVDISCS, Present_Cafe_EventScript_EmmaLovesLuvdiscs
	speakername Name_Emma
	msgbox Present_Cafe_Text_EmmaPostQuest, MSGBOX_DEFAULT
	closemessage
	release
	end

Present_Cafe_EventScript_EmmaLovesLuvdiscs::
	speakername Name_Emma
	msgbox Present_Cafe_Text_EmmaLovesLuvdiscs, MSGBOX_DEFAULT
	closemessage
	release
	end

Present_Cafe_EventScript_EmmaDontKnowFrench_1_1::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerOui
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaDontSpeakFrench
	goto Present_Cafe_EventScript_EmmaWrongAnswer
	end

Present_Cafe_EventScript_EmmaLeaveYouAlone::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerMal
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaLeaveYouAlone
	goto Present_Cafe_EventScript_EmmaWrongAnswer
	end

Present_Cafe_EventScript_EmmaDontKnowFrench_2_1::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerMonNom
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaDontSpeakFrench
	goto Present_Cafe_EventScript_EmmaWrongAnswer
	end

Present_Cafe_EventScript_EmmaDontKnowFrench_2_2::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerJeSuisLooker
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaDontSpeakFrench
	goto Present_Cafe_EventScript_EmmaWrongAnswer
	end

Present_Cafe_EventScript_EmmaDontKnowFrench_3_1::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerSure
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaDontSpeakFrench
	goto Present_Cafe_EventScript_EmmaWrongAnswer
	end

Present_Cafe_EventScript_EmmaSad::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerNoThanks
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaAhDaccord
	closemessage
	release
	end

Present_Cafe_EventScript_EmmaWrongAnswer::
	speakername Name_Looker
	msgbox Present_Cafe_Text_LookerWrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

Present_Cafe_EventScript_EmmaFinishQuest::
	completequest QUEST_BONJOUR_EMMA
	release
	end

Present_Cafe_EventScript_SweetTooth::
	lock
	goto_if_unset FLAG_TALKED_TO_PRESENT_SWEET_TOOTH, Present_Cafe_EventScript_SweetToothThankYou
	speak LOCALID_PRESENT_SWEET_TOOTH, DIR_WEST, Name_Sweet_Tooth, Present_Cafe_Text_SweetToothOneRareCandy
	speak LOCALID_CAFE_COOK, DIR_EAST, Name_Cook, Present_Cafe_Text_CookSoMany
	closemessage
	special SpawnCameraObject
	fadenewbgm MUS_NONE
	call_if_eq VAR_FACING, DIR_WEST, Present_Cafe_EventScript_PanCameraLeft
	call_if_eq VAR_FACING, DIR_NORTH, Present_Cafe_EventScript_PanCameraUp
	delay 90
	speak LOCALID_PRESENT_SWEET_TOOTH, DIR_WEST, Name_Sweet_Tooth, Present_Cafe_Text_SweetToothOoo
	speak LOCALID_CAFE_COOK, DIR_EAST, Name_Cook, Present_Cafe_Text_CookGivesIn
	playbgm MUS_DP_SUNYSHORE_DAY, TRUE
	speak LOCALID_PRESENT_SWEET_TOOTH, DIR_WEST, Name_Sweet_Tooth, Present_Cafe_Text_SweetToothYay
	call_if_eq VAR_FACING, DIR_WEST, Present_Cafe_EventScript_PanCameraRight
	call_if_eq VAR_FACING, DIR_NORTH, Present_Cafe_EventScript_PanCameraDown
	special RemoveCameraObject
	closemessage
	release
	end

Present_Cafe_EventScript_PanCameraUp::
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp
	waitmovement 0
	return

Present_Cafe_EventScript_PanCameraDown::
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown
	waitmovement 0
	return
	
Present_Cafe_EventScript_PanCameraLeft::
	applymovement LOCALID_CAMERA, Common_Movement_WalkLeft
	waitmovement 0
	return
	
Present_Cafe_EventScript_PanCameraRight::
	applymovement LOCALID_CAMERA, Common_Movement_WalkRight
	waitmovement 0
	return

Present_Cafe_EventScript_SweetToothThankYou::
	faceplayer
	playse SE_PIN
	applymovement LOCALID_PRESENT_SWEET_TOOTH, Common_Movement_ExclamationMark
	waitmovement 0
	delay 50
	call Script_GetNPCFacingDirection
	speak LOCALID_PRESENT_SWEET_TOOTH, VAR_0x8005, Name_Sweet_Tooth, Present_Cafe_Text_SweetToothThankYou
	speakername NULL
	giveitem ITEM_LIFE_ORB, 1
	closemessage
	applymovement LOCALID_PRESENT_SWEET_TOOTH, Common_Movement_FaceLeft
	waitmovement 0
	setflag FLAG_TALKED_TO_PRESENT_SWEET_TOOTH
	release
	end

Present_Cafe_EventScript_Cook::
	lock
	faceplayer
	speakername Name_Cook
	msgbox Present_Cafe_Text_Cook, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAFE_COOK, Common_Movement_FaceRight
	waitmovement
	release
	end

Present_Cafe_Text_SweetToothThankYou:
	.string "hi mister!!!!!!\p"
	.string "thank you so so so much!!!!!!\p"
	.string "i dont have much, but you can have\n"
	.string "this thing!!!!!!$"

Present_Cafe_Text_SweetToothOneRareCandy:
	.string "hi mister!!!!!\p"
	.string "i will have\p"
	.string "ONE\p"
	.string "rare candy please!!!!!$"

Present_Cafe_Text_CookSoMany:
	.string "But you've already had so many…$"

Present_Cafe_Text_SweetToothOoo:
	.string "… … …\n"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "…oooOOoOOooOoooo…$"

Present_Cafe_Text_CookGivesIn:
	.string "Oof… Fine…\p"
	.string "You can have another…$"

Present_Cafe_Text_SweetToothYay:
	.string "yayy$"

Present_Cafe_Text_Cook:
	.string "Oh lord please help me…\p"
	.string "This girl came in and started demanding\n"
	.string "candies…\p"
	.string "I've never even seen her before…$"

Present_Cafe_Text_EmmaLovesLuvdiscs:
	.string "Aaaaaaaa!\p"
	.string "J'adore les Luvdiscs dans la\n"
	.string "baie!\p"
	.string "Elles sont si jolis…$"

Present_Cafe_Text_EmmaBonjour:
	.string "Bonjour!$"

Present_Cafe_Text_LookerBonjour:
	.string "Bonjour?$"

Present_Cafe_Text_EmmaComoCaVa:
	.string "Como ça va?$"

Present_Cafe_Text_LookerWhatDoISayHere:
	.string "(What do I say here…?)$"

Present_Cafe_Text_LookerBienMerci:
	.string "Bien, merçi. Ça va?$"

Present_Cafe_Text_LookerOui:
	.string "Oui…?$"

Present_Cafe_Text_LookerMal:
	.string "Pas bien…?$"

Present_Cafe_Text_EmmaLeaveYouAlone:
	.string "Ah…\p"
	.string "Je vous laisserai tranquille.$"

Present_Cafe_Text_EmmaTresBien:
	.string "Bien ça va! Je m'appelle Emma!\n"
	.string "Et vous?$"

Present_Cafe_Text_LookerMonNom:
	.string "Mon nom est Looker…?$"

Present_Cafe_Text_LookerJeSuisLooker:
	.string "Je suis Looker…?$"

Present_Cafe_Text_LookerJeMappelle:
	.string "Je m'appelle…\p"
	.string "Looker.$"

Present_Cafe_Text_EmmaEnchantee:
	.string "Enchantée, Looker!\p"
	.string "Mon Pokémon veulent voir Porta Bella\n"
	.string "et combattrent des combats, mais je\l"
	.string "veux boire du café toute la journée…\p"
	.string "Seriez vous en mesure un Pokémon avec\n"
	.string "vous et combattre avec lui,\l"
	.string "s'il vous plaît?$"

Present_Cafe_Text_LookerHuh:
    .string "(Huh…?)$"

Present_Cafe_Text_LookerSure:
	.string "Sure…?$"

Present_Cafe_Text_EmmaDontSpeakFrench:
	.string "Ah? Vous non parlez pas Français?\n"
	.string "Tant pis…$"

Present_Cafe_Text_LookerNoThanks:
	.string "Je ne veux pas.$"

Present_Cafe_Text_EmmaAhDaccord:
	.string "Ah, d'accord…$"

Present_Cafe_Text_LookerJePeux:
	.string "Bien sûr.$"

Present_Cafe_Text_EmmaMerciBeaucoup:
	.string "Merçi beaucoup!\p"
	.string "Quel Pokémon veux-vous?$"

Present_Cafe_Text_EmmaPostQuest:
	.string "Merçi beaucoup, Looker!$"

Present_Cafe_Text_LookerWrongAnswer:
	.string "(Drat, wrong response…)$"

Present_Cafe_Text_EmmaCoffeeDelicious:
	.string "Ahhhh…\p"
	.string "Ce café est délicieux…$"