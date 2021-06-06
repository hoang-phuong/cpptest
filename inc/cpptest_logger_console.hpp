#pragma once

#include "cpptest_logger_abstract.hpp"
#include <string>
#include <vector>

namespace phuong
{
    namespace cpptest
    {
        class ConsoleLogger : public phuong::cpptest::AbstractLogger
        {
          public:
            static ConsoleLogger& getInstance();

            void info(std::string message);
            void debug(std::string message);
            void warn(std::string message);
            void error(std::string message);

          private:
            enum class FontEffect
            {
                kFontEffectReset        = 0U,
                kFontEffectBold         = 1U,
                kFontEffectFaint        = 2U,
                kFontEffectItalic       = 3U,
                kFontEffectUnderline    = 4U,
                kFontEffectSlowBlink    = 5U,
                kFontEffectRapidBlink   = 6U,
                kFontEffectInverseColor = 7U,
                kFontEffectConceal      = 8U,
                kFontEffectCrossedOut   = 9U,
                kFontEffectDefault      = 10U,
                kFontEffectAltFont1     = 11U,
                kFontEffectAltFont2     = 12U,
                kFontEffectAltFont3     = 13U,
                kFontEffectAltFont4     = 14U,
                kFontEffectAltFont5     = 15U,
                kFontEffectAltFont6     = 16U,
                kFontEffectAltFont7     = 17U,
                kFontEffectAltFont8     = 18U,
                kFontEffectAltFont9     = 19U,
                kFontEffectForegroundColorBlack = 30U,
                kFontEffectForegroundColorRed,
                kFontEffectForegroundColorGreen,
                kFontEffectForegroundColorYellow,
                kFontEffectForegroundColorBlue,
                kFontEffectForegroundColorMagenta,
                kFontEffectForegroundColorCyan,
                kFontEffectForegroundColorWhite,
                kFontEffectForegroundColorDefault = 39U,
                kFontEffectBackgroundColorBlack = 40U,
                kFontEffectBackgroundColorRed,
                kFontEffectBackgroundColorGreen,
                kFontEffectBackgroundColorYellow,
                kFontEffectBackgroundColorBlue,
                kFontEffectBackgroundColorMagenta,
                kFontEffectBackgroundColorCyan,
                kFontEffectBackgroundColorWhite,
                kFontEffectBackgroundColorDefault = 49U,
                kFontEffectFramed    = 51U,
                kFontEffectEncircled = 52U,
                kFontEffectOverlined = 53U,
                kFontEffectForegroundColorBrightBlack = 90U,
                kFontEffectForegroundColorBrightRed,
                kFontEffectForegroundColorBrightGreen,
                kFontEffectForegroundColorBrightYellow,
                kFontEffectForegroundColorBrightBlue,
                kFontEffectForegroundColorBrightMagenta,
                kFontEffectForegroundColorBrightCyan,
                kFontEffectForegroundColorBrightWhite,
                kFontEffectBackgroundColorBrightBlack = 100U,
                kFontEffectBackgroundColorBrightRed,
                kFontEffectBackgroundColorBrightGreen,
                kFontEffectBackgroundColorBrightYellow,
                kFontEffectBackgroundColorBrightBlue,
                kFontEffectBackgroundColorBrightMagenta,
                kFontEffectBackgroundColorBrightCyan,
                kFontEffectBackgroundColorBrightWhite
            };

            const std::string kEscCodeDelimiter = ";";
            const std::string kEscSeqEnd        = "m";
            const std::string kEscSeqPrefix     = "\033[";
            const std::string kEscSeqReset      = "\033[0m";

            const std::vector<FontEffect> infoFont {FontEffect::kFontEffectForegroundColorBrightWhite};
            const std::vector<FontEffect> debugFont {FontEffect::kFontEffectForegroundColorBrightCyan};
            const std::vector<FontEffect> warnFont {FontEffect::kFontEffectForegroundColorBrightMagenta};
            const std::vector<FontEffect> errorFont {FontEffect::kFontEffectForegroundColorBrightRed};

            std::string formatPlainMessage(std::string message, std::vector<FontEffect> const& fontEffects);

            ConsoleLogger()  = default;
            ~ConsoleLogger() = default;

            ConsoleLogger(ConsoleLogger const&) = delete;
            ConsoleLogger(ConsoleLogger&&)      = delete;
            ConsoleLogger& operator=(ConsoleLogger const&) = delete;
            ConsoleLogger& operator=(ConsoleLogger&&) = delete;
        };
    } // namespace cpptest
} // namespace phuong
