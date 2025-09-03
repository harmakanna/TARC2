Looker_Text_WhatSeemsToBeTheProblem:
    .string "What seems to be the problem?$"

Looker_Text_CanIHelpYouWithSomething:
    .string "Can I help you with something?$"

Looker_Text_IsSomethingWrong:
    .string "Is something wrong?$"

Looker_Text_HowCanIHelp:
    .string "How can I help?$"

Looker_Text_Understood:
    .string "Understood.$"

Looker_Text_ThereHasToBeSomething:
    .string "There has to be something I can\n"
    .string "do to help.$"

Looker_Text_IdBeHappyToHelp:
    .string "I'd be happy to help.$"

Looker_Text_ICanCertainlyTry:
    .string "I can certainly try.$"

Looker_Text_ConsiderItDone:
    .string "Consider it done.$"
    
Looker_Text_MyApologies:
    .string "My apologies.$"

Looker_Text_YouAreUnderSuspicion:
    .string "Stop, in the name of the law!\p"
    .string "You are under suspicion of capturing\n"
    .string "Landorus and disrupting the lives of\l"
    .string "people and Pokémon in Porta Bella alike!$"

Looker_Text_IKnowYouDidIt:
    .string "Don't you play dumb with me!\p"
    .string "I know you were the one who went to the\n"
    .string "Shrine of Prosperity, caught Landorus,\l"
    .string "and caused Tornadus and Thundurus to\l"
    .string "go wild in his absense!$"

Looker_Text_ComingWithMe:
    .string "You're coming with me to City Hall so\n"
    .string "we can sort this mess out!$"

Looker_Text_IKnewItWasYou:
    .string "Aha! I knew it was you!\p"
    .string "My hunch is always correct!$"

Looker_Text_IWillHandleThis:
    .string "I will handle this posthaste.$"

Looker_Text_GladICouldHelp:
    .string "I'm glad I could help.$"

Looker_Text_AnotherProblemSolved:
    .string "Another problem solved.$"

Looker_Text_OfCourse:
    .string "Of course.$"

Looker_Text_OfCourseICanHelp:
    .string "Of course I can help.$"
    
Looker_Text_SorryImBusy:
    .string "Sorry, I'm busy.$"

Looker_Text_SorryICouldntHelp:
    .string "Sorry I couldn't help.$"
    
Looker_Text_SureICan:
    .string "Sure, I can!$"

Looker_Text_Indeed:
    .string "Indeed.$"

Looker_Text_WillDo:
    .string "Will do.$"
    
Looker_Text_LeaveItToMe:
    .string "Leave it to me.$"
    
Looker_Text_ImOnTheCase:
    .string "I'm on the case.$"
    
Looker_Text_IWillAlwaysHelp:
    .string "Mission complete.$"

Looker_Text_AlrightFine:
    .string "Alright, fine.$"

Looker_Text_SoHeresTheThing:
    .string "So here's the thing…$"
    
Looker_Text_LetMeExplain:
    .string "Let me explain…$"

Looker_Text_ThisSeemsSerious:
    .string "This seems like a serious problem.$"
    
Looker_Text_ThatIsTroubling:
    .string "That is troubling.$"

Looker_Text_INeedYourHelp:
    .string "I need your help.$"

Looker_Text_Hmm:
    .string "Hmm…$"

Looker_Text_IHaveTheInformation:
    .string "I have the information you are looking\n"
    .string "for.$"

Looker_Text_WhatsWrong:
    .string "What's wrong?$"

Looker_Text_LetMeThinkAboutThat:
    .string "Let me think about that.$"

Looker_Text_ThankYouForYourHelp:
    .string "Thank you for your help.$"

Looker_Text_ThankYouForTheIntel:
    .string "Thank you for the intel.$"

Looker_Text_HereYouGo:
    .string "Here you go.$"

Looker_Text_NotYet:
    .string "Not yet.$"

Looker_Text_YouDontLookVeryGood:
    .string "You don't look very good right now.\n"
    .string "What seems to be the problem?$"
    
Looker_Text_IFoundWhatYoureLookingFor:
    .string "I found what you're looking for.$"

Looker_Text_AllInADaysWork:
    .string "All in a day's work.$"
    
Looker_Text_AlwaysHappyToHelp:
    .string "I'm always happy to help a citizen\n"
    .string "in need.$"
    
Looker_Text_WhatsThat:
    .string "Huh?\p"
    .string "What's that?$"

Looker_Text_Huh:
    .string "Huh?$"
    
Looker_Text_Unlucky:
    .string "Unlucky.$"

Looker_Text_ThatWouldBeWonderful:
    .string "That would be wonderful.$"

Looker_Text_ThankYou:
    .string "Thank you.$"
    
Looker_Text_Sure:
    .string "Sure…$"

Looker_Text_Asleep:
    .string "Zzz…$"

Looker_Text_Uhh:
    .string "Uhh…$"
    
Looker_Text_UhhOkay:
    .string "Uhh…\p"
    .string "Sure!$"
    
Looker_Text_IUnderstand:
    .string "I understand.$"
    
Looker_Text_NoThanks:
    .string "No thank you.$"
    
Looker_Text_Drat:
    .string "Drat… I need to try again…$"

Looker_Text_Ouch:
    .string "Ouch!$"
    
Looker_Text_ImOnTheCaseDoubt:
    .string "Umm…\p"
    .string "I'm on the case?\p"
    .string "I think?$"

Looker_Text_Dots:
    .string "…$"

Looker_Text_DotsLong:
    .string "… … …\n"
    .string "… … …$"

Looker_Text_IThinkINeedTwoPokemon:
    .string "Hmm…\n"
    .string "I think I need two Pokémon for this…$"

Looker_EventScript_FoundAllIdols::
    speak LOCALID_PLAYER, DIR_SOUTH, Name_Looker, Looker_Text_ThatsAllTheIdols
    closemessage
    questmenu QUEST_MENU_SET_REWARD, QUEST_GET_INTO_THE_GROOVE
    releaseall
    end

Looker_Text_ThatsAllTheIdols:
    .string "Hmm…\p"
    .string "I believe that's the last of the\n"
    .string "missing idols!\p"
    .string "I should go talk to the barista at\n"
    .string "Tauros Café when I get the chance…$"

Looker_Text_Vitamins:
    .string "Looker received some vitamins!$"

Looker_Text_Feathers:
    .string "Looker received some feathers!$"

Looker_Text_Mochi:
    .string "Looker received some mochi!$"
