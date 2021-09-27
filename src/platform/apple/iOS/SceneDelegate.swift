//
//  SceneDelegate.swift
//  GowEngineMount
//
//  Created by Stephen Gowen on 4/22/20.
//  Copyright © 2021 Stephen Gowen. All rights reserved.
//

import UIKit

final class SceneDelegate: UIResponder, UIWindowSceneDelegate
{
    var window: UIWindow?

    func scene(_ scene: UIScene, willConnectTo session: UISceneSession, options connectionOptions: UIScene.ConnectionOptions)
    {
        guard let windowScene = (scene as? UIWindowScene) else { return }
        
        self.window = UIWindow(windowScene: windowScene)
        self.window?.rootViewController = ViewController()
        self.window?.makeKeyAndVisible()
    }
}
