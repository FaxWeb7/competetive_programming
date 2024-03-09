import { FC, ReactNode, createContext, useState } from "react";
import { IAuth } from "../types/types";

export const AuthContext = createContext<IAuth>({
  isLoggedIn: false,
  setIsLoggedIn: () => {}
})

interface IAuthProps {
  children: ReactNode
}

export const AuthProvider: FC<IAuthProps> = ({ children }) => {
  const [isLoggedIn, setIsLoggedIn] = useState<boolean>(false)

  return (
    <AuthContext.Provider value={{isLoggedIn, setIsLoggedIn}}>
      {children}
    </AuthContext.Provider>
  )
}