//
// MultiAppender - shows how to use multiple appenders with the same logger. 
//

#include <plog/Log.h>
#include <plog/Appenders/ConsoleAppender.h>

int main()
{
    static plog::RollingFileAppender<plog::CsvFormatter> fileAppender("MultiAppender.csv", 8000, 3); // Create the 1st appender.
    static plog::ConsoleAppender<plog::TxtFormatter> consoleAppender; // Create the 2nd appender.
    plog::init(plog::debug, &fileAppender).addAppender(&consoleAppender); // Initialize the logger with the both appenders.

    // A bunch of log lines that goes to the both appenders: to the file and to the console.
    for (int i = 0; i < 100; ++i)
    {
        LOG_INFO << "i: " << i;
    }

    return 0;
}
