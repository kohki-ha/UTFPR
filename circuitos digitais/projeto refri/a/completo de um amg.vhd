LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY maquinaEstados IS
	PORT(
		moedas                  : 		IN STD_LOGIC_VECTOR(9 DOWNTO 0); -- vetor e moedas das chaves (0-9)
		opcao1, opcao2          : 		IN BIT; -- opcoes de produtos
		Display1			    :		OUT STD_LOGIC_VECTOR(6 DOWNTO 0); --display preco
		Display2			    :		OUT STD_LOGIC_VECTOR(6 DOWNTO 0); --display preco
		Display3			    :		OUT STD_LOGIC_VECTOR(6 DOWNTO 0); --display preco
		Display4			    :		OUT STD_LOGIC_VECTOR(6 DOWNTO 0) -- prouto (A - agua, R - reri, S - salgadinho, C - chocolate)
	);
END ENTITY maquinaEstados;

ARCHITECTURE main of maquinaEstados is
	BEGIN
		PROCESS(moedas, opcao1, opcao2) is
			VARIABLE escolha01, escolha02, escolha03, escolha04, escolha : integer := 0; -- variaveis para escolha de produtos
			VARIABLE moeda25_1, moeda25_2, moeda25_3, moeda50_1, moeda50_2, moeda50_3, moeda100_1, moeda100_2, moeda100_3, dinheiro_total : integer; -- variaveis para moedas
			VARIABLE preco01, preco02, preco03, preco04, preco_total : integer; -- variaveis para preco
	BEGIN

		-- INSERIR MOEDAS -----------------------------------------------------
		-- vetor de moedas representando um pino (0-9)
		-- 3 moedas por pino (25, 50, 100)
		-- caso pino (0-9) for 1, aumenta 1 na respectiva quantidade de moeda
		-- agua: 1.50 // refri: 3.00 // salgadinho: 3.50 // chocolate: 3.75
		-----------------------------------------------------------------------
		CASE moedas(0) IS
			WHEN '1' => moeda25_1 := 1;
			WHEN others => moeda25_1 := 0;
		END CASE;
		-----------------------------------------------------------------------
		case moedas(1) IS
			WHEN '1' => moeda25_2 := 1;
			WHEN OTHERS => moeda25_2 := 0;
		END CASE;
		-----------------------------------------------------------------------
		case moedas(2) IS
			WHEN '1' => moeda25_3 := 1;
			WHEN OTHERS => moeda25_3 := 0;
		END CASE;
		-----------------------------------------------------------------------
		CASE moedas(3) IS
			WHEN '1' => moeda50_1 := 2;
			WHEN OTHERS => moeda50_1 := 0;
		END CASE;
		-----------------------------------------------------------------------
		case moedas(4) IS
			WHEN '1' => moeda50_2 := 2;
			WHEN OTHERS => moeda50_2 := 0;
		END CASE;
		-----------------------------------------------------------------------
		CASE moedas(5) IS
			WHEN '1' => moeda50_3 := 2;
			WHEN OTHERS => moeda50_3 := 0;
		END CASE;
		-----------------------------------------------------------------------
		CASE moedas(6) is
			WHEN '1' => moeda100_1 := 4;
			WHEN OTHERS => moeda100_1 := 0;
		END CASE;
		-----------------------------------------------------------------------
		CASE moedas(7) is
			WHEN '1' => moeda100_2 := 4;
			WHEN OTHERS => moeda100_2 := 0;
		END CASE;
		-----------------------------------------------------------------------
		CASE moedas(8) is
			WHEN '1' => moeda100_3 := 4;
			WHEN OTHERS => moeda100_3 := 0;
		END CASE;

		-- OPCAO DE PRODUTO ---------------------------------------------------
		-- 11 = agua - 6 // 01 = reri - 12 // 10 = salgadinho - 14 // 00 = chocolate - 15
		-- variavel escolha recebe o valor da opcao de produto
		-- preco recebe o valor do preco do produto de acordo com a soma das moedas inseridas acima (moeda de 25 = 1, moeda de 50 = 2, moeda de 100 = 4)
		-- agua: 1.50 // refri: 3.00 // salgadinho: 3.50 // chocolate: 3.75
		-----------------------------------------------------------------------
		IF opcao1 = '1' AND opcao2 = '1' THEN
			escolha01 := 1;
			preco01 := 6;
		ELSE
			escolha01 := 0;
			preco01 := 0;
		END IF;
		-----------------------------------------------------------------------
		IF opcao1 = '1' AND opcao2 = '0' THEN
			escolha02 := 2;
			preco02 := 12;
		else
			escolha02 := 0;
			preco02 := 0;
		END IF;
		-----------------------------------------------------------------------
		IF opcao1 = '0' AND opcao2 = '1' THEN
			escolha03 := 3;
			preco03 := 14;
		ELSE
			escolha03 := 0;
			preco03 := 0;
		END IF;
		-----------------------------------------------------------------------
		IF opcao1 = '0' AND opcao2 = '0' THEN
			escolha04 := 4;
			preco04 := 15;
		ELSE
			escolha04 := 0;
			preco04 := 0;
		END IF;
		-----------------------------------------------------------------------
		preco_total := preco01 + preco02 + preco03 + preco04; -- soma dos precos dos produtos
		dinheiro_total := moeda25_1 + moeda25_2 + moeda25_3 + moeda50_1 + moeda50_2 + moeda50_3 + moeda100_1 + moeda100_2 + moeda100_3; -- soma das moedas inseridas
		escolha := escolha01 + escolha02 + escolha03 + escolha04; -- soma das escolhas de produtos
		-----------------------------------------------------------------------
		IF moedas(9) = '1' THEN -- se o pino 9 for 1
			IF dinheiro_total >= preco_total and preco_total > 0 THEN -- se o dinheiro inserido for maior ou igual ao preco total e o preco total for maior que 0
				dinheiro_total := dinheiro_total - preco_total; -- diminui o dinheiro total pelo preco total
			END IF;
		END IF;

		-- DISPLAY DO DINHEIRO E DO PRODUTO -----------------------------------
		-- mostra no display o valor do dinheiro total conforme as moedas sao insirias
		-- numero de 3 digitos, cada digito sendo mostrado em um display separado
		-- obs: o valor do dinheiro total é alterado se a condição acima é satisfeita e assim então irá mostrar o troco do cliente
		-- agua: 1.50 // refri: 3.00 // salgadinho: 3.50 // chocolate: 3.75
		-----------------------------------------------------------------------
		case (dinheiro_total) is
			WHEN 0 =>
				Display3 <= "1000000"; -- mostra 0
				Display2 <= "1000000"; -- mostra 0
				Display1 <= "1000000"; -- mostra 0
			-----------------------------------------------------------------------
			WHEN 1 => -- mostra 0.25
				Display3 <= "1000000"; -- mostra 0
				Display1 <= "0010010"; -- mostra 0,05
				Display2 <= "0100100"; -- mostra 0,20
			-----------------------------------------------------------------------
			WHEN 2 => -- mostra 0.5
				Display3 <= "1000000"; -- mostra 0
				Display1 <= "1000000"; -- mostra 0,00
				Display2 <= "0010010"; -- mostra 0,5
			-----------------------------------------------------------------------
			WHEN 3 => -- mostra 0.75
				Display3 <= "1000000"; -- mostra 0
				Display1 <= "0010010"; -- mostra 0,05
				Display2 <= "1111000"; -- mostra 0,7
			-----------------------------------------------------------------------
			WHEN 4 => -- mostra 1.0
				Display3 <= "1111001"; -- mostra 1
				Display1 <= "1000000"; -- mostra 0,00
				Display2 <= "1000000"; -- mostra 0,0
			-----------------------------------------------------------------------
			WHEN 5 => -- mostra 1.25
				Display3 <= "1111001"; -- mostra 1
				Display1 <= "0010010"; -- mostra 0,05
				Display2 <= "0100100"; -- mostra 0,2
			-----------------------------------------------------------------------
			WHEN 6 => -- mostra 1.5
				Display3 <= "1111001"; -- mostra 1
				Display1 <= "1000000"; -- mostra 0,00
				Display2 <= "0010010"; -- mostra 0,5
			-----------------------------------------------------------------------
			WHEN 7 => -- mostra 1.75
				Display3 <= "1111001"; -- mostra 1
				Display1 <= "0010010"; -- mostra 0,05
				Display2 <= "1111000"; -- mostra 0,7
			-----------------------------------------------------------------------
			WHEN 8  => -- mostra 2.0
				Display3 <= "0100100";-- mostra 2
				Display1 <= "1000000"; -- mostra 0,00
				Display2 <= "1000000"; -- mostra 0,0
			-----------------------------------------------------------------------
			WHEN 9  => -- mostra 2.25
				Display3 <= "0100100"; -- mostra 2
				Display1 <= "0010010"; -- mostra 0,05
				Display2 <= "0100100"; -- mostra 0,2
			-----------------------------------------------------------------------
			WHEN 10  => -- mostra 2.5
				Display3 <= "0100100"; -- mostra 2
				Display1 <= "1000000"; -- mostra 0,00
				Display2 <= "0010010"; -- mostra 0,5
			-----------------------------------------------------------------------
			WHEN 11  => -- mostra 2.75
				Display3 <= "0100100"; -- mostra 2
				Display1 <= "0010010"; -- mostra 0,05
				Display2 <= "1111000"; -- mostra 0,7
			-----------------------------------------------------------------------
			WHEN 12  => -- mostra 3.0
				Display3 <= "0110000"; -- mostra 3
				Display1 <= "1000000"; -- mostra 0,00
				Display2 <= "1000000"; -- mostra 0,0
			-----------------------------------------------------------------------
			WHEN 13  => -- mostra 3.25
				Display3 <= "0110000"; -- mostra 3
				Display1 <= "0010010"; -- mostra 0,05
				Display2 <= "0100100"; -- mostra 0,2
			-----------------------------------------------------------------------
			WHEN 14  => -- mostra 3.5
				Display3 <= "0110000"; -- mostra 3
				Display1 <= "1000000"; -- mostra 0,00
				Display2 <= "0010010"; -- mostra 0,5
			-----------------------------------------------------------------------
			WHEN 15  => -- mostra 3.75
				Display3 <= "0110000"; -- mostra 3
				Display1 <= "0010010"; -- mostra 0,05
				Display2 <= "1111000"; -- mostra 0,7
			-----------------------------------------------------------------------
			WHEN 16  => -- mostra 4.0
				Display3 <= "0011001"; -- mostra 4
				Display1 <= "1000000"; -- mostra 0,00
				Display2 <= "1000000"; -- mostra 0,0
			-----------------------------------------------------------------------
			WHEN 17  => -- mostra 4.25
				Display3 <= "0011001"; -- mostra 4
				Display1 <= "0010010"; -- mostra 0,05
				Display2 <= "0100100"; -- mostra 0,2
			-----------------------------------------------------------------------
			WHEN 18  => -- mostra 4.5
				Display3 <= "0011001"; -- mostra 4
				Display1 <= "1000000"; -- mostra 0,00
				Display2 <= "0010010"; -- mostra 0,5
			-----------------------------------------------------------------------
			WHEN 19  => -- mostra 4.75
				Display3 <= "0011001"; -- mostra 4
				Display1 <= "0010010"; -- mostra 0,05
				Display2 <= "1111000"; -- mostra 0,7
			-----------------------------------------------------------------------
			WHEN 20  => -- mostra 5.0
				Display3 <= "0010010"; -- mostra 5
				Display1 <= "1000000"; -- mostra 0,00
				Display2 <= "1000000"; -- mostra 0,0
			-----------------------------------------------------------------------
			WHEN 21  => -- mostra 5.25
				Display3 <= "0010010"; -- mostra 5
				Display1 <= "0010010"; -- mostra 0,05
				Display2 <= "0100100"; -- mostra 0,2
			-----------------------------------------------------------------------
			WHEN OTHERS => NULL;
		END CASE;

		-- DISPLAY DA ESCOLHA -----------------------------------------------------
		-- mostra a letra da escolha no display
		-- agua: 1.50 // refri: 3.00 // salgadinho: 3.50 // chocolate: 3.75
		---------------------------------------------------------------------------
		CASE escolha IS
			WHEN 1 => Display4 <= "0001000"; -- Agua
			WHEN 2 => Display4 <= "0101111"; -- Refrigerante
			WHEN 3 => Display4 <= "0010010"; -- Salgadinho
			WHEN 4 => Display4 <= "1000110"; -- Chocolate
			WHEN OTHERS => NULL;
		END CASE;
	END PROCESS;
END ARCHITECTURE;