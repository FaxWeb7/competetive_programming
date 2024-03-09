import { FC, useContext } from 'react';
import { AuthContext } from './AuthContext'
import { Title } from './Title';
import { IAuth } from '../types/types';

export const AuthPage: FC = () => {
  // useContext позволяет обернуть приложение в гллобальный контекст чтобы потом из любого места или компонента дергать переменные из этого пглобального контекста, вместо того чтобы постоянно передавать глобальную информацию в пропсах 
  const { isLoggedIn, setIsLoggedIn } = useContext<IAuth>(AuthContext);

  return (
    <div>
      <Title />
      {isLoggedIn ? (
        <button onClick={() => setIsLoggedIn(false)}>Выйти из системы</button>
      ) : (
        <button onClick={() => setIsLoggedIn(true)}>Войти</button>
      )}
    </div>
  )
}