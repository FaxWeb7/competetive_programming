import { FC, useEffect, useRef, useState } from 'react'
import { Link } from 'react-router-dom';
import { IMenu } from './types/types';
import styles from './App.module.scss'

const Menu: IMenu[] = [
  {
    name: 'Home',
    link: '/'
  },
  {
    name: 'Auth',
    link: '/auth'
  }
]

export const App: FC = () => {
  const [count, setCount] = useState<number>(0);
  const [isLoading, setIslLading] = useState<boolean>(true);

  // useEffect выполняется перед загрузкой страницы
  useEffect(() => {
    setTimeout(() => {
      setIslLading(false)
    }, 1000)
    // const fetchData = async (): Promise<IUser> => {
    //   const response = await fetch('url')
    //   const data = await response.json()
    //   setState(data)
    // }
    // fetchData()
  }, [])

  //ссылка на привязанный элемент (вместо document.getelbyid)
  const imageRef = useRef<HTMLImageElement | null>(null)
  const changeBorderRadius = () => {
    if (!imageRef || !imageRef.current) return
    imageRef.current.style.borderRadius = '20px'
    console.log(imageRef.current)
  }

  return (
    <>
      <div className={styles.wrapper}>
        <img src='/testPict.png' width={100} ref={imageRef}/>
        <br />
        <button onClick={changeBorderRadius}>click to change image border radius</button>

        <h1>First component</h1>
        <p>Counter is: {count}</p>
        <button onClick={() => setCount(count+1)}>click here!</button>

        {isLoading ? (
          <p>Loading...</p>
        ) : (
          <div className={styles.menu}>
            <p>Navigation:</p>
            { Menu.map((item, index) => (
              <div key={index} className={styles.menuItem}>
                <p>{index+1})</p>
                {/* переход по ссылке без перезагрузки страницы */}
                <Link to={item.link}>{item.name}</Link> 
              </div>
            )) }
          </div>
        )}
      </div>
    </>
  )
}