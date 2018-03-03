#include "stdafx.h"
#include "CppUnitTest.h"
#include "TextBlock.h"
#include <time.h>
#include <Windows.h>
#include <StrSafe.h>
#include "SharedAdaptiveCard.h"
#include "BaseCardElement.h"
#include "CustomObjectDelegateForIOS.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdaptiveCards;
using namespace std;

namespace AdaptiveCardsSharedModelUnitTest
{
    TEST_CLASS(CustomParsingForIOSTest)
    {
    public:
        TEST_METHOD(CanGetCustomJsonPayload)
        {
            std::string testJsonString = 
            "{\
                \"$schema\":\"http://adaptivecards.io/schemas/adaptive-card.json\",\
                \"type\": \"AdaptiveCard\",\
                \"version\": \"1.0\",\
                \"body\": [\
                    {\
                        \"type\": \"CustomIOSDelegate\",\
                        \"payload\": \"You can even draw attention to certain text with color\"\
                    }\
                ]\
            }";
            std::shared_ptr<AdaptiveCard> adaptiveCard = AdaptiveCard::DeserializeFromString(testJsonString);
            std::shared_ptr<BaseCardElement> elem = adaptiveCard->GetBody().front();
            std::shared_ptr<CustomObjectDelegateForIOS> delegate = std::static_pointer_cast<CustomObjectDelegateForIOS>(elem);
            Json::Value value = delegate->GetJsonPayload(); 
            Json::FastWriter fastWriter;
            std::string jsonString = fastWriter.write(value);

            std::string expected = "\"You can even draw attention to certain text with color\"\n";
            Assert::AreEqual(expected, jsonString);
        }

        TEST_METHOD(CanGetCustomJsonPayloadWithKnownElementFollowing)
        {
            std::string testJsonString = 
            "{\
                \"$schema\":\"http://adaptivecards.io/schemas/adaptive-card.json\",\
                \"type\": \"AdaptiveCard\",\
                \"version\": \"1.0\",\
                \"body\": [\
                    {\
                        \"type\": \"CustomIOSDelegate\",\
                        \"payload\": \"You can even draw attention to certain text with color\"\
                    },\
                    {\
                        \"type\": \"TextBlock\",\
                        \"text\": \"You can even draw attention to certain text with color\",\
                        \"wrap\": true,\
                        \"color\": \"attention\",\
                        \"unknown\": \"testing unknown\"\
                    }\
                ]\
            }";
            std::shared_ptr<AdaptiveCard> adaptiveCard = AdaptiveCard::DeserializeFromString(testJsonString);
            std::shared_ptr<BaseCardElement> elem = adaptiveCard->GetBody().front();
            std::shared_ptr<CustomObjectDelegateForIOS> delegate = std::static_pointer_cast<CustomObjectDelegateForIOS>(elem);
            Json::Value value = delegate->GetJsonPayload(); 
            Json::FastWriter fastWriter;
            std::string jsonString = fastWriter.write(value);

            std::string expected = "\"You can even draw attention to certain text with color\"\n";
            Assert::AreEqual(expected, jsonString);
        }

        TEST_METHOD(CanGetJsonPayloadOfArrayType)
        {
            std::string testJsonString = 
            "{\
                \"$schema\":\"http://adaptivecards.io/schemas/adaptive-card.json\",\
                \"type\": \"AdaptiveCard\",\
                \"version\": \"1.0\",\
                \"body\": [\
                    {\
                        \"type\": \"CustomIOSDelegate\",\
                        \"payload\": [\
                            {\
                                \"testloadone\": \"You can even draw attention to certain text with color\"\
                            },\
                            {\
                                \"testloadtwo\": \"You can even draw attention to certain text with markdown\"\
                            }\
                        ]\
                    },\
                    {\
                        \"type\": \"TextBlock\",\
                        \"text\": \"You can even draw attention to certain text with color\",\
                        \"wrap\": true,\
                        \"color\": \"attention\",\
                        \"unknown\": \"testing unknown\"\
                    }\
                ]\
            }";
            std::shared_ptr<AdaptiveCard> adaptiveCard = AdaptiveCard::DeserializeFromString(testJsonString);
            std::shared_ptr<BaseCardElement> elem = adaptiveCard->GetBody().front();
            std::shared_ptr<CustomObjectDelegateForIOS> delegate = std::static_pointer_cast<CustomObjectDelegateForIOS>(elem);
            Json::Value value = delegate->GetJsonPayload(); 
            Json::FastWriter fastWriter;
            std::string jsonString = fastWriter.write(value);

            std::string expected = "[{\"testloadone\":\"You can even draw attention to certain text with color\"},{\"testloadtwo\":\"You can even draw attention to certain text with markdown\"}]\n";
            Assert::AreEqual(expected, jsonString);
        }
    };
}
