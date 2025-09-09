Past_CelebiSociety_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Past_CelebiSociety_OnTransition
	.byte 0

Past_CelebiSociety_OnTransition::
	call_if_unset FLAG_HIDE_PAST_LISIA, Past_CelebiSociety_EventScript_SetupLisia
	end

Past_CelebiSociety_EventScript_SetupLisia::
	setobjectmovementtype LOCALID_PAST_CELEBI_SOCIETY_GENTLEMAN, MOVEMENT_TYPE_FACE_LEFT
	return

Past_CelebiSociety_EventScript_CouncilWoman::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_MAIN_GAME_START, Past_CelebiSociety_EventScript_CouncilWomanPreGame
	goto_if_set FLAG_SAVE_THE_LUVDISCS, Past_CelebiSociety_EventScript_CouncilWomanSaveLuvdiscs
	returnqueststate QUEST_HOMEGROWN_REMEDIES
	goto_if_eq VAR_RESULT, 2, Past_CelebiSociety_EventScript_CouncilWomanSeeCamilla
	speakername Name_Councilwoman
	msgbox Past_CelebiSociety_Text_CouncilWomanAhAnotherTimeTraveler, MSGBOX_DEFAULT
	closemessage
	release
	end

Past_CelebiSociety_EventScript_CouncilWomanPreGame::
	msgbox Past_CelebiSociety_Text_CouncilWomanPregame, MSGBOX_DEFAULT
	closemessage
	release
	end

Past_CelebiSociety_EventScript_CouncilWomanSaveLuvdiscs::
	speakername Name_Councilwoman
	msgbox Past_CelebiSociety_Text_CouncilWomanSaveLuvdiscs, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_SS_TIDAL
	clearflag FLAG_SAVE_THE_LUVDISCS
	clearflag FLAG_HIDE_PRESENT_LUVDISCS
	clearflag FLAG_HIDE_PRESENT_HOUSE2_MISSINGMAN
	clearflag FLAG_HIDE_TINY_BOAT
	release
	end

Past_CelebiSociety_EventScript_CouncilWomanSeeCamilla::
	speakername Name_Councilwoman
	msgbox Past_CelebiSociety_Text_CouncilWomanSeeCamilla, MSGBOX_DEFAULT
	closemessage
	release
	end

Past_CelebiSociety_Eventscript_Gentleman::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_PAST_LISIA, Past_CelebiSociety_EventScript_GentlemanLisia
	speakername Name_Gentleman
	msgbox Past_CelebiSociety_Text_GentlemanMyFavoriteThing, MSGBOX_DEFAULT
	closemessage
	release
	end

Past_CelebiSociety_EventScript_GentlemanLisia::
	speakername Name_Gentleman
	msgbox Past_CelebiSociety_Text_GentlemanLisia, MSGBOX_DEFAULT
	closemessage
	release
	end

Past_CelebiSociety_EventScript_Lisia::
	lock
	faceplayer
	call Script_GetNPCFacingDirection
	speak LOCALID_PAST_LISIA, VAR_0x8005, Name_Lisia, Past_CelebiSociety_Text_LisiaHello
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_SoHeresTheThing
	goto_if_set FLAG_DEFEATED_SHRINE_GENIES, Past_CelebiSociety_EventScript_LisiaLeaving
	goto_if_set FLAG_SPOKE_TO_PAST_LISIA, Past_CelebiSociety_EventScript_LisiaNotLeaving
	speak LOCALID_PAST_LISIA, VAR_0x8005, Name_Lisia, Past_CelebiSociety_Text_LisiaNotLeaving
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Past_CelebiSociety_Text_LookerCouldntYouGoBack
	speak LOCALID_PAST_LISIA, VAR_0x8005, Name_Lisia, Past_CelebiSociety_Text_LisiaUmm
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Past_CelebiSociety_Text_LookerIllogical
	closemessage
	setflag FLAG_SPOKE_TO_PAST_LISIA
	release
	end

Past_CelebiSociety_EventScript_LisiaNotLeaving::
	speak LOCALID_PAST_LISIA, VAR_0x8005, Name_Lisia, Past_CelebiSociety_Text_LisiaNotLeavingShort
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_IUnderstand
	closemessage
	release
	end

Past_CelebiSociety_EventScript_LisiaLeaving::
	speak LOCALID_PAST_LISIA, VAR_0x8005, Name_Lisia, Past_CelebiSociety_Text_LisiaLeaving
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_PAST_LISIA
	setobjectmovementtype LOCALID_PAST_CELEBI_SOCIETY_GENTLEMAN, MOVEMENT_TYPE_FACE_LEFT
	applymovement LOCALID_PAST_CELEBI_SOCIETY_GENTLEMAN, Common_Movement_FaceLeft
	waitmovement 0
	fadescreen FADE_FROM_BLACK
	clearflag FLAG_HIDE_CAFE_IDOL_LISIA
	addvar VAR_NUM_FOUND_IDOLS, 1
	goto_if_eq VAR_NUM_FOUND_IDOLS, 3, Looker_EventScript_FoundAllIdols
	release
	end

Past_CelebiSociety_EventScript_OscarWilde::
	lock
	faceplayer
	speakername Name_Oscar
	random 7
	call_if_eq VAR_RESULT, 0, Past_CelebiSociety_EventScript_OscarWildeQuote1
	call_if_eq VAR_RESULT, 1, Past_CelebiSociety_EventScript_OscarWildeQuote2
	call_if_eq VAR_RESULT, 2, Past_CelebiSociety_EventScript_OscarWildeQuote3
	call_if_eq VAR_RESULT, 3, Past_CelebiSociety_EventScript_OscarWildeQuote4
	call_if_eq VAR_RESULT, 4, Past_CelebiSociety_EventScript_OscarWildeQuote5
	call_if_eq VAR_RESULT, 5, Past_CelebiSociety_EventScript_OscarWildeQuote6
	call_if_eq VAR_RESULT, 6, Past_CelebiSociety_EventScript_OscarWildeQuote7
	closemessage
	release
	end

Past_CelebiSociety_EventScript_OscarWildeQuote1::
	msgbox Past_CelebiSociety_Text_OscarWildeQuote1, MSGBOX_DEFAULT
	return
	
Past_CelebiSociety_EventScript_OscarWildeQuote2::
	msgbox Past_CelebiSociety_Text_OscarWildeQuote2, MSGBOX_DEFAULT
	return
	
Past_CelebiSociety_EventScript_OscarWildeQuote3::
	msgbox Past_CelebiSociety_Text_OscarWildeQuote3, MSGBOX_DEFAULT
	return
	
Past_CelebiSociety_EventScript_OscarWildeQuote4::
	msgbox Past_CelebiSociety_Text_OscarWildeQuote4, MSGBOX_DEFAULT
	return
	
Past_CelebiSociety_EventScript_OscarWildeQuote5::
	msgbox Past_CelebiSociety_Text_OscarWildeQuote5, MSGBOX_DEFAULT
	return
	
Past_CelebiSociety_EventScript_OscarWildeQuote6::
	msgbox Past_CelebiSociety_Text_OscarWildeQuote6, MSGBOX_DEFAULT
	return
	
Past_CelebiSociety_EventScript_OscarWildeQuote7::
	msgbox Past_CelebiSociety_Text_OscarWildeQuote7, MSGBOX_DEFAULT
	return
	
Past_CelebiSociety_Text_OscarWildeQuote1:
	.string "I am so clever that sometimes I don't\n"
	.string "understand a single word I am saying.$"
	
Past_CelebiSociety_Text_OscarWildeQuote2:
	.string "I'd do anything to get back my youth.\p"
	.string "Except wake up early, partake in\n"
	.string "exercise, or be respectable.$"

Past_CelebiSociety_Text_OscarWildeQuote3:
	.string "My own business bores me to death.\n"
	.string "I prefer other people's.$"

Past_CelebiSociety_Text_OscarWildeQuote4:
	.string "To lose one parent may be regarded as\n"
	.string "a misfortune.\p"
	.string "To lose both, looks like carelessness.$"

Past_CelebiSociety_Text_OscarWildeQuote5:
	.string "Never speak disrespectfully of society.\n"
	.string "Only those who can't get into it do so.$"

Past_CelebiSociety_Text_OscarWildeQuote6:
	.string "I value my friends for their looks,\n"
	.string "my acquaintances for their characters,\l"
	.string "and my enemies for their intellects.$"

Past_CelebiSociety_Text_OscarWildeQuote7:
	.string "I can believe anything provided it's\n"
	.string "incredible.$"

Past_CelebiSociety_Text_LisiaHello:
	.string "Oh, hi! Finally, someone else from\n"
	.string "my time!\p"
	.string "I hope the storm's all settled?$"

Past_CelebiSociety_Text_LisiaLeaving:
	.string "So the storm's finally over?\n"
	.string "Awesome!\p"
	.string "Legit, we were attacked in the city out\n"
	.string "of nowhere by a bunch of Mightyena, then\l"
	.string "I got split up from Sophia in the woods…\p"
	.string "Thank Celebi for bringing me to safety…\n"
	.string "I'm still shaken up from that…\p"
	.string "Anyways, I'll rush back to the present!\n"
	.string "Thank you!$"

Past_CelebiSociety_Text_LisiaNotLeaving:
	.string "Ah… So the barista who organized our\n"
	.string "show is getting impatient and wants us\l"
	.string "there pronto.\p"
	.string "But the storm is still rampaging in the\n"
	.string "present, you said?\p"
	.string "I'm sorry, but I don't feel comfortable\n"
	.string "going back through that forest while\l"
	.string "the typhoon's still raging…\p"
	.string "I hope you get it.$"

Past_CelebiSociety_Text_LisiaNotLeavingShort:
	.string "I'm sorry, but I don't feel comfortable\n"
	.string "going back through that forest while\l"
	.string "the typhoon's still raging…\p"
	.string "I hope you get it.$"

Past_CelebiSociety_Text_LookerCouldntYouGoBack:
	.string "But you could just go back in time to\n"
	.string "right after the storm ends, no?$"

Past_CelebiSociety_Text_LisiaUmm:
	.string "Umm, I don't want to risk being out\n"
	.string "there again alone though…$"

Past_CelebiSociety_Text_LookerIllogical:
	.string "A bit illogical, but I suppose I\n"
	.string "cannot argue against anxieties.$"

Past_CelebiSociety_Text_GentlemanMyFavoriteThing:
	.string "Truly, my favorite aspect of life in\n"
	.string "Porta Bella is the wealth of knowledge\l"
	.string "given to us through the steady stream\l"
	.string "of time travelers.\p"
	.string "The Spirit of Peace is generous in her\n"
	.string "quest to save all who wander her forest!$"

Past_CelebiSociety_Text_GentlemanLisia:
	.string "The future is fascinating! I could\n"
	.string "never guess that performers would\l"
	.string "perform in front of millions of fans\l"
	.string "via the use of a 'television'!\p"
	.string "Truly, I appreciate the Spirit of Peace\n"
	.string "for her endless gift of knowledge\l"
	.string "through all these time travelers!$"

Past_CelebiSociety_Text_CouncilWomanPregame:
	.string "Ah, another time traveler.\p"
	.string "This might sound strange, but please\n"
	.string "do enjoy your stay in this era!$"

Past_CelebiSociety_Text_CouncilWomanAhAnotherTimeTraveler:
	.string "Ah, another time traveler.\p"
	.string "If you ever want something changed\n"
	.string "about the future, please let me know.\p"
	.string "I can assure you such a thing will not\n"
	.string "have any negative effects on the\l"
	.string "timeline!$"

Past_CelebiSociety_Text_CouncilWomanSaveLuvdiscs:
	.string "Excuse me, sir, did you say that\n"
	.string "large ship traffic in the future\l"
	.string "threatens our precious ecosystem?\p"
	.string "That sounds horrid!\p"
	.string "Thank you for informing me, I will\n"
	.string "ensure such a thing never happens!$"

Past_CelebiSociety_Text_CouncilWomanSeeCamilla:
	.string "Ah, a medicinal herb? That sounds like\n"
	.string "the bitter root, the Revival Herb!\p"
	.string "Camilla should have one for you.$"
	