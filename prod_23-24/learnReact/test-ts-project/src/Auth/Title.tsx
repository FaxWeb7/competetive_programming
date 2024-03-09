import { FC, useContext } from "react";
import { AuthContext } from "./AuthContext";
import { IAuth } from "../types/types";

export const Title: FC = () => {
  const { isLoggedIn } = useContext<IAuth>(AuthContext)
  return (
    <>
      {isLoggedIn ? (
        <h2>Привет, Артем!</h2>
      ) : (
        <h2>Войдите в систему</h2>
      )}
    </>
  )
}