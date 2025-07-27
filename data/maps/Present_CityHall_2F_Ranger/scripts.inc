Present_CityHall_2F_Ranger_MapScripts::
	.byte 0

Present_CityHall_2F_Ranger_EventScript_HeadRanger::
	lockall
	faceplayer
	returnqueststate QUEST_INVESTIGATE_PROSPERITY
	switch VAR_RESULT
	case 1, Present_CityHall_2F_Ranger_EventScript_HeadRangerInitiateQuest
	case 2, Present_CityHall_2F_Ranger_EventScript_HeadRangerActiveQuest
	case 3, Present_CityHall_2F_Ranger_EventScript_HeadRangerRewardQuest
	case 4, Present_CityHall_2F_Ranger_EventScript_HeadRangerCompletedQuest
	releaseall
	end

Present_CityHall_2F_Ranger_EventScript_HeadRangerInitiateQuest:
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	msgbox Present_CityHall_2F_Ranger_Text_LookerHello, MSGBOX_DEFAULT
	applymovement LOCALID_CITYHALL_RANGER, Common_Movement_WalkInPlaceFasterLeft
	msgbox Present_CityHall_2F_Ranger_Text_2_RangerGladYouMadeItOut
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	msgbox Present_CityHall_2F_Ranger_Text_LookerOfCourse, MSGBOX_DEFAULT
	applymovement LOCALID_CITYHALL_RANGER, Common_Movement_WalkInPlaceFasterLeft
	msgbox Present_CityHall_2F_Ranger_Text_HeadRangerInitiate, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CITYHALL_RANGER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	questmenu QUEST_MENU_SET_ACTIVE, QUEST_INVESTIGATE_PROSPERITY
	setvar VAR_QUEUE_GENIE_FIGHT, 1
	releaseall
	end
	
Present_CityHall_2F_Ranger_EventScript_HeadRangerActiveQuest:
	msgbox Present_CityHall_2F_Ranger_Text_HeadRangerActive, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CITYHALL_RANGER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end
	
Present_CityHall_2F_Ranger_EventScript_HeadRangerRewardQuest:
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	msgbox Present_CityHall_2F_Ranger_Text_LookerImBack, MSGBOX_DEFAULT
	applymovement LOCALID_CITYHALL_RANGER, Common_Movement_WalkInPlaceFasterLeft
	msgbox Present_CityHall_2F_Ranger_Text_HeadRangerDang, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	msgbox Present_CityHall_2F_Ranger_Text_LookerAllInADaysWork, MSGBOX_DEFAULT
	applymovement LOCALID_CITYHALL_RANGER, Common_Movement_WalkInPlaceFasterLeft
	msgbox Present_CityHall_2F_Ranger_Text_HeadRangerReward, MSGBOX_DEFAULT
	giveitem ITEM_SAFARI_BALL, 500
	closemessage
	applymovement LOCALID_CITYHALL_RANGER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	questmenu QUEST_MENU_COMPLETE_QUEST QUEST_INVESTIGATE_PROSPERITY
	releaseall
	end
	
Present_CityHall_2F_Ranger_EventScript_HeadRangerCompletedQuest:
	checkitem ITEM_SAFARI_BALL
	goto_if_eq VAR_RESULT, TRUE, Present_CityHall_2F_Ranger_EventScript_HeadRangerGiveMoreSafariBalls
	msgbox Present_CityHall_2F_Ranger_Text_HeadRangerComplete, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CITYHALL_RANGER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

Present_CityHall_2F_Ranger_EventScript_HeadRangerGiveMoreSafariBalls:
	msgbox Present_CityHall_2F_Ranger_Text_HeadRangerGiveMoreSafariBalls
	giveitem ITEM_SAFARI_BALL, 500
	closemessage
	applymovement LOCALID_CITYHALL_RANGER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

Present_CityHall_2F_Ranger_Text_LookerImBack:
	.string "Looker: I've arrived back.\p"
	.string "Not only was Tornadus there, as you\n"
	.string "suspected, but I also got ambushed\l"
	.string "from behind by Thundurus…$"

Present_CityHall_2F_Ranger_Text_HeadRangerGiveMoreSafariBalls:
	.string "Ranger: I'm sorry? Did you just say\n"
	.string "you RAN OUT of Safari Balls?\p"
	.string "How?\p"
	.string "Uhh… here's more?\p"
	.string "If I find out you've been running\n"
	.string "rampant on the wildlife here, I\l"
	.string "WILL report you to your higher-ups…$"

Present_CityHall_2F_Ranger_Text_LookerHello:
	.string "Looker: Hello.\n"
	.string "Has Anabel reported in on what happened?$"

Present_CityHall_2F_Ranger_Text_2_RangerGladYouMadeItOut:
	.string "Ranger: Welcome back, Looker!\p"
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
	.string "Looker: Not the warmest welcome…\n"
	.string "But sure.\p"
	.string "I'm sure this will help us find out\n"
	.string "more on what happened to Landorus.$"

Present_CityHall_2F_Ranger_Text_HeadRangerInitiate:
	.string "Ranger: Oh, thank you!\p"
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
	.string "getting through to there now.$"

Present_CityHall_2F_Ranger_Text_HeadRangerDang:
	.string "Ranger: Wait, you're telling me\n"
	.string "you had to fight back both\l"
	.string "legendaries at the same time!?\p"
	.string "That's insane!$"

Present_CityHall_2F_Ranger_Text_LookerAllInADaysWork:
	.string "Looker: All in a day's work.\n"
	.string "More peculiarly…\p"
	.string "Littered on the ground of the\n"
	.string "Shrine were plenty of used Pokéballs…\p"
	.string "Would you suppose anyone might have\n"
	.string "tried to catch Landorus?$"

Present_CityHall_2F_Ranger_Text_HeadRangerReward:
	.string "Ranger: Hmm… I suppose that is a\n"
	.string "possibility…\p"
	.string "We have nobody on guard in the mornings\n"
	.string "thanks to bad staffing issues…\p"
	.string "I suppose someone might have snuck in\n"
	.string "during those unattended hours and tried\l"
	.string "to catch it?\p"
	.string "Adults know not to over-catch wild\n"
	.string "Pokémon, but children can often run\l"
	.string "rampant on the ecosystem if unchecked.\p"
	.string "But to think there would be one strong\n"
	.string "enough to capture a legend…\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "Anyways, I think we can trust you\n"
	.string "to not go crazy yourself.\p"
	.string "We don't have much to give, but I hope\n"
	.string "these Safari Balls could come in handy?$" 

Present_CityHall_2F_Ranger_Text_HeadRangerComplete:
	.string "Thank you for all of your\n"
	.string "help, Looker!\p"
	.string "I hope those Safari Balls will\n"
	.string "come in handy in the future.$"