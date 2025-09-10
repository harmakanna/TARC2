Present_CityHall_2F_Ranger_MapScripts::
	.byte 0

Present_CityHall_2F_Ranger_EventScript_HeadRanger::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_MAIN_GAME_START, Present_CityHall_2F_Ranger_EventScript_HeadRangerBusy
	returnqueststate QUEST_INVESTIGATE_PROSPERITY
	switch VAR_RESULT
	case 1, Present_CityHall_2F_Ranger_EventScript_HeadRangerInitiateQuest
	case 2, Present_CityHall_2F_Ranger_EventScript_HeadRangerActiveQuest
	case 3, Present_CityHall_2F_Ranger_EventScript_HeadRangerRewardQuest
	case 4, Present_CityHall_2F_Ranger_EventScript_HeadRangerCompletedQuest
	release
	end

Present_CityHall_2F_Ranger_EventScript_HeadRangerBusy:
	msgbox Present_CityHall_2F_Ranger_Text_HeadRangerBusyWithPaperwork, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CITYHALL_RANGER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Present_CityHall_2F_Ranger_EventScript_HeadRangerInitiateQuest::
	setflag FLAG_SYS_DISAPPEAR_QUESTS
	call Script_GetNPCFacingDirection
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_CityHall_2F_Ranger_Text_LookerHello
	speak LOCALID_CITYHALL_RANGER, VAR_0x8005, Name_Head_Ranger, Present_CityHall_2F_Ranger_Text_HeadRangerGladYouMadeItOut
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_CityHall_2F_Ranger_Text_LookerOfCourse
	speak LOCALID_CITYHALL_RANGER, VAR_0x8005, Name_Head_Ranger, Present_CityHall_2F_Ranger_Text_HeadRangerInitiate
	closemessage
	applymovement LOCALID_CITYHALL_RANGER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	startquest QUEST_INVESTIGATE_PROSPERITY
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	setvar VAR_QUEUE_GENIE_FIGHT, 2
	release
	end
	
Present_CityHall_2F_Ranger_EventScript_HeadRangerActiveQuest::
	msgbox Present_CityHall_2F_Ranger_Text_HeadRangerActive, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CITYHALL_RANGER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
	
Present_CityHall_2F_Ranger_EventScript_HeadRangerRewardQuest::
	setflag FLAG_SYS_DISAPPEAR_QUESTS
	call Script_GetNPCFacingDirection
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_CityHall_2F_Ranger_Text_LookerImBack
	speak LOCALID_CITYHALL_RANGER, VAR_0x8005, Name_Head_Ranger, Present_CityHall_2F_Ranger_Text_HeadRangerDang
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_CityHall_2F_Ranger_Text_LookerAllInADaysWork
	speak LOCALID_CITYHALL_RANGER, VAR_0x8005, Name_Head_Ranger, Present_CityHall_2F_Ranger_Text_HeadRangerReward
	speakername NULL
	giveitem ITEM_SAFARI_BALL, 500
	closemessage
	applymovement LOCALID_CITYHALL_RANGER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	completequest QUEST_INVESTIGATE_PROSPERITY
	setvar VAR_PLAY_LOOKER_SCENE_ON_TRANSITION, 1
	setvar VAR_CUTSCENE_FOREST_STATE, 3
	setvar VAR_TRIGGER_CUTSCENE_FOREST, 2
	setflag FLAG_PLAY_LOOKER_RANGER_ON_TRANSITION
	clearflag FLAG_HIDE_FOREST_DEDENNE
	clearflag FLAG_HIDE_FOREST_TOGEDEMARU
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	release
	end
	
Present_CityHall_2F_Ranger_EventScript_HeadRangerCompletedQuest::
	goto_if_eq VAR_CATCH_GENIES_QUEST, 5, Present_CityHall_2F_Ranger_EventScript_HeadRangerExcuseMe
	goto_if_eq VAR_CATCH_GENIES_QUEST, 6, Present_CityHall_2F_Ranger_EventScript_HeadRangerMad
	checkitem ITEM_SAFARI_BALL
	goto_if_eq VAR_RESULT, FALSE, Present_CityHall_2F_Ranger_EventScript_HeadRangerGiveMoreSafariBalls
	goto_if_eq VAR_CATCH_GENIES_QUEST, 6, Present_CityHall_2F_Ranger_EventScript_HeadRangerMad
	msgbox Present_CityHall_2F_Ranger_Text_HeadRangerComplete, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CITYHALL_RANGER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Present_CityHall_2F_Ranger_EventScript_HeadRangerExcuseMe::
	call Script_GetNPCFacingDirection
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_CityHall_2F_Ranger_Text_LookerCaughtTheGenies
	speak LOCALID_CITYHALL_RANGER, VAR_0x8005, Name_Head_Ranger, Present_CityHall_2F_Ranger_Text_HeadRangerExcuseMe
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_CityHall_2F_Ranger_Text_LookerSorry
	speak LOCALID_CITYHALL_RANGER, VAR_0x8005, Name_Head_Ranger, Present_CityHall_2F_Ranger_Text_HeadRangerYouKnowWhat
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_CityHall_2F_Ranger_Text_LookerOkay
	closemessage
	applymovement LOCALID_CITYHALL_RANGER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	addvar VAR_CATCH_GENIES_QUEST, 1
	release
	end

Present_CityHall_2F_Ranger_EventScript_HeadRangerMad::
	checkitem ITEM_SAFARI_BALL
	goto_if_eq VAR_RESULT, FALSE, Present_CityHall_2F_Ranger_EventScript_HeadRangerGiveMoreSafariBallsMad
	speak LOCALID_CITYHALL_RANGER, VAR_0x8005, Name_Head_Ranger, Present_CityHall_2F_Ranger_Text_HeadRangerDontTalkToMe
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_CityHall_2F_Ranger_Text_LookerOkay
	closemessage
	applymovement LOCALID_CITYHALL_RANGER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Present_CityHall_2F_Ranger_EventScript_HeadRangerGiveMoreSafariBallsMad::
	speak LOCALID_CITYHALL_RANGER, VAR_0x8005, Name_Head_Ranger, Present_CityHall_2F_Ranger_Text_HeadRangerGiveMoreSafariBallsMad
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_CityHall_2F_Ranger_Text_LookerOkay
	speakername NULL
	giveitem ITEM_SAFARI_BALL, 500
	closemessage
	applymovement LOCALID_CITYHALL_RANGER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Present_CityHall_2F_Ranger_EventScript_HeadRangerGiveMoreSafariBalls::
	speakername Name_Head_Ranger
	msgbox Present_CityHall_2F_Ranger_Text_HeadRangerGiveMoreSafariBalls, MSGBOX_DEFAULT
	speakername NULL
	giveitem ITEM_SAFARI_BALL, 500
	closemessage
	applymovement LOCALID_CITYHALL_RANGER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Present_CityHall_2F_Ranger_EventScript_Scientist::
	lock
	faceplayer
	returnqueststate QUEST_FORGOTTEN_TO_TIME
	switch VAR_RESULT
	case 1, Present_CityHall_2F_Ranger_EventScript_ScientistQuestInactive
	case 2, Present_CityHall_2F_Ranger_EventScript_ScientistQuestActive
	case 4, Present_CityHall_2F_Ranger_EventScript_ScientistQuestComplete
	end

Present_CityHall_2F_Ranger_EventScript_ScientistQuestInactive::
	speakername Name_Present_FossilScientist
	msgbox Present_CityHall_2F_Ranger_Text_ScientistIWishThoseFossils, MSGBOX_DEFAULT
	closemessage
	release
	end

Present_CityHall_2F_Ranger_EventScript_ScientistQuestActive::
	goto_if_set FLAG_CHOSE_TUSK_FOSSIL, Present_CityHall_2F_Ranger_EventScript_ScientistChoseTusk
	goto_if_set FLAG_CHOSE_WING_FOSSIL, Present_CityHall_2F_Ranger_EventScript_ScientistChoseWing
	release
	end

Present_CityHall_2F_Ranger_EventScript_ScientistChoseTusk::
	speakername Name_Present_FossilScientist
	msgbox Present_CityHall_2F_Ranger_Text_ScientistIWishWing, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_CITYHALL_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	delay 50
	speakername Name_Present_FossilScientist
	msgbox Present_CityHall_2F_Ranger_Text_ScientistOhATusk, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	delay 80
	fadescreen FADE_FROM_BLACK
	delay 10
	speakername Name_Present_FossilScientist
	msgbox Present_CityHall_2F_Ranger_Text_FossilScientistIveDoneItTusk, MSGBOX_DEFAULT
	goto Present_CityHall_2F_Ranger_EventScript_FossilScientistGiveMamoswine
	release
	end


Present_CityHall_2F_Ranger_EventScript_ScientistChoseWing::
	speakername Name_Present_FossilScientist
	msgbox Present_CityHall_2F_Ranger_Text_ScientistIWishTusk, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_CITYHALL_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	delay 50
	speakername Name_Present_FossilScientist
	msgbox Present_CityHall_2F_Ranger_Text_ScientistOhAWing, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	delay 80
	fadescreen FADE_FROM_BLACK
	delay 10
	speakername Name_Present_FossilScientist
	msgbox Present_CityHall_2F_Ranger_Text_FossilScientistIveDoneItWing, MSGBOX_DEFAULT
	goto Present_CityHall_2F_Ranger_EventScript_FossilScientistGiveYanmega
	release
	end

Present_CityHall_2F_Ranger_EventScript_FossilQuestFinish::
	completequest QUEST_FORGOTTEN_TO_TIME
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	release
	end

Present_CityHall_2F_Ranger_EventScript_ScientistQuestComplete::
	msgbox Present_CityHall_2F_Ranger_Text_ScientistThankYou, MSGBOX_DEFAULT
	closemessage
	release
	end

Present_CityHall_2F_Ranger_EventScript_Display::
	msgbox Present_CityHall_2F_Ranger_Text_Egg, MSGBOX_SIGN
	end

Present_CityHall_2F_Ranger_Text_Egg:
	.string "An intricately decorated fabergé egg\n"
	.string "is on display.$"

Present_CityHall_2F_Ranger_Text_ScientistThankYou:
	.string "Thank you for giving me the chance\n"
	.string "to revive a Pokémon!\p"
	.string "Now if only I could revive that\n"
	.string "other fossil on display…$"
	
Present_CityHall_2F_Ranger_Text_FossilScientistIveDoneItTusk:
	.string "Ahahahahahaha!\p"
	.string "I've done it!\p"
	.string "I have successfully revived a Pokémon\n"
	.string "from its remains!\p"
	.string "Thank you sir! I can finally put to rest\n"
	.string "my many theories!\p"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "Oh, you can keep the Mamoswine.\p"
	.string "I'm not a Pokémon trainer, that thing\n"
	.string "would impale me!$"

Present_CityHall_2F_Ranger_Text_FossilScientistIveDoneItWing:
	.string "Ahahahahahaha!\p"
	.string "I've done it!\p"
	.string "I have successfully revived a Pokémon\n"
	.string "from its remains!\p"
	.string "Thank you sir! I can finally put to rest\n"
	.string "my many theories!\p"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "Oh, you can keep the Yanmega.\p"
	.string "I'm not a Pokémon trainer, that thing\n"
	.string "would bite my head off!$"

Present_CityHall_2F_Ranger_Text_ScientistOhATusk:
	.string "Ooo! Ooo!\p"
	.string "Is that an eroded tusk you have?\p"
	.string "Give it here! Let me show you something\n"
	.string "that will blow your mind!$"

Present_CityHall_2F_Ranger_Text_ScientistOhAWing:
	.string "Ooo! Ooo!\p"
	.string "Is that a wing imprint you have?\p"
	.string "Give it here! Let me show you something\n"
	.string "that will blow your mind!$"

Present_CityHall_2F_Ranger_Text_ScientistIWishWing:
	.string "Oh…\p"
	.string "I wish I could study that wing fossil,\n"
	.string "but the mayor says it's a priceless\l"
	.string "treasure…\p"
	.string "If only I could have it for myself…$"

Present_CityHall_2F_Ranger_Text_ScientistIWishTusk:
	.string "Oh…\p"
	.string "I wish I could study that tusk fossil,\n"
	.string "but the mayor says it's a priceless\l"
	.string "treasure…\p"
	.string "If only I could have it for myself…$"

Present_CityHall_2F_Ranger_Text_ScientistIWishThoseFossils:
	.string "Oh…\p"
	.string "I wish I could study those two fossils,\n"
	.string "but the mayor says they're priceless\l"
	.string "treasures…\p"
	.string "If only I could have one for myself…$"
	
Present_CityHall_2F_Ranger_Text_LookerImBack:
	.string "I've arrived back.\p"
	.string "Not only was Tornadus there, as you\n"
	.string "suspected, but I also got ambushed\l"
	.string "from behind by Thundurus…$"

Present_CityHall_2F_Ranger_Text_HeadRangerGiveMoreSafariBalls:
	.string "I'm sorry? Did you just say\n"
	.string "you RAN OUT of Safari Balls?\p"
	.string "How?\p"
	.string "Uhh… here's more?\p"
	.string "If I find out you've been running\n"
	.string "rampant on the wildlife here, I\l"
	.string "WILL report you to your higher-ups…$"

Present_CityHall_2F_Ranger_Text_HeadRangerGiveMoreSafariBallsMad:
	.string "You RAN OUT of Safari Balls?\p"
	.string "Did you catch ANOTHER genie…?\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "Sigh…\p"
	.string "Just take them…$"

Present_CityHall_2F_Ranger_Text_LookerHello:
	.string "Hello.\n"
	.string "Has Anabel reported in on what happened?$"

Present_CityHall_2F_Ranger_Text_HeadRangerGladYouMadeItOut:
	.string "Welcome back, Looker!\p"
	.string "She filled me in on everything that\n"
	.string "happened in the woods.\p"
	.string "Glad to hear you're back from the\n"
	.string "past and Estella's okay.\p"
	.string "Look, we've been short-staffed since\n"
	.string "our budget cuts and need more help.\p"
	.string "Sorry for putting you on the spot, but\n"
	.string "could you please investigate why we're\l"
	.string "getting such strong readings of the\l"
	.string "storm from the Shrine of Prosperity?\p"
	.string "If it's Tornadus, then we don't have\n"
	.string "the manpower to take it ourselves.$"

Present_CityHall_2F_Ranger_Text_LookerOfCourse:
	.string "Not the warmest welcome…\n"
	.string "But sure.\p"
	.string "I'm sure this will help us find out\n"
	.string "more on what happened to Landorus.$"

Present_CityHall_2F_Ranger_Text_HeadRangerInitiate:
	.string "Oh, thank you!\p"
	.string "You'll find the path to the Shrine\n"
	.string "of Prosperity on the east side of\l"
	.string "the city.\p"
	.string "I'll give a ring to the ranger on\n"
	.string "watch that you're going to help us.\p"
	.string "Be careful - it's still dangerous\n"
	.string "out in the forest!$"

Present_CityHall_2F_Ranger_Text_HeadRangerActive:
	.string "You'll find the path to the Shrine\n"
	.string "of Prosperity on the east side of\l"
	.string "the city.\p"
	.string "I gave the ranger stationed there a\n"
	.string "call that you're going to help us,\l"
	.string "so you shouldn't have issues getting\l"
	.string "through to there now.$"

Present_CityHall_2F_Ranger_Text_HeadRangerDang:
	.string "Wait, you're telling me you had to\n"
	.string "fight back both legendaries at the\l"
	.string "same time!?\p"
	.string "That's insane!$"

Present_CityHall_2F_Ranger_Text_LookerAllInADaysWork:
	.string "All in a day's work.\n"
	.string "More peculiarly…\p"
	.string "Littered on the ground of the Shrine\n"
	.string "were plenty of used Pokéballs…\p"
	.string "Would you suppose anyone might have\n"
	.string "tried to catch Landorus?$"

Present_CityHall_2F_Ranger_Text_HeadRangerReward:
	.string "Hmm… I suppose that is a\n"
	.string "possibility…\p"
	.string "We have nobody on guard in the mornings\n"
	.string "thanks to bad staffing issues…\p"
	.string "I suppose someone might have snuck in\n"
	.string "during those unattended hours and\l"
	.string "tried to catch it?\p"
	.string "Adults know not to over-catch wild\n"
	.string "Pokémon, but children can often run\l"
	.string "rampant on the ecosystem if unchecked.\p"
	.string "But to think there would be one strong\n"
	.string "enough to capture a legend…\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "Anyways, I think we can trust you to\n"
	.string "not go crazy yourself.\p"
	.string "We don't have much to give, but I hope\n"
	.string "these Safari Balls could come in handy?$" 

Present_CityHall_2F_Ranger_Text_HeadRangerComplete:
	.string "Thank you for all of your help,\n"
	.string "Looker!\p"
	.string "I hope those Safari Balls will come\n"
	.string "in handy in the future.$"

Present_CityHall_2F_Ranger_Text_HeadRangerBusyWithPaperwork:
	.string "Sorry, I'm busy with too many reports\n"
	.string "right now…\p"
	.string "Could you please come back later?$"

Present_CityHall_2F_Ranger_Text_LookerCaughtTheGenies:
	.string "I caught the genies. They shouldn't\n"
	.string "cause any more havoc now.$"

Present_CityHall_2F_Ranger_Text_HeadRangerExcuseMe:
	.string "I'm sorry…\p"
	.string "You CAUGHT the genies?\p"
	.string "Why would you do that?\p"
	.string "Why would you CATCH the genies?$"

Present_CityHall_2F_Ranger_Text_LookerSorry:
	.string "Sorry…\p"
	.string "I figured it would help the city\n"
	.string "return to a state of normalcy while\l"
	.string "I remain here…$"

Present_CityHall_2F_Ranger_Text_HeadRangerYouKnowWhat:
	.string "You know what?\p"
	.string "Fine.\p"
	.string "Fine!\p"
	.string "We don't know what it might do to the\n"
	.string "local ecosystem by catching them, but\l"
	.string "I'll let this slide because you've\l"
	.string "already helped so much.\p"
	.string "Do NOT do something that reckless again!$"

Present_CityHall_2F_Ranger_Text_LookerOkay:
	.string "Okay…$"

Present_CityHall_2F_Ranger_Text_HeadRangerDontTalkToMe:
	.string "Don't talk to me.$"