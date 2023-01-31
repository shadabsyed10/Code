#include "Practice_problem.h"

typedef enum
{
	sunday,
	monday,
	tuesday,
	wednesday,
	thursday,
	friday,
	saturday,
	NO_OF_DAYS
} WEEK_DAY;

void state_machine_example(void)
{
	static WEEK_DAY weekday = sunday;
	
	printf("Weekday is %d\n",weekday);
	switch (weekday)
	{
		case(sunday):
			weekday = monday;
			break;
		case(monday):
			weekday = tuesday;
			break;
		case(tuesday):
			weekday = wednesday;
			break;
		case(wednesday):
			weekday = thursday;
			break;
		case(thursday):
			weekday = friday;
			break;
		case(friday):
			weekday = saturday;
			break;

		default:
			weekday = sunday;
			break;
	}
	printf("After switch case Weekday is %d\n", weekday);
}
#if 0
//Different state of  machine
typedef enum
{
	Idle_State,
	Card_Inserted_State,
	Pin_Eentered_State,
	Option_Selected_State,
	Amount_Entered_State,
} eSystemState;

//Different type events
typedef enum
{
	Card_Insert_Event,
	Pin_Enter_Event,
	Option_Selection_Event,
	Amount_Enter_Event,
	Amount_Dispatch_Event
} eSystemEvent;

//Prototype of eventhandlers
eSystemState AmountDispatchHandler(void)
{
	return Idle_State;
}
eSystemState EnterAmountHandler(void)
{
	return Amount_Entered_State;
}
eSystemState OptionSelectionHandler(void)
{
	return Option_Selected_State;
}
eSystemState EnterPinHandler(void)
{
	return Pin_Eentered_State;
}
eSystemState InsertCardHandler(void)
{
	return Card_Inserted_State;
}

void state_machine_example1(void)
{
	eSystemState eNextState = Idle_State;
	eSystemEvent eNewEvent;

	while (1)
	{
		//Read system Events
		eSystemEvent eNewEvent;
		switch (eNextState)
		{
		case Idle_State:
		{
			if (Card_Insert_Event == eNewEvent)
			{
				eNextState = InsertCardHandler();
			}
		}
		break;
		case Card_Inserted_State:
		{
			if (Pin_Enter_Event == eNewEvent)
			{
				eNextState = EnterPinHandler();
			}
		}
		break;
		case Pin_Eentered_State:
		{
			if (Option_Selection_Event == eNewEvent)
			{
				eNextState = OptionSelectionHandler();
			}
		}
		break;
		case Option_Selected_State:
		{
			if (Amount_Enter_Event == eNewEvent)
			{
				eNextState = EnterAmountHandler();
			}
		}
		break;
		case Amount_Entered_State:
		{
			if (Amount_Dispatch_Event == eNewEvent)
			{
				eNextState = AmountDispatchHandler();
			}
		}
		break;
		default:
			break;
		}
	}
}
#endif