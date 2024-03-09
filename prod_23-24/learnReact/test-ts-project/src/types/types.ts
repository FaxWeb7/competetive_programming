export interface IMenu {
  name: string,
  link: string
}

export interface IAuth {
  isLoggedIn: boolean,
  setIsLoggedIn: (isLoggedIn: boolean) => void
}