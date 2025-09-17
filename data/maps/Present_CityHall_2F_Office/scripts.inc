Present_CityHall_2F_Office_MapScripts::
	.byte 0

Present_CityHall_2F_Office_EventScript_Anabel::
	lock
	faceplayer
	call Script_GetNPCFacingDirection
	call_if_set FLAG_SPOKE_TO_OFFICE_2F_ANABEL, Present_CityHall_2F_Office_EventScript_AnabelHiLookerShort
	call_if_unset FLAG_SPOKE_TO_OFFICE_2F_ANABEL, Present_CityHall_2F_Office_EventScript_AnabelHiLooker
	speakername Name_Anabel
	msgbox Present_CityHall_2F_Office_Text_AnabelWantAdvice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Present_CityHall_2F_Office_EventScript_AnabelNoAdvice
	msgbox Looker_Text_Hmm, MSGBOX_DEFAULT
	returnqueststate QUEST_SAVE_ESTELLA
	call_if_ne VAR_RESULT, 4, Present_CityHall_2F_Office_EventScript_AnabelEstella
	returnqueststate QUEST_INVESTIGATE_PROSPERITY
	call_if_ne VAR_RESULT, 4, Present_CityHall_2F_Office_EventScript_AnabelHeadRanger
	returnqueststate QUEST_INTERROGATE_MATT
	call_if_ne VAR_RESULT, 4, Present_CityHall_2F_Office_EventScript_AnabelAquaCorp
	returnqueststate QUEST_DEFEAT_PHOEBE
	call_if_ne VAR_RESULT, 4, Present_CityHall_2F_Office_EventScript_AnabelGym
	returnqueststate QUEST_FIND_THE_CULPRIT
	call_if_eq VAR_RESULT, 2, Present_CityHall_2F_Office_EventScript_AnabelCulprit
	call_if_unset FLAG_ANABEL_HAS_HINTS, Present_CityHall_2F_Office_EventScript_AnabelOutOfAdvice
	call_if_set FLAG_ANABEL_HAS_HINTS, Present_CityHall_2F_Office_EventScript_AnabelYouGotThis
	closemessage
	clearflag FLAG_ANABEL_HAS_HINTS
	applymovement LOCALID_OFFICE_2F_ANABEL, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Present_CityHall_2F_Office_EventScript_AnabelHiLooker::
	speak LOCALID_OFFICE_2F_ANABEL, VAR_0x8005, Name_Anabel, Present_CityHall_2F_Office_Text_AnabelHiLooker
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_CityHall_2F_Office_Text_LookerTripOkay
	speak LOCALID_OFFICE_2F_ANABEL, VAR_0x8005, Name_Anabel, Present_CityHall_2F_Office_Text_AnabelOhCamillaToldMe
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_CityHall_2F_Office_Text_LookerWhyNoDeduction
	speak LOCALID_OFFICE_2F_ANABEL, VAR_0x8005, Name_Anabel, Present_CityHall_2F_Office_Text_AnabelYouCantJust
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_CityHall_2F_Office_Text_LookerSoHowAreYouAffected
	speak LOCALID_OFFICE_2F_ANABEL, VAR_0x8005, Name_Anabel, Present_CityHall_2F_Office_Text_AnabelIKnowTheCulprit
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 120
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_CityHall_2F_Office_Text_LookerWillYouTellMe
	speak LOCALID_OFFICE_2F_ANABEL, VAR_0x8005, Name_Anabel, Present_CityHall_2F_Office_Text_AnabelNo
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_OFFICE_2F_ANABEL, Common_Movement_FaceDown
	waitmovement 0
	delay 170
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	speak LOCALID_OFFICE_2F_ANABEL, VAR_0x8005, Name_Anabel, Present_CityHall_2F_Office_Text_AnabelWhat
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_CityHall_2F_Office_Text_LookerFine
	speak LOCALID_OFFICE_2F_ANABEL, VAR_0x8005, Name_Anabel, Present_CityHall_2F_Office_Text_AnabelSureIDo
	setflag FLAG_SPOKE_TO_OFFICE_2F_ANABEL
	return

Present_CityHall_2F_Office_EventScript_AnabelHiLookerShort::
	speak LOCALID_OFFICE_2F_ANABEL, VAR_0x8005, Name_Anabel, Present_CityHall_2F_Office_Text_AnabelHiLookerShort
	playse SE_SELECT
	return

Present_CityHall_2F_Office_EventScript_AnabelEstella::
	playse SE_SELECT
	msgbox Present_CityHall_2F_Office_Text_AnabelEstella, MSGBOX_DEFAULT
	setflag FLAG_ANABEL_HAS_HINTS
	return

Present_CityHall_2F_Office_EventScript_AnabelAquaCorp::
	playse SE_SELECT
	msgbox Present_CityHall_2F_Office_Text_AnabelAquaCorp, MSGBOX_DEFAULT
	setflag FLAG_ANABEL_HAS_HINTS
	return

Present_CityHall_2F_Office_EventScript_AnabelGym::
	playse SE_SELECT
	call_if_set FLAG_ANABEL_HAS_HINTS, Present_CityHall_2F_Office_EventScript_AnabelGymToo
	call_if_unset FLAG_ANABEL_HAS_HINTS, Present_CityHall_2F_Office_EventScript_AnabelGymFirst
	setflag FLAG_ANABEL_HAS_HINTS
	return
	
Present_CityHall_2F_Office_EventScript_AnabelGymToo::
	msgbox Present_CityHall_2F_Office_Text_AnabelGymToo, MSGBOX_DEFAULT
	return

Present_CityHall_2F_Office_EventScript_AnabelGymFirst::
	msgbox Present_CityHall_2F_Office_Text_AnabelGym, MSGBOX_DEFAULT
	return

Present_CityHall_2F_Office_EventScript_AnabelHeadRanger::
	playse SE_SELECT
	msgbox Present_CityHall_2F_Office_Text_AnabelHeadRanger, MSGBOX_DEFAULT
	setflag FLAG_ANABEL_HAS_HINTS
	return

Present_CityHall_2F_Office_EventScript_AnabelCulprit::
	playse SE_SELECT
	msgbox Present_CityHall_2F_Office_Text_AnabelCulprit, MSGBOX_DEFAULT
	setflag FLAG_ANABEL_HAS_HINTS
	return
	
Present_CityHall_2F_Office_EventScript_AnabelNoAdvice::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_NoThanks
	speak LOCALID_OFFICE_2F_ANABEL, VAR_0x8005, Name_Anabel, Present_CityHall_2F_Office_Text_AnabelNoAdvice
	closemessage
	applymovement LOCALID_OFFICE_2F_ANABEL, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Present_CityHall_2F_Office_EventScript_AnabelOutOfAdvice::
	speak LOCALID_OFFICE_2F_ANABEL, VAR_0x8005, Name_Anabel, Present_CityHall_2F_Office_Text_AnabelOutOfAdvice
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_CityHall_2F_Office_Text_LookerOutOfAdvice
	return

Present_CityHall_2F_Office_EventScript_AnabelYouGotThis::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_ThankYouForYourHelp
	speak LOCALID_OFFICE_2F_ANABEL, VAR_0x8005, Name_Anabel, Present_CityHall_2F_Office_Text_AnabelBelievesInYou
	return

Present_CityHall_2F_Office_EventScript_Mayor::
	lock
	faceplayer
	speakername Name_Mayor
	msgbox Present_CityHall_2F_Office_Text_Mayor, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OFFICE_MAYOR, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Present_CityHall_2F_Office_EventScript_Display::
	msgbox Present_CityHall_2F_Office_Text_Egg, MSGBOX_SIGN
	end

Present_CityHall_2F_Office_Text_Egg:
	.string "An intricately decorated fabergé egg\n"
	.string "is on display.$"

Present_CityHall_2F_Office_Text_Mayor:
	.string "Oh dear! Are you okay?\p"
	.string "Anabel informed me of what went down\n"
	.string "in the forest earlier!\p"
	.string "She also seemed to have full faith in\n"
	.string "you to help us out of our predicament!\p"
	.string "I believe in you too, Mr. Looker!$"

Present_CityHall_2F_Office_Text_AnabelBelievesInYou:
	.string "You got this, Looker!\n"
	.string "I believe in you!$"

Present_CityHall_2F_Office_Text_AnabelOutOfAdvice:
	.string "You already solved the case!\n"
	.string "Are you worried you missed something?\p"
	.string "Just enjoy your time in Porta Bella\n"
	.string "already!$"

Present_CityHall_2F_Office_Text_LookerOutOfAdvice:
	.string "Fine. It'll be tough with all the\n"
	.string "paperwork on my mind left to do…$"

Present_CityHall_2F_Office_Text_AnabelNoAdvice:
	.string "Okay then. Let me know if you need any\n"
	.string "help cracking this case!$"

Present_CityHall_2F_Office_Text_AnabelHiLookerShort:
	.string "Hi, Looker!$"

Present_CityHall_2F_Office_Text_AnabelWantAdvice:
	.string "Would you like some advice on where\n"
	.string "to investigate next?$"

Present_CityHall_2F_Office_Text_AnabelHiLooker:
	.string "Hi, Looker!\p"
	.string "How was your trip back from the past?$"

Present_CityHall_2F_Office_Text_LookerTripOkay:
	.string "It was certainly better on the way\n"
	.string "back. At the very least, I could prepare\l"
	.string "for the spinning…\p"
	.string "Say, do you know why I have been seeing\n"
	.string "visions of the future?\p"
	.string "My deduction abilities are unaffected,\n"
	.string "but I seem to know intuitively what\l"
	.string "will happen mid-battle.$"

Present_CityHall_2F_Office_Text_AnabelOhCamillaToldMe:
	.string "Oh! Camilla told me about that.\p"
	.string "The first time you time travel, your\n"
	.string "sense of 'when' will be all messed up\l"
	.string "until your brain readjusts.$"

Present_CityHall_2F_Office_Text_LookerWhyNoDeduction:
	.string "So why can I not see who took\n"
	.string "Landorus already?$"

Present_CityHall_2F_Office_Text_AnabelYouCantJust:
	.string "Well, you can't just 'see the future'!\p"
	.string "It's an intuition thing. Kind of like a\n"
	.string "sixth sense of sorts.\p"
	.string "As such, it won't affect everything.$"

Present_CityHall_2F_Office_Text_LookerSoHowAreYouAffected:
	.string "So how have you been affected?$"

Present_CityHall_2F_Office_Text_AnabelIKnowTheCulprit:
	.string "Oh, I know what happened to Landorus!$"

Present_CityHall_2F_Office_Text_LookerWillYouTellMe:
	.string "Ah. Will you tell me then so we can\n"
	.string "close this case?$"

Present_CityHall_2F_Office_Text_AnabelNo:
	.string "No.$"

Present_CityHall_2F_Office_Text_AnabelWhat:
	.string "What!? Don't give me that look!\n"
	.string "It's more fun this way!\p"
	.string "I also know you can figure this one\n"
	.string "out on your own.\p"
	.string "For once.$"

Present_CityHall_2F_Office_Text_LookerFine:
	.string "Fine. Would you at least have any\n"
	.string "guidance on where to look next?$"

Present_CityHall_2F_Office_Text_AnabelSureIDo:
	.string "Sure I do.$"

Present_CityHall_2F_Office_Text_AnabelEstella:
	.string "Have you checked in with Estella's\n"
	.string "dad since coming back to the future?\p"
	.string "I'm sure he wants to show you his\n"
	.string "gratitude.$"

Present_CityHall_2F_Office_Text_AnabelAquaCorp:
	.string "We DID originally come by to\n"
	.string "investigate Team Aqua, you know.\p"
	.string "You still hafta perform that audit,\n"
	.string "sooner or later.$"

Present_CityHall_2F_Office_Text_AnabelGym:
	.string "The gym leader should be available\n"
	.string "now.\p"
	.string "She's quite knowledgeable about the\n"
	.string "goings-on of Porta Bella City!$"

Present_CityHall_2F_Office_Text_AnabelGymToo:
	.string "Lastly, the gym leader should be\n"
	.string "available now.\p"
	.string "She's quite knowledgeable about the\n"
	.string "goings-on of Porta Bella City!$"

Present_CityHall_2F_Office_Text_AnabelHeadRanger:
	.string "The head ranger said she wanted to\n"
	.string "see you after you got back to Porta\l"
	.string "Bella, remember?\p"
	.string "I already have. Make sure you check in\n"
	.string "at her office here!$"

Present_CityHall_2F_Office_Text_AnabelCulprit:
	.string "Ah! So you figured out it was one of\n"
	.string "the gym challengers in town!\p"
	.string "Do you know which yet?$"

Present_CityHall_2F_Office_Text_LookerNotYet:
	.string "Not yet.$"

Present_CityHall_2F_Office_Text_AnabelYouMightHaveTalked:
	.string "Well, there's a decent chance you\n"
	.string "have already talked to them!\p"
	.string "I'll narrow it down to five, at least -\n"
	.string "Leaf, Katerina, May, Blue, and Trey.$"
	