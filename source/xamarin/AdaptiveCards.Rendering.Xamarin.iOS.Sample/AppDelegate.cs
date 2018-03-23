﻿using Foundation;
using UIKit;
using AdaptiveCards.Rendering.Xamarin.iOS;
using AdaptiveCards.BotConnection;

namespace Adaptive.Cards.Rendering.Xamarin.IOS.Sample
{
    // The UIApplicationDelegate for the application. This class is responsible for launching the
    // User Interface of the application, as well as listening (and optionally responding) to application events from iOS.
    [Register("AppDelegate")]
    public class AppDelegate : UIApplicationDelegate
    {
        // class-level declarations

        public override UIWindow Window
        {
            get;
            set;
        }

        private UITextField adaptiveCardRequest;
        private UIButton sendButton;

        string hostconfig = @"
        {
          ""spacing"": {
            ""small"": 3,
            ""default"": 8,
            ""medium"": 20,
            ""large"": 30,
            ""extraLarge"": 40,
            ""padding"": 20
          },
          ""separator"": {
            ""lineThickness"": 1,
            ""lineColor"": ""#EEEEEE""
          },
        ""supportsInteractivity"": true,
        ""fontFamily"": ""Segoe UI"",
        ""fontSizes"": {
           ""small"": 12,
           ""default"": 14,
           ""medium"": 17,
           ""large"": 21,
           ""extraLarge"": 26
          },
          ""fontWeights"": {
            ""lighter"": 200,
            ""default"": 400,
            ""bolder"": 600
          },
          ""containerStyles"": {
            ""default"": {
              ""backgroundColor"": ""#00000000"",
              ""fontColors"": {
                ""default"": {
                  ""normal"": ""#333333"",
                  ""subtle"": ""#EE333333""
                },
                ""accent"": {
                  ""normal"": ""#2E89FC"",
                  ""subtle"": ""#882E89FC""
                },
                ""attention"": {
                  ""normal"": ""#cc3300"",
                  ""subtle"": ""#DDcc3300""
                },
                ""good"": {
                  ""normal"": ""#54a254"",
                  ""subtle"": ""#DD54a254""
                },
                ""warning"": {
                  ""normal"": ""#e69500"",
                  ""subtle"": ""#DDe69500""
                }
              }
            },
            ""emphasis"": {
              ""backgroundColor"": ""#08000000"",
              ""fontColors"": {
                ""default"": {
                  ""normal"": ""#333333"",
                  ""subtle"": ""#EE333333""
                },
                ""accent"": {
                  ""normal"": ""#2E89FC"",
                  ""subtle"": ""#882E89FC""
                },
                ""attention"": {
                  ""normal"": ""#cc3300"",
                  ""subtle"": ""#DDcc3300""
                },
                ""good"": {
                  ""normal"": ""#54a254"",
                  ""subtle"": ""#DD54a254""
                },
                ""warning"": {
                  ""normal"": ""#e69500"",
                  ""subtle"": ""#DDe69500""
                }
              }
            }
          },
          ""imageSizes"": {
            ""small"": 50,
            ""medium"": 80,
            ""large"": 120
          },
          ""actions"": {
            ""maxActions"": 5,
            ""spacing"": ""default"",
            ""buttonSpacing"": 10,
            ""showCard"": {
              ""actionMode"": ""inline"",
              ""inlineTopMargin"": 16
            },
            ""actionsOrientation"": ""horizontal"",
            ""actionAlignment"": ""stretch""
          },
          ""adaptiveCard"": {
            ""allowCustomStyle"": false
          },
          ""image"": {
            ""size"": ""medium""
          },
          ""imageSet"": {
            ""imageSize"": ""medium"",
            ""maxImageHeight"": 100
          },
          ""factSet"": {
            ""title"": {
              ""color"": ""default"",
              ""size"": ""default"",
              ""isSubtle"": false,
              ""weight"": ""bolder"",
              ""wrap"": true,
              ""maxWidth"": 150
            },
            ""value"": {
              ""color"": ""default"",
              ""size"": ""default"",
              ""isSubtle"": false,
              ""weight"": ""default"",
              ""wrap"": true
            },
            ""spacing"": 10
          }
        }";

        private ACOHostConfigParseResult m_config = null;
        private PayloadRetriever m_payloadRetriever = null;

        private UIView ReGenerateAdaptiveCard(string json)
        {
            var retrievedCard = ACOAdaptiveCard.FromJson(json);

            if (retrievedCard.IsValid == true)
            {
                var renderResult = ACRRenderer.Render(retrievedCard.Card, m_config.Config, 
                                                      new CoreGraphics.CGRect(10, 
                                                                              UIScreen.MainScreen.Bounds.Size.Height * 0.1f + 1, 
                                                                              UIScreen.MainScreen.Bounds.Size.Width - 20, 
                                                                              UIScreen.MainScreen.Bounds.Size.Height * 0.9f - 2));
                return renderResult.View;
            }
            return null;
        }

        public override bool FinishedLaunching(UIApplication application, NSDictionary launchOptions)
        {
            // create a new window instance based on the screen size
            Window = new UIWindow(UIScreen.MainScreen.Bounds);

            var controller = new UIViewController();
            controller.View.BackgroundColor = UIColor.White;
            controller.Title = "Xamarin Test App";

            m_config = ACOHostConfig.FromJson(hostconfig);
            m_payloadRetriever = new PayloadRetriever();

            Window.RootViewController = controller;

            // Add text field
            adaptiveCardRequest = new UITextField();
            adaptiveCardRequest.BorderStyle = UITextBorderStyle.RoundedRect;
            adaptiveCardRequest.Frame = new CoreGraphics.CGRect(0,
                                                       0,
                                                       UIScreen.MainScreen.Bounds.Size.Width * 0.9f,
                                                       UIScreen.MainScreen.Bounds.Size.Height * 0.1f);
            controller.View.AddSubview(adaptiveCardRequest);

            // Add button
            sendButton = UIButton.FromType(UIButtonType.System);
            sendButton.Frame = new CoreGraphics.CGRect(UIScreen.MainScreen.Bounds.Size.Width * 0.9f,
                                                       0,
                                                       UIScreen.MainScreen.Bounds.Size.Width * 0.1f,
                                                       UIScreen.MainScreen.Bounds.Size.Height * 0.1f);
            sendButton.SetTitle("Send", UIControlState.Normal);
            sendButton.TouchUpInside += (sender, e) =>
            {
                string request = adaptiveCardRequest.Text;
                var renderedCard = ReGenerateAdaptiveCard(m_payloadRetriever.RequestAdaptiveCard((request)));
                if (renderedCard != null)
                {
                    controller.View.AddSubview(renderedCard);
                }
            };
            controller.View.AddSubview(sendButton);

            // make the window visible
            Window.MakeKeyAndVisible();
          
            return true;
        }
        public override void OnResignActivation(UIApplication application)
        {
            // Invoked when the application is about to move from active to inactive state.
            // This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) 
            // or when the user quits the application and it begins the transition to the background state.
            // Games should use this method to pause the game.
        }

        public override void DidEnterBackground(UIApplication application)
        {
            // Use this method to release shared resources, save user data, invalidate timers and store the application state.
            // If your application supports background exection this method is called instead of WillTerminate when the user quits.
        }

        public override void WillEnterForeground(UIApplication application)
        {
            // Called as part of the transiton from background to active state.
            // Here you can undo many of the changes made on entering the background.
        }

        public override void OnActivated(UIApplication application)
        {
            // Restart any tasks that were paused (or not yet started) while the application was inactive. 
            // If the application was previously in the background, optionally refresh the user interface.
        }

        public override void WillTerminate(UIApplication application)
        {
            // Called when the application is about to terminate. Save data, if needed. See also DidEnterBackground.
        }
    }
}

